#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED

int controller_cargaTextoConcursantes(char* , LinkedList* pLinkedListConcursantes);
int controller_imprimeConcursantesCargados(LinkedList* miListaConcursantes);

int controller_calcularSegundaNota(LinkedList* miListaConcursantes);

int controller_elegirPromedioMayor(LinkedList* miListaConcursantes);

int controller_generarArchivoGanadores(LinkedList* miListaConcursantes);

int controller_guardarTextoConcursantes(char*, LinkedList* miListaConcursantes);

int controller_guardarTextoUnConcursantes (char* path, Concursante* concursanteGuardar);

int controller_elegirPromedioMayor(LinkedList* miListaConcursantes);

int controller_clasificadosPrimera(LinkedList* miListaConcursantes);

int controller_tresFinalistas(LinkedList* miListaConcursantes);

int controller_terceraNotayGanadoresEstaNota(LinkedList* miListaConcursantes);
#endif // controller_H_INCLUDED
