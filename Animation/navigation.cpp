/* Cheptsov Vasiliy, 10-4 class, 06.06.2014 */

#include "../physic.h"

/* Render unit function */
VOID physic::navigation::Render( physic::anim *Ani )
{
  INT MouseWheel = Ani->MouseWheel / 120;
  FLT Zoom = (MouseWheel > 0) ? (MouseWheel / 12.0 + 1) : (-1.0 / (MouseWheel - 1));
  glLoadIdentity();
  glTranslatef(ShiftX / 100.0, ShiftY / 100.0, 0);
  if (Ani->Height < Ani->Width)
    glScalef((FLT)Ani->Height / Ani->Width * Zoom, Zoom, 1);
  else
    glScalef(Zoom, (FLT)Ani->Width / Ani->Height * Zoom, 1);
} /* End of 'physic::navigation::Render' function */

/* Responce unit function */
VOID physic::navigation::Response( physic::anim *Ani )
{
  if (Ani->Keys[VK_ESCAPE])
    Ani->DoExit();
  if (Ani->Keys[VK_CONTROL] &&
      ((Ani->Keys['F'] && !Ani->KeysOld['F']) ||
       (Ani->Keys['f'] && !Ani->KeysOld['f'])))
    Ani->ChangeFullScreen();
  if (Ani->Keys[VK_CONTROL] &&
      ((Ani->Keys['P'] && !Ani->KeysOld['P']) ||
       (Ani->Keys['p'] && !Ani->KeysOld['p'])))
       Ani->ChangePause();
  if (Ani->Keys[VK_UP])
    ShiftY--;
  if (Ani->Keys[VK_DOWN])
    ShiftY++;
  if (Ani->Keys[VK_RIGHT])
    ShiftX--;
  if (Ani->Keys[VK_LEFT])
    ShiftX++;
} /* End of 'physic::navigation::Response' function */

/* Default class constructor function */
physic::navigation::navigation( VOID ) : ShiftX(0), ShiftY(0)
{
} /* End of 'physic::navigation::navigation_unit' function */

/* END OF 'navigation.cpp' FILE */
