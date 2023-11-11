//FAUCONNIER Damien 
//Date : 11/11/2023 11:44
//Sujet : Code horloge ir activer par le la valeur du courant 
//Pour : ER-Audiovisuel 
// test git



#include <TroykaCurrent.h>
#include <Wire.h> 
#include <RTClib.h>
#include <IRremote.h>

#define IR_LED_PIN 3; // Definir le broche de l'émetteur infrarouge


ACS712 sensorCurrent(A0);
RTC_DS3231 rtc; // Créer une isntance de la classe RTC_DS3231
IRsend irSender; // Créer une instance de la classe IRsend

unsigned long timerStart;
const unsigned long timerDuration = 21600000; // 6h en millisecondes (6 * 60 * 60 * 1000)
bool timerStarted = false; // Variable pour suivre si le minuteur a déjà été démarré

void setup() {
  Serial.begin(9600);

  // Initialiser le module RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Vérifier si le module RTC a perdu sa puissance
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // Vous pouvez ajouter du code ici pour définir l'heure si le module RTC a perdu sa puissance
  }
  // rtc.adjust(DateTime(2023, 11, 11, 11, 1, 0)); // Décommentez cette ligne si vous devez régler l'heure
  // Serial.println("Heure du DS3231 réglée avec succès !");
}

void loop() {
  // Obtenir l'heure actuelle du RTC
  DateTime now = rtc.now();
  
  // Lire la valeur du courant avec le capteur ACS712
  float current = sensorCurrent.readCurrentAC();

  // Vérifier si le courant dépasse 0.17 ampère et si le minuteur n'a pas encore démarré ( à changer par 1A pour l'utilisation réel)
  if (current > 0.17 && !timerStarted) {
    timerStart = millis(); // Démarrer le minuteur
    timerStarted = true; // Marquer le minuteur comme démarré
    Serial.println("Début du minuteur de 1 minute...");
  }

  // Vérifier si le minuteur est écoulé
  if (timerStarted && millis() - timerStart >= timerDuration) {
    // Envoyer les commandes infrarouges ici
    Serial.println("Minuteur expiré ! Envoyer les commandes infrarouges...");

    irSender.sendNEC(0xFFA25D, 32); // Exemple de commande NEC, 0xFFA25D est le code et 32 est la longueur en bits
    irSender.sendNEC(0xFFA25D, 32); // Exemple de commande NEC, 0xFFA25D est le code et 32 est la longueur en bits
    
    // Réinitialiser le minuteur après avoir exécuté les actions nécessaires
    timerStart = 0;
    timerStarted = false; // Réinitialiser la variable indiquant que le minuteur a démarré
  }

  // Afficher l'heure et le courant dans la console 
  Serial.print("Il est ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(" et le courant est de ");
  Serial.print(current, 3); // Afficher la valeur du courant avec trois chiffres après la virgule
  Serial.println(" A");

  delay(1000);
}
