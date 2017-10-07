/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
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

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define Subsystem_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Subsystem_IN_alarmmode         ((uint8_T)1U)
#define Subsystem_IN_ringing           ((uint8_T)1U)
#define Subsystem_IN_running           ((uint8_T)1U)
#define Subsystem_IN_setAhours         ((uint8_T)1U)
#define Subsystem_IN_setAminutes       ((uint8_T)2U)
#define Subsystem_IN_sethours          ((uint8_T)1U)
#define Subsystem_IN_setminutes        ((uint8_T)2U)
#define Subsystem_IN_silent            ((uint8_T)2U)
#define Subsystem_IN_stopped           ((uint8_T)2U)
#define Subsystem_IN_stopwatchmode     ((uint8_T)2U)
#define Subsystem_IN_switchOnAlarm     ((uint8_T)3U)
#define Subsystem_IN_timemode          ((uint8_T)3U)
#define Subsystem_IN_timesetmode       ((uint8_T)4U)
#define Subsystem_event_Balarm         (5)
#define Subsystem_event_Bminus         (2)
#define Subsystem_event_Bplus          (1)
#define Subsystem_event_Bstop          (6)
#define Subsystem_event_Btime          (3)
#define Subsystem_event_Btimeset       (4)
#define Subsystem_event_ttick          (0)

/* Forward declaration for local functions */
static void Su_enter_internal_stopwatchmode(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  DW_Subsystem_T *Subsystem_DW);
static void Subsystem_timesetmode(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW);
static void Subsystem_alarmmode(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW);
static void Subsystem_ControlSystem(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW);
static void Subsyste_chartstep_c3_Subsystem(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  uint8_T *Subsystem_Y_mode, boolean_T *Subsystem_Y_alarmactive, boolean_T
  *Subsystem_Y_hblink, boolean_T *Subsystem_Y_mblink, boolean_T
  *Subsystem_Y_ringalarm, DW_Subsystem_T *Subsystem_DW);

/* Function for Chart: '<S1>/SWatch' */
static void Su_enter_internal_stopwatchmode(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  DW_Subsystem_T *Subsystem_DW)
{
  /* Entry Internal 'stopwatchmode': '<S2>:40' */
  /* Transition: '<S2>:132' */
  Subsystem_DW->SWhours = 0U;
  Subsystem_DW->SWminutes = 0U;
  Subsystem_DW->SWseconds = 0U;
  Subsystem_DW->SWtenths = 0U;
  Subsystem_DW->is_stopwatchmode = Subsystem_IN_stopped;

  /* Outport: '<Root>/hours' */
  /* Entry 'stopped': '<S2>:83' */
  *Subsystem_Y_hours = Subsystem_DW->SWhours;

  /* Outport: '<Root>/minutes' */
  *Subsystem_Y_minutes = Subsystem_DW->SWminutes;

  /* Outport: '<Root>/seconds' */
  *Subsystem_Y_seconds = Subsystem_DW->SWseconds;

  /* Outport: '<Root>/tenths' */
  *Subsystem_Y_tenths = Subsystem_DW->SWtenths;
  Subsystem_DW->SWlap = false;
}

/* Function for Chart: '<S1>/SWatch' */
static void Subsystem_timesetmode(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW)
{
  uint32_T qY;
  int32_T tmp;

  /* Outport: '<Root>/mode' */
  *Subsystem_Y_mode = 1U;

  /* During 'timesetmode': '<S2>:24' */
  if (Subsystem_DW->sfEvent == Subsystem_event_Bstop) {
    /* Transition: '<S2>:77' */
    /* Exit Internal 'timesetmode': '<S2>:24' */
    Subsystem_DW->is_timesetmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/hblink' */
    /* Exit 'timesetmode': '<S2>:24' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;
    Subsystem_DW->is_ControlSystem = Subsystem_IN_stopwatchmode;

    /* Outport: '<Root>/mode' */
    /* Entry 'stopwatchmode': '<S2>:40' */
    *Subsystem_Y_mode = 3U;
    Su_enter_internal_stopwatchmode(Subsystem_Y_hours, Subsystem_Y_minutes,
      Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_DW);
  } else if (Subsystem_DW->sfEvent == Subsystem_event_Btime) {
    /* Transition: '<S2>:148' */
    /* Exit Internal 'timesetmode': '<S2>:24' */
    Subsystem_DW->is_timesetmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/hblink' */
    /* Exit 'timesetmode': '<S2>:24' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;
    Subsystem_DW->is_ControlSystem = Subsystem_IN_timemode;

    /* Outport: '<Root>/mode' */
    /* Entry 'timemode': '<S2>:23' */
    *Subsystem_Y_mode = 0U;
  } else if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
    /* Transition: '<S2>:152' */
    /* Exit Internal 'timesetmode': '<S2>:24' */
    Subsystem_DW->is_timesetmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Exit 'timesetmode': '<S2>:24' */
    Subsystem_DW->is_ControlSystem = Subsystem_IN_alarmmode;

    /* Outport: '<Root>/mode' */
    /* Entry 'alarmmode': '<S2>:39' */
    *Subsystem_Y_mode = 2U;

    /* Outport: '<Root>/hblink' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;

    /* Outport: '<Root>/alarmactive' */
    *Subsystem_Y_alarmactive = false;

    /* Outport: '<Root>/minutes' */
    /* Entry Internal 'alarmmode': '<S2>:39' */
    /* Transition: '<S2>:192' */
    *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
    Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

    /* Outport: '<Root>/hours' */
    /* Entry 'setAhours': '<S2>:197' */
    *Subsystem_Y_hours = Subsystem_DW->Ahours;
  } else if (Subsystem_DW->is_timesetmode == Subsystem_IN_sethours) {
    /* During 'sethours': '<S2>:61' */
    if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
      /* Transition: '<S2>:63' */
      tmp = (int32_T)(Subsystem_DW->hours + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      Subsystem_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 24U * 24U));
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else if ((Subsystem_DW->sfEvent == Subsystem_event_Bminus) &&
               (Subsystem_DW->hours == 0)) {
      /* Transition: '<S2>:65' */
      Subsystem_DW->hours = 23U;
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Bminus) {
      /* Transition: '<S2>:66' */
      qY = Subsystem_DW->hours - 1U;
      if (qY > Subsystem_DW->hours) {
        qY = 0U;
      }

      Subsystem_DW->hours = (uint8_T)qY;
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Btimeset) {
      /* Transition: '<S2>:72' */
      Subsystem_DW->counth = 0U;
      Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

      /* Outport: '<Root>/minutes' */
      /* Entry 'setminutes': '<S2>:70' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;
    } else {
      if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
        /* Transition: '<S2>:216' */
        if ((Subsystem_DW->sfEvent == Subsystem_event_ttick) &&
            (Subsystem_DW->counth == 0)) {
          /* Transition: '<S2>:231' */
          tmp = (int32_T)(Subsystem_DW->counth + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->counth = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);

          /* Outport: '<Root>/hblink' */
          *Subsystem_Y_hblink = !*Subsystem_Y_hblink;
          Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

          /* Outport: '<Root>/hours' */
          /* Entry 'sethours': '<S2>:61' */
          *Subsystem_Y_hours = Subsystem_DW->hours;
        } else {
          /* Transition: '<S2>:240' */
          tmp = (int32_T)(Subsystem_DW->counth + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->counth = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);
          Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

          /* Outport: '<Root>/hours' */
          /* Entry 'sethours': '<S2>:61' */
          *Subsystem_Y_hours = Subsystem_DW->hours;
        }
      }
    }
  } else {
    /* During 'setminutes': '<S2>:70' */
    if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
      /* Transition: '<S2>:68' */
      tmp = (int32_T)(Subsystem_DW->minutes + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      Subsystem_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 60U * 60U));
      Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

      /* Outport: '<Root>/minutes' */
      /* Entry 'setminutes': '<S2>:70' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;
    } else if ((Subsystem_DW->sfEvent == Subsystem_event_Bminus) &&
               (Subsystem_DW->minutes == 0)) {
      /* Transition: '<S2>:67' */
      Subsystem_DW->minutes = 59U;
      Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

      /* Outport: '<Root>/minutes' */
      /* Entry 'setminutes': '<S2>:70' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Bminus) {
      /* Transition: '<S2>:69' */
      qY = Subsystem_DW->minutes - 1U;
      if (qY > Subsystem_DW->minutes) {
        qY = 0U;
      }

      Subsystem_DW->minutes = (uint8_T)qY;
      Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

      /* Outport: '<Root>/minutes' */
      /* Entry 'setminutes': '<S2>:70' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Btimeset) {
      /* Transition: '<S2>:202' */
      Subsystem_DW->countm = 0U;

      /* Outport: '<Root>/mblink' */
      *Subsystem_Y_mblink = false;
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else {
      if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
        /* Transition: '<S2>:217' */
        if ((Subsystem_DW->sfEvent == Subsystem_event_ttick) &&
            (Subsystem_DW->countm == 0)) {
          /* Transition: '<S2>:243' */
          tmp = (int32_T)(Subsystem_DW->countm + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->countm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);

          /* Outport: '<Root>/mblink' */
          *Subsystem_Y_mblink = !*Subsystem_Y_mblink;
          Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

          /* Outport: '<Root>/minutes' */
          /* Entry 'setminutes': '<S2>:70' */
          *Subsystem_Y_minutes = Subsystem_DW->minutes;

          /* Outport: '<Root>/hblink' */
          *Subsystem_Y_hblink = false;
        } else {
          /* Transition: '<S2>:244' */
          tmp = (int32_T)(Subsystem_DW->countm + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->countm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);
          Subsystem_DW->is_timesetmode = Subsystem_IN_setminutes;

          /* Outport: '<Root>/minutes' */
          /* Entry 'setminutes': '<S2>:70' */
          *Subsystem_Y_minutes = Subsystem_DW->minutes;

          /* Outport: '<Root>/hblink' */
          *Subsystem_Y_hblink = false;
        }
      }
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void Subsystem_alarmmode(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW)
{
  uint32_T qY;
  int32_T tmp;

  /* Outport: '<Root>/mode' */
  *Subsystem_Y_mode = 2U;

  /* During 'alarmmode': '<S2>:39' */
  if (Subsystem_DW->sfEvent == Subsystem_event_Btimeset) {
    /* Transition: '<S2>:26' */
    /* Exit Internal 'alarmmode': '<S2>:39' */
    Subsystem_DW->is_alarmmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Exit 'alarmmode': '<S2>:39' */
    Subsystem_DW->is_ControlSystem = Subsystem_IN_timesetmode;

    /* Outport: '<Root>/mode' */
    /* Entry 'timesetmode': '<S2>:24' */
    *Subsystem_Y_mode = 1U;

    /* Outport: '<Root>/hblink' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;

    /* Outport: '<Root>/minutes' */
    /* Entry Internal 'timesetmode': '<S2>:24' */
    /* Transition: '<S2>:62' */
    *Subsystem_Y_minutes = Subsystem_DW->minutes;
    Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

    /* Outport: '<Root>/hours' */
    /* Entry 'sethours': '<S2>:61' */
    *Subsystem_Y_hours = Subsystem_DW->hours;
  } else if (Subsystem_DW->sfEvent == Subsystem_event_Bstop) {
    /* Transition: '<S2>:78' */
    /* Exit Internal 'alarmmode': '<S2>:39' */
    Subsystem_DW->is_alarmmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/hblink' */
    /* Exit 'alarmmode': '<S2>:39' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;
    Subsystem_DW->is_ControlSystem = Subsystem_IN_stopwatchmode;

    /* Outport: '<Root>/mode' */
    /* Entry 'stopwatchmode': '<S2>:40' */
    *Subsystem_Y_mode = 3U;
    Su_enter_internal_stopwatchmode(Subsystem_Y_hours, Subsystem_Y_minutes,
      Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_DW);
  } else if (Subsystem_DW->sfEvent == Subsystem_event_Btime) {
    /* Transition: '<S2>:149' */
    /* Exit Internal 'alarmmode': '<S2>:39' */
    Subsystem_DW->is_alarmmode = Subsystem_IN_NO_ACTIVE_CHILD;

    /* Outport: '<Root>/hblink' */
    /* Exit 'alarmmode': '<S2>:39' */
    *Subsystem_Y_hblink = false;

    /* Outport: '<Root>/mblink' */
    *Subsystem_Y_mblink = false;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;
    Subsystem_DW->is_ControlSystem = Subsystem_IN_timemode;

    /* Outport: '<Root>/mode' */
    /* Entry 'timemode': '<S2>:23' */
    *Subsystem_Y_mode = 0U;
  } else {
    switch (Subsystem_DW->is_alarmmode) {
     case Subsystem_IN_setAhours:
      /* During 'setAhours': '<S2>:197' */
      if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
        /* Transition: '<S2>:194' */
        tmp = (int32_T)(Subsystem_DW->Ahours + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Subsystem_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 24U * 24U));
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

        /* Outport: '<Root>/hours' */
        /* Entry 'setAhours': '<S2>:197' */
        *Subsystem_Y_hours = Subsystem_DW->Ahours;
      } else if ((Subsystem_DW->sfEvent == Subsystem_event_Bminus) &&
                 (Subsystem_DW->Ahours == 0)) {
        /* Transition: '<S2>:196' */
        Subsystem_DW->Ahours = 23U;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

        /* Outport: '<Root>/hours' */
        /* Entry 'setAhours': '<S2>:197' */
        *Subsystem_Y_hours = Subsystem_DW->Ahours;
      } else if (Subsystem_DW->sfEvent == Subsystem_event_Bminus) {
        /* Transition: '<S2>:189' */
        qY = Subsystem_DW->Ahours - 1U;
        if (qY > Subsystem_DW->Ahours) {
          qY = 0U;
        }

        Subsystem_DW->Ahours = (uint8_T)qY;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

        /* Outport: '<Root>/hours' */
        /* Entry 'setAhours': '<S2>:197' */
        *Subsystem_Y_hours = Subsystem_DW->Ahours;
      } else if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
        /* Transition: '<S2>:190' */
        Subsystem_DW->counth = 0U;

        /* Outport: '<Root>/hblink' */
        *Subsystem_Y_hblink = false;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

        /* Outport: '<Root>/minutes' */
        /* Entry 'setAminutes': '<S2>:195' */
        *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      } else {
        if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
          /* Transition: '<S2>:233' */
          if ((Subsystem_DW->sfEvent == Subsystem_event_ttick) &&
              (Subsystem_DW->counth == 0)) {
            /* Transition: '<S2>:218' */
            tmp = (int32_T)(Subsystem_DW->counth + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->counth = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
              ((uint8_T)tmp / 5U) * 5);

            /* Outport: '<Root>/hblink' */
            *Subsystem_Y_hblink = !*Subsystem_Y_hblink;
            Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

            /* Outport: '<Root>/hours' */
            /* Entry 'setAhours': '<S2>:197' */
            *Subsystem_Y_hours = Subsystem_DW->Ahours;
          } else {
            /* Transition: '<S2>:235' */
            tmp = (int32_T)(Subsystem_DW->counth + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->counth = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
              ((uint8_T)tmp / 5U) * 5);
            Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

            /* Outport: '<Root>/hours' */
            /* Entry 'setAhours': '<S2>:197' */
            *Subsystem_Y_hours = Subsystem_DW->Ahours;
          }
        }
      }
      break;

     case Subsystem_IN_setAminutes:
      /* During 'setAminutes': '<S2>:195' */
      if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
        /* Transition: '<S2>:193' */
        tmp = (int32_T)(Subsystem_DW->Aminutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Subsystem_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

        /* Outport: '<Root>/minutes' */
        /* Entry 'setAminutes': '<S2>:195' */
        *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      } else if ((Subsystem_DW->sfEvent == Subsystem_event_Bminus) &&
                 (Subsystem_DW->Aminutes == 0)) {
        /* Transition: '<S2>:198' */
        Subsystem_DW->Aminutes = 59U;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

        /* Outport: '<Root>/minutes' */
        /* Entry 'setAminutes': '<S2>:195' */
        *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      } else if (Subsystem_DW->sfEvent == Subsystem_event_Bminus) {
        /* Transition: '<S2>:199' */
        qY = Subsystem_DW->Aminutes - 1U;
        if (qY > Subsystem_DW->Aminutes) {
          qY = 0U;
        }

        Subsystem_DW->Aminutes = (uint8_T)qY;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

        /* Outport: '<Root>/minutes' */
        /* Entry 'setAminutes': '<S2>:195' */
        *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      } else if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
        /* Transition: '<S2>:191' */
        Subsystem_DW->countm = 0U;

        /* Outport: '<Root>/mblink' */
        *Subsystem_Y_mblink = false;
        Subsystem_DW->is_alarmmode = Subsystem_IN_switchOnAlarm;

        /* Outport: '<Root>/alarmactive' */
        /* Entry 'switchOnAlarm': '<S2>:320' */
        *Subsystem_Y_alarmactive = true;
      } else {
        if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
          /* Transition: '<S2>:219' */
          if ((Subsystem_DW->sfEvent == Subsystem_event_ttick) &&
              (Subsystem_DW->countm == 0)) {
            /* Transition: '<S2>:248' */
            tmp = (int32_T)(Subsystem_DW->countm + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->countm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
              ((uint8_T)tmp / 5U) * 5);

            /* Outport: '<Root>/mblink' */
            *Subsystem_Y_mblink = !*Subsystem_Y_mblink;
            Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

            /* Outport: '<Root>/minutes' */
            /* Entry 'setAminutes': '<S2>:195' */
            *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
          } else {
            /* Transition: '<S2>:247' */
            tmp = (int32_T)(Subsystem_DW->countm + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->countm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
              ((uint8_T)tmp / 5U) * 5);
            Subsystem_DW->is_alarmmode = Subsystem_IN_setAminutes;

            /* Outport: '<Root>/minutes' */
            /* Entry 'setAminutes': '<S2>:195' */
            *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
          }
        }
      }
      break;

     default:
      /* During 'switchOnAlarm': '<S2>:320' */
      if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
        /* Outport: '<Root>/alarmactive' */
        /* Transition: '<S2>:321' */
        *Subsystem_Y_alarmactive = false;
        Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

        /* Outport: '<Root>/hours' */
        /* Entry 'setAhours': '<S2>:197' */
        *Subsystem_Y_hours = Subsystem_DW->Ahours;
      }
      break;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void Subsystem_ControlSystem(uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, DW_Subsystem_T *Subsystem_DW)
{
  int32_T tmp;

  /* During 'ControlSystem': '<S2>:13' */
  switch (Subsystem_DW->is_ControlSystem) {
   case Subsystem_IN_alarmmode:
    Subsystem_alarmmode(Subsystem_Y_hours, Subsystem_Y_minutes,
                        Subsystem_Y_seconds, Subsystem_Y_tenths,
                        Subsystem_Y_mode, Subsystem_Y_alarmactive,
                        Subsystem_Y_hblink, Subsystem_Y_mblink, Subsystem_DW);
    break;

   case Subsystem_IN_stopwatchmode:
    /* Outport: '<Root>/mode' */
    *Subsystem_Y_mode = 3U;

    /* During 'stopwatchmode': '<S2>:40' */
    if (Subsystem_DW->sfEvent == Subsystem_event_Btimeset) {
      /* Transition: '<S2>:74' */
      /* Exit Internal 'stopwatchmode': '<S2>:40' */
      /* Exit Internal 'running': '<S2>:89' */
      Subsystem_DW->is_stopwatchmode = Subsystem_IN_NO_ACTIVE_CHILD;
      Subsystem_DW->is_ControlSystem = Subsystem_IN_timesetmode;

      /* Outport: '<Root>/mode' */
      /* Entry 'timesetmode': '<S2>:24' */
      *Subsystem_Y_mode = 1U;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;

      /* Outport: '<Root>/mblink' */
      *Subsystem_Y_mblink = false;
      Subsystem_DW->counth = 0U;
      Subsystem_DW->countm = 0U;

      /* Outport: '<Root>/minutes' */
      /* Entry Internal 'timesetmode': '<S2>:24' */
      /* Transition: '<S2>:62' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Btime) {
      /* Transition: '<S2>:150' */
      /* Exit Internal 'stopwatchmode': '<S2>:40' */
      /* Exit Internal 'running': '<S2>:89' */
      Subsystem_DW->is_stopwatchmode = Subsystem_IN_NO_ACTIVE_CHILD;
      Subsystem_DW->is_ControlSystem = Subsystem_IN_timemode;

      /* Outport: '<Root>/mode' */
      /* Entry 'timemode': '<S2>:23' */
      *Subsystem_Y_mode = 0U;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
      /* Transition: '<S2>:153' */
      /* Exit Internal 'stopwatchmode': '<S2>:40' */
      /* Exit Internal 'running': '<S2>:89' */
      Subsystem_DW->is_stopwatchmode = Subsystem_IN_NO_ACTIVE_CHILD;
      Subsystem_DW->is_ControlSystem = Subsystem_IN_alarmmode;

      /* Outport: '<Root>/mode' */
      /* Entry 'alarmmode': '<S2>:39' */
      *Subsystem_Y_mode = 2U;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;

      /* Outport: '<Root>/mblink' */
      *Subsystem_Y_mblink = false;
      Subsystem_DW->counth = 0U;
      Subsystem_DW->countm = 0U;

      /* Outport: '<Root>/alarmactive' */
      *Subsystem_Y_alarmactive = false;

      /* Outport: '<Root>/minutes' */
      /* Entry Internal 'alarmmode': '<S2>:39' */
      /* Transition: '<S2>:192' */
      *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

      /* Outport: '<Root>/hours' */
      /* Entry 'setAhours': '<S2>:197' */
      *Subsystem_Y_hours = Subsystem_DW->Ahours;
    } else if (Subsystem_DW->is_stopwatchmode == Subsystem_IN_running) {
      /* During 'running': '<S2>:89' */
      if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
        /* Transition: '<S2>:91' */
        /* Exit Internal 'running': '<S2>:89' */
        Subsystem_DW->is_stopwatchmode = Subsystem_IN_stopped;

        /* Outport: '<Root>/hours' */
        /* Entry 'stopped': '<S2>:83' */
        *Subsystem_Y_hours = Subsystem_DW->SWhours;

        /* Outport: '<Root>/minutes' */
        *Subsystem_Y_minutes = Subsystem_DW->SWminutes;

        /* Outport: '<Root>/seconds' */
        *Subsystem_Y_seconds = Subsystem_DW->SWseconds;

        /* Outport: '<Root>/tenths' */
        *Subsystem_Y_tenths = Subsystem_DW->SWtenths;
        Subsystem_DW->SWlap = false;
      } else if (Subsystem_DW->sfEvent == Subsystem_event_Bminus) {
        /* Transition: '<S2>:273' */
        Subsystem_DW->SWlap = !Subsystem_DW->SWlap;

        /* Exit Internal 'running': '<S2>:89' */
        Subsystem_DW->is_stopwatchmode = Subsystem_IN_running;

        /* Entry Internal 'running': '<S2>:89' */
        /* Transition: '<S2>:105' */
      } else {
        /* During 'counting': '<S2>:98' */
        if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
          /* Transition: '<S2>:102' */
          tmp = (int32_T)(Subsystem_DW->SWtenths + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->SWtenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 10U * 10U));
          if (Subsystem_DW->SWtenths == 0) {
            /* Transition: '<S2>:101' */
            tmp = (int32_T)(Subsystem_DW->SWseconds + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->SWseconds = (uint8_T)((uint32_T)(uint8_T)tmp -
              (uint8_T)((uint8_T)tmp / 60U * 60U));
            if (Subsystem_DW->SWseconds == 0) {
              /* Transition: '<S2>:104' */
              tmp = (int32_T)(Subsystem_DW->SWminutes + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Subsystem_DW->SWminutes = (uint8_T)((uint32_T)(uint8_T)tmp -
                (uint8_T)((uint8_T)tmp / 60U * 60U));
              if (Subsystem_DW->SWminutes == 0) {
                /* Transition: '<S2>:93' */
                tmp = (int32_T)(Subsystem_DW->SWhours + 1U);
                if ((uint32_T)tmp > 255U) {
                  tmp = 255;
                }

                Subsystem_DW->SWhours = (uint8_T)((uint32_T)(uint8_T)tmp -
                  (uint8_T)((uint8_T)tmp / 24U * 24U));
              } else {
                /* Transition: '<S2>:107' */
              }
            } else {
              /* Transition: '<S2>:95' */
            }
          } else {
            /* Transition: '<S2>:100' */
          }

          if (!Subsystem_DW->SWlap) {
            /* Outport: '<Root>/hours' */
            /* Transition: '<S2>:275' */
            *Subsystem_Y_hours = Subsystem_DW->SWhours;

            /* Outport: '<Root>/minutes' */
            *Subsystem_Y_minutes = Subsystem_DW->SWminutes;

            /* Outport: '<Root>/seconds' */
            *Subsystem_Y_seconds = Subsystem_DW->SWseconds;

            /* Outport: '<Root>/tenths' */
            *Subsystem_Y_tenths = Subsystem_DW->SWtenths;
          } else {
            /* Transition: '<S2>:108' */
          }
        }
      }
    } else {
      /* During 'stopped': '<S2>:83' */
      if (Subsystem_DW->sfEvent == Subsystem_event_Bplus) {
        /* Transition: '<S2>:90' */
        Subsystem_DW->is_stopwatchmode = Subsystem_IN_running;

        /* Entry Internal 'running': '<S2>:89' */
        /* Transition: '<S2>:105' */
      }
    }
    break;

   case Subsystem_IN_timemode:
    /* Outport: '<Root>/mode' */
    *Subsystem_Y_mode = 0U;

    /* During 'timemode': '<S2>:23' */
    if (Subsystem_DW->sfEvent == Subsystem_event_Btimeset) {
      /* Transition: '<S2>:75' */
      Subsystem_DW->is_ControlSystem = Subsystem_IN_timesetmode;

      /* Outport: '<Root>/mode' */
      /* Entry 'timesetmode': '<S2>:24' */
      *Subsystem_Y_mode = 1U;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;

      /* Outport: '<Root>/mblink' */
      *Subsystem_Y_mblink = false;
      Subsystem_DW->counth = 0U;
      Subsystem_DW->countm = 0U;

      /* Outport: '<Root>/minutes' */
      /* Entry Internal 'timesetmode': '<S2>:24' */
      /* Transition: '<S2>:62' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;
      Subsystem_DW->is_timesetmode = Subsystem_IN_sethours;

      /* Outport: '<Root>/hours' */
      /* Entry 'sethours': '<S2>:61' */
      *Subsystem_Y_hours = Subsystem_DW->hours;
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Bstop) {
      /* Transition: '<S2>:76' */
      Subsystem_DW->is_ControlSystem = Subsystem_IN_stopwatchmode;

      /* Outport: '<Root>/mode' */
      /* Entry 'stopwatchmode': '<S2>:40' */
      *Subsystem_Y_mode = 3U;
      Su_enter_internal_stopwatchmode(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_DW);
    } else if (Subsystem_DW->sfEvent == Subsystem_event_Balarm) {
      /* Transition: '<S2>:151' */
      Subsystem_DW->is_ControlSystem = Subsystem_IN_alarmmode;

      /* Outport: '<Root>/mode' */
      /* Entry 'alarmmode': '<S2>:39' */
      *Subsystem_Y_mode = 2U;

      /* Outport: '<Root>/hblink' */
      *Subsystem_Y_hblink = false;

      /* Outport: '<Root>/mblink' */
      *Subsystem_Y_mblink = false;
      Subsystem_DW->counth = 0U;
      Subsystem_DW->countm = 0U;

      /* Outport: '<Root>/alarmactive' */
      *Subsystem_Y_alarmactive = false;

      /* Outport: '<Root>/minutes' */
      /* Entry Internal 'alarmmode': '<S2>:39' */
      /* Transition: '<S2>:192' */
      *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
      Subsystem_DW->is_alarmmode = Subsystem_IN_setAhours;

      /* Outport: '<Root>/hours' */
      /* Entry 'setAhours': '<S2>:197' */
      *Subsystem_Y_hours = Subsystem_DW->Ahours;
    } else {
      /* Outport: '<Root>/hours' */
      *Subsystem_Y_hours = Subsystem_DW->hours;

      /* Outport: '<Root>/minutes' */
      *Subsystem_Y_minutes = Subsystem_DW->minutes;

      /* Outport: '<Root>/seconds' */
      *Subsystem_Y_seconds = Subsystem_DW->seconds;
    }
    break;

   default:
    Subsystem_timesetmode(Subsystem_Y_hours, Subsystem_Y_minutes,
                          Subsystem_Y_seconds, Subsystem_Y_tenths,
                          Subsystem_Y_mode, Subsystem_Y_alarmactive,
                          Subsystem_Y_hblink, Subsystem_Y_mblink, Subsystem_DW);
    break;
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void Subsyste_chartstep_c3_Subsystem(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  uint8_T *Subsystem_Y_mode, boolean_T *Subsystem_Y_alarmactive, boolean_T
  *Subsystem_Y_hblink, boolean_T *Subsystem_Y_mblink, boolean_T
  *Subsystem_Y_ringalarm, DW_Subsystem_T *Subsystem_DW)
{
  int32_T tmp;

  /* During: Subsystem/SWatch */
  Subsystem_ControlSystem(Subsystem_Y_hours, Subsystem_Y_minutes,
    Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
    Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
    Subsystem_DW);

  /* During 'TimeCount': '<S2>:14' */
  /* During 'timecount': '<S2>:17' */
  if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
    /* Transition: '<S2>:21' */
    tmp = (int32_T)(Subsystem_DW->tenths + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    Subsystem_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
      tmp / 10U * 10U));
    if (Subsystem_DW->tenths == 0) {
      /* Transition: '<S2>:29' */
      tmp = (int32_T)(Subsystem_DW->seconds + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      Subsystem_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 60U * 60U));
      if (Subsystem_DW->seconds == 0) {
        /* Transition: '<S2>:32' */
        tmp = (int32_T)(Subsystem_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Subsystem_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (Subsystem_DW->minutes == 0) {
          /* Transition: '<S2>:37' */
          tmp = (int32_T)(Subsystem_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
        } else {
          /* Transition: '<S2>:33' */
          /* Transition: '<S2>:60' */
        }
      } else {
        /* Transition: '<S2>:30' */
        /* Transition: '<S2>:60' */
      }
    } else {
      /* Transition: '<S2>:22' */
      /* Transition: '<S2>:60' */
    }
  }

  /* During 'AlarmManage': '<S2>:15' */
  if (Subsystem_DW->is_AlarmManage == Subsystem_IN_ringing) {
    /* Outport: '<Root>/alarmactive' incorporates:
     *  Outport: '<Root>/ringalarm'
     */
    /* During 'ringing': '<S2>:187' */
    if ((Subsystem_DW->Ahours != Subsystem_DW->hours) || (Subsystem_DW->Aminutes
         != Subsystem_DW->minutes) || (!*Subsystem_Y_alarmactive)) {
      /* Transition: '<S2>:186' */
      *Subsystem_Y_ringalarm = false;
      Subsystem_DW->is_AlarmManage = Subsystem_IN_silent;
    } else {
      if (Subsystem_DW->sfEvent == Subsystem_event_ttick) {
        /* Transition: '<S2>:252' */
        if ((Subsystem_DW->sfEvent == Subsystem_event_ttick) &&
            (Subsystem_DW->countalarm == 0)) {
          /* Transition: '<S2>:251' */
          tmp = (int32_T)(Subsystem_DW->countalarm + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->countalarm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);
          *Subsystem_Y_ringalarm = !*Subsystem_Y_ringalarm;
          Subsystem_DW->is_AlarmManage = Subsystem_IN_ringing;
        } else {
          /* Transition: '<S2>:253' */
          tmp = (int32_T)(Subsystem_DW->countalarm + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->countalarm = (uint8_T)((uint32_T)(uint8_T)tmp - (int32_T)
            ((uint8_T)tmp / 5U) * 5);
          Subsystem_DW->is_AlarmManage = Subsystem_IN_ringing;
        }
      }
    }
  } else {
    /* Outport: '<Root>/alarmactive' */
    /* During 'silent': '<S2>:185' */
    if ((Subsystem_DW->hours == Subsystem_DW->Ahours) && (Subsystem_DW->minutes ==
         Subsystem_DW->Aminutes) && (*Subsystem_Y_alarmactive)) {
      /* Transition: '<S2>:184' */
      Subsystem_DW->is_AlarmManage = Subsystem_IN_ringing;
    }
  }
}

/* Model step function */
void Subsystem_step(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
                    Subsystem_U_tick, boolean_T Subsystem_U_plusbutton,
                    boolean_T Subsystem_U_minusbutton, boolean_T
                    Subsystem_U_timemode, boolean_T Subsystem_U_timesetmode,
                    boolean_T Subsystem_U_alarmmode, boolean_T
                    Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T *
                    Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
                    *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
                    *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink,
                    boolean_T *Subsystem_Y_mblink, boolean_T
                    *Subsystem_Y_ringalarm)
{
  DW_Subsystem_T *Subsystem_DW = ((DW_Subsystem_T *) Subsystem_M->dwork);
  PrevZCX_Subsystem_T *Subsystem_PrevZCX = ((PrevZCX_Subsystem_T *)
    Subsystem_M->prevZCSigState);
  boolean_T zcEvent[7];
  boolean_T tmp;
  int32_T i;

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S2>/input events'
   */
  /* Inport: '<Root>/tick' */
  zcEvent[0] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_tick) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/plusbutton' */
  zcEvent[1] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_plusbutton) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[1] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/minusbutton' */
  zcEvent[2] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_minusbutton) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[2] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timemode' */
  zcEvent[3] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_timemode) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[3] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timesetmode' */
  zcEvent[4] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_timesetmode) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[4] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/alarmmode' */
  zcEvent[5] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_alarmmode) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[5] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/swatchmode' */
  zcEvent[6] = (((Subsystem_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 (int32_T)Subsystem_U_swatchmode) &&
                (Subsystem_PrevZCX->SWatch_Trig_ZCE[6] != UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 7; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    /* Inport: '<Root>/tick' */
    /* Gateway: Subsystem/SWatch */
    if ((int8_T)(zcEvent[0] ? Subsystem_U_tick ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S2>:1' */
      Subsystem_DW->sfEvent = Subsystem_event_ttick;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/plusbutton' */
    if ((int8_T)(zcEvent[1] ? Subsystem_U_plusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:6' */
      Subsystem_DW->sfEvent = Subsystem_event_Bplus;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/minusbutton' */
    if ((int8_T)(zcEvent[2] ? Subsystem_U_minusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:7' */
      Subsystem_DW->sfEvent = Subsystem_event_Bminus;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/timemode' */
    if ((int8_T)(zcEvent[3] ? Subsystem_U_timemode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:2' */
      Subsystem_DW->sfEvent = Subsystem_event_Btime;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/timesetmode' */
    if ((int8_T)(zcEvent[4] ? Subsystem_U_timesetmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:3' */
      Subsystem_DW->sfEvent = Subsystem_event_Btimeset;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/alarmmode' */
    if ((int8_T)(zcEvent[5] ? Subsystem_U_alarmmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:4' */
      Subsystem_DW->sfEvent = Subsystem_event_Balarm;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }

    /* Inport: '<Root>/swatchmode' */
    if ((int8_T)(zcEvent[6] ? Subsystem_U_swatchmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S2>:5' */
      Subsystem_DW->sfEvent = Subsystem_event_Bstop;
      Subsyste_chartstep_c3_Subsystem(Subsystem_Y_hours, Subsystem_Y_minutes,
        Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_Y_mode,
        Subsystem_Y_alarmactive, Subsystem_Y_hblink, Subsystem_Y_mblink,
        Subsystem_Y_ringalarm, Subsystem_DW);
    }
  }

  /* Inport: '<Root>/tick' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[0] = Subsystem_U_tick;

  /* Inport: '<Root>/plusbutton' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[1] = Subsystem_U_plusbutton;

  /* Inport: '<Root>/minusbutton' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[2] = Subsystem_U_minusbutton;

  /* Inport: '<Root>/timemode' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[3] = Subsystem_U_timemode;

  /* Inport: '<Root>/timesetmode' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[4] = Subsystem_U_timesetmode;

  /* Inport: '<Root>/alarmmode' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[5] = Subsystem_U_alarmmode;

  /* Inport: '<Root>/swatchmode' */
  Subsystem_PrevZCX->SWatch_Trig_ZCE[6] = Subsystem_U_swatchmode;
}

/* Model initialize function */
void Subsystem_initialize(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
  *Subsystem_U_tick, boolean_T *Subsystem_U_plusbutton, boolean_T
  *Subsystem_U_minusbutton, boolean_T *Subsystem_U_timemode, boolean_T
  *Subsystem_U_timesetmode, boolean_T *Subsystem_U_alarmmode, boolean_T
  *Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, boolean_T
  *Subsystem_Y_alarmactive, boolean_T *Subsystem_Y_hblink, boolean_T
  *Subsystem_Y_mblink, boolean_T *Subsystem_Y_ringalarm)
{
  DW_Subsystem_T *Subsystem_DW = ((DW_Subsystem_T *) Subsystem_M->dwork);
  PrevZCX_Subsystem_T *Subsystem_PrevZCX = ((PrevZCX_Subsystem_T *)
    Subsystem_M->prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)Subsystem_DW, 0,
                sizeof(DW_Subsystem_T));

  /* external inputs */
  *Subsystem_U_tick = false;
  *Subsystem_U_plusbutton = false;
  *Subsystem_U_minusbutton = false;
  *Subsystem_U_timemode = false;
  *Subsystem_U_timesetmode = false;
  *Subsystem_U_alarmmode = false;
  *Subsystem_U_swatchmode = false;

  /* external outputs */
  (*Subsystem_Y_hours) = 0U;
  (*Subsystem_Y_minutes) = 0U;
  (*Subsystem_Y_seconds) = 0U;
  (*Subsystem_Y_tenths) = 0U;
  (*Subsystem_Y_mode) = 0U;
  (*Subsystem_Y_alarmactive) = false;
  (*Subsystem_Y_hblink) = false;
  (*Subsystem_Y_mblink) = false;
  (*Subsystem_Y_ringalarm) = false;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      Subsystem_PrevZCX->SWatch_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    Subsystem_DW->is_alarmmode = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_stopwatchmode = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_timesetmode = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->counth = 0U;
    Subsystem_DW->countm = 0U;
    Subsystem_DW->SWlap = false;

    /* Entry: Subsystem/SWatch */
    /* Entry Internal: Subsystem/SWatch */
    /* Entry Internal 'ControlSystem': '<S2>:13' */
    /* Transition: '<S2>:25' */
    Subsystem_DW->is_ControlSystem = Subsystem_IN_timemode;

    /* SystemInitialize for Outport: '<Root>/mode' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* Entry 'timemode': '<S2>:23' */
    *Subsystem_Y_mode = 0U;

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    /* Entry Internal 'TimeCount': '<S2>:14' */
    /* Transition: '<S2>:18' */
    Subsystem_DW->hours = 0U;
    Subsystem_DW->minutes = 0U;
    Subsystem_DW->seconds = 0U;
    Subsystem_DW->tenths = 0U;

    /* SystemInitialize for Outport: '<Root>/alarmactive' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    /* Entry 'AlarmManage': '<S2>:15' */
    *Subsystem_Y_alarmactive = false;

    /* SystemInitialize for Outport: '<Root>/ringalarm' incorporates:
     *  SystemInitialize for Chart: '<S1>/SWatch'
     */
    *Subsystem_Y_ringalarm = false;

    /* SystemInitialize for Chart: '<S1>/SWatch' */
    Subsystem_DW->countalarm = 0U;

    /* Entry Internal 'AlarmManage': '<S2>:15' */
    /* Transition: '<S2>:188' */
    Subsystem_DW->Ahours = 0U;
    Subsystem_DW->Aminutes = 0U;
    Subsystem_DW->is_AlarmManage = Subsystem_IN_silent;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
