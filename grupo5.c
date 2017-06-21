#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct  {
          int dia;
          int mes;
          int anio;
}fecha;

typedef struct
{
          char nombre[50];
          int hora;
          fecha actual;
          char cancha[10];
int numreserva;

} reserva;


void apertura (char reservas[TAM]);
reserva cargar();
void mostrar(reserva dato,char reservas[TAM]);
//void ordenar(reserva dato[30],int N);
//void busqueda(reserva dato[30],int N);



int main(int argc, char const *argv[]) {
  reserva dato[30];
  char reservas[]="reservas.txt";
  int n=0,i,z,q;
apertura (reservas);

  system("cls");
  printf("-------------------- \t --------------------Bienvenido--------------------\t--------------------\n");
do{
  printf("|[1]    Reservar Cancha       |\n");
  printf("|[2]    Mostrar Reservas      |\n");
  printf("|[3]   Ordenar Reservas       |\n");
  printf("|[4]   Modificar Reservas     |\n");
  printf("|[5]        Salir             |\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Ingrese opcion:");
  scanf("%d",&q);
  fgetc(stdin);
  system("cls");

    switch (q) {
      case  1:
       printf("-------------------- \t ---------------Reservar Cancha-------------\t--------------------\n");

        printf("Reserva \n ");
        dato[n]=cargar();
        n++;
        system("cls");
        printf("\n Cargado Correctamente \n");
        break;

          case 2:

        printf("-------------------- \t ------------Lista de Reservas:----------\t--------------------\n");
        if(n==0)
        {
          printf("No hay datos cargados\n\n");
        }
        //ordenar(dato,n);
        for (i=0;i<n;i++)
        {
          printf("Reserva %d \n ",i+1);
          mostrar (dato[i]);
        };
        printf("-------------------- \t --------------------\t --------------------\t--------------------\n");

        break;
        case 3:
        printf("-------------------- \t ------------Ordenar reservas:----------\t--------------------\n");


          case 4:
          printf("-------------------- \t ------------Modificar reservas:----------\t--------------------\n");

            //busqueda(dato,n);
            break;
        case 5:
        printf("Saliste Correctamente\n");
        break;

        default:
        printf("Opcion no valida\n");
        break;
      printf("-------------------- \t --------------------\t --------------------\t--------------------\n");

    }
  }while(q!=5);

  return 0;
}
reserva cargar()
{
FILE *p;
reserva dato;
  int d;
  char reservas[]="reservas.txt";
p=fopen(reservas, "a");

  printf("Nombre Reserva:");
  fgets(dato.nombre,50,stdin);


printf("Hora reserva:");
scanf("%d",&dato.hora);


printf("Fecha de reserva:\n");
printf("Dia:");
scanf("%d", &dato.actual.dia);
printf("Mes:");
scanf("%d", &dato.actual.mes);
printf("Anio:");
scanf("%d", &dato.actual.anio);

fprintf(p,"%s,%d,%d,%d,%d\n\n" ,dato.nombre,dato.hora,dato.actual.dia,dato.actual.mes,dato.actual.anio);

fclose(p);

return dato;
}

void apertura (char reservas[50])
{
FILE *p;
char c;
          p=fopen(reservas,"r");//Apertura en modo lectura
          if(p==NULL)//Si no se pudo abrir, p es igual a NULL
{
                    printf("El archivo NO existe, se intentara crear...\n");
                    p=fopen(reservas,"w");//En modo w, el archivo se crea si no existe
                    if(p==NULL)//Si no se pudo abrir, p es igual a NULL
                    {
                              printf("El archivo NO se pudo crear...\n");

                    }
}
          fclose(p);
return;
}

void mostrar(reserva dato,char reservas[TAM]){
FILE *p;
reserva dato;
          p=fopen(reservas,"r");//Se abre el archivo en modo lectura
while(feof(p)==0)
{
dato=fgetc(p);
if (feof(p)==0)
fscanf(p,"%s,%d,%d,%d,%d\n\n" ,dato.nombre,dato.hora,dato.actual.dia,dato.actual.mes,dato.actual.anio);

}
fclose(p);
return;
}
