#include <iostream>

#include <wire.h>

#include <Adafruit_MotorShield.h>

Adafruit_MotorShield motorShield = Adafruit_MotorShield();

Adafruit_DCMotor *leftMotor = motorShield.getMotor(1);
Adafruit_DCMotor *rightMotor = motorShield.getMotor(2);

const int trigPin = 9;
const int echoPin = 10;

void setup() {
    Serial.begin(9600);

if (!motorShield.begin()){
    Serial.println("Erro ao inicializar a placa de controle de motores.");
    while(1);
}

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED_BUILTIN, OUTPUT);
}

void loop () {

    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

Serial.print("Distância: ");
Serial.print(distance);
Serial.println(" cm");

    if (distance > 20){
        leftMotor->setSpeed(150);
        rightMotor->setSpeed(150);        
        leftMotor->run(FORWARD);
        rightMotor->run(FORWARD);
    } else {
        leftMotor->setSpeed(0);
        rightMotor->setSpeed(0);        
        leftMotor->run(RELEASE);
        rightMotor->run(RELEASE);
    }

    delay(10000);

    if (Serial.available() > 0){
        char command = Serial.read();

        switch (command)
        {
        case 'F':
            // Move to Forward
            leftMotor->setSpeed(150);
            rightMotor->setSpeed(150);        
            leftMotor->run(FORWARD);
            rightMotor->run(FORWARD);
            break;
        
        case 'B':
            // Move to Backward
            leftMotor->setSpeed(150);
            rightMotor->setSpeed(150);        
            leftMotor->run(FORWARD);
            rightMotor->run(FORWARD);
            break;

        case 'S':
            // Stop
            leftMotor->setSpeed(0);
            rightMotor->setSpeed(0);        
            leftMotor->run(RELEASE);
            rightMotor->run(RELEASE);
            break;

        default:
            break;
        }
    }

}


