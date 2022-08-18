#include <stdio.h>
#include <string.h>

void bin(unsigned int, char []);
int rightrot(unsigned int, unsigned char);

int main()
{
    unsigned int i, x = 1205, n = 5;
    char s[35] = {};

    bin(x, s);
    for (i = 0; i < 35; ++i)
        putchar(s[i]);
    putchar('\n');
    x = rightrot(x, n);
    bin(x, s);
    for (i = 0; i < 35; ++i)
        putchar(s[i]);
    putchar('\n');
    getchar();
    return 0;
}

void bin(unsigned int x, char s[])
{
    int i, j, k;
    unsigned char bt[4] = {0};
    char arr[9] = {};

    for (j = 0; j < 4; ++j) {
        if (((x >> j*8) == 0) && (j > 0)) break;
        bt[j] = (unsigned char) (x >> j*8);
    }
    strcpy(s, "0b");
    for (k = 0; k < j; ++k) {
        for (i = 0; i < 8; ++i) {
            switch ((bt[j - k - 1] >> i) & 0b00000001)
            {
                case 1: arr[7 - i] = '1'; break;
                case 0: arr[7 - i] = '0'; break;
            }
        }
        strcat(s, arr);
    }
}

int rightrot(unsigned int x, unsigned char n)
{
    int y, i;

    for (i = 0; i < n; ++i) {
        y = x & ~(~0 << 1);
        y <<= 31;
        x >>= 1;
        x |= y;
    }
    return x;
}
