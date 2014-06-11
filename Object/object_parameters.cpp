/* Cheptsov Vasiliy, 10-4 class, 10.06.2014 */

#include "../physic.h"

/* Default class construtor function */
physic::object_parameters::object_parameters( VOID ) :
 Position(vec(0, 0, 0)), Velocity(vec(0, 0, 0)), Mass(1), Color(1, 1, 1, 1)
{
} /* End of 'physic::object_parameters::object_parameters' function */

/* User class constructor function */
physic::object_parameters::object_parameters( vec &NewPosition, vec &NewVelocity, DBL NewMass, color NewColor ) :
 Position(NewPosition), Velocity(NewVelocity), Mass(NewMass), Color(NewColor)
{
} /* End of 'physic::object_parameters::object::parameters' function */

/* END OF 'onject_parameters.cpp' FILE */
