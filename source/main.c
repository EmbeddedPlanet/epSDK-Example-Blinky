/****************************************************************************                                                                     *
 * Copyright (c) 2023 Embedded Planet, Inc.                                 *
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

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"
#include "ep_bsp.h"
#include "time_helper.h"
#include "uart_helper.h"
#include "led_helper.h"

#define mainLED_TASK_STACK_SIZE             128
#define DEAD_BEEF                           0xDEADBEEF                              /**< Value used as error code on stack dump, can be used to identify stack location on stack unwind. */
#define OSTIMER_WAIT_FOR_QUEUE              2                                       /**< Number of ticks to wait for the timer queue to be ready */

// Used for retrieval of device serial number from external flash
#define SERIAL_LENGTH       6
uint8_t ep_serial[SERIAL_LENGTH] = {'\0'};

/* Cell task handle */
TaskHandle_t ledTaskHandle;

char updateVerStr[9];
uint8_t updateVerMaj;
uint8_t updateVerMin;
uint16_t updateVerBui;

/* Watchdog reload value in seconds */
uint32_t watchdogReload;

/* Sensor power enable is required */
#define SENSOR_PWR_ENABLE NRF_GPIO_PIN_MAP(0, 31)

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
    // Initialize LED library
    led_init();

    for(;;)
    {
        // Set LED to double blink pattern
        led_mode(LED_DOUBLE_BLINK, true, 1);

        // Enable debug uart for this task
        init_uart(TASK_1);

        // Print debug log message
        DBGI("Starting LED double blink pattern for 10s");

        // Put uart to sleep
        uninit_uart(TASK_1);

        // Delay 5s
        vTaskDelay(pdMS_TO_TICKS(10000));

        // Turn off LED operation
        led_mode(LED_OFF, true, 1);

        // Enable debug uart for this task
        init_uart(TASK_1);

        // Print debug log message
        DBGI("Turning LED off for 10s");

        // Put uart to sleep
        uninit_uart(TASK_1);

        // Delay 5s
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
// Taken from FreeRTOS demo: https://github.com/FreeRTOS/FreeRTOS/blob/main/FreeRTOS-Plus/Demo/FreeRTOS_Cellular_Interface_Windows_Simulator/Common/main.c
static void prvMiscInitialization( void )
{
    nrfx_err_t error;

    #if defined(BOARD_GALAXIS)
    //Pullup the Rx line of Galaxis, otherwise noise is coupled
    // to the RX line and will generate a communication error:
    // "APP_UART_COMMUNICATION_ERROR" on the UART initialization.  
    // The communication error handler forces the system to restart,
    // so this issue may cuase the system to hang and reboot
    // a number of times.
    nrf_gpio_cfg_input(RX_PIN_NUMBER, NRF_GPIO_PIN_PULLUP);
    #endif

    // Initialize bsp
    ep_bsp_init(WATCHDOG_RELOAD, WATCHDOG_RELOAD_RATE);

    // Initialize debug output.
    init_uart(MAIN_LOOP);
    //init_swo();
    uart_helper.dbgi = true;

    // Start low frequency clock and rtc
    set_time(0);

    //Disable sensor power for low power
    nrf_gpio_cfg_output(SENSOR_PWR_ENABLE);
    nrf_gpio_pin_clear(SENSOR_PWR_ENABLE);

    DBGI("*************************************************");
    DBGI("* Embedded Planet Blinky FreeRTOS Example v%s *", VERSION_NUM);
    DBGI("*************************************************");

    /* Create the task to run tests. */
    xTaskCreate( LEDTask,
                "LEDTask",
                mainLED_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY+1,
                &ledTaskHandle );

    // Put uart to sleep
    uninit_uart(MAIN_LOOP);
}