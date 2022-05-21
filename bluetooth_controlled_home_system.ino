#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define led1 7
#define led2 8
#define transistorlight 5
#define transistorfan 12
int state;
char incoming_data;
void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (transistorlight, OUTPUT);
  pinMode (transistorfan, OUTPUT);
  digitalWrite(transistorlight, LOW);
  digitalWrite(transistorfan, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fan Off");
  lcd.setCursor(0, 1);
  lcd.print("Light Off");
  delay(200);

}

void loop() {

  if (Serial.available() > 0) {
    incoming_data = Serial.read();
    Serial.print(incoming_data);
    if (incoming_data == 'A') {
      digitalWrite(led1, HIGH);
      digitalWrite(transistorlight, HIGH);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Light On");
      delay(200);
    }
    else if (incoming_data == 'B') {
      digitalWrite(led1, LOW);
      digitalWrite(transistorlight, LOW);
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Light Off");
      delay(200);
    }
    else if (incoming_data == 'C') {
      digitalWrite(led2, HIGH);
      digitalWrite(transistorfan, HIGH);
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Fan On");
      delay(200);
    }
    else if (incoming_data == 'D') {
      digitalWrite(led2, LOW);
      digitalWrite(transistorfan, LOW);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Fan Off");
      delay(200);
    }
    else {
      digitalWrite(led2, LOW);
      digitalWrite(transistorfan, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(transistorlight, LOW);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fan Off");
      lcd.setCursor(0, 1);
      lcd.print("Light Off");
      delay(200);
    }
  }


}
