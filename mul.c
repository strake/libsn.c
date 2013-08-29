#include <stdlib.h>
#include "sn.h"
#include "prim.h"
#include "util.h"

// z = x y
void sn_mul (SN z, SN x, SN y, ulong flags) {
	ssize_t ii, jj;
	for (ii = z.nn - 1; ii >= 0; ii--) {
		ulong yw = ii < y.nn ? y.ns[ii] : 0; // in case that z.ns = y.ns
		ulong c, w;
		for (jj = ii; jj >= 0; jj--) {
			PRIM_MUL(c, w, jj < x.nn ? x.ns[jj] : 0, jj == 0 ? yw : ii-jj < y.nn ? y.ns[ii-jj] : 0);
			if (jj == ii && !(flags >> SN_Cumul & 1)) z.ns[ii] = 0;
			sn_add ((SN){ .nn = z.nn - ii, .ns = z.ns + ii },
			        (SN){ .nn = z.nn - ii, .ns = z.ns + ii },
			        (SN){ .nn = 2, .ns = (ulong []){ w, c } });
		}
	}
}
