// Pin Definitions
const int touchSensorPin = 2;
const int blueLEDPin = 9;
const int redLEDPin = 10;
const int greenLEDPin = 11;

// Variables
bool doorStatus = false; // false = "do not enter", true = "enter"

void setup()
{
  pinMode(touchSensorPin, INPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  digitalWrite(blueLEDPin, HIGH); // Blue LED on as standby light
}

void loop()
{
  int touchValue = digitalRead(touchSensorPin);

  if (touchValue == HIGH) // Touch sensor is triggered
  {
    delay(50); // Software debounce, can be adjusted to suit the specific sensor
    if (digitalRead(touchSensorPin) == HIGH) // Check again to make sure it wasn't a transient spike
    {
      doorStatus = !doorStatus; // Toggle door status

      // Update LEDs according to the new door status
      if (doorStatus)
      {
        digitalWrite(blueLEDPin, LOW); // Turn off standby light
        digitalWrite(redLEDPin, LOW);
        digitalWrite(greenLEDPin, HIGH);
      }
      else
      {
        digitalWrite(blueLEDPin, LOW); // Turn off standby light
        digitalWrite(greenLEDPin, LOW);
        digitalWrite(redLEDPin, HIGH);
      }

      delay(1000); // Wait for 1 second before accepting another touch, can be adjusted to suit your needs
      
      digitalWrite(redLEDPin, LOW); // Turn off red or green LED
      digitalWrite(greenLEDPin, LOW);
      digitalWrite(blueLEDPin, HIGH); // Turn on standby light
    }
  }
}
