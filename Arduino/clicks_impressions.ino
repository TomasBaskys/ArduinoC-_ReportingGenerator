const int buttonPin = 2;      // the number of the pushbutton pin
const int ledPin =  13;       // the number of the LED pin

int lightPin = 0;             //define a pin for Photo resistor
int threshold = 400;

int lastButtonState = 0;              // previous state of the button
int lastPhotoresistorState = 0;       // previous state of the photoresistor

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
}

void loop() {
  buttonClick();
  photoresistorThreshold();
}

void buttonClick(){
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      Serial.println("click");
    }
    delay(50);
  }
  
  lastButtonState = buttonState;
  
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void photoresistorThreshold() {
  int photoresistorValue = analogRead(lightPin);
  bool photoresistorState = photoresistorValue > threshold;

  
  if (photoresistorState != lastPhotoresistorState) {
    if (photoresistorState == HIGH) {
      Serial.println("impression");
    }
    delay(50);
  }
  
  lastPhotoresistorState = photoresistorState;
}

