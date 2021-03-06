/*
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

#ifndef CL_STDIO_H
#define CL_STDIO_H

#include "cl-stdlib.h"

#if GPU_COMPILED
char *fgets(char *, int, char *);
int fgetc(char);
int scanfi(__constant char *, int *, char **);
int scanfl(__constant char *, long *, char **);
int scanfs(__constant char *, short *, char **);
#else
int scanfi(char *, int *, char **);
int scanfl(char *, long *, char **);
int scanfs(char *, short *, char **);
#endif

#if GPU_COMPILED
char *fgets(char *s, int maxsize, char *stdin1) {

  if (*stdin1 == '\0')
    return 0;

  char *sptr = s;
  char *iptr = stdin1;
  int i;
  for (i = 0; i < maxsize; i++, sptr++) {
    *sptr = *iptr++;

    if (*sptr == '\n' || *sptr == '\0') {
      i++;
      sptr++;
      break;
    }
  }
  *sptr = '\0';
  return s;
}

int fgetc(char stdin1) {
  int c = stdin1;
  return c;
}
#endif

#if GPU_COMPILED
int scanfi(__constant char *format, int *arg, char **stdin1) {
#else
int scanfi(char *format, int *arg, char **stdin1) {
#endif

  // move stdin ptr to beginning of number
  while (**stdin1 != '\0' && !isdigit(**stdin1) && **stdin1 != '-') {
    (*stdin1)++;
  }

  // if number is negative, then update sign
  int sign = 1;
  if (**stdin1 == '-') {
    sign = -1;
    (*stdin1)++;
  }

  // parse the integer argument
  *arg = atoi(*stdin1) * sign;

  // move stdin ptr to end of number
  while (**stdin1 != '\0' && isdigit(**stdin1)) {
    (*stdin1)++;
  }

  return 1;
}

#if GPU_COMPILED
int scanfl(__constant char *format, long *arg, char **stdin1) {
#else
int scanfl(char *format, long *arg, char **stdin1) {
#endif
  // move stdin ptr to beginning of number
  while (**stdin1 != '\0' && !isdigit(**stdin1) && **stdin1 != '-') {
    (*stdin1)++;
  }

  // if number is negative, then update sign
  int sign = 1;
  if (**stdin1 == '-') {
    sign = -1;
    (*stdin1)++;
  }

  // parse the integer argument
  *arg = atoi(*stdin1) * sign;

  // move stdin ptr to end of number
  while (**stdin1 != '\0' && isdigit(**stdin1)) {
    (*stdin1)++;
  }

  return 1;
}

#if GPU_COMPILED
int scanfs(__constant char *format, short *arg, char **stdin1) {
#else
int scanfs(char *format, short *arg, char **stdin1) {
#endif

  // move stdin ptr to beginning of number
  while (**stdin1 != '\0' && !isdigit(**stdin1) && **stdin1 != '-') {
    (*stdin1)++;
  }

  // if number is negative, then update sign
  int sign = 1;
  if (**stdin1 == '-') {
    sign = -1;
    (*stdin1)++;
  }

  // parse the integer argument
  *arg = atoi(*stdin1) * sign;

  // move stdin ptr to end of number
  while (**stdin1 != '\0' && isdigit(**stdin1)) {
    (*stdin1)++;
  }

  return 1;
}

#endif
