#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Concursantes.h"
#include "../inc/parser.h"

int parser_concursanteTexto(FILE* pFile, LinkedList* pLinkedListConcursantes)
{
	int retorno = -1;

	if (pFile != NULL && pLinkedListConcursantes != NULL)
	{
			Concursante* localConcursante;
			char numeroConcursante[50];
			char nacimiento[50];
			char nombre[50];
			char dni [10];
			char fechaPresentacion[15];
			char temaPresentacion[100];
			char puntajePrimeraRonda[50];


			while(!feof(pFile))
				{
					if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numeroConcursante, nacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda)==7)
					{
						localConcursante = concursante_nuevoParametros(numeroConcursante, nacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda);
						if (localConcursante != NULL)
						{
							concursante_setPuntajeSegundaRonda(localConcursante,0);
							concursante_setPuntajeTerceraRonda(localConcursante,0);
							concursante_setPromedioNotas(localConcursante, 0);
							if (ll_add(pLinkedListConcursantes, localConcursante)== 0)
							{
								retorno = 1;
							}
						}
					}
				}
			fclose(pFile);
	}

	return retorno;
}
