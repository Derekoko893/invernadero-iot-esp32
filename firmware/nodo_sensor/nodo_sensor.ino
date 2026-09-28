#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define SOIL_PIN 34
#define LDR_PIN 32

DHT dht(DHT_PIN, DHT_TYPE);

int promedioADC(int pin) {

  long suma = 0;
  const int muestras = 10;

  for (int i = 0; i < muestras; i++) {
    suma += analogRead(pin);
    delay(10);
  }

  return suma / muestras;
}

void setup() {

  Serial.begin(115200);

  dht.begin();

  pinMode(SOIL_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);

  Serial.println("Nodo sensor iniciado");
}

void loop() {

  float temperatura = dht.readTemperature();
  float humedadAmbiente = dht.readHumidity();

  int humedadSuelo = promedioADC(SOIL_PIN);
  int luz = promedioADC(LDR_PIN);

  if (isnan(temperatura) || isnan(humedadAmbiente)) {

    Serial.print("Error DHT22");

  } else {

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C");

    Serial.print(" | Humedad ambiente: ");
    Serial.print(humedadAmbiente);
    Serial.print(" %");
  }

  Serial.print(" | Suelo ADC: ");
  Serial.print(humedadSuelo);

  Serial.print(" | Luz ADC: ");
  Serial.println(luz);

  delay(2500);
}
