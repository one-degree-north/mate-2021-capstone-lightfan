


int incomingByte = 0;     //for incoming serial data
int photoresistor = 0;    //this variable will hold a value based on the brightness of the ambient light


int pwmA=; //pin values to be determined later
int in1A=;
int in2A=;



void setup()

{
  Serial.begin(9600);               //start a serial connection with the computer
  delay(100);

// pins for the fan control
pinMode(pwmA, OUTPUT);
pinMode(in1A, OUTPUT);
pinMode(in2A, OUTPUT);

}




void loop()
{

// Turn on fan
digitalWrite(in1A, HIGH)
digitalWrite(in2A, LOW)

  //packets + photoresistor
  if (Serial.available()) {
    photoresistor = analogRead(A0);   
    int incomingByte = Serial.read();  
    }

  
    if (incomingByte()== "255") {
      value = map(photoresistor, 0, 1053, 1, 255)   //original stragety: value = ((photoresistor/400)255)
      Serial.print("Data byte num: ");
      Serial.println(value);
      Serial.write(value);                          //sends the photoresistor value 
    }

    else if (incomingByte()== "254") {
      digitalWrite(13, LOW);
    }
    
    else if (incomingByte()== "253") {
      digitalWrite(13, HIGH);
    }
  
  
  Serial.print("I received: "); {
  Serial.println(photoresistor); 
  }
  

  if (0 <= int(incomingByte()) <= 252) {
    fan_Speed = incomingByte/253 * 255    //converting to fan speed
  }


//changing the fan speed
analogWrite(pwmA, fan_Speed);


}
