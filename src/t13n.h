/**
 * t13n.h - The transliteration library header file.
 *
 * Copyright (c) 2014, Daniel Rasband <danrasband@gmail.com>
 */

#ifndef __T13N_H__
#define __T13N_H__

#include <stdlib.h>
#include "ucs.h"

/* Accepted Transliteration Types */
typedef enum t13nType {
  RomanizeHangul,
  HangulizeRoman,
} t13nType;

typedef struct character {
  ucschar codepoint;
  void *data;
  struct character *prevCharacter;
  struct character *nextCharacter;
} character;

typedef struct word {
  character *firstCharacter;
  character *lastCharacter;
  struct word *prevWord;
  struct word *nextWord;
  ucschar *separatorAfter;
} word;

typedef struct transliterationJob {
  word *firstWord;
  word *lastWord;
  void (*listTransliterator)(struct transliterationJob* job);
  void (*wordTransliterator)(word *w);
  void (*characterTransliterator)(character *c);
  size_t length;
} transliterationJob;


#endif
