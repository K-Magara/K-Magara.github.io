#include "IRremote.h"
IRsend IrSender;    // default=3

const int F1_PIN = 4;
const int F2_PIN = 5;
const int F3_PIN = 6;
const int UP_PIN = 9;
const int DW_PIN = 11;
const int LT_PIN = 10;
const int RT_PIN = 8;

#define SENDID    0xff00

#define SEND_UP   0x19
#define SEND_DW   0x1c
#define SEND_LT   0x0c
#define SEND_RT   0x5e
#define SEND_A    0x44
#define SEND_B    0x40
#define SEND_C    0x43

unsigned long tStartMillis;

void setup() {
  pinMode(F1_PIN, INPUT_PULLUP);
  pinMode(F2_PIN, INPUT_PULLUP);
  pinMode(F3_PIN, INPUT_PULLUP);
  pinMode(UP_PIN, INPUT_PULLUP);
  pinMode(DW_PIN, INPUT_PULLUP);
  pinMode(LT_PIN, INPUT_PULLUP);
  pinMode(RT_PIN, INPUT_PULLUP);
}

void loop() {
  tStartMillis = millis();
  //
  if ( !digitalRead(F1_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_A, 0);
    SendRepeat(F1_PIN);
  }
  else if ( !digitalRead(F2_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_B, 0);
    SendRepeat(F2_PIN);
  }
  else if ( !digitalRead(F3_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_C, 0);
    SendRepeat(F3_PIN);
  }
  //
  if ( !digitalRead(UP_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_UP, 0);
    SendRepeat(UP_PIN);
  }
  else if ( !digitalRead(DW_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_DW, 0);
    SendRepeat(DW_PIN);
  }
  else if ( !digitalRead(LT_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_LT, 0);
    SendRepeat(LT_PIN);
  }
  else if ( !digitalRead(RT_PIN) ) {
    IrSender.sendNECStandard(SENDID, SEND_RT, 0);
    SendRepeat(RT_PIN);
  }
}

void SendRepeat(int pin)
{
  while ( !digitalRead(pin) ) {
    // 文献によると108ms周期だが
    // ライブラリのソース ir_NEC.cpp には 110 で計算
    delay((tStartMillis + 110) - millis());
    tStartMillis = millis();
    IrSender.sendNECRepeat();
  }
}
