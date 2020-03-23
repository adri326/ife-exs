#ifndef CSWAP_H
#define CSWAP_H

#define cswap(type, a, b, c) {type d = a; a = b; b = c; c = d;}
void cswap2(int* a, int* b, int* c);

#endif // CSWAP_H
