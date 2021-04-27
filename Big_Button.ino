


// constants won't change. They're used here to set pin numbers:
const int buttonPin2 = 2; //big button
const int buttonPin3 = 3; //blue button
const int buttonPin4 = 4; //green button
const int buttonPin5 = 5; //yellow button
const int buttonPin6 = 6; //red button
const int buttonPin7 = 7; //switch up
const int buttonPin8 = 8; //switch down
// variables will change:


int buttonOptions = 0;


int oldbuttonstate = 0;// variable for reading the pushbutton status

#include "Keyboard.h"
void setup() {

  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  //Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // read the state of the pushbutton value:
  //buttonState2 = digitalRead(buttonPin2);
  //buttonState3 = digitalRead(buttonPin3);
  //  Serial.println(buttonState3);
  // buttonState4 = digitalRead(buttonPin4);
  // Serial.println(buttonState4);


  if (digitalRead(buttonPin3) == LOW) {
    buttonOptions = 0;
  } else if (digitalRead(buttonPin4) == LOW) {
    buttonOptions = 1;
  } else if (digitalRead(buttonPin5) == LOW) {
    buttonOptions = 2;
  } else if (digitalRead(buttonPin6) == LOW) {
    buttonOptions = 3;
  }


  delay(150);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonOptions == 0) {//button 3
    if (digitalRead(buttonPin2) == HIGH && oldbuttonstate == 1) {
      // turn LED on:

      oldbuttonstate = 0;

    } else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin7) == LOW) {
      // turn LED off:
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(5);
      Keyboard.press(KEY_F2);
      Keyboard.releaseAll();
      delay(50);
      oldbuttonstate = 1;

    }
    else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin8) == LOW) {
      delay(50);
      oldbuttonstate = 1;
      Keyboard.press(KEY_F11);
      Keyboard.releaseAll();
    }
  } else if (buttonOptions == 1) {//button4

    if (digitalRead(buttonPin2) == HIGH && oldbuttonstate == 1) {
      // turn LED on:

      oldbuttonstate = 0;

    } else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin7) == LOW) {
      // turn LED off:
      Keyboard.print("You pressed the button  and changed");
      //Serial.println("button 2 pushed");
      //Serial.println(buttonState3);
      delay(50);
      oldbuttonstate = 1;

    }
    else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin8) == LOW) {
      delay(50);
      oldbuttonstate = 1;

    }} else if (buttonOptions == 2) {//button 5

    if (digitalRead(buttonPin2) == HIGH && oldbuttonstate == 1) {
      // turn LED on:

      oldbuttonstate = 0;

    } else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin7) == LOW) {
      // turn LED off:
      Keyboard.print("Done for the day");
      //Serial.println("button 2 pushed");
      //Serial.println(buttonState3);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(50);
      oldbuttonstate = 1;

    }
    else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin8) == LOW) {
      delay(50);
      oldbuttonstate = 1;
    }} else if (buttonOptions == 3) {//button 6

    if (digitalRead(buttonPin2) == HIGH && oldbuttonstate == 1) {
      // turn LED on:

      oldbuttonstate = 0;

    } else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin7) == LOW) {
      // turn LED off:

      delay(50);
      oldbuttonstate = 1;

    }
    else if (digitalRead(buttonPin2) == LOW && oldbuttonstate == 0 && digitalRead(buttonPin8) == LOW) {
      delay(50);
      oldbuttonstate = 1;
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
    }



  }
    
}
