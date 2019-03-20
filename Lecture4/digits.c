/**
    @file digits.c
    @author(edits) Vincent H Lai (vhlai)
*/
// Do some I/O and math with unsigned types.

#include <stdlib.h>
#include <stdio.h>



/**
   Add up all the digits in the value, x, and return the sum.
   @param x: number of which digits will be added
*/
unsigned int digitSum( unsigned long x )
{
  unsigned int sum = 0;
  unsigned long remaining = x;
  while (remaining != 0){
      sum = sum + remaining%10;
      remaining = remaining/10;
  }
  return sum;
}

int main()
{
  // Range of values we're supposed to check.
  unsigned long low, high;

  // Target sum we're supposed to look for.
  unsigned int target;

  // Read the range of values from the user.
  int check = scanf("%lu %lu", &low, &high);
  
  if (check < 2){
      return EXIT_FAILURE;
  }

  // Read the digit sum we're supposed to look for.
  check = scanf("%u", &target);
  if (check < 1){
      return EXIT_FAILURE;
  }

  // Check all values from low up to high (inclusive), and report the ones
  // that have the given digit sum.
  for (unsigned long x = low; x <= high; x++){
      unsigned int sum = digitSum(x);
      if (sum == target){
            printf("%lu\n", x);
      }
  }

  return EXIT_SUCCESS;
}
