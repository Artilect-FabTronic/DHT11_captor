#include <LiquidCrystal.h>
#include <dht.h>                                  // pour le capteur de temperatures

#define dataPin A0                                // analogic
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);		  // brochage LCD  (rs, enable, d4, d5, d6, d7) plus les 5volts masses 
dht DHT;                                          // et le potar sur VO pour regler le retro eclairage

void setup() {
  lcd.begin(16, 2);                               // demarrer l'ecran LCD
  lcd.setCursor(0, 0);                            // Se placer au premier caractere a gauche en haut
  lcd.print("Attendre svp ");
  lcd.setCursor(0, 1);
  lcd.print("0.75 sec ... ");
  delay(750);                                     // juste pour être sur que le capteur a deja commence a remonter des temperatues et humiditées
}

void loop() {
  int readData = DHT.read11(dataPin);             // relire le capteur à chaque itération (capteur DHT11 +ou- 2°C et +ou- 5% de précision )
  // int readData = DHT.read22(dataPin);          // relire le capteur à chaque itération (capteur DHT22 +ou- 0.5°C et +ou- 2% de précision )
  float t = DHT.temperature;
  float h = DHT.humidity;
  lcd.setCursor(0, 0);
  lcd.print("Temp.: ");
  lcd.print(t);                                   // afficher la temperature sur la premiere ligne
  lcd.print(" °C");                              // en °C bien sur
  lcd.setCursor(0, 1);                            // seconde ligne
  lcd.print("Humi.: ");
  lcd.print(h);
  lcd.print(" %");                                // l humidité en pourcentage
  delay(1000);                                    // 1seconde de temps de rafraichissement
}
