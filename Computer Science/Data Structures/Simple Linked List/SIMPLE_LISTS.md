# Singly Linked List in C++

Complete implementation of a **Generic Singly Linked List** with header and sentinel nodes in C++, supporting multiple data types through templates.

---

## 📋 Description

This project implements a **Singly Linked List** data structure with header and sentinel nodes, designed as a generic template to handle any data type. The implementation provides efficient operations and demonstrates the power of C++ templates for creating reusable data structures.

### Singly Linked List Properties

- Each node contains data and a pointer to the next node
- Header node at the beginning for simplified operations
- Sentinel node at the end to mark list termination
- Template-based design supports any data type
- Unidirectional traversal from head to tail
- Dynamic memory management

---

## 🔧 Project Structure

```
├── Files
    ├── lista.h
    └── main.cpp
├── BookshopLists.dev
```

### Node Structure

```cpp
template <class T>
struct Nodo {
    T info;            // Stored information
    Nodo<T>* sig;      // Link to next node
};
```

### List Structure

```
cab -> [HEADER] -> [NODE 1] -> [NODE 2] -> ... -> [NODE n] -> [SENTINEL] -> nullptr
```

---

## ✨ Features

### Core Operations

- **insertar_inicio(T info)**: Inserts a node at the beginning in O(1)
- **insertar_final(T info)**: Inserts a node at the end in O(n)
- **insertar_pos(T info, int pos)**: Inserts a node at a specific position in O(n)
- **eliminar(int pos)**: Removes a node at a given position in O(n)
- **modificar(int pos, T newInfo)**: Updates information at a specific position in O(n)
- **obtenerDato(int pos)**: Retrieves data from a specific position in O(n)
- **lista_vacia()**: Checks if the list is empty in O(1)
- **getTam()**: Returns the current size of the list in O(1)

### Generic Template Support

The list supports multiple data types:
- **Integers** (int)
- **Floating-point numbers** (float)
- **Characters** (char)
- Any custom data type

---

## 🚀 Compilation and Execution

### Requirements

- Compiler with C++11 support or higher
- Compatible with MinGW, GCC, Clang, or MSVC

### Compile

```bash
# With g++
g++ -std=c++11 main.cpp -o lista_generica

# With MinGW
g++ main.cpp -o lista_generica.exe
```

### Execute

```bash
# Linux/Mac
./lista_generica

# Windows
lista_generica.exe
```

---

## 📖 Usage Example

```cpp
#include "lista.h"

int main() {
    // Create lists of different types
    Lista<int> listaEnteros;
    Lista<float> listaReales;
    Lista<char> listaCaracteres;
    
    // Insert integers
    listaEnteros.insertar_inicio(10);
    listaEnteros.insertar_final(20);
    listaEnteros.insertar_pos(15, 1);
    
    // Insert floats
    listaReales.insertar_inicio(3.14);
    listaReales.insertar_final(2.71);
    
    // Insert characters
    listaCaracteres.insertar_inicio('A');
    listaCaracteres.insertar_final('Z');
    
    // Get data
    int value = listaEnteros.obtenerDato(0);  // Returns 10
    cout << "First value: " << value << endl;
    
    // Modify data
    listaEnteros.modificar(1, 25);
    
    // Delete node
    listaEnteros.eliminar(0);
    
    // Check size
    cout << "List size: " << listaEnteros.getTam() << endl;
    
    // Check if empty
    if (listaEnteros.lista_vacia()) {
        cout << "List is empty" << endl;
    }
    
    return 0;
}
```

---

## 🎯 Program Demonstration

The `main.cpp` file includes an interactive menu system with support for three data types:

### Main Menu

```
=== GENERIC LISTS PROGRAM ===

Select list type:
1. Integers
2. Floats
3. Characters
0. Exit
```

### Action Menu (for each list type)

1. **Insert at beginning** - Adds element at the start
2. **Insert at end** - Adds element at the end
3. **Insert at position** - Adds element at specific index
4. **Display complete list** - Shows all elements
5. **Search element by position** - Direct access by index
6. **Modify element** - Updates existing element
7. **Delete element** - Removes element by position
8. **List size** - Displays total number of elements
0. **Return to main menu** - Go back to list type selection

### Sample Output

```
=== GENERIC LISTS PROGRAM ===

Select list type:
1. Integers
2. Floats
3. Characters
0. Exit
Option: 1

--- Integer List ---

Select an action:
1. Insert at beginning
2. Insert at end
...
Action: 1

Enter an integer: 42
Element inserted.

Action: 4

List contents:
42

Action: 2

Enter an integer: 100
Element inserted.

Action: 4

List contents:
42 100

Action: 8

List size: 2
```

---

## 🔍 Key Concepts

### Header and Sentinel Nodes

This implementation uses two special nodes to simplify operations:

#### Header Node (cab)
- Dummy node at the beginning
- Never contains actual data
- Eliminates special cases for empty list
- Points to first real node or sentinel

#### Sentinel Node (cen)
- Dummy node at the end
- Marks the end of the list
- Points to `nullptr`
- Avoids null pointer checks during traversal

### List States

**Empty List:**
```
cab -> [HEADER] -> [SENTINEL] -> nullptr
```

**List with elements:**
```
cab -> [HEADER] -> [42] -> [100] -> [SENTINEL] -> nullptr
```

---

## 💡 Templates in C++

This implementation demonstrates the power of C++ templates:

```cpp
template <class T>
class Lista {
    // Works with any data type T
};

// Usage:
Lista<int> intList;        // List of integers
Lista<float> floatList;    // List of floats
Lista<string> stringList;  // List of strings
Lista<Persona> personList; // List of custom objects
```

### Advantages of Templates

- **Type safety**: Compile-time type checking
- **Code reusability**: Single implementation for all types
- **Performance**: No runtime overhead
- **Flexibility**: Works with built-in and custom types

---

## ⚙️ Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insert at beginning | O(1) | O(1) |
| Insert at end | O(n) | O(1) |
| Insert at position | O(n) | O(1) |
| Delete | O(n) | O(1) |
| Access by position | O(n) | O(1) |
| Modify | O(n) | O(1) |
| Check if empty | O(1) | O(1) |
| Get size | O(1) | O(1) |

*Note: n represents the number of elements in the list*

---

## ⚠️ Error Handling

The implementation includes robust error handling:

```cpp
try {
    lista.obtenerDato(999);  // Invalid position
} catch (out_of_range& e) {
    cout << "Error: " << e.what() << endl;
}
```

### Exception Types

- `out_of_range`: Thrown for invalid position access
  - Position less than 0
  - Position greater than or equal to list size
  - Insert position greater than list size

### Validation Checks

```cpp
if (pos < 0 || pos >= tam) 
    throw out_of_range("Invalid position");
```

---

## 🧪 Testing

### Test Cases Covered

1. **Empty list operations**
   ```cpp
   Lista<int> lista;
   bool empty = lista.lista_vacia();  // true
   int size = lista.getTam();         // 0
   ```

2. **Single element operations**
   ```cpp
   lista.insertar_inicio(10);
   int value = lista.obtenerDato(0);  // 10
   lista.eliminar(0);
   ```

3. **Multiple insertions**
   ```cpp
   lista.insertar_inicio(10);
   lista.insertar_final(20);
   lista.insertar_pos(15, 1);
   // Result: 10 -> 15 -> 20
   ```

4. **Boundary conditions**
   - Insert at position 0 and n
   - Delete first and last elements
   - Access at boundaries

5. **Exception handling**
   ```cpp
   try {
       lista.obtenerDato(-1);  // Exception
       lista.eliminar(1000);   // Exception
   } catch (out_of_range& e) {
       // Handle error
   }
   ```

---

## 🔄 Comparison with Other List Types

| Feature | Singly Linked | Doubly Linked | Array-based |
|---------|--------------|---------------|-------------|
| Insert at start | O(1) | O(1) | O(n) |
| Insert at end | O(n) | O(1) | O(1)* |
| Random access | O(n) | O(n) | O(1) |
| Memory per node | 1 pointer | 2 pointers | Contiguous |
| Bidirectional | No | Yes | Yes |

*Assuming dynamic array with amortized analysis

---

## 📚 References

- Cormen, T. H., et al. *Introduction to Algorithms* (3rd ed.). MIT Press.
- Stroustrup, B. *The C++ Programming Language* (4th ed.). Addison-Wesley.
- Classic singly linked list with header and sentinel optimization
- Universidad Distrital Francisco José de Caldas - Data Structures course

---

## 🎓 Educational Value

This implementation is ideal for learning:

- **Template programming** in C++
- **Pointer manipulation** and dynamic memory
- **Data structure design** with sentinel nodes
- **Exception handling** in C++
- **Generic programming** concepts
- **Menu-driven program** design

---

## 🚀 Potential Extensions

Consider adding these features:

- **Reverse list** operation
- **Sort** functionality
- **Merge** two lists
- **Find** operation (search by value)
- **Copy constructor** and assignment operator
- **Iterator** pattern implementation
- **Circular list** variant

---

## 👤 Authors

- **Nicolás Martínez Pineda** - [GitHub](https://github.com/nikkaoyy)
- **Ian Nicolás Sandoval Martínez**

---

## 📝 License

This project is developed for educational purposes at Universidad Distrital Francisco José de Caldas.

---

## 🤝 Contributing

Contributions are welcome! Feel free to:

- Report bugs
- Suggest new features
- Improve documentation
- Submit pull requests

---

## 💻 System Requirements

- **Operating System**: Windows, Linux, or macOS
- **Compiler**: Any C++11 compliant compiler
  - GCC 4.8+
  - Clang 3.3+
  - MSVC 2015+
  - MinGW-w64

---

⭐ If you found this project helpful, consider giving it a star on GitHub!

---

## 📧 Contact

For questions or suggestions, please open an issue on GitHub or contact the authors directly.
