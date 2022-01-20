#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/flash.h"
#include "hardware/watchdog.h"
#include "hardware/structs/ssi.h"
#include "hardware/structs/ioqspi.h"


#if (RP2040_FACTORY)
extern uint8_t bin[];
extern uint32_t bin_size;
#endif

int main() {
    uint32_t count = 0;

    stdio_init_all();

#if (RP2040_FACTORY)
    {
        uint32_t i = 0;
        uint8_t *pu8 = (uint8_t*)0x20000000;

        for (i=0; i<bin_size; i++) {
            pu8[i] = bin[i];
        }

        printf("Jump to ram: 0x%x\n", (uint32_t)pu8);
        watchdog_reboot((uint32_t)pu8, SRAM_END, 0);
    }
#endif

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
