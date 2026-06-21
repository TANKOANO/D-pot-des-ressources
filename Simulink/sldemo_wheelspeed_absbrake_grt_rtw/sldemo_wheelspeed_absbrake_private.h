/*
 * sldemo_wheelspeed_absbrake_private.h
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

#ifndef sldemo_wheelspeed_absbrake_private_h_
#define sldemo_wheelspeed_absbrake_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "sldemo_wheelspeed_absbrake_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* private model entry point functions */
extern void sldemo_wheelspeed_absbrake_derivatives(void);

#endif                               /* sldemo_wheelspeed_absbrake_private_h_ */
