/*
  Blink patterns
  Turns on LEDs on and off repeatedly on a pattern.
  The potentiometer is used to change the intesity of light from the LEDs.
  The button/switch changes the pattern on press.

  - Nidesh Chitrakar
*/

bool didPress = false;
int brightness = 0;
int lightPattern = 1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}


// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);

  brightness = sensorValue / 4;
  //Serial.println(brightness);
  
  //Switch condition to change the pattern on button press.
  switch(lightPattern) {
    case 0:
      pattern1();
      break;
    case 1:
      pattern2();
      break;
    case 2: 
      pattern3();
      break;
    default:
      //analogWrite(3, brightness);
      //analogWrite(5, brightness);
      break;
  }
  delay(1);
}


//Function to check if the button was pressed
//If the button was pressed then the pattern of blinking will change to the next one
void checkButtonPress() {
  int buttonPressed = digitalRead(6);
  //Serial.println(buttonPressed);

  if (buttonPressed == 0) {
    didPress = true; 
  }

  if (didPress) {
    switch (lightPattern) {
      case 0:
        lightPattern = 1;
        break;
      case 1:
        lightPattern = 2;
        break;
      case 2:
        lightPattern = 0;
        break;
      default:
        break;
    }
    didPress = false;
  }
  Serial.println(lightPattern);
}


//Custom delay function to check for button press while waiting for a delay to timeout
//Source: http://forum.arduino.cc/index.php?topic=42317.0
void someDelay(unsigned long duration) {
  unsigned long start = millis();

  while (millis() - start <= duration) {
    checkButtonPress();
  }
}


//Blink Pattern 1
void pattern1() {
  analogWrite(3, brightness);
  someDelay(200);
  analogWrite(3, 0);
  analogWrite(5, brightness);
  someDelay(200);
  analogWrite(5, 0);
  someDelay(200);
  analogWrite(5, brightness);
  someDelay(200);
  analogWrite(5, 0);
  someDelay(200);
  analogWrite(3, brightness);
  analogWrite(5, brightness);
  someDelay(200);
  analogWrite(3, 0);
  analogWrite(5, 0);
  someDelay(1000);
}


//Blink Pattern 2
void pattern2() {
  analogWrite(3, brightness);
  analogWrite(5, brightness);
  someDelay(200);
  analogWrite(3, 0);
  analogWrite(5, 0);
  someDelay(200);
  analogWrite(3, brightness);
  someDelay(200);
  analogWrite(3, 0);
  someDelay(200);
  analogWrite(5, brightness);
  someDelay(200);
  analogWrite(5, 0);
  someDelay(200);
  analogWrite(3, brightness);
  analogWrite(5, brightness);
  someDelay(100);
  analogWrite(3, 0);
  analogWrite(5, 0);
  someDelay(500);
}


//Blink Pattern 3
void pattern3() {
  analogWrite(5, 0);
  analogWrite(3, brightness);
  someDelay(200);
  analogWrite(3, 0);
  analogWrite(5, brightness);
  someDelay(200);
}

