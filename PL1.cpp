#include <iostream>
#include <string>
#include "PL1generacionReservas.hpp"

using namespace std;

int main()
{
    int entrada = -1;
    while (entrada != 0)
    {
        cout << "|--------------------------------------------------------------Restaurante cpp----------------------------------------------------------------------------------|" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        cout << "|1. Generar aleatoriamente la cola de reservas antes de la apertura del restaurante.                                                                            |" << endl;
        cout << "|2. Mostrar en pantalla los datos de la cola de reservas.                                                                                                       |" << endl;
        cout << "|3. Borrar la cola de reservas.                                                                                                                                 |" << endl;
        cout << "|4. Generar aleatoriamente la pila de mesas.                                                                                                                    |" << endl;
        cout << "|5. Mostrar en pantalla los datos de la pila de mesas.                                                                                                          |" << endl;
        cout << "|6. Borrar la pila de mesas.                                                                                                                                    |" << endl;
        cout << "|7. Gestionar la primera reserva. Una vez gestionada la reserva, se mostraran en pantalla ambas colas de reservas, la pila de mesas libres y la cola de pedidos.|" << endl;
        cout << "|8. Gestion de reservas y pedido. Una vez reservada esa hora, mostrar ambas colas de reservas, la pila de mesas libres y la cola de pedidos.                    |" << endl;
        cout << "|9. Gestion hasta el final. Al finalizar, mostrar ambas colas, la pila de mesas y la cola de pedidos.                                                           |" << endl;
        cout << "|0. Salir.                                                                                                                                                      |" << endl;
        cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

        cin >> entrada;
        switch (entrada)
        {
        case 0:
            break;
        case 1:
            generarReservas(12);
            break;
        case 2:
            mostrarTodasReservas();
            break;
        case 3:
            sacarMostrarReservas();
            break;
        case 4:
            generarMesas(20);
            break;
        case 5:
            mostrarMesas();
            break;
        case 6:
            sacarMesas();
            break;
        case 7:
            simulacion7();
            break;
        case 8:
            simulacion8();
            break;
        case 9:
            simulacion9();
            break;
        default:
            break;
        }
    }
}