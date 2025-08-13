/*
 * 88q211x_init.c
 *
 *  Created on: Aug 12, 2025
 *      Author: bens1
 */

#include "88q211x.h"
#include "internal/88q211x_init.h"


phy_status_88q211x_t PHY_88Q211X_Init(phy_handle_88q211x_t *dev, phy_config_88q211x_t *config, phy_callbacks_88q211x_t *callbacks) {

    phy_status_88q211x_t status = PHY_88Q211X_OK;

    /* Check the device hasn't already been initialised. Note this may cause an unintended error if the struct uses non-zeroed memory. */
    if (dev->state != PHY_STATE_88Q211X_UNCONFIGURED) status = PHY_88Q211X_ALREADY_CONFIGURED;
    PHY_88Q211X_CHECK_STATUS_RET;

    /* Take the mutex */
    status = callbacks->callback_take_mutex(dev, config->timeout);
    PHY_88Q211X_CHECK_STATUS_RET;

    /* Only the 88Q2112 has been implemented. TODO: Add the 88Q2111 */
    if (config->variant != PHY_VARIANT_88Q2112) status = PHY_88Q211X_NOT_IMPLEMENTED_ERROR;
    PHY_88Q211X_CHECK_STATUS_END;

    /* TODO: Check config parameters */

    /* Check the callbacks */
    if (callbacks->callback_read_reg == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_write_reg == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_get_time_ms == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_delay_ms == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_delay_ns == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_take_mutex == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    if (callbacks->callback_give_mutex == NULL) status = PHY_88Q211X_PARAMETER_ERROR;
    PHY_88Q211X_CHECK_STATUS_END;

    /* Assign the inputs */
    dev->config    = config;
    dev->callbacks = callbacks;

    /* Reset parameters */
    dev->speed   = PHY_SPEED_88Q211X_100M; /* Speed always starts at 100M */
    dev->autoneg = dev->config->mode == PHY_MODE_88Q211X_AUTONEG;
    PHY_88Q211X_ResetEventCounters(dev);


    /* TODO:
     * - Set LP state, PMA/PMD reset, disable loopback, get speed 0x0000
     * - Check ID 0x0002-0x0003
     * - Check autoneg ability 0x0005
     * - PMA Transmit disable 0x0009
     * - Check speed ability 0x0012
     * - Set speed 0x0834
     * - Set master/slave 0x0834
     * - Disable 100BASE-T1 test 0x0836 (already disabled)
     * - Reset, low power, tx disable 0x0900
     * - Check eee + LP ability, check RX PMA/PMD link status 0x0901
     * - Enable EEE and OAM advertisement 0x0902 (already enabled)
     * - Check partner EEE and OAM advertisement 0x0903
     * - Test disable 0x0904
     *
     * -
     */

    /* Move from unconfigured to IDLE */
    dev->state = PHY_STATE_88Q211X_IDLE;

end:

    /* Release the mutex */
    PHY_88Q211X_UNLOCK;
    return status;
}


void PHY_88Q211X_ResetEventCounters(phy_handle_88q211x_t *dev) {
}

phy_status_88q211x_t PHY_88Q211X_CheckID(phy_handle_88q211x_t *dev) {

    phy_status_88q211x_t status = PHY_88Q211X_OK;
    uint32_t             reg_data;

    status = dev->callbacks->callback_read_reg(dev, );
    PHY_88Q211X_CHECK_STATUS_RET;

    return status;
}