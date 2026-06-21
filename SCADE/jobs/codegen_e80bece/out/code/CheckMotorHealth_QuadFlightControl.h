/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_CheckMotorHealth_QuadFlightControl_H_
#define SWAN_CheckMotorHealth_QuadFlightControl_H_

#include "Times_Flows_ti8.h"

typedef struct Ctx_CheckMotorHealth_QuadFlightControl {
  SSM_ST_MotorHealthManagement mem1;
  swan_bool mem2;
  outC_Times_Flows_ti8 /* $MotorHealthManagement:Abnormal:<2>:$(?-0): */ Ctx_Times1;
  outC_Times_Flows_ti8 /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */ Ctx_Times2;
} outC_CheckMotorHealth_QuadFlightControl;

/* QuadFlightControl::CheckMotorHealth */
extern void CheckMotorHealth_QuadFlightControl(
  /* isMotorFaulty */swan_bool isMotorFaulty,
  /* motorHealthState */MotorHealth_QuadTypes * restrict motorHealthState,
  outC_CheckMotorHealth_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void CheckMotorHealth_reset_QuadFlightControl(
  outC_CheckMotorHealth_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void CheckMotorHealth_init_QuadFlightControl(
  outC_CheckMotorHealth_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_CheckMotorHealth_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** CheckMotorHealth_QuadFlightControl.h
*************************************************************$ */
