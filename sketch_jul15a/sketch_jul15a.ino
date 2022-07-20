float resistor_cons = 5.67;
float arduino_cons = 0.0048875855327468;
#include <SoftwareSerial.h> 

SoftwareSerial Serial2(2,3);
  
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial2.begin(9600);
 pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str;
  int pinData = analogRead(A0);
  float R_volt =(pinData* arduino_cons);
  float base = (R_volt*resistor_cons);
  str=String(base);
  
  Serial2.print("t0.txt=\""+str+"\"");
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  delay(500);

}
