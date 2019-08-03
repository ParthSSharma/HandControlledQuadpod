#include<Wire.h>

long accelX, accelY, accelZ;
double gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

void setup(){
    Serial.begin(9600);
    Wire.begin(); //I2C communication
    setupMPU(); 
}

void loop(){
    recordAccelRegisters();
    recordGyroRegisters();
    printData();
    delay(100);
}

void setupMPU(){
    Wire.beginTransmission(0b1101000); //I2C address of MPU
    Wire.write(0x6B); //Accessing register 6B, power management
    Wire.write(0b00000000); //Disabling sleep mode
    Wire.endTransmission();
    Wire.beginTransmission(0b1101000);
    Wire.write(0x1B); //Setup gyro
    Wire.write(0b00000000); //Gyro for +/- 250rpm
    Wire.endTransmission();
    Wire.beginTransmission(0b1101000);
    Wire.write(0x1C); //Setup accel
    Wire.write(0b00000000); //Accel for +/- 2g
    Wire.endTransmission();
}

void recordAccelRegisters(){
    Wire.beginTransmission(0b1101000);
    Wire.write(0x3B); //Starting registors for accel readings
    Wire.endTransmission();
    Wire.requestFrom(0b1101000, 6); //Request accel registors 3B-40
    while(Wire.available() < 6);
    accelX = Wire.read()<<8|Wire.read(); //First 2 bytes
    accelY = Wire.read()<<8|Wire.read(); //Middle 2 bytes
    accelZ = Wire.read()<<8|Wire.read(); //Last 2 bytes
    processAccelData();
}

void processAccelData(){
    gForceX = accelX/16384.0;
    gForceY = accelY/16384.0;
    gForceZ = accelZ/16384.0;
}

void recordGyroRegisters(){
    Wire.beginTransmission(0b1101000);
    Wire.write(0x43); //Starting registors for gyro readings
    Wire.endTransmission();
    Wire.requestFrom(0b1101000, 6); //Request accel registors 43-48
    while(Wire.available() < 6);
    gyroX = Wire.read()<<8|Wire.read(); //First 2 bytes
    gyroY = Wire.read()<<8|Wire.read(); //Middle 2 bytes
    gyroZ = Wire.read()<<8|Wire.read(); //Last 2 bytes
    processGyroData();
}

void processGyroData(){
    rotX = gyroX/131.0;
    rotY = gyroY/131.0;
    rotZ = gyroZ/131.0;
}

void printData(){
    //Serial.print("Gyro(deg)");
    //Serial.print(" X = ");
    Serial.print(rotX);
    Serial.print(",");
    //Serial.print(" Y = ");
    Serial.print(rotY);
    Serial.print(",");
    //Serial.print(" Z = ");
    Serial.println(rotZ);
    Serial.print(",");
    //Serial.print("Accel(g)");
    //Serial.print(" X = ");
    Serial.print(gForceX);
    Serial.print(",");
    //Serial.print(" Y = ");
    Serial.print(gForceY);
    Serial.print(",");
    //Serial.print(" Z = ");
    Serial.print(gForceZ);
    Serial.print(";");
}
