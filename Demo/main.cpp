/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include "../physic.h"

/* The main program function.
 * ARGUMENTS:
 *   - handle of application instance:
 *       HINSTANCE hInstance;
 *   - dummy handle of previous application instance (not used):
 *       HINSTANCE hPrevInstance;
 *   - command line string:
 *       CHAR *CmdLine;
 *   - show window command parameter:
 *       INT CmdShow;
 * RETURNS:
 *   (INT) Error level for operation system (0 for success).
 */
INT WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    CHAR *CmdStr, INT CmdShow )
{
  physic::anim MyAnim;

  MyAnim << physic::world();
  MyAnim.AddObject(physic::object(physic::object_parameters()), 0);

  MyAnim.Run();
  return 30;
} /* End of 'WinMain' function */


/* END OF 'main.cpp' FILE */
