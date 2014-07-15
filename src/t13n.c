/**
 * t13n.c Code for transliteration.
 */

#include "t13n.h"
#include "languages.h"

/**
 * Word List Functions
 */

wordList *wordListCreate(void)
{
  struct wordList *wordList;

  if ((wordList = malloc(sizeof(*wordList))) == NULL) {
    return NULL;
  }

  // Instantiate with defaults.
  wordList->firstWord = wordList->lastWord = NULL;
  wordList->length = 0;
  wordList->free = NULL;

  return wordList;
}

/**
 * Word Functions
 */
word *wordCreate(void)
{
  struct word *word;

  if ((word = malloc(sizeof(*word))) == NULL) {
    return NULL;
  }

  // Instantiate with defaults.
  word->firstCharacter = word->lastCharacter = NULL;
  word->prevWord = word->nextWord = NULL;
  word->length = 0;

  return word;
}

/**
 * Character Functions
 */
character *characterCreate(void)
{
  struct character *character;

  if (character = malloc(sizeof(*character))) == NULL) {
    return NULL;
  }

  character->data = NULL;
  character->prevCharacter = character->nextCharacter = NULL;

  return character;
}


/*
// Add this to transliterate.c
size_t transliterate(char *source, char *buffer, size_t bufferSize, t13nType t13nOperation)
{
  size_t result = 0;
  size_t (*foo)(char *src, char *b, size_t n) = NULL;

  for (int i = 0; i < sizeof(procs) / sizeof(t13nTypeProc); i++) {
    if (procs[i].type == t13nOperation) {
      foo = procs[i].proc;
      result = foo(source, buffer, bufferSize);
    }
  }

  return bufferSize;
}
*/
