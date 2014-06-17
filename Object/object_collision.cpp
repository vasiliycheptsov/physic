/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::collision_info::collision_info( BOOL NewIsIntersected ) :
 IsIntersected(NewIsIntersected)
{
} /* End of 'physic::collision_info::collision_info' function */

/* Class constructor function */
physic::object_collision::object_collision( VOID ) : ObjectParam(NULL)
{
} /* End of 'physic::object_collision::object_collision' function */

/* Class init function */
VOID physic::object_collision::Init( physic::object_parameters *NewObjectParams )
{
  ObjectParam = NewObjectParams;
} /* End of 'physic::object_collision::Init' function */

physic::collision_info physic::object_collision::CircleWithCircle( physic::circle &Circle1,
                                                                   physic::circle &Circle2 )
{
  if ((!(Circle1.Position - Circle2.Position)) > (Circle1.Radius + Circle2.Radius))
    return collision_info(FALSE);

  collision_info Info(TRUE);
  Info.Normal = (Circle2.Position - Circle1.Position).Normalize();
  Info.Point1 = Circle1.Position + Info.Normal * Circle1.Radius;
  Info.Point2 = Circle2.Position + (-Info.Normal) * Circle2.Radius;
  Info.Depth = !(Info.Point1 - Info.Point2);
  return Info;
} /* End of 'physic::object_collision::CircleWithCircle' function */

/* END OF 'object_collision.cpp' FILE */
