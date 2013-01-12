
const int buttonPin = 2;     // the number of the pushbutton pin
const int maxButtonPin = 7;

const int jostikInitPin = 0;
const int jostikEndPin = 3;

const int ledPin =  13;      // the number of the LED pin
const String arrayBits = "111111";
const String arrayLettersBits = "arbxyl";
const String arrayJostikBits = "1111";
unsigned char x = 1;
String bits = arrayBits;
String jostickBits = arrayJostikBits;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(ledPin, OUTPUT);      
  
  for (int i = 2; i <= maxButtonPin; i++) {
      pinMode(i, INPUT);     
  }
  
  /**
  Esto era cuando era digital, pero read tomaba 0.1 v como HIGH
  for (int i = jostikInitPin; i <= jostikEndPin; i++) {
      pinMode(i, INPUT);     
  }
  */
}

void loop(){
  // read the state of the pushbutton value:
  for (int i = 2; i <= maxButtonPin; i++) {
    buttonState = digitalRead(i);
    if (buttonState != HIGH) {
      Keyboard.press(arrayLettersBits[i-2]);
    } else {
        Keyboard.release(arrayLettersBits[i-2]);
    }
    
  }
  
  /*
  if (bits[0] == '1') {
    Keyboard.write(97);
  }
  */
  
  for (int i = jostikInitPin; i <= jostikEndPin; i++) {
    buttonState = analogRead(i);
    if (buttonState == 1023.00) {
      switch(i) {
        case 0:
          Keyboard.write(KEY_RIGHT_ARROW);
          break;
        case 1:
          Keyboard.write(KEY_LEFT_ARROW);
          break;
        case 2:
          Keyboard.write(KEY_DOWN_ARROW);
          break;
        case 3:
          Keyboard.write(KEY_UP_ARROW);
          break;
      }
      
      jostickBits[i-jostikInitPin]='0';
    }
    
  }
  
  /**
  Serial.println(bits); 
  Serial.println(jostickBits); 
  **/

  bits = arrayBits;
  jostickBits = arrayJostikBits;
  delay(300);

    // turn LED on:    
 //   digitalWrite(ledPin, HIGH);  
 
}
