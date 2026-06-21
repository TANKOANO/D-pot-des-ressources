/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "CheckMotorHealth_QuadFlightControl.h"

/* QuadFlightControl::CheckMotorHealth */
void CheckMotorHealth_QuadFlightControl(
  /* isMotorFaulty */swan_bool isMotorFaulty,
  /* motorHealthState */MotorHealth_QuadTypes * restrict motorHealthState,
  outC_CheckMotorHealth_QuadFlightControl * restrict outC)
{
  SSM_ST_MotorHealthManagement x1;
  swan_bool x2;
  swan_bool x3;

  switch (outC->mem1) {
    case SSM_st_Failure_MotorHealthManagement :
      if (outC->mem2) {
        /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */
        Times_reset_Flows_ti8(&outC->Ctx_Times2);
      }
      if (isMotorFaulty) {
        /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */
        Times_reset_Flows_ti8(&outC->Ctx_Times2);
      }
      /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */
      Times_Flows_ti8(
        swan_lit_int8(20),
        swan_true,
        &outC->mem2,
        &outC->Ctx_Times2);
      if (outC->mem2) {
        x1 = SSM_st_Nominal_MotorHealthManagement;
      }
      else {
        x1 = SSM_st_Failure_MotorHealthManagement;
      }
      break;
    case SSM_st_Abnormal_MotorHealthManagement :
      x3 = !isMotorFaulty;
      if (outC->mem2) {
        /* $MotorHealthManagement:Abnormal:<2>:$(?-0): */
        Times_reset_Flows_ti8(&outC->Ctx_Times1);
      }
      /* $MotorHealthManagement:Abnormal:<2>:$(?-0): */
      Times_Flows_ti8(swan_lit_int8(20), swan_true, &x2, &outC->Ctx_Times1);
      outC->mem2 = x3 || x2;
      if (x3) {
        x1 = SSM_st_Nominal_MotorHealthManagement;
      }
      else if (x2) {
        x1 = SSM_st_Failure_MotorHealthManagement;
      }
      else {
        x1 = SSM_st_Abnormal_MotorHealthManagement;
      }
      break;
    case SSM_st_Nominal_MotorHealthManagement :
      outC->mem2 = isMotorFaulty;
      if (isMotorFaulty) {
        x1 = SSM_st_Abnormal_MotorHealthManagement;
      }
      else {
        x1 = SSM_st_Nominal_MotorHealthManagement;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  switch (x1) {
    case SSM_st_Failure_MotorHealthManagement :
      outC->mem1 = SSM_st_Failure_MotorHealthManagement;
      *motorHealthState = FAILURE;
      break;
    case SSM_st_Abnormal_MotorHealthManagement :
      outC->mem1 = SSM_st_Abnormal_MotorHealthManagement;
      *motorHealthState = ABNORMAL;
      break;
    case SSM_st_Nominal_MotorHealthManagement :
      outC->mem1 = SSM_st_Nominal_MotorHealthManagement;
      *motorHealthState = NOMINAL;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef SWAN_USER_DEFINED_INIT
void CheckMotorHealth_init_QuadFlightControl(
  outC_CheckMotorHealth_QuadFlightControl * restrict outC)
{
  /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */
  Times_init_Flows_ti8(&outC->Ctx_Times2);
  /* $MotorHealthManagement:Abnormal:<2>:$(?-0): */
  Times_init_Flows_ti8(&outC->Ctx_Times1);
  outC->mem2 = swan_false;
  outC->mem1 = SSM_st_Nominal_MotorHealthManagement;
}
#endif /* SWAN_USER_DEFINED_INIT */


#ifndef SWAN_NO_EXTERN_CALL_TO_RESET
void CheckMotorHealth_reset_QuadFlightControl(
  outC_CheckMotorHealth_QuadFlightControl * restrict outC)
{
  /* $MotorHealthManagement:Failure:<1>:$(?-0-0): */
  Times_reset_Flows_ti8(&outC->Ctx_Times2);
  /* $MotorHealthManagement:Abnormal:<2>:$(?-0): */
  Times_reset_Flows_ti8(&outC->Ctx_Times1);
  outC->mem2 = swan_false;
  outC->mem1 = SSM_st_Nominal_MotorHealthManagement;
}
#endif /* SWAN_NO_EXTERN_CALL_TO_RESET */




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** CheckMotorHealth_QuadFlightControl.c
*************************************************************$ */
