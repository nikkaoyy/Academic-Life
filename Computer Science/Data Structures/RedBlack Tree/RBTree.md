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
.
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
