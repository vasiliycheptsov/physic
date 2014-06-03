/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_VISUAL_H_
#define __OBJECT_VISUAL_H_

#include "../physicdef.h"

/* Main project namespace */
namespace tlr
{
  /* Visual object class */
  class object_visual
  {
  public:
    /* Render object function */
    virtual VOID Render( VOID ) = 0;
  }; /* End of 'tlr::object_visual' class */
} /* end of 'tlr' namespace */

#endif /* __OBJECT_VISUAL_H_ */

/* END OF 'object_visual.h' FILE */
