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

/* Get the index corresponding to the character c. To add an option with c, set
 * the lvalue returned to the offset which the correspond bit should have in a
 * set of flags. */
#define FO_MAPPING(map, c) ((map)[(c) - FO_UPCHAR_MAX])

/* bitwise OR into flags the bits corresponding to the options in opts according
 * to map. Invalid options are indicated in map by negative numbers. When an
 * invalid option is encountered the function immediately returns the index of
 * the invalid option with its bits inverted. If all goes well, 0 is returned.
 *
 * Note: opts should not include the initial '-'. */
int fo_parse(uint64_t *flags, const char *opts, const int8_t map[FO_N_PCHAR]);

#endif /* Header guard */
