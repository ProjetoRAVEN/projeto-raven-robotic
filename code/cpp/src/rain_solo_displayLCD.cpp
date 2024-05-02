#define sensor A0                     
#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void screenHelloWorld();
void screenClearBlank();
void turn_off_LED();

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  Serial.println("Inicializando Setup...");
  
  lcd.begin(16, 2);
  lcd.clear();
  delay(1000);
  lcd.setCursor(8, 1);
  lcd.print("SETUP...");
  delay(2000);
  lcd.clear();

  Serial.println("Sensor de Umidade + Display Online");

  Serial.println("Projeto");
  lcd.setCursor(0, 0);
  lcd.print("Projeto");
  delay(1000);
  Serial.println("Display LCD");
  lcd.setCursor(4, 1);
  lcd.print("Display LCD");
  delay(2000);
  lcd.clear();

  Serial.println("Loading... ");
  
  for (int i = 0; i <= 15; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Loading...");
    lcd.setCursor(i, 1);
    lcd.print("*");
    delay(200);
    lcd.clear();
  }
    
  Serial.println("## SETUP COMPLETADO ##");
}

void screenHelloWorld() {
  Serial.println("chamar screenHelloWorld()");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HELLO");
  delay(1000);
  lcd.setCursor(8, 1);
  lcd.print("WORLD...");
  delay(1000);
}

void screenClearBlank() {
  Serial.println("called screenClearBlank()");
  lcd.clear();
  delay(1000);
}

void loop() {
  screenHelloWorld();
  screenClearBlank();
  
  int signal = analogRead(sensor);
  Serial.print("Sinal: ");
  Serial.print(signal);
  
  if (signal >= 0 && signal < 350) {
    Serial.println("Status: Sinal de Umidade do Solo: (-)");
    turn_off_LED();
    // digitalWrite(LED_RD, HIGH); // Defina os pinos dos LEDs
  }
  
  if (signal >= 350 && signal < 750) {
    Serial.println("Status: Sinal de Umidade: (+)");
    turn_off_LED();
    // digitalWrite(LED_YL, HIGH); // Defina os pinos dos LEDs
  }
  
  if (signal >= 750 && signal < 1023) {
    Serial.println("Status: Sinal de Umidade do Solo: (+)");
    turn_off_LED();
    // digitalWrite(LED_GR, HIGH); // Defina os pinos dos LEDs
  }
  
  delay(1000);
}

void turn_off_LED() {
  // digitalWrite(LED_VM, LOW); // Defina os pinos dos LEDs
  // digitalWrite(LED_YL, LOW); // Defina os pinos dos LEDs
  // digitalWrite(LED_GR, LOW); // Defina os pinos dos LEDs
}
