//
// Created by Alex on 21.04.2024.
//
#include "parse.h"

bool parse_double(char* str, double* target) {
  char* endptr;
  *target = (double)strtod(str, &endptr);
  if (endptr == str) {
    return false;
  }
  return true;
}

void parse_tokens(char* str, int max_tokens, char** tokens, int* parsed_tokens) {
  char* token = strtok(str, " ");
  *parsed_tokens = 0;
  while (token) {
    token[strcspn(token, "\n")] = 0; // Strip \n
    tokens[(*parsed_tokens)++] = token;
    if (*parsed_tokens > max_tokens) {
      *parsed_tokens = 0;
    }
    token = strtok(NULL, ";");
  }

}