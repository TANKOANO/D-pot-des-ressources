/*
 * sldemo_wheelspeed_absbrake.c
 *
 * Code generation for model "sldemo_wheelspeed_absbrake".
 *
 * Model version              : 8.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Apr 21 05:24:27 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sldemo_wheelspeed_absbrake.h"
#include "sldemo_wheelspeed_absbrake_private.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_sldemo_wheelspeed_absbrake_T sldemo_wheelspeed_absbrake_B;

/* Continuous states */
X_sldemo_wheelspeed_absbrake_T sldemo_wheelspeed_absbrake_X;

/* Disabled State Vector */
XDis_sldemo_wheelspeed_absbra_T sldemo_wheelspeed_absbrake_XDis;

/* Block states (default storage) */
DW_sldemo_wheelspeed_absbrake_T sldemo_wheelspeed_absbrake_DW;

/* External inputs (root inport signals with default storage) */
ExtU_sldemo_wheelspeed_absbra_T sldemo_wheelspeed_absbrake_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_sldemo_wheelspeed_absbra_T sldemo_wheelspeed_absbrake_Y;

/* Real-time model */
static RT_MODEL_sldemo_wheelspeed_ab_T sldemo_wheelspeed_absbrake_M_;
RT_MODEL_sldemo_wheelspeed_ab_T *const sldemo_wheelspeed_absbrake_M =
  &sldemo_wheelspeed_absbrake_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sldemo_wheelspeed_absbrake_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  sldemo_wheelspeed_absbrake_step();
  sldemo_wheelspeed_absbrake_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  sldemo_wheelspeed_absbrake_step();
  sldemo_wheelspeed_absbrake_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void sldemo_wheelspeed_absbrake_step(void)
{
  if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    /* set solver stop time */
    if (!(sldemo_wheelspeed_absbrake_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sldemo_wheelspeed_absbrake_M->solverInfo,
                            ((sldemo_wheelspeed_absbrake_M->Timing.clockTickH0 +
        1) * sldemo_wheelspeed_absbrake_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sldemo_wheelspeed_absbrake_M->solverInfo,
                            ((sldemo_wheelspeed_absbrake_M->Timing.clockTick0 +
        1) * sldemo_wheelspeed_absbrake_M->Timing.stepSize0 +
        sldemo_wheelspeed_absbrake_M->Timing.clockTickH0 *
        sldemo_wheelspeed_absbrake_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    sldemo_wheelspeed_absbrake_M->Timing.t[0] = rtsiGetT
      (&sldemo_wheelspeed_absbrake_M->solverInfo);
  }

  /* Integrator: '<S1>/Brake pressure' */
  /* Limited  Integrator  */
  if (sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE >= 1500.0) {
    sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE = 1500.0;
  } else if (sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE <= 0.0) {
    sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE = 0.0;
  }

  /* Outport: '<Root>/Bp' incorporates:
   *  Integrator: '<S1>/Brake pressure'
   */
  sldemo_wheelspeed_absbrake_Y.Bp =
    sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE;
  if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    /* UnitDelay: '<Root>/Unit Delay' */
    sldemo_wheelspeed_absbrake_B.UnitDelay =
      sldemo_wheelspeed_absbrake_DW.UnitDelay_DSTATE;
  }

  /* Gain: '<Root>/1//I' incorporates:
   *  Integrator: '<S1>/Brake pressure'
   *  Sum: '<Root>/Sum'
   */
  sldemo_wheelspeed_absbrake_B.Wa = (sldemo_wheelspeed_absbrake_B.UnitDelay -
    sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE) * 0.2;

  /* Outport: '<Root>/Wa' */
  sldemo_wheelspeed_absbrake_Y.Wa = sldemo_wheelspeed_absbrake_B.Wa;
  if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    /* Outport: '<Root>/WheelSpeed' incorporates:
     *  DiscreteIntegrator: '<Root>/Wheel Speed'
     */
    sldemo_wheelspeed_absbrake_Y.WheelSpeed = 0.005 *
      sldemo_wheelspeed_absbrake_B.Wa +
      sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE;

    /* DiscreteIntegrator: '<Root>/Wheel Speed' incorporates:
     *  Outport: '<Root>/WheelSpeed'
     */
    if (sldemo_wheelspeed_absbrake_Y.WheelSpeed > 1000.0) {
      sldemo_wheelspeed_absbrake_Y.WheelSpeed = 1000.0;
    } else if (sldemo_wheelspeed_absbrake_Y.WheelSpeed < 0.0) {
      sldemo_wheelspeed_absbrake_Y.WheelSpeed = 0.0;
    }
  }

  /* TransferFcn: '<S1>/Hydraulic Lag ' */
  sldemo_wheelspeed_absbrake_B.HydraulicLag = 10000.0 *
    sldemo_wheelspeed_absbrake_X.HydraulicLag_CSTATE;
  if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
       *  Inport: '<Root>/Tire Torque'
       */
      sldemo_wheelspeed_absbrake_DW.UnitDelay_DSTATE =
        sldemo_wheelspeed_absbrake_U.TireTorque;

      /* Update for DiscreteIntegrator: '<Root>/Wheel Speed' incorporates:
       *  Outport: '<Root>/WheelSpeed'
       */
      sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE = 0.005 *
        sldemo_wheelspeed_absbrake_B.Wa +
        sldemo_wheelspeed_absbrake_Y.WheelSpeed;
      if (sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE > 1000.0) {
        sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE = 1000.0;
      } else if (sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE < 0.0) {
        sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE = 0.0;
      }

      /* End of Update for DiscreteIntegrator: '<Root>/Wheel Speed' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(sldemo_wheelspeed_absbrake_M)) {
    rt_ertODEUpdateContinuousStates(&sldemo_wheelspeed_absbrake_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sldemo_wheelspeed_absbrake_M->Timing.clockTick0)) {
      ++sldemo_wheelspeed_absbrake_M->Timing.clockTickH0;
    }

    sldemo_wheelspeed_absbrake_M->Timing.t[0] = rtsiGetSolverStopTime
      (&sldemo_wheelspeed_absbrake_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      sldemo_wheelspeed_absbrake_M->Timing.clockTick1++;
      if (!sldemo_wheelspeed_absbrake_M->Timing.clockTick1) {
        sldemo_wheelspeed_absbrake_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void sldemo_wheelspeed_absbrake_derivatives(void)
{
  XDot_sldemo_wheelspeed_absbra_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_sldemo_wheelspeed_absbra_T *)
             sldemo_wheelspeed_absbrake_M->derivs);

  /* Derivatives for Integrator: '<S1>/Brake pressure' */
  lsat = (sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE <= 0.0);
  usat = (sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE >= 1500.0);
  if (((!lsat) && (!usat)) || (lsat &&
       (sldemo_wheelspeed_absbrake_B.HydraulicLag > 0.0)) || (usat &&
       (sldemo_wheelspeed_absbrake_B.HydraulicLag < 0.0))) {
    _rtXdot->Brakepressure_CSTATE = sldemo_wheelspeed_absbrake_B.HydraulicLag;
  } else {
    /* in saturation */
    _rtXdot->Brakepressure_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S1>/Brake pressure' */

  /* Derivatives for TransferFcn: '<S1>/Hydraulic Lag ' incorporates:
   *  Inport: '<Root>/Controller out'
   */
  _rtXdot->HydraulicLag_CSTATE = -100.0 *
    sldemo_wheelspeed_absbrake_X.HydraulicLag_CSTATE;
  _rtXdot->HydraulicLag_CSTATE += sldemo_wheelspeed_absbrake_U.Controllerout;
}

/* Model initialize function */
void sldemo_wheelspeed_absbrake_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)sldemo_wheelspeed_absbrake_M, 0,
                sizeof(RT_MODEL_sldemo_wheelspeed_ab_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
                          &sldemo_wheelspeed_absbrake_M->Timing.simTimeStep);
    rtsiSetTPtr(&sldemo_wheelspeed_absbrake_M->solverInfo, &rtmGetTPtr
                (sldemo_wheelspeed_absbrake_M));
    rtsiSetStepSizePtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
                       &sldemo_wheelspeed_absbrake_M->Timing.stepSize0);
    rtsiSetdXPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
                 &sldemo_wheelspeed_absbrake_M->derivs);
    rtsiSetContStatesPtr(&sldemo_wheelspeed_absbrake_M->solverInfo, (real_T **)
                         &sldemo_wheelspeed_absbrake_M->contStates);
    rtsiSetNumContStatesPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
      &sldemo_wheelspeed_absbrake_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
      &sldemo_wheelspeed_absbrake_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
      &sldemo_wheelspeed_absbrake_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
      &sldemo_wheelspeed_absbrake_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
      (boolean_T**) &sldemo_wheelspeed_absbrake_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
                          (&rtmGetErrorStatus(sldemo_wheelspeed_absbrake_M)));
    rtsiSetRTModelPtr(&sldemo_wheelspeed_absbrake_M->solverInfo,
                      sldemo_wheelspeed_absbrake_M);
  }

  rtsiSetSimTimeStep(&sldemo_wheelspeed_absbrake_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&sldemo_wheelspeed_absbrake_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&sldemo_wheelspeed_absbrake_M->solverInfo, false);
  sldemo_wheelspeed_absbrake_M->intgData.y = sldemo_wheelspeed_absbrake_M->odeY;
  sldemo_wheelspeed_absbrake_M->intgData.f[0] =
    sldemo_wheelspeed_absbrake_M->odeF[0];
  sldemo_wheelspeed_absbrake_M->intgData.f[1] =
    sldemo_wheelspeed_absbrake_M->odeF[1];
  sldemo_wheelspeed_absbrake_M->intgData.f[2] =
    sldemo_wheelspeed_absbrake_M->odeF[2];
  sldemo_wheelspeed_absbrake_M->contStates = ((X_sldemo_wheelspeed_absbrake_T *)
    &sldemo_wheelspeed_absbrake_X);
  sldemo_wheelspeed_absbrake_M->contStateDisabled =
    ((XDis_sldemo_wheelspeed_absbra_T *) &sldemo_wheelspeed_absbrake_XDis);
  sldemo_wheelspeed_absbrake_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&sldemo_wheelspeed_absbrake_M->solverInfo, (void *)
                    &sldemo_wheelspeed_absbrake_M->intgData);
  rtsiSetSolverName(&sldemo_wheelspeed_absbrake_M->solverInfo,"ode3");
  rtmSetTPtr(sldemo_wheelspeed_absbrake_M,
             &sldemo_wheelspeed_absbrake_M->Timing.tArray[0]);
  sldemo_wheelspeed_absbrake_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  {
    sldemo_wheelspeed_absbrake_B.UnitDelay = 0.0;
    sldemo_wheelspeed_absbrake_B.Wa = 0.0;
    sldemo_wheelspeed_absbrake_B.HydraulicLag = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&sldemo_wheelspeed_absbrake_X, 0,
                  sizeof(X_sldemo_wheelspeed_absbrake_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&sldemo_wheelspeed_absbrake_XDis, 0,
                  sizeof(XDis_sldemo_wheelspeed_absbra_T));
  }

  /* states (dwork) */
  sldemo_wheelspeed_absbrake_DW.UnitDelay_DSTATE = 0.0;
  sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE = 0.0;

  /* external inputs */
  sldemo_wheelspeed_absbrake_U.Controllerout = 0.0;
  sldemo_wheelspeed_absbrake_U.TireTorque = 0.0;

  /* external outputs */
  sldemo_wheelspeed_absbrake_Y.Bp = 0.0;
  sldemo_wheelspeed_absbrake_Y.Wa = 0.0;
  sldemo_wheelspeed_absbrake_Y.WheelSpeed = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Brake pressure' */
  sldemo_wheelspeed_absbrake_X.Brakepressure_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  sldemo_wheelspeed_absbrake_DW.UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Wheel Speed' */
  sldemo_wheelspeed_absbrake_DW.WheelSpeed_DSTATE = 70.4;

  /* InitializeConditions for TransferFcn: '<S1>/Hydraulic Lag ' */
  sldemo_wheelspeed_absbrake_X.HydraulicLag_CSTATE = 0.0;
}

/* Model terminate function */
void sldemo_wheelspeed_absbrake_terminate(void)
{
  /* (no terminate code required) */
}
