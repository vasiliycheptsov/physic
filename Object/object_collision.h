/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_COLLISION_H_
#define __OBJECT_COLLISION_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Collision info class */
  class collision_info
  {
  public:
    BOOL IsIntersected;  // Is objects intersected flag
    vec
      Normal;            // Collision normal
      Point1,            // First collision point
      Point2;            // Second collision point
    FLT Depth;           // Depth value

    /* Class constructor function */
    collision_info( BOOL NewIsIntersected );
  }; /* End of 'physic::collision_info' class */

  /* Collision object class */
  class object_collision
  {
  private:
    object_parameters *ObjectParam;  // Object parameters

    /* Get circle with circle intersection function */
    static collision_info CircleWithCircle( circle &Circle1, circle &Circle2 );

#if 0
    /* Get circle with circle intersection function */
    static collision_info CircleWithPlane( circle &Circle, plane &Plane );

    /* Get circle with circle intersection function */
    static collision_info PlaneWithPlane( plane &Plane1, plane &Plane2 );
#endif /* 0 */

  protected:
    /* Class init function */
    VOID Init( object_parameters *NewObjectParams );

  public:
    /* Class constructor function */
    object_collision( VOID );
  };
} /* end of 'physic' namespace */

#endif /* __OBJECT_COLLISION_H_ */

/* END OF 'object_collision.h' FILE */
