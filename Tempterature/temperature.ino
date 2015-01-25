
double temperature = 0.0;

void setup()
{
  
  Serial.begin(9600);
  Spark.variable("temperature", &temperature, DOUBLE);
}


void loop()
{
 
  float voltage, degreesC, degreesF;

  voltage =  (analogRead(A0) * 3.3) / 4095;

  degreesC = (voltage - 0.5) * -100.0;
  
  degreesF = degreesC * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  
  temperature = degreesC;
    Spark.publish("temperature", String(degreesC));

  delay(2000); // repeat once per second (change as you wish!)
}
