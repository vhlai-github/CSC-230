#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Check command-line arguments and open the input file.
  FILE *fp;
  if ( ( fp = fopen( "input.txt", "r" ) ) == NULL ) {
    fprintf( stderr, "Can't open file: input.txt\n" );
    exit( EXIT_FAILURE );
  }

  // Allocate a string with a small, initial capacity.
  int capacity = 5;
  char *buffer = (char *)malloc(capacity+1); /* ... add initial call to malloc ... */ ;
  // Number of characters we're currently using.
  int len = 0;
  
  char ch;
  
  // Read from this file until we reach end-of-file, storing all characters
  // in buffer. Keep enlarging the buffer as needed until it contails the
  // contents of the whole file.  This took me 9 lines of code.
  while(fscanf(fp, "%c", &ch)==1){
      if (len >= capacity){
          capacity *= 2;
          buffer = (char *)realloc(buffer, capacity * sizeof(char)); 
      }
      buffer[len] = ch;
      len++;
  }

  // Print out the total size of the file, in characters.
  printf( "%d\n", len );

  // Print out the whole file, it's one big string.
  printf( "%s", buffer );

  // Don't leak memory or open files.
  free(buffer);
  fclose(fp);

  return 0;
}
