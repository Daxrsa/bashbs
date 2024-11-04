/* birchutils.c v1.1 */
#include "birchutils.h"
//#include <birchutils.h>

int16 nstoh(int16 srcport) {
    int16 dstport;  
    int8 a, b;

    a = ((srcport & 0xff00) >> 8);
    b = (srcport & 0xff);
    dstport = 0;
    dstport = (b << 8) + a;

    return dstport;
}

void zero(int8 *str, int16 size) {
    int8 *p;
    int16 n;

    for (n=0, p=str; n<size; n++, p++)
        *p = 0;

    return;
}

// 10.0.0.1
// 0x0100000a
// 0xddccbbaa
// 0x00ff0000
// --------------
// 0xdd000000
// 0xdd

int8 *todotted(in_addr_t ip) {
    int8 a, b, c, d;
    static int8 buf[16];

    d = ((ip & 0xff000000) >> 24);
    c = ((ip & 0xff0000) >> 16);
    b = ((ip & 0xff00) >> 8);
    a = ((ip & 0xff));

    zero(buf, 16);
    snprintf((char *)buf, 15, "%d.%d.%d.%d",
        a, b, c, d);

    return buf;
}









