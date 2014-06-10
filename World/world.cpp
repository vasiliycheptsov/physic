/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world::world( VOID )
{
  world_visual::Init(&ObjectCollection);
  world_model::Init(&ObjectCollection);
} /* End of 'physic::world::world' function */

/* Opeartor '<<' - add new object function */
physic::world & physic::world::operator<<( boost::shared_ptr<physic::object> &NewObject )
{
  ObjectCollection << NewObject;
  return *this;
} /* End of 'physic::world::operator<<' function */

/* END OF 'world.cpp' FILE */
