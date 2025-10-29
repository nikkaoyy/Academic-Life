// Universidad Distrital Francisco Jos� de Caldas
//
// Hecho por: Nicol�s Mart�nez Pineda && Ian Nicol�s Sandoval Mart�nez 
//
// Lista DOBLEMENTE ENLAZADA LINEAL con CABECERA y CENTINELA
//
// Estructura: cab -> [CAB] <-> [NODO 1] <-> [NODO 2] <-> ... <-> [NODO n] <-> [CEN] -> NULL
//             NULL <- [CAB] ...

#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// -----------------------------------------------------
// Definici�n del Nodo Doble
// -----------------------------------------------------
template <class T>
struct NodoDoble {
    T info;              // Informaci�n almacenada
    NodoDoble<T>* sig;   // Enlace al siguiente nodo
    NodoDoble<T>* ant;   // Enlace al nodo anterior
};

// -----------------------------------------------------
// Definici�n de la clase Lista Doblemente Enlazada
// -----------------------------------------------------
template <class T>
class ListaDoble {
private:
    NodoDoble<T>* cab;   // Nodo cabecera
    NodoDoble<T>* cen;   // Nodo centinela
    int tam;             // Tama�o de la lista

public:
    // Constructor
    ListaDoble() {
        cab = new NodoDoble<T>;
        cen = new NodoDoble<T>;
        
        // Configuraci�n: cabecera y centinela se apuntan a s� mismos en sus extremos
        cab->sig = cen;
        cab->ant = cab;   // La cabecera se apunta a s� misma
        cen->sig = cen;   // El centinela se apunta a s� mismo
        cen->ant = cab;   // El centinela apunta hacia atr�s a la cabecera
        
        tam = 0;
    }
    
    // Destructor
    ~ListaDoble() {
        // Liberar todos los nodos excepto cabecera y centinela
        NodoDoble<T>* actual = cab->sig;
        while (actual != cen) {
            NodoDoble<T>* temp = actual;
            actual = actual->sig;
            delete temp;
        }
        delete cab;
        delete cen;
    }

    // M�todos p�blicos
    bool lista_vacia();
    int getTam();
    T obtenerDato(int pos);
    bool eliminar(int pos);
    bool modificar(int pos, T infoNueva);
    void insertar_inicio(T infoNueva);
    void insertar_final(T infoNueva);
    void insertar_pos(T infoNueva, int pos);
    void vaciar_lista();
};

// -----------------------------------------------------
// Implementaciones
// -----------------------------------------------------

template <class T>
bool ListaDoble<T>::lista_vacia() {
    return cab->sig == cen; // Si cab apunta directamente a cen, est� vac�a y retorna True
}

template <class T>
int ListaDoble<T>::getTam() {
    return tam; // Devuelve el tama�o
}

template <class T>
void ListaDoble<T>::insertar_inicio(T infoNueva) {
	// Colocamos la info en el nodo nuevo
    NodoDoble<T>* nuevo = new NodoDoble<T>; //aux
    nuevo->info = infoNueva;
    
    // Insertar entre cabecera y el primer nodo real
    nuevo->sig = cab->sig;      // nuevo apunta al que era el primero (o al centinela)
    nuevo->ant = cab;           // nuevo apunta hacia atr�s a la cabecera
    cab->sig->ant = nuevo;      // el que era el primero ahora apunta hacia atr�s a nuevo
    cab->sig = nuevo;           // la cabecera apunta a nuevo
    
    tam++; // aumenta el tama�o
}

template <class T>
void ListaDoble<T>::insertar_final(T infoNueva) {
	// Colocamos la info en el nodo nuevo
    NodoDoble<T>* nuevo = new NodoDoble<T>; //aux
    nuevo->info = infoNueva;
    
    // Insertar entre el �ltimo nodo real y el centinela
    nuevo->sig = cen;           // nuevo apunta al centinela
    nuevo->ant = cen->ant;      // nuevo apunta hacia atr�s al �ltimo nodo
    cen->ant->sig = nuevo;      // el �ltimo nodo apunta a nuevo
    cen->ant = nuevo;           // el centinela apunta hacia atr�s a nuevo
    
    tam++; // aumenta el tama�o
}

template <class T>
void ListaDoble<T>::insertar_pos(T infoNueva, int pos) {
    if (pos < 0 || pos > tam) throw out_of_range("Posici�n inv�lida"); // posicici�n inv�lida
    
    if (pos == 0) {
        insertar_inicio(infoNueva); // insertar al inicio
        return;
    }
    if (pos == tam) {
        insertar_final(infoNueva); // insertar al final
        return;
    }
    // Colocamos la info en el nodo nuevo
    NodoDoble<T>* nuevo = new NodoDoble<T>;
    nuevo->info = infoNueva;
    
    //Buscamos la posici�n con un nodo aux = actual
    NodoDoble<T>* actual = cab->sig; 
    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }
    
    // Insertar antes del nodo actual
    nuevo->sig = actual;
    nuevo->ant = actual->ant;
    actual->ant->sig = nuevo;
    actual->ant = nuevo;
    
    tam++; // aumenta tama�o
}

template <class T>
T ListaDoble<T>::obtenerDato(int pos) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posici�n inv�lida"); // validar posici�n
    
    // creamos nodo auxiliar para buscar la info de acuerdo a la posici�n
    NodoDoble<T>* actual = cab->sig;
    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }
    
    return actual->info; //retornar la info en el nodo actual 
}

template <class T>
bool ListaDoble<T>::modificar(int pos, T infoNueva) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posici�n inv�lida"); // validar posici�n
    
    NodoDoble<T>* actual = cab->sig; //aux
    for (int i = 0; i < pos; i++) {
        actual = actual->sig; //ubicarnos en el nodo
    }
    
    actual->info = infoNueva; // cambiar posici�n
    return true; // salida True luego del cambio
}

template <class T>
bool ListaDoble<T>::eliminar(int pos) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posici�n inv�lida"); // validar posici�n
    
    NodoDoble<T>* actual = cab->sig; //aux
    for (int i = 0; i < pos; i++) {
        actual = actual->sig; //buscamos la posici�n
    }
    
    // Desenlazar el nodo de ambos lados
    actual->ant->sig = actual->sig;
    actual->sig->ant = actual->ant;
    
    delete actual; // eliminamos el nodo de la info
    tam--; // decrementamos el tama�o
    return true; // True si se elimina
}

template <class T>
void ListaDoble<T>::vaciar_lista() {
    // Eliminar todos los nodos excepto cabecera y centinela
    NodoDoble<T>* actual = cab->sig; // aux1
    while (actual != cen) { //m mientras que actual sea diferente al centinela
        NodoDoble<T>* temp = actual; // aux2 = aux1
        actual = actual->sig; // actual (aux1) avanza
        delete temp; // se elimina actual (debido al temp = actual) 
    }
    // Restablecer la lista vac�a
    cab->sig = cen; //cab apunta a centinela
    cen->ant = cab; //centinela apunta a cab
    tam = 0; // lista vaciada
}

#endif
