/* Cheptsov Vasiliy, 10-4 class, 11.06.2014 */

#ifndef __PLANE_H_
#define __PLANE_H_

#include "../../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Plane object class */
  class plane : public object
  {
  private:
    FLT
      Width,   // Plane width
      Height;  // Plane height

  public:
    /* Class constructor function */
    plane( object_parameters NewObjectParam, FLT NewWidth, FLT NewHeight );

    /* Render plane function */
    VOID Render( anim *Ani );
  }; /* End of 'physic::plane' class */
} /* end of 'physic' namespace */

#endif /* __PLANE_H_ */

/* END OF 'plane.h' FILE */
