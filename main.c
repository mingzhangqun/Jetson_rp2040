#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/flash.h"
#include "hardware/watchdog.h"
#include "hardware/structs/ssi.h"
#include "hardware/structs/ioqspi.h"


int main() {
    uint32_t count = 0;

    stdio_init_all();

    while (true) {
#if (RP2040_FACTORY)
        printf("Run in flash %d!\n", count++);
#else
        printf("Run in ram %d!\n", count++);
#endif
        sleep_ms(1000);
    }

    return 0;
}
