/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include "../physic.h"

class tst_unit : public tlr::unit
{
private:
  VOID Render( tlr::anim *Ani )
  {
    glBegin(GL_TRIANGLES);
      glColor3d(0, 0, 0);
      glVertex2d(1, -1);
      glVertex2d(0, -1);
      glVertex2d(-1, 0);
    glEnd();
  }
};

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
  tlr::anim MyAnim;

  MyAnim << new tst_unit();

  MyAnim.Run();
  return 30;
} /* End of 'WinMain' function */


/* END OF 'main.cpp' FILE */
