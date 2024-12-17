ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    .text : 
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
    } > FLASH

    .data : 
    {
        *(.data)
        . = ALIGN(4);
    } > SRAM AT > FLASH

    .bss :
    {
        *(.bss)
    } > SRAM
}
