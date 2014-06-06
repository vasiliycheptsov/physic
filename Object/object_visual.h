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
    object_parameters *ObjectParam;  // Pointer to object parameters

  public:
    /* Class constructor function */
    object_visual( VOID ) : ObjectParam(NULL)
    {
    } /* End of 'physic::object_visual::object_visual' function */

    /* Class init function */
    VOID Init( object_parameters *NewObjectParam )
    {
      ObjectParam = NewObjectParam;
    } /* End of 'physic::object_visual::Init' function */

    /* Render object function */
    VOID Render( VOID )
    {
      glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 1);
        glVertex2f(0, 0);
        glVertex2f(1, 0);
        glVertex2f(0, 1);
      glEnd();
    } /* End of 'physic::object_visual::Render' function */
  }; /* End of 'physic::object_visual' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_VISUAL_H_ */

/* END OF 'object_visual.h' FILE */
