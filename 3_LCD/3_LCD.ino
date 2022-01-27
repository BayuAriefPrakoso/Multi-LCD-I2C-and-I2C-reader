#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);
LiquidCrystal_I2C lcd3(0x25, 16, 2);

void setup(){
  Serial.begin(9600);
  
	lcd1.begin();
  lcd2.begin();
  lcd3.begin();

	lcd1.backlight();
  lcd2.backlight();
  lcd3.backlight();

	lcd1.print("LCD 1");
  lcd2.print("LCD 2");
  lcd3.print("LCD 3");
}

void loop(){
  if(Serial.available()){
    char x = Serial.read();
    String a = Serial.readString();
//    Serial.print(x);
//    Serial.println(a);

    if(x == '1'){
      lcd1.setCursor(0,1);
      lcd1.print(a);
      lcd1.print("    ");
    }
    else if(x == '2'){
      lcd2.setCursor(0,1);
      lcd2.print(a);
      lcd2.print("    ");
    }
    else if(x == '3'){
      lcd3.setCursor(0,1);
      lcd3.print(a);
      lcd3.print("    ");
    }
  }
}
