#ifndef Concursantes_H_INCLUDED
#define Concursantes_H_INCLUDED
struct Concursantes
{
	int numeroConcursante;
	int nacimiento;
	char nombre[50];
	char dni [10];
	char fechaPresentacion[15];
	char temaPresentacion[100];
	int puntajePrimeraRonda;
	int puntajeSegundaRonda;
	int puntajeTerceraRonda;
	float promedioNotas;
}typedef Concursante;


Concursante* concursante_nuevo();
Concursante*  concursante_nuevoParametros(char* numeroConcursante, char* nacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, char* puntajePrimeraRonda);
int setNuevoConcursante (Concursante* concursanteACargar, int numeroConcursante,int nacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, int puntajePrimeraRonda);
int concursante_setNumeroConcursante(Concursante* this,int numeroConcursante);
int concursante_getNumeroConcursante(Concursante* this,int* numeroConcursante);
int concursante_setNacimiento(Concursante* this,int nacimiento);
int concursante_getNacimiento(Concursante* this,int* nacimiento);
int concursante_setNombre(Concursante* this,char* nombre);
int concursante_getNombre(Concursante* this,char* nombre);
int concursante_setDni(Concursante* this,char* dni);
int concursante_getDni(Concursante* this,char* dni);
int concursante_setFechaPresentacion(Concursante* this,char* fechaPresentacion);
int concursante_getFechaPresentacion(Concursante* this,char* fechaPresentacion);
int concursante_setTemaPresentacion(Concursante* this,char* temaPresentacion);
int concursante_getTemaPresentacion(Concursante* this,char* temaPresentacion);
int concursante_setPuntajePrimeraRonda(Concursante* this,int puntajePrimeraRonda);
int concursante_getPuntajePrimeraRonda(Concursante* this,int* puntajePrimeraRonda);
int concursante_setPuntajeSegundaRonda(Concursante* this,int puntajeSegundoRonda);
int concursante_getPuntajeSegundaRonda(Concursante* this,int* puntajeSegundoRonda);
int concursante_setPuntajeTerceraRonda(Concursante* this, int terceraNota);
int concursante_getPuntajeTerceraRonda(Concursante* this, int* terceraNota);
int concursante_setPromedioNotas(Concursante* this,float promedioNotas);
int concursante_getPromedioNotas(Concursante* this,float* promedioNotas);
int concursante_mostrarConcursante(Concursante*);
int concursante_mostrarConcursanteSinPromedio(Concursante*);
int agregarSegundaNota(void* concursanteVoid);
int agregarTerceraNota(void* concursanteVoid);
int agregarPromedio(void* concursanteVoid);
int calcularNota ();
float calcularPromedio (Concursante* this);
int compararPromedio (void* uno, void* dos);
int agregarPromedioMayor (void* concursanteParam);
int concursantesMasSetenta(void* concursanteParam);
int concursantesGanadores1raRonda(void* concursanteParam, void* puntajeCriterio);
//int elegirGanadores(void* concursanteAnalizar, float promedioMayor);
int elegirGanadores(void* concursanteParam, void* promedioMayor);
void mostrarEncabezado();
float obtenerMayorPromedio(LinkedList* this);
int compararPrimeraNota (void* uno, void* dos);
int compararTerceraNota (void* uno, void* dos);

#endif // Concursantes_H_INCLUDED
