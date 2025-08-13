/*
 * 88q211x_init.h
 *
 *  Created on: Aug 12, 2025
 *      Author: bens1
 */

#ifndef INC_88Q211X_INIT_H_
#define INC_88Q211X_INIT_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "88q211x.h"


#define PHY_88Q211X_CHECK_STATUS_RET                 \
    do {                                             \
        if (status != PHY_88Q211X_OK) return status; \
    } while (0)

#define PHY_88Q211X_CHECK_STATUS_END            \
    do {                                        \
        if (status != PHY_88Q211X_OK) goto end; \
    } while (0)

#define PHY_88Q211X_LOCK                                                         \
    do {                                                                         \
        status = dev->callbacks->callback_take_mutex(dev, dev->config->timeout); \
        PHY_88Q211X_CHECK_STATUS_RET;                                            \
    } while (0)

#define PHY_88Q211X_UNLOCK dev->callbacks->callback_give_mutex(dev)


void PHY_88Q211X_ResetEventCounters(phy_handle_88q211x_t *dev);


#ifdef __cplusplus
}
#endif

#endif /* INC_88Q211X_INIT_H_ */