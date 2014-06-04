/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include "../physic.h"

/* Default class constructor function */
physic::object_model::object_model( VOID ) : Velocity(0, 0, 0), Mass(0)
{
} /* End of 'physic::object_model::object_model' function */

/* User class constructor function */
physic::object_model::object_model( physic::vec NewVelocity, FLT NewMass ) :
 Velocity(NewVelocity), Mass(NewMass)
{
} /* End of 'physic::object_model::object_model' function */

/* Kinematic update function */
 VOID physic::object_model::model_update( physic::object &Obj )
 {
 } /* End of 'physic::object_model::model_update' function */

/* END OF 'object_model.cpp' FILE */
