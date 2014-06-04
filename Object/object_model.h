/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_MODEL_H_
#define __OBJECT_MODEL_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  class object_model : public object_collision, public object_dynamic
  {
  private:
    vec Velocity;  // Object velocity
    FLT Mass;      // Object mass

  public:
    /* Default class constructor function */
    object_model( VOID );

    /* User class constructor function */
    object_model( vec NewVelocity, FLT NewMass );

    /* Kinematic update function */
    VOID model_update( object &Obj );
  }; /* End of 'physic::object_model' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_MODEL_H_ */

/* END OF 'object_model.h' FILE */
