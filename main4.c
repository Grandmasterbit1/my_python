#include <stdio.h>

char f[10];
int A[10];

void fatoi(char *f)
{
  int m, dig=0;

  for (m=0; m<10; m++)
  {
    A[m]=f[m];
  }
}

int main()
{
  char c;
  int m;
  printf ("Input : \n ");


  fgets( f, 10, stdin );

  fatoi(f);

  for (m=0; m<10; m++)
  {
    printf("%d",A[m]);
  }

return 0;
}
