#ifndef __TRANSLITERATE_H__
#define __TRANSLITERATE_H__

#include <stdlib.h>

/* Interface for transliterating a string. */

size_t transliterate(char *source, char *buffer, size_t bufferSize, t13nType t13nOperation);

#endif
