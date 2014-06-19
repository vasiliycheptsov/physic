/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#include <stdlib.h>

#include "../physic.h"

/* Class constructor function */
physic::object_dynamic::object_dynamic( VOID ) : ObjectParam(NULL)
{
} /* End of 'physic::object_dynamic::object_dynamic' function */

/* Class init function */
VOID physic::object_dynamic::Init( physic::object_parameters *NewObjectParam )
{
  ObjectParam = NewObjectParam;
} /* End of 'physic::object_dynamic::Init' function */

/* Dynamic update function */
VOID physic::object_dynamic::DynamicUpdate( physic::vec &ResultImpuls )
{
  if (ObjectParam != NULL)
    ObjectParam->Velocity += ResultImpuls / ObjectParam->Mass;
} /* End of 'physic::object_dynamic::DynamicUpdate' function */

/* Count impuls function */
physic::vec physic::object_dynamic::CountImpuls( physic::collision_info &Info,
                                                 physic::object_parameters *Param1,
                                                 physic::object_parameters *Param2,
                                                 BOOL IsCountForFirst )
{
  DBL Res = max(0, (-(Param2->Velocity - Param1->Velocity) & Info.Normal) /
                   (1.0 / Param1->Mass + 1.0 / Param2->Mass));
  if (IsCountForFirst)
    return Info.Normal * (((Param1->Velocity & Info.Normal) > 0) ? Res : 0);
  return Info.Normal * (((Param2->Velocity & (-Info.Normal)) > 0) ? (-Res) : 0);
} /* End of 'physic::object_dynamic::CountImpuls' function */

/* END OF 'object_dynamic.cpp' FILE */
