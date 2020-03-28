#include <stdio.h>

int count_digits(char *f)
{
  int m, k, dig=0;

  for (m=0; m<10; m++)
  {
  for (k = 48; k < 58; k++)
    if (f[m]==k)
      {dig++;}

  }

return dig;
}

int main()
{

  char f[10];

  printf( "Input: " );

  fgets( f, 10, stdin );

  printf("dig count:%d", count_digits(f));

return 0;
}
