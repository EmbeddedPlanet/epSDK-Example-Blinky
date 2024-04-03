/****************************************************************************                                                                     *
 * Copyright (c) 2022 Embedded Planet, Inc.                                 *
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
 * @file    agora.h
 * @author  Embedded Planet, Inc.
 * @author  M. Timieski  & Dan Maher
 * @date    21 Oct 2022
 * 
 * @brief Contains definitions for Agora (DES0263_11) support
 * 
 * Built for use with the nRF SDK 17.1
 * 
 */


#ifndef AGORA_H
#define AGORA_H

//For conversions to Agora in MBED See:
//https://github.com/EmbeddedPlanet/mbed-os/blob/master/targets/TARGET_NORDIC/TARGET_NRF5x/TARGET_NRF52/TARGET_MCU_NRF52840/TARGET_EP_AGORA/PinNames.h

//Port 0 pins 0 to 31 are accessed using: "0 to 31"
//Port 1 pins 0 to 31 are accessed using: "32 to 64" (pin number + 32)

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"

// SDK LED definitions for Agora
#define LEDS_NUMBER    1

#define LED_1          NRF_GPIO_PIN_MAP(0,5)

#define LED_START      LED_1
#define LED_STOP       LED_1

#define LEDS_ACTIVE_STATE 0

#define LEDS_LIST { LED_1 }

#define LEDS_INV_MASK  LEDS_MASK

#define BSP_LED_0      5

#define BUTTONS_NUMBER 1

#define BUTTON_1       29
#define BUTTON_PULL    NRF_GPIO_PIN_PULLUP

#define BUTTONS_ACTIVE_STATE 0

#define BUTTONS_LIST { BUTTON_1 }

#define BSP_BUTTON_0   BUTTON_1

//Agora Debug Output
#define PIN_NAME_DEBUG_RX NRF_GPIO_PIN_MAP(0,16)
#define PIN_NAME_DEBUG_TX NRF_GPIO_PIN_MAP(0,13)

/** Pin Numbering used in SDK examples */ 
#define RX_PIN_NUMBER     PIN_NAME_DEBUG_RX
#define TX_PIN_NUMBER     PIN_NAME_DEBUG_TX
#define CTS_PIN_NUMBER 7
#define RTS_PIN_NUMBER 5
#define HWFC           true

//Agora Cell connections
#define CELL_PWR_EN       NRF_GPIO_PIN_MAP(0, 28)
#define CELL_ON_OFF       NRF_GPIO_PIN_MAP(0, 30)
#define CELL_PWRMON       NRF_GPIO_PIN_MAP(1, 15) //Differs from Galaxis
#define CELL_HW_SHUTDOWN  NRF_GPIO_PIN_MAP(0, 24)
#define CELL_RX_PIN_NUMBER      NRF_GPIO_PIN_MAP(1, 1)
#define CELL_TX_PIN_NUMBER      NRF_GPIO_PIN_MAP(1, 2)
#define CELL_RTS_PIN_NUMBER     NRF_GPIO_PIN_MAP(0, 14)
#define CELL_CTS_PIN_NUMBER     NRF_GPIO_PIN_MAP(1, 8)
#define CELL_DTR_PIN_NUMBER         NRF_GPIO_PIN_MAP(1,4)
#define CELL_DSR _PIN_NUMBER         NRF_GPIO_PIN_MAP(1,3)
#define CELL_DCD_PIN_NUMBER          NRF_GPIO_PIN_MAP(0,15)

// Sensors (I2C)
#define PIN_NAME_SENSOR_POWER_ENABLE    NRF_GPIO_PIN_MAP(0,31)
#define PIN_NAME_SDA                    NRF_GPIO_PIN_MAP(0,26)
#define PIN_NAME_SCL                    NRF_GPIO_PIN_MAP(0,27)

// Miscellaneous I/O
#define PIN_NAME_PUSH_BUTTON       NRF_GPIO_PIN_MAP(0,29)
#define PIN_NAME_LED_RED           NRF_GPIO_PIN_MAP(0,5)
#define PIN_NAME_BT840_RESETN      NRF_GPIO_PIN_MAP(0,18)
#define PIN_NAME_BT840_SWO         NRF_GPIO_PIN_MAP(1,0)
#define BAT_MON_EN_PIN    NRF_GPIO_PIN_MAP(1,11)

#define BSP_QSPI_SCK_PIN    NRF_GPIO_PIN_MAP(0,19)
#define BSP_QSPI_CSN_PIN    NRF_GPIO_PIN_MAP(0,17)
#define BSP_QSPI_IO0_PIN    NRF_GPIO_PIN_MAP(0,20)
#define BSP_QSPI_IO1_PIN    NRF_GPIO_PIN_MAP(0,21)
#define BSP_QSPI_IO2_PIN    NRF_GPIO_PIN_MAP(0,22)
#define BSP_QSPI_IO3_PIN    NRF_GPIO_PIN_MAP(0,23)


// serialization APPLICATION board - temp. setup for running serialized MEMU tests
#define SER_APP_RX_PIN              NRF_GPIO_PIN_MAP(0,16)    // UART RX pin number.
#define SER_APP_TX_PIN              NRF_GPIO_PIN_MAP(0,13)    // UART TX pin number.
#define SER_APP_CTS_PIN             NRF_GPIO_PIN_MAP(0,2)     // UART Clear To Send pin number.
#define SER_APP_RTS_PIN             NRF_GPIO_PIN_MAP(1,15)    // UART Request To Send pin number.

#define SER_APP_SPIM0_SCK_PIN       NRF_GPIO_PIN_MAP(0,27)     // SPI clock GPIO pin number.
#define SER_APP_SPIM0_MOSI_PIN      NRF_GPIO_PIN_MAP(0,2)      // SPI Master Out Slave In GPIO pin number
#define SER_APP_SPIM0_MISO_PIN      NRF_GPIO_PIN_MAP(0,26)     // SPI Master In Slave Out GPIO pin number
#define SER_APP_SPIM0_SS_PIN        NRF_GPIO_PIN_MAP(1,13)     // SPI Slave Select GPIO pin number
#define SER_APP_SPIM0_RDY_PIN       NRF_GPIO_PIN_MAP(1,15)     // SPI READY GPIO pin number
#define SER_APP_SPIM0_REQ_PIN       NRF_GPIO_PIN_MAP(1,14)     // SPI REQUEST GPIO pin number

// serialization CONNECTIVITY board
#define SER_CON_RX_PIN              NRF_GPIO_PIN_MAP(1,14)    // UART RX pin number.
#define SER_CON_TX_PIN              NRF_GPIO_PIN_MAP(1,13)    // UART TX pin number.
#define SER_CON_CTS_PIN             NRF_GPIO_PIN_MAP(1,15)    // UART Clear To Send pin number. Not used if HWFC is set to false.
#define SER_CON_RTS_PIN             NRF_GPIO_PIN_MAP(0,2)     // UART Request To Send pin number. Not used if HWFC is set to false.


#define SER_CON_SPIS_SCK_PIN        NRF_GPIO_PIN_MAP(0,7)     // SPI SCK signal.
#define SER_CON_SPIS_MOSI_PIN       NRF_GPIO_PIN_MAP(0,11)    // SPI MOSI signal.
#define SER_CON_SPIS_MISO_PIN       NRF_GPIO_PIN_MAP(0,12)    // SPI MISO signal.
#define SER_CON_SPIS_CSN_PIN        NRF_GPIO_PIN_MAP(1,9)     // SPI CSN signal.
#define SER_CON_SPIS_RDY_PIN        NRF_GPIO_PIN_MAP(1,15)    // SPI READY GPIO pin number.
#define SER_CON_SPIS_REQ_PIN        NRF_GPIO_PIN_MAP(1,14)    // SPI REQUEST GPIO pin number.

#define SER_CONN_CHIP_RESET_PIN     NRF_GPIO_PIN_MAP(1,1)    // Pin used to reset connectivity chip

// Arduino board mappings
#define ARDUINO_SCL_PIN             27    // SCL signal pin
#define ARDUINO_SDA_PIN             26    // SDA signal pin
#define ARDUINO_AREF_PIN            2     // Aref pin

#define ARDUINO_13_PIN              NRF_GPIO_PIN_MAP(1, 15)  // Digital pin 13
#define ARDUINO_12_PIN              NRF_GPIO_PIN_MAP(1, 14)  // Digital pin 12
#define ARDUINO_11_PIN              NRF_GPIO_PIN_MAP(1, 13)  // Digital pin 11
#define ARDUINO_10_PIN              NRF_GPIO_PIN_MAP(1, 12)  // Digital pin 10
#define ARDUINO_9_PIN               NRF_GPIO_PIN_MAP(1, 11)  // Digital pin 9
#define ARDUINO_8_PIN               NRF_GPIO_PIN_MAP(1, 10)  // Digital pin 8

#define ARDUINO_7_PIN               NRF_GPIO_PIN_MAP(1, 8) // Digital pin 7
#define ARDUINO_6_PIN               NRF_GPIO_PIN_MAP(1, 7) // Digital pin 6
#define ARDUINO_5_PIN               NRF_GPIO_PIN_MAP(1, 6) // Digital pin 5
#define ARDUINO_4_PIN               NRF_GPIO_PIN_MAP(1, 5) // Digital pin 4
#define ARDUINO_3_PIN               NRF_GPIO_PIN_MAP(1, 4) // Digital pin 3
#define ARDUINO_2_PIN               NRF_GPIO_PIN_MAP(1, 3) // Digital pin 2
#define ARDUINO_1_PIN               NRF_GPIO_PIN_MAP(1, 2) // Digital pin 1
#define ARDUINO_0_PIN               NRF_GPIO_PIN_MAP(1, 1) // Digital pin 0

#define ARDUINO_A0_PIN              3     // Analog channel 0
#define ARDUINO_A1_PIN              4     // Analog channel 1
#define ARDUINO_A2_PIN              28    // Analog channel 2
#define ARDUINO_A3_PIN              29    // Analog channel 3
#define ARDUINO_A4_PIN              30    // Analog channel 4
#define ARDUINO_A5_PIN              31    // Analog channel 5


#ifdef __cplusplus
}
#endif

#endif // AGORA_H
