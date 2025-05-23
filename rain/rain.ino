const int rainSensorPin = A3; // Analog pin connected to the rain sensor

void setup() {
  pinMode(rainSensorPin, INPUT); // Set rain sensor pin as input
  pinMode(LED_BUILTIN, OUTPUT); // Set built-in LED pin as output
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int rainValue = analogRead(rainSensorPin); // Read analog value from rain sensor
  Serial.print("Rain sensor value: ");
  Serial.println(rainValue);
  
  // Check if it's raining heavily
  if (rainValue < 1000) { // You may need to adjust this threshold based on your sensor
    digitalWrite(LED_BUILTIN, HIGH); // Turn on built-in LED
    Serial.println("Rain detected");
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Turn off built-in LED
    Serial.println("No rain detected");
  }
  
  delay(1000); // Delay before next iteration
}
