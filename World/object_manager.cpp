/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#include "../physic.h"

/* Add new object function */
physic::object_manager physic::object_manager::AddObject( physic::object &Obj )
{
  Objects.push_back(boost::make_shared<object>(Obj));
  return *this;
} /* End of 'physic::object_manager::AddObject' function */

/* END OF 'object_manager.cpp' FILE */
