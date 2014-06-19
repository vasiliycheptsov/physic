/* Vasiliy Cheptsov, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Constructor class function */
physic::world_dynamic::world_dynamic( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_dynamic::world_dynamic' function */

/* Init class function */
VOID physic::world_dynamic::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
} /* End of 'physic::world_dynamic::Init' function */

VOID physic::world_dynamic::DynamicUpdate( std::vector<physic::collision_info> &Pairs )
{
  if (ObjectCollection != NULL && (INT)Pairs.size() > 0)
  {
    vec *Impulses = new vec[ObjectCollection->Size()];

    for (INT i = 0; i < (INT)Pairs.size(); i++)
    {
      Impulses[Pairs[i].Index1] +=
        object_dynamic::CountImpuls(Pairs[i],
          dynamic_cast<object_parameters *>((*ObjectCollection)[Pairs[i].Index1].get()),
          dynamic_cast<object_parameters *>((*ObjectCollection)[Pairs[i].Index2].get()),
          TRUE);
      Impulses[Pairs[i].Index2] += -Impulses[Pairs[i].Index1];
    }

    for (INT i = 0; i < ObjectCollection->Size(); i++)
      (*ObjectCollection)[i]->DynamicUpdate(Impulses[i]);

    delete [] Impulses;
  }
}

/* END OF 'world_dynamic.cpp' FILE */
