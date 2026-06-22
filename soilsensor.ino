#include <LiquidCrystal.h>
const int rs=7,en=6,d4=5, d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
String warning =" Needed to water!"; 
String sign="Enough water";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

int sensorVal = analogRead(A0);
  
   int  percentValue=map(sensorVal, 0, 1230, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  
  lcd.setCursor(0, 1);  
  lcd.print("Percent:");
  lcd.print(percentValue);
  lcd.print("%");
  if (percentValue<=9){
    lcd.print("Air");
    
  }
  if (percentValue<=39 && percentValue>=10){
lcd.print("Dry");
delay(3000);
lcd.clear();
lcd.print(warning);

delay(300);
 }

if(percentValue>39 && percentValue <53){
lcd.print("Humid");
}
if(percentValue>=53)
  {
    lcd.print("Wet");
delay(3000);
lcd.clear();
lcd.setCursor(2,0);

lcd.print(sign);
delay(320);
}    
  delay(1000);
  lcd.clear();
   
}
