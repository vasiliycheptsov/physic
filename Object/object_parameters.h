/* Cheptsov Vasiliy, 10-4 class, 05.06.2014 */

#ifndef __OBJECT_PARAMETERS_H_
#define __OBJECT_PARAMETERS_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Object parameters class */
  class object_parameters
  {
  public:
    vec Position;  // Object position
    vec Velocity;  // Object velocity
    DBL Mass;      // Object mass

    /* Default class construtor */
    object_parameters( VOID ) : Position(vec(0, 0, 0)), Velocity(vec(0, 0, 0)), Mass(1)
    {
    } /* End of 'physic::object_parameters::

    /* User class constructor function */
    object_parameters( vec &NewPosition, vec &NewVelocity, DBL NewMass ) :
     Position(NewPosition), Velocity(NewVelocity), Mass(NewMass)
    {
    } /* End of 'physic::object_parameters::object::parameters' function */
  }; /* End of 'physic::object_parameters' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_PARAMETERS_H_ */

/* END OF 'object_parameters' FILE */
