/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Class constructor function */
physic::world_collision::world_collision( VOID ) : ObjectCollection(NULL)
{
} /* End of 'physic::world_collision::world_collision' function */

/* Class init function */
VOID physic::world_collision::Init( physic::object_manager *NewObjectCollection )
{
  ObjectCollection = NewObjectCollection;
} /* End of 'physic::world_collision::Init' fuction */

std::vector<physic::collision_info> physic::world_collision::CollisionUpdate( VOID )
{
  std::vector<collision_info> Res;
  if (ObjectCollection != NULL)
    for (INT i = 0; i < ObjectCollection->Size(); i++)
      for (INT j = i + 1; j < ObjectCollection->Size(); j++)
      {
        collision_info Info(object_collision::CircleWithCircle(*reinterpret_cast<circle *>((*ObjectCollection)[i].get()),
                                                               *reinterpret_cast<circle *>((*ObjectCollection)[j].get())));
        if (Info.IsIntersected)
        {
          Info.Index1 = i;
          Info.Index2 = j;
          Res.push_back(Info);
        }
      }
  return Res;
}

/* END OF 'world_collision.cpp' FILE */
