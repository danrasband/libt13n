/**
 * t13n.c Code for transliteration.
 */

#include "t13n.h"
#include "languages.h"

typedef struct t13nTypeProc {
  t13nType type;
  void *proc;
} t13nTypeProc;

t13nTypeProc procs[] = {
  {
    RomanizeHangul,
    &test,
  },
  {
    HangulizeRoman,
    &test,
  },
};

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
