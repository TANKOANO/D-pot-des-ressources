/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_FlightControl_QuadFlightControl_H_
#define SWAN_FlightControl_QuadFlightControl_H_

#include "YawControl_QuadFlightControl.h"

typedef struct Ctx_FlightControl_QuadFlightControl {
  outC_PID_QuadFlightControl /* $PIDRoll: */ Ctx_PID1;
  outC_PID_QuadFlightControl /* $PIDPitch: */ Ctx_PID2;
  outC_YawControl_QuadFlightControl /* #1212: */ Ctx_YawControl1;
} outC_FlightControl_QuadFlightControl;

/* QuadFlightControl::FlightControl */
extern void FlightControl_QuadFlightControl(
  /* desiredAttitude */
  const AttitudeType_QuadTypes *desiredAttitude,
  /* desiredVerticalAcceleration */swan_float32 desiredVerticalAcceleration,
  /* currentAttitude */
  const AttitudeType_QuadTypes *currentAttitude,
  /* isReset */swan_bool isReset,
  MotorHealth_QuadTypes g1_motorHealthState,
  MotorHealth_QuadTypes g2_motorHealthState,
  MotorHealth_QuadTypes g3_motorHealthState,
  MotorHealth_QuadTypes g4_motorHealthState,
  /* attitudeCmd */AttitudeType_QuadTypes * restrict attitudeCmd,
  /* thrustControlCmd */swan_float32 * restrict thrustControlCmd,
  outC_FlightControl_QuadFlightControl * restrict outC);

#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
extern void FlightControl_reset_QuadFlightControl(
  outC_FlightControl_QuadFlightControl * restrict outC);
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */

#ifndef SWAN_USER_DEFINED_INIT
extern void FlightControl_init_QuadFlightControl(
  outC_FlightControl_QuadFlightControl * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_FlightControl_QuadFlightControl_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** FlightControl_QuadFlightControl.h
*************************************************************$ */
