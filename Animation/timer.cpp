/* Cheptsov Vasiliy, 10-4 class, 10.06.2014 */

#include "../physic.h"

/* Class constructor */
physic::timer::timer( VOID ) :
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
} /* End of 'physic::timer::timer' function */

/* Responce and update timer values function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::timer::Response( VOID )
{
  /* Query current timer value */
  LARGE_INTEGER CurrentTime;
  QueryPerformanceCounter(&CurrentTime);

  /* Evaluate global time values */
  GlobalTime =
    (DBL)(CurrentTime.QuadPart - StartTime) / TimesPerSecond;
  GlobalDeltaTime =
    (DBL)(CurrentTime.QuadPart - OldTime) / TimesPerSecond;

  /* Determine FPS value (one time per one second) */
  if (CurrentTime.QuadPart - FPSTime > TimesPerSecond)
  {
    FPS = (DBL)FrameCount / (CurrentTime.QuadPart - FPSTime) *
            TimesPerSecond;
    FPSTime = CurrentTime.QuadPart;
    FrameCount = 0;
  }

  /* Evaluate local time (time with pause) values */
  Time =
    (DBL)(CurrentTime.QuadPart - StartTime - PauseTime + ShiftTime) /
       TimesPerSecond;
  if (IsPause)
    DeltaTime = 0, PauseTime += CurrentTime.QuadPart - OldTime;
  else
    DeltaTime = GlobalDeltaTime;

  OldTime = CurrentTime.QuadPart;
} /* End of 'physic::timer::Response' function */

/* Increment frame count function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::timer::IncrFrameCount( VOID )
{
  FrameCount++;
} /* End of 'physic::timer::IncrFrameCount' function */

/* Enable/disable pause function.
 * ARGUMENTS:
 *   - new pause flag value:
 *       BOOL IsToBePause;
 * RETURNS:
 *   (BOOL) old pause state (true or false).
 */
BOOL physic::timer::SetPause( BOOL IsToBePause )
{
  if (IsPause == IsToBePause)
    return IsPause;
  return IsPause = IsToBePause;
} /* End of 'physic::timer::SetPause' function */

/* Change pause state function */
VOID physic::timer::ChangePause( VOID )
{
  static BOOL LastState = FALSE;
  LastState = !LastState;
  IsPause = LastState;
} /* End of 'physic::timer::ChangePause' function */

/* Add time shift function.
 * ARGUMENTS:
 *   - time shift in seconds to be add:
 *       double Shift;
 * RETURNS: None.
 */
VOID physic::timer::SetTimeShift( DBL Shift )
{
  ShiftTime += Shift * TimesPerSecond;
} /* End of 'physic::timer::SetTimeShift' function */

/* END OF 'timer.cpp' FILE */
