#include <iostream>
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
            total = aux = 10000;
            aux /= descuento;
            total -= aux;
        }

        if (tipo_suscripcion == "grupal" || tipo_suscripcion == "Grupal" || tipo_suscripcion == "GRUPAL")
        {
            total = aux = 15000;
            aux /= descuento;
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
    void setSalario(float salario)
    {
        this->salario = salario;
    }
    void setHoraT(int hora_t)
    {
        this->hora_t = hora_t;
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
        return 0;
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
        cout << "Tipo de Identificación";
        input >> empleado.tipo_identificacion;
        cout << "Documento: ";
        input >> empleado.documento;
        cout << "Tipo Contrato: ";
        input >> empleado.tipo_contrato;
        cout << "Salario: ";
        input >> empleado.salario;
        cout << "Horas Trabajadas: ";
        input >> empleado.hora_t;
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

    int op, opTemp, i_empleado, i_cliente, intModOp, n_desprendible;
    bool rep;
    string modOp;
    rep = true;
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
        cin >> op;

        switch (op)
        {

        case 1:
            do
            {

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
                        cout << "8. Regresar" << endl;
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
                         << "DESCRIPCION                     |  CANT |    VALOR\n"
                            "Pago de suscripcion "
                         << cliente[op - 1].getTipo_suscripcion()
                         << "  |  1  |  $" << cliente[op - 1].calcularPagosuscripcion() << "COP"
                         << "                                           $"
                         << cliente[op - 1].calcularPagosuscripcion() << "COP \n\n\n"
                         << "VALOR A PAGAR  $" << cliente[op - 1].calcularPagosuscripcion() << "COP\n\n\n"
                         << "            GRACIAS POR TU COMPRA";

                    break;
                case 5:
                    rep = false;
                    break;
                default:
                    break;
                }
                cout << "Cual desea observar: ";
                cin >> op;
                cout << cliente[op - 1];
                system("pause");
                break;
            case 4:
                break;
            case 5:
                rep = false;
                break;
            default:
                break;
            } while (rep == true);
            break;

        case 2:
            do
            {

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
                        cout << "12. Regresar\n"
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
                            cout << "Nuevo Salario: ";
                            cin >> intModOp;
                            empleado[opTemp].setSalario(intModOp);
                            break;
                        case 7:
                            cout << "Horas Trabajadas: ";
                            cin >> intModOp;
                            empleado[opTemp].setSalario(intModOp);
                            break;
                        case 8:
                            cout << "Horas Extra Diurnas: ";
                            cin >> intModOp;
                            empleado[opTemp].setHorasExtraD(intModOp);
                            break;
                        case 9:
                            cout << "Horas Extra Nocturnas: ";
                            cin >> intModOp;
                            empleado[opTemp].setHorasExtraN(intModOp);
                            break;
                        case 10:
                            cout << "Horas Extra Dominicales Diurnas: ";
                            cin >> intModOp;
                            empleado[opTemp].setHorasExtraDomD(intModOp);
                            break;
                        case 11:
                            cout << "Horas Extra Dominicales Nocturnas: ";
                            cin >> intModOp;
                            empleado[opTemp].setHorasExtraDomN(intModOp);
                            break;
                        case 12:
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
                    cout << "\t\tDESPRENDIBLE DE NÓMINA\n\n"
                         << "Aunar Villavicencio\t\t DESPRENDIBLE\t" << n_desprendible;
                    break;
                case 5:
                    rep = false;
                    break;
                default:
                    break;
                }
            } while (rep == true);
            rep = true;
            break;

        case 3:
            rep = false;
            break;
        }
    } while (rep == true);
    return 0;
}
