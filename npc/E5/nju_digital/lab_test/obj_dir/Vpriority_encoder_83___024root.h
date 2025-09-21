// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpriority_encoder_83.h for the primary calling header

#ifndef VERILATED_VPRIORITY_ENCODER_83___024ROOT_H_
#define VERILATED_VPRIORITY_ENCODER_83___024ROOT_H_  // guard

#include "verilated.h"


class Vpriority_encoder_83__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpriority_encoder_83___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(LED,4,0);
    VL_OUT8(HEX0,6,0);
    CData/*2:0*/ priority_encoder_83__DOT__code;
    CData/*0:0*/ priority_encoder_83__DOT__valid;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN16(SW,8,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*6:0*/, 8> priority_encoder_83__DOT__seg_table;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpriority_encoder_83__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpriority_encoder_83___024root(Vpriority_encoder_83__Syms* symsp, const char* v__name);
    ~Vpriority_encoder_83___024root();
    VL_UNCOPYABLE(Vpriority_encoder_83___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
