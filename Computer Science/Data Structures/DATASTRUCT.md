# 🧩 Data Structures  
**Repository:** Computer Science  

This module contains fundamental implementations of **data structures** in C++, designed to strengthen the understanding of dynamic memory, pointer manipulation, and data abstraction through the use of templates.  

---

## 📘 Contents
- **Linked Lists (Generic Lists)**  
  Implementation of dynamic lists with header and sentinel nodes, including insertion, deletion, search, and modification methods.  

- **Stacks and Queues** *(in progress)*  
  List-based structures demonstrating FIFO and LIFO data handling.  

- **Trees and Graphs** *(coming soon)*  
  Implementations focused on traversal, insertion, search, and hierarchical organization.  

---

## ⚙️ Code Structure

### `(structure name).h`
Contains the template class `(Structure name)<T>` and the structure `Nodo<T>`:
- Insert at the beginning, end, or a specific position  
- Delete or add nodes by position
- Search and modify elements  
- Retrieve current list size via `getTam()`  

### `main.cpp`
Main program that:
1. Creates the data structure (lists, stacks, trees, etc.)  
2. Insert elements in various positions  
3. Performs search, deletion, modification, and full list printing  

---

## 💻 How to Run

### Using **Dev-C++**
1. Open the project `BookshopStructure.dev` or create a new one.  
2. Include both `structure.h` and `main.cpp`.  
3. Compile and run the program.

### Using **bash** or terminal:
```bash
g++ main.cpp -o structure
./structure
