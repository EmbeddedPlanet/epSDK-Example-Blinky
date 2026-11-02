/****************************************************************************                                                                     *
 * Copyright (c) 2026 Embedded Planet, Inc.                                 *
 * SPDX-License-Identifier: Apache-2.0                                      *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *     http://www.apache.org/licenses/LICENSE-2.0                           *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ****************************************************************************/
/**
 * Created on: Apr 2, 2024
 * Created by: golobmichael
 * 
 * Copyright (c) Embedded Planet, Inc - All rights reserved
 *
 * This source file is private and confidential.
 * Unauthorized copying of this file is strictly prohibited.
 * 
 * Version 1.0 - 01SEPT22  Initial
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
#define VERSION_NUM                         "00.00.02"                                   /**< Version. Will be passed to Device Information Service. */
#define VERSION_MAJOR                       0
#define VERSION_MINOR                       0
#define VERSION_BUILD                       2

/* Struct to hold system information */
typedef struct
{
    char updateVerStr[9];
    uint8_t updateVerMaj;
    uint8_t updateVerMin;
    uint16_t updateVerBui;
} system_info_struct;
extern system_info_struct system_info;

//////////////////////////////////////////////////
/****                                        ****/
/****               WATCHDOG                 ****/
/****                                        ****/
//////////////////////////////////////////////////

/* Watchdog reload value in s */
#define WATCHDOG_RELOAD         90

/* How often the watchdog should be fed in percent of WATCHDOG_RELOAD */
#define WATCHDOG_RELOAD_RATE    50

//////////////////////////////////////////////////
/****                                        ****/
/****                  LED                   ****/
/****                                        ****/
//////////////////////////////////////////////////
#define ENABLE_LED_OPERATION    true

/** < Amount of time, in milliseconds, that the LED remains on during slow blinks*/
#define LED_SLOW_BLINK_LENGTH               pdMS_TO_TICKS(1000)

/** < Amount of time, in milliseconds, between slow blinks */
#define LED_SLOW_BLINK_INTERVAL             pdMS_TO_TICKS(1000)

/** < Amount of time, in milliseconds, that the LED remains on during fast blinks */
#define LED_FAST_BLINK_LENGTH               pdMS_TO_TICKS(200)

/** < Amount of time, in milliseconds, between fast blinks */
#define LED_FAST_BLINK_INTERVAL             pdMS_TO_TICKS(200)

/** < Amount of time, in milliseconds, that the LED remains on during extra fast blinks */
#define LED_EXTRA_FAST_BLINK_LENGTH         pdMS_TO_TICKS(75)

/** < Amount of time, in milliseconds, between extra fast blinks */
#define LED_EXTRA_FAST_BLINK_INTERVAL       pdMS_TO_TICKS(75)

/** < Amount of time, in milliseconds, that the LED remains on during alive blinks */
#define LED_ALIVE_BLINK_LENGTH              pdMS_TO_TICKS(100)

/** < Amount of time, in milliseconds, between alive blinks */
#define LED_ALIVE_BLINK_INTERVAL            pdMS_TO_TICKS(15000)

/** < Amount of time, in milliseconds, that the LED remains on during multi-blink patterns */
#define LED_MULTI_BLINK_LENGTH              pdMS_TO_TICKS(135)

/** < Amount of time, in milliseconds, between slow multi-blinks */
#define LED_MULTI_BLINK_INTERVAL            pdMS_TO_TICKS(3000)

/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* __MAIN_H__ */
