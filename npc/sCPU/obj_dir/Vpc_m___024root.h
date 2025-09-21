// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpc_m.h for the primary calling header

#ifndef VERILATED_VPC_M___024ROOT_H_
#define VERILATED_VPC_M___024ROOT_H_  // guard

#include "verilated.h"

class Vpc_m__Syms;

class Vpc_m___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*2:0*/ sCPU__DOT__inst_type;
    CData/*0:0*/ sCPU__DOT__gpr_w_en;
    CData/*2:0*/ sCPU__DOT__ram_rw_byte;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst_CXX,31,0);
    VL_OUT(pc_o,31,0);
    VL_OUT(out_inst,31,0);
    IData/*31:0*/ sCPU__DOT__pc;
    IData/*31:0*/ sCPU__DOT__next_pc;
    IData/*31:0*/ sCPU__DOT__alu_data;
    IData/*31:0*/ sCPU__DOT__inst_sCPU;
    IData/*31:0*/ sCPU__DOT__imm_sCPU;
    IData/*31:0*/ sCPU__DOT__gpr_w_data;
    IData/*31:0*/ sCPU__DOT__rs1_data;
    IData/*31:0*/ sCPU__DOT__rs2_data;
    IData/*31:0*/ sCPU__DOT__ram_addr;
    IData/*31:0*/ sCPU__DOT__ram_w_data;
    IData/*31:0*/ sCPU__DOT__ram_r_data;
    IData/*31:0*/ sCPU__DOT__alu_input_A;
    IData/*31:0*/ sCPU__DOT__alu_input_B;
    IData/*31:0*/ __Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__2__Vfuncout;
    IData/*31:0*/ __Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__3__Vfuncout;
    IData/*31:0*/ __Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__4__Vfuncout;
    IData/*31:0*/ __Vdly__sCPU__DOT__pc;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VL_OUT(gpr_files[32],31,0);
    VlUnpacked<IData/*31:0*/, 32> sCPU__DOT____Vcellout__GPR_CPU__gpr_files;
    VlUnpacked<IData/*31:0*/, 32> sCPU__DOT__GPR_CPU__DOT__GPR;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpc_m__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpc_m___024root(Vpc_m__Syms* symsp, const char* v__name);
    ~Vpc_m___024root();
    VL_UNCOPYABLE(Vpc_m___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
