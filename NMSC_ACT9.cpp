//NANCY MARIA SIQUEIROS CHAVEZ
//MATRICULA: 366239
//FECHA: 9 DE OCTUBRE DEL 2023
//ACTIVIDAD 9 "VECTORES Y MATRICES"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nancymary.h"
#define M 16

int mat[4][4];  
void menu();
void msges();
void llena_vect_sr (int v[], int n, int ri, int rf);
void llenar_mat_sr(int mat[][4], int m, int ri, int rf);
void imprime_vect(int v[], int n);
void imprime_mat(int mat[][4], int m);
void buscar(int v[], int m);


int main()
{
    menu();
}

void msges()
{
    printf("   M  E   N   U \n");
    printf("1.- LLENAR VECTOR (ALEATORIAMENTE) \n");
    printf("2.- LLENAR MATRIZ (ALEATORIAMENTE) \n");
    printf("3.- IMPRIMMIR VECTOR \n");
    printf("4.- IMPRIMIMR MATRIZ \n");
    printf("5.- ORDENAR VECTOR \n");
    printf("6.- BUSCAR VALOR EN VECTOR \n");
    printf("0.- SALIR \n");
}

void menu()
{
    int v[M];
    char msge[30]={"Escoge una opcion"};
    int op;
    do
    {
        msges();
        op = vali_num(0,6,msge);

        switch(op)
        {
        case 1:
            printf("LLENAR VECTOR (ALEATORIAMENTE) \n");
            llena_vect_sr(v, M, 100, 200);
            break;
        case 2:
            printf("LLENAR MARIZ (ALEATORIAMENTE) \n");
            llenar_mat_sr(mat, M, 1, 16);
            break;
        case 3:
            printf("IMPRIMIR VECTOR \n");
            imprime_vect(v, M);
            break;
        case 4:
            printf("IMPRIMIR MATRIZ \n");
            imprime_mat(mat, M);
            break;
        case 5:
            printf("ORDENAR VECTOR \n");
            ordenar(v, M);
            break;
        case 6:
            printf("BUSCAR VALOR EN VECTOR \n");
            buscar(v, M);
            break;
        case 0:
            printf("SALIR \n");
            break;    
        default:
            printf("OPCION NO VALIDA \n");
            break;
        }
    }
    while(op != 0);

}

void llena_vect_sr (int v[], int n, int ri, int rf)
{
    system("CLS");

    printf("LLENAR VECTOR (ALEATORIAMENTE) \n");

    srand(time(NULL));

    int rango, i, num;
    rango = (rf - ri) + 1;

    for (i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % rango) + ri;

        } while (busq_sec(v, 0, i, num) != -1);

        v[i] = num;
    }

    printf("VECTOR LLENADO \n");


    system("PAUSE");

    return menu();
}

void llenar_mat_sr(int mat[][4], int m, int ri, int rf)
{
    system("CLS");
    srand(time(NULL));
    int i, j, k, l;
    bool band;
    int num, rango;

    rango = (rf-ri)+1;

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            mat[i][j]=0;
        }
    }
    if (rango >= m*m)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                do
                {
                    num = (rand()%rango)+ri;
                    band = false;
                    k = 0;
                    while (k < 4 && band==false)
                    {
                        l = 0;
                        while (l < 4 && band == false) 
                        {
                            if (mat[k][l] == num) 
                            {
                                band = true;
                            }
                            l++;
                        }
                        k++;
                    }
                    
                }while(band==true);
                mat[i][j] = num;
            }
        }

    }

    printf("MATRIZ LLENADA \n");

    system("PAUSE");

    return menu();

}


void imprime_vect(int v[], int n)
{
    system("CLS");
    printf("IMPRIMIR VECTOR \n");
    int i;
    for (i = 0; i < 15; i++)
    {
        printf("Vector[%d]:%d \n",i,v[i]);
    }

    system("PAUSE");

    return menu();
}

void imprime_mat(int mat[][4], int m)
{
    system("CLS");
    printf("IMPRIMIR MATRIZ \n");
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("[%3d]",mat[i][j]);
        }
        printf("\n");
    }

    system("PAUSE");

    return;
}

void buscar(int v[], int m)
{
    system("CLS");
    int num, x;
    num = vali_num(100, 200,"Que numero quieres buscar en el vector?: ");

    x = busq_sec(v, M, num, 15);

    if(x != -1)
    {
        printf("El numero que esta buscando SI EXISTE!!");
        printf("El numero %d esta en el indice %d", num, x);
    }
    else
    {
        printf("El numero que esta buscando NO EXISTE!!");
    }

    system("PAUSE");


    return;
}


