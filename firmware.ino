// JBC 245 Station firmware version 3

// Copyright (C) 2021  gabor-smith

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// Firmware Version 3
// 2021.02.25.
// Compiles with MiniCore 2.0.9

#include "OneWire.h"
#include "ds18nolib.h"
#include "jbcFont.h"
#include "small4x6_font.h"
#include "ST7920_SPI.h"
#include "SPI.h"

#define MIN_TEMP 50
#define MAX_TEMP 490
#define NUM_VAL (16)

#define TC_CONSTANT 43500
#define VCC 4.79//Get vref at boot
#define R_FEEDBACK 68300
#define R_PULLDOWN 325

#define HOLD_TEMP 135
#define SLEEP_TIMEOUT 300000 //5 mins to sleep

#define TC_PIN A4
#define HEAT_PIN 6
#define INTERRUPT_PIN 2

ST7920_SPI lcd(10);

char buf[30];

int pot = 0;
int tempTab[NUM_VAL];
int i, ght = 31 - 7;
int x = 0;
int AMBIENT;
int INIT_TOGGLE = 0;

volatile int tipTempIs = 0;
volatile int tipTempSet = 0;
volatile int mainsCycles = 0;

bool HEAT;
bool NOTIP = 0;
bool HOLD = 0;
bool SLEEP = 0;
bool SLEEP_TOGGLE = 0;

unsigned long SLEEP_START = 0;
/*
void addPwr(){
  for (i = 0; i < NUM_VAL - 1; i++) pwrTab[i] = pwrTab[i + 1];
  pwrTab[NUM_VAL - 1] = pwrLoad;
}*/

void addTemp(){
  for (i = 0; i < NUM_VAL - 1; i++) tempTab[i] = tempTab[i + 1];
  int t = tipTempIs;
  if (t < MIN_TEMP) t = MIN_TEMP;
  if (t > MAX_TEMP) t = MAX_TEMP;
  tempTab[NUM_VAL - 1] = (long)(t - MIN_TEMP) * ght / (MAX_TEMP - MIN_TEMP);
}

/*void drawBar(int xg, int yg, int valTab[]) {
  for (i = 1; i < NUM_VAL; i++) {
    //lcd.setFont(Small4x6PL);
    //snprintf(buf, 30, "%d%%", map(pwrLoad,0,135,0,100));
    //lcd.printStr(xg, map(pwrLoad,0,135,64,yg) - 6, buf);
    lcd.fillRect(xg, map(pwrLoad, 0, 135, 64, 0), 5, map(pwrLoad, 0, 135, 59, 64), 1);
    //lcd.drawLineH(1 + xg + (i - 1) * 4, 1 + xg + (i + 0) * 4 - 1, yg + ght - 1 - valTab[i], 1);
    //lcd.drawLineH(xg + 1,xg + 7,map(pwrLoad,0,135,64,yg),0);
    //if (i > 1) lcd.drawLineV(1 + xg + (i - 1) * 4, yg + ght - 1 - valTab[i - 1], yg + ght - 1 - valTab[i], 1);
  }
}*/

void drawGraph(int xg, int yg, int valTab[]){
  for (i = 0; i < NUM_VAL - 1; i++) {
    int dy = valTab[i + 1] - valTab[i];
    lcd.drawLine(1 + xg + i * 4, yg + ght - 1 - valTab[i], 1 + xg + (i + 1) * 4, yg + ght - 1 - valTab[i + 1], 1);
  }
  /*snprintf(buf, 30, "%d'c",MAX_TEMP);
    lcd.printStr(97,yg,buf);
    snprintf(buf, 30, "%d'c",MIN_TEMP);
    lcd.printStr(97,58,buf);*/
}

void display(){
  lcd.cls();
  lcd.setFont(jbcFont);
  if(!NOTIP){
    snprintf(buf, 30, "%d\177c", tipTempIs);
    lcd.printStr(ALIGN_CENTER, 12, buf);
  }else{//tip not present
    snprintf(buf, 16, "NO TIP");
    lcd.printStr(32, 12, buf);
  }
  
  lcd.setFont(Small4x6PL);
  snprintf(buf, 30, "%d'c", pot);
  lcd.printStr(ALIGN_CENTER, 30, buf);
  if(HEAT) lcd.printStr(2, 56, "HEAT");
  if(HOLD) lcd.printStr(2, 56, "HOLD");
  if(SLEEP) lcd.printStr(2, 56, "SLEEP");
  snprintf(buf, 30, "%d'c", AMBIENT);
  lcd.printStr(109, 2, buf);
}

float runningAverage(float M){
  #define LENGTH 6
  static int values[LENGTH];
  static byte index = 0;
  static float sum = 0;
  static byte count = 0;
  sum -= values[index];
  values[index] = M;
  if(values[index] >= values[index-1]+100 && values[index] >= values[index-2]+100 || values[index]+100 <= values[index-1] && values[index]+100 <= values[index-2]){//throw out garbage input
    values[index] = values[index-2];
  }
  sum += values[index];
  index++;
  index = index % LENGTH;
  if (count < LENGTH) count++;
  return sum / count;
}

void zeroCrossingInterrupt(){
  mainsCycles++;
}

void setup(){
  //SPI.begin();
  //lcd.cls();
  lcd.init();
  lcd.display(0);
  /*lcd.setFont(jbcFont);//Loading screen
  lcd.printStr(24, 25, "JBC 245");
  lcd.drawRect(16, 20, 127 - 16 * 2, 63 - 20 * 2, 1);
  lcd.setFont(Small4x6PL);
  lcd.printStr(ALIGN_CENTER, 50, "Loading...");*/
  
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(HEAT_PIN, OUTPUT);
  pinMode(3, INPUT);
  HEAT = false;
  
  delay(100);
  dallas(A1, 1);
  delay(100);
  AMBIENT = dallas(A1, 0);
  delay(1000);
  
  readTemp();
  INIT_TOGGLE = 0;
  tipTempSet = 0;
  SLEEP = 1;
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), zeroCrossingInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(3), readTemp, FALLING);
}

void readTemp(){
  digitalWrite(HEAT_PIN, LOW);
  delayMicroseconds(800);
  tipTempIs = round(runningAverage(((analogRead(TC_PIN) * (VCC / 1023.0)) / (1 + R_FEEDBACK / R_PULLDOWN)) * TC_CONSTANT + AMBIENT));
  NOTIP = 0;
  if(tipTempIs >= 700) NOTIP = 1;
  delayMicroseconds(100);
  if(HEAT) digitalWrite(HEAT_PIN, HIGH);
}

void loop(){
  if(mainsCycles >= 0){
    digitalWrite(HEAT_PIN, LOW);
    HEAT = false;
    if(digitalRead(3) == 0) readTemp();
  }

  if(mainsCycles > 4){
    noInterrupts();
    if(tipTempIs < tipTempSet){
      digitalWrite(HEAT_PIN, HIGH);
      HEAT = true;
      //mainsCycles = sqrt(tipTempSet - tipTempIs) * -1;
    }
    else mainsCycles = -4;
    interrupts();
  }

  if(analogRead(A0) > 900){//iron in hold
    pot = map(analogRead(A3), 0, 1024, MIN_TEMP, MAX_TEMP);
    if(INIT_TOGGLE){
      HOLD = 1;
      if(!SLEEP_TOGGLE){
        SLEEP_START = millis();
        SLEEP_TOGGLE = 1;
        SLEEP = 0;
      }
      tipTempSet = HOLD_TEMP;//set hold temperature
      if(millis() - SLEEP_START >= SLEEP_TIMEOUT){//SLEEP time reached
        HOLD = 0;
        SLEEP = 1;
        tipTempSet = 0;//setting SLEEP temperature
      }
    }
  }else{//iron normal
    pot = tipTempSet = map(analogRead(A3), 0, 1024, MIN_TEMP, MAX_TEMP);
    INIT_TOGGLE = 1;
    HOLD = 0;
    SLEEP_TOGGLE = 0;
    SLEEP = 0;
  }
  display();
  addTemp();
  for(int i = 0; i < 100; i++){
    drawGraph(32, 40, tempTab);
  }
  lcd.display(0);
  mainsCycles++;
}
