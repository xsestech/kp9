//
// Created by Alex on 21.04.2024.
//

#ifndef PARSE_H
#define PARSE_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool parse_double(char* str, double* target);
void parse_tokens(char* str, int max_tokens, char** tokens, int* parsed_tokens);

#endif //PARSE_H
