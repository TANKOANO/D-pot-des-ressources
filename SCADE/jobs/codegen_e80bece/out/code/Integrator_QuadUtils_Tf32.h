/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_Integrator_QuadUtils_Tf32_H_
#define SWAN_Integrator_QuadUtils_Tf32_H_

#include "swan_types.h"

typedef struct Ctx_Integrator_QuadUtils_Tf32 {
  swan_float32 /* y */ y;
  swan_bool mem1;
} outC_Integrator_QuadUtils_Tf32;

/* QuadUtils::Integrator */
extern void Integrator_QuadUtils_Tf32(
  /* i */swan_float32 i,
  /* x */swan_float32 x,
  outC_Integrator_QuadUtils_Tf32 * restrict outC);

extern void Integrator_reset_QuadUtils_Tf32(
  outC_Integrator_QuadUtils_Tf32 * restrict outC);

#ifndef SWAN_USER_DEFINED_INIT
extern void Integrator_init_QuadUtils_Tf32(
  outC_Integrator_QuadUtils_Tf32 * restrict outC);
#endif /* SWAN_USER_DEFINED_INIT */



#endif /* SWAN_Integrator_QuadUtils_Tf32_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Integrator_QuadUtils_Tf32.h
*************************************************************$ */
