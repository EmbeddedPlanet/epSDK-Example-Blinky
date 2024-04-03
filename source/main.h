/**
 * Created on: Sept 1, 2022
 * Created by: golobmichael
 *
 * Taken from https://github.com/EmbeddedPlanet/pctel-cellular-demos/tree/master/utils
 * 
 * Copyright (c) Embedded Planet, Inc - All rights reserved
 *
 * This source file is private and confidential.
 * Unauthorized copying of this file is strictly prohibited.
 * 
 * Version 1.0 - 01SEPT22  Initial, ported from: https://github.com/EmbeddedPlanet/nrf_sdk_17_1/tree/master/examples/ble_peripheral/ble_app_hrs_freertos, golobmichael
 */
#ifndef __MAIN_H__
#define __MAIN_H__

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* General defines */

/* Version needs to be defined as string and ints */
#define VERSION_NUM                         "00.00.01"                                   /**< Version. Will be passed to Device Information Service. */
#define VERSION_MAJOR                       0
#define VERSION_MINOR                       0
#define VERSION_BUILD                       1

//////////////////////////////////////////////////
/****                                        ****/
/****               WATCHDOG                 ****/
/****                                        ****/
//////////////////////////////////////////////////

/* Watchdog reload value in s */
#define WATCHDOG_RELOAD         90

/* How often the watchdog should be fed in percent of WATCHDOG_RELOAD */
#define WATCHDOG_RELOAD_RATE    50

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* __MAIN_H__ */