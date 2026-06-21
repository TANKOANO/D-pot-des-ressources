/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#include "swan_imported_functions.h"
#include "swan_sensors.h"
#include "swan_consts.h"
#include "Max_Math_Common_Tf32.h"
#include "RotorControl_QuadFlightControl.h"

/* QuadFlightControl::RotorControl */
void RotorControl_QuadFlightControl(
  /* u1 */swan_float32 u1,
  /* u2 */swan_float32 u2,
  /* u3 */swan_float32 u3,
  /* u4 */swan_float32 u4,
  /* w1 */swan_float32 * restrict w1,
  /* w2 */swan_float32 * restrict w2,
  /* w3 */swan_float32 * restrict w3,
  /* w4 */swan_float32 * restrict w4)
{
  *w4 = /* #1416: */
    Sqrt32_Math_Common(
      /* #1409: */
      Max_Math_Common_Tf32(
        u1 / (swan_lit_float32(4.0) * THRUST_COEF_QuadFlightControl) - u3 /
        (swan_lit_float32(2.0) * L_QuadFlightControl * THRUST_COEF_QuadFlightControl) +
        u4 / (swan_lit_float32(4.0) * DRAG_TORQ_QuadFlightControl),
        swan_lit_float32(0.0)));
  *w3 = /* #1417: */
    Sqrt32_Math_Common(
      /* #1410: */
      Max_Math_Common_Tf32(
        u1 / (swan_lit_float32(4.0) * THRUST_COEF_QuadFlightControl) + u2 /
        (swan_lit_float32(2.0) * L_QuadFlightControl * THRUST_COEF_QuadFlightControl) -
        u4 / (swan_lit_float32(4.0) * DRAG_TORQ_QuadFlightControl),
        swan_lit_float32(0.0)));
  *w2 = /* #1418: */
    Sqrt32_Math_Common(
      /* #1411: */
      Max_Math_Common_Tf32(
        u1 / (swan_lit_float32(4.0) * THRUST_COEF_QuadFlightControl) - u2 /
        (swan_lit_float32(2.0) * L_QuadFlightControl * THRUST_COEF_QuadFlightControl) -
        u4 / (swan_lit_float32(4.0) * DRAG_TORQ_QuadFlightControl),
        swan_lit_float32(0.0)));
  *w1 = /* #1419: */
    Sqrt32_Math_Common(
      /* #1412: */
      Max_Math_Common_Tf32(
        u1 / (swan_lit_float32(4.0) * THRUST_COEF_QuadFlightControl) + u3 /
        (swan_lit_float32(2.0) * L_QuadFlightControl * THRUST_COEF_QuadFlightControl) +
        u4 / (swan_lit_float32(4.0) * DRAG_TORQ_QuadFlightControl),
        swan_lit_float32(0.0)));
}



/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** RotorControl_QuadFlightControl.c
*************************************************************$ */
