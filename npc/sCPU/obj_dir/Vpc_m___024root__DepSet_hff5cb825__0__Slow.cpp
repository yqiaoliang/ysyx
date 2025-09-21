// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_m.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpc_m___024root.h"

VL_ATTR_COLD void Vpc_m___024root___eval_static(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vpc_m___024root___eval_initial(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vpc_m___024root___eval_final(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vpc_m___024root___eval_triggers__stl(Vpc_m___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__stl(Vpc_m___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___eval_stl(Vpc_m___024root* vlSelf);

VL_ATTR_COLD void Vpc_m___024root___eval_settle(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vpc_m___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vpc_m___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/npc/sCPU/sCPU.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vpc_m___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__stl(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(IData/*31:0*/ raddr, CData/*7:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vpc_m___024root___stl_sequent__TOP__0(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->pc_o = vlSelf->sCPU__DOT__pc;
    Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(vlSelf->sCPU__DOT__pc, 4U, vlSelf->__Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout);
    vlSelf->sCPU__DOT__inst_sCPU = vlSelf->__Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout;
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1fU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1fU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1eU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1eU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1dU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1dU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1cU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1cU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1bU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1bU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x1aU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1aU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x19U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x19U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x18U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x18U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x17U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x17U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x16U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x16U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x15U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x15U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x14U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x14U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x13U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x13U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x12U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x12U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x11U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x11U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0x10U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x10U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xfU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xfU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xeU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xeU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xdU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xdU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xcU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xcU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xbU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xbU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0xaU] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xaU];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[9U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[9U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[8U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[8U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[7U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[7U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[6U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[6U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[5U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[5U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[4U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[4U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[3U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[3U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[2U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[2U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[1U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[1U];
    vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[0U] 
        = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0U];
    vlSelf->out_inst = vlSelf->sCPU__DOT__inst_sCPU;
    vlSelf->sCPU__DOT__gpr_w_en = (1U & ((~ (IData)(vlSelf->rst)) 
                                         & ((0x40U 
                                             & vlSelf->sCPU__DOT__inst_sCPU)
                                             ? (IData)(
                                                       (0x27U 
                                                        == 
                                                        (0x703fU 
                                                         & vlSelf->sCPU__DOT__inst_sCPU)))
                                             : ((0x20U 
                                                 & vlSelf->sCPU__DOT__inst_sCPU)
                                                 ? (IData)(
                                                           ((0x10U 
                                                             == 
                                                             (0x18U 
                                                              & vlSelf->sCPU__DOT__inst_sCPU)) 
                                                            & ((4U 
                                                                & vlSelf->sCPU__DOT__inst_sCPU)
                                                                ? 
                                                               ((vlSelf->sCPU__DOT__inst_sCPU 
                                                                 >> 1U) 
                                                                & vlSelf->sCPU__DOT__inst_sCPU)
                                                                : (IData)(
                                                                          (3U 
                                                                           == 
                                                                           (0xfe007003U 
                                                                            & vlSelf->sCPU__DOT__inst_sCPU))))))
                                                 : 
                                                ((0x10U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? (IData)(
                                                            (3U 
                                                             == 
                                                             (0x700fU 
                                                              & vlSelf->sCPU__DOT__inst_sCPU)))
                                                  : (IData)(
                                                            ((3U 
                                                              == 
                                                              (0xfU 
                                                               & vlSelf->sCPU__DOT__inst_sCPU)) 
                                                             & ((2U 
                                                                 == 
                                                                 (7U 
                                                                  & (vlSelf->sCPU__DOT__inst_sCPU 
                                                                     >> 0xcU))) 
                                                                | (4U 
                                                                   == 
                                                                   (7U 
                                                                    & (vlSelf->sCPU__DOT__inst_sCPU 
                                                                       >> 0xcU)))))))))));
    vlSelf->sCPU__DOT__rs1_data = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR
        [(0x1fU & (vlSelf->sCPU__DOT__inst_sCPU >> 0xfU))];
    vlSelf->sCPU__DOT__rs2_data = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR
        [(0x1fU & (vlSelf->sCPU__DOT__inst_sCPU >> 0x14U))];
    vlSelf->gpr_files[0x1fU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1fU];
    vlSelf->gpr_files[0x1eU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1eU];
    vlSelf->gpr_files[0x1dU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1dU];
    vlSelf->gpr_files[0x1cU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1cU];
    vlSelf->gpr_files[0x1bU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1bU];
    vlSelf->gpr_files[0x1aU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x1aU];
    vlSelf->gpr_files[0x19U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x19U];
    vlSelf->gpr_files[0x18U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x18U];
    vlSelf->gpr_files[0x17U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x17U];
    vlSelf->gpr_files[0x16U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x16U];
    vlSelf->gpr_files[0x15U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x15U];
    vlSelf->gpr_files[0x14U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x14U];
    vlSelf->gpr_files[0x13U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x13U];
    vlSelf->gpr_files[0x12U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x12U];
    vlSelf->gpr_files[0x11U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x11U];
    vlSelf->gpr_files[0x10U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0x10U];
    vlSelf->gpr_files[0xfU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xfU];
    vlSelf->gpr_files[0xeU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xeU];
    vlSelf->gpr_files[0xdU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xdU];
    vlSelf->gpr_files[0xcU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xcU];
    vlSelf->gpr_files[0xbU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xbU];
    vlSelf->gpr_files[0xaU] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0xaU];
    vlSelf->gpr_files[9U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [9U];
    vlSelf->gpr_files[8U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [8U];
    vlSelf->gpr_files[7U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [7U];
    vlSelf->gpr_files[6U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [6U];
    vlSelf->gpr_files[5U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [5U];
    vlSelf->gpr_files[4U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [4U];
    vlSelf->gpr_files[3U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [3U];
    vlSelf->gpr_files[2U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [2U];
    vlSelf->gpr_files[1U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [1U];
    vlSelf->gpr_files[0U] = vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files
        [0U];
    if (vlSelf->rst) {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((0x40U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)
                                         ? ((0x10U 
                                             & vlSelf->sCPU__DOT__inst_sCPU)
                                             ? 0U : 
                                            ((8U & vlSelf->sCPU__DOT__inst_sCPU)
                                              ? 0U : 
                                             ((4U & vlSelf->sCPU__DOT__inst_sCPU)
                                               ? ((2U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sCPU__DOT__inst_sCPU 
                                                         >> 0xcU)))
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)
                                               : 0U)))
                                         : 0U);
    } else if ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__inst_type = ((8U & vlSelf->sCPU__DOT__inst_sCPU)
                                             ? 0U : 
                                            ((4U & vlSelf->sCPU__DOT__inst_sCPU)
                                              ? ((2U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 4U
                                                   : 0U)
                                                  : 0U)
                                              : 0U));
        } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                  >> 0xcU)))) {
                    vlSelf->sCPU__DOT__ram_rw_byte = 1U;
                    vlSelf->sCPU__DOT__inst_type = 2U;
                } else if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                         >> 0xcU)))) {
                    vlSelf->sCPU__DOT__ram_rw_byte = 4U;
                    vlSelf->sCPU__DOT__inst_type = 2U;
                } else {
                    vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                    vlSelf->sCPU__DOT__inst_type = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
    } else if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = ((8U & vlSelf->sCPU__DOT__inst_sCPU)
                                         ? 0U : ((4U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->sCPU__DOT__inst_sCPU 
                                                         >> 0xcU)))
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)
                                                   : 0U)));
    } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                              >> 0xcU)))) {
                vlSelf->sCPU__DOT__ram_rw_byte = 4U;
                vlSelf->sCPU__DOT__inst_type = 1U;
            } else if ((4U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                     >> 0xcU)))) {
                vlSelf->sCPU__DOT__ram_rw_byte = 1U;
                vlSelf->sCPU__DOT__inst_type = 1U;
            } else {
                vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
    } else {
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    }
    if ((0U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = 0U;
    } else if ((1U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = (((- (IData)(
                                                   (vlSelf->sCPU__DOT__inst_sCPU 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       (vlSelf->sCPU__DOT__inst_sCPU 
                                        >> 0x14U));
    } else if ((2U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = (((- (IData)(
                                                   (vlSelf->sCPU__DOT__inst_sCPU 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0xfe0U & (vlSelf->sCPU__DOT__inst_sCPU 
                                                   >> 0x14U)) 
                                        | (0x1fU & 
                                           (vlSelf->sCPU__DOT__inst_sCPU 
                                            >> 7U))));
    } else if ((3U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = (((- (IData)(
                                                   (vlSelf->sCPU__DOT__inst_sCPU 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0x800U & (vlSelf->sCPU__DOT__inst_sCPU 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelf->sCPU__DOT__inst_sCPU 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelf->sCPU__DOT__inst_sCPU 
                                                 >> 7U)))));
    } else if ((4U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = (0xfffff000U 
                                       & vlSelf->sCPU__DOT__inst_sCPU);
    } else if ((5U == (IData)(vlSelf->sCPU__DOT__inst_type))) {
        vlSelf->sCPU__DOT__imm_sCPU = (((- (IData)(
                                                   (vlSelf->sCPU__DOT__inst_sCPU 
                                                    >> 0x1fU))) 
                                        << 0x15U) | 
                                       ((0x100000U 
                                         & (vlSelf->sCPU__DOT__inst_sCPU 
                                            >> 0xbU)) 
                                        | ((0xff000U 
                                            & vlSelf->sCPU__DOT__inst_sCPU) 
                                           | ((0x800U 
                                               & (vlSelf->sCPU__DOT__inst_sCPU 
                                                  >> 9U)) 
                                              | (0x7feU 
                                                 & (vlSelf->sCPU__DOT__inst_sCPU 
                                                    >> 0x14U))))));
    }
    if (vlSelf->rst) {
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__alu_input_A = 0U;
    } else if ((0x40U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                        if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                          >> 0xcU)))) {
                            vlSelf->sCPU__DOT__alu_input_B 
                                = vlSelf->sCPU__DOT__rs1_data;
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_A 
                                = vlSelf->sCPU__DOT__imm_sCPU;
                        } else {
                            vlSelf->sCPU__DOT__alu_input_B = 0U;
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_A = 0U;
                        }
                    } else {
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_A = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        }
    } else if ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_A = 0U;
                    } else {
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_A = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A = 0U;
                }
            } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((0U == (0xfe007000U & vlSelf->sCPU__DOT__inst_sCPU))) {
                        vlSelf->sCPU__DOT__alu_input_B 
                            = vlSelf->sCPU__DOT__rs1_data;
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_A 
                            = vlSelf->sCPU__DOT__rs2_data;
                    } else {
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_A = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            }
        } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                  >> 0xcU)))) {
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__ram_w_data = vlSelf->sCPU__DOT__rs2_data;
                    vlSelf->sCPU__DOT__alu_input_A 
                        = vlSelf->sCPU__DOT__imm_sCPU;
                } else if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                         >> 0xcU)))) {
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__ram_w_data = vlSelf->sCPU__DOT__rs2_data;
                    vlSelf->sCPU__DOT__alu_input_A 
                        = vlSelf->sCPU__DOT__imm_sCPU;
                } else {
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        }
    } else if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                  >> 0xcU)))) {
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A 
                        = vlSelf->sCPU__DOT__imm_sCPU;
                } else {
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_A = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        }
    } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__alu_input_A = 0U;
    } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__alu_input_A = 0U;
    } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                              >> 0xcU)))) {
                vlSelf->sCPU__DOT__alu_input_B = vlSelf->sCPU__DOT__rs1_data;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = vlSelf->sCPU__DOT__imm_sCPU;
            } else if ((4U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                     >> 0xcU)))) {
                vlSelf->sCPU__DOT__alu_input_B = vlSelf->sCPU__DOT__rs1_data;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = vlSelf->sCPU__DOT__imm_sCPU;
            } else {
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_A = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_A = 0U;
        }
    } else {
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__alu_input_A = 0U;
    }
    vlSelf->sCPU__DOT__alu_data = (vlSelf->sCPU__DOT__alu_input_A 
                                   + vlSelf->sCPU__DOT__alu_input_B);
    vlSelf->sCPU__DOT__ram_addr = ((IData)(vlSelf->rst)
                                    ? 0U : ((0x40U 
                                             & vlSelf->sCPU__DOT__inst_sCPU)
                                             ? ((0x20U 
                                                 & vlSelf->sCPU__DOT__inst_sCPU)
                                                 ? 
                                                ((0x10U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sCPU__DOT__inst_sCPU 
                                                           >> 0xcU)))
                                                       ? 0U
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)))
                                                 : 0U)
                                             : ((0x20U 
                                                 & vlSelf->sCPU__DOT__inst_sCPU)
                                                 ? 
                                                ((0x10U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? 
                                                 ((8U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 0U
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((IData)(
                                                              (0U 
                                                               == 
                                                               (0xfe007000U 
                                                                & vlSelf->sCPU__DOT__inst_sCPU)))
                                                       ? 0U
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)))
                                                  : 
                                                 ((8U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sCPU__DOT__inst_sCPU 
                                                           >> 0xcU)))
                                                       ? vlSelf->sCPU__DOT__alu_data
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sCPU__DOT__inst_sCPU 
                                                            >> 0xcU)))
                                                        ? vlSelf->sCPU__DOT__alu_data
                                                        : 0U))
                                                      : 0U)
                                                     : 0U))))
                                                 : 
                                                ((0x10U 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)
                                                  ? 
                                                 ((8U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sCPU__DOT__inst_sCPU 
                                                           >> 0xcU)))
                                                       ? 0U
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)))
                                                  : 
                                                 ((8U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->sCPU__DOT__inst_sCPU 
                                                           >> 0xcU)))
                                                       ? vlSelf->sCPU__DOT__alu_data
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->sCPU__DOT__inst_sCPU 
                                                            >> 0xcU)))
                                                        ? vlSelf->sCPU__DOT__alu_data
                                                        : 0U))
                                                      : 0U)
                                                     : 0U)))))));
    if ((1U == (IData)(vlSelf->sCPU__DOT__ram_rw_byte))) {
        Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(vlSelf->sCPU__DOT__ram_addr, (IData)(vlSelf->sCPU__DOT__ram_rw_byte), vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__2__Vfuncout);
        vlSelf->sCPU__DOT__ram_r_data = vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__2__Vfuncout;
    } else if ((2U == (IData)(vlSelf->sCPU__DOT__ram_rw_byte))) {
        Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(vlSelf->sCPU__DOT__ram_addr, (IData)(vlSelf->sCPU__DOT__ram_rw_byte), vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__3__Vfuncout);
        vlSelf->sCPU__DOT__ram_r_data = vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__3__Vfuncout;
    } else if ((4U == (IData)(vlSelf->sCPU__DOT__ram_rw_byte))) {
        Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(vlSelf->sCPU__DOT__ram_addr, (IData)(vlSelf->sCPU__DOT__ram_rw_byte), vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__4__Vfuncout);
        vlSelf->sCPU__DOT__ram_r_data = vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__4__Vfuncout;
    } else {
        vlSelf->sCPU__DOT__ram_r_data = 0U;
    }
    vlSelf->sCPU__DOT__gpr_w_data = ((IData)(vlSelf->rst)
                                      ? 0U : ((0x40U 
                                               & vlSelf->sCPU__DOT__inst_sCPU)
                                               ? ((0x20U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 
                                                  ((0x10U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sCPU__DOT__inst_sCPU 
                                                             >> 0xcU)))
                                                         ? 
                                                        ((IData)(4U) 
                                                         + vlSelf->sCPU__DOT__pc)
                                                         : 0U)
                                                        : 0U)
                                                       : 0U)
                                                      : 0U)))
                                                   : 0U)
                                               : ((0x20U 
                                                   & vlSelf->sCPU__DOT__inst_sCPU)
                                                   ? 
                                                  ((0x10U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((8U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? vlSelf->sCPU__DOT__imm_sCPU
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? 
                                                       ((IData)(
                                                                (0U 
                                                                 == 
                                                                 (0xfe007000U 
                                                                  & vlSelf->sCPU__DOT__inst_sCPU)))
                                                         ? vlSelf->sCPU__DOT__alu_data
                                                         : 0U)
                                                        : 0U)
                                                       : 0U)))
                                                    : 
                                                   ((8U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sCPU__DOT__inst_sCPU 
                                                             >> 0xcU)))
                                                         ? 0U
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->sCPU__DOT__inst_sCPU 
                                                              >> 0xcU)))
                                                          ? 0U
                                                          : 0U))
                                                        : 0U)
                                                       : 0U))))
                                                   : 
                                                  ((0x10U 
                                                    & vlSelf->sCPU__DOT__inst_sCPU)
                                                    ? 
                                                   ((8U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sCPU__DOT__inst_sCPU 
                                                             >> 0xcU)))
                                                         ? vlSelf->sCPU__DOT__alu_data
                                                         : 0U)
                                                        : 0U)
                                                       : 0U)))
                                                    : 
                                                   ((8U 
                                                     & vlSelf->sCPU__DOT__inst_sCPU)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelf->sCPU__DOT__inst_sCPU)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelf->sCPU__DOT__inst_sCPU)
                                                       ? 
                                                      ((1U 
                                                        & vlSelf->sCPU__DOT__inst_sCPU)
                                                        ? 
                                                       ((2U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->sCPU__DOT__inst_sCPU 
                                                             >> 0xcU)))
                                                         ? vlSelf->sCPU__DOT__ram_r_data
                                                         : 
                                                        ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->sCPU__DOT__inst_sCPU 
                                                              >> 0xcU)))
                                                          ? vlSelf->sCPU__DOT__ram_r_data
                                                          : 0U))
                                                        : 0U)
                                                       : 0U)))))));
}

VL_ATTR_COLD void Vpc_m___024root___eval_stl(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vpc_m___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__ico(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__act(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(negedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__nba(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(negedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpc_m___024root___ctor_var_reset(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->inst_CXX = VL_RAND_RESET_I(32);
    vlSelf->pc_o = VL_RAND_RESET_I(32);
    vlSelf->out_inst = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->gpr_files[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sCPU__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__alu_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__inst_sCPU = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__inst_type = VL_RAND_RESET_I(3);
    vlSelf->sCPU__DOT__imm_sCPU = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__gpr_w_en = VL_RAND_RESET_I(1);
    vlSelf->sCPU__DOT__gpr_w_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__rs1_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__rs2_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__ram_addr = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__ram_rw_byte = VL_RAND_RESET_I(3);
    vlSelf->sCPU__DOT__ram_w_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__ram_r_data = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__alu_input_A = VL_RAND_RESET_I(32);
    vlSelf->sCPU__DOT__alu_input_B = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->sCPU__DOT____Vcellout__GPR_CPU__gpr_files[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__3__Vfuncout = 0;
    vlSelf->__Vfunc_sCPU__DOT__RAM_CPU__DOT__pmem_read__4__Vfuncout = 0;
    vlSelf->__Vdly__sCPU__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
}
