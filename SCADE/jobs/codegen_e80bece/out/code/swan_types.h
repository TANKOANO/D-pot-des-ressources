/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** Command: swan_cg.exe config.json -student
*************************************************************$ */
#ifndef SWAN_TYPES_H_
#define SWAN_TYPES_H_

#include "swan_config.h"

/* QuadTypes::MotorHealth */
typedef enum swan_tag_MotorHealth_QuadTypes {
  /* QuadTypes::NOMINAL */ NOMINAL,
  /* QuadTypes::ABNORMAL */ ABNORMAL,
  /* QuadTypes::FAILURE */ FAILURE
} MotorHealth_QuadTypes;
/* QuadFlightControl::CheckMotorHealth/$MotorHealthManagement: */
typedef enum swan_tag_SSM_ST_MotorHealthManagement {
  /* QuadFlightControl::CheckMotorHealth/$MotorHealthManagement:Nominal: */ SSM_st_Nominal_MotorHealthManagement,
  /* QuadFlightControl::CheckMotorHealth/$MotorHealthManagement:Abnormal: */ SSM_st_Abnormal_MotorHealthManagement,
  /* QuadFlightControl::CheckMotorHealth/$MotorHealthManagement:Failure: */ SSM_st_Failure_MotorHealthManagement
} SSM_ST_MotorHealthManagement;
/* QuadTypes::AttitudeType */
typedef struct swan_tag_AttitudeType_QuadTypes {
  swan_float32 /* QuadTypes::pitch */ pitch;
  swan_float32 /* QuadTypes::roll */ roll;
  swan_float32 /* QuadTypes::yaw */ yaw;
} AttitudeType_QuadTypes;

#ifndef swan_cp_AttitudeType_QuadTypes
#define swan_cp_AttitudeType_QuadTypes(swan_c1, swan_c2)                      \
  (swan_assign_struct((swan_c1), (swan_c2), sizeof (AttitudeType_QuadTypes)))
#endif /* swan_cp_AttitudeType_QuadTypes */

#ifdef swan_use_AttitudeType_QuadTypes
#ifndef swan_eq_AttitudeType_QuadTypes
extern swan_bool swan_eq_AttitudeType_QuadTypes(
  const AttitudeType_QuadTypes *swan_c1,
  const AttitudeType_QuadTypes *swan_c2);
#endif /* swan_eq_AttitudeType_QuadTypes */
#endif /* swan_use_AttitudeType_QuadTypes */

#endif /* SWAN_TYPES_H_ */
/* $ Ansys Scade One - Swan Code Generator - Version 2.4.0 - Build 0955 
** swan_types.h
*************************************************************$ */
