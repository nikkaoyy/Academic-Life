# 📚 Lists — Data Structures in C++

This module implements **generic linked lists** in C++, demonstrating core concepts of **dynamic memory management**, **template programming**, and **node manipulation**.  
It is part of the *Data Structures* section of the **Computer Science** repository.

---

## 🧩 Overview

A **list** is a dynamic linear data structure composed of **nodes** linked through pointers.  
Each node stores an element and a reference to the next node.  
This implementation supports generic types (`int`, `float`, `char`, etc.) using C++ templates.

---

## ⚙️ Features

- ✅ Insert elements:
  - at the **beginning**
  - at the **end**
  - at a **specific position**
- 🔍 Search for elements by position
- ✏️ Modify existing nodes
- 🗑️ Delete elements safely
- 📏 Retrieve list size (`getTam()`)
- 💡 Supports **any data type** through templates

---

## 🧠 Implementation Details

### `Nodo<T>`
A node structure that holds:
- `info`: data of type `T`
- `sig`: pointer to the next node

### `Lista<T>`
Main template class that defines list behavior:
- `insertar_inicio(T info)`
- `insertar_final(T info)`
- `insertar_pos(T info, int pos)`
- `eliminar(int pos)`
- `obtenerDato(int pos)`
- `modificar(int pos, T nuevoDato)`
- `getTam()`

All methods include **exception handling** (`out_of_range`) for invalid positions.

---

## 🧾 Example Program

The `main.cpp` file demonstrates usage by creating **three lists**:
- Integers  
- Reals  
- Characters  

Each list:
1. Inserts 10 elements (3 at start, 3 at end, 4 in the middle)  
2. Searches and prints data by position  
3. Deletes that position  
4. Modifies the node at the same position  
5. Displays the final list content  

---

## 💻 How to Run

### Using **Dev-C++**
1. Open the project `BookshopList.dev`.
2. Make sure `main.cpp` and `lista.h` are included.
3. Compile and run.

### Using **bash** or terminal:
```bash
g++ main.cpp -o list_program
./list_program
