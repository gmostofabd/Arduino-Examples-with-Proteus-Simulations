#include <LiquidCrystal.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

const int buttonPin8 = 8;      // the number of the pushbutton pin
const int buttonPin9 = 9;      // the number of the pushbutton pin
const int buttonPin10 = 10;    // the number of the pushbutton pin
const int buttonPin11 = 11;    // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // initialize the library with the numbers of the interface pins
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;
int buttonState11 = 0;
uint8_t id =1;
uint8_t id_used =0;
int key= 0;

uint8_t getFingerprintEnroll();
//SoftwareSerial mySerial(11, 12);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial);

void setup() {
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(buttonPin10, INPUT_PULLUP); 
  pinMode(buttonPin11, INPUT_PULLUP); 
  lcd.begin(16, 2);
  lcd.print(" FINGERPRINT");
  lcd.setCursor(0, 1);
  lcd.print("ATTENDANCE DEMO");
  delay(500);
  finger.begin(57600);

 /* if (!finger.verifyPassword()) {        
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Did not find ");
    lcd.setCursor(0, 1);
    lcd.print("fingerprint sensor :(");
    while (1);
  } */
  
}

void loop() {
  showmenu();
  while((key = getkey()) == 0);  
  if (key == 1) {       
    id = getid();
    if(id == 0)
    {
       lcd.clear();
       lcd.setCursor(0, 0); 
       lcd.print("No space");
       lcd.setCursor(0, 1); 
       lcd.print("Del templetes");
       delay(1000);
    }else{
      getFingerprintEnroll();
    }
    delay(1500);
  } else if (key == 2) {   
    getFingerprintID();
    delay(1500);
  } else if (key == 3) {   
    showDelmenu();
    delay(1500);    
  } else if (key == 4) {   
       lcd.clear();
       lcd.setCursor(0, 0); 
       lcd.print("Credits:");
       delay(500);
       lcd.clear();
       lcd.setCursor(0, 0); 
       lcd.print("MANAN AHMED");
       lcd.setCursor(0, 1); 
       lcd.print("BROTI");
       delay(1000);
  }else {    
    //lcd.clear();
  }
}

void showmenu()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1:Enroll 2:Scan ");        
  lcd.setCursor(0, 1);
  lcd.print("3:Del  ");    
}

void showDelmenu()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  id_used = getUsedIdnext();
  lcd.print("ID <");lcd.print(id_used);lcd.print(">");
  lcd.print(" 1:Del");
  lcd.setCursor(0, 1);
  lcd.print("2:Up 3:Dn 4:Back");
   while(getkey()!=4)
   {
      if(getkey()==2)
      {
        while(getkey()==2);
        id_used = getUsedIdnext();
        lcd.setCursor(0, 0);
        lcd.print("ID <");lcd.print(id_used);lcd.print(">  1-Del");
      }else if(getkey()==3){
        while(getkey()==3);
        id_used = getUsedIdprev();
        lcd.setCursor(0, 0);
        lcd.print("ID <");lcd.print(id_used);lcd.print(">  1-Del");
      }else if(getkey()==1){
        while(getkey()==1);
        deleteFingerprint(id_used);
        unreserveId(id_used);
        id_used = getUsedIdprev();
        lcd.setCursor(0, 0);
        lcd.print("ID <");lcd.print(id_used);lcd.print(">  1-Del");
      }
      
   }
}

int getkey()
{
  if( digitalRead(buttonPin8)){
    while( digitalRead(buttonPin8));
    return 1;  
  }else if(digitalRead(buttonPin9)){
    while( digitalRead(buttonPin9));
    return 2;
  }else if(digitalRead(buttonPin10)){
    while( digitalRead(buttonPin10));
    return 3;
  }else if(digitalRead(buttonPin11)){
    while( digitalRead(buttonPin11));
    return 4;
  }else{return 0;}  
} 

int getid(){
  for(id = 1 ;id <=160;id++)
  {
    if(EEPROM.read(id)==0)
    {
      return id;  
    }
  }
  if(id>160)
  {
    return 0;  
  }
}

int getUsedIdnext()
{  
  for(;id_used<=160;)
  {
    id_used++;
    if(EEPROM.read(id_used)==1)  
    {      
      return id_used;  
    }
  }
  if(id_used>160)
  {
    return 0; 
  }
 return id_used; 
}

int getUsedIdprev()
{
  if(id_used>1)
  for(;id_used>0;)
  {
    id_used--;
    if(EEPROM.read(id_used)==1)  
    {      
      return id_used;  
    }
  }
  if(id_used>160)
  {
    return 0; 
  }
 return id_used; 
}

void reserveId(int id){
  EEPROM.write(id,1);
}

void unreserveId(int id){
  EEPROM.write(id,0);
}

uint8_t getFingerprintEnroll() {

  int p = -1;
  lcd.print("Waiting for finger");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.clear();
      lcd.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      lcd.clear();
      lcd.print("Imaging error");
      break;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      lcd.clear();
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      return p;
  }
  
  lcd.clear();
  lcd.print("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  lcd.clear();
  lcd.print("ID ");lcd.print(id);
  p = -1;
  lcd.clear();
  lcd.print("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.clear();
      lcd.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      lcd.clear();
      lcd.print("Imaging error");
      break;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      lcd.clear();
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      return p;
  }
  
  // OK converted!
  lcd.clear();
  lcd.print("Creating model #");lcd.print(id);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    lcd.clear();
     lcd.print("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    lcd.clear();
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    lcd.clear();
    lcd.print("Fingerprints did not match");
    return p;
  } else {
    lcd.clear();
    lcd.print("Unknown error");
    return p;
  }   
  
  lcd.clear();
  lcd.print("ID ");lcd.print(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    lcd.clear();
    lcd.print("Stored at id ");lcd.print(id);
    reserveId(id);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    lcd.clear();
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    lcd.clear();
    lcd.print("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    lcd.clear();
    lcd.print("Error writing to flash");
    return p;
  } else {
    lcd.clear();
    lcd.print("Unknown error");
    return p;
  }   
}


uint8_t getFingerprintID() {
  uint8_t p = 0;
  lcd.clear();
  lcd.print("Place Finger");
  delay(1500);
  p = finger.getImage();
  
  switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      lcd.clear();
      lcd.print("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      lcd.clear();
      lcd.print("Imaging error");
      return p;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      lcd.clear();
      lcd.print("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      lcd.clear();
      lcd.print("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      lcd.clear();
      lcd.print("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      lcd.clear();
      lcd.print("Could not find fingerprint features");
      return p;
    default:
      lcd.clear();
      lcd.print("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    lcd.clear();
    lcd.print("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    lcd.clear();
    lcd.print("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    lcd.clear();
    lcd.print("Did not find a match");
    return p;
  } else {
    lcd.clear();
    lcd.print("Unknown error");
    return p;
  }   
  
  // found a match!
    lcd.clear();
    lcd.print("Found ID #"); lcd.print(finger.fingerID);     
}

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  
  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
    return p;
  }   
}
