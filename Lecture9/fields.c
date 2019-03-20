#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  // Open the input file and print an error message if we're unsuccessful.
  // (the error message is mostly to help you with debugging.  We won't test
  // this behavior).
  
  FILE *f = fopen("input.txt", "r");
  if ( !f ) {
    fprintf( stderr, "Can't open input file\n" );
    exit( 1 );
  }

  // Counting input lines, so we can report errors.
  int lineCount = 1;
 
  // Keep reading input lines until we reach the end-of-file.
  // Write an output line or an error message for each one.
  
  //Venus Jensen 33770530841 vbjensen@oqtu.edu FRNO 624-771-4676 SIJ SBE WHV TVW
  char id[9];
  char fname[12];
  char lname[12];
  char phone1[4];
  char phone2[4];
  char phone3[5];
  int check;
while ((check = fscanf(f, "%11s %11s %*d %8[a-z]%*[@.a-z] %*[A-Z] %3[0-9] %*c %3[0-9] %*c %4[0-9]", fname, lname, id, phone1, phone2, phone3)) != EOF){
    if(check < 6){
        fprintf(stderr, "Invalid input, line %d\n", lineCount);
        fscanf(f, " %*[^\n]%*c");
    }
    else{
        printf("%8s %11s %11s (%3s)%3s-%4s\n", id, fname, lname, phone1, phone2, phone3);
        fscanf(f, "%*[A-Z ] %*[\n]");
    }
    lineCount++;
}
fclose(f);
  return EXIT_SUCCESS;
}
