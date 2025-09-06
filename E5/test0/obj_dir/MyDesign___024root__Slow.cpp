// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See MyDesign.h for the primary calling header

#include "verilated.h"

#include "MyDesign__Syms.h"
#include "MyDesign___024root.h"

void MyDesign___024root___ctor_var_reset(MyDesign___024root* vlSelf);

MyDesign___024root::MyDesign___024root(MyDesign__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    MyDesign___024root___ctor_var_reset(this);
}

void MyDesign___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

MyDesign___024root::~MyDesign___024root() {
}
