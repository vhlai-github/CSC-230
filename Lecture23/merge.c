// Same job as bubble.c, but using mergesort this time.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exitOnError( char const *message )
{
  printf( "%s\n", message );
  exit( EXIT_FAILURE );
}

// Read an input list from the user (there's a
// possible buffer overflow here)
int readList( int *list )
{
  int len;
  if ( scanf( "%d", &len ) != 1 )
    exitOnError( "Can't read input length" );
  
  for ( int i = 0; i < len; i++ )
    if ( scanf( "%d", list + i ) != 1 )
      exitOnError( "Can't read list item" );

  return len;
}

// Sort the given list using merge sort.
void sortList( int *list, int len )
{
  // A trivial list is already sorted.
  if ( len <= 1 )
    return;

  // Split list into two smaller lists, each about half as
  // long as the original list.

  // Length of the storage for the two half lists.
  int alen = ( len + 1 ) / 2;
  int blen = len / 2;

  // Storage for the two half lists.
  int a[ alen ];
  int b[ blen ];

  int pos = 0; // Current position in list.
  // Copy the first half (alen elements) of list[] to a[]

  for (int x = 0; x < alen; x++){
      a[x] = list[x];
      pos++;
  }

  // Copy the rest of list[] (the remaining blen elements) to b[]

  for (int x = 0; x < blen; x++){
      b[x] = list[pos];
      pos++;
  }


  // Recursively sort the two smaller lists.
  sortList( a, alen );
  sortList( b, blen );

  // Merge the two smaller lists into one sorted lists.

  // Current position in each of the lists.
  pos = 0;
  int apos = 0;
  int bpos = 0;

  // Merge, Repeatedly take the next item from a[] or b[] whichever
  // is smaller, copying it to the next position in list[]

  for(int x = 0; x < len; x++){
      if(a[apos]<=b[bpos]){
          list[x] = a[apos];
          apos++;
      }
      else if(a[apos]>b[bpos]){
          list[x] = b[apos];
          bpos++;
      }
  }
}

// Pint out a (hopefully sorted) list.
void printList( int *list, int len )
{
  for ( int i = 0; i < len; i++ ) {
    printf( "%d", list[ i ] );
    // fencepost behavior.
    if ( i + 1 < len )
      printf( " " );
  }
  printf( "\n" );
}

int main()
{
  int list[ 25000 ];
  
  int len = readList( list );
  sortList( list, len );
  printList( list, len );

  return 0;
}
