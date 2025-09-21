// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode8x3.h for the primary calling header

#include "Vencode8x3__pch.h"
#include "Vencode8x3___024root.h"

void Vencode8x3___024root___ico_sequent__TOP__0(Vencode8x3___024root* vlSelf);

void Vencode8x3___024root___eval_ico(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_ico\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vencode8x3___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 512> Vencode8x3__ConstPool__TABLE_h823e9f08_0;

VL_INLINE_OPT void Vencode8x3___024root___ico_sequent__TOP__0(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___ico_sequent__TOP__0\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.is_zero = (0U == (IData)(vlSelfRef.data_in));
    __Vtableidx1 = (((IData)(vlSelfRef.data_in) << 1U) 
                    | (IData)(vlSelfRef.en));
    vlSelfRef.data_out = Vencode8x3__ConstPool__TABLE_h823e9f08_0
        [__Vtableidx1];
}

void Vencode8x3___024root___eval_triggers__ico(Vencode8x3___024root* vlSelf);

bool Vencode8x3___024root___eval_phase__ico(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_phase__ico\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vencode8x3___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vencode8x3___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vencode8x3___024root___eval_act(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_act\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vencode8x3___024root___eval_nba(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_nba\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vencode8x3___024root___eval_triggers__act(Vencode8x3___024root* vlSelf);

bool Vencode8x3___024root___eval_phase__act(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_phase__act\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vencode8x3___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vencode8x3___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vencode8x3___024root___eval_phase__nba(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_phase__nba\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vencode8x3___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode8x3___024root___dump_triggers__ico(Vencode8x3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode8x3___024root___dump_triggers__nba(Vencode8x3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode8x3___024root___dump_triggers__act(Vencode8x3___024root* vlSelf);
#endif  // VL_DEBUG

void Vencode8x3___024root___eval(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vencode8x3___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("encode8x3.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vencode8x3___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vencode8x3___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("encode8x3.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vencode8x3___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("encode8x3.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vencode8x3___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vencode8x3___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vencode8x3___024root___eval_debug_assertions(Vencode8x3___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode8x3___024root___eval_debug_assertions\n"); );
    Vencode8x3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.en & 0xfeU)))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
