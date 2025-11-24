#include <iostream>
#include "ArbolRojiNegro.h"

using namespace std;

void mostrarCola(queue<int> cola, string nombre) {
    cout << nombre << ": ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

// Llamada al programa principal
int main() {
    ArbolRojiNegro arbol; // Crear arbol de la clase ArbolRojiNegro
    
    cout << "===============================================" << endl;
    cout << "    PROGRAMA DE ARBOL ROJO-NEGRO" << endl;
    cout << "===============================================\n" << endl;
    
    // ========================================
    // FASE 1: Inserción mostrando los 3 casos
    // ========================================
    cout << "1. INSERCION DE CLAVES (3 casos de ajuste)" << endl;
    cout << "-------------------------------------------" << endl;
    
    // Caso 1: Tío rojo - recoloreo
    arbol.insertar(10, "Raiz inicial");
    cout << "Insertado: 10 (Raiz inicial)" << endl;
    
    arbol.insertar(5, "Hijo izquierdo");
    cout << "Insertado: 5 (Hijo izquierdo)" << endl;
    
    arbol.insertar(15, "Hijo derecho");
    cout << "Insertado: 15 (Hijo derecho)" << endl;
    
    arbol.insertar(3, "CASO 1: Tio rojo - recoloreo");
    cout << "Insertado: 3 --> CASO 1: Tio rojo, se hace recoloreo" << endl;
    
    arbol.insertar(7, "Fuerza recoloreo");
    cout << "Insertado: 7 (Fuerza recoloreo)" << endl;
    
    // Caso 2: Nodo en posición media - rotación doble
    arbol.insertar(6, "CASO 2: Rotacion doble");
    cout << "Insertado: 6 --> CASO 2: Nodo medio, rotacion doble" << endl;
    
    arbol.insertar(12, "Hijo izq de 15");
    cout << "Insertado: 12 (Hijo izquierdo de 15)" << endl;
    
    arbol.insertar(18, "Hijo der de 15");
    cout << "Insertado: 18 (Hijo derecho de 15)" << endl;
    
    // Caso 3: Nodo externo - rotación simple
    arbol.insertar(1, "CASO 3: Rotacion simple");
    cout << "Insertado: 1 --> CASO 3: Nodo externo, rotacion simple" << endl;
    
    arbol.insertar(8, "Completa subarbol");
    cout << "Insertado: 8 (Completa subarbol)" << endl;
    
    arbol.insertar(11, "Mas nodos");
    cout << "Insertado: 11" << endl;
    
    arbol.insertar(13, "Mas nodos");
    cout << "Insertado: 13" << endl;
    
    arbol.insertar(20, "Nodo final");
    cout << "Insertado: 20" << endl;
    
    // ========================================
    // FASE 2: Mostrar dos recorridos
    // ========================================
    
    // En este caso el Inorden y Preorden
    
    cout << "\n2. PRIMEROS DOS RECORRIDOS" << endl;
    cout << "-------------------------------------------" << endl;
    mostrarCola(arbol.inorden(), "INORDEN  ");
    mostrarCola(arbol.preorden(), "PREORDEN ");
    
    // ========================================
    // FASE 3: Buscar clave dada por usuario
    // ========================================
    cout << "\n3. BUSQUEDA DE CLAVE" << endl;
    cout << "-------------------------------------------" << endl;
    
    int claveBuscar;
    cout << "Ingrese una clave a buscar: "; // Pedimos la clave
    cin >> claveBuscar;
    
    string info = arbol.buscar(claveBuscar); // Llamamos el método buscar(clave)
    if (!info.empty()) {
        cout << "\n[ENCONTRADO] Clave " << claveBuscar << endl;
        cout << "Informacion: " << info << endl;
    } else {
        cout << "\n[NO ENCONTRADO] La clave " << claveBuscar 
             << " no existe en el arbol." << endl;
    }
    
    // Búsquedas adicionales de demostración
    cout << "\nBusquedas adicionales:" << endl;
    cout << "Clave 10: " << arbol.buscar(10) << endl;
    cout << "Clave 15: " << arbol.buscar(15) << endl;
    
    // ========================================
    // FASE 4: Eliminación de los 4 casos
    // ========================================
    cout << "\n4. ELIMINACION DE CLAVES (4 casos)" << endl;
    cout << "-------------------------------------------" << endl;
    
    // Caso 1: Eliminar nodo HOJA
    cout << "\nCASO 1 - Eliminando nodo HOJA (20):" << endl;
    if (arbol.eliminar(20)) {
        cout << "[OK] Clave 20 eliminada (era hoja)." << endl;
        mostrarCola(arbol.inorden(), "Arbol: ");
    }
    
    // Caso 2: Eliminar nodo con UN hijo
    cout << "\nCASO 2 - Eliminando nodo con UN HIJO (1):" << endl;
    if (arbol.eliminar(1)) {
        cout << "[OK] Clave 1 eliminada (tenia un hijo)." << endl;
        mostrarCola(arbol.inorden(), "Arbol: ");
    }
    
    // Caso 3: Eliminar nodo con DOS hijos
    cout << "\nCASO 3 - Eliminando nodo con DOS HIJOS (5):" << endl;
    if (arbol.eliminar(5)) {
        cout << "[OK] Clave 5 eliminada (tenia dos hijos)." << endl;
        mostrarCola(arbol.inorden(), "Arbol: ");
    }
    
    // Caso 4: Eliminar nodo NEGRO (requiere ajuste)
    cout << "\nCASO 4 - Eliminando nodo NEGRO con ajuste (15):" << endl;
    if (arbol.eliminar(15)) {
        cout << "[OK] Clave 15 eliminada (negro, requirio ajuste)." << endl;
        mostrarCola(arbol.inorden(), "Arbol: ");
    }
    
    // ========================================
    // FASE 5: Mostrar otros dos recorridos
    // ========================================
    cout << "\n5. RECORRIDOS RESTANTES" << endl;
    cout << "-------------------------------------------" << endl;
    mostrarCola(arbol.posorden(), "POSORDEN  ");
    mostrarCola(arbol.porNiveles(), "POR NIVELES");
    
    // ========================================
    // DEMOSTRACIÓN ADICIONAL
    // ========================================
    
    // Dando una modificación a través de búsquedas
    cout << "\n6. FUNCIONALIDADES ADICIONALES" << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << "\nModificando informacion de clave 10..." << endl;
    if (arbol.modificar(10, "Raiz modificada post-eliminaciones")) {
        cout << "[OK] Modificacion exitosa." << endl;
        cout << "Nueva info: " << arbol.buscar(10) << endl;
    }
    
    // Estado final
    cout << "\n===============================================" << endl;
    cout << "           ESTADO FINAL DEL ARBOL" << endl;
    cout << "===============================================" << endl;
    mostrarCola(arbol.inorden(), "INORDEN FINAL");
    
    cout << "\n¡Programa ejecutado exitosamente!" << endl;
    cout << "===============================================\n" << endl;
    
    return 0;
}
