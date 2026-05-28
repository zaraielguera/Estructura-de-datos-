#include <iostream>
#include <string>

using namespace std;


struct Prenda {
    int codigo;
    string nombre;
    string talla;
    int cantidad;
    Prenda* siguiente; 
};


void registrarPrenda(Prenda*& cabeza);
void buscarPrenda(Prenda* cabeza);
void mostrarInventario(Prenda* cabeza); 

int main() {
    Prenda* cabeza = NULL; 
    int opcion;

    do {
        cout << "\n--- TIENDA DE ROPA (MÓDULO: LISTAS) ---" << endl;
        cout << "1. Registrar una prenda en inventario" << endl;
        cout << "2. Buscar una prenda por codigo" << endl;
        cout << "3. Ver inventario completo" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: 
                registrarPrenda(cabeza); 
                break;
            case 2: 
                buscarPrenda(cabeza); 
                break;
            case 3: 
                mostrarInventario(cabeza); 
                break;
            case 4: 
                cout << "Saliendo del modulo de listas..." << endl; 
                break;
            default: 
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 4);

    return 0;
}


void registrarPrenda(Prenda*& cabeza) {
    // Crear nueva prenda en memoria dinámica
    Prenda* nuevaPrenda = new Prenda();
    
    cout << "\n--- Ingresar datos de la prenda ---" << endl;
    cout << "Codigo: "; cin >> nuevaPrenda->codigo;
    cin.ignore(); 
    cout << "Nombre: "; getline(cin, nuevaPrenda->nombre);
    cout << "Talla: "; getline(cin, nuevaPrenda->talla);
    cout << "Cantidad: "; cin >> nuevaPrenda->cantidad;
    
    nuevaPrenda->siguiente = NULL; 

   
    if (cabeza == NULL) {
        cabeza = nuevaPrenda;
    } else {
       
        Prenda* auxiliar = cabeza;
        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }
        
        auxiliar->siguiente = nuevaPrenda;
    }
    cout << "-> Prenda registrada correctamente." << endl;
}


void buscarPrenda(Prenda* cabeza) {
    int codigoBuscado;
    cout << "\nIngrese el codigo de la prenda a buscar: "; 
    cin >> codigoBuscado;

    Prenda* auxiliar = cabeza;
    bool encontrado = false;

    while (auxiliar != NULL) {
        if (auxiliar->codigo == codigoBuscado) {
            encontrado = true;
            cout << "\n=== PRENDA ENCONTRADA ===" << endl;
            cout << "Codigo: " << auxiliar->codigo << endl;
            cout << "Nombre: " << auxiliar->nombre << endl;
            cout << "Talla: " << auxiliar->talla << endl;
            cout << "Cantidad en Stock: " << auxiliar->cantidad << endl;
            break; 
        }
        auxiliar = auxiliar->siguiente; 
    }

    if (!encontrado) {
        cout << "-> Prenda no encontrada." << endl;
    }
}

void mostrarInventario(Prenda* cabeza) {
    if (cabeza == NULL) {
        cout << "\nEl inventario esta vacio." << endl;
        return;
    }
    
    Prenda* auxiliar = cabeza;
    cout << "\n=== INVENTARIO DE LA TIENDA ===" << endl;
    while (auxiliar != NULL) {
        cout << "[" << auxiliar->codigo << "] " << auxiliar->nombre 
             << " | Talla: " << auxiliar->talla 
             << " | Stock: " << auxiliar->cantidad << endl;
        auxiliar = auxiliar->siguiente;
    }
}