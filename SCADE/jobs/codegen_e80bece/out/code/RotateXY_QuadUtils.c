/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_imported_functions.h"
#include "swan_sensors.h"
#include "swan_consts.h"
#include "RotateXY_QuadUtils.h"

/* QuadUtils::RotateXY */
void RotateXY_QuadUtils(
  /* x */swan_float32 x,
  /* y */swan_float32 y,
  /* a */swan_float32 a,
  /* xo */swan_float32 * restrict xo,
  /* yo */swan_float32 * restrict yo)
{
  swan_float32 x1;
  swan_float32 x2;

  x1 = /* #1490: */ Cosine32_Math_Trigo_StdC(a);
  x2 = /* #1495: */ Sine32_Math_Trigo_StdC(a);
  *xo = x * x1 - y * x2;
  *yo = x1 * y + x2 * x;
}



/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** RotateXY_QuadUtils.c
*************************************************************$ */
