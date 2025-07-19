//Soil Agriculture moisture with pump
#define sensorPin A0
#define RELAY_PIN 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}


void loop() {
   // Read the Analog Input
   // 625 IS AIR = 0%
   // 280-290 = WATER = 100%
  int value = analogRead(sensorPin);
  
  // Print the value to the serial monitor
  Serial.println("Analog output: ");
  Serial.println(value);
  
  // Wait for 1 second before the next reading
  delay(3000);

  if(value > 800){
    Serial.println("The soil moisture is DRY => activate pump");
    digitalWrite(RELAY_PIN, LOW);
    delay(2000);
  }else{
    Serial.println("The soil moisture is WET => deactivate the pump");
    digitalWrite(RELAY_PIN, HIGH);
    delay(2000);
  }

  delay(1000);
}
