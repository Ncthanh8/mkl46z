#ifndef _UART_H_
#define _UART_H_

#include "gpio.h"
#include <stdint.h>

typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
  __IO uint8_t C4;                                 /**< UART Control Register 4, offset: 0x8 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*******************************************************************************
 *                     UART_Register_Masks UART Register Masks                 *
 *******************************************************************************/

/* BDH - UART Baud Rate Register: High */
#define UART_BDH_SBR_MASK                        (0x1FU)
#define UART_BDH_SBR_SHIFT                       (0U)
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBR_SHIFT)) & UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK                       (0x20U)
#define UART_BDH_SBNS_SHIFT                      (5U)
#define UART_BDH_SBNS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBNS_SHIFT)) & UART_BDH_SBNS_MASK)
#define UART_BDH_RXEDGIE_MASK                    (0x40U)
#define UART_BDH_RXEDGIE_SHIFT                   (6U)
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_BDH_RXEDGIE_SHIFT)) & UART_BDH_RXEDGIE_MASK)
#define UART_BDH_LBKDIE_MASK                     (0x80U)
#define UART_BDH_LBKDIE_SHIFT                    (7U)
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_BDH_LBKDIE_SHIFT)) & UART_BDH_LBKDIE_MASK)

/* BDL - UART Baud Rate Register: Low */
#define UART_BDL_SBR_MASK                        (0xFFU)
#define UART_BDL_SBR_SHIFT                       (0U)
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDL_SBR_SHIFT)) & UART_BDL_SBR_MASK)

/* C1 UART Control Register 1 */
#define UART_C1_PT_MASK                          (0x1U)
#define UART_C1_PT_SHIFT                         (0U)
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PT_SHIFT)) & UART_C1_PT_MASK)
#define UART_C1_PE_MASK                          (0x2U)
#define UART_C1_PE_SHIFT                         (1U)
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PE_SHIFT)) & UART_C1_PE_MASK)
#define UART_C1_ILT_MASK                         (0x4U)
#define UART_C1_ILT_SHIFT                        (2U)
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C1_ILT_SHIFT)) & UART_C1_ILT_MASK)
#define UART_C1_WAKE_MASK                        (0x8U)
#define UART_C1_WAKE_SHIFT                       (3U)
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_WAKE_SHIFT)) & UART_C1_WAKE_MASK)
#define UART_C1_M_MASK                           (0x10U)
#define UART_C1_M_SHIFT                          (4U)
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x)) << UART_C1_M_SHIFT)) & UART_C1_M_MASK)
#define UART_C1_RSRC_MASK                        (0x20U)
#define UART_C1_RSRC_SHIFT                       (5U)
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_RSRC_SHIFT)) & UART_C1_RSRC_MASK)
#define UART_C1_UARTSWAI_MASK                    (0x40U)
#define UART_C1_UARTSWAI_SHIFT                   (6U)
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C1_UARTSWAI_SHIFT)) & UART_C1_UARTSWAI_MASK)
#define UART_C1_LOOPS_MASK                       (0x80U)
#define UART_C1_LOOPS_SHIFT                      (7U)
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C1_LOOPS_SHIFT)) & UART_C1_LOOPS_MASK)

/* C2 - UART Control Register 2 */
#define UART_C2_SBK_MASK                         (0x1U)
#define UART_C2_SBK_SHIFT                        (0U)
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_SBK_SHIFT)) & UART_C2_SBK_MASK)
#define UART_C2_RWU_MASK                         (0x2U)
#define UART_C2_RWU_SHIFT                        (1U)
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RWU_SHIFT)) & UART_C2_RWU_MASK)
#define UART_C2_RE_MASK                          (0x4U)
#define UART_C2_RE_SHIFT                         (2U)
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_RE_SHIFT)) & UART_C2_RE_MASK)
#define UART_C2_TE_MASK                          (0x8U)
#define UART_C2_TE_SHIFT                         (3U)
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_TE_SHIFT)) & UART_C2_TE_MASK)
#define UART_C2_ILIE_MASK                        (0x10U)
#define UART_C2_ILIE_SHIFT                       (4U)
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_ILIE_SHIFT)) & UART_C2_ILIE_MASK)
#define UART_C2_RIE_MASK                         (0x20U)
#define UART_C2_RIE_SHIFT                        (5U)
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RIE_SHIFT)) & UART_C2_RIE_MASK)
#define UART_C2_TCIE_MASK                        (0x40U)
#define UART_C2_TCIE_SHIFT                       (6U)
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_TCIE_SHIFT)) & UART_C2_TCIE_MASK)
#define UART_C2_TIE_MASK                         (0x80U)
#define UART_C2_TIE_SHIFT                        (7U)
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_TIE_SHIFT)) & UART_C2_TIE_MASK)

/* S1 - UART Status Register 1 */
#define UART_S1_PF_MASK                          (0x1U)
#define UART_S1_PF_SHIFT                         (0U)
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_PF_SHIFT)) & UART_S1_PF_MASK)
#define UART_S1_FE_MASK                          (0x2U)
#define UART_S1_FE_SHIFT                         (1U)
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_FE_SHIFT)) & UART_S1_FE_MASK)
#define UART_S1_NF_MASK                          (0x4U)
#define UART_S1_NF_SHIFT                         (2U)
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_NF_SHIFT)) & UART_S1_NF_MASK)
#define UART_S1_OR_MASK                          (0x8U)
#define UART_S1_OR_SHIFT                         (3U)
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_OR_SHIFT)) & UART_S1_OR_MASK)
#define UART_S1_IDLE_MASK                        (0x10U)
#define UART_S1_IDLE_SHIFT                       (4U)
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_IDLE_SHIFT)) & UART_S1_IDLE_MASK)
#define UART_S1_RDRF_MASK                        (0x20U)
#define UART_S1_RDRF_SHIFT                       (5U)
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_RDRF_SHIFT)) & UART_S1_RDRF_MASK)
#define UART_S1_TC_MASK                          (0x40U)
#define UART_S1_TC_SHIFT                         (6U)
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_TC_SHIFT)) & UART_S1_TC_MASK)
#define UART_S1_TDRE_MASK                        (0x80U)
#define UART_S1_TDRE_SHIFT                       (7U)
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_TDRE_SHIFT)) & UART_S1_TDRE_MASK)

/* S2 - UART Status Register 2 */
#define UART_S2_RAF_MASK                         (0x1U)
#define UART_S2_RAF_SHIFT                        (0U)
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x)) << UART_S2_RAF_SHIFT)) & UART_S2_RAF_MASK)
#define UART_S2_LBKDE_MASK                       (0x2U)
#define UART_S2_LBKDE_SHIFT                      (1U)
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDE_SHIFT)) & UART_S2_LBKDE_MASK)
#define UART_S2_BRK13_MASK                       (0x4U)
#define UART_S2_BRK13_SHIFT                      (2U)
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_BRK13_SHIFT)) & UART_S2_BRK13_MASK)
#define UART_S2_RWUID_MASK                       (0x8U)
#define UART_S2_RWUID_SHIFT                      (3U)
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RWUID_SHIFT)) & UART_S2_RWUID_MASK)
#define UART_S2_RXINV_MASK                       (0x10U)
#define UART_S2_RXINV_SHIFT                      (4U)
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RXINV_SHIFT)) & UART_S2_RXINV_MASK)
#define UART_S2_RXEDGIF_MASK                     (0x40U)
#define UART_S2_RXEDGIF_SHIFT                    (6U)
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_S2_RXEDGIF_SHIFT)) & UART_S2_RXEDGIF_MASK)
#define UART_S2_LBKDIF_MASK                      (0x80U)
#define UART_S2_LBKDIF_SHIFT                     (7U)
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDIF_SHIFT)) & UART_S2_LBKDIF_MASK)

/* C3 - UART Control Register 3 */
#define UART_C3_PEIE_MASK                        (0x1U)
#define UART_C3_PEIE_SHIFT                       (0U)
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_PEIE_SHIFT)) & UART_C3_PEIE_MASK)
#define UART_C3_FEIE_MASK                        (0x2U)
#define UART_C3_FEIE_SHIFT                       (1U)
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_FEIE_SHIFT)) & UART_C3_FEIE_MASK)
#define UART_C3_NEIE_MASK                        (0x4U)
#define UART_C3_NEIE_SHIFT                       (2U)
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_NEIE_SHIFT)) & UART_C3_NEIE_MASK)
#define UART_C3_ORIE_MASK                        (0x8U)
#define UART_C3_ORIE_SHIFT                       (3U)
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_ORIE_SHIFT)) & UART_C3_ORIE_MASK)
#define UART_C3_TXINV_MASK                       (0x10U)
#define UART_C3_TXINV_SHIFT                      (4U)
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXINV_SHIFT)) & UART_C3_TXINV_MASK)
#define UART_C3_TXDIR_MASK                       (0x20U)
#define UART_C3_TXDIR_SHIFT                      (5U)
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXDIR_SHIFT)) & UART_C3_TXDIR_MASK)
#define UART_C3_T8_MASK                          (0x40U)
#define UART_C3_T8_SHIFT                         (6U)
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_T8_SHIFT)) & UART_C3_T8_MASK)
#define UART_C3_R8_MASK                          (0x80U)
#define UART_C3_R8_SHIFT                         (7U)
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_R8_SHIFT)) & UART_C3_R8_MASK)

/* D - UART Data Register */
#define UART_D_R0T0_MASK                         (0x1U)
#define UART_D_R0T0_SHIFT                        (0U)
#define UART_D_R0T0(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R0T0_SHIFT)) & UART_D_R0T0_MASK)
#define UART_D_R1T1_MASK                         (0x2U)
#define UART_D_R1T1_SHIFT                        (1U)
#define UART_D_R1T1(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R1T1_SHIFT)) & UART_D_R1T1_MASK)
#define UART_D_R2T2_MASK                         (0x4U)
#define UART_D_R2T2_SHIFT                        (2U)
#define UART_D_R2T2(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R2T2_SHIFT)) & UART_D_R2T2_MASK)
#define UART_D_R3T3_MASK                         (0x8U)
#define UART_D_R3T3_SHIFT                        (3U)
#define UART_D_R3T3(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R3T3_SHIFT)) & UART_D_R3T3_MASK)
#define UART_D_R4T4_MASK                         (0x10U)
#define UART_D_R4T4_SHIFT                        (4U)
#define UART_D_R4T4(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R4T4_SHIFT)) & UART_D_R4T4_MASK)
#define UART_D_R5T5_MASK                         (0x20U)
#define UART_D_R5T5_SHIFT                        (5U)
#define UART_D_R5T5(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R5T5_SHIFT)) & UART_D_R5T5_MASK)
#define UART_D_R6T6_MASK                         (0x40U)
#define UART_D_R6T6_SHIFT                        (6U)
#define UART_D_R6T6(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R6T6_SHIFT)) & UART_D_R6T6_MASK)
#define UART_D_R7T7_MASK                         (0x80U)
#define UART_D_R7T7_SHIFT                        (7U)
#define UART_D_R7T7(x)                           (((uint8_t)(((uint8_t)(x)) << UART_D_R7T7_SHIFT)) & UART_D_R7T7_MASK)

/* C4 - UART Control Register 4 */
#define UART_C4_RDMAS_MASK                       (0x20U)
#define UART_C4_RDMAS_SHIFT                      (5U)
#define UART_C4_RDMAS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C4_RDMAS_SHIFT)) & UART_C4_RDMAS_MASK)
#define UART_C4_TDMAS_MASK                       (0x80U)
#define UART_C4_TDMAS_SHIFT                      (7U)
#define UART_C4_TDMAS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C4_TDMAS_SHIFT)) & UART_C4_TDMAS_MASK)


 /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { 0u, UART1_BASE, UART2_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { (UART_Type *)0u, UART1, UART2 }
/** Interrupt vectors for the UART peripheral type */
#define UART_RX_TX_IRQS                          { NotAvail_IRQn, UART1_IRQn, UART2_IRQn }
#define UART_ERR_IRQS                            { NotAvail_IRQn, UART1_IRQn, UART2_IRQn }

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART0_Peripheral_Access_Layer UART0 Peripheral Access Layer
 * @{
 */

/** UART0 - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __IO uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
  __IO uint8_t MA1;                                /**< UART Match Address Registers 1, offset: 0x8 */
  __IO uint8_t MA2;                                /**< UART Match Address Registers 2, offset: 0x9 */
  __IO uint8_t C4;                                 /**< UART Control Register 4, offset: 0xA */
  __IO uint8_t C5;                                 /**< UART Control Register 5, offset: 0xB */
} UART0_Type;

/* ----------------------------------------------------------------------------
   -- UART0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART0_Register_Masks UART0 Register Masks
 * @{
 */

/*! @name BDH - UART Baud Rate Register High */
#define UART0_BDH_SBR_MASK                       (0x1FU)
#define UART0_BDH_SBR_SHIFT                      (0U)
#define UART0_BDH_SBR(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_BDH_SBR_SHIFT)) & UART0_BDH_SBR_MASK)
#define UART0_BDH_SBNS_MASK                      (0x20U)
#define UART0_BDH_SBNS_SHIFT                     (5U)
#define UART0_BDH_SBNS(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_BDH_SBNS_SHIFT)) & UART0_BDH_SBNS_MASK)
#define UART0_BDH_RXEDGIE_MASK                   (0x40U)
#define UART0_BDH_RXEDGIE_SHIFT                  (6U)
#define UART0_BDH_RXEDGIE(x)                     (((uint8_t)(((uint8_t)(x)) << UART0_BDH_RXEDGIE_SHIFT)) & UART0_BDH_RXEDGIE_MASK)
#define UART0_BDH_LBKDIE_MASK                    (0x80U)
#define UART0_BDH_LBKDIE_SHIFT                   (7U)
#define UART0_BDH_LBKDIE(x)                      (((uint8_t)(((uint8_t)(x)) << UART0_BDH_LBKDIE_SHIFT)) & UART0_BDH_LBKDIE_MASK)

/*! @name BDL - UART Baud Rate Register Low */
#define UART0_BDL_SBR_MASK                       (0xFFU)
#define UART0_BDL_SBR_SHIFT                      (0U)
#define UART0_BDL_SBR(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_BDL_SBR_SHIFT)) & UART0_BDL_SBR_MASK)

/*! @name C1 - UART Control Register 1 */
#define UART0_C1_PT_MASK                         (0x1U)
#define UART0_C1_PT_SHIFT                        (0U)
#define UART0_C1_PT(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C1_PT_SHIFT)) & UART0_C1_PT_MASK)
#define UART0_C1_PE_MASK                         (0x2U)
#define UART0_C1_PE_SHIFT                        (1U)
#define UART0_C1_PE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C1_PE_SHIFT)) & UART0_C1_PE_MASK)
#define UART0_C1_ILT_MASK                        (0x4U)
#define UART0_C1_ILT_SHIFT                       (2U)
#define UART0_C1_ILT(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C1_ILT_SHIFT)) & UART0_C1_ILT_MASK)
#define UART0_C1_WAKE_MASK                       (0x8U)
#define UART0_C1_WAKE_SHIFT                      (3U)
#define UART0_C1_WAKE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C1_WAKE_SHIFT)) & UART0_C1_WAKE_MASK)
#define UART0_C1_M_MASK                          (0x10U)
#define UART0_C1_M_SHIFT                         (4U)
#define UART0_C1_M(x)                            (((uint8_t)(((uint8_t)(x)) << UART0_C1_M_SHIFT)) & UART0_C1_M_MASK)
#define UART0_C1_RSRC_MASK                       (0x20U)
#define UART0_C1_RSRC_SHIFT                      (5U)
#define UART0_C1_RSRC(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C1_RSRC_SHIFT)) & UART0_C1_RSRC_MASK)
#define UART0_C1_DOZEEN_MASK                     (0x40U)
#define UART0_C1_DOZEEN_SHIFT                    (6U)
#define UART0_C1_DOZEEN(x)                       (((uint8_t)(((uint8_t)(x)) << UART0_C1_DOZEEN_SHIFT)) & UART0_C1_DOZEEN_MASK)
#define UART0_C1_LOOPS_MASK                      (0x80U)
#define UART0_C1_LOOPS_SHIFT                     (7U)
#define UART0_C1_LOOPS(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C1_LOOPS_SHIFT)) & UART0_C1_LOOPS_MASK)

/*! @name C2 - UART Control Register 2 */
#define UART0_C2_SBK_MASK                        (0x1U)
#define UART0_C2_SBK_SHIFT                       (0U)
#define UART0_C2_SBK(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C2_SBK_SHIFT)) & UART0_C2_SBK_MASK)
#define UART0_C2_RWU_MASK                        (0x2U)
#define UART0_C2_RWU_SHIFT                       (1U)
#define UART0_C2_RWU(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C2_RWU_SHIFT)) & UART0_C2_RWU_MASK)
#define UART0_C2_RE_MASK                         (0x4U)
#define UART0_C2_RE_SHIFT                        (2U)
#define UART0_C2_RE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C2_RE_SHIFT)) & UART0_C2_RE_MASK)
#define UART0_C2_TE_MASK                         (0x8U)
#define UART0_C2_TE_SHIFT                        (3U)
#define UART0_C2_TE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_C2_TE_SHIFT)) & UART0_C2_TE_MASK)
#define UART0_C2_ILIE_MASK                       (0x10U)
#define UART0_C2_ILIE_SHIFT                      (4U)
#define UART0_C2_ILIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C2_ILIE_SHIFT)) & UART0_C2_ILIE_MASK)
#define UART0_C2_RIE_MASK                        (0x20U)
#define UART0_C2_RIE_SHIFT                       (5U)
#define UART0_C2_RIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C2_RIE_SHIFT)) & UART0_C2_RIE_MASK)
#define UART0_C2_TCIE_MASK                       (0x40U)
#define UART0_C2_TCIE_SHIFT                      (6U)
#define UART0_C2_TCIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C2_TCIE_SHIFT)) & UART0_C2_TCIE_MASK)
#define UART0_C2_TIE_MASK                        (0x80U)
#define UART0_C2_TIE_SHIFT                       (7U)
#define UART0_C2_TIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C2_TIE_SHIFT)) & UART0_C2_TIE_MASK)

/* S1 - UART Status Register 1 */
#define UART0_S1_PF_MASK                         (0x1U)
#define UART0_S1_PF_SHIFT                        (0U)
#define UART0_S1_PF(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_PF_SHIFT)) & UART0_S1_PF_MASK)
#define UART0_S1_FE_MASK                         (0x2U)
#define UART0_S1_FE_SHIFT                        (1U)
#define UART0_S1_FE(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_FE_SHIFT)) & UART0_S1_FE_MASK)
#define UART0_S1_NF_MASK                         (0x4U)
#define UART0_S1_NF_SHIFT                        (2U)
#define UART0_S1_NF(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_NF_SHIFT)) & UART0_S1_NF_MASK)
#define UART0_S1_OR_MASK                         (0x8U)
#define UART0_S1_OR_SHIFT                        (3U)
#define UART0_S1_OR(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_OR_SHIFT)) & UART0_S1_OR_MASK)
#define UART0_S1_IDLE_MASK                       (0x10U)
#define UART0_S1_IDLE_SHIFT                      (4U)
#define UART0_S1_IDLE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_S1_IDLE_SHIFT)) & UART0_S1_IDLE_MASK)
#define UART0_S1_RDRF_MASK                       (0x20U)
#define UART0_S1_RDRF_SHIFT                      (5U)
#define UART0_S1_RDRF(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_S1_RDRF_SHIFT)) & UART0_S1_RDRF_MASK)
#define UART0_S1_TC_MASK                         (0x40U)
#define UART0_S1_TC_SHIFT                        (6U)
#define UART0_S1_TC(x)                           (((uint8_t)(((uint8_t)(x)) << UART0_S1_TC_SHIFT)) & UART0_S1_TC_MASK)
#define UART0_S1_TDRE_MASK                       (0x80U)
#define UART0_S1_TDRE_SHIFT                      (7U)
#define UART0_S1_TDRE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_S1_TDRE_SHIFT)) & UART0_S1_TDRE_MASK)

/* S2 - UART Status Register 2 */
#define UART0_S2_RAF_MASK                        (0x1U)
#define UART0_S2_RAF_SHIFT                       (0U)
#define UART0_S2_RAF(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_S2_RAF_SHIFT)) & UART0_S2_RAF_MASK)
#define UART0_S2_LBKDE_MASK                      (0x2U)
#define UART0_S2_LBKDE_SHIFT                     (1U)
#define UART0_S2_LBKDE(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_S2_LBKDE_SHIFT)) & UART0_S2_LBKDE_MASK)
#define UART0_S2_BRK13_MASK                      (0x4U)
#define UART0_S2_BRK13_SHIFT                     (2U)
#define UART0_S2_BRK13(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_S2_BRK13_SHIFT)) & UART0_S2_BRK13_MASK)
#define UART0_S2_RWUID_MASK                      (0x8U)
#define UART0_S2_RWUID_SHIFT                     (3U)
#define UART0_S2_RWUID(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_S2_RWUID_SHIFT)) & UART0_S2_RWUID_MASK)
#define UART0_S2_RXINV_MASK                      (0x10U)
#define UART0_S2_RXINV_SHIFT                     (4U)
#define UART0_S2_RXINV(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_S2_RXINV_SHIFT)) & UART0_S2_RXINV_MASK)
#define UART0_S2_MSBF_MASK                       (0x20U)
#define UART0_S2_MSBF_SHIFT                      (5U)
#define UART0_S2_MSBF(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_S2_MSBF_SHIFT)) & UART0_S2_MSBF_MASK)
#define UART0_S2_RXEDGIF_MASK                    (0x40U)
#define UART0_S2_RXEDGIF_SHIFT                   (6U)
#define UART0_S2_RXEDGIF(x)                      (((uint8_t)(((uint8_t)(x)) << UART0_S2_RXEDGIF_SHIFT)) & UART0_S2_RXEDGIF_MASK)
#define UART0_S2_LBKDIF_MASK                     (0x80U)
#define UART0_S2_LBKDIF_SHIFT                    (7U)
#define UART0_S2_LBKDIF(x)                       (((uint8_t)(((uint8_t)(x)) << UART0_S2_LBKDIF_SHIFT)) & UART0_S2_LBKDIF_MASK)

/*! @name C3 - UART Control Register 3 */
#define UART0_C3_PEIE_MASK                       (0x1U)
#define UART0_C3_PEIE_SHIFT                      (0U)
#define UART0_C3_PEIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_PEIE_SHIFT)) & UART0_C3_PEIE_MASK)
#define UART0_C3_FEIE_MASK                       (0x2U)
#define UART0_C3_FEIE_SHIFT                      (1U)
#define UART0_C3_FEIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_FEIE_SHIFT)) & UART0_C3_FEIE_MASK)
#define UART0_C3_NEIE_MASK                       (0x4U)
#define UART0_C3_NEIE_SHIFT                      (2U)
#define UART0_C3_NEIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_NEIE_SHIFT)) & UART0_C3_NEIE_MASK)
#define UART0_C3_ORIE_MASK                       (0x8U)
#define UART0_C3_ORIE_SHIFT                      (3U)
#define UART0_C3_ORIE(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_ORIE_SHIFT)) & UART0_C3_ORIE_MASK)
#define UART0_C3_TXINV_MASK                      (0x10U)
#define UART0_C3_TXINV_SHIFT                     (4U)
#define UART0_C3_TXINV(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C3_TXINV_SHIFT)) & UART0_C3_TXINV_MASK)
#define UART0_C3_TXDIR_MASK                      (0x20U)
#define UART0_C3_TXDIR_SHIFT                     (5U)
#define UART0_C3_TXDIR(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C3_TXDIR_SHIFT)) & UART0_C3_TXDIR_MASK)
#define UART0_C3_R9T8_MASK                       (0x40U)
#define UART0_C3_R9T8_SHIFT                      (6U)
#define UART0_C3_R9T8(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_R9T8_SHIFT)) & UART0_C3_R9T8_MASK)
#define UART0_C3_R8T9_MASK                       (0x80U)
#define UART0_C3_R8T9_SHIFT                      (7U)
#define UART0_C3_R8T9(x)                         (((uint8_t)(((uint8_t)(x)) << UART0_C3_R8T9_SHIFT)) & UART0_C3_R8T9_MASK)

/*! @name D - UART Data Register */
#define UART0_D_R0T0_MASK                        (0x1U)
#define UART0_D_R0T0_SHIFT                       (0U)
#define UART0_D_R0T0(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R0T0_SHIFT)) & UART0_D_R0T0_MASK)
#define UART0_D_R1T1_MASK                        (0x2U)
#define UART0_D_R1T1_SHIFT                       (1U)
#define UART0_D_R1T1(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R1T1_SHIFT)) & UART0_D_R1T1_MASK)
#define UART0_D_R2T2_MASK                        (0x4U)
#define UART0_D_R2T2_SHIFT                       (2U)
#define UART0_D_R2T2(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R2T2_SHIFT)) & UART0_D_R2T2_MASK)
#define UART0_D_R3T3_MASK                        (0x8U)
#define UART0_D_R3T3_SHIFT                       (3U)
#define UART0_D_R3T3(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R3T3_SHIFT)) & UART0_D_R3T3_MASK)
#define UART0_D_R4T4_MASK                        (0x10U)
#define UART0_D_R4T4_SHIFT                       (4U)
#define UART0_D_R4T4(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R4T4_SHIFT)) & UART0_D_R4T4_MASK)
#define UART0_D_R5T5_MASK                        (0x20U)
#define UART0_D_R5T5_SHIFT                       (5U)
#define UART0_D_R5T5(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R5T5_SHIFT)) & UART0_D_R5T5_MASK)
#define UART0_D_R6T6_MASK                        (0x40U)
#define UART0_D_R6T6_SHIFT                       (6U)
#define UART0_D_R6T6(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R6T6_SHIFT)) & UART0_D_R6T6_MASK)
#define UART0_D_R7T7_MASK                        (0x80U)
#define UART0_D_R7T7_SHIFT                       (7U)
#define UART0_D_R7T7(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_D_R7T7_SHIFT)) & UART0_D_R7T7_MASK)

/*! @name MA1 - UART Match Address Registers 1 */
#define UART0_MA1_MA_MASK                        (0xFFU)
#define UART0_MA1_MA_SHIFT                       (0U)
#define UART0_MA1_MA(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_MA1_MA_SHIFT)) & UART0_MA1_MA_MASK)

/*! @name MA2 - UART Match Address Registers 2 */
#define UART0_MA2_MA_MASK                        (0xFFU)
#define UART0_MA2_MA_SHIFT                       (0U)
#define UART0_MA2_MA(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_MA2_MA_SHIFT)) & UART0_MA2_MA_MASK)

/*! @name C4 - UART Control Register 4 */
#define UART0_C4_OSR_MASK                        (0x1FU)
#define UART0_C4_OSR_SHIFT                       (0U)
#define UART0_C4_OSR(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C4_OSR_SHIFT)) & UART0_C4_OSR_MASK)
#define UART0_C4_M10_MASK                        (0x20U)
#define UART0_C4_M10_SHIFT                       (5U)
#define UART0_C4_M10(x)                          (((uint8_t)(((uint8_t)(x)) << UART0_C4_M10_SHIFT)) & UART0_C4_M10_MASK)
#define UART0_C4_MAEN2_MASK                      (0x40U)
#define UART0_C4_MAEN2_SHIFT                     (6U)
#define UART0_C4_MAEN2(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C4_MAEN2_SHIFT)) & UART0_C4_MAEN2_MASK)
#define UART0_C4_MAEN1_MASK                      (0x80U)
#define UART0_C4_MAEN1_SHIFT                     (7U)
#define UART0_C4_MAEN1(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C4_MAEN1_SHIFT)) & UART0_C4_MAEN1_MASK)

/*! @name C5 - UART Control Register 5 */
#define UART0_C5_RESYNCDIS_MASK                  (0x1U)
#define UART0_C5_RESYNCDIS_SHIFT                 (0U)
#define UART0_C5_RESYNCDIS(x)                    (((uint8_t)(((uint8_t)(x)) << UART0_C5_RESYNCDIS_SHIFT)) & UART0_C5_RESYNCDIS_MASK)
#define UART0_C5_BOTHEDGE_MASK                   (0x2U)
#define UART0_C5_BOTHEDGE_SHIFT                  (1U)
#define UART0_C5_BOTHEDGE(x)                     (((uint8_t)(((uint8_t)(x)) << UART0_C5_BOTHEDGE_SHIFT)) & UART0_C5_BOTHEDGE_MASK)
#define UART0_C5_RDMAE_MASK                      (0x20U)
#define UART0_C5_RDMAE_SHIFT                     (5U)
#define UART0_C5_RDMAE(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C5_RDMAE_SHIFT)) & UART0_C5_RDMAE_MASK)
#define UART0_C5_TDMAE_MASK                      (0x80U)
#define UART0_C5_TDMAE_SHIFT                     (7U)
#define UART0_C5_TDMAE(x)                        (((uint8_t)(((uint8_t)(x)) << UART0_C5_TDMAE_SHIFT)) & UART0_C5_TDMAE_MASK)


/*!
 * @}
 */ /* end of group UART0_Register_Masks */


/* UART0 - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART0_Type *)UART0_BASE)
/** Array initializer of UART0 peripheral base addresses */
#define UART0_BASE_ADDRS                         { UART0_BASE }
/** Array initializer of UART0 peripheral base pointers */
#define UART0_BASE_PTRS                          { UART0 }
/** Interrupt vectors for the UART0 peripheral type */
#define UART0_RX_TX_IRQS                         { UART0_IRQn }
#define UART0_ERR_IRQS                           { UART0_IRQn }

/*****************************************************************************
 *                           Interrupt vector numbers                        *
 *****************************************************************************/

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  UART0_IRQn                   = 12,               /**< UART0 status and error */
  UART1_IRQn                   = 13,               /**< UART1 status and error */
  UART2_IRQn                   = 14,               /**< UART2 status and error */
  PORTA_IRQn                   = 30,               /**< PORTA pin detect */
  PORTC_PORTD_IRQn             = 31                /**< Single interrupt vector for PORTC and PORTD pin detect */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */

/*****************************************************************************
 *                     Public types/enumerations/variables                   *
 *****************************************************************************/

#define UART_BUFFER_SIZE 64 /* Size of the buffer for the received data */

typedef void (*CallBack_Type)(uint8_t *buffer, uint32_t length); /* Function pointer type for RX callback */


static uint8_t uart_length = 0; /* Length of the received data */
static uint8_t uart_rx_buffer[UART_BUFFER_SIZE]; /* Buffer for the received data */
static uint8_t uart_rx_count = 0; /* Counter for the received data */
static uint8_t *uart_buffer = 0; /* Pointer to the buffer for the received data */

static CallBack_Type uart_callback = 0; /* Callback function pointer */


/*****************************************************************************
 *                            Public functions                               *
 *****************************************************************************/
void UART0_PinConfig(void);
void UART0_Init( uint32_t baud_rate );
extern void SystemCoreClockUpdate(void);
void UART0_PutChar(char c);
void UART0_SendByte(uint8_t data);
void UART0_SendString(char *str);
void UART0_PutChar(char c);
uint8_t UART0_ReceiveByte(void);
void UART0_ReceiveString( uint8_t *str);

#endif /* _UART_H_ */
