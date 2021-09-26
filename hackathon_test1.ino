#define RED_LEDS 9
#define GREEN_LEDS 8

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LEDS, OUTPUT);
  pinMode(GREEN_LEDS, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RED_LEDS, HIGH);
  delay(500);
  digitalWrite(RED_LEDS, LOW);
  digitalWrite(GREEN_LEDS, HIGH);
  delay(500);
  digitalWrite(GREEN_LEDS, LOW);

}
