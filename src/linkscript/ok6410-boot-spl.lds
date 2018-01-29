OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x0c000000;
	. = ALIGN(4);
	.text :
	{
		*(.vectors)
		./src/startup/start.o (.text*)
		*(.text*)
	}
	
	. = ALIGN(4);
	.data :
	{
		*(.data*)
	}
	
	. = ALIGN(4);
	__bss_start =.;
	.bss :
	{
		*(*.bss*)
	}
	__bss_end =.;
}