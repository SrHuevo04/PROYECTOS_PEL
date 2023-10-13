#include <iostream>
#include "Clases.h"
using namespace std;
void menu(){
    RegistroBiblio rg = RegistroBiblio();
    int eleccion = 0;
    cout<<"Buenos dias, ¿que quiere hacer?"<<endl;
    cout<<"1. Añadir persona"<<endl;
    cout<<"2. Crear libros"<<endl;
    cout<<"3. Sacar libro"<<endl;
    cout<<"4. Devolver libro"<<endl;
    cout<<"5. Ver historial de la persona"<<endl;
    cout<<"6. Ver libros disponibles"<<endl;
    cout<<"7. Ver si la persona tiene un libro"<<endl;
    cin>>eleccion;
    string nombre;
    int edad;
    string dni;
    string autor;
    string titulo;
    int nIdentificativo;
    switch(eleccion){
        case 1:
            cout <<"Introduce el nombre de la persona: "<<endl;
            cin >>nombre;
            cout << "Introduce tu edad";
            cin >>edad;
            cout<< "Introduce tu DNI";
            cin  >> dni;
            Persona p = Persona(nombre,edad,dni);
            rg.registrarPersona(p);
            break;
        case 2:
            cout<< "Introduce el autor del libro";
            cin>> autor;
            cout<< "Introduce el titulo del libro";
            cin>> titulo;
            cout<< "Introduce el numero identificativo del libro";
            cin>> nIdentificativo;
            Libro l = Libro(autor,titulo,nIdentificativo);
            rg.registrarLibro(l);
            break;
        case 3:
            cout <<"Introduce el nombre de la persona: "<<endl;
            cin >>nombre;
            cout << "Introduce tu edad";
            cin >>edad;
            cout<< "Introduce tu DNI";
            cin >>dni;
            Persona per = Persona(nombre,edad,dni);
            cout<< "Introduce el autor del libro: ";
            cin>> autor;
            cout<< "Introduce el titulo del libro: ";
            cin>> titulo;
            cout<< "Introduce el numero identificativo del libro: ";
            cin>> nIdentificativo;
            Libro li = Libro(autor,titulo,nIdentificativo);
            rg.sacarLibro(per,li);
            cout<<"Libro "<< l.getTitulo() <<"disponible?"<<l.isDisponible()<<endl;
            break;
        case 4:
            cout <<"Introduce el nombre de la persona: "<<endl;
            cin >>nombre;
            cout << "Introduce tu edad";
            cin >>edad;
            cout<< "Introduce tu DNI";
            cin >>dni;
            Persona perso = Persona(nombre,edad,dni);
            cout<< "Introduce el autor del libro: ";
            cin>> autor;
            cout<< "Introduce el titulo del libro: ";
            cin>> titulo;
            cout<< "Introduce el numero identificativo del libro: ";
            cin>> nIdentificativo;
            Libro lib = Libro(autor,titulo,nIdentificativo);
            rg.devolverLibro(perso,lib);
            break;
        case 5:
            cout <<"Introduce el nombre de la persona: "<<endl;
            cin >>nombre;
            cout << "Introduce la edad de la persona";
            cin >>edad;
            cout<< "Introduce el DNI de la persona";
            cin >>dni;
            Persona pers = Persona(nombre,edad, dni);
            rg.verHistorial(p);
            break;
        case 6:
            rg.verLibros();
            break;
        case 7:
            cout <<"Introduce el nombre de la persona: "<<endl;
            cin >>nombre;
            cout << "Introduce la edad de la persona";
            cin >>edad;
            cout<< "Introduce el DNI de la persona";
            cin >>dni;
            Persona person = Persona(nombre,edad, dni);
            rg.hasLibro(person);
            break;
        default:
            cout<<"Opcion erronea"<<endl;
            break;
    }
}
int main() {
    menu();
    return 0;
}
