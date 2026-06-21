/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_types.h"

#ifdef swan_use_AttitudeType_QuadTypes
swan_bool swan_eq_AttitudeType_QuadTypes(
  const AttitudeType_QuadTypes *swan_c1,
  const AttitudeType_QuadTypes *swan_c2)
{
  swan_bool swan_equ;

  swan_equ = swan_true;
  swan_equ = swan_equ && swan_c1->yaw == swan_c2->yaw;
  swan_equ = swan_equ && swan_c1->roll == swan_c2->roll;
  swan_equ = swan_equ && swan_c1->pitch == swan_c2->pitch;
  return swan_equ;
}
#endif /* swan_use_AttitudeType_QuadTypes */

/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** swan_types.c
*************************************************************$ */
