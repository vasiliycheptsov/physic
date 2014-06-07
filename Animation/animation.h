/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <stdio.h>

#include "../physicdef.h"

/* Project namespace */
namespace physic
{
  /* Animation handle class */
  class anim : public win, public render, public input
  {
  private:
    std::vector<world> Worlds;  // Worlds
    navigation Navigation;      // Navigation elements

  public:
    /* Class constructor */
    anim( VOID );
    /* Class destructor */
    ~anim( VOID );

    /* Resize window handle function */
    VOID Resize( VOID );

    /* Redraw window content function */
    VOID Paint( HDC hDC );

      /* Activate window changing handle function */
    VOID Activate( VOID );

    /* Timer event handle function */
    VOID Timer( VOID );

    /* Operator '<<' - add new world to animation stock function */
    anim & operator<<( world &NewWorld );

    /* Add new object to current world function */
    anim & AddObject( object &NewObject, INT WorldIndex );
  }; /* End of 'anim' class */
} /* end of 'physic' namespace */

#endif /* __ANIMATION_H_ */

/* END OF 'animation.h' FILE */
