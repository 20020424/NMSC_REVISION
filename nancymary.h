
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vali_num(int ri, int rf, const char msge[]);
int busq_sec (int v[], int n, int i, int num);
void ordenar (int v[], int m);

int vali_num(int ri, int rf,const char msge[])
{
    int num;
    char xnum[30];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if(num < ri || num > rf)
        {
            printf("ERROR: El numero debe estar entre %d y %d \n", ri, rf);

        }

    } while(num < ri || num > rf);

   return num;
}

int busq_sec (int v[], int n, int i, int num)
{
    for(i=0;i<n;i++)
    {
        if( num == v[i])
        {
            return i;
        }
    }

    return -1;
}


void ordenar(int v[], int m)
{
    int i,j;
    int temp;

    for (i=0; i<m-1;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[j]<v[i])
            {
                temp = v[i];

                v[i] = v[j];

                v[j] = temp;

            }
        }
    }
}
