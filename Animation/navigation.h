/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __NAVIGATION_H_
#define __NAVIGATION_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Navigation unit */
  class navigation
  {
  private:
    INT ShiftX, ShiftY;

  public:
    /* Default class constructor function */
    navigation( VOID );

    /* Render unit function */
    VOID Render( anim *Ani );

    /* Responce unit function */
    VOID Response( anim *Ani );
  }; /* End of 'physic::navigation_unit' class */
} /* end of 'physic' namespace */

#endif /* __NAVIGATION_H_ */

/* END OF 'navigation.h' FILE */
