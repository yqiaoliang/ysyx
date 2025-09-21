// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_m.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vpc_m___024root.h"

void Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(IData/*31:0*/ raddr, CData/*7:0*/ len, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vpc_m___024root___ico_sequent__TOP__0(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___ico_sequent__TOP__0\n"); );
    // Body
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
    if (vlSelf->rst) {
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((0x40U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                        if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                          >> 0xcU)))) {
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_B 
                                = vlSelf->sCPU__DOT__rs1_data;
                            vlSelf->sCPU__DOT__inst_type = 1U;
                        } else {
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_B = 0U;
                            vlSelf->sCPU__DOT__inst_type = 0U;
                        }
                    } else {
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__inst_type = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__inst_type = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
    } else if ((0x20U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__inst_type = 4U;
                    } else {
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                        vlSelf->sCPU__DOT__inst_type = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__inst_type = 0U;
                }
            } else {
                if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
                    if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                        if ((0U == (0xfe007000U & vlSelf->sCPU__DOT__inst_sCPU))) {
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_B 
                                = vlSelf->sCPU__DOT__rs1_data;
                        } else {
                            vlSelf->sCPU__DOT__ram_w_data = 0U;
                            vlSelf->sCPU__DOT__alu_input_B = 0U;
                        }
                    } else {
                        vlSelf->sCPU__DOT__ram_w_data = 0U;
                        vlSelf->sCPU__DOT__alu_input_B = 0U;
                    }
                } else {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                }
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                  >> 0xcU)))) {
                    vlSelf->sCPU__DOT__ram_w_data = vlSelf->sCPU__DOT__rs2_data;
                    vlSelf->sCPU__DOT__ram_rw_byte = 1U;
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__inst_type = 2U;
                } else if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                         >> 0xcU)))) {
                    vlSelf->sCPU__DOT__ram_w_data = vlSelf->sCPU__DOT__rs2_data;
                    vlSelf->sCPU__DOT__ram_rw_byte = 4U;
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__inst_type = 2U;
                } else {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__inst_type = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
    } else if ((0x10U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
                if ((0U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                  >> 0xcU)))) {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_B 
                        = vlSelf->sCPU__DOT__rs1_data;
                    vlSelf->sCPU__DOT__inst_type = 1U;
                } else {
                    vlSelf->sCPU__DOT__ram_w_data = 0U;
                    vlSelf->sCPU__DOT__alu_input_B = 0U;
                    vlSelf->sCPU__DOT__inst_type = 0U;
                }
            } else {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
    } else if ((8U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((4U & vlSelf->sCPU__DOT__inst_sCPU)) {
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__alu_input_B = 0U;
        vlSelf->sCPU__DOT__inst_type = 0U;
    } else if ((2U & vlSelf->sCPU__DOT__inst_sCPU)) {
        if ((1U & vlSelf->sCPU__DOT__inst_sCPU)) {
            if ((2U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                              >> 0xcU)))) {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__ram_rw_byte = 4U;
                vlSelf->sCPU__DOT__alu_input_B = vlSelf->sCPU__DOT__rs1_data;
                vlSelf->sCPU__DOT__inst_type = 1U;
            } else if ((4U == (7U & (vlSelf->sCPU__DOT__inst_sCPU 
                                     >> 0xcU)))) {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__ram_rw_byte = 1U;
                vlSelf->sCPU__DOT__alu_input_B = vlSelf->sCPU__DOT__rs1_data;
                vlSelf->sCPU__DOT__inst_type = 1U;
            } else {
                vlSelf->sCPU__DOT__ram_w_data = 0U;
                vlSelf->sCPU__DOT__ram_rw_byte = 0U;
                vlSelf->sCPU__DOT__alu_input_B = 0U;
                vlSelf->sCPU__DOT__inst_type = 0U;
            }
        } else {
            vlSelf->sCPU__DOT__ram_w_data = 0U;
            vlSelf->sCPU__DOT__ram_rw_byte = 0U;
            vlSelf->sCPU__DOT__alu_input_B = 0U;
            vlSelf->sCPU__DOT__inst_type = 0U;
        }
    } else {
        vlSelf->sCPU__DOT__ram_w_data = 0U;
        vlSelf->sCPU__DOT__ram_rw_byte = 0U;
        vlSelf->sCPU__DOT__alu_input_B = 0U;
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
    vlSelf->sCPU__DOT__alu_input_A = ((IData)(vlSelf->rst)
                                       ? 0U : ((0x40U 
                                                & vlSelf->sCPU__DOT__inst_sCPU)
                                                ? (
                                                   (0x20U 
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
                                                          ? vlSelf->sCPU__DOT__imm_sCPU
                                                          : 0U)
                                                         : 0U)
                                                        : 0U)
                                                       : 0U)))
                                                    : 0U)
                                                : (
                                                   (0x20U 
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
                                                          ? vlSelf->sCPU__DOT__rs2_data
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
                                                          ? vlSelf->sCPU__DOT__imm_sCPU
                                                          : 
                                                         ((2U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->sCPU__DOT__inst_sCPU 
                                                               >> 0xcU)))
                                                           ? vlSelf->sCPU__DOT__imm_sCPU
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
                                                          ? vlSelf->sCPU__DOT__imm_sCPU
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
                                                          ? vlSelf->sCPU__DOT__imm_sCPU
                                                          : 
                                                         ((4U 
                                                           == 
                                                           (7U 
                                                            & (vlSelf->sCPU__DOT__inst_sCPU 
                                                               >> 0xcU)))
                                                           ? vlSelf->sCPU__DOT__imm_sCPU
                                                           : 0U))
                                                         : 0U)
                                                        : 0U)))))));
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

void Vpc_m___024root___eval_ico(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vpc_m___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vpc_m___024root___eval_act(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_act\n"); );
}

void Vpc_m___024root____Vdpiimwrap_sCPU__DOT__RAM_CPU__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_INLINE_OPT void Vpc_m___024root___nba_sequent__TOP__0(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (((~ (IData)(vlSelf->rst)) & (IData)(((0x23U 
                                              == (0x7fU 
                                                  & vlSelf->sCPU__DOT__inst_sCPU)) 
                                             & ((0U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->sCPU__DOT__inst_sCPU 
                                                     >> 0xcU))) 
                                                | (2U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->sCPU__DOT__inst_sCPU 
                                                       >> 0xcU)))))))) {
        Vpc_m___024root____Vdpiimwrap_sCPU__DOT__RAM_CPU__DOT__pmem_write_TOP(vlSelf->sCPU__DOT__ram_addr, vlSelf->sCPU__DOT__ram_w_data, (IData)(vlSelf->sCPU__DOT__ram_rw_byte));
    }
}

VL_INLINE_OPT void Vpc_m___024root___nba_sequent__TOP__1(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdly__sCPU__DOT__pc = vlSelf->sCPU__DOT__pc;
    vlSelf->__Vdly__sCPU__DOT__pc = ((IData)(vlSelf->rst)
                                      ? 0xfffffffcU
                                      : vlSelf->sCPU__DOT__next_pc);
}

VL_INLINE_OPT void Vpc_m___024root___nba_sequent__TOP__2(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v0;
    __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__sCPU__DOT__GPR_CPU__DOT__GPR__v32;
    __Vdlyvdim0__sCPU__DOT__GPR_CPU__DOT__GPR__v32 = 0;
    IData/*31:0*/ __Vdlyvval__sCPU__DOT__GPR_CPU__DOT__GPR__v32;
    __Vdlyvval__sCPU__DOT__GPR_CPU__DOT__GPR__v32 = 0;
    CData/*0:0*/ __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v32;
    __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v32 = 0;
    // Body
    __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v0 = 0U;
    __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v32 = 0U;
    if (vlSelf->rst) {
        __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v0 = 1U;
        vlSelf->sCPU__DOT__next_pc = 0xfffffffcU;
    } else {
        if (((IData)(vlSelf->sCPU__DOT__gpr_w_en) & 
             (0U != (0x1fU & (vlSelf->sCPU__DOT__inst_sCPU 
                              >> 7U))))) {
            __Vdlyvval__sCPU__DOT__GPR_CPU__DOT__GPR__v32 
                = vlSelf->sCPU__DOT__gpr_w_data;
            __Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v32 = 1U;
            __Vdlyvdim0__sCPU__DOT__GPR_CPU__DOT__GPR__v32 
                = (0x1fU & (vlSelf->sCPU__DOT__inst_sCPU 
                            >> 7U));
        }
        vlSelf->sCPU__DOT__next_pc = (((~ (IData)(vlSelf->rst)) 
                                       & (IData)((0x67U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->sCPU__DOT__inst_sCPU))))
                                       ? vlSelf->sCPU__DOT__alu_data
                                       : ((IData)(4U) 
                                          + vlSelf->sCPU__DOT__pc));
    }
    if (__Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v0) {
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[1U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[2U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[3U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[4U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[5U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[6U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[7U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[8U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[9U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xaU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xbU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xcU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xdU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xeU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0xfU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x10U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x11U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x12U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x13U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x14U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x15U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x16U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x17U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x18U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x19U] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1aU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1bU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1cU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1dU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1eU] = 0U;
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[0x1fU] = 0U;
    }
    if (__Vdlyvset__sCPU__DOT__GPR_CPU__DOT__GPR__v32) {
        vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR[__Vdlyvdim0__sCPU__DOT__GPR_CPU__DOT__GPR__v32] 
            = __Vdlyvval__sCPU__DOT__GPR_CPU__DOT__GPR__v32;
    }
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
}

VL_INLINE_OPT void Vpc_m___024root___nba_sequent__TOP__3(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->sCPU__DOT__pc = vlSelf->__Vdly__sCPU__DOT__pc;
    vlSelf->pc_o = vlSelf->sCPU__DOT__pc;
    Vpc_m___024root____Vdpiimwrap_sCPU__DOT__ROM_CPU__DOT__pmem_read_TOP(vlSelf->sCPU__DOT__pc, 4U, vlSelf->__Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout);
    vlSelf->sCPU__DOT__inst_sCPU = vlSelf->__Vfunc_sCPU__DOT__ROM_CPU__DOT__pmem_read__0__Vfuncout;
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
}

VL_INLINE_OPT void Vpc_m___024root___nba_comb__TOP__0(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->sCPU__DOT__rs1_data = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR
        [(0x1fU & (vlSelf->sCPU__DOT__inst_sCPU >> 0xfU))];
    vlSelf->sCPU__DOT__rs2_data = vlSelf->sCPU__DOT__GPR_CPU__DOT__GPR
        [(0x1fU & (vlSelf->sCPU__DOT__inst_sCPU >> 0x14U))];
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

void Vpc_m___024root___eval_nba(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vpc_m___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vpc_m___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vpc_m___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vpc_m___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vpc_m___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vpc_m___024root___eval_triggers__ico(Vpc_m___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__ico(Vpc_m___024root* vlSelf);
#endif  // VL_DEBUG
void Vpc_m___024root___eval_triggers__act(Vpc_m___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__act(Vpc_m___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpc_m___024root___dump_triggers__nba(Vpc_m___024root* vlSelf);
#endif  // VL_DEBUG

void Vpc_m___024root___eval(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<3> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vpc_m___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vpc_m___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/npc/sCPU/sCPU.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vpc_m___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vpc_m___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vpc_m___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/npc/sCPU/sCPU.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vpc_m___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vpc_m___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yqiaoliang/Desktop/digital/ysyx/ysyx-workbench/npc/sCPU/sCPU.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vpc_m___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vpc_m___024root___eval_debug_assertions(Vpc_m___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_m__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_m___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
