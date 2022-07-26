#include <stdio.h>
#include <stdint.h>

union reg
{
  uint32_t eax; // EAX REGISTRADO DE 32 BITS 
  uint16_t ax; // AX REGISTRADO DE 16 BITS

  struct
  {
    uint8_t al; // AL REGISTRADO DE 8 BITS MENOS SIGNIFICATIVO
    uint8_t ah; // AH REGISTRADO DE 8 BITS MAIS SIGNIFICATIVO
  };
};

int main(void)
{
  union reg x = {.eax = 0x11223344};

  printf("AH: %02x\n"
         "AL: %02x\n"
         "AX: %04x\n"
         "EAX: %08x\n",
         x.ah,
         x.al,
         x.ax,
         x.eax);
}