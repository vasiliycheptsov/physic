/* Cheptsov Vasiliy, 10-4 class, 10.06.2014 */

#include "../../physic.h"

/* Class constructor function */
physic::circle::circle( physic::object_parameters NewObjectParam, FLT NewRadius ) : Radius(NewRadius)
{
  *dynamic_cast<object_parameters *>(this) = NewObjectParam;
} /* End of 'physic::circle::circle' function */

/* Render circle function */
VOID physic::circle::Render( physic::anim *Ani )
{
  glColor3f(Color.R, Color.G, Color.B);
  glTranslatef(Position.X, Position.Y, Position.Z);
  glutSolidSphere(Radius, 100 * Radius, 100 * Radius);
  glTranslatef(-Position.X, -Position.Y, -Position.Z);
} /* End of 'physic::circle::Render' function */

/* END OF 'circle.cpp' FILE */
