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

  physic::object_parameters Params2;
  Params2.Position = physic::vec(1, 0, 0);
  Params2.Color = physic::color(0, 1, 1, 0);
  Params2.Velocity = physic::vec(-0.1, 0, 0);
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::circle>(Params2, (FLT)0.3));

  physic::object_parameters Params3;
  Params3.Position = physic::vec(-1, 0, 0);
  Params3.Color = physic::color(1, 1, 0, 1);
  Params3.Velocity = physic::vec(0.1, 0, 0);
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::circle>(Params3, (FLT)0.3));

  physic::object_parameters Params4;
  Params4.Position = physic::vec(0, 1, 0);
  Params4.Color = physic::color(0, 1, 0, 0);
  Params4.Velocity = physic::vec(0, -0.15, 0);
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::circle>(Params4, (FLT)0.3));

  physic::object_parameters Params5;
  Params5.Position = physic::vec(0, -1, 0);
  Params5.Color = physic::color(1, 0, 0, 0);
  Params5.Velocity = physic::vec(0, 0.05, 0);
  MyAnim << boost::dynamic_pointer_cast<physic::object>(boost::make_shared<physic::circle>(Params5, (FLT)0.3));

  physic::profiler Run("Run program profiler");
  MyAnim.Run();
  return 30;
} /* End of 'WinMain' function */


/* END OF 'main.cpp' FILE */
