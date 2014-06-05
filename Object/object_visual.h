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
  private:
    boost::weak_ptr<object_parameters> ObjectParam;  // Pointer to object parameters
    BOOL IsInit;                                     // Is class init flag

  public:
    /* Class constructor function */
    object_visual( VOID ) : IsInit(FALSE)
    {
    } /* End of 'physic::object_visual::object_visual' function */

    /* Class init function */
    VOID Init( boost::weak_ptr<object_parameters> &NewObjectParam )
    {
      ObjectParam = NewObjectParam;
      IsInit = TRUE;
    } /* End of 'physic::object_visual::Init' function */

    /* Render object function */
    virtual VOID Render( VOID )
    {
    } /* End of 'physic::object_visual::Render' function */
  }; /* End of 'physic::object_visual' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_VISUAL_H_ */

/* END OF 'object_visual.h' FILE */
