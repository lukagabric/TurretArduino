#include <Servo.h> 
 
Servo servoVertical;
Servo servoHorizontal;
 
int servoVerticalPin = 9;
int servoHorizontalPin = 10;

int x;
int y;

void setup() { 
    Serial.begin(9600);
    servoVertical.attach(servoVerticalPin);
    servoHorizontal.attach(servoHorizontalPin);
} 

void loop() {
    if (Serial.available() > 0) {
        if (Serial.read() == 'X') {
            x = Serial.parseInt();
            if (Serial.read() == 'Y') {
                y = Serial.parseInt();
                moveTurret();
            }
        }
    
        while (Serial.available() > 0) {
            Serial.read();
        }        
    }
}

void moveTurret() {
    int servoX = map(x, 0, 600, 40, 130);
    int servoY = map(y, 0, 450, 20, 100);
        
    servoHorizontal.write(servoX);
    servoVertical.write(180 - servoY);
        
    delay(20);
}

