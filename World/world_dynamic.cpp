/* Vasiliy Cheptsov, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Constructor class function */
physic::world_dynamic::world_dynamic( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_dynamic::world_dynamic' function */

/* Init class function */
VOID physic::world_dynamic::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
} /* End of 'physic::world_dynamic::Init' function */

/* END OF 'world_dynamic.cpp' FILE */
