#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	return 0;
}

struct Prenda {
    int codigo;
    string nombre;
    string talla;
    int cantidad;
    float precio;

    Prenda* siguiente;
};

Prenda* inicioLista = NULL;

void registrarPrenda() {

    Prenda* nuevo = new Prenda();

    cout << "\n--- REGISTRAR PRENDA ---\n";

    cout << "Codigo: ";
    cin >> nuevo->codigo;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nuevo->nombre);

    cout << "Talla: ";
    getline(cin, nuevo->talla);

    cout << "Cantidad: ";
    cin >> nuevo->cantidad;

    cout << "Precio: ";
    cin >> nuevo->precio;

    nuevo->siguiente = NULL;

    if (inicioLista == NULL) {

        inicioLista = nuevo;

    } else {

        Prenda* auxiliar = inicioLista;

        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }

        auxiliar->siguiente = nuevo;
    }

    cout << "\n La prenda fue registrada correctamente.\n";
}

void mostrarInventario() {

    if (inicioLista == NULL) {

        cout << "\n El inventario esta vacio.\n";
        return;
    }

    Prenda* auxiliar = inicioLista;

    cout << "\n--- INVENTARIO ---\n";

    while (auxiliar != NULL) {

        cout << "Codigo: " << auxiliar->codigo << endl;
        cout << "Nombre: " << auxiliar->nombre << endl;
        cout << "Talla: " << auxiliar->talla << endl;
        cout << "Cantidad: " << auxiliar->cantidad << endl;
        cout << "Precio: " << auxiliar->precio << endl;

        cout << "----------------------\n";

        auxiliar = auxiliar->siguiente;
    }
}

void buscarPrenda() {

    int codigoBuscar;
    bool encontrado = false;

    cout << "\nIngrese codigo a buscar: ";
    cin >> codigoBuscar;

    Prenda* auxiliar = inicioLista;

    while (auxiliar != NULL) {

        if (auxiliar->codigo == codigoBuscar) {

            cout << "\nPrenda encontrada\n";

            cout << "Nombre: " << auxiliar->nombre << endl;
            cout << "Talla: " << auxiliar->talla << endl;
            cout << "Cantidad: " << auxiliar->cantidad << endl;
            cout << "Precio: " << auxiliar->precio << endl;

            encontrado = true;
        }

        auxiliar = auxiliar->siguiente;
    }

    if (!encontrado) {
        cout << "\nPrenda no encontrada.\n";
    }
}