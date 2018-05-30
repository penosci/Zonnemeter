import processing.serial.*; //import de serial library
Serial myPort;    // The serial port
String inString;  // Input string from serial port
int lf = 10;      // ASCII linefeed 
int valuemeter = 0;
int t = 0;
PrintWriter output;
int fileOpen=0;

void setup()
{
  size(400,200); 
  printArray(Serial.list()); 
 
  myPort = new Serial(this, Serial.list()[32], 2400); 
  myPort.bufferUntil(lf); 
  
}
String curentDate() {
  String time = year() + month() + day() + ";" + hour() +  minute() + second() ;
  return time;
}

void draw(){
  background(0); 
  //text("received: " + inString, 10,50);
  

 
}
void serialEvent(Serial p) { 
  inString = p.readString(); 
  if (fileOpen==0){
    String filename = year()+ "-" + month() + "-" + day() + "--" + hour() + "-" + minute() + ".csv";
    output = createWriter(filename);
    fileOpen = 1;
  }
  if (inString!=null){
    output.print(curentDate() + ";" + inString);
    output.flush(); // Write the remaining data
    t++;
  }
  if (t==360){ 
    output.close(); // Finish the file
    fileOpen = 0;
  }
  
} 
