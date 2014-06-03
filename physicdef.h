/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __PHYSICDEF_H_
#define __PHYSICDEF_H_

#include <assert.h>
#include <commondf.h>

#include "tsg/tsg.h"
#include "stock.h"

/* Debug memory allocation support */
#ifdef _DEBUG
#  define _CRTDBG_MAP_ALLOC
#  include <crtdbg.h>
#  define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
    _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
static class __Dummy
{
public:
  /* Class constructor */
  __Dummy( VOID )
  {
    SetDbgMemHooks();
  } /* End of '__Dummy' constructor */
} __oops;
#endif /* _DEBUG */

#ifdef _DEBUG
#  ifdef _CRTDBG_MAP_ALLOC
#    define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#  endif /* _CRTDBG_MAP_ALLOC */
#endif /* _DEBUG */

/* Common purpose base types */
typedef __int64 INT64;
typedef unsigned __int64 UINT64;
typedef double DBL;
typedef float FLT;

/* Project namespace */
namespace tlr
{
  /* TSG base types */
  typedef tsg::TVec<FLT> vec;

  /* Forward references */
  class win;
  class timer;
  class input;
  class render;
  class anim;
  class unit;
  class navigation_unit;
} /* end of 'tlr' namespace */

#endif /* __PHYSICDEF_H_ */

/* END OF 'physicdef.h' FILE */
