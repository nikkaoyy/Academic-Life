/*

Universidad Distrital Francisco José de Caldas

Librería en base al algoritmo de Árboles RojiNegros del libro
Introducción a los Algoritmos de Thomas H. Cormen 

Realizado por: 

Nicolás Martínez Pineda (20241020098)
Ian Nicolás Sandoval Martínez (20241020078)

*/

#ifndef ARBOLROJINEGRO_H
#define ARBOLROJINEGRO_H

#include <string>
#include <queue>
#include <stack>
using namespace std;

#define ROJO true
#define NEGRO false

// Estructura del nodo según especificación
struct nodo {
    int clave;
    string Info;
    nodo *izq, *der, *padre;
    bool color; // true = ROJO, false = NEGRO
};

// Clase del Árbol RojiNegro
class ArbolRojiNegro {
private:
    nodo* raiz;
    nodo* NIL; // centinela
    
    // Métodos
    
    // Buscar nodo
    nodo* buscarNodo(int clave) {
        nodo* actual = raiz; // aux en raíz
        while (actual != NIL && actual->clave != clave) { // apunta a la clave hasta encontrarla por izq o der
            if (clave < actual->clave)
                actual = actual->izq;
            else
                actual = actual->der;
        }
        return actual; // retorna el nodo que tiene la clave buscada
    }
    
    
    nodo* minimo(nodo* n) {
        while (n->izq != NIL) // mientras haya hijo izq ir al max izq que es el menor
            n = n->izq;
        return n;
    }
    
    // Algoritmos de Rotación izq - der
    
    void rotarIzquierda(nodo* x) { 
        nodo* y = x->der; // y como la der. de x
        x->der = y->izq; // transplante del subarbol
        if (y->izq != NIL) 
            y->izq->padre = x; // actualizamos el padre de y a x
        y->padre = x->padre; // transplante x, y
        if (x->padre == NIL) // si x era raíz ahora y es raíz
            raiz = y;
        else if (x == x->padre->izq) // si x era hijo izquierdo y lo reemplaza
            x->padre->izq = y;
        else // si x era hijo derecho y lo reemplaza
            x->padre->der = y;
        y->izq = x; // x hijo izq. de y
        x->padre = y; // y padre de x
    }
    
    void rotarDerecha(nodo* x) { // Función espejo de rotarIzquierda
        nodo* y = x->izq;
        x->izq = y->der;
        if (y->der != NIL)
            y->der->padre = x;
        y->padre = x->padre;
        if (x->padre == NIL)
            raiz = y;
        else if (x == x->padre->der)
            x->padre->der = y;
        else
            x->padre->izq = y;
        y->der = x;
        x->padre = y;
    }
    
    // Algoritmo en base al libro de Thomas H. Cormen
    void ajustarInsercion(nodo* z) {
        while (z->padre->color == ROJO) {
            if (z->padre == z->padre->padre->izq) {
                nodo* y = z->padre->padre->der;
                if (y->color == ROJO) {
                    z->padre->color = NEGRO;
                    y->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    z = z->padre->padre;
                } else {
                    if (z == z->padre->der) {
                        z = z->padre;
                        rotarIzquierda(z);
                    }
                    z->padre->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    rotarDerecha(z->padre->padre);
                }
            } else {
                nodo* y = z->padre->padre->izq;
                if (y->color == ROJO) {
                    z->padre->color = NEGRO;
                    y->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    z = z->padre->padre;
                } else {
                    if (z == z->padre->izq) {
                        z = z->padre;
                        rotarDerecha(z);
                    }
                    z->padre->color = NEGRO;
                    z->padre->padre->color = ROJO;
                    rotarIzquierda(z->padre->padre);
                }
            }
        }
        raiz->color = NEGRO;
    }
    
    // Función aux del transplante de u,v para el balanceo del Árbol RojiNegro
    void transplantar(nodo* u, nodo* v) {
        if (u->padre == NIL)
            raiz = v;
        else if (u == u->padre->izq)
            u->padre->izq = v;
        else
            u->padre->der = v;
        v->padre = u->padre;
    }
    
    // Eliminación de nodo x por medio de los 4 casos de Thomas H. Cormen
    void ajustarEliminacion(nodo* x) {
        while (x != raiz && x->color == NEGRO) {
            if (x == x->padre->izq) {
                nodo* w = x->padre->der;
                if (w->color == ROJO) {
                    w->color = NEGRO;
                    x->padre->color = ROJO;
                    rotarIzquierda(x->padre);
                    w = x->padre->der;
                }
                if (w->izq->color == NEGRO && w->der->color == NEGRO) {
                    w->color = ROJO;
                    x = x->padre;
                } else {
                    if (w->der->color == NEGRO) {
                        w->izq->color = NEGRO;
                        w->color = ROJO;
                        rotarDerecha(w);
                        w = x->padre->der;
                    }
                    w->color = x->padre->color;
                    x->padre->color = NEGRO;
                    w->der->color = NEGRO;
                    rotarIzquierda(x->padre);
                    x = raiz;
                }
            } else {
                nodo* w = x->padre->izq;
                if (w->color == ROJO) {
                    w->color = NEGRO;
                    x->padre->color = ROJO;
                    rotarDerecha(x->padre);
                    w = x->padre->izq;
                }
                if (w->der->color == NEGRO && w->izq->color == NEGRO) {
                    w->color = ROJO;
                    x = x->padre;
                } else {
                    if (w->izq->color == NEGRO) {
                        w->der->color = NEGRO;
                        w->color = ROJO;
                        rotarIzquierda(w);
                        w = x->padre->izq;
                    }
                    w->color = x->padre->color;
                    x->padre->color = NEGRO;
                    w->izq->color = NEGRO;
                    rotarDerecha(x->padre);
                    x = raiz;
                }
            }
        }
        x->color = NEGRO;
    }
    
    // Eliminar el árbol
    void destruirArbol(nodo* n) {
        if (n != NIL) {
            destruirArbol(n->izq);
            destruirArbol(n->der);
            delete n;
        }
    }

public:
	// Constructor
    ArbolRojiNegro() {
        NIL = new nodo;
        NIL->color = NEGRO;
        NIL->izq = NIL->der = NIL->padre = 	nullptr;
        raiz = NIL;
    }
    
    // Destructor
    ~ArbolRojiNegro() {
        destruirArbol(raiz);
        delete NIL;
    }
    
    // Inserción llamando a ajustarInserción(z) (z: el nuevo nodo)
    void insertar(int clave, string info) {
        nodo* z = new nodo;
        z->clave = clave;
        z->Info = info;
        z->izq = NIL;
        z->der = NIL;
        z->color = ROJO;
        
        nodo* y = NIL;
        nodo* x = raiz;
        
        while (x != NIL) {
            y = x;
            if (z->clave < x->clave)
                x = x->izq;
            else
                x = x->der;
        }
        
        z->padre = y;
        
        if (y == NIL)
            raiz = z;
        else if (z->clave < y->clave)
            y->izq = z;
        else
            y->der = z;
        
        ajustarInsercion(z);
    }
    
    // Eliminación a través de la clave
    bool eliminar(int clave) {
        nodo* z = buscarNodo(clave);
        if (z == NIL)
            return false;
        
        nodo* y = z;
        nodo* x;
        bool colorOriginalY = y->color;
        
        if (z->izq == NIL) {
            x = z->der;
            transplantar(z, z->der);
        } else if (z->der == NIL) {
            x = z->izq;
            transplantar(z, z->izq);
        } else {
            y = minimo(z->der);
            colorOriginalY = y->color;
            x = y->der;
            
            if (y->padre == z) {
                x->padre = y;
            } else {
                transplantar(y, y->der);
                y->der = z->der;
                y->der->padre = y;
            }
            
            transplantar(z, y);
            y->izq = z->izq;
            y->izq->padre = y;
            y->color = z->color;
        }
        
        delete z;
        
        if (colorOriginalY == NEGRO)
            ajustarEliminacion(x);
        
        return true;
    }
    
    // Buscar la clave
    string buscar(int clave) {
        nodo* n = buscarNodo(clave);
        if (n != NIL)
            return n->Info;
        return "";
    }
    
    bool modificar(int clave, string nuevaInfo) {
        nodo* n = buscarNodo(clave);
        if (n != NIL) {
            n->Info = nuevaInfo;
            return true;
        }
        return false;
    }
    
    // Impresión del Inorden
    queue<int> inorden() {
        queue<int> resultado;
        if (raiz == NIL) return resultado;
        
        stack<nodo*> pila;
        nodo* actual = raiz;
        
        while (actual != NIL || !pila.empty()) {
            while (actual != NIL) {
                pila.push(actual);
                actual = actual->izq;
            }
            actual = pila.top();
            pila.pop();
            resultado.push(actual->clave);
            actual = actual->der;
        }
        return resultado;
    }
    
    // Impresión del Preorden
    queue<int> preorden() {
        queue<int> resultado;
        if (raiz == NIL) return resultado;
        
        stack<nodo*> pila;
        pila.push(raiz);
        
        while (!pila.empty()) {
            nodo* actual = pila.top();
            pila.pop();
            resultado.push(actual->clave);
            
            if (actual->der != NIL)
                pila.push(actual->der);
            if (actual->izq != NIL)
                pila.push(actual->izq);
        }
        return resultado;
    }
    
    // Impresión del Posorden
    queue<int> posorden() {
        queue<int> resultado;
        if (raiz == NIL) return resultado;
        
        stack<nodo*> pila1, pila2;
        pila1.push(raiz);
        
        while (!pila1.empty()) {
            nodo* actual = pila1.top();
            pila1.pop();
            pila2.push(actual);
            
            if (actual->izq != NIL)
                pila1.push(actual->izq);
            if (actual->der != NIL)
                pila1.push(actual->der);
        }
        
        while (!pila2.empty()) {
            resultado.push(pila2.top()->clave);
            pila2.pop();
        }
        return resultado;
    }
    
    // Impresión de nodos por niveles como una cola queue<int>
    queue<int> porNiveles() {
        queue<int> resultado;
        if (raiz == NIL) return resultado;
        
        queue<nodo*> cola;
        cola.push(raiz);
        
        while (!cola.empty()) {
            nodo* actual = cola.front();
            cola.pop();
            resultado.push(actual->clave);
            
            if (actual->izq != NIL)
                cola.push(actual->izq);
            if (actual->der != NIL)
                cola.push(actual->der);
        }
        return resultado;
    }
};

#endif
