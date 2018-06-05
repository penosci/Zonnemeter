#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
String incoming;
String dataToSend;

void setup() {
 
  Serial.begin(9600);                 //Serial connection
  WiFi.begin("steven-K73SV", "Mu4W8Of2");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
  Serial.println("Connection made");
  
 
}

void loop() {
 
 while(Serial.available()) {

  incoming= Serial.readString();// read the incoming data as string

  Serial.println(incoming);
  dataToSend = incoming;

}
 if(dataToSend!=""){
  send_to_server(dataToSend);
  dataToSend="";
  
 }
  
 
}

void send_to_server(String data) {
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   
     HTTPClient http;    //Declare object of class HTTPClient
   
     http.begin("http://10.42.0.21:80/webserver/esp_update.php");      //Specify request destination
     http.addHeader("Content-Type", "application/x-www-form-urlencoded");
     //http.writeToStream(&Serial);
   
     int httpCode = http.POST(data);   //Send the request
     String payload = http.getString();                  //Get the response payload
     Serial.println(httpCode);   //Print HTTP return code
     Serial.println(payload);    //Print request response payload
   
     http.end();  //Close connection
   
   }else{
   
      Serial.println("Error in WiFi connection");   
   
  }
}


