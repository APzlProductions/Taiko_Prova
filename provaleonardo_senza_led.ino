#include <Keyboard.h>                        //include the Keyboard library to use the piezos like a button on a keyboard.
#define PiezoRedLeft  0                      //analogic pin where the piezo is wired to.
#define PiezoBlueLeft  1                     //analogic pin where the piezo is wired to.
#define PiezoRedRight  2                     //analogic pin where the piezo is wired to.
#define PiezoBlueRight  3                    //analogic pin where the piezo is wired to.
#define Treshold 400                         //is the piezo value to go beyond to say that you have triggered the piezo and cancelling noise.
int PiezoSensorValueRedLeft;                     //this variable is for later, it's used to have the piezo's value.
int PiezoSensorValueBlueLeft;                    //this variable is for later, it's used to have the piezo's value.
int PiezoSensorValueRedRight;                    //this variable is for later, it's used to have the piezo's value.
int PiezoSensorValueBlueRight;                   //this variable is for later, it's used to have the piezo's value.




void setup() {
  delay(2000);                                                                    //delay for the safety of the arduino.
  Serial.begin(9600);
  Keyboard.begin();                                                               //this activate the function of keyboard.
}




void loop() {

  PiezoSensorValueRedLeft = analogRead(PiezoRedLeft);                               //read the piezo's output
  redLeft();                                                                        //read the redLeft void
  PiezoSensorValueBlueLeft = analogRead(PiezoBlueLeft);                             //read the piezo's output
  blueLeft();                                                                       //read the blueLeft void
  PiezoSensorValueRedRight = analogRead(PiezoRedRight);                             //read the piezo's output
  redRight();                                                                       //read the red void
  PiezoSensorValueBlueRight = analogRead(PiezoBlueRight);                           //read the piezo's output
  blueRight();                                                                      //read the blueRight void
  
}






void redLeft() {                                                                      //left red part of the taiko
  if(PiezoSensorValueRedLeft >= Treshold){                                            //this is the part where it know when you hit it
    Serial.print("Red left:     ");
    Serial.println(PiezoSensorValueRedLeft);                                          //print in the serial
    Keyboard.press('x');                                                              //click any key of the keyboard (in my case "x")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('x');                                                            //now release the key
    delay(5);
  }
}



void redRight() {                                                                     //right red part of the taiko
  if(PiezoSensorValueRedRight >= Treshold){                                           //this is the part where it know when you hit it
    Serial.print("Red right:     ");
    Serial.println(PiezoSensorValueRedRight);                                         //print in the serial
    Keyboard.press('c');                                                              //click any key of the keyboard (in my case "c")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('c');                                                            //now release the key
    delay(5);
  }
}







void blueLeft() {                                                                     //left blue part of the taiko
  if(PiezoSensorValueBlueLeft >= Treshold){                                           //this is the part where it know when you hit it
    Serial.print("Blue left:     ");
    Serial.println(PiezoSensorValueBlueLeft);                                         //print in the serial
    Keyboard.press('z');                                                              //click any key of the keyboard (in my case "z")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('z');                                                            //now release the key
    delay(5);
  }
}



void blueRight() {                                                                    //blue part of the taiko
  if(PiezoSensorValueBlueRight >= Treshold){                                          //this is the part where it know when you hit it
    Serial.print("Blue right:     ");
    Serial.println(PiezoSensorValueBlueRight);                                        //print in the serial
    Keyboard.press('v');                                                              //click any key of the keyboard (in my case "v")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('v');                                                            //now release the key
    delay(5);
  }
}
