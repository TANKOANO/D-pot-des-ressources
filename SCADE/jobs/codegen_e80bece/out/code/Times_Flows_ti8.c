/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_sensors.h"
#include "swan_consts.h"
#include "Times_Flows_ti8.h"

/* Flows::Times */
void Times_Flows_ti8(
  /* count */swan_int8 count,
  /* in */swan_bool in,
  /* out */swan_bool * restrict out,
  outC_Times_Flows_ti8 * restrict outC)
{
  swan_bool x1;

  if (outC->mem2) {
    outC->mem1 = count;
  }
  if (outC->mem2) {
    outC->mem2 = swan_false;
  }
  x1 = in && outC->mem1 >= swan_lit_int8(0);
  if (x1) {
    outC->mem1 = outC->mem1 - swan_lit_int8(1);
  }
  *out = in && outC->mem1 == swan_lit_int8(0);
}

#ifndef SWAN_USER_DEFINED_INIT
void Times_init_Flows_ti8(outC_Times_Flows_ti8 * restrict outC)
{
  outC->mem1 = swan_lit_int8(0);
  outC->mem2 = swan_true;
}
#endif /* SWAN_USER_DEFINED_INIT */


void Times_reset_Flows_ti8(outC_Times_Flows_ti8 * restrict outC)
{
  outC->mem2 = swan_true;
}




/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Times_Flows_ti8.c
*************************************************************$ */
