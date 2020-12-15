#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Concursantes.h"
#include "../inc/controller.h"
#include "../inc/parser.h"


int controller_cargaTextoConcursantes(char* path, LinkedList* pLinkedListConcursantes)
{
	int retorno = -1;

	if (pLinkedListConcursantes != NULL && path != NULL)
	{
		FILE* fpArchivo;
		fpArchivo = fopen(path, "r");
		if (fpArchivo !=NULL)
		{
			if (parser_concursanteTexto(fpArchivo, pLinkedListConcursantes))
			{
				printf("\nEl archivo de texto se cargo exitosamente");
				retorno = 1;
			}
		}
	}

	return retorno;
}

int controller_imprimeConcursantesCargados(LinkedList* pLinkedListConcursantes)
{
	int retorno = -1;
	int isEmpty = ll_isEmpty(pLinkedListConcursantes);

	if (pLinkedListConcursantes != NULL)
	{
		if (isEmpty)
		{
			printf("\nDebe cargar los concursantes con la opcion 1");
		}else
		{
			int i;
			int len;
			Concursante* aux;
			len = ll_len(pLinkedListConcursantes);
			mostrarEncabezado();
			for (i=0;i<len;i++)
			{
				aux = ll_get(pLinkedListConcursantes, i);

				if (concursante_mostrarConcursante(aux))
				{
					printf("\nHubo un error al mostrar el concursante");
				}
			}
			retorno = 1;
		}
	}

	return retorno;
}

int controller_calcularSegundaNota(LinkedList* miListaConcursantes)
{
	int retorno = -1;

	if (miListaConcursantes != NULL)
	{
		if (ll_map(miListaConcursantes, agregarSegundaNota))
		{
			if (ll_map(miListaConcursantes, agregarPromedio))
			{
				printf("\nSe cargó correctamente la 2da nota y el promedio\n");
				retorno = 1;
			}
		}
	}

	return retorno;
}

int controller_guardarTextoConcursantes (char* path, LinkedList* pLinkedListConcursantes)
{
	int retorno = -1;
	int isEmpty = ll_isEmpty(pLinkedListConcursantes);

	if (path != NULL && pLinkedListConcursantes != NULL && isEmpty == 0)
	{
		int i;
		int len;
		Concursante* aux;
		FILE* fpArchivo;
		int numeroConcursanteAux;
		int nacimientoAux;
		char nombreAux [50];
		char dniAux[10];
		char fechaPresentacionAux[15];
		char temaPresentacionAux[100];
		int puntajePrimeraRondaAux;
		int puntajeSegundaRondaAux;
		int puntajeTerceraRondaAux;
		float promedioNotasAux;

		fpArchivo = fopen(path, "w");

		if(fpArchivo !=NULL)
		{
			len = ll_len(pLinkedListConcursantes);
			fprintf(fpArchivo,"numeroConcursante,anio,nombre,dni,fechapresentacion,temaPresentacion,puntajePrimeraRonda,puntajeSegundaRonda,puntajeTerceraRonda,promedioNotas\n");
				for(i=0; i<len; i++)
				{
					retorno = -1;
					aux =  ll_get(pLinkedListConcursantes,i);
					if(concursante_getNumeroConcursante(aux, &numeroConcursanteAux))
					{
						char numeroConcursanteStr[20];
						sprintf(numeroConcursanteStr,"%d",numeroConcursanteAux);
						if (concursante_getNacimiento(aux, &nacimientoAux))
						{
							char nacimientoStr[20];
							sprintf(nacimientoStr,"%d",nacimientoAux);
							if (concursante_getNombre(aux, nombreAux))
							{
								if (concursante_getDni(aux, dniAux))
								{
									if (concursante_getFechaPresentacion(aux, fechaPresentacionAux))
									{
										if (concursante_getTemaPresentacion(aux, temaPresentacionAux))
										{
											if (concursante_getPuntajePrimeraRonda(aux, &puntajePrimeraRondaAux))
											{
												char puntajePrimeraRondaStr[20];
												sprintf(puntajePrimeraRondaStr,"%d",puntajePrimeraRondaAux);
												if (concursante_getPuntajeSegundaRonda(aux, &puntajeSegundaRondaAux))
												{
													char puntajeSegundaRondaStr[10];
													sprintf(puntajeSegundaRondaStr,"%d",puntajeSegundaRondaAux);
													if (concursante_getPromedioNotas(aux, &promedioNotasAux))
													{
														char promedioNotasStr[20];
														sprintf(promedioNotasStr,"%.2f",promedioNotasAux);
														if (concursante_getPuntajeTerceraRonda(aux, &puntajeTerceraRondaAux))
														{
															char puntajeTerceraRondaStr[10];
															sprintf(puntajeTerceraRondaStr,"%d",puntajeTerceraRondaAux);
															fprintf(fpArchivo,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",numeroConcursanteStr,nacimientoStr, nombreAux, dniAux, fechaPresentacionAux, temaPresentacionAux, puntajePrimeraRondaStr, puntajeSegundaRondaStr, puntajeTerceraRondaStr, promedioNotasStr);
															retorno = 1;
														}else
														{
															printf("\nError al obtener notas de la tercera ronda");
															break;
														}
													}else
													{
														printf("\nError al obtener promedio de notas");
														break;
													}
												}else
												{
													printf("\nError al obtener la 2da nota");
													break;
												}
											}else
											{
												printf("\nError al obtener la 1ra nota");
												break;
											}
										}else
										{
											printf("\nError al obtener el tema de presentacion");
											break;
										}
									}else
									{
										printf("\nError al obtener la fecha de presentacion");
										break;
									}
								}else
								{
									printf("\nError al obtener el dni del concursante");
									break;
								}
							}else
							{
								printf("\nError al obtener el nombre del concursante");
								break;
							}
						}else
						{
							printf("\nError al obtener la fecha de nacimiento del concursante");
							break;
						}
					}else
					{
						printf("\nError al obtener el numero de concursante");
						break;
					}
				}
				fclose(fpArchivo);
		}else if(isEmpty == 1)
		{
			printf("\nEl array esta vacio\n");
		}
		else
		{
			printf("\nHubo un problema al guardar en texto\n");
		}
	}

	return retorno;
}

int controller_guardarTextoUnConcursantes (char* path, Concursante* concursanteGuardar)
{
	int retorno = -1;

	if (path != NULL && concursanteGuardar != NULL)
	{

			int numeroConcursanteAux;
			int nacimientoAux;
			char nombreAux [50];
			char dniAux[10];
			char fechaPresentacionAux[15];
			char temaPresentacionAux[100];
			int puntajePrimeraRondaAux;
			int puntajeSegundaRondaAux;
			int puntajeTerceraRondaAux;
			float promedioNotasAux;
			FILE* fpArchivo;

			fpArchivo = fopen(path, "w");
			if (fpArchivo!=NULL)
			{
				if(concursante_getNumeroConcursante(concursanteGuardar, &numeroConcursanteAux))
				{
						char numeroConcursanteStr[20];
						sprintf(numeroConcursanteStr,"%d",numeroConcursanteAux);
						if (concursante_getNacimiento(concursanteGuardar, &nacimientoAux))
							{
								char nacimientoStr[20];
								sprintf(nacimientoStr,"%d",nacimientoAux);
								if (concursante_getNombre(concursanteGuardar, nombreAux))
								{
									if (concursante_getDni(concursanteGuardar, dniAux))
									{
										if (concursante_getFechaPresentacion(concursanteGuardar, fechaPresentacionAux))
										{
											if (concursante_getTemaPresentacion(concursanteGuardar, temaPresentacionAux))
											{
												if (concursante_getPuntajePrimeraRonda(concursanteGuardar, &puntajePrimeraRondaAux))
												{
													char puntajePrimeraRondaStr[20];
													sprintf(puntajePrimeraRondaStr,"%d",puntajePrimeraRondaAux);
													if (concursante_getPuntajeSegundaRonda(concursanteGuardar, &puntajeSegundaRondaAux))
													{
														char puntajeSegundaRondaStr[10];
														sprintf(puntajeSegundaRondaStr,"%d",puntajeSegundaRondaAux);
														if (concursante_getPromedioNotas(concursanteGuardar, &promedioNotasAux))
														{
															char promedioNotasStr[20];
															sprintf(promedioNotasStr,"%.2f",promedioNotasAux);
															if (concursante_getPuntajeTerceraRonda(concursanteGuardar, &puntajeTerceraRondaAux))
															{
																char puntajeTerceraRondaStr[10];
																sprintf(puntajeTerceraRondaStr,"%d",puntajeTerceraRondaAux);
																fprintf(fpArchivo,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",numeroConcursanteStr,nacimientoStr, nombreAux, dniAux, fechaPresentacionAux, temaPresentacionAux, puntajePrimeraRondaStr, puntajeSegundaRondaStr,puntajeTerceraRondaStr, promedioNotasStr);
																retorno = 1;
															}else
															{
																printf("\nError al obtener notas de la tercera ronda");
															}
														}else
														{
															printf("\nError al obtener promedio de notas");
														}
													}else
													{
														printf("\nError al obtener la 2da nota");
													}
												}else
												{
													printf("\nError al obtener la 1ra nota");
												}
											}else
											{
												printf("\nError al obtener el tema de presentacion");
											}
										}else
										{
											printf("\nError al obtener la fecha de presentacion");
										}
									}else
									{
										printf("\nError al obtener el dni del concursante");
									}
								}else
								{
									printf("\nError al obtener el nombre del concursante");
								}
							}else
							{
								printf("\nError al obtener la fecha de nacimiento del concursante");
							}
					}else
					{
						printf("\nError al obtener el numero de concursante");
					}

			}
			fclose(fpArchivo);
			}


	return retorno;
}
/*
int controller_elegirPromedioMayor(LinkedList* miListaConcursantes)
{
	int retorno= -1;

	if (miListaConcursantes != NULL)
	{
		float promedioMayor;
		LinkedList* miListaTop;
		Concursante* concursantePromedioMayor;
		miListaTop = ll_newLinkedList();
		miListaTop = ll_clone(miListaConcursantes);
		if (ll_sort(miListaTop, compararPromedio, 0))
		{
			concursantePromedioMayor = ll_get(miListaTop, 0);
			if (concursantePromedioMayor != NULL)
			{
				Concursante* aux;
				char dni [10];
				char path [50];
				int i;
				int len;

				if (concursante_getPromedioNotas(concursantePromedioMayor, &promedioMayor))
				{
					ll_clear(miListaTop);
					miListaTop = ll_filter(miListaConcursantes, elegirGanadores, promedioMayor);
					if (miListaTop != NULL)
					{
						len = ll_len(miListaTop);

						if (len > 0)
						{
							for(i=0;i<len;i++)
							{
								aux = ll_get(miListaTop, i);
								concursante_getDni(aux, dni);
								strcpy(path, "C:/Users/Agust/Documents/");
								strcat(path, dni);
								strcat(path, ".csv");
								if (controller_guardarTextoUnConcursantes(path, aux)==-1)
								{
									break;
								}
							}

								if (controller_imprimeConcursantesCargados(miListaTop, 1))
								{
									retorno = 1;
								}
						}
					}
				}
			}
		}
	}

	return retorno;
}
*/

int controller_elegirPromedioMayor(LinkedList* miListaConcursantes)
{
	int retorno= -1;

	if (miListaConcursantes != NULL)
	{
		float* promedioMayor = (float*) malloc(sizeof(float));
		void* promedioMayorVoid = (void*) malloc(sizeof(void));
		float promedioMax;
		char dni [10];
		char path [50];
		int i;
		int len;
		LinkedList* miListaTop;
		Concursante* aux;

		miListaTop = ll_newLinkedList();
		promedioMax = obtenerMayorPromedio(miListaConcursantes);
		*promedioMayor = promedioMax;

		promedioMayorVoid = (void*) promedioMayor;

		miListaTop = ll_filter(miListaConcursantes, elegirGanadores, promedioMayorVoid);

		free(promedioMayor);
		free(promedioMayorVoid);

		if (miListaTop != NULL)
		{
			len = ll_len(miListaTop);
			if (len > 0)
			{
				for(i=0;i<len;i++)
				{
					aux = ll_get(miListaTop, i);
					concursante_getDni(aux, dni);
					strcpy(path, "C:/Users/Agust/Documents/");
					strcat(path, dni);
					strcat(path, ".csv");
					if (controller_guardarTextoUnConcursantes(path, aux)==-1)
					{
						break;
					}
				}
				printf("\nLos ganadores son:\n");
				if (controller_imprimeConcursantesCargados(miListaTop))
				{
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int controller_clasificadosPrimera (LinkedList* miListaConcursantes)
{
	int retorno = -1;

	if (miListaConcursantes != NULL)
	{
		int cantidadClasificados;
		cantidadClasificados = ll_count(miListaConcursantes, concursantesMasSetenta);
		if (cantidadClasificados !=-1)
		{
			printf("\nLa cantidad de clasificados es : %d", cantidadClasificados);
		}else
		{
			printf("\nHubo un problema al contar la cantidad de clasificados");
		}

		retorno = 1;
	}

	return retorno;
}

int controller_tresFinalistas(LinkedList* miListaConcursantes)
{
	int retorno= -1;

	if (miListaConcursantes != NULL)
	{
		int* pNotaCriterio = (int*) malloc(sizeof(int));
		void* pNotaCriterioVoid = (void*) malloc(sizeof(void));
		int notaCriterio;
		char dni [10];
		char path [50];
		int i;
		int len;
		LinkedList* miListaTop;
		LinkedList* miListaOrdenada;
		void* auxVoid;
		Concursante* auxConcursante;

		miListaTop = ll_newLinkedList();
		miListaOrdenada = ll_newLinkedList();
		miListaOrdenada = ll_clone (miListaConcursantes);

		///Clono mi lista y la ordeno.
		if (ll_sort(miListaOrdenada, compararPrimeraNota,0))
		{
			//de esta lista me traigo el tercer concursante
			auxVoid = ll_get(miListaOrdenada, 2);
			auxConcursante = (Concursante*) auxVoid;
			ll_deleteLinkedList(miListaOrdenada);
		}
		//extraigo el puntaje de este 3er concursante ese va a ser mi nota criterio para filtrar
		if (concursante_getPuntajePrimeraRonda(auxConcursante, &notaCriterio))
		{
			*pNotaCriterio = notaCriterio;
			pNotaCriterioVoid = (void*) pNotaCriterio;
			miListaTop = ll_filter(miListaConcursantes, concursantesGanadores1raRonda, pNotaCriterioVoid);
			free(pNotaCriterio);
			free(pNotaCriterioVoid);

			if (miListaTop != NULL)
			{
				len = ll_len(miListaTop);
				if (len > 0)
				{
					Concursante* aux;
					printf("\nLos 3 finalistas de la primera ronda son:\n");
					mostrarEncabezado();
					for(i=0;i<3;i++)
					{
						aux = ll_get(miListaTop, i);
						concursante_getDni(aux, dni);
						strcpy(path, "C:/Users/Agust/Documents/");
						strcat(path, dni);
						strcat(path, ".csv");
						if(concursante_mostrarConcursante(aux))
						{
							if (controller_guardarTextoUnConcursantes(path, aux)==-1)
							{
								retorno = -1;
							}else
							{
								retorno = 1;
							}
						}

					}
					ll_deleteLinkedList(miListaTop);
					}
			}
		}
	}



	return retorno;
}

int controller_terceraNotayGanadoresEstaNota(LinkedList* miListaConcursantes)
{
	int retorno = -1;

	if (miListaConcursantes != NULL)
		{
			if (ll_map(miListaConcursantes, agregarTerceraNota))
			{
				int i;
				LinkedList* miListaTop;
				miListaTop = ll_newLinkedList();
				miListaTop = ll_clone(miListaConcursantes);
				//clono mi lista y la ordeno por la tercera nota
				if (ll_sort(miListaTop, compararTerceraNota, 0))
				{
					printf("\nLos 3 mejores de la tercera ronda son:\n");
					mostrarEncabezado();
					//itero esta lista ordenada e imprimo los primeros tres puestos
					for(i=0;i<3;i++)
					{
						Concursante* aux;
						aux = ll_get(miListaTop, i);
						concursante_mostrarConcursante(aux);
					}
					retorno= 1;
					ll_deleteLinkedList(miListaTop);
				}
			}
		}


	return retorno;
}

/*
int controller_tresFinalistas(LinkedList* miListaConcursantes)
{
	int retorno = -1;

	if (miListaConcursantes != NULL)
	{
		LinkedList* miListaGanadores;
		miListaGanadores = ll_newLinkedList();
		int* puntajeCriterio = (int*) malloc(sizeof(int));
		void* puntajeCriterioVoid = (void*) malloc(sizeof(void));

		*puntajeCriterio = 60;

		puntajeCriterioVoid = (void*) puntajeCriterio;

		miListaGanadores = ll_filter(miListaConcursantes, concursantesGanadores1raRonda, puntajeCriterioVoid);
		if (miListaGanadores!= NULL)
		{
			Concursante* auxElemento;
			int i;
			for(i=0;i<3;i++)
			{
				 auxElemento =	ll_get(miListaGanadores, i);
			}
		}



	}
	return retorno;
}
*/
