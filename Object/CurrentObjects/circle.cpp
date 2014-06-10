/* Cheptsov Vasiliy, 10-4 class, 10.06.2014 */

#include "../../physic.h"

/* Class constructor function */
physic::circle::circle( physic::object_parameters &NewObjectParam )
{
  *dynamic_cast<object_parameters *>(this) = NewObjectParam;
} /* End of 'physic::circle::circle' function */

/* Render circle function */
VOID physic::circle::Render( VOID )
{
  glPointSize(Radius);
  glBegin(GL_POINT);
    glColor3f(Color.R, Color.G, Color.B);
    glVertex2f(dynamic_cast<object_parameters *>(this)->Position.X,
               dynamic_cast<object_parameters *>(this)->Position.Y);
  glEnd();
} /* End of 'physic::circle::Render' function */

/* END OF 'circle.cpp' FILE */
