#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buzzer=8;
int total=0;
bool finished=false;
bool started=false;
int minutes=0;
int seconds=0;

bool paused=false;
int pauseButton=6;
int lastButtonState=HIGH;

void setup() {
  lcd.begin(16, 2);
  pinMode(pauseButton,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,HIGH);
  Serial.begin(9600);
  lcd.print("Enter minutes: ");
  Serial.println("Enter minutes: ");

}

void loop() {
  int buttonState=digitalRead(pauseButton);
  if(buttonState==LOW && lastButtonState==HIGH){
    paused=!paused;
    if(paused) Serial.println("Timer paused");
    else Serial.println("Timer resumed");
  }
  lastButtonState=buttonState;
  if(!started && !finished && total==0 && Serial.available()>0){
    minutes=Serial.parseInt();
    while(Serial.available()>0){
      Serial.read();
    }
    lcd.clear();
    lcd.print("Minutes: ");
    lcd.print(minutes);
    delay(1000);

    Serial.println("Enter seconds: ");
    lcd.setCursor(0,1);
    lcd.print("Enter seconds");
    while(Serial.available()==0){
     
    }
    seconds=Serial.parseInt();
    while(Serial.available()>0){
      Serial.read();
    }
    int temp=seconds/60;
    seconds=seconds%60;
    total=(minutes+temp)*60+seconds;

    lcd.clear();
    lcd.print("Minutes: ");
    lcd.print(minutes);
    lcd.setCursor(0, 1);
    lcd.print("Seconds: ");
    lcd.print(seconds);
    delay(2000);
    started=true;
    lcd.clear();
  }
    if(paused){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Timer paused");
      lcd.setCursor(5, 1);
      if(minutes<10) lcd.print("0");
      lcd.print(minutes);
      lcd.print(":");
      if(seconds<10) lcd.print("0");
      lcd.print(seconds);
    }
    if(started && !finished && !paused){
      minutes=total/60;
      seconds=total%60;
      lcd.setCursor(1, 0);
      lcd.print("Time Remaining: ");
      lcd.setCursor(5, 1);
      if(minutes<10) lcd.print("0");
      lcd.print(minutes);
      lcd.print(":");
      if(seconds<10) lcd.print("0");
      lcd.print(seconds);
      delay(1000);
      total--;
      
      if(total==0){
        lcd.clear();
        lcd.print("Done!");
        digitalWrite(buzzer,LOW);
        started=false;
        finished=true;
      }
    }    
}
