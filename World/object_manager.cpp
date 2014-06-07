/* Cheptsov Vasiliy, 10-4 class, 04.06.2014 */

#include "../physic.h"

/* Class destructor function */
physic::object_manager::~object_manager( VOID )
{
  ClearObjectCollection();
} /* End of 'physic::object_manager::~object_manager' function */

/* Operator '<<' - add new object function */
physic::object_manager physic::object_manager::operator<<( physic::object &Obj )
{
  ObjectCollection.push_back(boost::make_shared<object>(Obj));
  return *this;
} /* End of 'physic::object_manager::AddObject' function */

/* Delete object by index function */
VOID physic::object_manager::DeleteSelectObject( INT Index )
{
  ObjectCollection.erase(ObjectCollection.begin() + Index);
} /* End of 'physic::object_manager::DeleteSelectObject' function */

/* Clear object collection function */
VOID physic::object_manager::ClearObjectCollection( VOID )
{
  ObjectCollection.clear();
} /* End of 'physic::object_manager::Delete' function */

/* Get number of objects in object collection function */
UINT physic::object_manager::Size( VOID )
{
  return ObjectCollection.size();
} /* End of 'physic::object_manager::GetNoofObjects' function */

/* Operator '[]' - get object by index function */
physic::object & physic::object_manager::operator[]( INT Index )
{
  return *(ObjectCollection[Index].get());
} /* End of 'physic::object_manager::GetObject' function */

/* END OF 'object_manager.cpp' FILE */
