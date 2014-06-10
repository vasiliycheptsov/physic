/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __OBJECT_H_
#define __OBJECT_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Object class */
  class object : public object_parameters, public object_visual, public object_model
  {
  protected:
    /* Default class constructor */
    object( VOID );

  public:
    /* Class constructor function */
    object( object_parameters &NewObjectParam );
  };
}

#endif /* __OBJECT_H_ */

/* END OF 'object.h' FILE */
