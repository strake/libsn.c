#include <memory.h>
#include <stdlib.h>
#include "sn.h"
#include "prim.h"
#include "util.h"

SN sn_alloc0 (ssize_t nn) {
	SN x = { .nn = nn, .ns = malloc (sizeof (long)*nn) };
	if (x.ns) memset (x.ns, 0, sizeof (long)*nn);
	return x;
}
