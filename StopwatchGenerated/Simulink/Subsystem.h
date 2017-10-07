/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.168
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Oct  2 15:03:36 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <string.h>
#include <stddef.h>
#ifndef Subsystem_COMMON_INCLUDES_
# define Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<S1>/SWatch' */
  uint8_T is_ControlSystem;            /* '<S1>/SWatch' */
  uint8_T is_timesetmode;              /* '<S1>/SWatch' */
  uint8_T is_stopwatchmode;            /* '<S1>/SWatch' */
  uint8_T is_alarmmode;                /* '<S1>/SWatch' */
  uint8_T is_AlarmManage;              /* '<S1>/SWatch' */
  uint8_T hours;                       /* '<S1>/SWatch' */
  uint8_T minutes;                     /* '<S1>/SWatch' */
  uint8_T seconds;                     /* '<S1>/SWatch' */
  uint8_T tenths;                      /* '<S1>/SWatch' */
  uint8_T SWhours;                     /* '<S1>/SWatch' */
  uint8_T SWminutes;                   /* '<S1>/SWatch' */
  uint8_T SWseconds;                   /* '<S1>/SWatch' */
  uint8_T SWtenths;                    /* '<S1>/SWatch' */
  uint8_T Ahours;                      /* '<S1>/SWatch' */
  uint8_T Aminutes;                    /* '<S1>/SWatch' */
  uint8_T counth;                      /* '<S1>/SWatch' */
  uint8_T countm;                      /* '<S1>/SWatch' */
  uint8_T countalarm;                  /* '<S1>/SWatch' */
  boolean_T SWlap;                     /* '<S1>/SWatch' */
} DW_Subsystem_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SWatch_Trig_ZCE[7];       /* '<S1>/SWatch' */
} PrevZCX_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
  PrevZCX_Subsystem_T *prevZCSigState;
  DW_Subsystem_T *dwork;
};

/* Model entry point functions */
extern void Subsystem_initialize(RT_MODEL_Subsystem_T *const Subsystem_M,
  boolean_T *Subsystem_U_tick, boolean_T *Subsystem_U_plusbutton, boolean_T
  *Subsystem_U_minusbutton, boolean_T *Subsystem_U_timemode, boolean_T
  *Subsystem_U_timesetmode, boolean_T *Subsystem_U_alarmmode, boolean_T
  *Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm);
extern void Subsystem_step(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
  Subsystem_U_tick, boolean_T Subsystem_U_plusbutton, boolean_T
  Subsystem_U_minusbutton, boolean_T Subsystem_U_timemode, boolean_T
  Subsystem_U_timesetmode, boolean_T Subsystem_U_alarmmode, boolean_T
  Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('NewWatch/Subsystem')    - opens subsystem NewWatch/Subsystem
 * hilite_system('NewWatch/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NewWatch'
 * '<S1>'   : 'NewWatch/Subsystem'
 * '<S2>'   : 'NewWatch/Subsystem/SWatch'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
