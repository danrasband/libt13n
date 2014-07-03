/**
 * t13n.h - The transliteration library header file.
 *
 * Copyright (c) 2014, Daniel Rasband <danrasband@gmail.com>
 */

#ifndef __T13N_H__
#define __T13N_H__

#include "stdlib.h"

/* Accepted Transliteration Types */
typedef enum t13nType {
  RomanizeHangul,
  HangulizeRoman,
} t13nType;

/* Interface for transliterating a string. */

size_t transliterate(char *source, char *buffer, size_t bufferSize, t13nType t13nOperation);


#endif
