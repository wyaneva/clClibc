/* 
 * cl-string.h
 * String manipulation. 
 *
 * Copyright 2016 Vanya Yaneva, The University of Edinburgh
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


#ifndef CL_STRING_H
#define CL_STRING_H

int strcmp(const char* s1, char* s2)
{
  while(*s1 && (*s1 == *s2))
  {
    s1++;
    s2++;
  }

  return (*s1 < *s2) ? -1 : *s1 > *s2;
}

char *strcpy(char* dest, char* source)
{
  char* destptr = dest;
  do
  {
    *destptr = *source++;
  }
  while(*destptr++);

  return dest;
}

size_t strlen(char* str)
{
  size_t len = 0; 
  while(*str++)
  {
    len++;
  }

  return len;
}

#endif
