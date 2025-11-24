# Árbol Rojo-Negro en C++

Implementación completa de un árbol binario de búsqueda balanceado **Rojo-Negro** en C++, con todas las operaciones fundamentales y recorridos iterativos.

---

## 📋 Descripción

Este proyecto implementa un **árbol Rojo-Negro (Red-Black Tree)** siguiendo los algoritmos del libro *Introduction to Algorithms* de Cormen et al.  
Los árboles Rojo-Negro son estructuras auto-balanceadas que garantizan operaciones en **O(log n)**.

### Propiedades del Árbol Rojo-Negro

- Cada nodo es rojo o negro  
- La raíz es siempre negra  
- Todas las hojas (NIL) son negras  
- Si un nodo es rojo, ambos hijos son negros  
- Todos los caminos desde un nodo hasta sus hojas contienen el mismo número de nodos negros  

---

## 🔧 Estructura del Proyecto

    ├── Files
        ├── ArbolRojiNegro.h
        └── main.cpp
    └── RBTree.dev


### Estructura del Nodo

```cpp
struct nodo {
    int clave;
    string Info;
    nodo *izq, *der, *padre;
    bool color; // true = ROJO, false = NEGRO
};
```

✨ Funcionalidades
Operaciones Principales: 
- insertar(int clave, string info): Inserta un nodo y rebalancea el árbol con 3 casos: Tío rojo (recoloreo), Rotación doble y Rotación simple
- eliminar(int clave): Elimina un nodo manteniendo las propiedades del árbol con 4 casos: Nodo hoja, Nodo con un hijo, Nodo con dos hijos y Ajuste por nodo negro eliminado.
- buscar(int clave): Retorna la información asociada a una clave.
- modificar(int clave, string nuevaInfo): Actualiza la información de un nodo existente.

- Recorridos (Iterativos)
inorden() – izquierda → raíz → derecha
preorden() – raíz → izquierda → derecha
posorden() – izquierda → derecha → raíz
porNiveles() – recorrido por niveles (BFS)

🚀 Compilación y Ejecución
Requisitos

Compilador con soporte para C++11 o superior
Compatible con MinGW, GCC, Clang o MSVC

Compilar
```
# Con g++
g++ -std=c++11 main.cpp -o arbol_rn
```

Ejecutar
```
./arbol_rn
```

📖 Ejemplo de Uso
```cpp
#include "ArbolRojiNegro.h"
int main() {
    ArbolRojiNegro arbol;
    
    arbol.insertar(10, "Raiz");
    arbol.insertar(5, "Izquierda");
    arbol.insertar(15, "Derecha");
    
    string info = arbol.buscar(10);
    cout << info << endl; // "Raiz"

    queue<int> inorden = arbol.inorden();
    // Resultado esperado: 5 10 15

    arbol.modificar(10, "Nueva información");
    arbol.eliminar(5);
    
    return 0;
}
```

🎯 Demostración del Programa

El archivo main.cpp incluye:

- Inserción de 13 nodos que activan los tres casos de ajuste
- Recorridos iniciales (inorden y preorden)
- Búsqueda interactiva
- Eliminación de nodos cubriendo todos los casos
- Recorridos finales
- Modificación de información

Salida Ejemplo
```
===============================================
    PROGRAMA DE ARBOL ROJO-NEGRO
===============================================

1. INSERCION DE CLAVES (3 casos de ajuste)
-------------------------------------------
Insertado: 10 (Raiz inicial)
Insertado: 5 (Hijo izquierdo)
Insertado: 15 (Hijo derecho)
...

2. PRIMEROS DOS RECORRIDOS
-------------------------------------------
INORDEN  : 1 3 5 6 7 8 10 11 12 13 15 18 20
PREORDEN : 7 5 3 1 6 12 10 8 11 15 13 18 20

3. BUSQUEDA DE CLAVE
-------------------------------------------
Ingrese una clave a buscar: 10
[ENCONTRADO] Clave 10
Informacion: Raiz inicial
...
```

🔍 Conceptos Clave
Nodo NIL (Centinela)

Se utiliza un nodo centinela en lugar de NULL:
- Siempre es negro
- Representa las hojas externas
- Simplifica el código evitando verificaciones

Rotaciones

Herramienta de rebalanceo manteniendo el orden BST.

Rotación Izquierda
```
    [x]              [y]
   /   \            /   \
  A    [y]   →    [x]    C
      /   \       / \
     B     C     A   B

```
Rotación Derecha
```
      [y]          [x]
     /   \        /   \
   [x]    C  →   A    [y]
   / \                / \
  A   B              B   C
```

📚 Referencias

Cormen, T. H., et al. Introduction to Algorithms (3rd ed.). MIT Press.
Algoritmos de inserción y eliminación según el pseudocódigo oficial de Cormen.

👤 Autores

- Nicolás Martínez Pineda **[GitHub](https://github.com/nikkaoyy)**
- Ian Nicolás Sandoval Martínez

⭐ Si este proyecto te fue útil, considera darle una estrella en GitHub.
