#include <math.h>
#include <stdio.h>
int main()
{
    int n, calories_i, i, j; 
    printf("Enter the number of sweets consumed \n");
    scanf("%d",&n);
    int *calories = malloc(sizeof(int) * n);
    for(calories_i = 0; calories_i < n; calories_i++){
       scanf("%d",&calories[calories_i]);
    }
    unsigned long int run=0;
    for(i=0;i<n;i++)
    {
        int max=calories[0],maxi=0;
        for(j=1;j<n;j++)
        {
            if(max<calories[j] && calories[j]>=0)
            {
                max=calories[j];
                maxi=j;
            }
        }
        calories[maxi]=-1;
        run+=max*pow(2,i);
    }
    printf("\nThe least distance to be covered is: \n");
    printf("%lu miles",run);
    return 0;
}

