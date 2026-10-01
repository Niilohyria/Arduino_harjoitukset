// vakioita ei muuteta. Niitä käytetään määrittämään pinnien numerot:
const int nappiPinni = 2;     // painonapin pinnin numero
const int ledPinni = 13;      // LEDin pinnin numero
int ledTila = LOW;            // ledTila kertoo, onko LED päällä vai ei
long edellinenMillis = 0;     // tallentaa viimeisimmän ajan, jolloin LED päivitettiin

// seuraavat muuttujat ovat long-tyyppisiä, koska aika millisekunteina
// kasvaa nopeasti suuremmaksi kuin mitä int voi tallentaa
long aikavali = 1000;

int napinTila = 0;            // muuttuja painonapin tilan lukemiseen
int laskuri = 0;
int edellinenNapinTila = 0;

void setup() {
  // alustetaan LED-pinni ulostuloksi:
  pinMode(ledPinni, OUTPUT);
  // alustetaan painonappi syötteeksi:
  pinMode(nappiPinni, INPUT);
 
}

void loop() {
  unsigned long nykyinenMillis = millis();
  // luetaan painonapin tila:
  napinTila = digitalRead(nappiPinni);

  // jos napin tila on muuttunut edellisestä
  if (napinTila != edellinenNapinTila) {
    if (napinTila == HIGH) {
      laskuri++;
      if (laskuri == 10) // nollataan laskuri 10 painalluksen jälkeen
        laskuri = 0;
    }
  }

  // jos painalluksia on vähintään 5, vilkutetaan LEDiä
  if (laskuri >= 5) {
   digitalWrite(ledPinni, HIGH);
  
  } else {
    // jos painalluksia on alle 5, LED on pois päältä
    digitalWrite(ledPinni, LOW);
  }

  edellinenNapinTila = napinTila;
 
}
