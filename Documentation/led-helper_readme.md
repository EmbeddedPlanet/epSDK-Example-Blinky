# LED Helper Utility

This utility allows for easy control of an LED by passing predefined blink patterns to a background FreeRTOS task.

## Contents
**led_helper.h** - Utility header.

## Set up
1. Include **led_helper.h** in the necessary source files
2. Add the include path for **led_helper.h** to your Makefile

**SDK_config.h**  
Ensure the the following parameters are present and configured in the SDK_config.h. Refer to SDK_config.h in the example.
```C++
No specific defines needed.
```

## LED Color Mask
The third parameter used in the "led_mode" is a binary mask use to activate one or more available LEDs:

The Galaxis has a RGB LED and can be set to the following colors using the mask.  
**Galaxis Mask Values:**  
1 - Red  
2 - Green  
3 - Yellow  
4 - Blue  
5 - Magenta  
6 - Cyan  
7 - White  

The Agora has a Red LED, and can onyl be set to RED.
**Agora Mask Values:**  
1 - Red  

## Use
Detailed use can be found in epSDK User Guide as well as the header file. However, the most simplified steps are as follows:

```C++
    /* First, the led utility needs to be initialized. This begins the background FreeRTOS task */
    led_init();

    /* Now we can pass any flash pattern pre-defined in the led_mode_enum within the led_helper.h file by use of the led_mode function 
    The led_mode function takes two parameters: the flash pattern and a bool that indicates whether the utility shall latch that
    flash pattern. 
    */

    /* The third parameter of the led_mode function
    is a binary mask to set active LEDs, using 2^(n-1), 
    where 'n' is the LED or LEDs of interest.  
    For example: If the device supports a single
    LED the mask is set to 1.
    For three LEDs: 1,2, or 4 set the individual
    LEDs with 3 setting LED 1 and 2, and 5,6 and 7
    setting additional combinations of the LEDs.
    */

    /* Turn the LED on: */
    led_mode(LED_ON, true, 1);

    /* Turn the LED off: */
    led_mode(LED_OFF, true, 1);

    /* This will set the LED to a repeated fast blink, since latch == true */
    led_mode(LED_FAST_BLINK, true, 1);

    /* This will set the LED to a single fast blink, since latch == false */
    led_mode(LED_FAST_BLINK, false, 1);

    /* Turn LEDs off to lower sleep current */
    led_pause();
    /*/ Shutoff any LEDs, turn to input */
    nrf_gpio_cfg_default(NRF_GPIO_PIN_MAP(0, 8));
```

## Versions
- V0.0.1 Initial Release. Only supports a single LED.
- V0.1.0 Update support for multiple LED/LED colors.  Revise 'led_mode' function to include led_mask input parameter.
