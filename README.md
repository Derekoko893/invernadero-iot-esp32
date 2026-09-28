# Invernadero Inteligente IoT

Proyecto IoT para el monitoreo de variables ambientales utilizando un ESP32.

## Objetivo

Implementar un nodo sensor capaz de obtener datos en tiempo real para supervisar las condiciones de una planta.

## Variables medidas

- Temperatura ambiental
- Humedad ambiental
- Humedad del suelo
- Intensidad de luz

## Hardware utilizado

- ESP32
- DHT22
- Sensor capacitivo de humedad de suelo
- Sensor LDR
- Protoboard
- Cables Dupont

## Conexiones actuales

| Sensor | Señal | ESP32 |
|---|---|---|
| DHT22 | OUT | GPIO 4 |
| Humedad suelo | AOUT | GPIO 34 |
| LDR | S | GPIO 32 |

Los sensores se alimentan con 3.3 V y comparten GND con el ESP32.

## Estado actual

- [x] ESP32 funcionando
- [x] DHT22 funcionando
- [x] Sensor de humedad del suelo funcionando
- [ ] Sensor LDR en calibración
- [ ] Integración final de sensores
- [ ] Telemetría
- [ ] Dashboard web

## Integrantes

- Nombre del integrante 1
- Nombre del integrante 2
