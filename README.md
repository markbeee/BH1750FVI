# **Library and example sketch for light sensor BH1750FVI works with Arduino, ESP8266**
 
This library works with the ambient light sensor BH1750FVI both tested with Arduino and ESP8266.
The demo sketch puts out the current ambient light value via the serial port.
The address pin should be tied to GND to use the default I2C-address 0x23. You can change it in the BH1750FVI header file if you need a different address.

BH1750FVI connected to a ESP12 breadboard adapter board
(see my project [ESP8266 breadboard adapter board](https://github.com/markbeee/ESP8266_Breakout_Board))

![BH1750FVI breadboard setup with ESP8266](/images/BH1750FVI.jpg)

I use the BH1750FVI in my [IKEA Krydda hydroponics project](https://github.com/markbeee/IKEA_hydroponics_control)

