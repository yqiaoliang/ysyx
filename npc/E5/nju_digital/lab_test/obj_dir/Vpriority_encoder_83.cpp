// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpriority_encoder_83__pch.h"

//============================================================
// Constructors

Vpriority_encoder_83::Vpriority_encoder_83(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpriority_encoder_83__Syms(contextp(), _vcname__, this)}
    , LED{vlSymsp->TOP.LED}
    , HEX0{vlSymsp->TOP.HEX0}
    , SW{vlSymsp->TOP.SW}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpriority_encoder_83::Vpriority_encoder_83(const char* _vcname__)
    : Vpriority_encoder_83(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpriority_encoder_83::~Vpriority_encoder_83() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpriority_encoder_83___024root___eval_debug_assertions(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG
void Vpriority_encoder_83___024root___eval_static(Vpriority_encoder_83___024root* vlSelf);
void Vpriority_encoder_83___024root___eval_initial(Vpriority_encoder_83___024root* vlSelf);
void Vpriority_encoder_83___024root___eval_settle(Vpriority_encoder_83___024root* vlSelf);
void Vpriority_encoder_83___024root___eval(Vpriority_encoder_83___024root* vlSelf);

void Vpriority_encoder_83::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpriority_encoder_83::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpriority_encoder_83___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpriority_encoder_83___024root___eval_static(&(vlSymsp->TOP));
        Vpriority_encoder_83___024root___eval_initial(&(vlSymsp->TOP));
        Vpriority_encoder_83___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpriority_encoder_83___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpriority_encoder_83::eventsPending() { return false; }

uint64_t Vpriority_encoder_83::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpriority_encoder_83::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpriority_encoder_83___024root___eval_final(Vpriority_encoder_83___024root* vlSelf);

VL_ATTR_COLD void Vpriority_encoder_83::final() {
    Vpriority_encoder_83___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpriority_encoder_83::hierName() const { return vlSymsp->name(); }
const char* Vpriority_encoder_83::modelName() const { return "Vpriority_encoder_83"; }
unsigned Vpriority_encoder_83::threads() const { return 1; }
void Vpriority_encoder_83::prepareClone() const { contextp()->prepareClone(); }
void Vpriority_encoder_83::atClone() const {
    contextp()->threadPoolpOnClone();
}
