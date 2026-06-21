/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_PID_QuadFlightControl_H_
#define SWAN_PID_QuadFlightControl_H_

#include "Integrator_QuadUtils_Tf32.h"

typedef struct Ctx_PID_QuadFlightControl {
  swan_float32 mem1;
  swan_bool mem2;
  outC_Integrator_QuadUtils_Tf32 /* #5: */ Ctx_Integrator1;
} outC_PID_QuadFlightControl;

/* QuadFlightControl::PID */
extern void PID_QuadFlightControl(
  /* target */swan_float32 target,
  /* current */swan_float32 current,
  /* kp */swan_float32 kp,
  /* ki */swan_float32 ki,
  /* kd */swan_float32 kd,
  /* errorLim */swan_float32 errorLim,
  /* reset */swan_bool reset,
  /* control */swan_float32 * restrict control,
  outC_PID_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void PID_reset_QuadFlightControl(
  outC_PID_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void PID_init_QuadFlightControl(
  outC_PID_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_PID_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** PID_QuadFlightControl.h
*************************************************************$ */
