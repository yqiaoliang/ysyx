// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode8x3.h for the primary calling header

#ifndef VERILATED_VENCODE8X3___024ROOT_H_
#define VERILATED_VENCODE8X3___024ROOT_H_  // guard

#include "verilated.h"


class Vencode8x3__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vencode8x3___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(data_in,7,0);
    VL_IN8(en,0,0);
    VL_OUT8(is_zero,0,0);
    VL_OUT8(data_out,2,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vencode8x3__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vencode8x3___024root(Vencode8x3__Syms* symsp, const char* v__name);
    ~Vencode8x3___024root();
    VL_UNCOPYABLE(Vencode8x3___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
