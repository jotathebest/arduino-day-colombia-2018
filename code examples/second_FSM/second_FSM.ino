/*
   State machine valid states
*/
enum states { 
  LED_ON,
  LED_OFF,
  NUM_STATES
};

/*
    Initial SM state and functions declaration
*/
enum states state = LED_OFF;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(state) {
    case LED_ON:
      digitalWrite(LED_BUILTIN, HIGH);
      state = LED_OFF;
      break;
    case LED_OFF:
      digitalWrite(LED_BUILTIN, LOW);
      state = LED_ON;
      break;
  }
  delay(1000);
}
