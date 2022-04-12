# Rapport technique

## Matériel

Notre système est composé de 3 boards : 
 - Semtech SX127
 - Nucleo L152RE sur STM32
 - Sensor SKU:SEN0208

Ainsi que d'un capteur à ultrason relié au sensor.

## Logiciel

Pendant nos développements nous avons essayé de 

- récupérer les données du capteurs
- envoyer des données par LoRaWAN

### RIOT-OS

RIOT-OS n'a pas permis de récupérer les données. 

Le test `blinky` a été concluant.

Le test `lorawan` a levé une erreur : "arm-none-eabi-gcc not found" malgré son installation

Le test `gnrc_lorawan` a compilé sans parvenir à s'enregistrer ; les devuid, appkey et appeui ont été fourni dans le Makefile.

### Arduino

Le logiciel a été utilisé tardivement.

Nous avons pu utiliser les codes example fournis sur (https://wiki.dfrobot.com/Weatherproof_Ultrasonic_Sensor_With_Separate_Probe_SKU_SEN0208)[https://wiki.dfrobot.com/Weatherproof_Ultrasonic_Sensor_With_Separate_Probe_SKU_SEN0208]

Nous avons utilisé le mode 3 qui permet de récupérer la distance. Le résultat renvoyé était constemment 0 sans que l'on sache si c'était à cause de la sonde ou d'un problème de transfert des données.

Par la suite, nous avons cherché un example LoRaWAN pour nous permettre de joindre notre carte à un serveur. Aucun n'a fonctionné. Nous avons essayé les librairies :

- Beelan LoRaWan (non conçue pour STM32)
- Cayenne LPP (non conçue pour STM32)
- EByte LoRa E32
- LoRa
- MCCI LoRaWan LMIC
- MKRWAN
- STM32duino l-Nucleo LRWAN1

Les erreurs étant peu explicites, nous avons pas pu creusé l'origine du problème.

