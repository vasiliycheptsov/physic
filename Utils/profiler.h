/* Cheptsov Vasiliy, 10-4 class, 05.06.2014 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../physicdef.h"

/* Main project namepace */
namespace physic
{
  /* Profiler class */
  class profiler
  {
  private:
    UINT64 StartTime;  // Start profiler time
    INT NameSize;
    CHAR *Name;

    /* Convert to seconds function */
    DBL Convert( UINT64 Time )
    {
      return Time / (DBL)CLOCKS_PER_SEC;
    } /* End of 'physic::profiler::Convert' function */

  public:
    /* Class constructor function */
    profiler( CHAR *NewName ) : NameSize(strlen(NewName))
    {
      Name = new CHAR[NameSize + 1];
      memcpy((VOID *)Name, (VOID *)NewName, NameSize + 1);
      StartTime = clock();
    } /* End of 'physic::profiler::profiler' function */

    /* Class destructor function */
    ~profiler( VOID )
    {
      UINT64
        FinishTime = clock(),
        DeltaTime = (FinishTime - StartTime);
      FILE *F = fopen("profiler.log", "at");

      if (F != NULL)
      {
        fprintf(F, "profiler <%s>: Start: %lf, Finish: %lf, Delta: %lf",
                Name, Convert(StartTime), Convert(FinishTime), Convert(DeltaTime));
        fclose(F);
      }

      delete [] Name;
    } /* End of 'pysic::profiler::~profiler' function */
  }; /* End of 'physic::profiler' class */
} /* end of 'physic' namespace */

/* END OF 'profiler.h' FILE */
