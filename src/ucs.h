#ifndef LIBT13N_UCS_H__
#define LIBT13N_UCS_H__

#include <stdlib.h>
#include <stdint.h>

#define UCS_HANGUL_JAMO_BASE               0x1100 // 4352
#define UCS_HANGUL_JAMO_COMPATIBILITY_BASE 0x3130 // 12592
#define UCS_HANGUL_JAMO_EXTENDED_A_BASE    0xA960 // 43360
#define UCS_HANGUL_SYLLABLES_BASE          0xAC00 // 44032

/*
Unicode character point. Up to 0xffff (65,535).
*/
typedef uint16_t ucschar;

/*
Takes a pointer to a source string, a pointer to an allocated ucschar string,
and a buffer size for how much space has been allocated for the destination
string.

Returns 0 if successful, otherwise returns the total needed buffersize to
complete the operation. Returns a negative value if an error occurred.
*/
int utf8_to_ucs(char *source, ucschar *destination, size_t size);

/* Same as utf8_to_ucs, but backwards. */
int ucs_to_utf8(ucschar *source, char *destination, size_t size);

/* Number of unicode characters in string, up to but not including the NULL
character. */
size_t ucs_strlen(const ucschar *ucsstr);


#endif
