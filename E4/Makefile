NAME = minirvEMU
SRCS = minirv.c
ARCH = native
export ARCH

include $(AM_HOME)/Makefile

.PHONY: run
run: image
	./build/minirvEMU-native.elf
