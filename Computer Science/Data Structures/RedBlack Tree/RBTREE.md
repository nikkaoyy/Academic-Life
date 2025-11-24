# Red-Black Tree in C++

Complete implementation of a **Red-Black** balanced binary search tree in C++, featuring all fundamental operations and iterative traversals.

---

## 📋 Description

This project implements a **Red-Black Tree** following the algorithms from *Introduction to Algorithms* by Cormen et al.  
Red-Black Trees are self-balancing structures that guarantee **O(log n)** operations.

### Red-Black Tree Properties

- Each node is either red or black  
- The root is always black  
- All leaves (NIL) are black  
- If a node is red, both children are black  
- All paths from a node to its leaves contain the same number of black nodes  

---

## 🔧 Project Structure

    ├── Files
        ├── ArbolRojiNegro.h
        └── main.cpp
    └── RBTree.dev


### Node Structure

```cpp
struct nodo {
    int clave;
    string Info;
    nodo *izq, *der, *padre;
    bool color; // true = RED, false = BLACK
};
```

## ✨ Features
Main Operations: 
- insertar(int clave, string info): Inserts a node and rebalances the tree with 3 cases: Red uncle (recoloring), Double rotation, and Single rotation
- eliminar(int clave): Deletes a node while maintaining tree properties with 4 cases: Leaf node, Node with one child, Node with two children, and Adjustment for deleted black node.
- buscar(int clave): Returns the information associated with a key.
- modificar(int clave, string nuevaInfo): Updates the information of an existing node.

- Traversals (Iterative)
inorden() – left → root → right
preorden() – root → left → right
posorden() – left → right → root
porNiveles() – level-order traversal (BFS)

## 🚀 Compilation and Execution
Requirements

Compiler with C++11 support or higher
Compatible with MinGW, GCC, Clang, or MSVC

Compile
```
# With g++
g++ -std=c++11 main.cpp -o arbol_rn
```

Execute
```
./arbol_rn
```

## 📖 Usage Example
```cpp
#include "ArbolRojiNegro.h"
int main() {
    ArbolRojiNegro arbol;
    
    arbol.insertar(10, "Root");
    arbol.insertar(5, "Left");
    arbol.insertar(15, "Right");
    
    string info = arbol.buscar(10);
    cout << info << endl; // "Root"

    queue<int> inorden = arbol.inorden();
    // Expected result: 5 10 15

    arbol.modificar(10, "New information");
    arbol.eliminar(5);
    
    return 0;
}
```

## 🎯 Program Demonstration

The main.cpp file includes:

- Insertion of 13 nodes triggering all three adjustment cases
- Initial traversals (inorder and preorder)
- Interactive search
- Node deletion covering all cases
- Final traversals
- Information modification

Sample Output
```
===============================================
    RED-BLACK TREE PROGRAM
===============================================

1. KEY INSERTION (3 adjustment cases)
-------------------------------------------
Inserted: 10 (Initial root)
Inserted: 5 (Left child)
Inserted: 15 (Right child)
...

2. FIRST TWO TRAVERSALS
-------------------------------------------
INORDER  : 1 3 5 6 7 8 10 11 12 13 15 18 20
PREORDER : 7 5 3 1 6 12 10 8 11 15 13 18 20

3. KEY SEARCH
-------------------------------------------
Enter a key to search: 10
[FOUND] Key 10
Information: Initial root
...
```

## 🔍 Key Concepts
NIL Node (Sentinel)

A sentinel node is used instead of NULL:
- Always black
- Represents external leaves
- Simplifies code by avoiding checks

Rotations

Rebalancing tool that maintains BST order.

Left Rotation
```
    [x]              [y]
   /   \            /   \
  A    [y]   →    [x]    C
      /   \       / \
     B     C     A   B

```
Right Rotation
```
      [y]          [x]
     /   \        /   \
   [x]    C  →   A    [y]
   / \                / \
  A   B              B   C
```

## 📚 References

Cormen, T. H., et al. Introduction to Algorithms (3rd ed.). MIT Press.
Insertion and deletion algorithms based on Cormen's official pseudocode.

## 👤 Authors

- Nicolás Martínez Pineda **[GitHub](https://github.com/nikkaoyy)**
- Ian Nicolás Sandoval Martínez

⭐ If you found this project helpful, consider giving it a star on GitHub.
