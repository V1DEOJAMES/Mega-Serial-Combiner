# Mega-Serial-Combiner
 Uses the three serial channels on the Arduino Mega to create a 3->1 Serial channel. Adds numbers infront of each new line to identify which channel the serial data originates from. Tested only at 115200baud

This takes what would normally require 3 different UART converters and thus three USB ports into one Mega and one USB port. 
This also handles the issue that many serial converters are very bad at combining two different serial channels at the same time- and often end up out of sync. 

As an example talking to a device with AT commands:
COM1 (My device sending AT commands to a network module)
```
172560 - AT+CSQ
```
COM2 (The network module responding to my AT command)
```
172560 - 
172560 - +CSQ: 99,99
172561 - 
172561 - OK
```
COM3 (A debug channel reporting the result of the communication)
```
172561 - --CSQ? 99 | Code(1)--
```
This can be very annoying if you need to save the resulting conversation- there is software which combines these conversations- but often due to the nature of serial communications it can be out of sync and timestamps will vary wildly which can complicates thing if you need to track the timing of a conversation.

With this small amount of code and the Arduino Mega- these issues are resolved and the resulting conversation would be printed as:
```
172560 - 3: AT+CSQ
172560 - 2: 
172560 - 2: +CSQ: 99,99
172561 - 2: 
172561 - 2: OK
172561 - 1: --CSQ? 99 | Code(1)--
```
