/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __WORLD_VISUAL_H_
#define __WORLD_VISUAL_H_

#include "../physicdef.h"

namespace physic
{
  class world_visual
  {
  private:
    object_manager *ObjectCollection;  // Object collection

  public:
    /* Class constructor function */
    world_visual( VOID );

    /* Class init function */
    VOID Init( object_manager *NewObjectCollection );

    /* Render all world objects function */
    VOID Render( anim *Ani );
  };
}

#endif /* __WORLD_VISUAL_H_ */

/* END OF 'world_visual' FILE */
