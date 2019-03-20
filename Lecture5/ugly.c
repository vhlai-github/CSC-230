// Same prime-detection strategy, but without any structured
// looping constructs.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Report a list of prime values.
 */
int main( void )
{
  // Get the range of values we're supposed to test.
  unsigned int low, high;
  if ( scanf( "%d%d", &low, &high ) != 2 ) {
    printf( "Invalid input\n" );
    exit( EXIT_FAILURE );
  }
  
  // Write your own, ugly solution, using goto instead of structured looping.

  int i = low;
  int val = 0;
  int check = 0;
  
  mainLoop: 
  if (check == 1){
      printf("%u\n", i);
      i++;
  }
  if (i >= high){
      goto doneWithMain;
  }
  else{
  goto checkPrime;
  }
  
  
  checkPrime:
  val = i;
  unsigned int fact = 2;
  
  checkPrimeLoop:
  if (fact*fact > val){
      check =1;
      goto mainLoop;
  }
  else if(val%fact == 0){
      check = 0;
      i++;
      goto mainLoop;
  }
  else {
      fact++;
      goto checkPrimeLoop;
  }
  
  doneWithMain:
  
  return EXIT_SUCCESS;
}
