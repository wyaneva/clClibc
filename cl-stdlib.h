/*
 * cl-stdlib.h
 * String to int conversion
 *
 * Copyright 2016-2020 Vanya Yaneva, The University of Edinburgh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CL_STDLIB_H
#define CL_STDLIB_H

#include "cl-ctype.h"

// integer
int atoi(const char *);

// long versions
long int atol(const char *);

int atoi(const char *str) {
  int res = 0;
  int sign = 1;

  // Skip any initial empty spaces
  while (*str == ' ')
    str++;

  // If number is negative, then update sign
  if (*str == '-') {
    sign = -1;
    str++;
  }

  // Iterate through all digits of input string and update result
  while (*str != '\0') {
    if (!isdigit(*str))
      break;

    res = res * 10 + *str - '0';
    str++;
  }

  // Return result with sign
  return sign * res;
}

long int atol(const char *str) {
  long int res = 0;
  int sign = 1;

  // Skip any initial empty spaces
  while (*str == ' ')
    str++;

  // If number is negative, then update sign
  if (*str == '-') {
    sign = -1;
    str++;
  }

  // Iterate through all digits of input string and update result
  while (*str != '\0') {
    if (!isdigit(*str))
      break;

    res = res * 10 + *str - '0';
    str++;
  }

  // Return result with sign
  return sign * res;
}

#endif
