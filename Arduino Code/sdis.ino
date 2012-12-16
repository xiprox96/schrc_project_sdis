 #include <SoftwareSerial.h>
#include <LiquidCrystal.h>

 #define rxPin 2
#define txPin 3

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//String holder;
//int ihsan = 111111;
//nt haris = 000000; 

byte ihsan[5] = {0x06,0x02,0x8D,0x29,0xDC};
byte hadzem[5] = {0x06,0x02,0x6E,0x8D,0x9C};
byte haris[5]  = {0x06,0x02,0x4D,0x1C,0xD7};

 byte data[5];  
 int val = 0;

 void setup()
 {     
   
  lcd.begin(16, 2);
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
pinMode(25, OUTPUT);
pinMode(22, OUTPUT);
pinMode(24, OUTPUT);
        digitalWrite(22, HIGH);
                digitalWrite(25, HIGH);
                                digitalWrite(24, HIGH);


Serial.begin(9600);
  }

 void loop()
 {
  

  Serial.print(0xAB,BYTE);     
     Serial.print(0x02,BYTE);       
        Serial.print(0x02,BYTE);  
             
  

   val = Serial.read();
    
   while (val != 0xAB)
   { 
      val = Serial.read();
      delay(1000);
   }
   

   data[0] = Serial.read();    // we read data 1
   data[1] = Serial.read();    // we read data 2
   data[2] = Serial.read();    // we read data 3
   data[3] = Serial.read();    // we read data 4
   data[4] = Serial.read();    // we read data 5
   Serial.read();              // checksum
   
      boolean i_card = true;
   boolean h_card = true;
      boolean ha_card = true;
   
   for (int i=0; i<5; i++)
   {
     if (data[i] < 16) Serial.print("0");
     Serial.print(data[i], HEX);
   //  holder = (data[1], HEX);
      
      
    if (data[i] != ihsan[i]) i_card = false;
    if (data[i] != haris[i]) h_card = false;
    if (data[i] != hadzem[i]) ha_card = false;
      
   
   }
    
   if (i_card) 
   {
     Serial.println("Hello ihsan!");
    lcd.clear();
     //lcd.print("ihsan isik:");
      lcd.print("Ihsan Isik");
      lcd.setCursor(0, 1);
     lcd.print("06028D29DC");
     digitalWrite(24, LOW);
          digitalWrite(22, LOW);
     
        digitalWrite(25, HIGH);
        
   }
  
  
   else if (h_card) 
   {
     Serial.println("Hello Haris!");
          lcd.clear();
      lcd.print("Haris Botic");
      lcd.setCursor(0, 1);
     lcd.print("06024D1CD7");
         digitalWrite(24, LOW);
                   digitalWrite(22, LOW);
      
          digitalWrite(25, HIGH);
   }
  
  else if (ha_card) 
   {
     Serial.println("Unknown Card!");
          lcd.clear();
      lcd.print("Unknown");
      lcd.setCursor(0, 1);


          digitalWrite(25, LOW);
                    digitalWrite(22, HIGH);
           digitalWrite(24, HIGH);56
Serial.print(0x0f,BYTE);  



delay(1000);


 }
 }
