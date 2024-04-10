[![epSDK Blinky Example][ep-logo]][ep-link]

[ep-logo]: logo.png
[epSDK-current-state]: epSDK-current-state.PNG
[ep-link]: https://www.embeddedplanet.com/
[ep-doc-link]: https://www.embeddedplanet.com/product-documentation

The epSDK for FreeRTOS provides static library files for sensors and communication interfaces, significantly reducing development time and testing costs. The epSDK provides integration to a user’s application through simple user-friendly API calls.

The intended use of epSDK is with EP supplied hardware and a FreeRTOS OS running on a Nordic nRF52840 microcontroller. Users can configure the communication interfaces and drivers through compiler defines that get passed to the libraries. A slightly modified nRF SDK is provided to users and includes the FreeRTOS kernel. The Sensors, Communication Interfaces, and Bootloader are contained within the epSDK. Users shall develop their individual applications but are provided with an example to get started. Individual drivers and communication interfaces are portable to other hardware using FreeRTOS on an nRF52840 microcontroller. Contact EP to discuss.

The epSDK is provided as a library file compatible with either Connected Sensor, Connected Equipment, or Connected Vehicle. Contact EP to discuss customizations.

![epSDK-current-state]

## License

The software is provided under the [Apache-2.0 license](LICENSE-apache-2.0.txt).

## Documentation
The epSDK Blinky QuickStart Guide and epSDK User Guide can be found on the [EP Documents Page][ep-doc-link]

## Getting Started
Follow the steps in the epSDK Blink QuickStart Guide to get the unit up and running.
