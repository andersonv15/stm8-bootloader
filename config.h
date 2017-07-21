#ifndef CONFIG_H
#define CONFIG_H

#include "stm8s.h"

#define BAUDRATE        115200

/* flash block size */
#define BLOCK_SIZE      64
#define RX_BUFFER_LEN   (BLOCK_SIZE + 8)

/* application address */
#define BOOT_ADDR        0x8400
#define BOOT_ADDR_S     "0x8400"
#define BOOT()          __asm__("jp " BOOT_ADDR_S)

/* entry jumper */
#define BOOT_PIN        3
#define BOOT_PIN_IDR    PD_IDR
#define BOOT_PIN_CR1    PD_CR1

typedef void boot();
#define BOOT_CALL(addr) ((boot*) addr)()

#endif /* CONFIG_H */