// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpriority_encoder_83.h for the primary calling header

#include "Vpriority_encoder_83__pch.h"
#include "Vpriority_encoder_83___024root.h"

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_static(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_static\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_initial__TOP(Vpriority_encoder_83___024root* vlSelf);

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_initial(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_initial\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpriority_encoder_83___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_initial__TOP(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_initial__TOP\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.priority_encoder_83__DOT__seg_table[0U] = 0x3fU;
    vlSelfRef.priority_encoder_83__DOT__seg_table[1U] = 6U;
    vlSelfRef.priority_encoder_83__DOT__seg_table[2U] = 0x5bU;
    vlSelfRef.priority_encoder_83__DOT__seg_table[3U] = 0x4fU;
    vlSelfRef.priority_encoder_83__DOT__seg_table[4U] = 0x66U;
    vlSelfRef.priority_encoder_83__DOT__seg_table[5U] = 0x6dU;
    vlSelfRef.priority_encoder_83__DOT__seg_table[6U] = 0x7dU;
    vlSelfRef.priority_encoder_83__DOT__seg_table[7U] = 7U;
}

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_final(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_final\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__stl(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpriority_encoder_83___024root___eval_phase__stl(Vpriority_encoder_83___024root* vlSelf);

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_settle(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_settle\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vpriority_encoder_83___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("priority_encoder_83.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vpriority_encoder_83___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__stl(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___dump_triggers__stl\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vpriority_encoder_83___024root___ico_sequent__TOP__0(Vpriority_encoder_83___024root* vlSelf);

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_stl(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_stl\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vpriority_encoder_83___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vpriority_encoder_83___024root___eval_triggers__stl(Vpriority_encoder_83___024root* vlSelf);

VL_ATTR_COLD bool Vpriority_encoder_83___024root___eval_phase__stl(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_phase__stl\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vpriority_encoder_83___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vpriority_encoder_83___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__ico(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___dump_triggers__ico\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__act(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___dump_triggers__act\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__nba(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___dump_triggers__nba\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpriority_encoder_83___024root___ctor_var_reset(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___ctor_var_reset\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->SW = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12049966652336546605ull);
    vlSelf->LED = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5726660071522653945ull);
    vlSelf->HEX0 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 17204923707227110124ull);
    vlSelf->priority_encoder_83__DOT__code = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15423872995187358476ull);
    vlSelf->priority_encoder_83__DOT__valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15010571030758928064ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->priority_encoder_83__DOT__seg_table[__Vi0] = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2697994007528250505ull);
    }
}
