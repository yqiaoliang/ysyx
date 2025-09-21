DESIGN_NAME := sCPU
ORIGINAL_DIR := $(shell pwd)
VERILOG_FILES := $(shell find $(ORIGINAL_DIR) -maxdepth 1 -name "*.v")
SIM_CPP_FILE := $(shell find $(ORIGINAL_DIR) -maxdepth 1 -name "*_sim.cpp")
NXDC_FILES := $(shell find $(ORIGINAL_DIR) -maxdepth 1 -name "*.nxdc")

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(DESIGN_NAME)
$(shell mkdir -p $(BUILD_DIR))
INC_PATH ?=
include $(NVBOARD_HOME)/scripts/nvboard.mk
# INC_PATH += $(NEMU_HOME)/include

INCFLAGS = $(addprefix -I, $(INC_PATH))
$(info #INCFLAGS = $(INCFLAGS))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(DESIGN_NAME)\""
VSRCS = $(VERILOG_FILES)
CSRCS = $(SIM_CPP_FILE)

all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc $(VERILOG_FILES) --exe $(SIM_CPP_FILE)

	$(MAKE) -C $(CURDIR)/obj_dir -f ${DESIGN_NAME}.mk $(DESIGN_NAME)

	$(CURDIR)/obj_dir/$(DESIGN_NAME)


nvboard:
	@rm -rf $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--trace \
		--top-module $(DESIGN_NAME) $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE) \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))
	$(BIN)

	

	

include /home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/Makefile
