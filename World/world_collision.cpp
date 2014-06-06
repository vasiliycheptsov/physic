/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world_collision::world_collision( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_collision::world_collision' function */

/* Class init function */
VOID physic::world_collision::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
} /* End of 'physic::world_collision::Init' fuction */

/* END OF 'world_collision.cpp' FILE */
