# UART Helper

The UART Helper is used to enable LibUARTE1 input/output and SWO output

## Contents
**uart_helper.h** - Utility header.

## Set up
1. Include **uart_helper.h** in the necessary source files
2. Add the include path for **uart_helper.h** to your Makefile

## Config
The sdk_config.h is modified to contain:
```C++
    #define RETARGET_ENABLED        1
    #define SEND_LOG_OVER_UART      1
    #define SEND_LOG_OVER_SWO       1
    #define NRF_LIBUARTE_DRV_UARTE1 1
    #define NRFX_UARTE_ENABLED      1
    #define NRFX_UARTE1_ENABLED     1
    #define TIMER_ENABLED           1
    #define TIMER3_ENABLED          1
    #define TIMER4_ENABLED          1
    #define NRFX_TIMER_ENABLED      1
    #define NRFX_TIMER3_ENABLED     1
    #define NRFX_TIMER4_ENABLED     1

```
In source code the initialization for UART and/or SWO performed:
```C++
    init_uart(MAIN_LOOP);
    init_swo();
```
Note that if "init_swo()" is not defined, the output is still sent to the SWO port when the program runs immediately after programming.  Once the device has been reset the output to SWO will cease. 

Note that the following line needs to be added in the Makefile compile flag options to enable SWO:
```C++
CFLAGS += -DENABLE_SWO
```

Note that the following line needs to be added in the Makefile compile flag options to enable all features:
```C++
CFLAGS += -DFREERTOS
```

##  Header
Header file for initializing LibUARTE1 input/output and SWO output.

The header file also contains a controllable debug print mechanism. The mechanism is used to standardize information, warning, and error messages.  It is used like a printf statement with the return and line feed characters automatically appended.  The information, warning, and errors can be enabled and disabled on the fly.

By default DBGI (debug information) is turned off, but can be globally enabled (uart_helper.dbgi = true; to enable) in the main function and can be selectively enabled and disabled around specific problem code areas.

Warnings and errors are enabled by default but can be disabled/enabled on the fly throughout code:
```C++
uart_helper.dbgi = true;  
uart_helper.dbgw = false;   
uart_helper.dbge = false;
```  

The debug information can contain additional information:  function file and line number (full), function and line number (compact),or just the debug text (none) by selecting the header style:   
uart_helper.dbg_header_style = DEBUG_HEADER_FULL;   
uart_helper.dbg_header_style = DEBUG_HEADER_COMPACT;   
uart_helper.dbg_header_style = DEBUG_HEADER_NONE;  

The header style can also be changed on the fly.

The warning and error messages are sent with color escape sequences to both the SWO and UART to help with quick identification of warnings and errors.

The debug UART has the following defines for enabling and disabling of UART:
    MAIN_LOOP
    TASK_1
    TASK_2 - used by cell library
    TASK_3
    TASK_4
Debug UART will be enabled with an init_uart containing these defines. Debug UART will be disabled when they have all be uninitialized or never initialized.

Examples:
```C++
    init_uart(MAIN_LOOP);
    init_swo();

    DBGI("TEST1");
    DBGW("TEST2");
    DBGE("TEST3");
    uart_helper.dbgi = true;
    DBGI("TEST4");
    uart_helper.dbg_header_style = DEBUG_HEADER_FULL;
    DBGI("TEST5");
    /* Shut off debug uart for sleep mode */
    uninit_uart(MAIN_LOOP);
```

Displays the following in the UART and/or SWO port:

<span style="color:cyan">[WRN][main:216]: TEST2</span>   
<span style="color:red">[ERR][main:217]: TEST3</span>   
[INF][main:219]: TEST4   
[INF][main - ../source/main.c:221]: TEST5