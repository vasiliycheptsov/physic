/* Cheptsov Vasiliy, 10-4 class, 09.06.2014*/

#include "../physic.h"

/* Class constructor function */
physic::object_visual::object_visual( VOID ) : ObjectParam(NULL)
{
} /* End of 'physic::object_visual::object_visual' function */

/* Class init function */
VOID physic::object_visual::Init( physic::object_parameters *NewObjectParam )
{
  ObjectParam = NewObjectParam;
} /* End of 'physic::object_visual::Init' function */

/* Render object function */
VOID physic::object_visual::Render( VOID )
{
  glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 1);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(0, 1);
  glEnd();
} /* End of 'physic::object_visual::Render' function */

/* END OF 'object_visual.cpp' FILE */
