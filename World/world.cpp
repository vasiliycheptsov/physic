/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world::world( physic::anim *Ani )
{
  world_visual::Init(dynamic_cast<object_manager *>(this));
  world_model::Init(dynamic_cast<object_manager *>(this), Ani);
} /* End of 'physic::world::world' function */

/* END OF 'world.cpp' FILE */
