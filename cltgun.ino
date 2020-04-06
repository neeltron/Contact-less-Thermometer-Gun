#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <VirtualWire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  mlx.begin();
  lcd.begin(16, 2);
}
void loop() {
  Serial.println(mlx.readAmbientTempF());
  Serial.println(mlx.readObjectTempF()+7);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String(mlx.readObjectTempF()+7)+"F");
  lcd.setCursor(0, 1);
  lcd.print(String(((mlx.readObjectTempF()+7)-32)*5/9)+"C");
  delay(1000);
}
