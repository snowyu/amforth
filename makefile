# user modifiable secion is up here

AVRDUDE=avrdude 
AVRA=/opt/cdk4avr/bin/avra

default: menu

bf.hex: *.asm words/*.asm devices/*.asm
	$(AVRA)  -I $(INCLUDE) --listmac -l bf.lst -m bf.map bf.asm -o bf.hex

bf: bf.hex bf.eep.hex
	$(AVRDUDE) -c avr911 -p atmega169 -P /dev/ttyUSB2 -e -U flash:w:bf.hex:i -U eeprom:w:bf.eep.hex:i

p16.hex: *.asm words/*.asm devices/*.asm
	$(AVRA) -I $(INCLUDE) --listmac -l p16.lst -m p16.map p16.asm

p16: p16.hex p16.eep.hex
	$(AVRDUDE) -c stk200 -p atmega32 -P /dev/parport0 -e -U flash:w:p16.hex:i -U eeprom:w:p16.eep.hex:i

p8.hex: *.asm words/*.asm devices/*.asm
	$(AVRA) -I $(INCLUDE) --listmac -l p8.lst -m p8.map p8.asm

p8: p8.hex p8.eep.hex
	$(AVRDUDE) -c stk200 -p atmega8 -P /dev/parport0 -e -U flash:w:p8.hex:i -U eeprom:w:p8.eep.hex:i

asuro.hex: *.asm words/*.asm devices/*.asm
	$(AVRA) -I $(INCLUDE) --listmac -l asuro.lst -m asuro.map asuro.asm

asuro: asuro.hex asuro.eep.hex
	$(AVRDUDE) -c stk200 -p atmega8 -P /dev/parport0 -e -U flash:w:asuro.hex:i -U eeprom:w:asuro.eep.hex:i

clean:
	rm -f p16.hex p16.eep.hex p16.lst p16.map p16.cof p16.obj
	rm -f p8.hex p8.eep.hex p8.lst p8.map p8.cof p8.obj
	rm -f bf.hex bf.eep.hex bf.lst bf.map bf.cof bf.obj
	rm -f asuro.hex asuro.eep.hex asuro.lst asuro.map asuro.cof asuro.obj

menu:
	@echo usage
	@echo make bf      -- AVR Butterfly with upload
	@echo make bf.hex  -- AVR Butterfly without upload
	@echo make p16     -- Evaluation Board atmega32 at 16 MHz with upload
	@echo make p16.hex -- Evaluation Board atmega32 at 16 MHz without upload
	@echo make p8      -- Evaluation Board atmega8 at 8 MHz with upload
	@echo make p8.hex  -- Evaluation Board atmega8 at 8 MHz without upload
	@echo make asuro   -- AREXX asuro controller in programmer
	@echo make asuro.hex  -- AVR asuro 
