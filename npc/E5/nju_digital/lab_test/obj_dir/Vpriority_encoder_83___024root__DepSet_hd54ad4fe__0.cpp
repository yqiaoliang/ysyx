// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpriority_encoder_83.h for the primary calling header

#include "Vpriority_encoder_83__pch.h"
#include "Vpriority_encoder_83__Syms.h"
#include "Vpriority_encoder_83___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__ico(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG

void Vpriority_encoder_83___024root___eval_triggers__ico(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_triggers__ico\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpriority_encoder_83___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__act(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG

void Vpriority_encoder_83___024root___eval_triggers__act(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_triggers__act\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpriority_encoder_83___024root___dump_triggers__act(vlSelf);
    }
#endif
}
