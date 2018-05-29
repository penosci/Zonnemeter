import cc.arduino.*; //import de arduino firmata driver

import processing.serial.*; //import de serial library

Arduino arduino;  //declareer de Arduino integer als arduino

int valuemeter = 0;
int t = 0;
void setup()
{
  arduino = new Arduino(this, "com6", 57600); //zet de arduino poort op en geeft aan hoeveel baud
  arduino.pinMode(0, Arduino.INPUT); //geeft de pinMode van de arduino aan
  
}
String curentDate() {
  String time = year()+ "-" + month() + "-" + day() + "--" + hour() + "-" + minute() + "-" + second() ;
  return time;
}

void draw(){
  PrintWriter output;
  String filename = curentDate() + ".txt";
  output = createWriter(filename);
  while(t<59) {
    output.println(curentDate() + ":" + arduino.analogRead(0));
    delay(1000);
   ++t;
  }
  output.flush(); // Write the remaining data
  output.close(); // Finish the file
  t=0;
}