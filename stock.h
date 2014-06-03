/* Cheptsov Vasiliy, 10-4, 02.06.2014 */

#ifndef __STOCK_H_
#define __STOCK_H_

#include <string.h>
#include <assert.h>

#include <commondf.h>

/* Stock container template class */
template<class Type, INT ForwardAllocation = 10>
  class stock
  {
    friend class stock;
  private:
    /* Objectr stock - dynamic array */
    Type *Bulk;
    /* Stock allocated and filled size */
    INT AllocatedSize, FilledSize;

    /* Clone stock function.
     * ARGUMENTS:
     *   - reference to stock to be cloned:
     *       const stock<Type, N> &CopyStock;
     * RETURNS: None.
     */
    template<INT N>
      VOID Clone( const stock<Type, N> &CopyStock )
      {
        /* Free old data if any exists */
        if (Bulk != NULL)
          delete[] Bulk;

        /* Allocate memory for a new copy */
        Bulk = new Type[CopyStock.FilledSize];
        /* Copy data */
        for (INT i = 0; i < CopyStock.FilledSize; i++)
          Bulk[i] = CopyStock.Bulk[i];
        FilledSize = AllocatedSize = CopyStock.FilledSize;
      } /* End of 'Clone' function */

  public:

    /* Class constructor.
     * ARGUMENTS:
     *   - first allocated elements number:
     *       INT StartSize;
     */
    stock( INT StartSize = 0 ) :
      Bulk(NULL), FilledSize(0), AllocatedSize(0)
    {
      assert(ForwardAllocation > 0);
      if (StartSize > 0)
      {
        /* Initial memory allocation */
        Bulk = new Type[StartSize];
        AllocatedSize = StartSize;
      }
    } /* End of 'stock' constructor */

    /* Copying constructor.
     * ARGUMENTS:
     *   - reference to stock to be coped:
     *       const stock<Type, N> &CopyStock;
     * RETURNS: None.
     */
    stock( const stock &CopyStock ) : Bulk(NULL)
    {
      Clone(CopyStock);
    } /* End of 'stock' constructor */

    /* Copying constructor.
     * ARGUMENTS:
     *   - reference to stock to be coped:
     *       const stock<Type, N> &CopyStock;
     * RETURNS: None.
     */
    template<INT N>
      stock( const stock<Type, N> &CopyStock ) : Bulk(NULL)
      {
        Clone(CopyStock);
      } /* End of 'stock' constructor */

    /* Assignment operator function.
     * ARGUMENTS:
     *   - reference to stock to be coped:
     *       const stock<Type, N> &CopyStock;
     * RETURNS:
     *   (stock &) self reference.
     */
    stock & operator=( const stock &CopyStock )
    {
      Clone(CopyStock);
      return *this;
    } /* End of 'operator=' function */

    /* Assignment operator function.
     * ARGUMENTS:
     *   - reference to stock to be coped:
     *       const stock<Type, N> &CopyStock;
     * RETURNS:
     *   (stock &) self reference.
     */
    template<INT N>
      stock & operator=( const stock<Type, N> &CopyStock )
      {
        Clone(CopyStock);
        return *this;
      } /* End of 'operator=' function */

    /* Class destructor */
    ~stock( VOID )
    {
      delete[] Bulk;
    } /* End of '~stock' destructor */

    /* Функция получения размера склада */
    /* Obtain stock size function.
     * ARGUMENTS: None.
     * RETURNS:
     *   (INT) number of filled stock elements.
     */
    INT Size( VOID ) const
    {
      return FilledSize;
    } /* End of 'Size' function */

    /* Obtain stock last element function.
     * ARGUMENTS: None.
     * RETURNS:
     *   (Type &) reference to last element.
     */
    Type & Last( VOID )
    {
      assert(FilledSize > 0);
      return Bulk[FilledSize - 1];
    } /* End of 'Last' function */

    /* Obtain stock last element function.
     * ARGUMENTS: None.
     * RETURNS:
     *   (const Type &) reference to last element.
     */
    const Type & Last( VOID ) const
    {
      assert(FilledSize > 0);
      return Bulk[FilledSize - 1];
    } /* End of 'Last' function */

    /* Obtain stock element by index function.
     * ARGUMENTS:
     *   - element index:
     *       INT I;
     * RETURNS:
     *   (Type &) reference to last element.
     */
    Type & operator[]( INT I )
    {
      assert(I >= 0 && I < FilledSize);
      return Bulk[I];
    } /* End of 'operator[]' function */

    /* Obtain stock element by index function.
     * ARGUMENTS:
     *   - element index:
     *       INT I;
     * RETURNS:
     *   (const Type &) reference to last element.
     */
    const Type & operator[]( INT I ) const
    {
      assert(I >= 0 && I < FilledSize);
      return Bulk[I];
    } /* End of 'operator[]' function */

    /* Stock clear function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    VOID Clear( VOID )
    {
      delete[] Bulk; // free memory
      Bulk = NULL;   // set array pointer to empty value
      FilledSize = AllocatedSize = 0;
    } /* End of 'Clear' function */

    /* Stock reset stock element numbers function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    VOID Reset( VOID )
    {
      /* Reset stock filled elements count */
      FilledSize = 0;
    } /* End of 'Reset' function */

    /* Allocation specified number of new stock elements function.
     * ARGUMENTS:
     *   - number of new elements:
     *       INT NumToAlloc;
     * RETURNS: None.
     */
    VOID Alloc( INT NumToAlloc )
    {
      if (FilledSize + NumToAlloc > AllocatedSize)
      {
        /* Allocate memory for new elements */
        Type *NewBulk = new Type[AllocatedSize + NumToAlloc];

        if (FilledSize > 0)
        {
          /* Copy old data */
          for (INT i = 0; i < FilledSize; i++)
            NewBulk[i] = Bulk[i];

          /* Free old data memory */
          delete[] Bulk;
        }
        Bulk = NewBulk;
        /* Increment allocated size */
        AllocatedSize += NumToAlloc;
      }
      /* Increment filled counter */
      FilledSize += NumToAlloc;
    } /* End of 'Alloc' function */

    /* Fast delete (place last to removed position) stock element function.
     * ARGUMENTS:
     *   - number of element to be delete:
     *       INT NoToDelete;
     * RETURNS: None.
     */
    VOID Delete( INT NoToDelete )
    {
      assert(NoToDelete >= 0 && NoToDelete < FilledSize);
      if (NoToDelete != --FilledSize)
        memcpy((VOID *)(Bulk + NoToDelete),
          (VOID *)(Bulk + FilledSize),
          sizeof(Type));
    } /* End of 'Delete' function */

    /* Stable delete (preserve rest elements order) stock element function.
     * ARGUMENTS:
     *   - number of element to be delete:
     *       INT NoToDelete;
     * RETURNS: None.
     */
    VOID StableDelete( INT NoToDelete )
    {
      assert(NoToDelete >= 0 && NoToDelete < FilledSize);
      if (NoToDelete != --FilledSize)
        memmove((VOID *)(Bulk + NoToDelete),
          (VOID *)(Bulk + NoToDelete + 1),
          sizeof(Type) * (FilledSize - NoToDelete));
    } /* End of 'StableDelete' function */

    /* Delete last stock elements function.
     * ARGUMENTS:
     *   - number of elements to be delete:
     *       INT NumToDelete;
     * RETURNS: None.
     */
    VOID DeleteLast( INT NumToDelete = 1 )
    {
      assert(NumToDelete >= 0 && NumToDelete <= FilledSize);
      FilledSize -= NumToDelete;
    } /* End of 'DeleteLast' function */

    /* Add a new element to stock function.
     * ARGUMENTS:
     *   - new data to be add:
     *       Type Object;
     * RETURNS:
     *   (stock &) self reference to stock.
     */
    stock & Add( Type Object )
    {
      /* Check for stock allocated size */
      if (FilledSize == AllocatedSize)
      {
        /* Allocate memory for new elements */
        Type *NewBulk = new Type[AllocatedSize + ForwardAllocation];

        if (FilledSize > 0)
        {
          /* Copy old data */
          for (INT i = 0; i < FilledSize; i++)
            NewBulk[i] = Bulk[i];

          /* Free old data memory */
          delete[] Bulk;
        }
        Bulk = NewBulk;
        /* Increment allocated size */
        AllocatedSize += ForwardAllocation;
      }
      /* Add new element and increment filled counter */
      Bulk[FilledSize++] = Object;
      return *this;
    } /* End of 'Add' function */

    /* Add a new element to stock function.
     * ARGUMENTS:
     *   - new data to be add:
     *       Type Object;
     * RETURNS:
     *   (stock &) self reference to stock.
     */
    stock & operator<<( Type Object )
    {
      Add(Object);
      return *this;
    } /* End of 'operator<<' function */
  }; /* End of 'stock' class */

#endif /* __STOCK_H_ */

/* END OF 'stock.h' FILE */
