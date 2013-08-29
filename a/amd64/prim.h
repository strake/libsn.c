#define PRIM_ADD(c_, z_, x_, y_) asm ("movq %[x], %[z]; addq %[y], %[z]; movq $0, %[c]; adcq $0, %[c];" : [c] "=rm" (c_), [z] "=&rm" (z_) : [x] "g" (x_), [y] "g" (y_))
#define PRIM_SUB(c_, z_, x_, y_) asm ("movq %[x], %[z]; subq %[y], %[z]; movq $0, %[c]; sbbq $0, %[c];" : [c] "=rm" (c_), [z] "=&rm" (z_) : [x] "g" (x_), [y] "g" (y_))
#define PRIM_MUL(c_, z_, x_, y_) asm ("mulq %[y]" : [z] "=a" (z_), [c] "=d" (c_) : [x] "%a" (x_), [y] "rm" (y_))
