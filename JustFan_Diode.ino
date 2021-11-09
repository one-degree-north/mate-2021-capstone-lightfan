

int photoresistor = 0;
int fan_Speed = 0;

int pwmA = 13;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  // pins for the fan control
  pinMode(pwmA, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:

  photoresistor = analogRead(A0);
  
  Serial.print("Recieved: ");
  Serial.println(photoresistor);
  
  fan_Speed = photoresistor/400 *255;
  //changing the fan speed
  analogWrite(pwmA, fan_Speed);
  
  Serial.print("Fan speed = ");
  Serial.println(fan_Speed);
  
  
}
