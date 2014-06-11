/* Cheptsov Vasiliy, 10-4 class, 11.06.2014 */

#include "../../physic.h"

/* Class constructor function */
physic::plane::plane( physic::object_parameters NewObjectParam, FLT NewWidth, FLT NewHeight ) :
 Width(NewWidth), Height(NewHeight)
{
  *dynamic_cast<object_parameters *>(this) = NewObjectParam;
} /* End of 'physic::plane::plane' function */

/* Render plane function */
VOID physic::plane::Render( anim *Ani )
{
  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(Color.R, Color.G, Color.B);
    glVertex2f(Position.X, Position.Y);
    glVertex2f(Position.X + Width, Position.Y);
    glVertex2f(Position.X, Position.Y + Height);
    glVertex2f(Position.X + Width, Position.Y + Height);
  glEnd();
} /* End of 'physic::plane::Render' function */

/* END OF 'plane.cpp' FILE */
