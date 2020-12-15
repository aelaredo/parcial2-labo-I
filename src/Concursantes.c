#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Concursantes.h"
#include "../inc/controller.h"

Concursante* concursante_nuevo()
{
	Concursante* localConcursante;

	localConcursante = (Concursante*) malloc(sizeof(Concursante));

	return localConcursante;
}


Concursante*  concursante_nuevoParametros(char* numeroConcursanteStr, char* nacimientoStr, char* nombre, char* dni,
			char* fechaPresentacion, char* temaPresentacion, char* puntajePrimeraRondaStr)

{
	Concursante* retornoConcursante = NULL;

	if (numeroConcursanteStr != NULL && nacimientoStr != NULL && nombre != NULL && dni !=NULL && fechaPresentacion!= NULL && temaPresentacion != NULL && puntajePrimeraRondaStr !=NULL)
	{
		Concursante* localConcursante;
		int numeroConcursante;
		numeroConcursante = atoi(numeroConcursanteStr);
		int nacimiento;
		nacimiento = atoi(nacimientoStr);
		int puntajePrimeraRonda;
		puntajePrimeraRonda = atoi(puntajePrimeraRondaStr);

		localConcursante = concursante_nuevo();

			if(!(setNuevoConcursante(localConcursante, numeroConcursante, nacimiento, nombre , dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda))){
				free(localConcursante);
				retornoConcursante = NULL;
			}else{
				retornoConcursante = localConcursante;
			}

	}

	return retornoConcursante;
}

int setNuevoConcursante (Concursante* concursanteACargar, int numeroConcursante,int nacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, int puntajePrimeraRonda)
{
	int retorno = 0;

	if (concursante_setNumeroConcursante(concursanteACargar, numeroConcursante)==1)
	{
		if (concursante_setNacimiento(concursanteACargar, nacimiento)==1)
		{
			if (concursante_setNombre(concursanteACargar, nombre)==1)
			{
				if(concursante_setDni(concursanteACargar, dni)==1)
				{
					if (concursante_setFechaPresentacion(concursanteACargar, fechaPresentacion)==1)
					{
						if (concursante_setTemaPresentacion(concursanteACargar, temaPresentacion)==1)
						{
							if (concursante_setPuntajePrimeraRonda(concursanteACargar, puntajePrimeraRonda)==1)
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

int concursante_setNumeroConcursante(Concursante* this,int numeroConcursante)
{

	int setter = 0;

	if (this != NULL && numeroConcursante > 0)
	{
		this->numeroConcursante = numeroConcursante;
		setter = 1;
	}

	return setter;
}

int concursante_getNumeroConcursante(Concursante* this,int* numeroConcursante){

	int getter = 0;

	if (this != NULL)
	{
		*numeroConcursante = this->numeroConcursante;
		getter = 1;
	}

	return getter;
}

int concursante_setNacimiento(Concursante* this,int nacimiento){

	int setter = 0;

	if (this != NULL && nacimiento > 0)
	{
		this->nacimiento = nacimiento;
		setter = 1;
	}

	return setter;
}

int concursante_getNacimiento(Concursante* this,int* nacimiento){

	int getter = 0;

	if (this != NULL)
	{
		*nacimiento = this->nacimiento;
		getter = 1;
	}

	return getter;
}

int concursante_setNombre(Concursante* this,char* nombre){

	int setter = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		setter = 1;
	}

	return setter;
}

int concursante_getNombre(Concursante* this,char* nombre){

	int getter = 0;

	if (this != NULL)
	{
		strcpy(nombre,this->nombre);
		getter = 1;
	}

	return getter;
}

int concursante_setDni(Concursante* this,char* dni){

	int setter = 0;

	if (this != NULL && dni != NULL)
	{
		strcpy(this->dni, dni);
		setter = 1;
	}

	return setter;
}

int concursante_getDni(Concursante* this,char* dni){

	int getter = 0;

	if (this != NULL)
	{
		strcpy(dni, this->dni);
		getter = 1;
	}

	return getter;
}

int concursante_setFechaPresentacion(Concursante* this,char* fechaPresentacion){

	int setter = 0;

	if (this != NULL && fechaPresentacion != NULL)
	{
		strcpy(this->fechaPresentacion, fechaPresentacion);
		setter = 1;
	}

	return setter;
}

int concursante_getFechaPresentacion(Concursante* this,char* fechaPresentacion){

	int getter = 0;

	if (this != NULL)
	{
		strcpy(fechaPresentacion, this->fechaPresentacion);
		getter = 1;
	}

	return getter;
}

int concursante_setTemaPresentacion(Concursante* this,char* temaPresentacion){

	int setter = 0;

	if (this != NULL && temaPresentacion != NULL)
	{
		strcpy(this->temaPresentacion, temaPresentacion);
		setter = 1;
	}

	return setter;
}

int concursante_getTemaPresentacion(Concursante* this,char* temaPresentacion){

	int getter = 0;

	if (this != NULL)
	{
		strcpy(temaPresentacion, this->temaPresentacion);
		getter = 1;
	}

	return getter;
}

int concursante_setPuntajePrimeraRonda(Concursante* this,int puntajePrimeraRonda){

	int setter = 0;

	if (this != NULL && puntajePrimeraRonda > 0)
	{
		this->puntajePrimeraRonda = puntajePrimeraRonda;
		setter = 1;
	}

	return setter;
}

int concursante_getPuntajePrimeraRonda(Concursante* this,int *puntajePrimeraRonda){

	int getter = 0;

	if (this != NULL)
	{
		*puntajePrimeraRonda = this->puntajePrimeraRonda;
		getter = 1;
	}

	return getter;
}

int concursante_setPuntajeSegundaRonda(Concursante* this,int puntajeSegundoRonda){

	int setter = 0;

	if (this != NULL && puntajeSegundoRonda >= 0)
	{
		this->puntajeSegundaRonda = puntajeSegundoRonda;
		setter = 1;
	}

	return setter;
}

int concursante_getPuntajeSegundaRonda(Concursante* this,int* puntajeSegundoRonda){

	int getter = 0;

	if (this != NULL )
	{
		*puntajeSegundoRonda = this->puntajeSegundaRonda;
		getter = 1;
	}

	return getter;
}

int concursante_setPuntajeTerceraRonda(Concursante* this, int terceraNota){
	int setter = 0;

		if (this != NULL && terceraNota >= 0)
		{
			this->puntajeTerceraRonda = terceraNota;
			setter = 1;
		}

		return setter;
}

int concursante_getPuntajeTerceraRonda(Concursante* this, int* terceraNota){
	int getter = 0;

		if (this != NULL )
		{
			*terceraNota = this->puntajeTerceraRonda;
			getter = 1;
		}

		return getter;

}

int concursante_setPromedioNotas(Concursante* this,float promedioNotas){

	int setter = 0;

	if (this != NULL && promedioNotas >= 0)
	{
		this->promedioNotas = promedioNotas;
		setter = 1;
	}

	return setter;
}

int concursante_getPromedioNotas(Concursante* this,float* promedioNotas){

	int getter = 0;

	if (this != NULL)
	{
		*promedioNotas = this->promedioNotas;
		getter = 1;
	}

	return getter;
}


int concursante_mostrarConcursante(Concursante* this)
{
	int retorno = 1;


	if (this != NULL)
	{
		int numeroConcursante;
		int nacimiento;
		char nombre [50];
		char dni[10];
		char fechaPresentacion[15];
		char temaPresentacion[100];
		int puntajePrimeraRonda;
		int puntajeSegundaRonda;
		int puntajeTerceraRonda;
		float promedioNotas;

		if(concursante_getNumeroConcursante(this, &numeroConcursante))
		{
			if (concursante_getNacimiento(this, &nacimiento))
			{

				if (concursante_getNombre(this, nombre))
				{

					if (concursante_getDni(this, dni))
					{

						if (concursante_getFechaPresentacion(this, fechaPresentacion))
						{

							if (concursante_getTemaPresentacion(this, temaPresentacion))
							{

								if (concursante_getPuntajePrimeraRonda(this, &puntajePrimeraRonda))
								{
									if (concursante_getPuntajeSegundaRonda(this, &puntajeSegundaRonda))
									{
										if (concursante_getPromedioNotas(this, &promedioNotas))
										{
											if(concursante_getPuntajeTerceraRonda(this, &puntajeTerceraRonda))
											{
												printf("\n %4d|| %13d|| %13s|| %10s|| %10s || %45s || %11d || %11d || %11d|| %10.2f ||",  numeroConcursante, nacimiento, nombre,dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, puntajeTerceraRonda,  promedioNotas);
											}

										}
									}

									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}

int concursante_mostrarConcursanteSinPromedio(Concursante* this)
{
	int retorno = 1;


	if (this != NULL)
	{
		int numeroConcursante;
		int nacimiento;
		char nombre [50];
		char dni[10];
		char fechaPresentacion[15];
		char temaPresentacion[100];
		int puntajePrimeraRonda;

		if(concursante_getNumeroConcursante(this, &numeroConcursante))
		{
			if (concursante_getNacimiento(this, &nacimiento))
			{

				if (concursante_getNombre(this, nombre))
				{

					if (concursante_getDni(this, dni))
					{

						if (concursante_getFechaPresentacion(this, fechaPresentacion))
						{

							if (concursante_getTemaPresentacion(this, temaPresentacion))
							{

								if (concursante_getPuntajePrimeraRonda(this, &puntajePrimeraRonda))
								{

									printf("\n %4d|| %13d|| %13s|| %10s|| %10s || %45s || %11d ||      0      ||     0      ||     0       ",  numeroConcursante, nacimiento, nombre,dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda);

									retorno = 0;
								}
							}
						}

					}
				}
			}
		}
	}

	return retorno;
}

int agregarSegundaNota(void* concursanteVoid)
{
	int retorno = -1;

		if (concursanteVoid != NULL)
		{
			Concursante* localConcursante= (Concursante*)concursanteVoid ;
			int segundaNota;
			segundaNota = calcularNota();

				if (concursante_setPuntajeSegundaRonda(localConcursante, segundaNota))
				{
					retorno = 1;
				}
		}
	return retorno;
}


int agregarPromedio(void* concursanteVoid)
{
	int retorno = -1;

	if (concursanteVoid != NULL)
	{
		Concursante* localConcursante= (Concursante*)concursanteVoid ;
		float promedio;

		promedio = calcularPromedio(localConcursante);
		if(concursante_setPromedioNotas(localConcursante, promedio))
		{
			retorno = 1;
		}
	}

	return retorno;
}

int calcularNota (){

	int nota = rand () % (101);

	return nota;
}

float calcularPromedio (Concursante* this){

	float promedio = -1;

	if (this != NULL)
	{

		int segundaNota;
		int primeraNota;

		if (concursante_getPuntajeSegundaRonda(this, &segundaNota))
			{
				if(concursante_getPuntajePrimeraRonda(this, &primeraNota))
				{
					promedio = ((float)primeraNota + (float)segundaNota)/2;
				}
			}
	}

	return promedio;
}

int compararPromedio (void* uno, void* dos){

	int retorno=0;

	Concursante* concursanteUno = (Concursante*) uno;

	Concursante* concursanteDos = (Concursante*) dos;

	float concursanteUnoPromedio;
	float concursanteDosPromedio;

	if (concursante_getPromedioNotas(concursanteUno,&concursanteUnoPromedio))
	{
		if (concursante_getPromedioNotas(concursanteDos,&concursanteDosPromedio))
		{
			if (concursanteUnoPromedio > concursanteDosPromedio)
			{
				retorno = 1;
			}
			else if(concursanteUnoPromedio < concursanteDosPromedio)
			{
				retorno = -1;
			}
		}
	}


	return retorno;
}

int compararPrimeraNota (void* uno, void* dos){

	int retorno=0;

	Concursante* concursanteUno = (Concursante*) uno;

	Concursante* concursanteDos = (Concursante*) dos;

	int concursanteUno1raNota;
	int concursanteDos1raNota;

	if (concursante_getPuntajePrimeraRonda(concursanteUno,&concursanteUno1raNota))
	{
		if (concursante_getPuntajePrimeraRonda(concursanteDos,&concursanteDos1raNota))
		{
			if (concursanteUno1raNota > concursanteDos1raNota)
			{
				retorno = 1;
			}
			else if(concursanteUno1raNota < concursanteDos1raNota)
			{
				retorno = -1;
			}
		}
	}


	return retorno;
}



int compararTerceraNota (void* uno, void* dos){

	int retorno=0;

	Concursante* concursanteUno = (Concursante*) uno;

	Concursante* concursanteDos = (Concursante*) dos;

	int concursanteUno3raNota;
	int concursanteDos3raNota;

	if (concursante_getPuntajeTerceraRonda(concursanteUno,&concursanteUno3raNota))
	{
		if (concursante_getPuntajeTerceraRonda(concursanteDos,&concursanteDos3raNota))
		{
			if (concursanteUno3raNota > concursanteDos3raNota)
			{
				retorno = 1;
			}
			else if(concursanteUno3raNota < concursanteDos3raNota)
			{
				retorno = -1;
			}
		}
	}


	return retorno;
}

/*
int elegirGanadores(void* concursanteParam, float promedioMayor)
{
	int retorno = -1;
	if (concursanteParam != NULL && promedioMayor >= 0)
	{
		Concursante* concursanteAnalizar = (Concursante*) concursanteParam;
		float promedio;
		if (concursante_getPromedioNotas(concursanteAnalizar, &promedio))
		{
			if (promedio == promedioMayor)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
*/

int elegirGanadores(void* concursanteParam, void* promedioMayor)
{
	int retorno = -1;
	if (concursanteParam != NULL && promedioMayor != NULL)
	{
		float promedioAux;
		Concursante* concursanteAnalizar = (Concursante*) concursanteParam;
		if (concursante_getPromedioNotas(concursanteAnalizar, &promedioAux))
		{
			float* promedioMayorFloat;
			promedioMayorFloat = (float*) promedioMayor;
			if (*promedioMayorFloat == promedioAux)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}


int concursantesMasSetenta(void* concursanteParam)
{
	int retorno = -1;

	if (concursanteParam != NULL)
	{
		Concursante* concursanteAnalizar = (Concursante*) concursanteParam;
		char path[50];
		char dni[10];
		int puntajePrimera;
		if (concursante_getPuntajePrimeraRonda(concursanteAnalizar, &puntajePrimera))
		{
			if (puntajePrimera >= 70)
			{
				retorno = 1;
				strcpy(path, "");
				concursante_getDni(concursanteAnalizar, dni);
				strcpy(path, "C:/Users/Agust/Documents/");
				strcat(path, dni);
				strcat(path, ".csv");

				if (controller_guardarTextoUnConcursantes(path, concursanteAnalizar)==-1)
				{
					printf("\nNo se pudo guardar en texto del concursante clasificado");
				}
			}
		}

	}

	return retorno;
}

int concursantesGanadores1raRonda(void* concursanteParam, void* pPrimeraNotaParam)
{
	int retorno = -1;
	if (concursanteParam != NULL && pPrimeraNotaParam != NULL)
	{
		int primerNotaAux;
		Concursante* concursanteAnalizar = (Concursante*) concursanteParam;
		if (concursante_getPuntajePrimeraRonda(concursanteAnalizar, &primerNotaAux))
		{
			int* pPrimeraNota;
			pPrimeraNota = (int*) pPrimeraNotaParam;
			if (primerNotaAux >= *pPrimeraNota)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

/*
int concursantesGanadores1raRonda(void* concursanteParam, void* puntajeCriterio)
{
	int retorno = -1;

	if (concursanteParam != NULL)
	{
		Concursante* concursanteAnalizar = (Concursante*) concursanteParam;

		char path[50];
		char dni[10];
		int puntajePrimera;
		if (concursante_getPuntajePrimeraRonda(concursanteAnalizar, &puntajePrimera))
		{
			int* puntajeCriterioInt;
			puntajeCriterioInt = (int*) puntajeCriterio;
			if (puntajePrimera >= *puntajeCriterioInt)
			{
				retorno = 1;

				strcpy(path, "");
				concursante_getDni(concursanteAnalizar, dni);
				strcpy(path, "C:/Users/Agust/Documents/");
				strcat(path, dni);
				strcat(path, ".csv");

				if (controller_guardarTextoUnConcursantes(path, concursanteAnalizar)==-1)
				{
					printf("\nNo se pudo guardar en texto del concursante clasificado");
				}

			}
		}

	}

	return retorno;
}
*/


void mostrarEncabezado()
{
	printf("\n| N° ||Año nacimiento||        Nombre||        DNI||     Fecha  ||                       Tema                    ||Pje. 1ra Rda.||Pje. 2da Rda.||Pje 3ra Rda.|| Puntaje Promedio|\n");
}


float obtenerMayorPromedio(LinkedList* this)
{
		float retorno = -1;
		if (this != NULL)
		{
			float promedio;
			LinkedList* miListaTop;
			Concursante* concursantePromedioMayor;
			miListaTop = ll_newLinkedList();
			miListaTop = ll_clone(this);
			if (ll_sort(miListaTop, compararPromedio, 0))
			{
				concursantePromedioMayor = ll_get(miListaTop, 0);
				if (concursantePromedioMayor != NULL)
				{
					if (concursante_getPromedioNotas(concursantePromedioMayor, &promedio))
					{
						retorno = promedio;
						ll_deleteLinkedList(miListaTop);
					}
				}
			}

		}


	return retorno;
}

int agregarTerceraNota(void* concursanteVoid)
{
	int retorno = -1;

		if (concursanteVoid != NULL)
		{
			Concursante* localConcursante= (Concursante*)concursanteVoid ;
			int terceraNota;
			terceraNota = calcularNota();

				if (concursante_setPuntajeTerceraRonda(localConcursante, terceraNota))
				{
					retorno = 1;
				}
		}
	return retorno;
}



