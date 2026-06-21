/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_CONSTS_H_
#define SWAN_CONSTS_H_

#include "swan_types.h"

/* QuadFlightControl::PI */
#define PI_QuadFlightControl                                                  \
  (swan_lit_float32(3.1415926535897932384626433832795))

/* QuadFlightControl::T_CYCLE */
#define T_CYCLE_QuadFlightControl (swan_lit_float32(0.1))

/* QuadFlightControl::ROLL_KP */
#define ROLL_KP_QuadFlightControl (swan_lit_float32(0.5))

/* QuadFlightControl::ROLL_KI */
#define ROLL_KI_QuadFlightControl (swan_lit_float32(0.1))

/* QuadFlightControl::ROLL_KD */
#define ROLL_KD_QuadFlightControl (swan_lit_float32(0.5))

/* QuadFlightControl::PITCH_KP */
#define PITCH_KP_QuadFlightControl (swan_lit_float32(0.9))

/* QuadFlightControl::PITCH_KI */
#define PITCH_KI_QuadFlightControl (swan_lit_float32(0.01))

/* QuadFlightControl::PITCH_KD */
#define PITCH_KD_QuadFlightControl (swan_lit_float32(0.5))

/* QuadFlightControl::YAW_KP */
#define YAW_KP_QuadFlightControl (swan_lit_float32(12.0))

/* QuadFlightControl::YAW_KI */
#define YAW_KI_QuadFlightControl (swan_lit_float32(1.0))

/* QuadFlightControl::YAW_KD */
#define YAW_KD_QuadFlightControl (swan_lit_float32(6.0))

/* QuadFlightControl::MASS */
#define MASS_QuadFlightControl (swan_lit_float32(1.0))

/* QuadFlightControl::G */
#define G_QuadFlightControl (swan_lit_float32(9.81))

/* QuadFlightControl::DRAG_TORQ */
#define DRAG_TORQ_QuadFlightControl (swan_lit_float32(1.3858e-7))

/* QuadFlightControl::THRUST_COEF */
#define THRUST_COEF_QuadFlightControl (swan_lit_float32(3.36629e-7))

/* QuadFlightControl::L */
#define L_QuadFlightControl (swan_lit_float32(0.85))

/* QuadFlightControl::YAW_LIMIT */
#define YAW_LIMIT_QuadFlightControl (swan_lit_float32(6.25))

/* QuadFlightControl::ROTATE_LIMIT */
#define ROTATE_LIMIT_QuadFlightControl (swan_lit_float32(3.25))

/* QuadFlightControl::THRUST_HIGH_LIMIT */
#define THRUST_HIGH_LIMIT_QuadFlightControl (swan_lit_float32(43.5))

#endif /* SWAN_CONSTS_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** swan_consts.h
*************************************************************$ */
