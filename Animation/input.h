/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __INPUT_H_
#define __INPUT_H_

#include "../physicdef.h"

/* Project namespace */
namespace physic
{
  /* Joystick button selection class */
  class joy_button
  {
  private:
    INT Button; /* Button number */
  public:
    /* Class constructor.
     * ARGUMENTS:
     *   - button number:
     *       INT Value;
     */
    joy_button( INT Value ) : Button(Value)
    {
    } /* End of 'joy_button' function */
    friend class input;
  };

  /* Input system handle class */
  class input
  {
  private:
    /* Work window reference */
    HWND &hWnd;
  public:
    /* Input devices data */
    BYTE Keys[256], KeysOld[256];    // Keyboard keys state

    INT
      MouseX, MouseY,                // Mouse cursor position
      MouseDeltaX, MouseDeltaY,      // Relative mouse cursor shift
      MousePosOldX, MousePosOldY,    // Old mouse position
      MouseWheel,                    // Relative wheel value
      MouseDeltaWheel,               // 
      MouseBut[16], MouseButOld[16]; // Mouse buttons state

    BYTE JBut[32], JButOld[32]; // Joystick button state
    DBL Jx, Jy, Jz, Jr;         // Joystive axe
    INT JPov;                   // Point-of-View [0-8] joustick state */

    /* Class constructor */
    input( HWND &hWndRef );

    /* Response input devices function */
    VOID Response( VOID );

    /* Check keyboard keys once pressed function */
    BOOL IsPressed( INT KeyValue );

    /* Check joystic buttons once pressed function */
    BOOL IsPressed( joy_button KeyValue );

  }; /* End of 'anim' class */
} /* end of 'physic' namespace */

#endif /* __INPUT_H_ */

/* END OF 'input.h' FILE */
