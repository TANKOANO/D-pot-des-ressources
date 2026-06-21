/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "PitchRollFilter_QuadFlightControl.h"

/* QuadFlightControl::PitchRollFilter */
swan_float32 PitchRollFilter_QuadFlightControl(
  /* in */swan_float32 in,
  /* min */swan_float32 min,
  /* max */swan_float32 max,
  /* band */swan_float32 band)
{
  swan_bool x1;
  swan_float32 x2;
  /* out */
  swan_float32 out;

  if (in >= max) {
    out = max;
  }
  else if (in <= min) {
    out = min;
  }
  else {
    out = in;
  }
  if (swan_lit_float32(0) <= out) {
    x2 = out;
  }
  else {
    x2 = - out;
  }
  x1 = out != in;
  if (x2 < band) {
    out = swan_lit_float32(0.0);
  }
  return out;
}



/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** PitchRollFilter_QuadFlightControl.c
*************************************************************$ */
