#include <stdio.h>
#include <string.h>
#include <rpc/des_crypt.h>

int main()
{
  // A key for encrypting, exactly 8 characters long.
  char key[] = "abcd1234";

  // Fill in the parity bits in the key.
  des_setparity( key );

  // A message to encrypt, exactly 24 characters in length (needs to be a multiple of 8.
  char message[] = "Here, an example message";
  int msgLen = strlen( message );

  // Encrypt the message with the key.
  ecb_crypt( key, message, msgLen, DES_ENCRYPT ); 

  // Print the encrypted message, in Hex, since it probably looks
  // like random garbage.
  printf( "Encrypted Message:\n" );
  for ( int i = 0; i < msgLen; i++ ) {
    printf( "%02x ", (unsigned char) message[ i ] );
    if ( i % 8 == 7 || i + 1 == msgLen )
      printf( "\n" );
  }

  // Decrypt the message using the same key.
  ecb_crypt( key, message, msgLen, DES_DECRYPT ); 

  // We should get our original message back.
  printf( "Decrypted Message:\n" );
  printf( "%s\n", message );	

  return 0;
}
