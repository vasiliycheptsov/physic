/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_VISUAL_H_
#define __OBJECT_VISUAL_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Visual object class */
  class object_visual
  {
  public:
    /* Render object function */
    virtual VOID Render( object &Obj )
    {
    } /* End of 'physic::object_visual::Render' function */
  }; /* End of 'physic::object_visual' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_VISUAL_H_ */

/* END OF 'object_visual.h' FILE */
