//NANCY MARIA SIQUEIROS CHAVEZ
//MATRICULA: 366239
//FECHA: 13 DE OCTUBRE DEL 2023
//ACTIVIDAD 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "nancy.h"
#define N 500

typedef struct Talum{
        char matri;
        char nombre[50];
        char ApPat[50];
        char ApMat[50];
        int edad;
        char sexo[50];
        long matricula;
        int status;   
    }Talum;

int msges();
void menu();
Talum gen_reg_man(void);
Talum gen_reg_aut(void);
void imp_reg(Talum vect[], int n,Talum man[],int j);
void buscar(Talum vect[], int n);
void eliminar(Talum vect[], int n);
Talum ordenar(Talum vect[], int n);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}


int msges()
{
    int op,menu;
    system ("CLS");
    printf ("   M  E   N   U \n");
    printf("1.- AGREGAR AUTOMATICAMENTE \n");
    printf("2.- AGREGAR MANUAL \n");
    printf("3.- IMPRIMIR \n");
    printf("4.- BUSCAR \n");
    printf("5.- ELIMINAR REGISTRO \n");
    printf("6.- ORDENAR REGISTROS \n");
    printf("0.- SALIR  \n");
    op=vali_num(0,6,"ELIGE UNA OPCION:","ERROR");
    return op;
}


void menu()
{
  int i,op,total,tam=0,j,k=0,l;
  Talum vect[N],man[10];
  Talum reg;
    do{
        l = k+10;
        op=msges();
        switch (op)
        {
            case 1:
                for(i=k; i<l; i++)
                {
                    vect[i]=gen_reg_aut();
                    k++;
                }
                
                break;
            case 2:
                vect[k]=gen_reg_man();
                k++;
                break;      
            case 3:
                imp_reg(vect,k,man,j);
                break; 
            case 4:
                buscar(vect,i);
                break;
            case 5:
                eliminar(vect,i);
                break;
            case 6:
                ordenar(vect, k);
                break;			  	  	     
        }
    }while (op != 0);
    system("PAUSE");
}

Talum gen_reg_man(void)
{
    system("CLS");
    Talum reg;
    reg.matricula = vali_num_long(300000,399999,"Ingresa tu matricula: ","ENTRE 300000 Y 399999 ");    
    printf("Escribe tu Nombre: ");
	scanf("%s",&reg.nombre);            
    printf("Escribe tu apellido Paterno: ");
	scanf("%s",&reg.ApPat);           
    printf("Escribe tu apellido Materno: ");
	scanf("%s",&reg.ApMat);
    reg.edad = vali_num(18,100,"Ingresa tu edad: ","ENTRE 18 Y 100");
	printf("Ingresa tu sexo[Hombre o Mujer]:");          
    scanf("%s",reg.sexo);
	return reg;
		
}

Talum gen_reg_aut(void)
{
    Talum reg;
    char mujeres[20][20] = {"NANCY", "NATALIA", "OLIVIA","JOSELYNE","KARLA","DANIELA","VALENTINA","MAYA","ANA","PATRICIA","SARA","SHANON"};
    char hombres[20][20] = {"MARCELO","DANIEL","MILO","EMILIO","SERGIO","ENRIQUE","CESAR","AUGUSTO","GUILLERMO","MIGUEL","JOAQUIN","ANGEL"};
    char ApPat[20][20] = { "SIQUEIROS", "OZUNA", "GARCIA","LIZARRAGA","GONZALEZ","MARTINEZ","JENAROS","MORALES","MENDOZA","OLIVA","LEAL","HENRIQUEZ"};
    char ApMat[20][20] = {"CHAVEZ" , "ORTIZ","RODRIGUEZ","DIAZ","LOZANO","JUAREZ","QUINTERO","ZARAGOZA","CARRILLO","BELTRAN","SANDOVAL","SMITH"};
    reg.status = 1; 
    int sexo,status=1;
	int rango,rf=30,ri=18;
	int rango2,rf2=2,ri2=1;
	long ri3=300000, rf3=399999, rango3;
	rango=(rf-ri)+1;
	reg.edad=(rand()%rango)+ri;
	reg.matri=rand()%100;
	strcpy(reg.ApPat,ApPat[rand()%12]);
	strcpy(reg.ApMat,ApMat[rand()%12]);
	
	rango2=(rf2-ri2)+1;
	sexo=(rand()%rango2)+ri2;
    if (sexo==1)
    {
       	strcpy(reg.sexo,"HOMBRE");
       	strcpy(reg.nombre,hombres[rand()%11]);
    }
    else
    {
       	strcpy(reg.sexo,"MUJER");
        strcpy(reg.nombre,mujeres[rand()%11]);
    } 
    rango3 = ( rf3 - ri3 ) + 1;
    reg.matricula = (rand()%rango3) + ri3;   
    reg.status = status;
    return reg;
}


void imp_reg(Talum vect[], int n,Talum man[],int j)
{
	system("CLS");
	int i;
	printf("   MATRICULA      NOMBRE       APELLIDO PAT    APELLIDO MAT     EDAD        SEXO   \n");
	for(i=0; i<n; i++)
	{
		if (vect[i].status==1)
		{
	        printf("    %6d    %10s    %12s    %12s     %6d    %10s   \n",vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);
	    }
    }	
	getchar();	
}

void buscar(Talum vect[], int n)
{
	
	system("CLS");
	int mati,i,j,com=0;
    mati=vali_num_long(300000,399999,"Matricula que deseas buscar:","LA MATRICULA DEBE ESTAR ENTRE 300000 Y 399999"); 
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
		    for(j=i; j==i; j++) 
			{
				printf("N.    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
				printf("%d.-   %6ld        %8s    %14s       %14s        %5d       %7s      \n",i,vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);	
				com=1;
			}	
		}	   
		   
    }
    if (com==0)
    {
        printf("USUARIO NO ENCONTRADO..\n");
	}

	getchar();	
}

void eliminar(Talum vect[], int n)
{
	system("CLS");
	int mati,i,j,com=0;
	printf("ELIMINAR Matricula\n ");
	mati=vali_num_long(300000,399999,"Ingresa la Matricula que deseas ELIMINAR:","ERROR");
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
		    for(j=i; j==i; j++) 
			{
				vect[i].status=0;
				printf("N.    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
				printf("%d.-   %6ld        %8s    %14s       %14s        %5d       %7s      \n",i,vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);	
				com=1;
			}	
            printf(" \n SE ELIMINO AL ALUMNO CORRECTAMENTE \n");
		}	      
    }
    if (com==0)
    {
        printf("USUARIO NO ENCONTRADO..\n");
	}
	getchar();
}	

Talum ordenar(Talum vect[], int n) 
{
    int i, j;
    Talum burb;
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (vect[i].matricula > vect[j].matricula) 
            {
                burb = vect[i];
                vect[i] = vect[j];
                vect[j] = burb;
            }
        }
    }
    printf("El vector ha sido ordenado por matrícula \n");
    printf("N.    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d.-   %6ld        %8s    %14s       %14s        %5d       %7s      \n",i,vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);
    }

    getchar();

    return vect[n];

}
