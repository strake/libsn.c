#include <stdlib.h>
#include "sn.h"
#include "prim.h"
#include "util.h"

int sn_compar (SN x, SN y) {
	for (ssize_t ii = MAX(x.nn, y.nn) - 1; ii >= 0; ii--) {
		ulong xw = ii < x.nn ? x.ns[ii] : 0,
		      yw = ii < y.nn ? y.ns[ii] : 0;
		if (xw != yw) return (xw - yw);
	}
	return 0;
}
