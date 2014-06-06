/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __WORLD_MODEL_H_
#define __WORLD_MODEL_H_

#include "../physicdef.h"

namespace physic
{
  class world_model : public world_collision, public world_dynamic
  {
  private:
    object_manager *ObjectCollection;  // Object collection

  public:
    /* Class constructor function */
    world_model( VOID );

    /* Class init functiob */
    VOID Init( object_manager *NewObjectCollection );
  };
}

#endif /* __WORLD_MODEL_H_ */

/* END OF 'world_model' FILE */
