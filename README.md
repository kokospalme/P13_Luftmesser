
# Projekt Luftmesser

Unterlagen zum Projekt "Luftmesser" (v1.0)
##### Alle Daten unterliegen der Creative Common Lizenz CC BY-SA 4.0 (https://creativecommons.org/licenses/by-sa/4.0/)
##### <img src="https://github.com/kokospalme/P13_Luftmesser/blob/main/Bilder/QR.png"  height = "150" width = "150" >

## Lerninhalte

### Hardware/Schaltplan
- Vorwiderstände (Einsatz und Berechnung)
- Spannungsteiler (Einsatz und Berechnung)
- Schaltplan (Lesen und Verstehen)
- Microcontrollerboards (Einsatz von Pins)

### Programmierung (Arduino/C++)
#### Code Level 1
- #defines
- Variablen (bool, int)
- pinMode()
- analogRead()
- digitalWrite()
- for-Schleifen
- delay
- if-else-Anweisung

#### Code Level 2
- #defines
- Variablen (bool, int)
- arrays (int)
- pinMode()
- analogRead()
- digitalWrite()
- for-Schleifen
- delay
- if-else-Anweisung
- Mittelwertberechnung mit Arrays
## Software
### Arduino SDK
https://www.arduino.cc/en/software
#### STM8 Package/Core
https://github.com/tenbaht/sduino/raw/master/package_sduino_stm8_index.json

##### komplexere SDKs:
- patformIO:  https://platformio.org/platformio-ide
- sloeber: http://eclipse.baeyens.it/index.shtml

### stlink Treiber
https://github.com/stlink-org/stlink
#### OSX
https://macappstore.org/stlink/
#### Windows
Die Installation auf Windows habe ich bisher nicht getestet...
#### Linux
die auch noch nicht :)

## Hardware
### parts
- 1x CPU STM8S103F3P6 Board (eBay), support und Pinout: https://tenbaht.github.io/sduino/hardware/stm8blue/
- 1x Pinheader 4x2.54mm (Pollin)
- 1x Gas Sensor MQ-135 (eBay)
- 3x LED 3mm: rot, gelb, grün (eBay)
- 3x Widerstand 330 Ohm (Sortiment Pollin)
- 2x Widerstand 100kOhm (Sortiment Pollin)
- ca. 10 cm Kabellitze (eBay, Pollin)
Alternativen zu Pollin: Reichelt Elektronik, Conrad electronics
### Programmieren
- Programmier-Adapter ("progammer") ST-Link V2 (eBay)
##### Foto:
<img src="https://github.com/kokospalme/P13_Luftmesser/blob/main/Bilder/ST%20Link%20programmer.png">

##### ...oder billig-Clon (kann dann nur STM8, nicht STM32 programmieren!):
<img src="https://github.com/kokospalme/P13_Luftmesser/blob/main/Bilder/clone%20STlinkv2.png">
