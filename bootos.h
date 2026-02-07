void _start() {
    main();
    exit();
}

void put(char c) {
    asm volatile (
        "pusha\n"
        "mov al, [bp+4]\n"
        "int 0x22\n"
        "popa\n"
    );
}

void exit() {
    asm volatile (
        "int 0x20\n"
    );
}
