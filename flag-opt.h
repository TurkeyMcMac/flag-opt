#ifndef _FLAG_OPT_H

#define _FLAG_OPT_H

#include <limits.h>
#include <stdint.h>

/* Highest code of an unprintable character excluding DEL. */
#define FO_UPCHAR_MAX '\31'

/* Number of printable characters. */
#define FO_N_PCHAR (CHAR_MAX - FO_UPCHAR_MAX)

/* Check if str is a string of options. */
#define FO_HAS_OPTS(str) (*(str) == '-')

/* Get index corresponding to the character c. */
#define FO_MAPPING(map, c) ((map)[(c) - FO_UPCHAR_MAX])

/* bitwise OR into flags the bits corresponding to the options in opts according
 * to map.
 * Note: opts should not include the initial '-'. */
int fo_parse(uint64_t *flags, const char *opts, const int8_t map[FO_N_PCHAR]);

#endif /* Header guard */
