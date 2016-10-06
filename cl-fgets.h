/* 
 * cl-fgets.h
 * Reading line by line from a string, to emulate reading from FILE stream 
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


#ifndef CL_FGETS_H
#define CL_FGETS_H

char* fgets(char *s, int maxsize, char* stdin1, int* idxptr)
{
  //TODO: what happens when we encounter the NUL char
  if(*(stdin1+*idxptr) == '\0')
    return 0;

  char* sptr = s;
  char* iptr = stdin1+*idxptr;
  int i;
  for(i = 0; i < maxsize; i++, sptr++)
  {
    *sptr = *iptr++;

    if(*sptr == '\n' || *sptr == '\0')
    {
      i++;
      sptr++;
      break;
    }
  }
  *sptr = '\0';
  *idxptr += i;
  return s;
}

#endif
