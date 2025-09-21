// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_m.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpc_m__Syms.h"
#include "Vpc_m___024root.h"

void Vpc_m___024root___ctor_var_reset(Vpc_m___024root* vlSelf);

Vpc_m___024root::Vpc_m___024root(Vpc_m__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpc_m___024root___ctor_var_reset(this);
}

void Vpc_m___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpc_m___024root::~Vpc_m___024root() {
}
