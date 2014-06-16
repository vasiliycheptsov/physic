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
    object_parameters *ObjectParam;  // Object parameters

  protected:
    /* Class init function */
    VOID Init( object_parameters *NewObjectParam );

  public:
    /* Class constructor function */
    object_model( VOID );

    /* Kinematic update function */
    VOID ModelUpdate( DBL DeltaTime );
  }; /* End of 'physic::object_model' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_MODEL_H_ */

/* END OF 'object_model.h' FILE */
