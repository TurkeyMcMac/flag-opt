#include "flag-opt.h"

int fo_parse(uint64_t *flags, const char *opts, const int8_t map[FO_N_PCHAR])
{
	int i;
	int8_t c, bit;
	for (i = 0; opts[i] != '\0'; ++i) {
		c = opts[i];
		c -= FO_UPCHAR_MAX;
		if (c < 0)
			return ~i;
		bit = map[c];
		if (bit < 0)
			return ~i;
		*flags |= 1 << bit;
	}
	return 0;
}
