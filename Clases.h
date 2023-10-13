//
// Created by belen on 12/10/2023.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef GRUPO1_AC1_CLASES_H
#define GRUPO1_AC1_CLASES_H
class Libro{
    /**
     * Clase que representa la entidad de Libro
     */
private:
    /**
     * Atributos de la clase Libro
     * @param autor Persona que escribio el libro
     * @param titulo Titulo del libro
     * @param numero Numero identificativo del libro en la biblioteca
     */
    string autor;
    string titulo;
    int numero;
    bool disponible;

public:
    /**
     * Metodo constructor de libro sin parametrizar
     */
    Libro(){}
    /**
     * Metodo constructor de libro
     * @param a Autor de libro
     * @param t Titulo del libro
     * @param num Numero identificativo del libro
     */
    Libro(string a, string t, int num){
        Libro::autor = a;
        Libro::numero = num;
        Libro::titulo = t;
        Libro::disponible = true;
    }
    /**
     * Metodo que devuelve si un libro esta disponible
     * @return Si el libro está disponible o no
     */
    bool isDisponible() {
        return disponible;
    }
    /**
     * Metodo para establecer si el libro esta disponible
     * @param disponible Si el libro esta disponible o no
     */
    void setDisponible(bool disponible) {
        Libro::disponible = disponible;
    }
    /**
     * Sobreescibimos el operador == para poder comparar objetos de tipo libro
     * @param l Un objeto de tipo libro
     * @return Si son iguales o no
     */
    bool operator==(const Libro& l)const{
        return(autor == l.autor && titulo == l.titulo && numero == l.numero);
    }
    /**
     * Metodo para imprimir por pantalla los atributos principales de libro
     */
    void toString(){
        cout<<"Autor: "<<Libro::autor<<
        "Titulo: "<<Libro::titulo <<
        "Numero: "<<Libro::numero<<endl;
    }
    string getTitulo(){
        return titulo;
    }
};
class Persona{
    /**
     * Clase que representa la entidad de una persona
     */
private:
    /**
     * Atributos de Persona
     * @param nombre Nombre de la persona
     * @param edad Edad de la persona
     * @param dni DNI de la persona
     * @param libro El libro que tiene esa persona
     * @param historial Lista de libros que se ha leido una persona
     */
    string nombre;
    int edad;
    string dni;
    Libro libro;
    vector<Libro> historial;
public:
    /**
     * Metodo constructor de persona
     * @param n Nombre de la persona
     * @param e Edad de la persona
     * @param dni DNI de la persona
     */
    Persona(string n, int e, string dni){
        Persona::nombre = n;
        Persona::edad = e;
        Persona::dni = dni;
        libro = Libro();
    }
    /**
     * Metodo que devuelve el objeto Libro asociado a una persona
     * @return Objeto libro asociado a una persona
     */
    Libro getLibro(){
        return Persona::libro;
    }
    /**
     * Metodo que asigan un libro a una persona
     * @param l Libro que se quiere asociar a una persona
     */
    void setLibro(Libro l){
        Persona::libro=l;
    }
    /**
     * Sobreescribimos el operador == para ver si dos personas son iguales
     * @param p persona a comparar
     * @return Si las personas son iguales
     */
    bool operator==(const Persona& p)const{
        return(nombre == p.nombre && edad == p.edad && dni == p.dni);
    }
    /**
     * Metodo que añade un libro al historial de una persona
     * @param l Libro que se quiere meter en el historial
     */
    void addHistorial(Libro l){
        historial.push_back(l);
    }
    /**
     * Metodo que permite ver los libros del historial
     */
    void verLibros(){
        for (int i = 0; i < historial.size() ; ++i) {
            historial[i].toString();
        }
    };
};
class RegistroBiblio{
    /**
     * Clase que administra la entrada y salida de libros de la biblioteca
     */
private:
    /**
     * Atributos de la clase
     * @param puntero Puntero que apunta al ultimo elemento de la lista de libros
     * @param listaLibros Array de 20 elementos de tipo libro donde se almacenan los libros de la biblioteca
     * @param registrados Vector que contiene a las personas registradas en la biblioteca
     */
    int puntero;
    Libro listaLibros[20];
    vector<Persona> registrados;
public:
    /**
     * Metodo constructor sin parametrizar de RegistroBiblio
     */
    RegistroBiblio(){}
    /**
     * Metodo para registrar nuevos libros en la lista de libros
     * @param libro Libro que se quiere introducir en la lista
     */
    void registrarLibro(Libro libro){
        listaLibros[puntero] = libro;
        puntero++;
    };
    /**
     * Metodo que permite registrar nuevas personas en la lista de registrados
     * @param persona Persona que se quiere registrar en la lista de registrados
     */
    void registrarPersona(Persona persona){
        registrados.push_back(persona);
    }
    /**
     * Metodo para ver los libros disponibles en la biblioteca
     */
    void verLibros(){
        for (int i = 0; i < puntero; i++) {
            listaLibros[i].toString();
        }
    }
    /**
     * Metodo para sacar un libro de la biblioteca y asignarselo a una persona
     * @param persona Persona a la que se le asigna un libro
     * @param l Libro que se quiere asignar
     */
    void sacarLibro(Persona persona, Libro l){
        bool personaEncontrada = false;
        bool libroEncontrado = false;

        for (int i = 0; i < registrados.size() ; ++i) {
            if(registrados[i] == persona){
                personaEncontrada = true;
                for(int z = 0;z<20;z++){
                    if (listaLibros[z] == l) {
                        listaLibros[z] = Libro();
                        libroEncontrado = true;
                        for (int j = z; j < puntero; j++) {
                            persona.setLibro(l);
                            persona.addHistorial(l);
                            l.setDisponible(false);
                            listaLibros[j] = listaLibros[j + 1];
                        }
                        puntero--;
                    }
                }
                if(libroEncontrado == false){
                    cout<<"No se ha encontrado este libro"<<endl;
                }
            }
        }
        if(personaEncontrada == false){
            cout<<"No se ha encontrado esta persona"<<endl;
        }
    }
    /**
     * Metodo que permite ver el historial de una persona
     * @param person Persona de la cual se quiere ver su historial
     */
    void verHistorial(Persona person){
        person.verLibros();
    }
    /**
     * Metodo que permite volver a asignar un libro en la biblioteca y desasignarlo de una persona
     * @param persona Persona que devuelve el libro
     * @param l libro a devolver
     */
    void devolverLibro(Persona persona, Libro l){
        for (int i = 0; i < registrados.size() ; ++i) {
            if(persona == registrados[i]){
                persona.setLibro(Libro());
                registrarLibro(l);
                l.setDisponible(true);
            }
        }
    }
    void hasLibro(Persona persona){
        if(persona.getLibro() == Libro()){
            cout<<"Esta persona no tiene un libro asignado"<<endl;
        }
        else{
            cout<<"Esta persona si tiene un libro asignado"<<endl;
        }
    }
};
#endif //GRUPO1_AC1_CLASES_H
