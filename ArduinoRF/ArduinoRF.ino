#include <RCSwitch.h>
 
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

RCSwitch mySwitch = RCSwitch();
int RCTransmissionPin = 5;

void setup() {
  
  Serial.begin(9600);
  inputString.reserve(200);
  
  mySwitch.enableTransmit( RCTransmissionPin );
}

void loop() {
  
   if (stringComplete) {
    
              if(inputString.indexOf("[1-on]") == 0)
                { 
                processCommand("a");
                
	        }
             if(inputString.indexOf("[1-off]") == 0)
                { 
                processCommand("b");
               
	        }
            if(inputString.indexOf("[2-on]") ==0)
                { 
                processCommand("c");
               
	        }
             if(inputString.indexOf("[2-off]") ==0)
                { 
                processCommand("d");
              
	        }
             if(inputString.indexOf("[3-on]") ==0)
                { 
                processCommand("e");
              
	        }
             if(inputString.indexOf("[3-off]") ==0)
                { 
                processCommand("f");
                }          
    
    
    
    
    
    //Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
void processCommand(String command) {
  if        (command == "a") {
    mySwitch.send(12673608, 24);
 
  } else if (command == "b") {
    mySwitch.send(12673609, 24);

  } else if (command == "c") {
    mySwitch.send(12673604, 24);

  } else if (command == "d") {
    mySwitch.send(12673613, 24);
  
  } else if (command == "e") {
    mySwitch.send(12673602, 24);

  } else if (command == "f") {
    mySwitch.send(12673615, 24);
  }
}
