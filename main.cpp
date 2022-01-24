#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Persona
{
protected:
    string nombre, apellido, tipo_identificacion;
    int documento;

public:
    Persona()
    {
        nombre = " ";
        apellido = " ";
        tipo_identificacion = " ";
        documento = 0;
    }
    Persona(string nombre, string apellido, string tipo_identificacion, int documento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->tipo_identificacion = tipo_identificacion;
        this->documento = documento;
    }
    string getNombre()
    {
        return nombre;
    }
    string getApellido()
    {
        return apellido;
    }
    string getTipo_identificacion()
    {
        return tipo_identificacion;
    }
    int getDocumento()
    {
        return documento;
    }
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    void setApellido(string apellido)
    {
        this->apellido = apellido;
    }
    void setTipo_identificacion(string tipo_identificacion)
    {
        this->tipo_identificacion = tipo_identificacion;
    }
    void setDocumento(int documento)
    {
        this->documento = documento;
    }
    friend ostream &operator<<(ostream &output, Persona &persona)
    {
        output << "Nombre: " << persona.getNombre() << endl;
        output << "Apellido: " << persona.getApellido() << endl;
        output << "Documento tipo: " << persona.getTipo_identificacion() << endl;
        output << "Numero de documento: " << persona.getDocumento() << endl;
        return output;
    }
};

class Cliente : public Persona
{
protected:
    string direccion, tipo_suscripcion;
    int descuento;

public:
    Cliente() : Persona()
    {
        direccion = " ";
        tipo_suscripcion = " ";
        descuento = 0;
    }
    Cliente(string nombre, string apellido, string tipo_identificacion, int documento, string direccion,
            string tipo_suscripcion, int descuento)
            : Persona(nombre, apellido, tipo_identificacion, documento)
    {
        this->direccion = direccion;
        this->tipo_suscripcion = tipo_suscripcion;
        this->descuento = descuento;
    }
    string getDireccion()
    {
        return direccion;
    }
    string getTipo_suscripcion()
    {
        return tipo_suscripcion;
    }
    int getDescuento()
    {
        return descuento;
    }
    void setDireccion(string direccion)
    {
        this->direccion = direccion;
    }
    void setTipo_suscripcion(string tipo_suscripcion)
    {
        this->tipo_suscripcion = tipo_suscripcion;
    }
    void setDescuento(int descuento)
    {
        this->descuento = descuento;
    }
    float calcularPagosuscripcion()
    {
        float aux = 0;
        float total;
        if (tipo_suscripcion == "personal" || tipo_suscripcion == "Personal" || tipo_suscripcion == "PERSONAL")
        {
            total = 10000;
            aux = total * descuento / 100;
            total -= aux;
        }

        if (tipo_suscripcion == "grupal" || tipo_suscripcion == "Grupal" || tipo_suscripcion == "GRUPAL")
        {
            total = 15000;
            aux = total * descuento / 100;
            total -= aux;
        }

        if (tipo_suscripcion == "empresarial" || tipo_suscripcion == "Empresarial" || tipo_suscripcion == "EMPRESARIAL")
        {
            total = 25000;
            aux = total * descuento / 100;
            total -= aux;
        }

        return total;
    }

    friend ostream &operator<<(ostream &output, Cliente &cliente)
    {
        output << "1. Nombre: " << cliente.getNombre() << endl;
        output << "2. Apellido: " << cliente.getApellido() << endl;
        output << "3. Documento tipo " << cliente.getTipo_identificacion() << endl;
        output << "4. Numero de documento: " << cliente.getDocumento() << endl;
        output << "5. Direccion: " << cliente.getDireccion() << endl;
        output << "6. Tipo de suscripcion: " << cliente.getTipo_suscripcion() << endl;
        output << "7. Descuento aplicado: " << cliente.getDescuento() << "%" << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Cliente &cliente)
    {
        cout << "Nombre: ";
        input >> cliente.nombre;
        cout << "Apellido: ";
        input >> cliente.apellido;
        cout << "Tipo de documento (C.C, T.I, C.I): ";
        input >> cliente.tipo_identificacion;
        cout << "Numero de documento: ";
        input >> cliente.documento;
        cout << "Direccion: ";
        cin.ignore();
        getline(input, cliente.direccion);
        cout << "Tipo de suscripcion (Personal, Grupal, Empreasarial): ";
        input >> cliente.tipo_suscripcion;
        cout << "Descuento aplicado: ";
        input >> cliente.descuento;

        return input;
    }
};

class Empleado : public Persona
{
protected:
    string tipo_contrato;
    float salario;
    int hora_t, horas_extra_d, horas_extra_n, horas_extra_dom_d, horas_extra_dom_n;

public:
    Empleado() : Persona()
    {
        tipo_contrato = "";
        salario = hora_t = horas_extra_d = horas_extra_n = horas_extra_dom_d = horas_extra_dom_n = 0;
    }
    Empleado(string nombre, string apellido, string tipo_identificacion, int documento, string tipo_contrato, float salario, int hora_t, int horas_extra_d, int horas_extra_n, int horas_extra_dom_d, int horas_extra_dom_n) : Persona(nombre, apellido, tipo_identificacion, documento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->tipo_identificacion = tipo_identificacion;
        this->documento = documento;
        this->tipo_contrato = tipo_contrato;
        this->salario = salario;
        this->hora_t = hora_t;
        this->horas_extra_d = horas_extra_d;
        this->horas_extra_n = horas_extra_n;
        this->horas_extra_dom_d = horas_extra_dom_d;
        this->horas_extra_dom_n = horas_extra_dom_n;
    }
    string getTipoContrato()
    {
        return tipo_contrato;
    }
    float getSalario()
    {
        return salario;
    }
    int getHoraT()
    {
        return hora_t;
    }
    int getHorasExtraD()
    {
        return horas_extra_d;
    }
    int getHorasExtraN()
    {
        return horas_extra_n;
    }
    int getHorasExtraDomD()
    {
        return horas_extra_dom_d;
    }
    int getHorasExtraDomN()
    {
        return horas_extra_dom_n;
    }
    void setTipoContrato(string tipo_contrato)
    {
        this->tipo_contrato = tipo_contrato;
    }
    void setHorasExtraD(int horas_extra_d)
    {
        this->horas_extra_d = horas_extra_d;
    }
    void setHorasExtraN(int horas_extra_n)
    {
        this->horas_extra_n = horas_extra_n;
    }
    void setHorasExtraDomN(int horas_extra_dom_n)
    {
        this->horas_extra_dom_n = horas_extra_dom_n;
    }
    void setHorasExtraDomD(int horas_extra_dom_d)
    {
        this->horas_extra_dom_d = horas_extra_dom_d;
    }
    float calcularSalario()
    {
        int hora_o = 4166.67;
        if (tipo_contrato == "TC" || tipo_contrato == "tc")
        {
            hora_t = 240;
        }
        else if (tipo_contrato == "TP" || tipo_contrato == "tp")
        {
            hora_t = 120;
        }
        salario = hora_t * hora_o;
        salario += (hora_o * 1.25) * horas_extra_d;
        salario += (hora_o * 1.75) * horas_extra_n;
        salario += (hora_o * 2) * horas_extra_dom_d;
        salario += (hora_o * 2.5) * horas_extra_dom_n;
        return salario;
    }
    friend ostream &operator<<(ostream &output, Empleado &empleado)
    {

        output << "1. Nombre: " << empleado.getNombre() << endl;
        output << "2. Apellido: " << empleado.getApellido() << endl;
        output << "3. Tipo de Identificación: " << empleado.getTipo_identificacion() << endl;
        output << "4. Documento: " << empleado.getDocumento() << endl;
        output << "5. Tipo de Contrato: " << empleado.getTipoContrato() << endl;
        output << "6. Salario: " << empleado.getSalario() << endl;
        output << "7. Horas Trabajadas: " << empleado.getHoraT() << endl;
        output << "8. Horas Extra Diurnas: " << empleado.getHorasExtraD() << endl;
        output << "9. Horas Extra Nocturnas: " << empleado.getHorasExtraN() << endl;
        output << "10. Horas Extra Dominicales Diurnas: " << empleado.getHorasExtraDomD() << endl;
        output << "11. Horas Extra Dominicales Nocturnas: " << empleado.getHorasExtraDomN() << endl
               << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Empleado &empleado)
    {
        cout << "Nombre: ";
        input >> empleado.nombre;
        cout << "Apellido: ";
        input >> empleado.apellido;
        cout << "Tipo de Identificación(C.C, T.I, C.I): ";
        input >> empleado.tipo_identificacion;
        cout << "Documento: ";
        input >> empleado.documento;
        cout << "Tipo Contrato: Tiempo Completo (TC) - Tiempo Parcial (TP): ";
        input >> empleado.tipo_contrato;
        cout << "Horas Extra Diurnas: ";
        input >> empleado.horas_extra_d;
        cout << "Horas Extra Nocturnas: ";
        input >> empleado.horas_extra_n;
        cout << "Horas Extra Dominicales Diurnas: ";
        input >> empleado.horas_extra_dom_d;
        cout << "Horas Extra Dominicales Nocturnas: ";
        input >> empleado.horas_extra_dom_n;
        return input;
    }
};

int main()
{
    Cliente cliente[2];
    Empleado empleado[2];

    int op, opTemp, i_empleado, i_cliente, intModOp, opPersona;
    bool rep;
    string modOp;
    float floatModOp, hora_o;
    rep = true;
    hora_o = 4166.67;
    i_cliente = i_empleado = 0;
    do
    {
        cout << "################################################\n"
                "###   Sistema de planificacion de recursos   ###\n"
                "################################################\n \n"
                "Menu: \n"
                "1. Clientes \n"
                "2. Empleados \n"
                "3. Salir \n \n"
                "Que desea realizar? \n"
                ">>  ";
        cin >> opPersona;

        do
        {
            switch (opPersona)
            {

                case 1:

                    cout << "################################################\n"
                            "###   Sistema de planificacion de recursos   ###\n"
                            "################################################\n \n"
                            "Gestion de clientes \n"
                            "Menu: \n"
                            "1. Crear clientes \n"
                            "2. Modificar clientes \n"
                            "3. Ver clientes \n"
                            "4. Generar facturas \n"
                            "5. Regresar \n \n"
                            "Que desea realizar? \n"
                            ">>  ";
                    cin >> op;

                    switch (op)
                    {

                        case 1:

                            while (i_cliente < 2)
                            {
                                cin >> cliente[i_cliente];
                                i_cliente++;
                                break;
                            }
                            break;

                        case 2:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> opTemp;
                            opTemp--;
                            do
                            {
                                cout << cliente[opTemp];
                                cout << "8. Eliminar datos\n"
                                        "9. Regresar \n";
                                cout << ">> ";
                                cin >> op;
                                switch (op)
                                {

                                    case 1:
                                        cout << "Ingerese nuevo nombre: ";
                                        cin >> modOp;
                                        cliente[opTemp].setNombre(modOp);
                                        break;

                                    case 2:
                                        cout << "Ingerese nuevo apellido: ";
                                        cin >> modOp;
                                        cliente[opTemp].setApellido(modOp);
                                        break;

                                    case 3:
                                        cout << "Ingerese nuevo tipo de documento (C.C, C.I T.I): ";
                                        cin >> modOp;
                                        cliente[opTemp].setTipo_identificacion(modOp);
                                        break;

                                    case 4:
                                        cout << "Ingerese nuevo documento: ";
                                        cin >> intModOp;
                                        cliente[opTemp].setDocumento(intModOp);
                                        break;

                                    case 5:
                                        cout << "Ingerese nueva direccion: ";
                                        cin.ignore();
                                        getline(cin, modOp);
                                        cliente[opTemp].setDireccion(modOp);
                                        break;

                                    case 6:
                                        cout << "Ingerese nuevo tipo de suscripcion (Personal, Grupal, Empresarial: ";
                                        cin >> modOp;
                                        cliente[opTemp].setTipo_suscripcion(modOp);
                                        break;

                                    case 7:
                                        cout << "Ingerese nuevo descuento: ";
                                        cin >> intModOp;
                                        cliente[opTemp].setDescuento(intModOp);
                                        break;

                                    case 8:
                                        cliente[opTemp]=Cliente();
                                        i_cliente=opTemp;
                                        rep = false;
                                        break;

                                    case 9:
                                        rep = false;
                                        break;

                                    default:
                                        break;
                                }
                            } while (rep == true);
                            rep = true;
                            break;

                        case 3:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> op;
                            cout << cliente[op - 1];
                            system("pause");
                            break;

                        case 4:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> op;
                            cout << "Villavicencio                     Factrura  #00" << op << endl;
                            cout << "Km via Acacias, anillo vial \n"
                                    "(8) 6823030 / Cel: 3103689660 \n"
                                    "-----------------------------------------------------\n\n"
                                    "FACTURA A \n"
                                 << cliente[op - 1].getNombre() << " " << cliente[op - 1].getApellido() << "\n"
                                 << cliente[op - 1].getTipo_identificacion() << ": " << cliente[op - 1].getDocumento()
                                 << "\n"
                                 << "Direccion: " << cliente[op - 1].getDireccion() << "\n \n \n"
                                 << "DESCRIPCION                 |  CANT |   VALOR\n"
                                    "Pago de suscripcion "
                                 << cliente[op - 1].getTipo_suscripcion()
                                 << " |   1   |  $" << cliente[op - 1].calcularPagosuscripcion() << " COP\n"
                                 << "                            TOTAL     $"
                                 << cliente[op - 1].calcularPagosuscripcion() << " COP \n\n\n"
                                 << "VALOR A PAGAR  $" << cliente[op - 1].calcularPagosuscripcion() << " COP\n\n"
                                 << "            GRACIAS POR TU COMPRA\n"
                                    "    Feliz mes te desea la familia unillanos\n\n";
                            system("pause");
                            break;
                        case 5:
                            rep = false;
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:

                    cout << "################################################\n"
                            "###   Sistema de planificacion de recursos   ###\n"
                            "################################################\n \n"
                            "Gestion de Empleados \n"
                            "Menu: \n"
                            "1. Crear empleados \n"
                            "2. Modificar empleados \n"
                            "3. Ver empleados \n"
                            "4. Generar recibos de nómina \n"
                            "5. Regresar \n \n"
                            "¿Que desea realizar? \n"
                            ">> ";
                    cin >> op;
                    switch (op)
                    {
                        case 1:
                            while (i_empleado < 2)
                            {
                                cin >> empleado[i_empleado];
                                i_empleado++;
                                break;
                            }
                            break;
                        case 2:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << empleado[i].getNombre() << endl;
                            }
                            cout << ">> ";
                            cin >> opTemp;
                            opTemp -= 1;
                            do
                            {
                                cout << empleado[opTemp];
                                cout << "12. Eliminar datos\n"
                                        "13. Regresar\n"
                                     << ">> ";
                                cin >> op;
                                switch (op)
                                {
                                    case 1:
                                        cout << "Nuevo Nombre: ";
                                        cin >> modOp;
                                        empleado[opTemp].setNombre(modOp);
                                        break;
                                    case 2:
                                        cout << "Nuevo Apellido: ";
                                        cin >> modOp;
                                        empleado[opTemp].setApellido(modOp);
                                        break;
                                    case 3:
                                        cout << "Nuevo Tipo de Identificación: ";
                                        cin >> modOp;
                                        empleado[opTemp].setTipo_identificacion(modOp);
                                        break;
                                    case 4:
                                        cout << "Nuevo Número de Documento: ";
                                        cin >> intModOp;
                                        empleado[opTemp].setDocumento(intModOp);
                                        break;
                                    case 5:
                                        cout << "Nuevo Tipo de Contrato: ";
                                        cin >> modOp;
                                        empleado[opTemp].setTipoContrato(modOp);
                                        break;
                                    case 6:
                                        cout << "Horas Extra Diurnas: ";
                                        cin >> intModOp;
                                        empleado[opTemp].setHorasExtraD(intModOp);
                                        break;
                                    case 7:
                                        cout << "Horas Extra Nocturnas: ";
                                        cin >> intModOp;
                                        empleado[opTemp].setHorasExtraN(intModOp);
                                        break;
                                    case 8:
                                        cout << "Horas Extra Dominicales Diurnas: ";
                                        cin >> intModOp;
                                        empleado[opTemp].setHorasExtraDomD(intModOp);
                                        break;
                                    case 9:
                                        cout << "Horas Extra Dominicales Nocturnas: ";
                                        cin >> intModOp;
                                        empleado[opTemp].setHorasExtraDomN(intModOp);
                                        break;
                                    case 10:
                                        empleado[opTemp]=Empleado();
                                        i_empleado=opTemp;
                                        rep = false;
                                        break;
                                    case 11:
                                        rep = false;
                                        break;
                                    default:
                                        break;
                                }
                            } while (rep == true);
                            rep = true;
                            break;
                        case 3:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << empleado[i].getNombre() << endl;
                            }
                            cout << ">> ";
                            cin >> op;
                            cout << empleado[op - 1];
                            system("read -p 'Presiona Enter... ' var");
                            break;
                        case 4:
                            system("clear");
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << empleado[i].getNombre() << endl;
                            }
                            cout << ">> ";
                            cin >> op;
                            op -= 1;
                            floatModOp = empleado[op].calcularSalario();
                            cout << "\t\tDESPRENDIBLE DE PAGO\n\n"
                                 << "Aunar Villavicencio\t\t DESPRENDIBLE\t #0001\n"
                                 << "\t\t\t\t FECHA\t 27/11/2019\n\n"
                                 << "Km1 Vía Acacías, Anillo Vial\n"
                                 << "Villavicencio, Meta\n"
                                 << "(8) 6823030 / Cel: 3103689660\n"
                                 << "--------------------------------------------------------\n\n"
                                 << "SALARIO\t\t" << empleado[op].getSalario() << "\n"
                                 << "TIPO CONTRATO\t" << empleado[op].getTipoContrato() << "\n"
                                 << empleado[op].getNombre() << "\n"
                                 << empleado[op].getTipo_identificacion() << " " << empleado[op].getDocumento() << "\n\n"
                                 << setw(10) << "DESCRIPCIÓN" << setw(20) << "|" << setw(10) << "CANT" << setw(5) << "|" << setw(10) << "VALOR\n"
                                 << setw(10) << "Pago nómina" << setw(20) << "|" << setw(10) << empleado[op].getHoraT() << setw(5) << "|" << setw(4) << "$" << fixed << setprecision(1) << hora_o * empleado[op].getHoraT() << "COP\n"
                                 << setw(10) << "Horas extras diurnas" << setw(11) << "|" << setw(10) << empleado[op].getHorasExtraD() << setw(5) << "|" << setw(5) << "$" << (hora_o * 1.25) * empleado[op].getHorasExtraD() << "COP\n"
                                 << setw(10) << "Horas extras nocturnas" << setw(9) << "|" << setw(10) << empleado[op].getHorasExtraN() << setw(5) << "|" << setw(5) << "$" << (hora_o * 1.75) * empleado[op].getHorasExtraN() << "COP\n"
                                 << setw(10) << "Horas extras dirunas dom" << setw(7) << "|" << setw(10) << empleado[op].getHorasExtraDomD() << setw(5) << "|" << setw(5) << "$" << (hora_o * 2) * empleado[op].getHorasExtraDomD() << "COP\n"
                                 << setw(10) << "Horas extras nocturnas dom" << setw(5) << "|" << setw(10) << empleado[op].getHorasExtraDomN() << setw(5) << "|" << setw(5) << "$" << (hora_o * 2.5) * empleado[op].getHorasExtraDomN() << "COP\n\n"
                                 << setw(41) << "TOTAL" << setw(5) << "|" << setw(10) << "$" << floatModOp << "COP\n\n\n"
                                 << "VALOR A PAGAR: $" << floatModOp << " COP\n\n"
                                 << "\t Gracias por trabajar con nosotros\n"
                                 << "\tFeliz Año te desea la familia AUNAR\n\n"
                                 << "--------------------------------------------------------\n\n";
                            break;
                        case 5:
                            rep = false;
                            break;
                        default:
                            break;
                    }
                    break;
                case 3:
                    rep = false;
                    break;
                default:
                    break;
            }
        } while (rep == true);
    } while (rep == true);
    return 0;
}