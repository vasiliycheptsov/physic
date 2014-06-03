/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_MODEL_H_
#define __OBJECT_MODEL_H_

#include "../physicdef.h"

/* Main project namespace */
namespace tlr
{
  class object_model
  {
  private:
    vec Velocity;  // Object velocity

  public:
    /* Default class constructor function */
    object_model( VOID ) : Velocity(0)
    {
    } /* End of 'tlr::object_model::object_model' function */
  }; /* End of 'tlr::object_model' class */
} /* end of 'tlr' namespace */

#endif /* __OBJECT_MODEL_H_ */

/* END OF 'object_model.h' FILE */
