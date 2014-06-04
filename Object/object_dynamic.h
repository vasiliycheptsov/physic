/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __OBJECT_DYNAMIC_H_
#define __OBJECT_DYNAMIC_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Dymanic object class */
  class object_dynamic
  {
  public:
    VOID dynamic_update( object &Obj );
  };
} /* end of 'physic' namespace */

#endif /* __OBJECT_DYNAMIC_H_ */

/* END OF 'object_dynamic.h' FILE */
