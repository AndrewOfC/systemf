/*
MIT License

Copyright (c) 2023 Andrew E. Page

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "systemf/systemf.h"

/*
 *
 */
int systemf(const char *command, ...)
{
    va_list args ;
    int len, result ;
    char buffer[SYSTEMF_MAXIMUM_SMALL_BUFFER], *bufferPtr = NULL ; // initial size
    
    va_start(args, command) ;
    len = vsnprintf(buffer, sizeof(buffer), command, args) ;
    va_end(args) ;
    
    if( len >= sizeof(buffer) ) {
        bufferPtr = malloc(len+1) ;
	assert(bufferPtr != NULL) ;
	
	va_start(args, command) ;
        vsnprintf(bufferPtr, len+1, command, args) ;
	va_end(args) ;
	
        result = system(bufferPtr) ;
        free(bufferPtr) ;
    }
    else
        result = system(buffer) ;

    return result ;
}
