//the below 3 lines of code are to be copied from the blynk web platform for your device
#define BLYNK_TEMPLATE_ID "Your Template ID"  
#define BLYNK_TEMPLATE_NAME "Your template name"
#define BLYNK_AUTH_TOKEN "Your Auth Token"

#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <WiFi.h>

BlynkTimer timer;

//type in your wifi name and password
char ssid[] = "Wi-Fi name";
char pass[] = "Wi-Fi password";

Servo SolarServo;

//pin setup
int Left_LDR = 35;
int Right_LDR = 34;
int ServoPin = 23;
int Current = 32;
int Voltage = 33;

//variables
int position = 90;
int buffer = 50; //to minimise jitterring and unnecessary movement of servo for small values of difference

float voltageFactor = 5.0;  //for voltage sensor, as the ratio is 5:1
float sensitivity = 0.185;
float zeroCurrentVoltage = 0.0; //To calculate current sensor's reading at zero current flowing

float vout,cout;
float voltage,current,power;

void measure(){
  vout = analogRead(Voltage);
  cout = analogRead(Current);

  vout = (vout * 3.3) / 4095.0;
  voltage = vout * voltageFactor;//converting the analog voltage value to proper voltage

  cout = (cout * 3.3) / 4095.0; //converting the analog current value to a proper current
  current = (cout - zeroCurrentVoltage) / sensitivity; 

  power = voltage * current;

  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, power);

}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L,measure);

  SolarServo.attach(ServoPin);
  SolarServo.write(position);
  delay(1000);

  long sum = 0;
  for (int i = 0; i < 200; i++) {
    sum += analogRead(Current);
    delay(2);
  }
  float raw = sum / 200.0;  //averaging readings
  zeroCurrentVoltage = (raw * 3.3) / 4095.0;  //calculate the zero point
}


void loop() {
  Blynk.run();
  timer.run();

  int LDRL = analogRead(Left_LDR);
  int LDRR = analogRead(Right_LDR);
  int difference = LDRL - LDRR;

  Serial.print("voltage =");
  Serial.print(voltage);
  Serial.print(" current =");
  Serial.print(current);
  Serial.print(" Left=");
  Serial.print(LDRL);
  Serial.print(" Right=");
  Serial.print(LDRR);
  Serial.print(" difference=");
  Serial.print(difference);
  Serial.print(" position=");
  Serial.println(position);

  if (difference > buffer) {
    position-=1;
  }
  else if (difference < -buffer) {
    position+=1;
  }

  if (position > 180) position = 180;
  if (position < 0) position = 0;

  SolarServo.write(position);
  delay(50);
}
