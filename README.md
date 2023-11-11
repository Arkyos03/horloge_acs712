# Projet Arduino avec Capteur de Courant, Horloge RTC et Émetteur Infrarouge

Ce projet Arduino utilise un capteur de courant ACS712, une horloge temps réel (RTC DS3231), et un émetteur infrarouge pour effectuer des actions en fonction du courant détecté.

## Description

Le code Arduino inclus dans ce projet surveille en continu le courant capté par le capteur ACS712. Lorsque le courant dépasse un certain seuil (0.17 ampère dans cet exemple), un minuteur de 1 minute est déclenché. À l'expiration du minuteur, des commandes infrarouges sont envoyées via l'émetteur infrarouge.

## Matériel Requis

- Capteur de courant ACS712
- Module RTC DS3231
- Émetteur infrarouge (et LED infrarouge)
- Arduino (avec ports analogiques et numériques)

## Câblage

Assurez-vous de câbler les composants selon le schéma de câblage fourni dans le code. Vous pouvez trouver des instructions détaillées dans la section "Câblage" du README.

## Câblage

| Composant               | Arduino Pin | Description                                          |
|-------------------------|-------------|------------------------------------------------------|
| ACS712 (Signal)         | A0          | Connecté à la broche analogique A0 pour le signal.   |
| ACS712 (Alimentation +) | 5V          | Alimentation en 5V pour le capteur ACS712.            |
| ACS712 (Alimentation -) | GND         | Mise à la terre pour le capteur ACS712.              |
| RTC DS3231 (SDA)         | A4          | Connecté à la broche analogique A4 pour la communication I2C (données). |
| RTC DS3231 (SCL)         | A5          | Connecté à la broche analogique A5 pour la communication I2C (horloge). |
| RTC DS3231 (VCC)         | 5V          | Alimentation en 5V pour le module RTC.               |
| RTC DS3231 (GND)         | GND         | Mise à la terre pour le module RTC.                  |
| IR LED                  | 9           | Connecté à la broche numérique 9 pour la LED infrarouge. |
| (Autres connexions)      | -           | Assurez-vous de connecter les broches GND ensemble pour une référence commune. |

## Personnalisation

Vous pouvez personnaliser ce projet en ajustant les seuils de courant, les durées du minuteur, ou en ajoutant des fonctionnalités supplémentaires selon vos besoins.

## Auteurs

- **Arkyos03**

N'hésitez pas à contribuer à ce projet en proposant des améliorations, des corrections de bugs, ou des fonctionnalités supplémentaires.

## Licence

-- 
