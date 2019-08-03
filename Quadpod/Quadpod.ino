#include<Servo.h>

Servo leg1Joint1;
Servo leg1Joint2;
Servo leg2Joint1;
Servo leg2Joint2;
Servo leg3Joint1;
Servo leg3Joint2;
Servo leg4Joint1;
Servo leg4Joint2;

void setup(){
  Serial.begin(9600);
  leg1Joint1.attach(5);
  leg1Joint2.attach(6);
  leg2Joint1.attach(7);
  leg2Joint2.attach(8);
  leg3Joint1.attach(9);
  leg3Joint2.attach(10);
  leg4Joint1.attach(11);
  leg4Joint2.attach(12);
  stopmtn();
}

void loop(){
abc:  if(Serial.available() > 0){
    char input = Serial.read();
    switch (input){
      case '1': fwmtn();
                goto abc;
      case '2': bwmtn();
                goto abc;
      case '3': leftmtn();
                goto abc;
      case '4': rightmtn();
                goto abc;
      default: goto abc;
    }
  }
}

void stopmtn(){
    leg1Joint1.write(90);
    leg1Joint2.write(90);
    leg2Joint1.write(90);
    leg2Joint2.write(90);
    leg3Joint1.write(90);
    leg3Joint2.write(90);
    leg4Joint1.write(90);
    leg4Joint2.write(90);
}

void fwmtn(){
    leg1Joint2.write(0);
    leg1Joint1.write(45);
    delay(200);
    leg1Joint2.write(90);
    leg2Joint2.write(0);
    leg2Joint1.write(135);
    delay(200);
    leg2Joint2.write(90);
    leg3Joint2.write(0);
    leg3Joint1.write(45);
    delay(200);
    leg3Joint2.write(90);
    leg4Joint2.write(0);
    leg4Joint1.write(135);
    delay(200);
    leg4Joint2.write(90);
    delay(200);
    leg1Joint1.write(135);
    leg2Joint1.write(45);
    leg3Joint1.write(135);
    leg4Joint1.write(45);
    delay(400);
    Serial.end();
    Serial.begin(9600);
}

void bwmtn(){
    leg1Joint2.write(0);
    leg1Joint1.write(135);
    delay(200);
    leg1Joint2.write(90);
    leg2Joint2.write(0);
    leg2Joint1.write(45);
    delay(200);
    leg2Joint2.write(90);
    leg3Joint2.write(0);
    leg3Joint1.write(135);
    delay(100);
    leg3Joint2.write(90);
    leg4Joint2.write(0);
    leg4Joint1.write(45);
    delay(100);
    leg4Joint2.write(90);
    delay(100);
    leg1Joint1.write(45);
    leg2Joint1.write(135);
    leg3Joint1.write(45);
    leg4Joint1.write(135);
    delay(400);
    Serial.end();
    Serial.begin(9600);
}

void leftmtn(){
    leg1Joint2.write(0);
    leg1Joint1.write(120);
    delay(100);
    leg1Joint2.write(90);
    leg2Joint2.write(0);
    leg2Joint1.write(120);
    delay(100);
    leg2Joint2.write(90);
    leg3Joint2.write(0);
    leg3Joint1.write(120);
    delay(100);
    leg3Joint2.write(90);
    leg4Joint2.write(0);
    leg4Joint1.write(120);
    delay(100);
    leg4Joint2.write(90);
    delay(100);
    leg1Joint1.write(60);
    leg2Joint1.write(60);
    leg3Joint1.write(60);
    leg4Joint1.write(60);
    delay(400);
    Serial.end();
    Serial.begin(9600);
}

void rightmtn(){
    leg1Joint2.write(0);
    leg1Joint1.write(60);
    delay(100);
    leg1Joint2.write(90);
    leg2Joint2.write(0);
    leg2Joint1.write(60);
    delay(100);
    leg2Joint2.write(90);
    leg3Joint2.write(0);
    leg3Joint1.write(60);
    delay(100);
    leg3Joint2.write(90);
    leg4Joint2.write(0);
    leg4Joint1.write(60);
    delay(100);
    leg4Joint2.write(90);
    delay(100);
    leg1Joint1.write(120);
    leg2Joint1.write(120);
    leg3Joint1.write(120);
    leg4Joint1.write(120);
    delay(400);
    Serial.end();
    Serial.begin(9600);
}
