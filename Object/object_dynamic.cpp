/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::object_dynamic::object_dynamic( VOID ) : ObjectParam(NULL)
{
} /* End of 'physic::object_dynamic::object_dynamic' function */

/* Class init function */
VOID physic::object_dynamic::Init( physic::object_parameters *NewObjectParam )
{
  ObjectParam = NewObjectParam;
} /* End of 'physic::object_dynamic::Init' function */

/* Dynamic update function */
VOID physic::object_dynamic::DynamicUpdate( DBL DeltaTime )
{
} /* End of 'physic::object_dynamic::DynamicUpdate' function */

/* END OF 'object_dynamic.cpp' FILE */
