#include "curl_handler.h"
#include <string.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct Memory *mem = (struct Memory *)userp;

  if (mem->size + realsize >= sizeof(mem->response)) {
    fprintf(stderr, "Response size exceeds buffer limit\n");
    return 0;
  }

  memcpy(&(mem->response[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;

  return realsize;
}

CURLcode fetch_data(const char *url, struct Memory *chunk) {
  CURL *curl = curl_easy_init();
  if(!curl) {
    return CURLE_FAILED_INIT;
  }

  chunk->size = 0;
  chunk->response[0] = 0;

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)chunk);

  CURLcode res = curl_easy_perform(curl);

  curl_easy_cleanup(curl);
  return res;
}
