//
// Created by andrew on 11/3/23.
//
#pragma once
#ifndef SYSTEMF_SYSTEMF_H
#define SYSTEMF_SYSTEMF_H

#ifdef __GNUC__
#define SYSTEMF_PARAMCHECK_ATTR __attribute__ ((format (printf, 1, 2)))
#else
#warning no printf param checking
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
