#include <Bounce2.h>

const int button1Pin = 2;
const int button2Pin = 3;

Bounce button1 = Bounce();
Bounce button2 = Bounce();

int state = 0;  
void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  button1.attach(button1Pin);
  button2.attach(button2Pin);

  button1.interval(5);
  button2.interval(5);

  Serial.begin(115200);
}

void loop() {
  button1.update();
  button2.update();

  if (button1.fell()) {
    
    state = 1;
    Serial.println("Button 1 Pressed");
  }
  if (button1.rose()){
    Serial.println("Button 1 Realeased");
    }


  
  if (button2.fell()) {
    
    state = 0;
    Serial.println("Button 2 Pressed");
  }
  if (button2.rose()){
    Serial.println("Button 2 Realeased");
  }
  
  Serial.println("Current State: " + String(state));

  delay(100);
}
