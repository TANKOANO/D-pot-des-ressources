/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "YawControl_QuadFlightControl.h"

/* QuadFlightControl::YawControl */
void YawControl_QuadFlightControl(
  /* targetYaw */swan_float32 targetYaw,
  /* currentYaw */swan_float32 currentYaw,
  /* targetR */swan_float32 * restrict targetR,
  outC_YawControl_QuadFlightControl * restrict outC)
{
  swan_bool x1;
  swan_float32 x2;
  swan_float32 x3;
  swan_float32 x4;
  swan_float32 x5;
  swan_float32 x6;

  x2 = targetYaw - currentYaw;
  if (!(swan_lit_float32(0) <= x2)) {
    x2 = - x2;
  }
  x1 = x2 > PI_QuadFlightControl;
  if (x1) {
    x3 = targetYaw - currentYaw;
    if (swan_lit_float32(0) <= x3) {
      x6 = x3;
    }
    else {
      x6 = - x3;
    }
    x5 = x3 / x6 * (swan_lit_float32(2.) * PI_QuadFlightControl) + currentYaw;
  }
  else {
    x5 = currentYaw;
  }
  /* #1473: */
  PID_QuadFlightControl(
    targetYaw,
    x5,
    YAW_KP_QuadFlightControl,
    YAW_KI_QuadFlightControl,
    YAW_KD_QuadFlightControl,
    PI_QuadFlightControl / swan_lit_float32(8),
    swan_false,
    &x4,
    &outC->Ctx_PID1);
  *targetR = - x4;
}

#ifndef SWAN_USER_DEFINED_INIT
void YawControl_init_QuadFlightControl(
  outC_YawControl_QuadFlightControl * restrict outC)
{
  /* #1473: */ PID_init_QuadFlightControl(&outC->Ctx_PID1);
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void YawControl_reset_QuadFlightControl(
  outC_YawControl_QuadFlightControl * restrict outC)
{
  /* #1473: */ PID_reset_QuadFlightControl(&outC->Ctx_PID1);
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** YawControl_QuadFlightControl.c
*************************************************************$ */
