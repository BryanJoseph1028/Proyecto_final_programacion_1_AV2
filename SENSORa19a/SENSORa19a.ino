int inPin =  8; //fin del sensor//
int value0 = 0;
int led = 12; //pin donde se encuentra el led//

void setup() {
  Serial.begin(9600); //de entrada//
   pinMode(inPin,INPUT);
   pinMode(led,OUTPUT);//de salida//  
}

void loop() {
  value0 = digitalRead(inPin);

  if(digitalRead(inPin)==LOW){
    digitalWrite(led,HIGH); //ENCIENDE EL LED//
    }
    else{
      digitalWrite(led,LOW); //APAGA EL LED//
      }
       Serial.print("sensor =1");  Serial.print(value0);//IMPRIME//
       delay(1000);
}
