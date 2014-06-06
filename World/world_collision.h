/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __WORLD_COLLISION_H_
#define __WORLD_COLLISION_H_

#include "../physicdef.h"

namespace physic
{
  class world_collision
  {
  private:
    object_manager *ObjectCollection;  // Object collection

  public:
    /* Class constructor function */
    world_collision( VOID );

    /* Class init function */
    VOID Init( object_manager *NewObjectCollection );
  };
}

#endif /* __WORLD_COLLISION_H_ */

/* END OF 'world_collision' FILE */
