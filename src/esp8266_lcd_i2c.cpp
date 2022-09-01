#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
String frase =" ";
boolean frasecompleta = false;

void setup()
{
  Serial.begin(9600);
  frase.reserve(200);
  pinMode(LED_BUILTIN, OUTPUT);
  // Iniciar LCD
  //lcd.begin(20, 4);
  lcd.init();
  lcd.backlight(); // Agregar brillo
  // Limpiar
  lcd.clear();
  // Imprimir
  lcd.setCursor(0, 0);
  lcd.print("hola maxy ");
  lcd.setCursor(0, 1); // Segunda fila

}

void loop(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  if (frasecompleta){
  lcd.println (frase);
  frasecompleta = false;
  frase = " ";
}
}


void serialevent() {
while (Serial.available()){
  char caracter =(char) Serial.read();
  frase+=caracter;
  if(caracter=='\n') frasecompleta = true;
}
}
