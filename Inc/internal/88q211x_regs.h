/*
 * 88q211x_regs.h
 *
 *  Created on: Aug 12, 2025
 *      Author: bens1
 */

#ifndef INC_88Q211X_REGS_H_
#define INC_88Q211X_REGS_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "88q211x.h"


/* ---------------------------------------------------------------------------- */
/* IEEE PMA/PMD Registers */
/* ---------------------------------------------------------------------------- */

enum PHY_88Q211X_PMAPMDRegs_Enum {
    PHY_88Q211X_REG_PMA_PMD_CTRL_1                    = 0x0000, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_DEV_ID_1                  = 0x0002, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_DEV_ID_2                  = 0x0003, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_SPEED_ABILITY             = 0x0004, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_PKG_DEVS_1                = 0x0005, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_PKG_DEVS_2                = 0x0006, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_CTRL_2                    = 0x0007, /* Device 1 */
    PHY_88Q211X_REG_10G_PMA_PMD_STATUS_2              = 0x0008, /* Device 1 */
    PHY_88Q211X_REG_10G_PMA_TX_DISABLE                = 0x0009, /* Device 1 */
    PHY_88Q211X_REG_10G_PMA_PMD_SIG_DET               = 0x000a, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_EXT_ABILITY               = 0x000b, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_PKG_ID_1                  = 0x000e, /* Device 1 */
    PHY_88Q211X_REG_PMA_PMD_PKG_ID_2                  = 0x000f, /* Device 1 */
    PHY_88Q211X_REG_BASE_T1_PMA_PMD_EXT_ABILITY       = 0x0012, /* Device 1 */
    PHY_88Q211X_REG_100BASE_T1_PMA_PMD_TEST_CTRL      = 0x0834, /* Device 1 */
    PHY_88Q211X_REG_BASE_T1_CTRL                      = 0x0900, /* Device 1 */
    PHY_88Q211X_REG_1000BASE_T1_PMA_STATUS            = 0x0901, /* Device 1 */
    PHY_88Q211X_REG_1000BASE_T1_TRAINING              = 0x0902, /* Device 1 */
    PHY_88Q211X_REG_1000BASE_T1_LINK_PARTNER_TRAINING = 0x0903, /* Device 1 */
    PHY_88Q211X_REG_1000BASE_T1_TEST_MODE_CTRL        = 0x0904, /* Device 1 */
};

/* ---------------------------------------------------------------------------- */
/* Common Control Registers (Device 3) */
/* ---------------------------------------------------------------------------- */

enum PHY_88Q211X_CtrlRegs_Enum {
    PHY_88Q211X_REG_RST_CTRL          = 0x8000, /* Device 3 */
    PHY_88Q211X_REG_TX_DISABLE_STATUS = 0x8002, /* Device 3 */
    PHY_88Q211X_REG_SYNCE_CTRL        = 0x8004, /* Device 3 */
    PHY_88Q211X_REG_INT_EN_1          = 0x8010, /* Device 3 */
    PHY_88Q211X_REG_GPIO_INT_STATUS   = 0x8011, /* Device 3 */
    PHY_88Q211X_REG_TEMP_2            = 0x8041, /* Device 3 */
    PHY_88Q211X_REG_TEMP_3            = 0x8042, /* Device 3 */
    PHY_88Q211X_REG_TEMP_4            = 0x8043, /* Device 3 */
    PHY_88Q211X_REG_INT_EN_2          = 0xfe16, /* Device 3 */
    PHY_88Q211X_REG_INT_STATUS        = 0xfe17, /* Device 3 */
    PHY_88Q211X_REG_TDR_CTRL          = 0xfec3, /* Device 3 */
    PHY_88Q211X_REG_TDR_STATUS_1      = 0xfedb, /* Device 3 */
    PHY_88Q211X_REG_TDR_STATUS_2      = 0xdedc, /* Device 3 */
    PHY_88Q211X_REG_IO_VOLTAGE_CTRL   = 0x8214, /* Device 4!!!! */
    PHY_88Q211X_REG_LPSD_1            = 0x801c, /* Device 3 */
    PHY_88Q211X_REG_LPSD_2            = 0x801d, /* Device 3 */
};

/* ---------------------------------------------------------------------------- */
/* IEEE PCS Registers (Device 3) */
/* ---------------------------------------------------------------------------- */

// enum PHY_88Q211X_PCSRegs_Enum {
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
//     PHY_88Q211X_REG_ = 0x,
// };

/* ---------------------------------------------------------------------------- */
/* IEEE Auto-Negotiation Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* 100BASE-T1 Copper Unit Advance PCS Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* 1000BASE-T1 Copper Unit Advance PCS Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* Copper Unit Advance Auto-Negotiation Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* RGMII Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* SGMII Registers */
/* ---------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------- */
/* PTP Registers */
/* ---------------------------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* INC_88Q211X_REGS_H_ */