/**
 * @author Avery kittkat.xyz
 * 
 * This is a tutorial project for the App State ASCII Club
**/

// Define constants
#define PIN_BTN 2

#define PIN_WAL 3
#define PIN_DON 4

#define PIN_RED 5
#define PIN_YEL 6
#define PIN_GRE 7

// Whether the current state is green (for cars)
bool isGreen = false;

// Setup the input and output pins
void setup()
{
  // Button input pin
  pinMode(PIN_BTN, INPUT);
  
  // Traffic light output pins
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YEL, OUTPUT);
  pinMode(PIN_GRE, OUTPUT);
  
  // Walk/don't walk output pins
  pinMode(PIN_WAL, OUTPUT);
  pinMode(PIN_DON, OUTPUT);
}

// Main program loop
void loop()
{
  // If the button is pressed, start the walk cycle
  if (digitalRead(PIN_BTN) == HIGH) {
    walkCycle();
    isGreen = false;
  }
  // Else, green light for cars
  else {
    // If it is just switching to green, give a small delay
    if (!isGreen) {
      delay(1000);
      isGreen = true;
      carsGreen();
    }
  }
}

// Cars have a green light
void carsGreen()
{
  digitalWrite(PIN_GRE, HIGH);
  digitalWrite(PIN_DON, HIGH);
  digitalWrite(PIN_RED, LOW);
}

// Cycle to stop cars, and allow people to go
void walkCycle()
{
  carsCountDown();
  walk();
  walkCountDown();
}

// Cycle through green, yellow, red for cars
void carsCountDown()
{
  const int time = 5;
  delay(1000);
  digitalWrite(PIN_GRE, LOW);
  digitalWrite(PIN_YEL, HIGH);
  delay(1000 * 5);
  digitalWrite(PIN_YEL, LOW);
  digitalWrite(PIN_RED, HIGH);
  delay(1000);
}

// Allow people to walk
void walk()
{
  const int time = 5;
  digitalWrite(PIN_DON, LOW);
  digitalWrite(PIN_WAL, HIGH);
  delay(1000 * 5);
}

// Count down for people walking
void walkCountDown()
{
  const int time = 10;
  digitalWrite(PIN_WAL, LOW);
  for (int i = 0; i < time; i++) {
    digitalWrite(PIN_DON, HIGH);
    delay(500);
    digitalWrite(PIN_DON, LOW);
    delay(500);
  }
  digitalWrite(PIN_DON, HIGH);
}
