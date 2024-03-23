#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#define TML 5

int menu(){
    int op;
    cout << "*********************************************\n";
    cout << "               MENU DE OPCIONES             *\n";
    cout << "*********************************************\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar prestamo a la lista\n";
    cout << "3. Hacer pagos de prestamos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalles de prestamo\n";
    cout << "7. Salir\n";
    cout << "*********************************************\n";
    cout << "Digite una opcion: ";
    cin >> op;
    cout << "*********************************************\n";
    cout << "\n";
    return op;
}
Cliente *BuscarCliente(Cliente *lstCl[], int contadorCl, int idCliente){
    bool encontrado = false;
    int contador =0;
    Cliente *cli = NULL;
    while (contador < contadorCl && !encontrado){
        if (lstCl[contador]->getIdCliente() == idCliente){
            encontrado = true;
            cli = lstCl[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}
Prestamo *BuscarPrestamo(Prestamo *lstPrestamo[], int contadorPrestamo, int idPrestamo){
    bool encontrado = false;
    int contador =0;
    Prestamo *ptmo = NULL;
    while (contador < contadorPrestamo && !encontrado){
        if (lstPrestamo[contador]->getNumeroPrestamo() == idPrestamo){
            encontrado = true;
            ptmo = lstPrestamo[contador];
        }
        else{
            contador++;
        }
    }
    return ptmo;
}
Cliente *agregarCliente(){
    int idCliente;
    string nombreCl,apellidoCl;
    Cliente *cli;
    cout << "Digite el Id del Cliente: ";
    cin >> idCliente;
    cout << "Digite el Nombre del Cliente: ";
    cin >> nombreCl;
    cout << "Digite el Apellido del Cliente: ";
    cin >> apellidoCl;
    cli = new Cliente(idCliente, nombreCl, apellidoCl);
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli){
    int np;
    int diafecha, mesfecha, aniofecha;
    Fecha *f1;
    float ma;
    Prestamo *ptmo;

    cout << "Digite el Numero del Prestamo: ";
    cin >> np;

    cout << "Digite la Fecha de Aprobacion (dd/mm/aa) : \n";
    cout << "dia: "; cin >> diafecha;
    cout << "mes: ";cin >> mesfecha;
    cout << "anio: ";cin >> aniofecha;
    f1 = new Fecha(diafecha,mesfecha,aniofecha);

    cout << "Digite el Monto Aprobado: $";
    cin >> ma;
    ptmo = new Prestamo(np, cli, f1, ma);
    return ptmo;
}

void registrarPago(Prestamo *ptmo){
    int diafecha, mesfecha, aniofecha;
    Fecha *f1;
    float mp;
    Pago *pg;
    cout << "Digite la Fecha del Pago (dd/mm/aa) : \n";
    cout << "dia: "; cin >> diafecha;
    cout << "mes: ";cin >> mesfecha;
    cout << "anio: ";cin >> aniofecha;
    f1 = new Fecha(diafecha, mesfecha, aniofecha);

    cout << "Digite el Monto del Pago: $";
    cin >> mp;
    pg = new Pago(f1, mp);
    ptmo->hacerPago(pg);
}

void verDetalles(Prestamo *ptmo){
    cout << "\n";
    cout << "No Prestamo : " << ptmo->getNumeroPrestamo() <<endl;
    cout << "Cliente : " << ptmo->getCliente()->getNombre() << " " << ptmo->getCliente()->getApellido() << endl;
    cout << "Fecha Aprobacion : ";
    ptmo->getFechaAprobacion()->mostrarFecha();
    cout << "\nMonto aprobado : $" << ptmo->getMontoAprobado() <<endl;
    cout << "Saldo pendiente : $" << ptmo->getSaldoPendiente() << endl;
    if (ptmo->getContadorPagos() == 0){
        cout << "\nNo tiene pagos registrados\n";
    }
    else{
        Pago **lista = ptmo->getLstPagos();
        cout <<"\nPagos\n";
        cout << "No\tFecha\t\tMonto del Pago\n";
        for (int i=0; i<ptmo->getContadorPagos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t" << lista[i]->getMontoPago() << endl;
        }
    }
}


int main()
{
    Cliente *lstCliente[TML];
    Prestamo *lstPrestamo[TML];
    Cliente *cli=NULL;
    Prestamo *ptmo = NULL;
    int opc, contCli = 0, contPtmo = 0, idCli, idPtmo;
    do{
        system("cls");
        opc = menu();
        switch (opc){
            case 1:
                ///Agregar clientes
                if (contCli < TML){
                    lstCliente[contCli] = agregarCliente();
                    contCli++;
                    cout << "\nEl cliente se agrego con exito\n";
                }else{
                    cout << "\nLa lista esta llena\n";
                }
                break;

            case 2:
                ///Agregar prestamos
                if(contPtmo < TML){
                    cout << "Digite el Id del cliente: ";
                    cin >> idCli;
                    cli = BuscarCliente(lstCliente, contCli, idCli);
                    if (cli){
                        lstPrestamo[contPtmo] = agregarPrestamo(cli);
                        contPtmo++;
                        cout << "\nEl prestamo se registro con exito\n";
                    }
                    else{
                        cout << "\nEl cliente no existe, no se puede agregar el prestamo";
                    }
                }
                else{
                    cout << "\nLa lista esta llena\n";
                }
                break;

            case 3:
                ///Hacer pagos
                cout << "Digite el Numero del Prestamo: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if(ptmo){
                    registrarPago(ptmo);
                    cout << "\nEl pago se registro con exito\n";
                }
                else{
                    cout << "\nEl prestamo no existe, no se puede registrar el pago";
                }
                break;

            case 4:
                ///Mostrar lista clientes
                if (contCli == 0){
                    cout << "\nLa lista esta vacia\n";
                }
                else{
                    cout << "Id\tNombre\tApellido\n";
                    for (int i=0;i<contCli;i++){
                        cout <<lstCliente[i]->getIdCliente() << "\t";
                        cout <<lstCliente[i]->getNombre() << "\t";
                        cout <<lstCliente[i]->getApellido() << "\n";
                    }
                }
                break;

            case 5:
                ///Mostrar lista prestamos
                if (contPtmo == 0){
                    cout << "La lista esta vacia\n";
                }
                else{
                    cout << "No\tCliente\t\tFecha\t\tMonto\tSaldo\n";
                    for (int i=0;i<contPtmo;i++){
                        cout <<lstPrestamo[i]->getNumeroPrestamo() << "\t";
                        cout <<lstPrestamo[i]->getCliente()->getNombre() << " " << lstPrestamo[i]->getCliente()->getApellido() << "\t";
                        lstPrestamo[i]->getFechaAprobacion()->mostrarFecha(); cout << "\t";
                        cout << "$" << lstPrestamo[i]->getMontoAprobado() << "\t";
                        cout << "$" << lstPrestamo[i]->getSaldoPendiente() <<endl;
                    }
                }
                break;

            case 6:
                ///Mostrar detalles del prestamo
                cout << "Digite el Numero del Prestamo: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if(ptmo){
                    verDetalles(ptmo);
                }
                else{
                    cout << "\nEl prestamo no existe, no se puede visualizar los detalles";
                }
                break;

            case 7:
                ///Salir
                cout << "\nSaliendo del programa\n";
                break;

            default:
                cout << "\nError, opcion no definida\n";
                break;
        }
        system ("pause");
    }while (opc !=7);
    return 0;
}
