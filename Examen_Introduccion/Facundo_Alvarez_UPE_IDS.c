#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cant 450

struct datos{
             char dni[9];     /*nomb_ape para nombre y apellido. acomp para la cantidad de acompañantes*/
             char cargo[2];
             char nomb_ape[91];
             short acomp;
};

int main(void)
{
    struct datos invitado[cant];
    short indice=0;
    short c_invitados;       /*contador para cantidad de invitados*/
    short espacio_restante=0;
    char salir;              /*variable que utilizo para salir de cada ciclo*/
    short validacion_cargo=0;/*variable que utilizo para salir del ciclo de cargo,donde compruevo que el usuario ingrese uno de los carcteres que corresponden*/
    short validacion_acomp=0;/*variable que utilizo para salir del ciclo de cantidad de acompañantes para que no ingresen mas personas que la cap. maxima*/
    short verificacion_acomp=0;// variable utilizada para que no ingresen mas acomp de los que cargo el usuario
    short suma=0;/*variable que utilizo para calcular el porcentaje del salon ocupado*/
    short cont_invitados=0;/*variable que utilizo para contar la cantidad de invitados separada de la suma total de personas*/
    short cont_docente=0;/*contador de docentes*/
    float porc_ocupado=0;/*porcentaje del salon ocupado*/

    struct datos auxiliar;/*para uso de ordenamiento*/
    short r=0;
    short no_ordenado=0;

    char dni_buscado[9];


printf("\n\t\tRegistro para fiesta en UPE\n\n");

             while(indice<cant && salir!='y')/*primer ciclo donde ingresamos todos los datos de invitado*/
            {
                validacion_cargo=0;
                cont_invitados++;

                 printf("Ingrese dni: ");
                  scanf("%8[0-9 mf][^\n]s",invitado[indice].dni);//por si son personas mayores de edad que tiene letras en su dni y
                                                                   // por si el usuario ingresa + de 8 numero no se guardan

                  fflush(stdin);

                  while(validacion_cargo==0)
                    { //aca empieza el ciclo de validacion para el cargo


                   printf("Ingrese el caracter correspondiente para su cargo\n \n\t Docente: d \n\t Administrativo: a \n\t Jerarquico: j \n\t otro:o \n escriba el caracter aqui: ");
                  scanf("%2[dajoDAJO][^\n]s",invitado[indice].cargo);/*para que si el usuario ingrese otro caracter no pueda seguir y si
                                                                      ingresa mas de un caracter solo se gaurde el primero, ademas, se le agrega su 
				                                                      respectiva mayus a cada letra por si el usuario tiene el teclado en mayuscula*/
                  fflush(stdin);

                    if(invitado[indice].cargo[0]=='a' || invitado[indice].cargo[0]=='A')
                       {validacion_cargo++;}
                       else
                       {if(invitado[indice].cargo[0]=='d' || invitado[indice].cargo[0]=='D')
                           {validacion_cargo++;}
                           else
                            {if(invitado[indice].cargo[0]=='j' || invitado[indice].cargo[0]=='J')
                            {validacion_cargo++;}
                                else
                                    {if(invitado[indice].cargo[0]=='o' || invitado[indice].cargo[0]=='O')
                                    {validacion_cargo++;}
                                        else
                                            {printf("Por favor ingrese una de las opciones!! \n\n");}
                                    }
                            }
                       }

                    };/*solo permito que ingrese un solo dato,lo que ingrese despues no se va a guardar, y ademas que ingrese solo los caracteres que le pido
                        ciclo donde meto al usuario hasta que ingrese el dato correspodiente, con validacion con if*/



                    fflush(stdin);

                     printf("Ingrese nombre y apellido sin separaciones: ");
                      scanf("%90[^\n]s",invitado[indice].nomb_ape);
                       fflush(stdin);

                 validacion_acomp=0;

                    while(validacion_acomp==0)/*ciclo de validacion_acomp para que no desborde la capacidad maxima*/
                    {
                       c_invitados=0;
                       c_invitados++;

                       printf("Ingrese la cantidad de acompaniantes: ");
                        scanf("%hd",&invitado[indice].acomp);
                        fflush(stdin);


                        suma=invitado[indice].acomp+c_invitados+suma;
                        espacio_restante=cant-suma;

                        if(espacio_restante<0)
                        {
                            printf("\nSupera el max de cupo\n");
                            suma=suma-invitado[indice].acomp-c_invitados;

                        }
                           else
                           {
                               if(espacio_restante==0)   //en caso de que el espacio restante sea 0 se termina el ingreso de datos
                                                         //porq se llega al numero max de personas que pueden igresar a la fiesta
                               {
                                   salir='y';
                                    validacion_acomp++;
                               }
                                 else
                                 {
                                     printf("\n\tCantidad aceptada\n");
                                     validacion_acomp++;
                                 }
                           }




                    }
                          if(salir!='y')
                            {
                           printf("\nPara finalizar ingrese y: ");
                                    scanf("%c",&salir);
                                    fflush(stdin);
                                    indice++;
                                    printf("\n");
                            }

            }//llave para primer while;

printf("\n\t----------\n");

            suma=suma-cont_invitados;
             printf("\ncantidad total de personas inscriptas es:%hd \n la cantidad de acompaniantes es:%hd\n\n",cont_invitados,suma);
/*ordenamiento de los vectores*/
             do{
                    r++;
                    no_ordenado=0;

             for(indice=0;indice<cont_invitados-r;indice++)


                if(strcmp(invitado[indice].dni,invitado[indice+1].dni)>0)
              {
                 		auxiliar=invitado[indice];
		                invitado[indice]=invitado[indice+1];
		                invitado[indice+1]=auxiliar;
		                no_ordenado=1;
              }


             }while(no_ordenado==1);
             salir=0;
             printf("\n\t----------\n");
             printf("\t\tDia de la fiesta\n");
             do{/*ciclo donde ingresamos los dni y verifica que el dni este inscripto*/
                    fflush(stdin);
                    validacion_acomp=0;
                    indice=0;

                    printf("Ingrese DNI: ");
                     scanf("%8[0-9 mf][^\n]s",dni_buscado);
                     fflush(stdin);

                     while(strcmp(invitado[indice].dni,dni_buscado)!=0 && indice<cant)/*busqueda secuencial*/
                     {
                        indice++;
                     }

                         if(strcmp(dni_buscado,invitado[indice].dni)==0)
                         {
                             if(validacion_acomp==0)/*si pasa la verificacion de dni, se pasa a ver que la cantidad de gente que lo acompaña sea igual o menor a lo inscripto*/
                             {
                                 printf("\nCuantas personas lo acompanian: ");
                                  scanf("%hd",&verificacion_acomp);
                                   fflush(stdin);
                                   if(verificacion_acomp>invitado[indice].acomp)
                                   {
                                       printf("La cantidad ingresada es mayor a los lugares reservados\n");
                                       validacion_acomp++;
                                   }
                                   else
                                   {
                                       printf("\nCantidad de acompaniantes aceptada\n");
                                       invitado[indice].acomp=verificacion_acomp;
                                   }
                             }
                         }
                         else
                         {
                             printf("\nDNI no registrado!!\n");
                         }

                    printf("\nSi desea finalizar ingrese y: ");
                     scanf("%c",&salir);
                      fflush(stdin);

             }while(salir!='y');

printf("\n\t----------\n");
             indice=0;
/*ciclo final, donde imprimimos en pantalla los dni,cargo y nombre y apellido de todos los invitados*/
            do
               {
                   printf("%s\t",invitado[indice].dni);
                   printf("%s\t",invitado[indice].nomb_ape);

                   if(invitado[indice].cargo[0]=='a' || invitado[indice].cargo[0]=='A')
                       {printf("Adminstrativo\n");}
                       else
                       {if(invitado[indice].cargo[0]=='d' || invitado[indice].cargo[0]=='D')
                           {printf("Docente\n");
                            cont_docente++;
                           }
                           else
                            {if(invitado[indice].cargo[0]=='j' || invitado[indice].cargo[0]=='J')
                            {printf("Jerarquico\n");}
                                else
                                    {if(invitado[indice].cargo[0]=='o' || invitado[indice].cargo[0]=='O')
                                    {printf("Otro\n");}

                                    }
                            }
                       }
                       indice++;
               } while(indice<cont_invitados);
               suma=0;
/*ciclo for que utilizo para contar la cantidad total de personas que asistieron a la fiesta(igualo suma a cero porq es una variable que utilice anteriormente y tenia datos almacenados)*/
               for(indice=0;indice<cont_invitados;indice++)
               {
                   suma=invitado[indice].acomp+c_invitados+suma;
               };
               porc_ocupado=(float)(suma*100)/cant;

               printf("\tCantidad total de docente  ==>%hd\n",cont_docente);
               printf("\tCantidad total de personas ==>%hd\n",suma);
               printf("\tPorcentaje ocupado         ==>%.2f%%\n\n",porc_ocupado);

    return 0;
}
