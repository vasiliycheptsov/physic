/* Cheptsov Vasiliy, 10-4 class, 05.06.2014 */

#include "../physic.h"

/* Default class constructor */
physic::object::object( VOID )
{
} /* End of 'physic::object::object' function */

/* Class onstructor function */
physic::object::object( physic::object_parameters &NewObjectParam )
{
  *dynamic_cast<object_parameters *>(this) = NewObjectParam;
  object_visual::Init(dynamic_cast<object_parameters *>(this));
  object_model::Init(dynamic_cast<object_parameters *>(this));
} /* End of 'physic::object::object' function */

/* END OF 'object.cpp' FILE */
