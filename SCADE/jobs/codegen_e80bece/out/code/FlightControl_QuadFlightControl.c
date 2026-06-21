/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_imported_functions.h"
#include "swan_sensors.h"
#include "swan_consts.h"
#include "PitchRollFilter_QuadFlightControl.h"
#include "FlightControl_QuadFlightControl.h"

/* QuadFlightControl::FlightControl */
void FlightControl_QuadFlightControl(
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
  outC_FlightControl_QuadFlightControl * restrict outC)
{
  swan_float32 x1;
  swan_float32 x2;
  swan_float32 x3;
  swan_float32 x4;
  swan_float32 x5;
  swan_float32 x6;
  swan_bool x7;
  swan_float32 x8;
  swan_float32 x9;
  swan_float32 x10;
  swan_float32 x11;
  swan_float32 x12;
  swan_float32 x13;
  swan_float32 x14;
  swan_float32 x15;
  swan_float32 x16;
  swan_float32 x17;

  /* #1212: */
  YawControl_QuadFlightControl(
    desiredAttitude->yaw,
    currentAttitude->yaw,
    &x3,
    &outC->Ctx_YawControl1);
  x7 = g1_motorHealthState == FAILURE || g2_motorHealthState == FAILURE ||
    g3_motorHealthState == FAILURE || g4_motorHealthState == FAILURE;
  x2 = /* $FilterRoll: */
    PitchRollFilter_QuadFlightControl(
      currentAttitude->roll,
      - PI_QuadFlightControl / swan_lit_float32(2),
      PI_QuadFlightControl / swan_lit_float32(2),
      swan_lit_float32(0.01));
  x5 = /* #1194: */ Cosine32_Math_Trigo_StdC(x2);
  x1 = /* $FilterPitch: */
    PitchRollFilter_QuadFlightControl(
      currentAttitude->pitch,
      - PI_QuadFlightControl / swan_lit_float32(2),
      PI_QuadFlightControl / swan_lit_float32(2),
      swan_lit_float32(0.01));
  x6 = /* #1197: */ Cosine32_Math_Trigo_StdC(x1);
  *thrustControlCmd = (desiredVerticalAcceleration + G_QuadFlightControl) *
    MASS_QuadFlightControl / (x6 * x6 * (x5 * x5));
  if (x7) {
    x15 = PI_QuadFlightControl / swan_lit_float32(16);
    x16 = swan_lit_float32(0) - x15;
    x17 = x15 + swan_lit_float32(0);
    x12 = PI_QuadFlightControl / swan_lit_float32(12);
    x13 = swan_lit_float32(0) - x12;
    x14 = x12 + swan_lit_float32(0);
    if (desiredAttitude->roll >= x17) {
      x16 = x17;
    }
    else if (!(desiredAttitude->roll <= x16)) {
      x16 = desiredAttitude->roll;
    }
    if (desiredAttitude->pitch >= x14) {
      x13 = x14;
    }
    else if (!(desiredAttitude->pitch <= x13)) {
      x13 = desiredAttitude->pitch;
    }
  }
  else {
    x10 = PI_QuadFlightControl / swan_lit_float32(8);
    x16 = swan_lit_float32(0) - x10;
    x11 = x10 + swan_lit_float32(0);
    if (desiredAttitude->roll >= x11) {
      x16 = x11;
    }
    else if (!(desiredAttitude->roll <= x16)) {
      x16 = desiredAttitude->roll;
    }
    x8 = PI_QuadFlightControl / swan_lit_float32(6);
    x13 = swan_lit_float32(0) - x8;
    x9 = x8 + swan_lit_float32(0);
    if (desiredAttitude->pitch >= x9) {
      x13 = x9;
    }
    else if (!(desiredAttitude->pitch <= x13)) {
      x13 = desiredAttitude->pitch;
    }
  }
  /* $PIDPitch: */
  PID_QuadFlightControl(
    x13,
    x1,
    PITCH_KP_QuadFlightControl,
    PITCH_KI_QuadFlightControl,
    PITCH_KD_QuadFlightControl,
    swan_lit_float32(10.0),
    isReset,
    &x4,
    &outC->Ctx_PID2);
  if (!(swan_lit_float32(0) <= x1)) {
    x1 = - x1;
  }
  attitudeCmd->pitch = - x4;
  /* $PIDRoll: */
  PID_QuadFlightControl(
    x16,
    x2,
    ROLL_KP_QuadFlightControl,
    ROLL_KI_QuadFlightControl,
    ROLL_KD_QuadFlightControl,
    swan_lit_float32(10.),
    isReset,
    &attitudeCmd->roll,
    &outC->Ctx_PID1);
  if (!(swan_lit_float32(0) <= x2)) {
    x2 = - x2;
  }
  if (x2 < swan_lit_float32(1.5) && x1 < swan_lit_float32(1.5)) {
    attitudeCmd->yaw = - (x3 * swan_lit_float32(2.0));
  }
  else {
    attitudeCmd->yaw = swan_lit_float32(0.0);
  }
}

#ifndef SWAN_USER_DEFINED_INIT
void FlightControl_init_QuadFlightControl(
  outC_FlightControl_QuadFlightControl * restrict outC)
{
  /* #1212: */ YawControl_init_QuadFlightControl(&outC->Ctx_YawControl1);
  /* $PIDPitch: */ PID_init_QuadFlightControl(&outC->Ctx_PID2);
  /* $PIDRoll: */ PID_init_QuadFlightControl(&outC->Ctx_PID1);
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void FlightControl_reset_QuadFlightControl(
  outC_FlightControl_QuadFlightControl * restrict outC)
{
  /* #1212: */ YawControl_reset_QuadFlightControl(&outC->Ctx_YawControl1);
  /* $PIDPitch: */ PID_reset_QuadFlightControl(&outC->Ctx_PID2);
  /* $PIDRoll: */ PID_reset_QuadFlightControl(&outC->Ctx_PID1);
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** FlightControl_QuadFlightControl.c
*************************************************************$ */
