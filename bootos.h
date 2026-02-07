void _start() {
    asm volatile (
        "mov ax, 0\n"
        "mov ds, ax\n"
        "mov es, ax\n"
        "mov ax, 0x7000\n"
        "mov ss, ax\n"
        "mov sp, 0xFFFE\n"
    );
    main();
    exit();
}


void exit() {
    asm volatile (
        "int 0x20\n"
    );
}

char get() {
    asm volatile (
        "int 0x21\n"
        "mov ah, 0\n"
    );
}

void put(char c) {
    asm volatile (
        "mov ax, [bp+4]\n"
        "int 0x22\n"
    );
}

void puts(char str[]) {
    char c = '\xff';
    while (c != 0) {
        c = *str;
        str++;
        if (c != 0){
            put(c);
        }
    }
}

char* gets() {
    char str[128];
    char* pointer = &str;
    char* end = pointer+127;

    char c = '\xff';

    while (c != '\r') {
        c = get();
        if (c != '\r' && pointer == end) {
            continue;
        }
        *pointer = c;
        pointer++;
    }

    return str;
}
