#include "bootos.h"

void main() {
    puts("test\r");

    char input[128];

    while(1) {
        put('>');
        gets(input, sizeof(input));

        puts(input);
    }
}
