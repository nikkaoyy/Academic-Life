# Doubly Linked List in C++

Complete implementation of a **Doubly Linked List** with header and sentinel nodes in C++, featuring comprehensive CRUD operations and file management.

---

## 📋 Description

This project implements a **Doubly Linked List** data structure with header and sentinel nodes, designed to manage person records efficiently. The implementation provides constant-time insertions at both ends and maintains bidirectional traversal capabilities.

### Doubly Linked List Properties

- Each node has pointers to both next and previous nodes
- Header node at the beginning for simplified operations
- Sentinel node at the end to avoid null pointer checks
- Bidirectional traversal capability
- Dynamic memory management

---

## 🔧 Project Structure

```
├── Files
    ├── lista_doble.h
    ├── main.cpp
    └── personas.txt
├── DoublyLinked.dev
```

### Node Structure

```cpp
template <class T>
struct NodoDoble {
    T info;              // Stored information
    NodoDoble<T>* sig;   // Link to next node
    NodoDoble<T>* ant;   // Link to previous node
};
```

### List Structure

```
NULL <- [HEADER] <-> [NODE 1] <-> [NODE 2] <-> ... <-> [NODE n] <-> [SENTINEL] -> NULL
```

---

## ✨ Features

### Core Operations

- **insertar_inicio(T info)**: Inserts a node at the beginning in O(1)
- **insertar_final(T info)**: Inserts a node at the end in O(1)
- **insertar_pos(T info, int pos)**: Inserts a node at a specific position in O(n)
- **eliminar(int pos)**: Removes a node at a given position
- **modificar(int pos, T newInfo)**: Updates information at a specific position
- **obtenerDato(int pos)**: Retrieves data from a specific position
- **lista_vacia()**: Checks if the list is empty
- **getTam()**: Returns the current size of the list
- **vaciar_lista()**: Clears all nodes from the list

### File Management

- **Load data from CSV file**: Reads person records from `personas.txt`
- **Save data to CSV file**: Writes current list contents to file
- **Automatic file parsing**: Handles CSV format with proper field separation

### Search Operations

- **Search by position**: Direct access to any node
- **Search by ID (cédula)**: Linear search by identification number
- **Search by student code**: Linear search by student code

---

## 📊 Person Structure

```cpp
struct Persona {
    string cedula;           // ID number
    string nombre;           // Full name
    string codigoEstudiante; // Student code
    string carrera;          // Career/Major
    int edad;                // Age
};
```

---

## 🚀 Compilation and Execution

### Requirements

- Compiler with C++11 support or higher
- Compatible with MinGW, GCC, Clang, or MSVC
- `personas.txt` file for data loading (included)

### Compile

```bash
# With g++
g++ -std=c++11 main.cpp -o lista_personas

# With MinGW
g++ main.cpp -o lista_personas.exe
```

### Execute

```bash
# Linux/Mac
./lista_personas

# Windows
lista_personas.exe
```

---

## 📖 Usage Example

```cpp
#include "lista_doble.h"

int main() {
    ListaDoble<Persona> lista;
    
    // Insert at the beginning
    Persona p1("1001234567", "John Doe", "20211020001", "Computer Science", 22);
    lista.insertar_inicio(p1);
    
    // Insert at the end
    Persona p2("1002345678", "Jane Smith", "20211020002", "Electronics", 21);
    lista.insertar_final(p2);
    
    // Insert at specific position
    Persona p3("1003456789", "Bob Johnson", "20201020003", "Industrial Eng.", 23);
    lista.insertar_pos(p3, 1);
    
    // Get data
    Persona retrieved = lista.obtenerDato(0);
    cout << "First person: " << retrieved.nombre << endl;
    
    // Modify data
    Persona updated("1001234567", "John Updated", "20211020001", "AI", 23);
    lista.modificar(0, updated);
    
    // Delete node
    lista.eliminar(1);
    
    // Check size
    cout << "List size: " << lista.getTam() << endl;
    
    return 0;
}
```

---

## 🎯 Program Demonstration

The `main.cpp` file includes an interactive menu with the following options:

### Menu Options

1. **Load data from file** - Imports all records from `personas.txt`
2. **Add person at beginning** - Inserts new record at the start
3. **Add person at end** - Inserts new record at the end
4. **Insert person at position** - Inserts at a specific index
5. **Display all persons** - Shows complete list with positions
6. **Search person by position** - Direct access by index
7. **Search by ID** - Find person by cédula
8. **Search by student code** - Find student by code
9. **Modify person** - Update existing record
10. **Delete person by position** - Remove by index
11. **Delete person by ID** - Remove by cédula
12. **Save data to file** - Export current list to CSV
13. **List size** - Display total number of records
0. **Exit** - Close the program

### Sample Output

```
=== DOUBLY LINKED LIST PROGRAM - PERSONS ===

Select an action:
1. Load data from file
2. Add person at beginning
...
Option: 1

Data loaded successfully. Total: 10 persons.

=== COMPLETE LIST OF PERSONS ===
Position 0: ID: 1001234567 | Name: Juan Carlos Pérez García | Code: 20211020001 | Career: Computer Engineering | Age: 22
Position 1: ID: 1002345678 | Name: María Fernanda López Rodríguez | Code: 20211020002 | Career: Electronics Engineering | Age: 21
...
```

---

## 🔍 Key Concepts

### Header and Sentinel Nodes

This implementation uses two special nodes:

- **Header Node (cab)**: Dummy node at the beginning
  - Simplifies insertion at the start
  - Eliminates special cases for empty list
  - Never contains actual data

- **Sentinel Node (cen)**: Dummy node at the end
  - Marks the end of the list
  - Avoids null pointer checks
  - Simplifies insertion at the end

### Advantages

- **O(1) insertion/deletion** at both ends
- **Bidirectional traversal** for flexible navigation
- **No null pointer checks** due to sentinel
- **Generic template** supports any data type
- **Exception handling** for invalid operations

### Memory Management

```cpp
// Proper cleanup in destructor
~ListaDoble() {
    NodoDoble<T>* actual = cab->sig;
    while (actual != cen) {
        NodoDoble<T>* temp = actual;
        actual = actual->sig;
        delete temp;
    }
    delete cab;
    delete cen;
}
```

---

## 📁 File Format

The `personas.txt` file uses CSV format:

```csv
cedula,nombre,codigo,carrera,edad
1001234567,Juan Carlos Pérez García,20211020001,Ingeniería de Sistemas,22
1002345678,María Fernanda López Rodríguez,20211020002,Ingeniería Electrónica,21
```

### CSV Structure

- **Header row**: Field names (automatically skipped during load)
- **Data rows**: Comma-separated values
- **Encoding**: UTF-8 for special characters (á, é, í, ó, ú, ñ)

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
- File errors: Handled with error messages
- Input validation: Prevents invalid operations

---

## 🧪 Testing

### Test Cases Covered

1. **Empty list operations**
   - Inserting into empty list
   - Checking size of empty list
   - Attempting to access empty list

2. **Boundary conditions**
   - Insert at position 0 and n
   - Delete first and last elements
   - Access at boundaries

3. **File operations**
   - Load from existing file
   - Save to new file
   - Handle missing file

4. **Search operations**
   - Search existing records
   - Search non-existing records
   - Multiple searches

---

## 📚 References

- Cormen, T. H., et al. *Introduction to Algorithms* (3rd ed.). MIT Press.
- Classic doubly linked list implementation with header and sentinel optimization
- Universidad Distrital Francisco José de Caldas - Data Structures course

---

## 👤 Authors

- **Nicolás Martínez Pineda** - [GitHub](https://github.com/nikkaoyy)
- **Ian Nicolás Sandoval Martínez**

---

## 📝 License

This project is developed for educational purposes at Universidad Distrital Francisco José de Caldas.

---

## 🤝 Contributing

Feel free to fork this repository and submit pull requests for improvements:

- Additional search algorithms
- Performance optimizations
- Enhanced error handling
- New utility functions

---

⭐ If you found this project helpful, consider giving it a star on GitHub!
