/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "QuadFlightControl_QuadFlightControl.h"

/* QuadFlightControl::QuadFlightControl */
void QuadFlightControl_QuadFlightControl(
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
  outC_QuadFlightControl_QuadFlightControl * restrict outC)
{
  swan_float32 x1;
  AttitudeType_QuadTypes x2;

  /* #1382: */
  FlightControl_QuadFlightControl(
    desiredAttitude,
    desiredVerticalAccel,
    currentAttitude,
    isReset,
    outC->mem1,
    outC->mem2,
    outC->mem3,
    outC->mem4,
    &x2,
    &x1,
    &outC->Ctx_FlightControl1);
  /* #1376: */
  MotorControl_QuadFlightControl(
    (const AttitudeType_QuadTypes *) &x2,
    x1,
    g1_motorStates,
    g2_motorStates,
    g3_motorStates,
    g4_motorStates,
    g1_motorHealthState,
    g2_motorHealthState,
    g3_motorHealthState,
    g4_motorHealthState,
    g1_rotorCmd,
    g2_rotorCmd,
    g3_rotorCmd,
    g4_rotorCmd,
    &outC->Ctx_MotorControl1);
  outC->mem4 = *g4_motorHealthState;
  outC->mem3 = *g3_motorHealthState;
  outC->mem2 = *g2_motorHealthState;
  outC->mem1 = *g1_motorHealthState;
}

#ifndef SWAN_USER_DEFINED_INIT
void QuadFlightControl_init_QuadFlightControl(
  outC_QuadFlightControl_QuadFlightControl * restrict outC)
{
  outC->mem1 = NOMINAL;
  outC->mem2 = NOMINAL;
  outC->mem3 = NOMINAL;
  outC->mem4 = NOMINAL;
  /* #1376: */ MotorControl_init_QuadFlightControl(&outC->Ctx_MotorControl1);
  /* #1382: */ FlightControl_init_QuadFlightControl(&outC->Ctx_FlightControl1);
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void QuadFlightControl_reset_QuadFlightControl(
  outC_QuadFlightControl_QuadFlightControl * restrict outC)
{
  outC->mem1 = NOMINAL;
  outC->mem2 = NOMINAL;
  outC->mem3 = NOMINAL;
  outC->mem4 = NOMINAL;
  /* #1376: */ MotorControl_reset_QuadFlightControl(&outC->Ctx_MotorControl1);
  /* #1382: */ FlightControl_reset_QuadFlightControl(&outC->Ctx_FlightControl1);
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** QuadFlightControl_QuadFlightControl.c
*************************************************************$ */
