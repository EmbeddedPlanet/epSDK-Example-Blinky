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
 * @file    main.c
 * @version See Version in main.h
 * @author  Embedded Planet, Inc.
 * @author  golobmichael
 * @date    29 AUG 2023
 * 
 * @brief Connected Vehicle Main.  
 * 
 * Built for use with the nRF SDK 17.1
 * 
 */

/**
 * Created on: Sept 1, 2022
 * Created by: golobmichael
 * 
 * Copyright (c) Embedded Planet, Inc - All rights reserved
 *
 * This source file is private and confidential.
 * Unauthorized copying of this file is strictly prohibited.
 * 
 * Version 1.0 - 01SEPT22  Initial
 */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"
#include "ep_bsp.h"
#include "uart_helper.h"
#include "led_helper.h"

#define mainLED_TASK_STACK_SIZE             128
#define DEAD_BEEF                           0xDEADBEEF                              /**< Value used as error code on stack dump, can be used to identify stack location on stack unwind. */

// Used for storage of version
system_info_struct system_info;

/* Cell task handle */
TaskHandle_t ledTaskHandle;

/* Watchdog reload value in seconds */
uint32_t watchdogReload;

/* Miscellaneous initialization including preparing the logging and cell. */
static void prvMiscInitialization( void );

/*-----------------------------------------------------------*/
/**@brief Callback function for asserts in the SoftDevice.
 *
 * @details This function will be called in case of an assert in the SoftDevice.
 *
 * @warning This handler is an example only and does not fit a final product. You need to analyze
 *          how your product is supposed to react in case of Assert.
 * @warning On assert from the SoftDevice, the system can only recover on reset.
 *
 * @param[in]   line_num   Line number of the failing ASSERT call.
 * @param[in]   file_name  File name of the failing ASSERT call.
 */
void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name)
{
    app_error_handler(DEAD_BEEF, line_num, p_file_name);
}

/*-----------------------------------------------------------*/

static void LEDTask( void * pvParameters )
{
    led_init();

    for(;;)
    {
        DBGI("Single blink LED operation");
        led_mode(LED_SINGLE_BLINK, true, 1);

        // Flash single blink for 10s
        vTaskDelay(pdMS_TO_TICKS(10000));

        DBGI("Double blink LED operation");
        led_mode(LED_DOUBLE_BLINK, true, 1);

        // Flash double blink for 10s
        vTaskDelay(pdMS_TO_TICKS(10000));

        DBGI("Triple blink LED operation");
        led_mode(LED_TRIPLE_BLINK, true, 1);

        // Flash triple blink for 10s
        vTaskDelay(pdMS_TO_TICKS(10000));
    }

    vTaskDelete( NULL );
}

/*-----------------------------------------------------------*/

/**@brief Function for application main entry.
 */
int main(void)
{
    /* Miscellaneous initialization including preparing the logging and cell */
    prvMiscInitialization();

    // Start FreeRTOS scheduler.
    vTaskStartScheduler();

    for (;;)
    {
        APP_ERROR_HANDLER(NRF_ERROR_FORBIDDEN);
    }
}

/*-----------------------------------------------------------*/
static void prvMiscInitialization( void )
{
    nrfx_err_t error;

    // Initialize bsp
    ep_bsp_init(WATCHDOG_RELOAD, WATCHDOG_RELOAD_RATE);

    // Initialize modules.
    init_uart(MAIN_LOOP);
    //init_swo();
    uart_helper.dbgi = true;

    /* Set integer version */
    system_info.updateVerMaj = VERSION_MAJOR;
    system_info.updateVerMin = VERSION_MINOR;
    system_info.updateVerBui = VERSION_BUILD;
    /* Set string version */
    sprintf( system_info.updateVerStr,"%02d.%02d.%02ld", system_info.updateVerMaj, system_info.updateVerMin, system_info.updateVerBui );

    DBGI("*************************************************");
    DBGI("* Embedded Planet Blinky FreeRTOS Example v%s *", system_info.updateVerStr);
    DBGI("*************************************************");

    /* Create the task to run tests. */
    xTaskCreate( LEDTask,
                "LEDTask",
                mainLED_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY+1,
                &ledTaskHandle );
}
