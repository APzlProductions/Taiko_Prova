#include <FastLED.h>                         //include the FastLED library to make the WS2811 - WS2812... work.
#include <Keyboard.h>                        //include the Keyboard library to use the piezos like a button on a keyboard.
#define TIPO_LED WS2812B                     //say the type of led strip.
#define COLORI GRB                           //say the type of colors order (you can change it if you want).
#define NUM_LEDS  135                        //say the number of leds on your strip (if you have a WS2811, 1 led = 3 leds on a WS2812).
#define DATA_PIN  3                          //say the data pin where you want to wire the strip DATA IN pin. 
#define PiezoRedLeft  0                      //analogic pin where the piezo is wired to.
#define PiezoBlueLeft  1                     //analogic pin where the piezo is wired to.
#define PiezoRedRight  2                     //analogic pin where the piezo is wired to.
#define PiezoBlueRight  3                    //analogic pin where the piezo is wired to.
#define TresholdRed 400                      //is the piezo value to go beyond to say that you have triggered the piezo and cancelling noise.xxx
#define TresholdBlue 200
#define Brightness 200

uint8_t gHue = 0;
bool choose = 0;
CRGB leds[NUM_LEDS];                         //this create the variable 'leds' and it's value it's the same of the number of leds on your strip.



void setup() {
  delay(2000);                                                                    //delay for the safety of the arduino.
  FastLED.addLeds<TIPO_LED, DATA_PIN, COLORI>(leds, NUM_LEDS);                    //this adds the type of led that you're working on, the data pin, the order of colors and the number of leds on your strip.
  Serial.begin(9600);
  FastLED.setBrightness(Brightness);
  Keyboard.begin();                                                               //this activate the function of keyboard.
}




void loop() {
  if(choose < 1){                                                                   //this make the strip go brrr at the beginnig.
    rainbow();
  }
  redLeft(analogRead(PiezoRedLeft));                                               //read the piezo's output                                                           
  blueLeft(analogRead(PiezoBlueLeft));                                                                                               
  redRight(analogRead(PiezoRedRight));                                                                                                                    
  blueRight(analogRead(PiezoBlueRight));                                          
  gHue++;
  
}



void rainbow(){                                                                      //the brrr void
  fill_rainbow(leds, NUM_LEDS, gHue, 2);                                             //the brrr command
  FastLED.show();                                                                    //show it
}




void redLeft(int Val) {                                                              //left red part of the taiko
  if(Val >= TresholdRed){                                                            //this is the part where it know when you hit it
    Serial.print("Red left:     ");
    Serial.println(Val);                                        
    Keyboard.press('x');                                                              //click any key of the keyboard (in my case "x")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('x');                                                            //now release the key
    red_anim();                                                                       //let's see the animation on the led strip
    choose++;                                                                         //make it know that you are using it, so it will stop going brrr
  }
}



void redRight(int Val) {                                                              //right red part of the taiko
  if(Val >= TresholdRed){                                                             //this is the part where it know when you hit it
    Serial.print("Red right:     ");
    Serial.println(Val);                                 
    Keyboard.press('c');                                                              //click any key of the keyboard (in my case "c")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('c');                                                            //now release the key
    red_anim();                                                                       //let's see the animation on the led strip
    choose++;                                                                         //make it know that you are using it, so it will stop going brrr
  }
}




void red_anim() {                                                                     //void for the red animation
  for(int i=0; i<=NUM_LEDS; i++){                                                     //turn on from the first to the last led of the strip in a pinkish color
    leds[i] = CRGB(244,23,84);                                                        
    FastLED.show();
  }
  for(int i=NUM_LEDS-1; i>=0; i--){                                                   //now turn off from the last to the first led of the strip 
    leds[i] = CRGB(0,0,0);
    FastLED.show();
  }
}








void blueLeft(int Val) {                                                             //left blue part of the taiko
  if(Val >= TresholdBlue){                                                           //this is the part where it know when you hit it
    Serial.print("Blue left:     ");
    Serial.println(Val);                                 
    Keyboard.press('z');                                                              //click any key of the keyboard (in my case "z")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('z');                                                            //now release the key
    blue_anim();                                                                      //let's see the animation on the led strip
    choose++;                                                                         //make it know that you are using it, so it will stop going brrr
  }
}



void blueRight(int Val) {                                                             //blue part of the taiko
  if(Val >= TresholdBlue){                                                            //this is the part where it know when you hit it
    Serial.print("Blue right:     ");
    Serial.println(Val);                                    
    Keyboard.press('v');                                                              //click any key of the keyboard (in my case "v")
    delay(12);                                                                        //delay to make the pc know that it clicked, altrough arduino will be too fast
    Keyboard.release('v');                                                            //now release the key
    blue_anim();                                                                      //let's see the animation on the led strip
    choose++;                                                                         //make it know that you are using it, so it will stop going brrr
  }
}





void blue_anim() {                                                                     //void for the red animation
  for(int i=0; i<=NUM_LEDS; i++){                                                      //turn on from the first to the last led of the strip in a light blue color
    leds[i] = CRGB(66,66,255);
    FastLED.show();
  }
  for(int i=NUM_LEDS-1; i>=0; i--){                                                    //now turn off from the last to the first led of the strip
    leds[i] = CRGB(0,0,0);
    FastLED.show();
  }
}
