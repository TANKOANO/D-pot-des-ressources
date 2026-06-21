/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "Integrator_QuadUtils_Tf32.h"

/* QuadUtils::Integrator */
void Integrator_QuadUtils_Tf32(
  /* i */swan_float32 i,
  /* x */swan_float32 x,
  outC_Integrator_QuadUtils_Tf32 * restrict outC)
{
  if (outC->mem1) {
    outC->y = i;
  }
  if (outC->mem1) {
    outC->mem1 = swan_false;
  }
  outC->y = x + outC->y;
}

#ifndef SWAN_USER_DEFINED_INIT
void Integrator_init_QuadUtils_Tf32(
  outC_Integrator_QuadUtils_Tf32 * restrict outC)
{
  outC->y = swan_lit_float32(0.0);
  outC->mem1 = swan_true;
}
#endif /* SWAN_USER_DEFINED_INIT */


void Integrator_reset_QuadUtils_Tf32(
  outC_Integrator_QuadUtils_Tf32 * restrict outC)
{
  outC->mem1 = swan_true;
}




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Integrator_QuadUtils_Tf32.c
*************************************************************$ */
