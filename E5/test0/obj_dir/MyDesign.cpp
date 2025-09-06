// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "MyDesign.h"
#include "MyDesign__Syms.h"

//============================================================
// Constructors

MyDesign::MyDesign(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new MyDesign__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

MyDesign::MyDesign(const char* _vcname__)
    : MyDesign(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

MyDesign::~MyDesign() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void MyDesign___024root___eval_debug_assertions(MyDesign___024root* vlSelf);
#endif  // VL_DEBUG
void MyDesign___024root___eval_static(MyDesign___024root* vlSelf);
void MyDesign___024root___eval_initial(MyDesign___024root* vlSelf);
void MyDesign___024root___eval_settle(MyDesign___024root* vlSelf);
void MyDesign___024root___eval(MyDesign___024root* vlSelf);

void MyDesign::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate MyDesign::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    MyDesign___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        MyDesign___024root___eval_static(&(vlSymsp->TOP));
        MyDesign___024root___eval_initial(&(vlSymsp->TOP));
        MyDesign___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    MyDesign___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool MyDesign::eventsPending() { return false; }

uint64_t MyDesign::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* MyDesign::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void MyDesign___024root___eval_final(MyDesign___024root* vlSelf);

VL_ATTR_COLD void MyDesign::final() {
    MyDesign___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* MyDesign::hierName() const { return vlSymsp->name(); }
const char* MyDesign::modelName() const { return "MyDesign"; }
unsigned MyDesign::threads() const { return 1; }
