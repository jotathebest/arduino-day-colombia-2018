/*
   COLOMBIA ARDUINO AND RASPBERRY PI DAY
   Example Script to create finite state machines

   Based on three great website posts

   John Santic
   http://johnsantic.com/comp/state.html

   Jacob Beningo
   https://www.edn.com/electronics-blogs/embedded-basics/4406821/Function-pointers---Part-3--State-machines

   Joonas Pihlajamaa
   http://codeandlife.com/2013/10/06/tutorial-state-machines-with-c-callbacks/

   Speaker:
   Jose Garcia @Ubidots Hardware and Software Developer
*/


/***********************************
   STATE MACHINE SETUP
 ***********************************/

/*
   State machine valid states
*/
typedef enum {
  LED_ON,
  LED_OFF,
  NUM_STATES
} StateType;

/*
   State machine table structure
*/

typedef struct {
  StateType State;

  // Create the function pointer
  void (*function)(void);
} StateMachineType;


/*
    Initial SM state and functions declaration
*/

StateType SmState = LED_ON;

void Sm_LED_ON();
void Sm_LED_OFF();

/*
   LookUp table with states and functions to execute
*/

StateMachineType StateMachine[] =
{
  {LED_ON, Sm_LED_ON},
  {LED_OFF, Sm_LED_OFF}
};

/*
   Custom State Functions routines
*/

void Sm_LED_ON() {
  // Custom Function Code
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  // Move to next state
  SmState = LED_OFF;
}

void Sm_LED_OFF() {
  // Custom Function Code
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  // Move to next state
  SmState = LED_ON;
}

/*
   Main function state change routine
*/

void Sm_Run(void) {
  // Makes sure that the actual state is valid
  if (SmState < NUM_STATES) {
    (*StateMachine[SmState].function) ();
  }
  else {
    // Error exception code
    Serial.println("[ERROR] Not valid state");
  }
}

/***********************************
   MAIN ARDUINO FUNCTIONS
 ***********************************/

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Sm_Run();
}
