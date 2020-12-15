/*
 ============================================================================
 Name        : parcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Concursantes.h"
#include "../inc/controller.h"



int main(void) {
	int menu;
	char archivo [20];
	char pathLeer [150];
	char pathEscribir [150];

	LinkedList* miListaConcursantes;

	int flagSegunda = 0;
	int flagPrimera = 0;

	miListaConcursantes = ll_newLinkedList();


	do
	{
		fflush(stdin);
		fflush(stdout);
		printf("\nSeleccione\n1. Para cargar datos.\n2. Para imprimirlos una vez cargados.\n3. Para cargar la 2da nota\n4. Guardar en .csv\n5. Elegir ganadores y guardarlos.\n6. Contar clasificados primera (+70 puntos) y guardarlos separados\n7. Mostrar y guardar 3 mejores de la primera ronda (punto 8/9 recu)\n8. Agregar nota 3ra ronda y mostrar los 3 mejores de esa ronda  (punto 9 recu)");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &menu);

		switch(menu)
		{
			case 1:
				if (!flagPrimera)
				{
					strcpy(pathLeer, "C:/Users/Agust/Documents/");
					strcpy(archivo, "2doparcial.csv");
					strcat(pathLeer, archivo);
					if(controller_cargaTextoConcursantes(pathLeer, miListaConcursantes)==-1)
					{
						printf("\n Hubo un problema al cargar el archivo de texto");
					}
					flagPrimera = 1;
				}else
				{
					printf("\n Ya se cargo el archivo al sistema");
				}
			break;
			case 2:
				if(controller_imprimeConcursantesCargados(miListaConcursantes)==-1)
				{
					printf("\nHubo un problema imprimir la lista");
				}
			break;
			case 3:
				if (controller_calcularSegundaNota(miListaConcursantes)==-1)
				{
					printf("\nHubo un problema al asignar la segunda nota");
				}
				flagSegunda = 1;
			break;
			case 4:
				strcpy(archivo, "2doparcial.csv");
				strcpy(pathEscribir, "C:/Users/Agust/Documents/resultado");
				strcat(pathEscribir, archivo);
				if (controller_guardarTextoConcursantes(pathEscribir, miListaConcursantes))
				{
					printf("\nSe guardaron exitosamente los concursantes\n");
				}else
				{
					printf("\nHubo un problema al guardar en texto a los concursantes");
				}
				break;
			case 5:
				if (!(flagSegunda))
				{
					printf("\nDebe asignar la 2da nota para elegir ganador");

				}else
				{
					if(controller_elegirPromedioMayor(miListaConcursantes)==-1)
					{
						printf("\nHubo un problema al elegir el promedio mayor");
					}
				}
				break;
			case 6:
				if(controller_clasificadosPrimera(miListaConcursantes)==-1)
				{
					printf("\nHubo un problema al contar los clasificados");
				}
				break;
			case 7:
				if(controller_tresFinalistas(miListaConcursantes)==-1)
				{
					printf("\nHubo un problema al elegir los tres finalistas de la primera ronda");
				}
				break;
			case 8:
				if(controller_terceraNotayGanadoresEstaNota(miListaConcursantes)==-1)
				{
					printf("\nHubo un problema al asignar la tercera nota y a los ganadores de esta nota");
				}
				break;
		}

	}while (menu!=9);

	return 0;
}
