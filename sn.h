typedef struct {
	ssize_t nn;
	unsigned long *ns; // little-endian
} SN;

enum {
	SN_Carry,
};

enum {
	SN_Cumul,
};

SN sn_alloc0 (ssize_t);

int   sn_compar  (SN, SN);
ulong sn_add     (SN, SN, SN);
ulong sn_sub     (SN, SN, SN);
void  sn_mul     (SN, SN, SN, unsigned long flags);
void  sn_shlWord (SN, SN, long);
