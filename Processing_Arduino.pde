import processing.serial.*;
import processing.sound.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port

SoundFile file1;
SoundFile file2;
SoundFile file3;
SoundFile file4;
SoundFile file5;
SoundFile file6;
SoundFile file7;
SoundFile file8;

void setup()
{
  size(640, 360);
  background(255);
  file1 = new SoundFile(this, "C3.mp3");
  file2 = new SoundFile(this, "D3.mp3");
  file3 = new SoundFile(this, "E3.mp3");
  file4 = new SoundFile(this, "F3.mp3");
  file5 = new SoundFile(this, "G3.mp3");
  file6 = new SoundFile(this, "A3.mp3");
  file7 = new SoundFile(this, "B3.mp3");
  file8 = new SoundFile(this, "C4.mp3");
  
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  for(int i=0; i<Serial.list().length; i++){
   println(i + "; " + Serial.list()[i]); 
  }
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  
  
}


void draw()
{
  if ( myPort.available() > 0) 
    {  // If data is available,
      val = myPort.readStringUntil('\n');         // read it and store it in val
    } 
    if(val != null){
      println("[" + val.trim() + "]");
      if(val.trim().equals("play1")){
        if(file1.isPlaying() == false){
          file1.play();
        }
      }
      if(val.trim().equals("play2")){
        if(file2.isPlaying() == false){
          file2.play();
        }
      }
      if(val.trim().equals("play3")){
        if(file3.isPlaying() == false){
          file3.play();
        }
      }
      if(val.trim().equals("play4")){
        if(file4.isPlaying() == false){
          file4.play();
        }
      }
      if(val.trim().equals("play5")){
        if(file5.isPlaying() == false){
          file5.play();
        }
      }
      if(val.trim().equals("play6")){
        if(file6.isPlaying() == false){
          file6.play();
        }
      }
      if(val.trim().equals("play7")){
        if(file7.isPlaying() == false){
          file7.play();
        }
      }
      if(val.trim().equals("7")){
        if(file8.isPlaying() == false){
          file8.play();
        }
      }
      val = null;
      
    }
}
