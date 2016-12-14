/* cl-ctype.h
 * Character testing 
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


#ifndef CL_CTYPE_H
#define CL_CTYPE_H

int isalnum(int);
int isalpha(int);
//int iscntrl(int);
int isdigit(int);
//int isgraph(int);
int islower(int);
//int isprint(int);
//int ispunct(int);
//int isspace(int);
int isupper(int);
//int isxdigit(int);
//int tolower(int);
int toupper(int);


int isalnum(int c)
{
  return isalpha(c) || isdigit(c);
}

int isalpha(int c)  
{
  return isupper(c) || islower(c);
}

int isdigit(int c)  
{
  return c >= '0' && c <= '9';
}

int islower(int c)  
{
  return c >= 'a' && c <= 'z';
}

int isupper(int c)  
{
  return c >= 'A' && c <= 'Z';
}

int toupper(int c)
{
  if( c >= 'a' && c <= 'z')
    c = c -('a' - 'A');

  return c;
}

#endif 
