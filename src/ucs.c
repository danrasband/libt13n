#include "ucs.h"

/*
UCS                | 1st byte | 2nd byte | 3rd byte | 4th byte
---------------------------------------------------------------
U+0000..U+007F      00..7F
U+0080..U+07FF      C2..DF      80..BF
U+0800..U+0FFF      E0          A0..BF      80..BF
U+1000..U+FFFF      E1..EF      80..BF      80..BF
U+10000..U+3FFFF    F0          90..BF      80..BF      80..BF
U+40000..U+FFFFF    F1..F3      80..BF      80..BF      80..BF
U+100000..U+10FFFF  F4          80..8F      80..BF      80..BF
*/
#define UTF8_CHAR_IN_RANGE(chr, min, max) (chr >= min && chr <= max)

int utf8_to_ucs(char *source, ucschar *destination, size_t size)
{
  size_t bufferUsed = 0;
  char a, b, c;

  while (a = *source++) {
    // 1 byte utf8
    if (a <= 0x7f) {
      *destination = a;
    }
    // 2 bytes
    else if (a <= 0xdf) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x80 + (a - 0xc2) + (b - 0x80)
    }
    // 3 bytes, 2nd byte starts at 0xa0
    else if (a == 0xe0) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0xa0, 0xbf)) {
        return -1;
      }

      c = *source++;
      if (!UTF8_CHAR_IN_RANGE(c, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x800 + (a - 0xe0) + (b - 0xa0) + (c - 0x80)
    }
    // 3 bytes, 2nd byte starts at 0x80
    else if (a <= 0xef) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0x80, 0xbf)) {
        return -1;
      }

      c = *source++;
      if (!UTF8_CHAR_IN_RANGE(c, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x800 + (a - 0xe0) + (b - 0x80) + (c - 0x80)
    }
    // 4 bytes, 2nd byte starting with 0x90
    else if (a == 0xf0) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0x90, 0xbf)) {
        return -1;
      }

      c = *source++;
      if (!UTF8_CHAR_IN_RANGE(c, 0x80, 0xbf)) {
        return -1;
      }

      d = *source++;
      if (!UTF8_CHAR_IN_RANGE(d, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x800 + (a - 0xe0) + (b - 0x90) + (c - 0x80) + (d - 0x80)
    }
    else if (a <= 0xf3) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0x80, 0xbf)) {
        return -1;
      }

      c = *source++;
      if (!UTF8_CHAR_IN_RANGE(c, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x800 + (a - 0xe0) + (b - 0x80) + (c - 0x80)
    }
    else if (a == 0xf4) {
      b = *source++;

      if (!UTF8_CHAR_IN_RANGE(b, 0x80, 0xbf)) {
        return -1;
      }

      c = *source++;
      if (!UTF8_CHAR_IN_RANGE(c, 0x80, 0xbf)) {
        return -1;
      }

      *destination = 0x800 + (a - 0xe0) + (b - 0x80) + (c - 0x80)
    }
    else {
      return -1;
    }

    destination++;
  }

  return b;
}

int ucs_to_utf8(ucschar *source, char *destination, size_t size)
{
  ucschar c;

  while (c = *source++) {
    if (c < 0x80) {
      *destination++ = c;
    }
    else if (c < 0x800) {
      *destination++ = 192 + c / 64;
      *destination++ = 128 + c % 64;
    }
    else if (c - 0xd800u < 0x800) {
      return -1;
    }
    else if (c < 0x10000) {
      *destination++ = 224 + c / 4096;
      *destination++ = 128 + c / 64 % 64;
      *destination++ = 128 + c % 64;
    }
    else if (c < 0x110000) {
      *destination++ = 240 + c / 262144;
      *destination++ = 128 + c / 4096 % 64;
      *destination++ = 128 + c / 64 % 64;
      *destination++ = 128 + c % 64;
    }
    else {
      return -1;
    }
  }

  return destination;
}

/**
 * Get the size of a null-terminated UCS string.
 */
size_t ucs_strlen(const ucschar *ucsstr)
{
  size_t len = 0;

  while (*ucsstr++ != NULL) {
    len++;
  }

  return len;
}
