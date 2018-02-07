OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
  IRAM (xrw) : ORIGIN = 0x0c000000, LENGTH = 8K
  DDRAM (xrw) : ORIGIN = 0x50000000, LENGTH = 256M
}

__stack = ORIGIN(DDRAM) + LENGTH(DDRAM);

ENTRY(_start)
SECTIONS
{
	.text : ALIGN(4)
	{
		*(.vectors)
		./src/startup/start.o (.text*)
		*(.text*)
	} >IRAM
	
	.data : ALIGN(4)
	{
		*(.data*)
	} >IRAM
	
	. = ALIGN(4);
	__bss_start = ADDR(.bss);
	.bss (NOLOAD): ALIGN(4)
	{
		*(*.bss*)
	} >DDRAM
	__bss_end = ADDR(.bss) + SIZEOF(.bss);
}