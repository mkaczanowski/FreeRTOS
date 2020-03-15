CC=e-gcc
CFLAGS=-I.
FREERTOSSRC=../../Source
INCLUDES= -g -I$(FREERTOSSRC)/include -I$(FREERTOSSRC)/portable/GCC/Epiphany -I.
DEPS = $(FREERTOSSRC)/portable/GCC/Epiphany/portmacro.h Makefile FreeRTOSConfig.h

ESDK=${EPIPHANY_HOME}
ELIBS=${ESDK}/tools/host/lib
EINCS=${ESDK}/tools/host/include
ELDF=internal.ldf

vpath %.c .:$(FREERTOSSRC)/:$(FREERTOSSRC)/portable/MemMang:$(FREERTOSSRC)/portable/GCC/Epiphany
vpath %.s $(FREERTOSSRC)/portable/GCC/Epiphany

run: main e_main.srec
	e-reset && LD_LIBRARY_PATH=${ELIBS} ./main

%.srec: e_main.elf
	e-objcopy --srec-forceS3 --output-target srec $< $@

%.elf: $(ELDF) tasks.o port.o portasm.o list.o heap_1.o %.o
	$(CC) -g -T$< -Wl,--gc-sections -o $@ $(filter-out $<,$^) -le-lib

main: main.c $(DEPS)
	gcc $< -o $@  -I ${EINCS} -L ${ELIBS} -le-hal -le-loader

clean:
	rm -f main *.o *.srec *.elf

.SECONDARY:
%.o: %.c  $(DEPS)
	$(CC) -fdata-sections -ffunction-sections -c -o $@ $< $(INCLUDES)

%.o: %.s  $(DEPS)
	$(CC) -c -o $@ $< $(INCLUDES)
