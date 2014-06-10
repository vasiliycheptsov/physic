/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include <stdio.h>
#include <stdarg.h>

#include "../physic.h"

/* Class constructor.
 * ARGUMENTS:
 *   - render window handle reference:
 *       HWND &hWndRender;
 */
physic::render::render( HWND &hWndRender ) :
  hWnd(hWndRender), hDC(GetDC(hWnd)), hRC(NULL)
{
  INT i;
  PIXELFORMATDESCRIPTOR pfd = {0};

  /* Initialisation OpenGL: select appropriate pixel format */
  pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
  pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_SUPPORT_GDI | PFD_DOUBLEBUFFER;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 32;

  i = ChoosePixelFormat(hDC, &pfd);
  DescribePixelFormat(hDC, i, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
  SetPixelFormat(hDC, i, &pfd);

  hRC = wglCreateContext(hDC);
  wglMakeCurrent(hDC, hRC);

  /* Set default OpenGL parameters */
  glClearColor(0, 0, 0, 1);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  if (glewInit() != GLEW_OK)
  {
    /* Error in extensions initialization */
    ReleaseDC(hWnd, hDC);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);

    MessageBox(hWnd, "ERROR: glew initialization", "ERROR",
      MB_ICONERROR | MB_OK);
    exit(0);
  }

  /* Make work font */
  SelectObject(hDC,
    CreateFont(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, RUSSIAN_CHARSET,
    OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
    FF_SWISS | VARIABLE_PITCH, "Arial"));
  wglUseFontBitmaps(hDC, 0, 256, 3030);
  /*
  wglUseFontOutlines(hDC, 0, 256, 30 * 3030, 0.00051, 0.1, WGL_FONT_POLYGONS, NULL);
  */
  glListBase(3030);
} /* End of 'physic::render::render' function */

/* Class destructor.
 * ARGUMENTS: None.
 */
physic::render::~render( VOID )
{
  /* Destroy rendering context */
  wglMakeCurrent(NULL, NULL);
  if (hRC != NULL)
    wglDeleteContext(hRC);
  if (hDC != NULL)
    ReleaseDC(hWnd, hDC);
} /* End of 'physic::render::~render' function */

/* Resize render window handle function.
 * ARGUMENTS:
 *   - new window work area size:
 *       INT W, H;
 * RETURNS: None.
 */
VOID physic::render::Resize( INT W, INT H )
{
  /* Store new size */
  Width = W;
  Height = H;

  /* Update camera projection data */
  glViewport(0, 0, W, H);

} /* End of 'physic::render::Resize' function */

/* Start frame rendering function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::render::StartFrame( VOID )
{
  glClear(GL_COLOR_BUFFER_BIT);
} /* End of 'physic::render::StartFrame' function */

/* Finish  frame rendering function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::render::EndFrame( VOID )
{
  glFinish();
} /* End of 'physic::render::EndFrame' function */

/* Copy current frame to window function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::render::CopyFrame( VOID )
{
  SwapBuffers(hDC);
} /* End of 'physic::render::CopyFrame' function */

/* Output formatted text function.
 * ARGUMENTS:
 *   - screen position:
 *       DBL X, Y;
 *   - formatted string:
 *       CHAR *Fmt;
 * RETURNS:
 *   (INT) number of output symbols.
 */
INT physic::render::PrintF( DBL X, DBL Y, CHAR *Fmt, ... )
{
  INT ret;
  va_list ap;
  static CHAR Buf[10000];

  memset(Buf, 0, 10000);
  va_start(ap, Fmt);
  ret = vsprintf(Buf, Fmt, ap);
  glRasterPos2d(X, Y);
  glCallLists(ret, GL_UNSIGNED_BYTE, Buf);
  va_end(ap);
  return ret;
} /* End of 'physic::render::PrintF' function */

/* END OF 'RENDER.CPP' FILE */
