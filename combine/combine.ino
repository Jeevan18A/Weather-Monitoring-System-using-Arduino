#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LM35 A0 // Analog pin connected to LM35 temperature sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LM35, INPUT); // Set LM35 pin as input
  pinMode(LED_BUILTIN, OUTPUT); // Set built-in LED pin as output
  Serial.begin(9600);
  Serial.println(F("Combined Code Test!"));
  dht.begin();
}

void loop() {
  // Read temperature from LM35 sensor
  float lmvalue = analogRead(LM35);
  float tempr = (lmvalue * 500) / 1023;
  Serial.print("Temperature from LM35: ");
  Serial.println(tempr); //Temperature in Celcius

  // Read temperature and humidity from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Check if it's raining heavily
  int rainValue = analogRead(A3);
  if (rainValue < 1000) { // You may need to adjust this threshold based on your sensor
    digitalWrite(LED_BUILTIN, HIGH); // Turn on built-in LED
    Serial.println("Rain detected");
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Turn off built-in LED
    Serial.println("No rain detected");
  }

  // Print temperature and humidity from DHT sensor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));

  delay(2000); // Wait before next reading
}
