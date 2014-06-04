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
    timer( VOID ) :
      FrameCount(0), GlobalTime(0), GlobalDeltaTime(0), ShiftTime(0),
      Time(0), DeltaTime(0), PauseTime(0), IsPause(FALSE), FPS(0)
    {
      /* Initialize timer clocks count */
      LARGE_INTEGER CurrentTime;

      /* Query timer information */
      QueryPerformanceCounter(&CurrentTime);
      StartTime = OldTime = FPSTime = CurrentTime.QuadPart;
      QueryPerformanceFrequency(&CurrentTime);
      TimesPerSecond = CurrentTime.QuadPart;
    } /* End of 'timer' function */

    /* Responce and update timer values function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    void Response( void )
    {
      /* Query current timer value */
      LARGE_INTEGER CurrentTime;
      QueryPerformanceCounter(&CurrentTime);

      /* Evaluate global time values */
      GlobalTime =
        (double)(CurrentTime.QuadPart - StartTime) / TimesPerSecond;
      GlobalDeltaTime =
        (double)(CurrentTime.QuadPart - OldTime) / TimesPerSecond;

      /* Determine FPS value (one time per one second) */
      if (CurrentTime.QuadPart - FPSTime > TimesPerSecond)
      {
        FPS = (double)FrameCount / (CurrentTime.QuadPart - FPSTime) *
                TimesPerSecond;
        FPSTime = CurrentTime.QuadPart;
        FrameCount = 0;
      }

      /* Evaluate local time (time with pause) values */
      Time =
        (double)(CurrentTime.QuadPart - StartTime - PauseTime + ShiftTime) /
           TimesPerSecond;
      if (IsPause)
        DeltaTime = 0, PauseTime += CurrentTime.QuadPart - OldTime;
      else
        DeltaTime = GlobalDeltaTime;

      OldTime = CurrentTime.QuadPart;
    } /* End of 'Response' function */

    /* Increment frame count function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    void IncrFrameCount( void )
    {
      FrameCount++;
    } /* End of 'IncrFrameCount' function */

    /* Enable/disable pause function.
     * ARGUMENTS:
     *   - new pause flag value:
     *       BOOL IsToBePause;
     * RETURNS:
     *   (BOOL) old pause state (true or false).
     */
    BOOL SetPause( BOOL IsToBePause )
    {
      if (IsPause == IsToBePause)
        return IsPause;
      return IsPause = IsToBePause;
    } /* End of 'SetPause' function */

    /* Add time shift function.
     * ARGUMENTS:
     *   - time shift in seconds to be add:
     *       double Shift;
     * RETURNS: None.
     */
    void SetTimeShift( double Shift )
    {
      ShiftTime += Shift * TimesPerSecond;
    } /* End of 'SetTimeShift' function */
  }; /* End of 'timer' class */
} /* end of 'physic' namespace */

#endif /* __TIMER_H_ */

/* END OF 'timer.h' FILE */
