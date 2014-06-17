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
  private:
    object_parameters *ObjectParam;  // Object parameters

  protected:
    /* Class init function */
    VOID Init( object_parameters *NewObjectParameters );

  public:
    /* Class constructor function */
    object_dynamic( VOID );

    /* Dynamic update function */
    VOID DynamicUpdate( vec &ResultImpuls );

    /* Count impuls function */
    static vec CountImpuls( collision_info &Info, object_parameters *Param1,
                            object_parameters *Param2, BOOL IsCountForFirst );
  };
} /* end of 'physic' namespace */

#endif /* __OBJECT_DYNAMIC_H_ */

/* END OF 'object_dynamic.h' FILE */
