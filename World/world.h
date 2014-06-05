/* Cheptsov Vasiliy, 10-4 class, 03.06.2014 */

#ifndef __WORLD_H_
#define __WORLD_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* World class */
  class world : public world_visual, public world_model
  {
  }; /* End of 'physic::world' class */
} /* end of 'physic' namespace */

#endif /* __WORLD_H_ */

/* END OF 'world.h' FILE */