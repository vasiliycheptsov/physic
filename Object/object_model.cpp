/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::object_model::object_model( VOID ) : IsInit(FALSE)
{
} /* End of 'physic::opbject_model::object_model' function */

/* Class init function */
VOID physic::object_model::Init( boost::weak_ptr<physic::object_parameters> &NewObjectParam )
{
  ObjectParam = NewObjectParam;
  object_collision::Init(ObjectParam);
  object_dynamic::Init(ObjectParam);
  IsInit = TRUE;
} /* End of 'physic::object_model::Init' function */

/* Kinematic update function */
VOID physic::object_model::ModelUpdate( DBL DeltaTime )
{
  ObjectParam.lock().get()->Position = ObjectParam.lock().get()->Velocity * DeltaTime;
} /* End of 'physic::object_model::ModelUpdate' function */

/* END OF 'object_model.cpp' FILE */
