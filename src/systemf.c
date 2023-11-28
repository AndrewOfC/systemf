//
// Created by andrew on 11/3/23.
//
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
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
