#ifndef CURL_HANDLER_H
#define CURL_HANDLER_H

#include <stdio.h>
#include <curl/curl.h>

struct Memory {
	char response[8192];
	size_t size;
};

CURLcode fetch_data(const char *url, struct Memory *chunk);

#endif
