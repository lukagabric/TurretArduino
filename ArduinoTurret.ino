#include <Servo.h> 
 
Servo servoVertical;
Servo servoHorizontal;
 
int servoVerticalPin = 9;
int servoHorizontalPin = 10;

int x, prevX;
int y, prevY;

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
    if (prevX != x || prevY != y) {
        prevX = x;
        prevY = y;

        int servoX = map(x, 0, 600, 40, 130);
        int servoY = map(y, 0, 450, 160, 80);
        
        servoX = min(servoX, 130);
        servoX = max(servoX, 40);
        servoY = min(servoY, 160);
        servoY = max(servoY, 80);
        
        servoHorizontal.write(servoX);
        servoVertical.write(servoY);
        
        delay(20);
    }
}
