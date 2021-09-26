// This is code for a "hallway stoplight system" designed for the FAU Hackathon, 9/25/21. This program uses four LEDs, two generic sensors, and an 
// Arduino Uno to create a basic, two-way stoplight system for hallways, corridors, and other confined spaces where you are worried about running
// into people in an awkward way.

#define RED_LIGHT_L 9 // first light, red LEDs (high when opposite detected, low when clear) [pin 9]
#define GREEN_LIGHT_L 8 // first light, green LEDs (high when clear, low when opposite detected) [pin 8]
#define RED_LIGHT_R 10 // second light, red LEDs (high when opposite detected, low when clear) [pin 10]
#define GREEN_LIGHT_R 11 // second light, green LEDs (high when clear, low when opposite detected) [pin 11]

#define MOTION_SENSOR_L 12 // motion detector for first light [pin 12]
#define MOTION_SENSOR_R 13 // motion detector for second light [pin 13]

int curr_state = 0; // the state machine starts in position 0, where no one is coming
int prev_state = 0;

void setup() {
  // put your setup code here, to run once:

  // initializing outputs
  pinMode(RED_LIGHT_L, OUTPUT);       
  pinMode(GREEN_LIGHT_L, OUTPUT);
  pinMode(RED_LIGHT_R, OUTPUT);
  pinMode(GREEN_LIGHT_R, OUTPUT);

  // initializing inputs
  pinMode(MOTION_SENSOR_L, INPUT);  
  pinMode(MOTION_SENSOR_R, INPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  // calling state machine 
  SM_s1();  

}

void SM_s1() {

  // taking values from motion detectors
  int left_motion = digitalRead(MOTION_SENSOR_L);
  int right_motion = digitalRead(MOTION_SENSOR_R);


  // state machine
  switch (curr_state) {
   
    case 0:                                      // no one coming

      // outputs
      digitalWrite(RED_LIGHT_L, LOW);
      digitalWrite(RED_LIGHT_R, LOW);
      digitalWrite(GREEN_LIGHT_L, HIGH);
      digitalWrite(GREEN_LIGHT_R, HIGH);

      // next state logic
      if (left_motion == HIGH) { curr_state = 1; }
      if (right_motion == HIGH) { curr_state = 2;}

      Serial.println("Currently case 0");
      
    break;

    case 1:                                     // person coming from left

      // outputs
      digitalWrite(RED_LIGHT_L, LOW);
      digitalWrite(RED_LIGHT_R, HIGH);
      digitalWrite(GREEN_LIGHT_L, HIGH);
      digitalWrite(GREEN_LIGHT_R, LOW);

      // next state logic
      if (left_motion == LOW) { curr_state = 0; }

      Serial.println("Currently case 1");
      
    break;

    case 2:                                    // person coming from right

      // outputs
      digitalWrite(RED_LIGHT_L, HIGH);
      digitalWrite(RED_LIGHT_R, LOW);
      digitalWrite(GREEN_LIGHT_L, LOW);
      digitalWrite(GREEN_LIGHT_R, HIGH);

      // next state logic
      if (right_motion == LOW) { curr_state = 0;}

      Serial.println("Currently case 2");
      
    break;
  }
 
}
