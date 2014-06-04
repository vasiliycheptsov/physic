/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __NAVIGATION_H_
#define __NAVIGATION_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Navigation unit */
  class navigation_unit : public unit
  {
  private:
    INT ShiftX, ShiftY;

    /* Render unit function */
    VOID Render( anim *Ani )
    {
      INT MouseWheel = Ani->MouseWheel / 120;
      FLT Zoom = (MouseWheel > 0) ? (MouseWheel / 12.0 + 1) : (-1.0 / (MouseWheel - 1));
      glLoadIdentity();
      glTranslatef(ShiftX / 100.0, ShiftY / 100.0, 0);
      glScalef((FLT)Ani->Height / Ani->Width * Zoom, Zoom, 1);
    } /* End of 'physic::navigation_unit::Render' function */

    /* Responce unit function */
    VOID Response( anim *Ani )
    {
      if (Ani->Keys[VK_ESCAPE])
        Ani->DoExit();
      if (Ani->Keys[VK_UP])
        ShiftY--;
      if (Ani->Keys[VK_DOWN])
        ShiftY++;
      if (Ani->Keys[VK_RIGHT])
        ShiftX--;
      if (Ani->Keys[VK_LEFT])
        ShiftX++;
    } /* End of 'physic::navigation_unit::Response' function */

  public:
    /* Default class constructor function */
    navigation_unit( VOID ) : ShiftX(0), ShiftY(0)
    {
    } /* End of 'physic::navigation_unit::navigation_unit' function */
  }; /* End of 'physic::navigation_unit' class */
} /* end of 'physic' namespace */

#endif /* __NAVIGATION_H_ */

/* END OF 'navigation.h' FILE */
