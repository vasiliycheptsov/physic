/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#ifndef __OBJECT_MANAGER_H_
#define __OBJECT_MANAGER_H_

#include "../physicdef.h"

/* Main project namespace */
namespace physic
{
  /* Object manager class */
  class object_manager
  {
  private:
    std::vector<boost::shared_ptr<object>> Objects;  // World objects

  public:
    /* Add new object function */
    object_manager AddObject( object &Obj );
  }; /* End of 'physic::object_manager' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_MANAGER_H_ */

/* END OF 'object_manager.h' FILE */
