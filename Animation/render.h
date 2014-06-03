/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __RENDER_H_
#define __RENDER_H_

#include <glew.h>
#include <gl/gl.h>
#include <gl/glu.h>

#pragma comment(lib, "opengl32")
#pragma comment(lib, "glu32")
#pragma comment(lib, "glew32")

#include "../physicdef.h"

/* Project namespace */
namespace tlr
{
  /* Render engine through OpenGL class */
  class render : public timer
  {
  private:
    HWND &hWnd;  // Window handle
    HDC hDC;     // Device context handle
    HGLRC hRC;   // Rendering context handle

  public:
    /* Frame size */
    INT Width, Height;

    /* Class constructor */
    render( HWND &hWndRender );

    /* Class destructor */
    ~render( VOID );

    /* Resize render window handle function */
    VOID Resize( INT W, INT H );

    /* Start frame rendering function */
    VOID StartFrame( VOID );

    /* Finish frame rendering function */
    VOID EndFrame( VOID );

    /* Copy current frame to window function */
    VOID CopyFrame( VOID );

    /* Output formatted text function */
    static INT PrintF( DBL X, DBL Y, CHAR *Fmt, ... );
  }; /* End of 'anim' class */
} /* end of 'tlr' namespace */

#endif /* __RENDER_H_ */

/* END OF 'render.h' FILE */
