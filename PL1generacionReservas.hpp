#include <iostream>
#include <string>
#include <random>
#include "PL1h.hpp"

using namespace std;

// Generar cReservas con las reservas realizadas por los clienetes
// Generar pMesas con las mesas libres
// Simular gestion de cReservas y creacion de cPedidos
// Menu opciones

// Random
int generarNumeroAleatorio(int min, int max)
{
    random_device rd;
    default_random_engine generador(rd());
    uniform_int_distribution<int> distribucion(min, max);
    return distribucion(generador);
}

/*
 *Reservas
 */

string nombres[] = {"Sofía", "Hugo", "Lucía", "Martín", "Valentina", "Pablo", "María", "Mateo", "Julia", "Daniel", "Marta", "David", "Paula", "Alejandro", "Andrea", "Adrián", "Carmen", "Diego", "Isabel", "Ana"};
string nombreAle()
{
    int nombreAleatorio = generarNumeroAleatorio(0, sizeof(nombres) / sizeof(nombres[0]) - 1);
    return nombres[nombreAleatorio];
}

string localizacion[] = {"Terraza", "Interior"};

string localizacionAleReservas()
{
    int localizacionAleatoria = generarNumeroAleatorio(0, sizeof(localizacion) / sizeof(localizacion[0]) - 1);
    return localizacion[localizacionAleatoria];
}

int numeroPersonasAle()
{
    return generarNumeroAleatorio(1, 8);
}

int horas[] = {13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 13, 15, 14, 13, 15, 13};
static int indice = 0;
int horaAle()
{
    int hora = horas[indice];
    indice = (indice + 1) % (sizeof(horas) / sizeof(horas[0]));
    return hora;
}

string tipo[] = {"Vegano", "Sin Gluten", "Completo"};

string tipoAle()
{
    int tipoAleatorio = generarNumeroAleatorio(0, sizeof(tipo) / sizeof(tipo[0]) - 1);
    return tipo[tipoAleatorio];
}

// Inicializar la cola de reservas
cReserva creserva = {nullptr, nullptr};

// Crear una reserva aleatoria
void generarReservaAle()
{
    Reserva *reserva1 = new Reserva;
    reserva1->nombre = nombreAle();
    reserva1->localizacion = localizacionAleReservas();
    reserva1->n_personas = numeroPersonasAle();
    reserva1->hora = horaAle();
    reserva1->tipo = tipoAle();
    introducirReserva(creserva, reserva1);
}

// Crear x reservas aleatorias
void generarReservas(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        generarReservaAle();
    }
    cout << cantidad << " Reservas generadas" << endl;
    cout << endl;
}

// Sacar y mostrar las reservas
void sacarMostrarReservas()
{
    bool hayReservas = true;
    while (hayReservas == true)
    {
        Reserva *reservaSacar = sacarReserva(creserva);
        if (reservaSacar == nullptr)
        {
            cout << "No quedan mas reservas" << endl;
            hayReservas = false;
            break;
        }
        cout << endl;
        cout << "Reserva eliminada: " << endl;
        cout << "Nombre: " << reservaSacar->nombre << endl;
        cout << "Localizacion: " << reservaSacar->localizacion << endl;
        cout << "Numero de personas: " << reservaSacar->n_personas << endl;
        cout << "Hora de la reserva: " << reservaSacar->hora << endl;
        cout << "Preferencia del menu:  " << reservaSacar->tipo << endl;
        cout << endl;
    }
}

// Mostrar reservas
void mostrarTodasReservas()
{
    Reserva *mostrarReserva = creserva.front;
    if (mostrarReserva == nullptr)
    {
        cout << "No hay mas reservas" << endl;
        cout << endl;
    }
    while (mostrarReserva != nullptr)
    {
        cout << endl;
        cout << "Reserva: " << endl;
        cout << "Nombre: " << mostrarReserva->nombre << endl;
        cout << "Localizacion: " << mostrarReserva->localizacion << endl;
        cout << "Numero de personas: " << mostrarReserva->n_personas << endl;
        cout << "Hora de la reserva: " << mostrarReserva->hora << endl;
        cout << "Preferencia del menú: " << mostrarReserva->tipo << endl;
        cout << endl;
        mostrarReserva = mostrarReserva->next;
    }
}

/*
 *Mesas
 */

int numero_mesa[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
static int indice_mesa = 0;
int numero_de_mesa()
{
    int mesa = numero_mesa[indice_mesa];
    indice_mesa = (indice_mesa + 1) % (sizeof(numero_mesa) / sizeof(numero_mesa[0]));
    return mesa;
}

int capacidad[] = {4, 8};
int capacidadAle()
{
    int capacidadAleatorio = generarNumeroAleatorio(0, sizeof(capacidad) / sizeof(capacidad[0]) - 1);
    return capacidad[capacidadAleatorio];
}

string localizacionAleMesas()
{
    int localizacionAleatoria = generarNumeroAleatorio(0, sizeof(localizacion) / sizeof(localizacion[0]) - 1);
    return localizacion[localizacionAleatoria];
}

// Inicializar la pila de mesas
pMesas pmesas = {nullptr};
// Generar una mesa aleatoria
void generarMesaAle()
{
    Mesas *mesa1 = new Mesas;
    mesa1->n_mesa = numero_de_mesa();
    mesa1->localizacion = localizacionAleMesas();
    mesa1->capacidad = capacidadAle();
    apilarMesas(pmesas, mesa1);
}

void generarMesas(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        generarMesaAle();
    }
    cout << cantidad << " Mesas generadas" << endl;
    cout << endl;
}

// Mostrar Datos de las mesas
void mostrarMesas()
{
    cout << "MESAS LIBRES: " << endl;
    Mesas *mostrarMesa = pmesas.top;
    if (mostrarMesa == nullptr)
    {
        cout << "No hay más mesas" << endl;
    }
    while (mostrarMesa != nullptr)
    {
        cout << "Numero de mesa: " << mostrarMesa->n_mesa << endl;
        cout << "Localizacion:  " << mostrarMesa->localizacion << endl;
        cout << "Capacidad: " << mostrarMesa->capacidad << endl;
        cout << endl;
        mostrarMesa = mostrarMesa->next;
    }
}

// Borrar mesas
void sacarMesas()
{
    Mesas *sacarMesa = desapilarMesas(pmesas);
    if (sacarMesa == nullptr)
    {
        cout << "No hay mesas registradas" << endl;
    }
    while (sacarMesa != nullptr)
    {
        sacarMesa = desapilarMesas(pmesas);
    }
}

// Inicializar pila de mesas ocupadas
pMesas pmesasOcupadas = {nullptr};

// Inicializar la cola Pedidos
cPedido cpedidos = {nullptr, nullptr};

// Para calular cada 3 pedidos
int counter = 1;

// Resetear las mesas cada 4 pedidos (salto de turno)
void resetMesas()
{
    if (pmesasOcupadas.top != nullptr)
    {
        for (int i = 0; i < counter / 2; i++)
        {
            Mesas *mesa = desapilarMesas(pmesasOcupadas);
            apilarMesas(pmesas, mesa);
        }
    }
    else
    {
        cout << "No hay mesas ocupadas" << endl;
        cout << endl;
    }
}

// inicializar cpendientes
cReserva cpendientes = {nullptr, nullptr};

// Gestionar las reservas pendientes cada 2 que salen de creservas
void gestionarPendientes()
{
    Reserva *reserva = sacarReserva(cpendientes);
    if (cpendientes.front != nullptr)
    {

        cout << "Reserva pendinte de: " << reserva->nombre << endl;
        cout << "Mesa asignada: " << endl;
        cout << "Numero de mesa: ";
        Mesas *mesaEncontrada = buscarMesa(pmesas, reserva->n_personas, reserva->localizacion);
        cout << endl;
        cout << "Capacidad de la mesa: " << mesaEncontrada->capacidad << endl;
        cout << "Localizacion de la mesa: " << mesaEncontrada->localizacion << endl;
        if (mesaEncontrada != nullptr)
        {
            Pedido *pedido = new Pedido;
            pedido->nombre = reserva->nombre;
            pedido->n_mesa = mesaEncontrada->n_mesa;
            pedido->localizacion = mesaEncontrada->localizacion;
            pedido->n_personas = reserva->n_personas;
            pedido->tipo = reserva->tipo;
            introducirPedido(cpedidos, pedido);
            apilarMesas(pmesasOcupadas, mesaEncontrada);
        }
        if (counter % 4 == 0)
        {
            resetMesas();
        }
        counter++;
    }
}

// Buscar una mesa con x capacidad en la pila de mesas disponibles
void encontrarMoverMesa()
{
    Reserva *reserva = sacarReserva(creserva);
    cout << "Reserva de: " << reserva->nombre << endl;
    cout << "Mesa asignada: " << endl;
    cout << "Numero de mesa: ";
    Mesas *mesaEncontrada = buscarMesa(pmesas, reserva->n_personas, reserva->localizacion);
    cout << endl;
    cout << "Capacidad de la mesa: " << mesaEncontrada->capacidad << endl;
    cout << "Localizacion de la mesa: " << mesaEncontrada->localizacion << endl;
    cout << endl;

    if (mesaEncontrada == nullptr)
    {
        Reserva *pendiente = new Reserva;
        pendiente->nombre = reserva->nombre;
        pendiente->localizacion = reserva->localizacion;
        pendiente->n_personas = reserva->n_personas;
        pendiente->tipo = reserva->tipo;
        pendiente->hora = 0;
        introducirReserva(cpendientes, pendiente);
        cout << "Pedido introducido a pendientes. Nombre: " << pendiente->nombre << endl;
        cout << endl;
    }
    else
    {
        Pedido *pedido = new Pedido;
        pedido->nombre = reserva->nombre;
        pedido->n_mesa = mesaEncontrada->n_mesa;
        pedido->localizacion = mesaEncontrada->localizacion;
        pedido->n_personas = reserva->n_personas;
        pedido->tipo = reserva->tipo;
        introducirPedido(cpedidos, pedido);
        apilarMesas(pmesasOcupadas, mesaEncontrada);
    }
    if (counter % 4 == 0)
    {
        resetMesas();
    }
    if (counter % 3 == 0)
    {
        cout << "Gestionando Pendientes: " << endl;
        gestionarPendientes();
    }
    counter++;
}

void mostrarMesasOcupadas()
{
    cout << "MESAS OCUPADAS: " << endl;
    Mesas *mostrarMesa = pmesasOcupadas.top;
    if (mostrarMesa == nullptr)
    {
        cout << "No hay más mesas" << endl;
    }
    while (mostrarMesa != nullptr)
    {
        cout << "Numero de mesa: " << mostrarMesa->n_mesa << endl;
        cout << "Localizacion: " << mostrarMesa->localizacion << endl;
        cout << "Capacidad: " << mostrarMesa->capacidad << endl;
        cout << endl;
        mostrarMesa = mostrarMesa->next;
    }
}

// Mostrar Pedidos
void mostrarPedidos()
{
    Pedido *mostrarReserva = cpedidos.front;
    if (mostrarReserva == nullptr)
    {
        cout << "No hay reservas" << endl;
    }
    while (mostrarReserva != nullptr)
    {
        cout << endl;
        cout << "Pedido: " << endl;
        cout << "Nombre: " << mostrarReserva->nombre << endl;
        cout << "Numero de Mesa: " << mostrarReserva->n_mesa << endl;
        cout << "Localizacion: " << mostrarReserva->localizacion << endl;
        cout << "Numero de personas: " << mostrarReserva->n_personas << endl;
        cout << "Preferencia del menú: " << mostrarReserva->tipo << endl;
        cout << endl;
        mostrarReserva = mostrarReserva->next;
    }
}

/*
 *Simular  la  gestión  de  la primera  reserva  de  la  colacReservas, según  se  ha  detallado  en  el funcionamiento del programa,
 *creando el pedido del cliente si es posible e insertándolo en cPedidos.
 *Una vez gestionada la reserva, se mostrarán1en pantalla ambas colas de reservas, la pila de mesas libres y la colade pedidos
 */

void simulacion7()
{
    generarReservas(1);
    generarMesas(20);
    encontrarMoverMesa();
    mostrarTodasReservas();
    mostrarMesas();
    /*mostrarTodasReservas();*/
    mostrarPedidos();
}
void simulacion8()
{
    generarReservas(4);
    generarMesas(20);
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    /*mostrarTodasReservas();*/
    mostrarMesas();
    mostrarMesasOcupadas();
    mostrarPedidos();
}
void simulacion9()
{
    generarReservas(15);
    generarMesas(20);
    /*mostrarTodasReservas();*/
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    encontrarMoverMesa();
    mostrarMesas();
    mostrarMesasOcupadas();
    mostrarPedidos();
}