#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 9); // RX, TX

void setup()
{
// Start the hardware serial port
Serial.begin(9600);
pinMode(13, OUTPUT); // onboard LED
digitalWrite(13, LOW); // switch OFF LED
bluetooth.begin(9600);
}

void loop()
{
bluetooth.listen();
// while there is data coming in, read it
// and send to the hardware serial port:
while (bluetooth.available() > 0) {
char inByte = bluetooth.read();
Serial.write(inByte);
}

// Read user input if available.
if (Serial.available()){
delay(10); // The DELAY!
bluetooth.write(Serial.read());
}
}
