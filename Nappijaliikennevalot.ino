int red = 13;
int yellow = 11;
int green = 9;
int button = 7;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

// odotus joka reagoi nappiin heti
bool waitMs(unsigned long timeMs) {
  unsigned long start = millis();
  while (millis() - start < timeMs) {
    if (digitalRead(button) == HIGH) {
      // heti punainen
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      return true;
    }
  }
  return false;
}

void loop() {

  // punainen
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  if (waitMs(3000)) return;

  // punainen + keltainen
  digitalWrite(yellow, HIGH);
  if (waitMs(1000)) return;

  // vihreä
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  if (waitMs(3000)) return;

  // keltainen
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  waitMs(1000);
}