/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "Max_Math_Common_Tf32.h"

/* Math::Common::Max */
swan_float32 Max_Math_Common_Tf32(/* x */swan_float32 x, /* y */swan_float32 y)
{
  /* v */
  swan_float32 v;

  if (x > y) {
    v = x;
  }
  else {
    v = y;
  }
  return v;
}



/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Max_Math_Common_Tf32.c
*************************************************************$ */
