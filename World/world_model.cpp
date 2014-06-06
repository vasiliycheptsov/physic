/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world_model::world_model( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_model::world_model' function */

/* Class init functiob */
VOID physic::world_model::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
  world_collision::Init(ObjectCollection);
  world_dynamic::Init(ObjectCollection);
} /* End of 'physic::world_model::Init' function */

/* END OF 'world_model.cpp' FILE */
