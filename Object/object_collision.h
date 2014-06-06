/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_COLLISION_H_
#define __OBJECT_COLLISION_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Collision object class */
  class object_collision
  {
  private:
    object_parameters *ObjectParam;  // Object parameters

  public:
    /* Class constructor function */
    object_collision( VOID );

    /* Class init function */
    VOID Init( object_parameters *NewObjectParams );
  };
} /* end of 'physic' namespace */

#endif /* __OBJECT_COLLISION_H_ */

/* END OF 'object_collision.h' FILE */
