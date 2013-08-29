#include <stdlib.h>
#include "sn.h"
#include "prim.h"
#include "util.h"

// z = x ± y
static ulong sn_addsub (SN z, SN x, SN y, int sub) {
	ulong ci = 0, co;
	ssize_t ii;
	for (ii = 0; ii < z.nn; ii++) {
		ulong xw = ii < x.nn ? x.ns[ii] : 0, yw = ii < y.nn ? y.ns[ii] : 0;
		if (sub) PRIM_SUB(co, z.ns[ii], xw, yw);
		else     PRIM_ADD(co, z.ns[ii], xw, yw);
		z.ns[ii] += ci;
		ci = co;
	}
	return (ci ? 1 << SN_Carry : 0);
}

// z = x + y
ulong sn_add (SN z, SN x, SN y) {
	return sn_addsub (z, x, y, 0);
}

ulong sn_sub (SN z, SN x, SN y) {
	return sn_addsub (z, x, y, 1);
}
