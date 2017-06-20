#include <SoftwareSerial.h>

#define LED_PIN  13

SoftwareSerial bluetooth(10, 9); // RX, TX

void setup()
{
  // Start the hardware serial port
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // onboard LED
  
  bluetooth.begin(9600);
}

void loop()
{
  bluetooth.listen();
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (bluetooth.available() > 0) {
    char inByte = bluetooth.read();
//    Serial.write(inByte);

    String recStr = bluetooth.readString();
    Serial.println(recStr); 
    if (recStr == "powerOn"){
      digitalWrite(LED_PIN, HIGH);
    }else if(recStr == "powerOff"){
      digitalWrite(LED_PIN, LOW);
    }else{
      digitalWrite(LED_PIN, HIGH);

      if (recStr != "0"){
        if(recStr == "1"){
          //1h: 1*60*60*1000
          delay(10 * 1000); //10 sec
        }else if (recStr == "2"){
          //2h: 2*60*60*1000
          delay(20 * 1000); //20 sec
        }else if (recStr == "4"){
          //4h: 4*60*60*1000
          delay(40 * 1000); //40 sec
        }
        digitalWrite(LED_PIN, LOW);
      } 
    }
    
  }

  // Read user input if available.
  if (Serial.available()){
    delay(10); // The DELAY!
    bluetooth.write(Serial.read());
  }
}

