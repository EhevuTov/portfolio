#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] ) {
  
  unsigned short i = 129;
  float f = 3.14;
  unsigned char* s = "Hello, World!";
  char buff[100];

  typedef struct packet {
    unsigned short i;
    float f;
    char s[13];
  };

  printf ( "short: %u\n", i );
  printf ( "float: %f\n", f );
  printf ( "string: %s\n", s );

  memcpy ( buff, &i, sizeof( unsigned short ) );
  memcpy ( buff + sizeof( unsigned short ), &f, sizeof( float ) );
  memcpy ( buff + sizeof( unsigned short ) + sizeof( float ), s, strlen( s ) );

  for (int i = 0; i < 30; i++) {
    printf ( "%02X\n", buff[i] );
  };

  struct packet output;
  output.i  = (unsigned short) (buff[0]);
  output.f  = (float) (buff[0 + sizeof(unsigned short)]);

  printf ( "packet short: %u\n", output.i );
  printf ( "packet float: %f\n", output.f );

  return 1;
}
