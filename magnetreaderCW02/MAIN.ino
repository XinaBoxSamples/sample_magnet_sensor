void main_code(void) {

  int x, y, z;


  //OD01.println("Entered Loop");
  mag.readMag(&x, &y, &z);
  float magnitude = sqrt(pow(x * mag.x_scale, 2) + pow(y * mag.y_scale, 2)); //x_scale and y_scale are set by calibration! Do not modify them!
  if (initvalue == 12345) initvalue = magnitude;
  float diff = pow(magnitude - initvalue, 2);
  if (diff > maxt) {
    maxt = diff;
    intt = maxt / 12;
  }
  //if (diff>0.01)
  //{
  //  OD01.print("Value: ");
  //  OD01.println(diff);
  OD01.set2X();
  for (float i = 0; i < diff; i += intt) {
    OD01.print("*");
  }
  OD01.println();
  OD01.set1X();
  OD01.println("Move magnet across sensor");
  OD01.println("to increase the *'s");
  //}
  //    if (diff>0.01) magnet = true;
  //    else magnet = false;
  //    if (magnet != first) {
  //      first = magnet;
  //      OD01.println(magnet);
  //      OD01.println("TEST");
  //    }

}

void calibrate_mag(void)
{
  if (!mag.isCalibrated()) //If we're not calibrated
  {
    if (!mag.isCalibrating()) //And we're not currently calibrating
    {
      OD01.clear();
      OD01.println("Entering calibration...");
      mag.enterCalMode(); //This sets the output data rate to the highest possible and puts the mag sensor in active mode
    }
    else
    {
      //Must call every loop while calibrating to collect calibration data
      //This will automatically exit calibration
      //You can terminate calibration early by calling mag.exitCalMode();
      mag.calibrate();
    }
  }

  else
  {
    calibration_flag = true;
    OD01.print("Calibrated!");
  }
}

