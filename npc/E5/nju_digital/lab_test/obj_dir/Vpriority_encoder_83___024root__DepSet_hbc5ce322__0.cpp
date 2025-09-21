// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpriority_encoder_83.h for the primary calling header

#include "Vpriority_encoder_83__pch.h"
#include "Vpriority_encoder_83___024root.h"

void Vpriority_encoder_83___024root___ico_sequent__TOP__0(Vpriority_encoder_83___024root* vlSelf);

void Vpriority_encoder_83___024root___eval_ico(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_ico\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vpriority_encoder_83___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vpriority_encoder_83___024root___ico_sequent__TOP__0(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___ico_sequent__TOP__0\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x100U & (IData)(vlSelfRef.SW))) {
        vlSelfRef.priority_encoder_83__DOT__valid = 0U;
        vlSelfRef.priority_encoder_83__DOT__code = 0U;
        if (((((((((0x80U == (0x80U & (IData)(vlSelfRef.SW))) 
                   | (0x40U == (0xc0U & (IData)(vlSelfRef.SW)))) 
                  | (0x20U == (0xe0U & (IData)(vlSelfRef.SW)))) 
                 | (0x10U == (0xf0U & (IData)(vlSelfRef.SW)))) 
                | (8U == (0xf8U & (IData)(vlSelfRef.SW)))) 
               | (4U == (0xfcU & (IData)(vlSelfRef.SW)))) 
              | (2U == (0xfeU & (IData)(vlSelfRef.SW)))) 
             | (1U == (0xffU & (IData)(vlSelfRef.SW))))) {
            if ((0x80U == (0x80U & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 7U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((0x40U == (0xc0U & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 6U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((0x20U == (0xe0U & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 5U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((0x10U == (0xf0U & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 4U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((8U == (0xf8U & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 3U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((4U == (0xfcU & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 2U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else if ((2U == (0xfeU & (IData)(vlSelfRef.SW)))) {
                vlSelfRef.priority_encoder_83__DOT__code = 1U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            } else {
                vlSelfRef.priority_encoder_83__DOT__code = 0U;
                vlSelfRef.priority_encoder_83__DOT__valid = 1U;
            }
        } else {
            vlSelfRef.priority_encoder_83__DOT__code = 0U;
            vlSelfRef.priority_encoder_83__DOT__valid = 0U;
        }
    } else {
        vlSelfRef.priority_encoder_83__DOT__code = 0U;
        vlSelfRef.priority_encoder_83__DOT__valid = 0U;
    }
    vlSelfRef.LED = ((0x18U & (IData)(vlSelfRef.LED)) 
                     | (IData)(vlSelfRef.priority_encoder_83__DOT__code));
    vlSelfRef.LED = ((1U & (IData)(vlSelfRef.LED)) 
                     | ((IData)(vlSelfRef.priority_encoder_83__DOT__valid) 
                        << 4U));
    vlSelfRef.HEX0 = vlSelfRef.priority_encoder_83__DOT__seg_table
        [vlSelfRef.priority_encoder_83__DOT__code];
}

void Vpriority_encoder_83___024root___eval_triggers__ico(Vpriority_encoder_83___024root* vlSelf);

bool Vpriority_encoder_83___024root___eval_phase__ico(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_phase__ico\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vpriority_encoder_83___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vpriority_encoder_83___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vpriority_encoder_83___024root___eval_act(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_act\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vpriority_encoder_83___024root___eval_nba(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_nba\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vpriority_encoder_83___024root___eval_triggers__act(Vpriority_encoder_83___024root* vlSelf);

bool Vpriority_encoder_83___024root___eval_phase__act(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_phase__act\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpriority_encoder_83___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vpriority_encoder_83___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpriority_encoder_83___024root___eval_phase__nba(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_phase__nba\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpriority_encoder_83___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__ico(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__nba(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpriority_encoder_83___024root___dump_triggers__act(Vpriority_encoder_83___024root* vlSelf);
#endif  // VL_DEBUG

void Vpriority_encoder_83___024root___eval(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vpriority_encoder_83___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("priority_encoder_83.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vpriority_encoder_83___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vpriority_encoder_83___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("priority_encoder_83.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vpriority_encoder_83___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("priority_encoder_83.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vpriority_encoder_83___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vpriority_encoder_83___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpriority_encoder_83___024root___eval_debug_assertions(Vpriority_encoder_83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpriority_encoder_83___024root___eval_debug_assertions\n"); );
    Vpriority_encoder_83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.SW & 0xfe00U)))) {
        Verilated::overWidthError("SW");}
}
#endif  // VL_DEBUG
