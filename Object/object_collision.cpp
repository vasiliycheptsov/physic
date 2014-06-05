/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::object_collision::object_collision( VOID ) : IsInit(FALSE)
{
} /* End of 'physic::object_collision::object_collision' function */

/* Class init function */
VOID physic::object_collision::Init( boost::weak_ptr<physic::object_parameters> &NewObjectParams )
{
  ObjectParam = NewObjectParams;
  IsInit = TRUE;
} /* End of 'physic::object_collision::Init' function */

/* END OF 'object_collision.cpp' FILE */
