#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
 #include <SPI.h>
TMRpcm tmrpcm;   // create an object for use in this sketch
 int SW1; 
 int SW2;
 int SW3;
 int SW4;
 char fileName[11];    //an array to hold the filename
int fileToPlay ;
void setup(){
 pinMode(14,INPUT);  //Define A0 as digital input.
 
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  return;   // don't do anything more if not
  }
 tmrpcm.setVolume(5);
 tmrpcm.play("1.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
}
 
void loop(){  
 SW1=digitalRead(14); 
  
     if (SW1 == LOW) { //if SW1 pressed then play file "6.wav"
      fileToPlay = random(1,10); //a random number
    sprintf(fileName, "%d.wav", fileToPlay);  //turn the number into a string and add extension
    Serial.println( fileName);
      tmrpcm.play(fileName);
    }
  
}
