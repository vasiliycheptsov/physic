/* Cheptsov Vasiliy, 10-4 class, 10.06.2014 */

#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "../../physicdef.h"

/* Main project namespace */
namespace physic
{
  class circle : public object
  {
  private:
    FLT Radius;  // Circle radius

  public:
    /* Class constructor function */
    circle( object_parameters NewObjectParam, FLT NewRadius );

    /* Render circle function */
    VOID Render( anim *Ani );
  }; /* End of 'physic::circle' class */
} /* end of 'physic' namespace */

#endif /* __CIRCLE_H_ */

/* END OF 'circle.h' FILE */
