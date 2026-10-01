#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define SOIL_PIN 34
#define LDR_PIN 32

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(SOIL_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);

  Serial.println("Sistema iniciado...");
}

void loop() {

  // DHT22
  float humedadAmbiente = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Sensor de suelo
  int humedadSuelo = analogRead(SOIL_PIN);

  // LDR
  int luz = analogRead(LDR_PIN);

  if (!isnan(humedadAmbiente) && !isnan(temperatura)) {

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C");

    Serial.print(" | Humedad ambiente: ");
    Serial.print(humedadAmbiente);
    Serial.print(" %");

  } else {
    Serial.print("Error DHT22");
  }

  Serial.print(" | Suelo ADC: ");
  Serial.print(humedadSuelo);

  Serial.print(" | Luz ADC: ");
  Serial.println(luz);

  delay(2500);
}