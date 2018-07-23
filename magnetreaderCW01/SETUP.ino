void setup_program(void) {
  // Set the I2C Pins for CW01
#ifdef ESP8266
 Wire.pins(2, 14);
 Wire.setClockStretchLimit(15000);
 Wire.begin();
#else
 // Start the I2C Comunication
 Wire.begin();
#endif
  // disable wifi
  WiFi.forceSleepBegin();

  // set and start i2c bus
  Wire.begin(2, 14);

  // start sensor
   mag.initialize(); //Initialize the MAG3110
 initvalue = 12345;
 maxt=0;

  // start oled
  OLED.begin();
  
  // clear oled
  OD01.clear();

  // set output leds
  pinMode(CW01_RED, OUTPUT);
  pinMode(CW01_GREEN, OUTPUT);
  pinMode(CW01_BLUE, OUTPUT);

  // turn rgb on
  digitalWrite(CW01_RED, HIGH);
  digitalWrite(CW01_GREEN, HIGH);
  digitalWrite(CW01_BLUE, HIGH);

  delay(2000);

  // turn rgb off
  digitalWrite(CW01_RED, LOW);
  digitalWrite(CW01_GREEN, LOW);
  digitalWrite(CW01_BLUE, LOW);
  
  delay(1000);
  t.tick_main = millis();
  t.tick_poll = millis();
}

