/* Cheptsov Vasiliy, 10-4 class, 02.06.2014 */

#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <stdio.h>

#include "../physicdef.h"

/* Project namespace */
namespace tlr
{
  /* Animation object base class */
  class unit
  {
  public:
    /* Unit message sending class */
    class msg
    {
    public:
      INT Id;     // Message ID (user defined)
      VOID *Data; // Message additional data

      /* Class constructor.
       * ARGUMENTS:
       *   - message ID value:
       *       INT NewId;
       *   - message additional data pointer:
       *       VOID *NewData;
       */
      msg( INT NewId = 0, VOID *NewData = NULL ) : Id(NewId), Data(NewData)
      {
      } /* End of 'msg' constructor */
    }; /* End of 'msg' class */

    /* New frame response function.
     * ARGUMENTS:
     *   - pointer to animation handle object:
     *       anim *Ani;
     * RETURNS: None.
     */
    virtual VOID Response( anim *Ani )
    {
    } /* End of 'Response' function */

    /* Render object function.
     * ARGUMENTS:
     *   - pointer to animation handle object:
     *       anim *Ani;
     * RETURNS: None.
     */
    virtual VOID Render( anim *Ani )
    {
    } /* End of 'Render' function */

    /* Handle message function.
     * ARGUMENTS:
     *   - message data reference:
     *       msg &M;
     * RETURNS:
     *   (INT) due to message and unit type.
     */
    virtual INT Handle( msg &M )
    {
      return 0;
    } /* End of 'Handle' function */

    /* Class destructor */
    virtual ~unit( VOID )
    {
    } /* End of '~unit' function */
  };

  /* Animation handle class */
  class anim : public win, public render, public input
  {
  private:
    /* Animation object stock */
    stock<unit *> Units;
  protected:
  public:
    /* Class constructor */
    anim( VOID );
    /* Class destructor */
    ~anim( VOID );

    /* Resize window handle function */
    VOID Resize( VOID );

    /* Redraw window content function */
    VOID Paint( HDC hDC );

      /* Activate window changing handle function */
    VOID Activate( VOID );

    /* Timer event handle function */
    VOID Timer( VOID );

    /* Add unit to animation stock function */
    anim & operator<<( unit *Uni );

    /* Delete unit from animation system function */
    VOID DeleteUnit( unit *Uni );
  }; /* End of 'anim' class */
} /* end of 'tlr' namespace */

#endif /* __ANIMATION_H_ */

/* END OF 'animation.h' FILE */
