#define RED_LIGHT 9 // first light, red LEDs (high when opposite detected, low when clear)
#define GREEN_LIGHT 8 // first light, green LEDs (high when clear, low when opposite detected)
#define RED_LIGHT_2 10 // second light, red LEDs (high when opposite detected, low when clear)
#define GREEN_LIGHT_2 11 // second light, green LEDs (high when clear, low when opposite detected)

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(RED_LIGHT_2, OUTPUT);
  pinMode(GREEN_LIGHT_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RED_LIGHT, HIGH);
  digitalWrite(GREEN_LIGHT_2, HIGH);
  
  digitalWrite(RED_LIGHT_2, LOW);
  digitalWrite(GREEN_LIGHT, LOW);
  
  delay(500);
  
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(GREEN_LIGHT_2, LOW);

  digitalWrite(RED_LIGHT_2, HIGH);
  digitalWrite(GREEN_LIGHT, HIGH);
  
  delay(500);

  digitalWrite(RED_LIGHT, HIGH);
  digitalWrite(GREEN_LIGHT_2, HIGH);
  
  digitalWrite(RED_LIGHT_2, LOW);
  digitalWrite(GREEN_LIGHT, LOW);

  delay(500);

}
