
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup()
{
  pinMode(13, OUTPUT);   
  pinMode(12, OUTPUT);    
  pinMode(11, OUTPUT);    
  pinMode(10, OUTPUT);   
  pinMode(9, OUTPUT);
    
  Serial.begin(9600);
  if(mma.begin()){
    Serial.println("MMA8451 found!");
    mma.setRange(MMA8451_RANGE_2_G);
  }
  else{
    Serial.println("MMA8451 not found!");
  }
}

void loop()
{
  checkButton(A0, 900, 13);
  checkButton(A1, 500, 12);
  checkButton(A2, 500, 11);
  checkButton(A3, 900, 10);

  checkAccelerometer();

  delay(100);
}


void checkButton(int analogInput, int trigger, int ledPin){
  int value = analogRead(analogInput);
  //Serial.print(analogInput); Serial.print("\t=\t"); Serial.println(value);
  if(value >= trigger )
  {
    digitalWrite(ledPin, LOW);    // sets the LED off

  }
  else{
    digitalWrite(ledPin, HIGH);    // sets the LED off
  } 
}


void checkAccelerometer(){ 
  mma.read();

  Serial.print("Y:\t"); Serial.print(mma.y); 
  Serial.println();
  
  uint8_t o = mma.getOrientation();

  if(mma.y  > 0 ){
  digitalWrite(9, HIGH);
    return;
  }
  digitalWrite(9, LOW);
  
}

