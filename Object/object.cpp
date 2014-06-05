/* Cheptsov Vasiliy, 10-4 class, 05.06.2014 */

/*
 * Error with make weak_ptr
 */

#include "../physic.h"

physic::object::object( physic::object_parameters &NewObjectParam ) :
 ObjectParam(NewObjectParam)
{
  object_visual::Init(boost::weak_ptr<object_parameters>(ObjectParam));
  object_model::Init(boost::weak_ptr<object_parameters>(ObjectParam));
} /* End of 'physic::object::object' function */

/* END OF 'object.cpp' FILE */
