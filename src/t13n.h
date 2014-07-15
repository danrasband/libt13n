/**
 * t13n.h - The transliteration library header file.
 *
 * Copyright (c) 2014, Daniel Rasband <danrasband@gmail.com>
 */

#ifndef __T13N_H__
#define __T13N_H__

#include <stdlib.h>
#include "ucs.h"

// The character - where all the most important data is stored.
typedef struct character {
  // The UCS character codepoint.
  ucschar codepoint;

  // The transliterated data. This could be a struct or a string of letters.
  void *data;

  // For traversal between characters.
  struct character *prevCharacter;
  struct character *nextCharacter;
} character;

// The word - where a word's characters are kept track of.
typedef struct word {
  // Head and tail of word's characters.
  character *firstCharacter;
  character *lastCharacter;

  // Traverse forward and backward between words
  struct word *prevWord;
  struct word *nextWord;

  // Whether or not this is a non-word, and the non-word ucschar if it isn't a
  // word.
  bool isNonWord;
  ucschar nonWord;

  // The length of this word, in number of ucschars.
  size_t length;
} word;

// The list of words and non-words.
typedef struct wordList {
  // Head and tail words for this list of words.
  word *firstWord;
  word *lastWord;

  // Transliteration functions.
  void (*listTransliterator)(struct wordList* job);
  void (*wordTransliterator)(word *w);
  void (*characterTransliterator)(constant character *c, void **data);

  // Utility
  void (*free)(void *data);

  // Size of word/non-word list.
  size_t length;
  bool isComplete;
} wordList;

// Word list functions
wordList *wordListCreate(void);
void wordListFree(wordList *wordList);

// Word functions
word *wordCreate(void);
void wordFree(word *word);

// Character functions
character *characterCreate(void);
void characterFree(character *character);

#endif
