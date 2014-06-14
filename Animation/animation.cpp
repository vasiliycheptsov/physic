/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include "../physic.h"

/* Class constructor.
 * ARGUMENTS:
 *   - render window handle:
 *       HWND &hWndRender;
 */
physic::anim::anim( VOID ) :
  render(const_cast<HWND &>(win::hWnd)),
  input(const_cast<HWND &>(win::hWnd)),
  World(this)
{
} /* End of 'physic::anim::anim' constructor */

/* Class destructor.
 * ARGUMENTS:
 *   - render window handle:
 *       HWND hWndRender;
 */
physic::anim::~anim( VOID )
{
} /* End of 'physic::anim::~anim' destructor */

/* Resize window handle function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::anim::Resize( VOID )
{
  render::Resize(win::W, win::H);
} /* End of 'physic::anim::Resize' function */

/* Redraw window content function.
 * ARGUMENTS:
 *   - window device context:
 *       HDC hDC;
 * RETURNS: None.
 */
VOID physic::anim::Paint( HDC hDC )
{
  StartFrame();
  glPushAttrib(GL_ALL_ATTRIB_BITS);
  Navigation.Render(this);
  glPopAttrib();
  World.ModelUpdate(this);
  World.Render(this);
  EndFrame();
  CopyFrame();
  IncrFrameCount();
} /* End of 'physic::anim::Paint' function */

/* Activate window changing handle function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::anim::Activate( VOID )
{
  if (IsActive)
    SetPause(FALSE);
  else
    SetPause(TRUE);
} /* End of 'physic::anim::Activate' function */

/* Timer event handle function.
 * ARGUMENTS: None.
 * RETURNS: None.
 */
VOID physic::anim::Timer( VOID )
{
  /* Handle timer */
  timer::Response();
  static CHAR Buf[100];
  sprintf(Buf, "fps: %.5f", FPS);
  SetWindowText(win::hWnd, Buf);

  /* Handle input system */
  input::Response();

  /* Hanlde animation objects */
  Navigation.Response(this);
} /* End of 'physic::anim::Timer' function */

/* Operator '<<' - add world to animation function.
 * ARGUMENTS:
 *   - pointer to unit to be add:
 *       unit *Uni;
 * RETURNS:
 *   (anim &) self reference.
 */
physic::anim & physic::anim::operator<<( boost::shared_ptr<physic::object> &NewObject )
{
  World << NewObject;
  return *this;
} /* End of 'physic::anim::operator<<' function */

/* END OF 'animation.cpp' FILE */
