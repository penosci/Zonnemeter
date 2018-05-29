
String output;
void setup() {
  Serial.begin(2400);
  randomSeed(analogRead(0));
}

void loop() {
  String var1 = String(random(2000));
  String var2 = String(random(1999));
  output = String(var2+';'+var2);
  Serial.println(output);
  delay(1000);
}
