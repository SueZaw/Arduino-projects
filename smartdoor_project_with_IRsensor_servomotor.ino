//Smart Door with Infrared Sensor and Servo motor 
//Written by Sue Zaw

#include <Servo.h>

Servo myservo; //declaring myservo

int sensor_pin = 8;//add your sensor output pin number , မိမိတပ်ဆင်ထားသော sensor output pin number ထည့်ပါ
int servo_pin =9;//add your servo output pin number , မိမိတပ်ဆင်ထားသော servo output pin number ထည့်ပါ
int val;

void setup(){
  pinMode(sensor_pin,INPUT); //declaring that we will use Input from sensor_pin,sensor_pin မှ Input ယူမည့် အကြောင်း
  myservo.attach(servo_pin);
   Serial.begin(9600);
}

void loop(){
   myservo.write(30); 
  val = digitalRead(sensor_pin);
  Serial.println(val);//printing out value in serial monitor,value များကို  serial monitor တွင် ဖတ်ရှုနိုင်ရန်
  if (val==0) //sennsor_pin value သည် 0 , ဆိုလိုသည်မှာ object detected
  {
    myservo.write(120); 
    delay(3600);
    myservo.write(30);
  }
  /*if (val==1)
  {
    tap_servo.write(180);
    
  }*/
}