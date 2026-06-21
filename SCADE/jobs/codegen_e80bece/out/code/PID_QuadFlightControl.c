/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "PID_QuadFlightControl.h"

/* QuadFlightControl::PID */
void PID_QuadFlightControl(
  /* target */swan_float32 target,
  /* current */swan_float32 current,
  /* kp */swan_float32 kp,
  /* ki */swan_float32 ki,
  /* kd */swan_float32 kd,
  /* errorLim */swan_float32 errorLim,
  /* reset */swan_bool reset,
  /* control */swan_float32 * restrict control,
  outC_PID_QuadFlightControl * restrict outC)
{
  swan_float32 x1;
  swan_float32 x2;
  swan_float32 x3;
  swan_float32 x4;

  x1 = target - current;
  if (swan_lit_float32(0) <= x1) {
    x4 = x1;
  }
  else {
    x4 = - x1;
  }
  if (x4 < errorLim) {
    x3 = x1 * T_CYCLE_QuadFlightControl;
  }
  else {
    x3 = swan_lit_float32(0.0);
  }
  if (outC->mem2) {
    x2 = swan_lit_float32(0.0);
  }
  else {
    x2 = (x1 - outC->mem1) * kd / T_CYCLE_QuadFlightControl;
  }
  if (outC->mem2) {
    outC->mem2 = swan_false;
  }
  outC->mem1 = x1;
  if (reset) {
    /* #5: */ Integrator_reset_QuadUtils_Tf32(&outC->Ctx_Integrator1);
  }
  /* #5: */
  Integrator_QuadUtils_Tf32(swan_lit_float32(0.0), x3, &outC->Ctx_Integrator1);
  *control = x1 * kp + outC->Ctx_Integrator1.y * ki + x2;
}

#ifndef SWAN_USER_DEFINED_INIT
void PID_init_QuadFlightControl(outC_PID_QuadFlightControl * restrict outC)
{
  /* #5: */ Integrator_init_QuadUtils_Tf32(&outC->Ctx_Integrator1);
  outC->mem1 = swan_lit_float32(0.0);
  outC->mem2 = swan_true;
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void PID_reset_QuadFlightControl(outC_PID_QuadFlightControl * restrict outC)
{
  /* #5: */ Integrator_reset_QuadUtils_Tf32(&outC->Ctx_Integrator1);
  outC->mem2 = swan_true;
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** PID_QuadFlightControl.c
*************************************************************$ */
