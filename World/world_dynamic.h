/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __WORLD_DYNAMIC_H_
#define __WORLD_DYNAMIC_H_

#include "../physicdef.h"

namespace physic
{
  class world_dynamic
  {
  private:
    object_manager *ObjectCollection;  // Object collection

  protected:
    /* Init class function */
    VOID Init( object_manager *NewObjectCollection );

  public:
    /* Constructor class function */
    world_dynamic( VOID );
  };
}

#endif /* __WORLD_DYNAMIC_H_ */

/* END OF 'world_dynamic' FILE */
