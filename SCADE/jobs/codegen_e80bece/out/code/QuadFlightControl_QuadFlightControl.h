/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_QuadFlightControl_QuadFlightControl_H_
#define SWAN_QuadFlightControl_QuadFlightControl_H_

#include "FlightControl_QuadFlightControl.h"
#include "MotorControl_QuadFlightControl.h"

typedef struct Ctx_QuadFlightControl_QuadFlightControl {
  MotorHealth_QuadTypes mem1;
  MotorHealth_QuadTypes mem2;
  MotorHealth_QuadTypes mem3;
  MotorHealth_QuadTypes mem4;
  outC_FlightControl_QuadFlightControl /* #1382: */ Ctx_FlightControl1;
  outC_MotorControl_QuadFlightControl /* #1376: */ Ctx_MotorControl1;
} outC_QuadFlightControl_QuadFlightControl;

/* QuadFlightControl::QuadFlightControl */
extern void QuadFlightControl_QuadFlightControl(
  swan_bool g1_motorStates,
  swan_bool g2_motorStates,
  swan_bool g3_motorStates,
  swan_bool g4_motorStates,
  /* isReset */swan_bool isReset,
  /* currentAttitude */
  const AttitudeType_QuadTypes *currentAttitude,
  /* desiredAttitude */
  const AttitudeType_QuadTypes *desiredAttitude,
  /* desiredVerticalAccel */swan_float32 desiredVerticalAccel,
  MotorHealth_QuadTypes * restrict g1_motorHealthState,
  MotorHealth_QuadTypes * restrict g2_motorHealthState,
  MotorHealth_QuadTypes * restrict g3_motorHealthState,
  MotorHealth_QuadTypes * restrict g4_motorHealthState,
  swan_float32 * restrict g1_rotorCmd,
  swan_float32 * restrict g2_rotorCmd,
  swan_float32 * restrict g3_rotorCmd,
  swan_float32 * restrict g4_rotorCmd,
  outC_QuadFlightControl_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void QuadFlightControl_reset_QuadFlightControl(
  outC_QuadFlightControl_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void QuadFlightControl_init_QuadFlightControl(
  outC_QuadFlightControl_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_QuadFlightControl_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** QuadFlightControl_QuadFlightControl.h
*************************************************************$ */
