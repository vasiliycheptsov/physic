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
  physic::profiler MainProfiler("Main program profiler");
  physic::anim MyAnim;
  physic::object_parameters Params;
  MyAnim << boost::make_shared<physic::object>(physic::object(Params));
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::circle>(Params, (FLT)1));
  Params.Color = physic::color(1, 1, 0, 1);
  Params.Velocity = physic::vec(-0.01, -0.01, 0);
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::plane>(Params, (FLT)1, (FLT)1));
  physic::profiler Run("Run program profiler");
  MyAnim.Run();
  return 30;
} /* End of 'WinMain' function */


/* END OF 'main.cpp' FILE */
