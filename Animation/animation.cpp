/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#include "../physic.h"

/* Class constructor.
 * ARGUMENTS:
 *   - render window handle:
 *       HWND &hWndRender;
 */
physic::anim::anim( VOID ) :
  render(const_cast<HWND &>(win::hWnd)),
  input(const_cast<HWND &>(win::hWnd))
{
  Units << new navigation_unit();
} /* End of 'physic::anim::anim' constructor */

/* Class destructor.
 * ARGUMENTS:
 *   - render window handle:
 *       HWND hWndRender;
 */
physic::anim::~anim( VOID )
{
  /* Remove all units */
  for (INT i = 0; i < Units.Size(); i++)
    delete Units[i];
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
  for (INT i = 0; i < Units.Size(); i++)
  {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    Units[i]->Render(this);
    glPopAttrib();
  }
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
  for (INT i = 0; i < Units.Size(); i++)
    Units[i]->Response(this);


} /* End of 'physic::anim::Timer' function */

/* Add unit to animation stock function.
 * ARGUMENTS:
 *   - pointer to unit to be add:
 *       unit *Uni;
 * RETURNS:
 *   (anim &) self reference.
 */
physic::anim & physic::anim::operator<<( physic::unit *Uni )
{
  Units << Uni;
  return *this;
} /* End of 'physic::anim::operator<<' function */

/* Delete unit from animation system function.
 * ARGUMENTS:
 *   - pointer to unit to be delete:
 *       unit *Uni;
 * RETURNS: None.
 */
VOID physic::anim::DeleteUnit( unit *Uni )
{
  for (INT i = 0; i < Units.Size(); i++)
    if (Units[i] == Uni)
    {
      delete Units[i];
      Units.StableDelete(i);
    }
} /* End of 'physic::anim::DeleteUnit' function */

/* END OF 'animation.cpp' FILE */