#include <stdlib.h>
#include "sn.h"
#include "prim.h"
#include "util.h"

// z = x << n
void sn_shlWord (SN z, SN x, long n) {
	// must have c99 semantics, i.e. ∀ x y . x*(x/y) >= 0
	long m = n/(sizeof (long) << 3);
	ulong ci = 0, co;
	ssize_t ii;
	
	n %= sizeof (long) << 3;
	
	for (ii = m; ii < z.nn; ii++) {
		if (ii - m < x.nn) {
			co = x.ns[ii - m] >> (sizeof (long) << 3) - n;
			if (ii >= 0) z.ns[ii] = x.ns[ii - m] << n;
		}
		if (ii >= 0) z.ns[ii] |= ci;
		ci = co;
	}
}
