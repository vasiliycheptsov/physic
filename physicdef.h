/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __PHYSICDEF_H_
#define __PHYSICDEF_H_

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

#pragma warning(disable: 4355)

#pragma comment(lib, "winmm")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "glu32")
#pragma comment(lib, "glew32")

/* Project namespace */
namespace physic
{
  /* TSG base types */
  typedef tsg::TVec<FLT> vec;
  typedef tsg::TColor<FLT> color;

  /* Forward utils references */
  class profiler;

  /* Forward object references */
  class collision_info;
  class object_parameters;
  class onject_visual;
  class object_dynamic;
  class object_collision;
  class object_model;
  class object;
  class circle;
  class plane;

  /* Forward world references */
  class object_manager;
  class world_visual;
  class world_dynamic;
  class world_collision;
  class world_model;
  class world;

  /* Forward animation references */
  class win;
  class timer;
  class input;
  class render;
  class navigation;
  class anim;
} /* end of 'physic' namespace */

#endif /* __PHYSICDEF_H_ */

/* END OF 'physicdef.h' FILE */
