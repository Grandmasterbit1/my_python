#include <stdio.h>
void Ex9(void)
{
    int matrix[5][6]={{7,4,78,66,4,9},{5,8,3,56,87,22},{16,15,1,8,0,8},{12,19,28,4,6,9},{55,34,85,71,21,30}};
    int s=0, k,a,c=0;
    for (k = 0; k < 8; ++k)
    {
a=matrix[0][k];
        for (s = 1; s < 5; ++s)
           if( matrix[s][k]<a)
            {
                a=matrix[s][k];c=s;
           }
        printf("matrix[%d][%d] \t%d\n",c,k,a);
    }

}
 int main(void)
{

     Ex9();
return 0;
 }
