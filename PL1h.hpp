#include <iostream>
#include <string>
using namespace std;

// Estructura de la reserva
struct Reserva
{
    string nombre;
    string localizacion;
    int n_personas;
    int hora;
    string tipo;
    Reserva *next;
};

// Estructura de las mesas
struct Mesas
{
    int n_mesa;
    int capacidad;
    string localizacion;
    Mesas *next;
};

// Estructura de los pedidos
struct Pedido
{
    int n_mesa;
    string nombre;
    int n_personas;
    string tipo;
    string localizacion;
    Pedido *next;
};

// cReservas; reservas ya realizadas
struct cReserva
{
    Reserva *front;
    Reserva *back;
};

// cPedidos; pedidos almacenados
struct cPedido
{
    Pedido *front;
    Pedido *back;
};

// pMesas; mesas libres
struct pMesas
{
    Mesas *top;
};

// introducir Reservas
void introducirReserva(cReserva &cola, Reserva *reserva)
{
    reserva->next = nullptr;
    if (cola.back == nullptr)
    {
        cola.front = cola.back = reserva;
    }
    else
    {
        cola.back->next = reserva;
        cola.back = reserva;
    }
}

// sacar Reservas
Reserva *sacarReserva(cReserva &cola)
{
    if (cola.front == nullptr)
    {
        return nullptr;
    }
    else
    {
        Reserva *reserva = cola.front;
        cola.front = cola.front->next;
        if (cola.front == nullptr)
        {
            cola.back = nullptr;
        }
        return reserva;
    }
}

// apilar mesas
void apilarMesas(pMesas &pila, Mesas *mesas)
{
    mesas->next = pila.top;
    pila.top = mesas;
}

// Apiilar solo una mesa
void apilarUnaMesas(pMesas &pila, Mesas *mesas)
{
    mesas->next = pila.top;
}

// desapilar mesas
Mesas *desapilarMesas(pMesas &pila)
{
    if (pila.top == nullptr)
    {
        return nullptr;
    }
    else
    {
        Mesas *mesas = pila.top;
        pila.top = pila.top->next;
        return mesas;
    }
}

// Buscar mesas por capacidad
Mesas *buscarMesa(pMesas &pila, int capacidad, string localizacion)
{
    Mesas *mesa = pila.top;
    Mesas *mesaAnterior = nullptr;
    while (mesa != nullptr)
    {
        if ((capacidad <= 4 && mesa->capacidad == 4 && mesa->localizacion == localizacion) || (capacidad >= 5 && capacidad <= 8 && mesa->capacidad == 8 && mesa->localizacion == localizacion))
        {
            if (mesaAnterior != nullptr)
            {
                mesaAnterior->next = mesa->next;
            }
            else
            {
                pila.top = mesa->next;
            }
            cout << mesa->n_mesa;
            return mesa;
        }
        mesaAnterior = mesa;
        mesa = mesa->next;
    }
    cout << "No quedan mesas con esas especificaciones" << endl;
    return nullptr;
}

// introducir pedido
void introducirPedido(cPedido &cola, Pedido *pedido)
{
    pedido->next = nullptr;
    if (cola.back == nullptr)
    {
        cola.front = cola.back = pedido;
    }
    else
    {
        cola.back->next = pedido;
        cola.back = pedido;
    }
}

// sacarPedido
Pedido *sacarPedido(cPedido &cola)
{
    if (cola.front == nullptr)
    {
        return nullptr;
    }
    else
    {
        Pedido *pedido = cola.front;
        cola.front = cola.front->next;
        if (cola.front == nullptr)
        {
            cola.back = nullptr;
        }
        return pedido;
    }
}
