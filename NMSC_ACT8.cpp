//NANCY MARIA SIQUEIROS CHAVEZ
//MATRICULA: 366239
//FECHA: 29 DE SEPTIEMBRE DEL 2023
//ACTIVIDAD 8


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define M 10
int mat[4][4];
void menu();
int msges();
int vali_num(int ri, int rf, char msge[]);
void llenar_vect_manual(int vect[], int m, int ri, int rf);
void llenar_vect_alea(int vect[], int m, int ri, int rf);
void llenar_vect_2vect(int vect_1[], int vect_2[], int vect_3[], int m);
void imprime_vect(int vect_1[], int vect_2[], int vect_3[], int m);
void llena_mat(int mat[][4], int vect_1[], int vect_2[], int m, int n);
void imprime_mat(int mat[][4], int filas, int columnas);


int main()
{
    menu();
}

int msges()
{
    int op;
    printf("   M  E   N   U \n");
    printf("1.- LLENAR VECTOR 1(MANUALMENTE) \n");
    printf("2.- LLENAR VECTOR 2(ALEATORIAMENTE) \n");
    printf("3.- LLENAR VECTOR 3(VECTOR 1 Y VECTOR 2) \n");
    printf("4.- IMPRIMIR VECTORES \n");
    printf("5.- LLENAR MATRIZ 4X4 \n");
    printf("6.- IMPRIMIR MATRIZ \n");
    printf("0.- SALIR \n");
    printf("OPCION: ");
    scanf("%d", &op);

    return op;
}

void menu()
{
    int op, vect_1[M], vect_2[M], vect_3[M*2];
    do
    {
        op = msges();
        switch(op)
        {
        case 1:
            printf("LLENAR VECTOR 1 \n");
            llenar_vect_manual(vect_1, M, 30, 70);
            break;
        case 2:
            printf("LLENAR VECTOR 2 \n");
            llenar_vect_alea(vect_2, M, 1, 10);
            break;
        case 3:
            printf("LLENAR VECTOR 3 \n");
            llenar_vect_2vect(vect_1, vect_2, vect_3, M);
            break;
        case 4:
            printf("IMPRIMIR VECTORES \n");
            imprime_vect(vect_1, vect_2, vect_3, M);

            break;
        case 5:
            printf("LLENAR MATRIZ 4X4 \n");
            llena_mat(mat, vect_1, vect_2, 4, 4);
            break;
        case 6:
            printf("IMPRIMIR MATRIZ \n");
            imprime_mat(mat, 4, 4);
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

int vali_num(int ri, int rf, char msge[])
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

void llenar_vect_manual(int vect_1[], int m, int ri, int rf)
{
    system("CLS");
    char msge[100] = "Dame un numero entre el 30 y el 70: ";
    int i;
    for(i=0;i<m;i++)
    {
        vect_1[i] = vali_num(ri, rf, msge);    
    }

    printf("VECTOR 1 LLENADO \n");

    system("PAUSE");
    
}

void llenar_vect_alea(int vect_2[], int m, int ri, int rf)
{
    system("CLS");
    srand(time(NULL));
    int ind = 0;
    int i;

    while (ind < 10) 
    {
        int numalea = rand() % 20 + 1;

        bool repetido = false;
        for (int i = 0; i < ind; i++) 
        {
            if (vect_2[i] == numalea) 
            {
                repetido = true;
                break;
            }
        }

        if (!repetido) 
        {
            vect_2[ind] = numalea;
            ind++;
        }
    }

    printf("Vector generado:\n");

    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", vect_2[i]);
    }
    printf("\n");

    printf("VECTOR 2 LLENADO \n");

    system("PAUSE");


}

void llenar_vect_2vect(int vect_1[], int vect_2[], int vect_3[], int m)
{
    system("CLS");
    int i;
    for(i=0;i<m;i++)
    {
        vect_3[i] = vect_1[i];
        vect_3[i+m] = vect_2[i];
    }

    printf("VECTOR 3 LLENADO \n");

    system("PAUSE");

}

void imprime_vect(int vect_1[], int vect_2[], int vect_3[], int m)
{
    system("CLS");

    int i;
    printf("vect_1: ");
    for(i=0;i<m;i++)
    {
        printf("%d ", *(vect_1+i));
    }
    printf("\n");

    printf("vect_2: ");
    for(i=0;i<m;i++)
    {
        printf("%d ", *(vect_2+i));
    }
    printf("\n");

    printf("vect_3: ");
    for(i=0;i<2*m;i++)
    {
        printf("%d ", *(vect_3+i));
    }
    printf("\n");

    system("PAUSE");
}

void llena_mat(int mat[][4], int vect_1[], int vect_2[], int m, int n)
{
    system("CLS");

    int i, j, k, l;
    k=0;
    l=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(k<m)
            {
                mat[i][j] = vect_1[k];
                k++;
            }
            else
            {
                mat[i][j] = vect_2[l];
                l++;
            }

        }
    }

    printf("MATRIZ LLENADA \n");

    system("PAUSE");
}


void imprime_mat(int mat[][4], int filas, int columnas) 
{
    system("CLS");


    for (int i = 0; i < filas; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    system("PAUSE");
}

