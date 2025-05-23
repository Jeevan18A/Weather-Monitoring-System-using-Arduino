#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define rainSensorPin A3  // Analog pin connected to the rain sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx and Rain Sensor Test!"));

  pinMode(rainSensorPin, INPUT); // Set rain sensor pin as input
  pinMode(LED_BUILTIN, OUTPUT); // Set built-in LED pin as output
  
  dht.begin(); // Begin DHT sensor
}

void loop() {
  // Read temperature and humidity from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Read rain sensor value
  int rainValue = analogRead(rainSensorPin);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print(f);
  Serial.print("°F  Heat index: ");
  Serial.print(dht.computeHeatIndex(t, h, false));
  Serial.println("°F");

  Serial.print("Rain sensor value: ");
  Serial.println(rainValue);

  // Check if it's raining heavily
  if (rainValue > 500) { // You may need to adjust this threshold based on your sensor
    digitalWrite(LED_BUILTIN, HIGH); // Turn on built-in LED
    Serial.println("Rain detected");
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Turn off built-in LED
    Serial.println("No rain detected");
  }

  delay(2000); // Delay between measurements
}
