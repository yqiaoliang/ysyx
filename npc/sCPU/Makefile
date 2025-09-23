sCPU_DESIGN_NAME := sCPU
sCPU_ORIGINAL_DIR := /home/yqiaoliang/Desktop/digital/ysyx/npc/sCPU
VERILOG_FILES := $(shell find $(sCPU_ORIGINAL_DIR) -maxdepth 2 -name "*.v")
SIM_CPP_FILE := $(shell find $(sCPU_ORIGINAL_DIR) -maxdepth 1 -name "*_sim.cpp")
SIM_C_FILE := $(shell find $(sCPU_ORIGINAL_DIR) $(sCPU_ORIGINAL_DIR)/src -name "*.c")
NXDC_FILES := $(shell find $(sCPU_ORIGINAL_DIR) -maxdepth 1 -name "*.nxdc")

sCPU_VERILATOR = verilator
sCPU_VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

sCPU_BUILD_DIR = /home/yqiaoliang/Desktop/digital/ysyx/npc/sCPU/build
OBJ_DIR = $(sCPU_BUILD_DIR)/obj_dir
sCPU_BIN = $(sCPU_BUILD_DIR)/$(sCPU_DESIGN_NAME)
$(shell mkdir -p $(sCPU_BUILD_DIR))
INC_PATH ?=
include $(NVBOARD_HOME)/scripts/nvboard.mk
sCPU_LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
# INC_PATH += $(NEMU_HOME)/include

sCPU_INCFLAGS = $(addprefix -I, $(INC_PATH))
$(info #sCPU_INCFLAGS = $(sCPU_INCFLAGS))
sCPU_CXXFLAGS += $(sCPU_INCFLAGS) -DTOP_NAME="\"V$(sCPU_DESIGN_NAME)\""
sCPU_VSRCS = $(VERILOG_FILES)
sCPU_CSRCS = $(SIM_C_FILE) $(SIM_CPP_FILE)
sCPU_ARGS = /home/yqiaoliang/Desktop/digital/ysyx/clone_hub/ics2024/nemu/build/riscv32-nemu-interpreter-so
# sCPU_ARGS = /home/yqiaoliang/Desktop/digital/ysyx/clone_hub/ics2024/nemu/tools/spike-diff/build/riscv32-spike-so
# $(info sCPU_CSRCS $(sCPU_CSRCS))


all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc $(VERILOG_FILES) --exe $(SIM_CPP_FILE)

	$(MAKE) -C $(CURDIR)/obj_dir -f ${sCPU_DESIGN_NAME}.mk $(sCPU_DESIGN_NAME)

	$(CURDIR)/obj_dir/$(sCPU_DESIGN_NAME)


nvboard:
	@rm -rf $(sCPU_BUILD_DIR)
	@mkdir -p $(sCPU_BUILD_DIR)
	$(sCPU_VERILATOR) $(sCPU_VERILATOR_CFLAGS) \
		--trace \
		--top-module $(sCPU_DESIGN_NAME) $(sCPU_VSRCS) $(sCPU_CSRCS) $(NVBOARD_ARCHIVE) \
		$(addprefix -CFLAGS , $(sCPU_CXXFLAGS)) $(addprefix -LDFLAGS , $(sCPU_LDFLAGS)  -lreadline) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(sCPU_BIN))
# 	$(sCPU_BIN) $(IMAGE).bin
	

	

include /home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/Makefile
