# ESPHome-Victron-VE.Direct-Control
Using Victron VE.Direct to Control my Victron Blue Smart IP22 Power source

## General idea
My plan was to use the *Victron Blue Smart IP22 Charger 24/8 (1)* charger in power source mode to charge my Anker Solix E1600 in order to charge it with the power of my solar panels ("Nulleinspeisung"). I chose this charger because it has a VE.Direct port and it's quite cheep and high quality. How to access the port is shown in: [Victron_BlueSmart_IP22](https://github.com/pvtex/Victron_BlueSmart_IP22).

So far I just implemented the cyclic readout and the setting of the voltage and current. I don't have a lot experiance in ESPHome so see this more like an example. If you have any suggestions feel free to contribute. Maybe this methode can be expanded to other Victron devices, but I don't know.

## Approach
I used the [VictronConnect App](https://www.victronenergy.com/support-and-downloads/software#victronconnect-app) for Linux and connect my Laptop via USB2Serial with the VE.Direct Port. Using the ESP in listening mode to the TX-Line of the USB2Serial while sending commands I was able to reverse engineer the necessary commands (I know the sent values are in hex, but calculating the chars from the int were faster, same for the checksum).

## Usefull links
- https://www.victronenergy.com/upload/documents/VE.Direct-Protocol-3.33.pdf
- https://www.victronenergy.com/live/vedirect_protocol:faq
- https://github.com/pvtex/Victron_BlueSmart_IP22
