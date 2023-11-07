#include <Servo.h>

Servo myServo1;
Servo myServo2;

const int rampTime = 5000;

const int phase1 = rampTime;
boolean p1 = false; // nothing, both on on top
const int phase2 = rampTime;
boolean p2 = false; // eurydice falls
const int phase3 = rampTime;
boolean p3 = false; // orpheus goes after
const int phase4 = rampTime;
boolean p4 = false; // wait at bottom, bargain with hades
const int phase5 = rampTime+300;
boolean p5 = false; // both go up
const int phase6 = rampTime;
boolean p6 = false;// euridyce falls again
const int reset = rampTime+300;
boolean pr = false;// reset
const int rwait = 3000;

const int stop = 91;
const int forward = 45; //45;
const int backward = 135; //135;

boolean correct = false;

long currentMillis = 0;
long startMillis = 0;

int bPinCheck[] = {0,0,0,0,0,0,0};
const uint8_t buttonPins[] = { 12, 11, 10, 9, 7, 6};
const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup() {
  myServo1.attach(5);
  myServo1.write(stop);
  myServo2.attach(4);
  myServo2.write(stop);
  pinMode(LED_BUILTIN, OUTPUT);
  for (uint8_t i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {

  currentMillis = millis();
  setPhases();
  //myServo2.write(backward);
  setServos();
  if(p4 == true){
    bargain();
  }
  
  
  buttonChanges();

}

void buttonChanges()
{
  for (uint8_t i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == HIGH /*&& digitalRead(buttonPins[i]) != bPinCheck[i]*/) {
      bPinCheck[i] = digitalRead(buttonPins[i]);
      Serial.println("AAAAA");
      switch(i){
        case 0:
          Serial.println("play1");
          break;
        case 1:
          Serial.println("play2");
          break;
        case 2:
          Serial.println("play3");
          break;
        case 3:
          Serial.println("play4");
          break;
        case 4:
          Serial.println("play5");
          break;
        case 5:
          Serial.println("play6");
          break;
        case 6:
          Serial.println("play7");
          break;
      }
      
      Serial.println("hmmm");
    }
  }
}

void setPhases()
{
  if(p1 == false && p2 == false && p3 == false && p4 == false && p5 == false && p6 == false && pr == false){
    myServo1.write(stop);
    myServo2.write(stop);
    for (uint8_t i = 0; i < numTones; i++) {
      if (digitalRead(buttonPins[i]) == HIGH) {
        p1 = true;
      }
    }
    
  } else if(p1 == true && p2 == false && p3 == false && p4 == false && p5 == false && p6 == false && pr == false){
    if(currentMillis-startMillis >= phase1){
      startMillis = millis();
      p1 = false;
      p2 = true;

    }
  } else if(p1 == false && p2 == true && p3 == false && p4 == false && p5 == false && p6 == false && pr == false){
    if(currentMillis-startMillis >= phase2){
      startMillis = millis();
      p2 = false;
      p3 = true;
    }
  } else if(p1 == false && p2 == false && p3 == true && p4 == false && p5 == false && p6 == false && pr == false){
    if(currentMillis-startMillis >= phase3){
      startMillis = millis();
      p3 = false;
      p4 = true;
    }
  } else if(p1 == false && p2 == false && p3 == false && p4 == true && p5 == false && p6 == false && pr == false){
    if(correct == true){
      startMillis = millis();
      p4 = false;
      p5 = true;
      correct = false;
    }
  } else if(p1 == false && p2 == false && p3 == false && p4 == false && p5 == true && p6 == false && pr == false){
    if(currentMillis-startMillis >= phase5){
      startMillis = millis();
      p5 = false;
      p6 = true;
    }
  } else if(p1 == false && p2 == false && p3 == false && p4 == false && p5 == false && p6 == true && pr == false){
    if(currentMillis-startMillis >= phase6){
      myServo1.write(stop);
      myServo2.write(stop);
      delay(3000);
      startMillis = millis();
      p6 = false;
      pr = true;
    }
  } else if(p1 == false && p2 == false && p3 == false && p4 == false && p5 == false && p6 == false && pr == true){
    if(currentMillis-startMillis >= reset){
      startMillis = millis();
      pr = false;
    }
  }
}

void setServos()
{
  if(p1){
    myServo1.write(stop);
    myServo2.write(stop);
  }
  if(p2){
    myServo2.write(forward);
  }
  if(p3){
    myServo1.write(forward);    
    myServo2.write(stop);
  }
  if(p4){
    myServo1.write(stop);    
    myServo2.write(stop);
  }
  if(p5){
    myServo1.write(backward);    
    myServo2.write(backward);
  }
  if(p6){
    myServo1.write(stop);    
    myServo2.write(forward);
  }
  if(pr){
    myServo2.write(backward);
    myServo1.write(stop);
  }
}

int buttonChange1()
{
  for (uint8_t i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == HIGH /*&& digitalRead(buttonPins[i]) != bPinCheck[i]*/) {
      bPinCheck[i] = digitalRead(buttonPins[i]);
      Serial.println("AAAAA");
      switch(i){
        case 0:
          Serial.println("play1");
          return 1;
        case 1:
          Serial.println("play2");
          return 2;
        case 2:
          Serial.println("play3");
          return 3;
        case 3:
          Serial.println("play4");
          return 4;
        case 4:
          Serial.println("play5");
          return 5;
        case 5:
          Serial.println("play6");
          return 6;
        case 6:
          Serial.println("play7");
          return 7;
      }
      
      Serial.println("hmmm");
    }
  }
}


void bargain()
{
  int h = millis();
  Serial.println("play1");
  delay(800);
  Serial.println("play3");
  delay(800);
  Serial.println("play2");
  delay(800);
  Serial.println("play5");

  int waitForResponse = 0;
  while(waitForResponse == 0){
    int y = millis();
    int button = buttonChange1();
    
    if (button == 1 || y-h>20000){
      waitForResponse = 1;
    }
  }
  waitForResponse = 0;
  while(waitForResponse == 0){
    int y = millis();
    int button = buttonChange1();
    if (button == 3){
      waitForResponse = 1;
    }
  }
  waitForResponse = 0;
  while(waitForResponse == 0){
    int y = millis();
    int button = buttonChange1();
    if (button == 2){
      waitForResponse = 1;
    }
  }
  waitForResponse = 0;
  while(waitForResponse == 0){
    int y = millis();
    int button = buttonChange1();
    if (button == 5){
      waitForResponse = 1;
    }
  }
  correct = true;
}
