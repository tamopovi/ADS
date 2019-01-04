#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    f = fopen("f7.txt","ab+");
    /*int i = 0;
    for (i = 0; i< 2000; i++)
    {
        fprintf(f,"%d ",i);
        if (i == 1999)
            fprintf(f,"%d",i);

    }*/
    int i, n;
    time_t t;

    n = 5;

   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
       if (i == n-1)
            fprintf(f,"%d", rand() % 50);
      else
            fprintf(f,"%d ", rand() % 50);
   }
    fclose(f);
    return 0;
}
