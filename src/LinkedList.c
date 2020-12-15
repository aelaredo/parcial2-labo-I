#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* pNodoAux = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {

    		pNodoAux = this->pFirstNode;
    		for(i=0;i<nodeIndex;i++)
    		{
    			pNodoAux = pNodoAux->pNextNode;
    		}

    }

    return pNodoAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoNuevo;
    Node* pNodoAnterior;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	pNodoNuevo = (Node*) malloc(sizeof(Node));
    	if (pNodoNuevo != NULL)
    	{
    		this->size++;
    		pNodoNuevo->pElement = pElement;
    		if (nodeIndex == 0)
    		{
    			pNodoNuevo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNodoNuevo;
    		}else
    		{
    			pNodoAnterior = getNode(this, nodeIndex-1);
    			pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
    			pNodoAnterior->pNextNode = pNodoNuevo;
    		}
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if (addNode(this, ll_len(this),pElement)==0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if (this != NULL)
    {
    	Node* nodoAux;
    	nodoAux = getNode(this, index);

    	if(nodoAux!=NULL)
    	{
    		returnAux = nodoAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    if (this != NULL && index < ll_len(this))
    {
    	Node* nodoAux;
    	/*
    	 if( addNode(this, index,pElement)==0 )
    	 {
    		 returnAux = 0;
    	 }
    	 */

    	nodoAux = getNode(this, index);
    	if (nodoAux !=NULL)
    	{
    		nodoAux->pElement = pElement;
    		returnAux = 0;
    	}
    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodoBorrar;
    Node* pNodoAnterior;
    Node* pNodoSiguiente;

    if (this != NULL)
    {
    	if (index >= 0 && index < ll_len(this))
    	{
    		pNodoBorrar = getNode(this, index);
    		if (pNodoBorrar != NULL)
    		{
    			free(pNodoBorrar);
    			if (index == 0)
    			{
    				pNodoSiguiente = getNode(this, 1);
    				this->pFirstNode = pNodoSiguiente;
    			}else
    			{
    				pNodoSiguiente = getNode(this, index+1);
    				pNodoAnterior = getNode(this, index-1);
    				pNodoAnterior->pNextNode = pNodoSiguiente;
    			}
    		returnAux = 0;
    		this->size--;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i = ll_len(this);
    if(this != NULL)
    {
        do
        {
            ll_remove(this,i);
            i--;

        }while(this->pFirstNode != NULL);

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if (this!=NULL)
    {
    	int i;
    	int len = ll_len(this);
    	for(i=0;i<len;i++)
        {

        	if (ll_get (this, i) == pElement)
        	{
        		returnAux = i;
        	}
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	if (ll_len(this) == 0)
    	{
    		returnAux = 1;
    	}else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL)
    {
       	if (index >= 0 && index <= ll_len(this))
       	{
       		addNode(this, index, pElement);
       		returnAux = 0;
       	}
    }


    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if (this != NULL)
    {
       	if (index >= 0 && index < ll_len(this))
       	{
       		Node* auxNodo;
       		auxNodo = ll_get(this,index);
       		returnAux = auxNodo;
       		ll_remove(this,index);
       	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if (this != NULL)
    {
    	if(ll_indexOf(this,pElement)!=-1)
    	{
    		returnAux = 1;
    	}else
    	{
    		returnAux = 0;
    	}

    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if (this != NULL && this2 !=NULL)
    {
    	if (ll_len (this) >= 0 && ll_len (this2) >= 0)
    	{
    		int i;
        	Node* nodoAux;
        	Node* nodoAux2;
        	int contadorElementos = 0;
        	returnAux = 0;
        	int len =ll_len(this);
        	for(i=0;i<len;i++)
        	{
        		nodoAux = getNode(this, i);
        		nodoAux2 = getNode(this2, i);
        		if (nodoAux2->pElement == nodoAux->pElement)
        		{
        			contadorElementos++;
        		}

        		if (contadorElementos == ll_len(this))
        		{
        			returnAux = 1;
        			break;
        		}
        	}
    	}
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if (this != NULL && from >= 0 && to <= ll_len (this) && to > from)
    {
    	 LinkedList* cloneArrayAux = NULL;
    	 cloneArrayAux = ll_newLinkedList();
    	 if (cloneArrayAux != NULL)
    	 {
    		 void* auxElemento;
    		 int i;
    		 for(i=from;i<=to;i++)
    		 {
    			 auxElemento =	ll_get(this, i);
    			  if (auxElemento != NULL)
    			  {
    				 ll_add(cloneArrayAux, auxElemento);
    			 }
    		 }
    		 cloneArray = cloneArrayAux;
    	 }
    }

    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if (this != NULL)
    {
    	cloneArray = ll_subList(this,0, (ll_len(this)-1));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{

    int returnAux =-1;

    if (this != NULL && (order == 0 || order == 1) && pFunc != NULL)
    {
    	int flagSwap;
    	int i;
    	int j;
    	void* elementoUno;
    	void* elementoDos;
    	int funcion;

    	do
    	{
    		flagSwap = 0;
    		int len = ll_len(this);
    		for(i=0;i<len-1;i++)
    	    {
    				j = i+1;
    	        	elementoUno = ll_get(this, i);
    	        	elementoDos = ll_get(this, j);

    	        	if (elementoUno != NULL)
    	        	{
    	        		funcion = pFunc(elementoUno, elementoDos);
    	        		if ((funcion > 0 && order == 1) || (funcion < 0 && order == 0 ) )
    	        		{
    	        			ll_set(this, i, elementoDos);
    	        			ll_set(this, j, elementoUno);
    	        			flagSwap = 1;
    	        		}
    	        	returnAux = 1;
    	        	}
    	    }
    	}while(flagSwap);
   }
    return returnAux;

}

/** \brief Recorre una Linked List y ejecuta una funcion para cada elemento de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion que se le aplicara a cada elemento
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */

int ll_map (LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;

	if (this != NULL && pFunc != NULL)
	{
		int i;
		void* auxElemento;
		int len = ll_len(this);
		 for(i=0;i<len;i++)
		 {
			 auxElemento =	ll_get(this, i);
			 pFunc(auxElemento);
		 }
		 retorno = 1;
	}

	return retorno;
}

/** \brief Recorre una Linked List y cuenta que elementos cumplen un criterio dado por funcion
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio encargada de devolver 1 si se debe contar o 0 si no se debe contar
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        (>= 0) Cantidad de elementos que cumplen el criterio de la funcion
 */

int ll_count(LinkedList* this, int (*fn)(void* element))
{
    int contador = -1;


    if (this!=NULL)
    {
    	int i;
    	contador = 0;
    	void* auxElemento;
    	int len = ll_len(this);
    	for(i=0;i<len;i++)
        {
    		auxElemento = ll_get (this, i);

    		int contar = fn(auxElemento);
    		if(contar)
    		{
    			contador++;
    		}
        }
    }

    return contador;
}

/** \brief Recorre una Linked List y pasa a otra linked list los elementos que cumplen el criterio de la funcion
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio que indica con 1 si se debe agregar a la nueva lista o 0 sik no se debe agregar a la nueva lista
 * \param void* Puntero al dato con el que se filtrará la linked list
 * \return int Retorna  (NULL) Si no se logra retornar ninguna lista
                        (LinkedList*) Un puntero a la linked list con loe elementos filtrados
 */

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element, void* criterio), void* criterioParam)
{
	LinkedList* linkedListRetorno = NULL;

	if (this != NULL && fn != NULL && criterioParam != NULL)
	{
		int i;
		void* auxElemento;
		int agregar;
		LinkedList* linkedListFiltrada;
		linkedListFiltrada = ll_newLinkedList();
		if (linkedListFiltrada != NULL)
		{
			int len = ll_len(this);
			for(i=0;i<len;i++)
			{
				auxElemento =	ll_get(this, i);
				agregar = fn(auxElemento, criterioParam);
				if (agregar)
				{
					ll_add(linkedListFiltrada, auxElemento);
				}
			}
			linkedListRetorno = linkedListFiltrada;
		}
	}

	return linkedListRetorno;
}


/*
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element, float criterio), float criterioParam)
{
	LinkedList* linkedListRetorno = NULL;

	if (this != NULL && fn != NULL)
	{
		int i;
		void* auxElemento;
		int agregar;
		LinkedList* linkedListFiltrada;
		linkedListFiltrada = ll_newLinkedList();
		if (linkedListFiltrada != NULL)
		{
			int len = ll_len(this);
			for(i=0;i<len;i++)
			{
				auxElemento =	ll_get(this, i);
				agregar = fn(auxElemento, criterioParam);
				if (agregar)
				{
					ll_add(linkedListFiltrada, auxElemento);
				}
			}
			linkedListRetorno = linkedListFiltrada;
		}
	}

	return linkedListRetorno;
}
*/

