/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __TIMER_H_
#define __TIMER_H_

#include "../physicdef.h"

/* Project namespace */
namespace physic
{
  /* Synchronization timer handle class */
  class timer
  {
  private:
    /* Start time (in ticks) */
    UINT64
      StartTime,      // Time from program start
      OldTime,        // Time of last frame
      FPSTime,        // Time of last FPS measure
      PauseTime,      // Total pause time
      ShiftTime,      // Time shift
      TimesPerSecond; // Timer sensitivity
    
    /* Frame counter */
    UINT64 FrameCount;

  public:

    /* Timer data (in seconds) */
    double
      GlobalTime,      // Time from program start
      GlobalDeltaTime, // Delta time from last frame
      Time,            // Time from prgram start (with pause)
      DeltaTime;       // Delta time from last frame (with pause)

    /* Pause flag */
    BOOL IsPause;

    /* Frames-per-second value */
    double FPS;

    /* Class constructor */
    timer( VOID );

    /* Responce and update timer values function */
    VOID Response( VOID );

    /* Increment frame count function */
    VOID IncrFrameCount( VOID );

    /* Enable/disable pause function */
    BOOL SetPause( BOOL IsToBePause );

    /* Add time shift function */
    VOID SetTimeShift( DBL Shift );
  }; /* End of 'timer' class */
} /* end of 'physic' namespace */

#endif /* __TIMER_H_ */

/* END OF 'timer.h' FILE */
