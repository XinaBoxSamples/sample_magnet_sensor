#include <xCore.h> //add core library @ https://github.com/xinabox/xCore
#include <xOD01.h> //add sensor library @ https://github.com/xinabox/xOD01
#include "TIMER_CTRL.h"
#include <SparkFun_MAG3110.h> //add Sparkfun library @ https://github.com/sparkfun/SparkFun_MAG3110_Breakout_Board_Arduino_Library

#if defined(ESP8266)
#define RED   RED
#define GREEN GREEN
#define BLUE  BLUE
#include <ESP8266WiFi.h>
#define Serial Serial

#elif defined(ARDUINO_SAMD_ZERO)
#define RED   CC03_RED
#define GREEN CC03_GREEN
#define BLUE  CC03_BLUE
#define Serial SerialUSB

#elif defined(ARDUINO_AVR_PRO)
#define RED   CC01_RED
#define GREEN CC01_GREEN
#define BLUE  CC01_BLUE
#define Serial Serial

#elif defined(ESP32)
#define RED   CW02_RED
#define GREEN CW02_GREEN
#define BLUE  CW02_BLUE
#define Serial Serial
#endif

float initvalue;
float maxt;
float intt;
boolean magnet;
boolean first;
boolean calibration_flag = false;
MAG3110 mag = MAG3110(); //Instantiate MAG3110

unsigned long currentMilli = 0;
int ledID = 0;

bool fade_flag1 = true;
unsigned long previousMilli1 = 0;    // timing variable for LEDS
int LED_state1 = 0;
bool fade_flag2 = true;
unsigned long previousMilli2 = 0;    // timing variable for LEDS
int LED_state2 = 0;
bool fade_flag3 = true;
unsigned long previousMilli3 = 0;    // timing variable for LEDS
int LED_state3 = 0;


void setup() {
  // put your setup code here, to run once:
  setup_program();
}

void loop() {
  // put your main code here, to run repeatedly:
  main_program();
}
