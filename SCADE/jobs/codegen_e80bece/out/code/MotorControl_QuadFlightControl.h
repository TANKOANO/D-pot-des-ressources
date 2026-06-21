/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_MotorControl_QuadFlightControl_H_
#define SWAN_MotorControl_QuadFlightControl_H_

#include "CheckMotorHealth_QuadFlightControl.h"

typedef struct Ctx_MotorControl_QuadFlightControl {
  outC_CheckMotorHealth_QuadFlightControl /* $CheckRL: */ Ctx_CheckRL;
  outC_CheckMotorHealth_QuadFlightControl /* $CheckRR: */ Ctx_CheckRR;
  outC_CheckMotorHealth_QuadFlightControl /* $CheckFR: */ Ctx_CheckFR;
  outC_CheckMotorHealth_QuadFlightControl /* $CheckFL: */ Ctx_CheckFL;
} outC_MotorControl_QuadFlightControl;

/* QuadFlightControl::MotorControl */
extern void MotorControl_QuadFlightControl(
  /* attitudeCmd */
  const AttitudeType_QuadTypes *attitudeCmd,
  /* thrustControlCmd */swan_float32 thrustControlCmd,
  swan_bool g1_motorStates,
  swan_bool g2_motorStates,
  swan_bool g3_motorStates,
  swan_bool g4_motorStates,
  MotorHealth_QuadTypes * restrict g1_motorHealthStates,
  MotorHealth_QuadTypes * restrict g2_motorHealthStates,
  MotorHealth_QuadTypes * restrict g3_motorHealthStates,
  MotorHealth_QuadTypes * restrict g4_motorHealthStates,
  swan_float32 * restrict g1_rotorCmd,
  swan_float32 * restrict g2_rotorCmd,
  swan_float32 * restrict g3_rotorCmd,
  swan_float32 * restrict g4_rotorCmd,
  outC_MotorControl_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void MotorControl_reset_QuadFlightControl(
  outC_MotorControl_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void MotorControl_init_QuadFlightControl(
  outC_MotorControl_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_MotorControl_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** MotorControl_QuadFlightControl.h
*************************************************************$ */
