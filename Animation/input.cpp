/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include <string.h>

#include "../physic.h"

/* Mouse wheel value */
static INT MouseWheelOld;

/* Local mouse hook handle function.
 * ARGUMENTS:
 *   - notification code:
 *       INT Code;
 *   - message type:
 *       WPARAM wParam;
 *   - hook structure (MSLLHOOKSTRUCT *):
 *       LPARAM lParam;
 * RETURNS:
 *   (LRESULT) not uset, returns 0.
 */
static LRESULT CALLBACK MouseHook( INT Code, WPARAM wParam, LPARAM lParam )
{
  MSLLHOOKSTRUCT *hs = (MSLLHOOKSTRUCT *)lParam;

  switch (wParam)
  {
  case WM_MOUSEWHEEL:
    MouseWheelOld += (SHORT)HIWORD(hs->mouseData);
    break;
  }

  return 0;
} /* End of 'MouseHook' function */

/* Class constructor.
 * ARGUMENTS: None.
 */
physic::input::input( HWND &hWndRef ) : hWnd(hWndRef)
{
  /* Register mouse event hook handle */
  SetWindowsHookEx(WH_MOUSE_LL, MouseHook, GetModuleHandle(NULL), 0);

  memset(Keys, 0, 256);

  POINT pt;
  GetCursorPos(&pt);
  ScreenToClient(hWnd, &pt);
  MousePosOldX = pt.x;
  MousePosOldY = pt.y;

  /* Read data first time */
  Response();
} /* End of 'physic::input::input' function */

/* Responce input devices function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::input::Response( VOID )
{
  /*** Keyboard ***/

  /* Copy old state */
  memcpy(KeysOld, Keys, 256);

  /* Read new keyboard state */
  GetKeyboardState(Keys);

  /* High bit - key state - move to low bit */
  for (INT i = 0; i < 256; i++)
    Keys[i] >>= 7;

  /* Mouse */
  POINT pt;
  GetCursorPos(&pt);
  ScreenToClient(hWnd, &pt);
  MouseX = pt.x;
  MouseY = pt.y;
  MouseBut[0] = Keys[VK_LBUTTON];
  MouseBut[1] = Keys[VK_RBUTTON];
  MouseBut[2] = Keys[VK_MBUTTON];
  MouseDeltaX = pt.x - MousePosOldX;
  MouseDeltaY = pt.y - MousePosOldY;
  MouseWheel = MouseWheelOld;
  //MouseWheelOld = 0;
  MousePosOldX = pt.x;
  MousePosOldY = pt.y;

  /* Joystick */
  if (joyGetNumDevs() > 1)
  {
    JOYCAPS jc;

    if (joyGetDevCaps(JOYSTICKID1, &jc, sizeof(jc)) == JOYERR_NOERROR)
    {
      JOYINFOEX ji;

      ji.dwSize = sizeof(ji);
      ji.dwFlags = JOY_RETURNALL;

      if (joyGetPosEx(JOYSTICKID1, &ji) == JOYERR_NOERROR)
      {
        /* Buttons */
        memcpy(JButOld, JBut, 32);
        for (INT i = 0; i < 32; i++)
          JBut[i] = (ji.dwButtons >> i) & 1;

        /* оси переводим в диапазон -1..1 */
        Jx = 2.0 * (ji.dwXpos - jc.wXmin) / (jc.wXmax - jc.wXmin) - 1;
        Jy = 2.0 * (ji.dwYpos - jc.wYmin) / (jc.wYmax - jc.wYmin) - 1;
        Jz = 2.0 * (ji.dwZpos - jc.wZmin) / (jc.wZmax - jc.wZmin) - 1;
        Jr = 2.0 * (ji.dwRpos - jc.wRmin) / (jc.wRmax - jc.wRmin) - 1;

        if (ji.dwPOV == 0xFFFF)
          JPov = 0;
        else
          JPov = ji.dwPOV / 4500 + 1;
      }
    }
  }
} /* End of 'physic::input::Response' function */

/* Check keyboard keys once pressed function.
 * ARGUMENTS:
 *   - key value:
 *       INT KeyValue;
 * RETURNS: None.
 */
BOOL physic::input::IsPressed( INT KeyValue )
{
  assert(KeyValue >= 0 && KeyValue < 256);
  return Keys[KeyValue] && !KeysOld[KeyValue];
} /* End of 'physic::input::Response' function */

/* Check joystick buttons once pressed function.
 * ARGUMENTS:
 *   - key value:
 *       joy_button KeyValue;
 * RETURNS: None.
 */
BOOL physic::input::IsPressed( joy_button KeyValue )
{
  assert(KeyValue.Button >= 0 && KeyValue.Button < 32);
  return JBut[KeyValue.Button] && !JButOld[KeyValue.Button];
} /* End of 'physic::input::Response' function */

/* END OF 'input.cpp' FILE */
