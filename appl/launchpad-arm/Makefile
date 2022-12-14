
REVISION := $(shell git status -bs -u no|tr / -)
ifeq ("$(REVISION)", "")
    REVISION := $(shell svnversion -n)
endif

CROSS=arm-none-eabi-
BOARD=$(shell uname -m)
ifeq ("$(BOARD)", "armv7l")
   CROSS=
endif
LANG=C


BOARD = lp-stellaris
LANG=C
%.lst: %.elf
	$(CROSS)objdump -D $< >$@

%.hex: %.elf
	$(CROSS)objcopy -O ihex $< $@

%.o: %.asm buildinfo
	$(CROSS)as --warn --fatal-warnings -alms=lp-stellaris.list -I../../arm -I ../../arm/devices/lm4f120xl -I ../../shared -o $@ $<

all: lp-stellaris.hex lp-stellaris.lst

lp-stellaris.elf: lp-stellaris.o ../../arm/amforth.s buildinfo
	$(CROSS)ld -T memmap $< -o $@ 
	$(CROSS)objcopy lp-stellaris.elf lp-stellaris.bin -O binary
	$(CROSS)objcopy lp-stellaris.elf lp-stellaris.hex -O ihex

clean:
	rm -f *.elf *.bin *.o *.log *.lst *.hex *.list words/build-info.s

upload: lp-stellaris.elf
	lm4flash lp-stellaris.bin

buildinfo: words/build-info.tmpl
	cat words/build-info.tmpl | sed "s/%d/ `date`/" | sed "s/%r/${REVISION}/" > words/build-info.s
