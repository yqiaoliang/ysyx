# AM_HOME ?= /home/yqiaoliang/Desktop/digital/ysyx/clone_hub/ics2024/abstract-machine

NAME = minirvEMU
SRCS = gui.c main.c riscv_sim.c memory.c utils.c
ARCH = native
export ARCH

include $(AM_HOME)/Makefile

.PHONY: run
run: image
	./build/minirvEMU-native.elf

