/*
   State machine valid states
*/
enum states { 
  LED_ON,
  LED_OFF
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
  if(state == LED_OFF) {
    digitalWrite(LED_BUILTIN, HIGH);
    state = LED_ON;
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    state = LED_OFF;
  }
}
