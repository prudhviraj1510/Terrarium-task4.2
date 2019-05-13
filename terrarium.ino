int photoResistor = A5;
int photoResistorPower = A0;

int photoResistorCheckTime = 10000;  
int lastPhotoResistorReport;
char lightValue[4];   

void setup() {
    
  pinMode(photoResistor, INPUT);
  pinMode(photoResistorPower, OUTPUT);

  
  digitalWrite(photoResistorPower, HIGH);
  
  lastPhotoResistorReport = millis();
}

void loop() {
    
  if ((millis() - lastPhotoResistorReport) >= photoResistorCheckTime) {
      lastPhotoResistorReport = millis();   
      int lightLevel = analogRead(photoResistor); 
      
      if (lightLevel < 500) Particle.publish("lightLevel", "dark", PRIVATE);
      if (lightLevel >= 500 && lightLevel < 900) Particle.publish("lightLevel", "medium", PRIVATE);
      if (lightLevel >= 900) Particle.publish("lightLevel", "bright", PRIVATE);
      
      sprintf(lightValue,"%d", lightLevel);   
      Particle.publish("sensorValue", lightValue, PRIVATE);
  }
} 