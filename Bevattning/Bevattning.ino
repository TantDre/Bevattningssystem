// Titel: Bevattning (Prototyp)
// Författare: André Sollander
// Datum: 2018-02-27

//---------- Variabler ----------

// Bevattning
int waterTime = 5 * 1000;                // Bevattningstid
int Threshold = 90;                      // Gränsvärde för jordfuktighet
int waitTime = 3600000;                  // Väntetid

// Fuktighetssensor
int sensorPin = A0;                     // Sensorns signalpin
int sensorValue = 0;                    // Definerar variabel för sensorvärde
int sensorVCC = 13;                     // Sensorns VCC-pin

// Relä
int relayPin = 11;                      // Reläts signalpin
int relayVCC = 12;                      // Reläts VCC-pin

//---------- Setup ----------

void setup() {
  Serial.begin(9600);                    // Initierar serialporten
  pinMode(sensorVCC, OUTPUT);            // Aktiverar outputpins
  pinMode(relayVCC, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(sensorVCC, LOW);          // Initial output sätts till 0V
  digitalWrite(relayVCC, LOW);
  digitalWrite(relayPin, LOW);
}

//---------- Loop ----------

void loop() {
  digitalWrite(sensorVCC, HIGH);         // Startar sensorn med 5V
  delay(100);
  sensorValue = analogRead(sensorPin);   // Läser av sensorvärdet
  digitalWrite(sensorVCC, LOW);          // Slår av sensorn
  Serial.println(sensorValue);           // Skickar värdet via serialporten

  if (Threshold < sensorValue) {         // Om sensorvärdet är högre än gränsvärdet
    digitalWrite(relayVCC, HIGH);         // Startar relästyrningen
    delay(100);
    digitalWrite(relayPin, HIGH);         // Skickar styrsignal till relät
    delay(waterTime);                     // Bevattnar
    digitalWrite(relayPin, LOW);          // Slår av styrsignalen
    digitalWrite(relayVCC, LOW);          // Slår av relästyrningen
    delay(waitTime);                       // Väntar
  }
  else {
    delay(waitTime);                        // Väntar
  }
}
