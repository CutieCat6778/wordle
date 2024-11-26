#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "dict.h"

int parse_json_response(const char *json_str, struct Dict *dict);

#endif
