// Universidad Distrital Francisco José de Caldas
//
// Hecho por: Nicolás Martínez Pineda && Ian Nicolás Sandoval Martínez 
//
// La forma en la que trabajamos en este código en el que implementamos 
// cabeceras y centinelas es de la siguiente manera
//
// cab ---> [CAB] -> [NODO 1] -> [NODO 2] -> ... -> [NODO n] -> [CEN] -> nullptr

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// -----------------------------------------------------
// Definición del Nodo
// -----------------------------------------------------
template <class T>
struct Nodo {
    T info;            // Información almacenada en la lista
    Nodo<T>* sig;      // Enlace al siguiente nodo
};

// -----------------------------------------------------
// Definición de la clase Lista con CABECERA y CENTINELA
// -----------------------------------------------------
template <class T>
class Lista {
private:
    Nodo<T>* cab;   // Nodo cabecera
    Nodo<T>* cen;   // Nodo centinela
    int tam;        // Tamaño de la lista

public:
    // Constructor
    Lista() {
        cab = new Nodo<T>;
        cen = new Nodo<T>;
        cab->sig = cen;   // La lista vacía apunta de cabecera a centinela
        cen->sig = NULL; // Centinela marca el final
        tam = 0;
    }

    // Métodos públicos
    bool lista_vacia();
    int getTam();
    T obtenerDato(int pos);
    bool eliminar(int pos);
    bool modificar(int pos, T infoNueva);
    void insertar_inicio(T infoNueva);
    void insertar_final(T infoNueva);
    void insertar_pos(T infoNueva, int pos);
};

// -----------------------------------------------------
// Implementaciones
// -----------------------------------------------------

template <class T>
bool Lista<T>::lista_vacia() {
    return cab->sig == cen; // comprobamos si luego de la cabecera está la centinela, si es así no hay nodos reales y la lista es vacía
}

template <class T>
int Lista<T>::getTam() {
    return tam; // devuelve el int del tamaño (tam)
}

template <class T>
void Lista<T>::insertar_inicio(T infoNueva) {
    Nodo<T>* nuevo = new Nodo<T>; // insertamos new nodo "nuevo" -> [?|?]
    nuevo->info = infoNueva; // asignamos los valores que queremos guardar en el nodo -> [1|A]
    nuevo->sig = cab->sig; 
	// nuevo -> sig enlaza el primer nodo y cab -> sig al primer nodo real o al centinela si está vacío
    cab->sig = nuevo; 
	// apuntamos al nuevo nodo 
    // ANTES: cab -> [1|A] -> cen
	// DESPUÉS: cab -> [nuevo] -> [1|A] -> cen
    tam++; //aumenta el tamaño de la lista
}

template <class T>
void Lista<T>::insertar_final(T infoNueva) {
    Nodo<T>* nuevo = new Nodo<T>; 
    nuevo->info = infoNueva;
    nuevo->sig = cen; // sig apuntará al nodo centinela para que nuevo los apunte a ellos como "último elemento"	

    Nodo<T>* actual = cab; // creamos puntero auxiliar "actual"
    while (actual->sig != cen) // se recorre el ciclo hasta encontrar el nodo cuyo sig apunta al cen (el último)
	{
        actual = actual->sig; 
    }

    actual->sig = nuevo; // asigna al nodo actual que apunta al siguiente el valor de nuevo
    tam++; // aumenta en el tamaño
}

template <class T>
void Lista<T>::insertar_pos(T infoNueva, int pos) {
    if (pos < 0 || pos > tam) throw out_of_range("Posición inválida"); // pos válida

    Nodo<T>* nuevo = new Nodo<T>; // new nodo "nuevo"
    nuevo->info = infoNueva; // asignamos info

    Nodo<T>* actual = cab; // aux
    for (int i = 0; i < pos; i++) { //recorre lista pos veces 
        actual = actual->sig; //actual apunta al nodo anterior a donde se quiere insertar
    }

    nuevo->sig = actual->sig; // enlazamos el nuevo nodo al siguiente
    actual->sig = nuevo; // asignamos al nodo actual la info en nuevo
    tam++; // incrementa el tamaño
}

template <class T>
T Lista<T>::obtenerDato(int pos) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posición inválida"); //pos válida

    Nodo<T>* actual = cab->sig; // nodo actual
    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }

    return actual->info; // info de nodo actual
}

template <class T>
bool Lista<T>::modificar(int pos, T infoNueva) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posición inválida"); //pos válida

    Nodo<T>* actual = cab->sig;
    for (int i = 0; i < pos; i++) { // recorrer posiciones
        actual = actual->sig; // actual apunta al nodo sig
    }

    actual->info = infoNueva; // la info apuntada por el nodo actual se remplaza con infoNueva
    return true; // devuelve True
}

template <class T>
bool Lista<T>::eliminar(int pos) {
    if (pos < 0 || pos >= tam) throw out_of_range("Posición inválida"); //pos válido

    Nodo<T>* anterior = cab; //aux
    for (int i = 0; i < pos; i++) { //recorrer posiciónes
        anterior = anterior->sig;   //hasta llegar al nodo anterior
    }

    Nodo<T>* borrar = anterior->sig; //nuevo nodo aux "borrar"
    anterior->sig = borrar->sig; //soltamos el nodo anterior

    delete borrar; // eliminamos el nodo borrar
    tam--; //decrementa el tamaño
    return true; //elemento eliminado
}

#endif

