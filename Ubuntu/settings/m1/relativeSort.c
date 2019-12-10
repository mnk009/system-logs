#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/* compare for ptr to integer */
int cmppi(const void *p0, const void *p1){
    return (*(int *)p0 - *(int *)p1);
}

/* compare for ptr to ptr to integer */
int cmpppi(const void *p0, const void *p1){
    return (**(int **)p0 - **(int **)p1);
}

int main()
{
int first[] =  {2,1, 2,5, 7, 1, 9, 3, 6, 8, 8};
int second[] = {2, 1, 8, 3};
int **ap;                               /* array of pointers */
int *tmpp;
int tmpi;
size_t i, j;

    /* allocate and generate array of pointers to first[] */
    ap = (int **)malloc(sizeof(first)/sizeof(first[0])*sizeof(int *));
    for(i = 0; i < sizeof(first)/sizeof(first[0]); i++)
        ap[i] = &first[i];
    /* sort ap  */
    qsort(ap, sizeof(first)/sizeof(first[0]), sizeof(int *), cmpppi);
    /* sort second */
    qsort(second, sizeof(second)/sizeof(second[0]), sizeof(int), cmppi);
    /* reorder ap and second in place using ap as rank (O(n) time) */
    for (i = 0; i < sizeof(second) / sizeof(second[0]); i++){
        while(i != (j = ap[i] - first)){
            tmpp = ap[i];               /* swap(ap[i], ap[j]) */
            ap[i] = ap[j];
            ap[j] = tmpp;
            tmpi = second[i];           /* swap(second[i], second[j] */
            second[i] = second[j];
            second[j] = tmpi;
        }
    }   
    /* display second[] */
    for (i = 0; i < sizeof(second) / sizeof(second[0]); i++)
        printf("%3d", second[i]);
    printf("\n");
    free(ap);
    return 0;
}
