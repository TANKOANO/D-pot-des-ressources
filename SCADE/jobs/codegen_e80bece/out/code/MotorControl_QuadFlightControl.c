/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "RotorControl_QuadFlightControl.h"
#include "RotateXY_QuadUtils.h"
#include "MotorControl_QuadFlightControl.h"

/* QuadFlightControl::MotorControl */
void MotorControl_QuadFlightControl(
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
  outC_MotorControl_QuadFlightControl * restrict outC)
{
  swan_float32 x1;
  swan_float32 x2;
  swan_float32 x3;
  swan_float32 x4;
  swan_float32 x5;

  if (thrustControlCmd >= THRUST_HIGH_LIMIT_QuadFlightControl) {
    x5 = THRUST_HIGH_LIMIT_QuadFlightControl;
  }
  else if (thrustControlCmd <= swan_lit_float32(0.)) {
    x5 = swan_lit_float32(0.);
  }
  else {
    x5 = thrustControlCmd;
  }
  /* $CheckRL: */
  CheckMotorHealth_QuadFlightControl(
    g3_motorStates,
    g3_motorHealthStates,
    &outC->Ctx_CheckRL);
  /* $CheckRR: */
  CheckMotorHealth_QuadFlightControl(
    g4_motorStates,
    g4_motorHealthStates,
    &outC->Ctx_CheckRR);
  /* $CheckFR: */
  CheckMotorHealth_QuadFlightControl(
    g2_motorStates,
    g2_motorHealthStates,
    &outC->Ctx_CheckFR);
  /* $CheckFL: */
  CheckMotorHealth_QuadFlightControl(
    g1_motorStates,
    g1_motorHealthStates,
    &outC->Ctx_CheckFL);
  x4 = - YAW_LIMIT_QuadFlightControl;
  if (attitudeCmd->yaw >= YAW_LIMIT_QuadFlightControl) {
    x4 = YAW_LIMIT_QuadFlightControl;
  }
  else if (!(attitudeCmd->yaw <= x4)) {
    x4 = attitudeCmd->yaw;
  }
  x3 = - ROTATE_LIMIT_QuadFlightControl;
  /* #1126: */
  RotateXY_QuadUtils(
    attitudeCmd->roll,
    attitudeCmd->pitch,
    PI_QuadFlightControl / swan_lit_float32(4),
    &x1,
    &x2);
  if (x2 >= ROTATE_LIMIT_QuadFlightControl) {
    x2 = ROTATE_LIMIT_QuadFlightControl;
  }
  else if (x2 <= x3) {
    x2 = x3;
  }
  if (x1 >= ROTATE_LIMIT_QuadFlightControl) {
    x1 = ROTATE_LIMIT_QuadFlightControl;
  }
  else if (x1 <= x3) {
    x1 = x3;
  }
  /* #1128: */
  RotorControl_QuadFlightControl(
    x5,
    x1,
    x2,
    x4,
    g1_rotorCmd,
    g2_rotorCmd,
    g3_rotorCmd,
    g4_rotorCmd);
}

#ifndef SWAN_USER_DEFINED_INIT
void MotorControl_init_QuadFlightControl(
  outC_MotorControl_QuadFlightControl * restrict outC)
{
  /* $CheckFL: */ CheckMotorHealth_init_QuadFlightControl(&outC->Ctx_CheckFL);
  /* $CheckFR: */ CheckMotorHealth_init_QuadFlightControl(&outC->Ctx_CheckFR);
  /* $CheckRR: */ CheckMotorHealth_init_QuadFlightControl(&outC->Ctx_CheckRR);
  /* $CheckRL: */ CheckMotorHealth_init_QuadFlightControl(&outC->Ctx_CheckRL);
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void MotorControl_reset_QuadFlightControl(
  outC_MotorControl_QuadFlightControl * restrict outC)
{
  /* $CheckFL: */ CheckMotorHealth_reset_QuadFlightControl(&outC->Ctx_CheckFL);
  /* $CheckFR: */ CheckMotorHealth_reset_QuadFlightControl(&outC->Ctx_CheckFR);
  /* $CheckRR: */ CheckMotorHealth_reset_QuadFlightControl(&outC->Ctx_CheckRR);
  /* $CheckRL: */ CheckMotorHealth_reset_QuadFlightControl(&outC->Ctx_CheckRL);
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** MotorControl_QuadFlightControl.c
*************************************************************$ */
