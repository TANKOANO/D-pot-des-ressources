/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_YawControl_QuadFlightControl_H_
#define SWAN_YawControl_QuadFlightControl_H_

#include "PID_QuadFlightControl.h"

typedef struct Ctx_YawControl_QuadFlightControl {
  outC_PID_QuadFlightControl /* #1473: */ Ctx_PID1;
} outC_YawControl_QuadFlightControl;

/* QuadFlightControl::YawControl */
extern void YawControl_QuadFlightControl(
  /* targetYaw */swan_float32 targetYaw,
  /* currentYaw */swan_float32 currentYaw,
  /* targetR */swan_float32 * restrict targetR,
  outC_YawControl_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void YawControl_reset_QuadFlightControl(
  outC_YawControl_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void YawControl_init_QuadFlightControl(
  outC_YawControl_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_YawControl_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** YawControl_QuadFlightControl.h
*************************************************************$ */
