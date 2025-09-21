// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_MYDESIGN__SYMS_H_
#define VERILATED_MYDESIGN__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "MyDesign.h"

// INCLUDE MODULE CLASSES
#include "MyDesign___024root.h"

// SYMS CLASS (contains all model state)
class MyDesign__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    MyDesign* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    MyDesign___024root             TOP;

    // CONSTRUCTORS
    MyDesign__Syms(VerilatedContext* contextp, const char* namep, MyDesign* modelp);
    ~MyDesign__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
