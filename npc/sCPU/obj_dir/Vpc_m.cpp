// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpc_m.h"
#include "Vpc_m__Syms.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

Vpc_m::Vpc_m(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpc_m__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , inst_CXX{vlSymsp->TOP.inst_CXX}
    , pc_o{vlSymsp->TOP.pc_o}
    , out_inst{vlSymsp->TOP.out_inst}
    , gpr_files{vlSymsp->TOP.gpr_files}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpc_m::Vpc_m(const char* _vcname__)
    : Vpc_m(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpc_m::~Vpc_m() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpc_m___024root___eval_debug_assertions(Vpc_m___024root* vlSelf);
#endif  // VL_DEBUG
void Vpc_m___024root___eval_static(Vpc_m___024root* vlSelf);
void Vpc_m___024root___eval_initial(Vpc_m___024root* vlSelf);
void Vpc_m___024root___eval_settle(Vpc_m___024root* vlSelf);
void Vpc_m___024root___eval(Vpc_m___024root* vlSelf);

void Vpc_m::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpc_m::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpc_m___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpc_m___024root___eval_static(&(vlSymsp->TOP));
        Vpc_m___024root___eval_initial(&(vlSymsp->TOP));
        Vpc_m___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpc_m___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpc_m::eventsPending() { return false; }

uint64_t Vpc_m::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpc_m::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpc_m___024root___eval_final(Vpc_m___024root* vlSelf);

VL_ATTR_COLD void Vpc_m::final() {
    Vpc_m___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpc_m::hierName() const { return vlSymsp->name(); }
const char* Vpc_m::modelName() const { return "Vpc_m"; }
unsigned Vpc_m::threads() const { return 1; }
