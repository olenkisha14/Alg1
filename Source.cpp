//Main.cpp

#include <iostream>
#include <vector>
#include "Proveedor.h"
#include "Producto.h"

using namespace std;

int main() {
    vector<Proveedor> proveedores;
    vector<Producto> productos;

    int opcion;

    do {
        cout << "\nMENU\n";
        cout << "1. Insertar producto\n";
        cout << "2. Insertar proveedor\n";
        cout << "3. Modificar Producto\n";
        cout << "4. Eliminar productos vencidos\n";
        cout << "5. Reportes\n";
        cout << "6. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            int idProducto;
            string nombre;
            string tipo;
            int cantidad;
            string categoria;
            int anio;
            double precio;
            int proveedorIndex;

            cout << "Ingrese el ID del producto: "; cin >> idProducto; cin.ignore();
            cout << "Ingrese el nombre del producto: "; getline(cin, nombre);
            cout << "Ingrese el tipo del producto (polvo o liquido): "; cin >> tipo;
            cout << "Ingrese la cantidad del producto: "; cin >> cantidad;
            cout << "Ingrese la categoria del producto (A, B o C): "; cin >> categoria;
            cout << "Ingrese el anio del producto: "; cin >> anio;
            cout << "Ingrese el precio del producto: "; cin >> precio;

            cout << "Proveedores disponibles:\n";
            for (size_t i = 0; i < proveedores.size(); ++i) {
                cout << i << ". " << proveedores[i].getRazonSocial() << endl;
            }

            cout << "Ingrese el índice del proveedor para este producto: "; cin >> proveedorIndex;

            if (proveedorIndex >= 0 && proveedorIndex < proveedores.size()) {
                Producto nuevoProducto(idProducto, nombre, tipo, cantidad, categoria, anio, precio, &proveedores[proveedorIndex]);
                productos.push_back(nuevoProducto);
                cout << "Producto agregado exitosamente.\n";
            }
            else {
                cout << "Índice de proveedor inválido.\n";
            }
        }
        break;

        case 2:
        {
            string ruc;
            string razonSocial;
            string categoria;
            string direccion;
            string telefono;

            cout << "Ingrese el RUC del proveedor: "; cin >> ruc;
            cin.ignore();
            cout << "Ingrese la razón social del proveedor: ";
            getline(cin, razonSocial);
            cout << "Ingrese la categoría del proveedor: "; cin >> categoria;
            cin.ignore();
            cout << "Ingrese la direccion del proveedor: ";
            getline(cin, direccion);
            cout << "Ingrese el telefono del proveedor: "; cin >> telefono;

            Proveedor nuevoProveedor(ruc, razonSocial, categoria, direccion, telefono);
            proveedores.push_back(nuevoProveedor);

            cout << "Proveedor agregado exitosamente.\n";
        }
        break;

        case 3:
        {
            int productoIndex;

            cout << "Productos existentes:\n";
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << i << ". " << productos[i].getNombre() << endl;
            }

            cout << "Ingrese el indice del producto a modificar: "; cin >> productoIndex;

            if (productoIndex >= 0 && productoIndex < productos.size()) {
                Producto& productoModificar = productos[productoIndex];

                string nuevoNombre;
                string nuevoTipo;
                int nuevaCantidad;
                string nuevaCategoria;
                int nuevoanio;
                double nuevoPrecio;

                cin.ignore();
                cout << "Ingrese el nuevo nombre del producto: "; getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo tipo del producto (polvo o líquido): "; cin >> nuevoTipo;
                cout << "Ingrese la nueva cantidad del producto: "; cin >> nuevaCantidad;
                cout << "Ingrese la nueva categoría del producto (A, B o C): "; cin >> nuevaCategoria;
                cout << "Ingrese el nuevo anio del producto: "; cin >> nuevoanio;
                cout << "Ingrese el nuevo precio del producto: "; cin >> nuevoPrecio;

                productoModificar.setNombre(nuevoNombre);
                productoModificar.setTipo(nuevoTipo);
                productoModificar.setCantidad(nuevaCantidad);
                productoModificar.setCategoria(nuevaCategoria);
                productoModificar.setanio(nuevoanio);
                productoModificar.setPrecio(nuevoPrecio);

                cout << "Producto modificado exitosamente.\n";
            }
            else {
                cout << "Indice de producto invalido.\n";
            }
        }
        break;

        case 4:
        {
            int anioActual = 2024;

            int productosEliminados = 0;

            for (auto it = productos.begin(); it != productos.end(); ) {
                if (it->getanio() < anioActual) {
                    it = productos.erase(it);
                    ++productosEliminados;
                }
                else {
                    ++it;
                }
            }

            cout << productosEliminados << " productos vencidos eliminados.\n";
        }
        break;

        case 5:
        {
            cout << "Reporte de productos en stock:\n";

            for (const auto& producto : productos) {
                if (producto.getCantidad() > 0) {
                    cout << "Nombre: " << producto.getNombre() << "\n";
                    cout << "Tipo: " << producto.getTipo() << "\n";
                    cout << "Cantidad: " << producto.getCantidad() << "\n";
                    cout << "Categoría: " << producto.getCategoria() << "\n";
                    cout << "anio: " << producto.getanio() << "\n";
                    cout << "Precio: " << producto.getPrecio() << "\n";
                    cout << "Proveedor: " << producto.getProveedor()->getRazonSocial() << "\n";
                    cout << "------------------------------------\n";
                }
            }

            cout << "Fin del reporte.\n";
        }
        break;

        case 6:
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;

        default:
            cout << "Opcion invalida. Por favor, ingrese una opcion valida.\n";
        }
        system("cls");
    } while (opcion != 6);

    return 0;
}