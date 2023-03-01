#include <SoftwareSerial.h>
SoftwareSerial SIM900(2,3);
String textMessage;
char phone_no[] = "+8801675324403"; //
char msg;
String message;
char str[15];


const int buzzer = 11;
const int flamePin = 8;
int flame = HIGH;

int value;
int set=10;

//const String Phone_1 = "+8801675324403";

#define rxPin 2
#define txPin 3

//SoftwareSerial sim800L(rxPin,txPin);

//sim800L.println("AT");
//delay(1000);
//sim800L.println("AT+CMGF=1");
//delay(1000);

#define rainfall A4

void setup() {
  Serial.begin (115200);
 //Serial.begin (9600); 
   pinMode(buzzer, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(rainfall,INPUT);
  

 
SIM900.begin(9600);
  delay(200);
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
SIM900.println("AT+CNMI=2,2,0,0,0");// AT Command to receive a live SMS
Serial.println("AT+CNMI=2,2,0,0,0");
    Serial.print("SIM900 ready...");
delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:

   // flame detector code 23- 33
  flame = digitalRead(flamePin);

  if(flame == LOW){
    digitalWrite(buzzer, HIGH);
    //Serial.print("asd");
    delay(50);

    emergency();

     //send_multi_sms();
    //send_multi_call();
    
  }
  else{
digitalWrite(buzzer, LOW);
delay(50);
  }


  

 //Serial.println("LOL");
// rain detector code from here to rest

value = analogRead(rainfall);
 //Serial.println(value);

 value = map(value,0,1023,225,0);

 //Serial.println(value);

 if(value>=set){

//  Serial.println("rain detected");

  digitalWrite(buzzer,HIGH);

  emergency();

   //send_multi_sms();
    //send_multi_call();

 }

 else{

  digitalWrite(buzzer,LOW);

 }

 delay(50);
/*
  while(sim800L.available()){
    Serial.println(sim800L.readString());
  }

*/

}
/*
void send_sms(String text, String phone){
    sim800L.print("AT+CMGF=1\r");
    delay(1000);
    sim800L.print("AT+CMGS=\""+phone+"\"\r");
    delay(1000);
    sim800L.print(text);
    delay(100);
    sim800L.write(0x1A);
    delay(5000);
  }

  void make_call(String phone){
    Serial.println("calling...");
    sim800L.println("ATD"+phone+":");
    delay(20000);
    sim800L.println("ATH");
    delay(1000);
  }

void send_multi_sms(){
    if(Phone_1 != ""){
      Serial.print("Phone !: ");
      send_sms("Save Your Child", Phone_1);
    }
  }

  
  void send_multi_call(){
    if(Phone_1 != ""){
      Serial.print("Phone !: ");
      make_call(Phone_1);
    }
  }
*/
void emergency(){
    Serial.println("hello");
       SIM900.print("AT+CMGF=1\r"); 
    delay(20);
    SIM900.print("AT+CMGS=\"");
    SIM900.print("+8801675324403");
    SIM900.println("\"");  
    delay(20);
    SIM900.print("Your Child is in danger....");
    delay(20);
    SIM900.println((char)26); 
    delay(20);
    SIM900.println();  
      delay(200);

}

  


