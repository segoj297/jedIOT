int sensorValue[5];
int sensorPin = 0;    // select the input pin for the sensor
int red1 = 9;     // select the pin for the LED
int red2 = 10; //added white LED to the sketch
int red3 = 2; //added yellow LED to the sketch
int buttonVal = 0;  // value of button press

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);  
  pinMode(red3, OUTPUT); 
}

//test bed for arduino pi code

void loop() {

//reading input from pins
int digValue9= digitalRead(9); //reading red1
int digValue10= digitalRead(10); //reading red2
int digValue2= digitalRead(2); //reading red3
  
 for (int i=0;i<5;i++){
  sensorValue[i] = analogRead(i);
  Serial.print(sensorValue[i]); 
  Serial.print(",");
  }
  sensorValue[5] = analogRead(5);
  Serial.print (sensorValue[5]);
  Serial.print(",");
  Serial.print(digValue9);
  Serial.print(",");
  Serial.println(digValue10);
  Serial.print(",");
  Serial.println(digValue2);

// read the value from the sensor:
buttonVal = analogRead(sensorPin); 

//master if statement, containing red1, red2, red3 ifs
if (Serial.available() > 0 ) {
//char incoming = Serial.read();


  String incoming = Serial.readStringUntil('\n');
  Serial.println(incoming);
  if (incoming=="low") {
      digitalWrite(red1, HIGH);
      digitalWrite(red2, LOW);
      digitalWrite(red3, LOW);
  }

    if (incoming=="medium") {
      digitalWrite(red1, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(red3, LOW);
  }

    if (incoming=="high") {
      digitalWrite(red1, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(red3, HIGH);
  }

  if (incoming=="off") {
      digitalWrite(red1, LOW);
      digitalWrite(red2, LOW);
      digitalWrite(red3, LOW);

  }

}
}


