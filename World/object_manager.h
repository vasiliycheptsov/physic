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
    std::vector<boost::shared_ptr<object>> ObjectCollection;  // World objects

  public:
    /* Class destructor function */
    ~object_manager( VOID );

    /* Operator '<<' - add new object function */
    object_manager operator<<( boost::shared_ptr<object> &Obj );

    /* Delete object by index function */
    VOID DeleteSelectObject( INT Index );

    /* Clear object collection function */
    VOID ClearObjectCollection( VOID );

    /* Get number of objects in object collection function */
    UINT Size( VOID );

    /* Operator '[]' - get object by index function */
    boost::shared_ptr<object> & operator[]( INT Index );
  }; /* End of 'physic::object_manager' class */
} /* end of 'physic' namespace */

#endif /* __OBJECT_MANAGER_H_ */

/* END OF 'object_manager.h' FILE */
