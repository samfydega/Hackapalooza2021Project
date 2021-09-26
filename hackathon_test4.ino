#define GREEN_LIGHT 8 // first light, green LEDs (high when clear, low when opposite detected) [pin 8]

void setup() {
  
  // put your setup code here, to run once:
  pinMode(GREEN_LIGHT, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREEN_LIGHT, HIGH);
  delay(500);
  digitalWrite(GREEN_LIGHT, LOW);
  delay(500);
}
