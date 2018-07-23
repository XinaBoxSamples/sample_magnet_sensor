void TaskScheduler(void) {
  if (ledID == 0) {
   red_fade(30, CW01_RED, 255, 5);
 } else if (ledID == 1) {
   green_fade(30, CW01_GREEN, 255, 5);
 } else if (ledID == 2) {
   blue_fade(30, CW01_BLUE, 255, 5);
 }


  if (calibration_flag) {
    if ((millis() - t.tick_main) > 500) {
      OD01.clear();
      main_code();
      t.tick_main = millis();
    }
  }

  if (!calibration_flag) {
    if ((millis() - t.tick_main) > 10) {
      calibrate_mag();
      t.tick_main = millis();
    }
  }

}
