/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_Times_Flows_ti8_H_
#define SWAN_Times_Flows_ti8_H_

#include "swan_types.h"

typedef struct Ctx_Times_Flows_ti8 {
  swan_int8 mem1;
  swan_bool mem2;
} outC_Times_Flows_ti8;

/* Flows::Times */
extern void Times_Flows_ti8(
  /* count */swan_int8 count,
  /* in */swan_bool in,
  /* out */swan_bool * restrict out,
  outC_Times_Flows_ti8 * restrict outC);

extern void Times_reset_Flows_ti8(outC_Times_Flows_ti8 * restrict outC);

#ifndef SWAN_USER_DEFINED_INIT
extern void Times_init_Flows_ti8(outC_Times_Flows_ti8 * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_Times_Flows_ti8_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Times_Flows_ti8.h
*************************************************************$ */
