/*
 * 88q211x.h
 *
 *  Created on: Aug 3, 2025
 *      Author: bens1
 */

#ifndef INC_88Q211X_H_
#define INC_88Q211X_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "stdint.h"
#include "stdbool.h"
#include "stdatomic.h"
#include "hal.h"


typedef struct phy_handle_88q211x_t phy_handle_88q211x_t;

typedef enum {
    PHY_88Q211X_OK      = HAL_OK,
    PHY_88Q211X_ERROR   = HAL_ERROR,
    PHY_88Q211X_BUSY    = HAL_BUSY,
    PHY_88Q211X_TIMEOUT = HAL_TIMEOUT,
    PHY_88Q211X_ALREADY_CONFIGURED,
    PHY_88Q211X_PARAMETER_ERROR,
    PHY_88Q211X_NOT_IMPLEMENTED_ERROR,
} phy_status_88q211x_t;

typedef enum {
    PHY_VARIANT_88Q2111,
    PHY_VARIANT_88Q2112,
} phy_variant_88q211x_t;

typedef enum {
    PHY_INTERFACE_88Q211X_RGMII   = 0x0,
    PHY_INTERFACE_88Q211X_SGMII   = 0x1,
    PHY_INTERFACE_88Q211X_INVALID = 0x2
} phy_interface_88q211x_t;

typedef enum {
    PHY_MODE_88Q211X_FIXED_SPEED_100M = 0x0, /* Speed is programmed once at startup */
    PHY_MODE_88Q211X_FIXED_SPEED_1G   = 0x1, /* Speed is programmed once at startup */
    PHY_MODE_88Q211X_AUTONEG          = 0x2, /* Speed is automatically negotiated (AUTONEG) */
    PHY_MODE_88Q211X_DYNAMIC_SPEED    = 0x3, /* Speed is updated dynamically by the application (e.g. for connecting to potentially non-autoneg PHYs of unknown speed) (100/1000M/AUTONEG) */
    PHY_MODE_88Q211X_INVALID          = 0x4
} phy_mode_88q211x_t;

typedef enum {
    PHY_SPEED_88Q211X_1G      = 0x0,
    PHY_SPEED_88Q211X_100M    = 0x1,
    PHY_SPEED_88Q211X_INVALID = 0x2
} phy_speed_88q211x_t;

typedef struct {
    phy_variant_88q211x_t   variant;
    uint32_t                timeout; /* Timeout in ms for doing anything with a timeout (read, write, take mutex etc) */
    uint8_t                 phy_addr;
    phy_mode_88q211x_t      mode;
    phy_interface_88q211x_t interface;
} phy_config_88q211x_t;

/* Stores information about driver events */
typedef struct {
} phy_event_counters_88q211x_t;

typedef enum {
    PHY_STATE_88Q211X_UNCONFIGURED = 0,
    PHY_STATE_88Q211X_IDLE,
} phy_state_88q211x_t;

typedef phy_status_88q211x_t (*phy_callback_88q211x_read_reg_t)(phy_handle_88q211x_t *dev, uint32_t reg, uint32_t *data);
typedef phy_status_88q211x_t (*phy_callback_88q211x_write_reg_t)(phy_handle_88q211x_t *dev, uint32_t reg, uint32_t data);
typedef uint32_t (*phy_callback_88q211x_get_time_ms_t)(phy_handle_88q211x_t *dev);
typedef void (*phy_callback_88q211x_delay_ms_t)(phy_handle_88q211x_t *dev, uint32_t ms);
typedef void (*phy_callback_88q211x_delay_ns_t)(phy_handle_88q211x_t *dev, uint32_t ns);
typedef phy_status_88q211x_t (*phy_callback_88q211x_take_mutex_t)(phy_handle_88q211x_t *dev, uint32_t timeout);
typedef phy_status_88q211x_t (*phy_callback_88q211x_give_mutex_t)(phy_handle_88q211x_t *dev);

typedef struct {
    phy_callback_88q211x_read_reg_t    callback_read_reg;    /* Read from a register */
    phy_callback_88q211x_write_reg_t   callback_write_reg;   /* Write to a register */
    phy_callback_88q211x_get_time_ms_t callback_get_time_ms; /* Get time in ms */
    phy_callback_88q211x_delay_ms_t    callback_delay_ms;    /* Non-blocking delay in ms */
    phy_callback_88q211x_delay_ns_t    callback_delay_ns;    /* Blocking delay in ns */
    phy_callback_88q211x_take_mutex_t  callback_take_mutex;  /* Take the mutex protecting the device */
    phy_callback_88q211x_give_mutex_t  callback_give_mutex;  /* Give the mutex protecting the device */
} phy_callbacks_88q211x_t;

struct phy_handle_88q211x_t {
    const phy_config_88q211x_t    *config;
    const phy_callbacks_88q211x_t *callbacks;
    phy_event_counters_88q211x_t   events;
    phy_state_88q211x_t            state;
    phy_speed_88q211x_t            speed;
    bool                           autoneg;
};

phy_status_88q211x_t PHY_88Q211X_Init(phy_handle_88q211x_t *dev, phy_config_88q211x_t *config, phy_callbacks_88q211x_t *callbacks);
void                 PHY_88Q211X_HandleInterrupt(phy_handle_88q211x_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* INC_88Q211X_H_ */
