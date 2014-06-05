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
    boost::weak_ptr<object_parameters> ObjectParam;  // Object parameters
    BOOL IsInit;                                     // Is class init flag

  public:
    /* Class constructor function */
    object_model( VOID );

    /* Class init function */
    VOID Init( boost::weak_ptr<object_parameters> &NewObjectParam );

    /* Kinematic update function */
    VOID ModelUpdate( DBL DeltaTime );
  }; /* End of 'physic::object_model' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_MODEL_H_ */

/* END OF 'object_model.h' FILE */
