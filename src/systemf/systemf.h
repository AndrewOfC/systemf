#pragma once
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
#ifndef SYSTEMF_SYSTEMF_H
#define SYSTEMF_SYSTEMF_H

#ifdef __GNUC__
#define SYSTEMF_PARAMCHECK_ATTR __attribute__ ((format (printf, 1, 2)))
#else
#warning no printf param checking
#define SYSTEMF_PARAMCHECK_ATTR
#endif

#define SYSTEMF_MAXIMUM_SMALL_BUFFER 256

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief format and execute system command
 *
 * @param command printf style string
 * @param ... printf style parameters
 * @return return value of underlying system(const char *call)
 */
int systemf(const char *command, ...) SYSTEMF_PARAMCHECK_ATTR;

#ifdef __cplusplus
}
#endif

#endif //SYSTEMF_SYSTEMF_H
