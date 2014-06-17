/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world_visual::world_visual( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_visual::world_visual' function */

/* Class init function */
VOID physic::world_visual::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
} /* End of 'physic::world_visual::Init' function */

/* Render all world objects function */
VOID physic::world_visual::Render( physic::anim *Ani )
{
  if (ObjectCollection != NULL)
    for (INT i = 0; i < ObjectCollection->Size(); i++)
    {
      glPushAttrib(GL_ALL_ATTRIB_BITS);
      (*ObjectCollection)[i]->Render(Ani);
      glPopAttrib();
    }
} /* End of 'physic::world_visual::Render' function */

/* END OF 'world_visual.cpp' FILE */
