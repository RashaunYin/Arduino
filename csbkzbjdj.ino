const int TrigPin = 0; 
const int EchoPin = 1; 
float distance;  

void setup() {
  // 初始化数字引脚LED_BUILTIN作为输出。
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); 
  
  Serial.println("Ultrasonic sensor:"); 
}


void loop() {
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  distance = pulseIn(EchoPin, HIGH) / 58.00; 

  if (distance <= 10) {
  digitalWrite(13, HIGH);   
  delay(1);                       
  digitalWrite(13, LOW);    
  delay(1);        
}

  else{
  digitalWrite(13, LOW);   
  delay(1);                       
  digitalWrite(13, HIGH);    
  delay(1);        
}

  Serial.print(distance); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(1000); 
}
