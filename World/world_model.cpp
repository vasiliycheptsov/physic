/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world_model::world_model( VOID ) :
 ObjectCollection(NULL), LastTime(0)
{
} /* End of 'physic::world_model::world_model' function */

/* Class init functiob */
VOID physic::world_model::Init( physic::object_manager *NewObjectCollection,
                                physic::anim *Ani )
{
  ObjectCollection = NewObjectCollection;
  world_collision::Init(ObjectCollection);
  world_dynamic::Init(ObjectCollection);
  LastTime = Ani->Time;
} /* End of 'physic::world_model::Init' function */

/* Model update function */
VOID physic::world_model::ModelUpdate( anim *Ani )
{
  DBL NowTime = Ani->Time;
  for (INT i = 0; i < ObjectCollection->Size(); i++)
    (*ObjectCollection)[i]->ModelUpdate(NowTime - LastTime);
  LastTime = NowTime;
} /* End of 'physic::world_model::ModelUpdate' function */

/* END OF 'world_model.cpp' FILE */
