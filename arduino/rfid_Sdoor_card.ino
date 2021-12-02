//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <TM1637Display.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED
#define BUZZER 2 //buzzer pin
#define CLK 7 //afficheur pin 
#define DIO 8 //afficheur pin 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
TM1637Display display = TM1637Display(CLK,DIO);

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  display.setBrightness(7);
  display.clear();
  delay(1000);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //change here the UID of the card/cards that you want to give access
  if (content.substring(1) == "63 83 C9 3E" || content.substring(1) == "04 75 44 4B 71 57 80" ) 
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
    const uint8_t SEG_DONE[] = {
 /* SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_C | SEG_D | SEG_E | SEG_G  ,                 // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E*/
  SEG_A |SEG_B |SEG_C |SEG_D |SEG_E |SEG_F , 
  SEG_B |SEG_C |SEG_D |SEG_E |SEG_F ,
  SEG_E |SEG_F ,
  };
  display.setSegments(SEG_DONE,4,0);
    
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
        const uint8_t SEG_DONE[] = {
  SEG_C | SEG_E | SEG_G,                           // n     
  SEG_C | SEG_D | SEG_E | SEG_G  ,              // O
  SEG_C | SEG_E | SEG_G,                           // n
  
  };
  display.setSegments(SEG_DONE,3,0);
  }
} 
