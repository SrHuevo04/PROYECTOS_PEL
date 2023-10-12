//
// Created by belen on 12/10/2023.
//
#include <string>
#include <vector>
using namespace std;

#ifndef GRUPO1_AC1_CLASES_H
#define GRUPO1_AC1_CLASES_H
class Libro{
private:
    string autor;
    string titulo;
    int fechaEntrega;
    int fechaDevolucion;
    int numero;
    bool disponible;

public:
    Libro(){}
    Libro(string a, string t, int num){
        Libro::autor = a;
        Libro::numero = num;
        Libro::titulo = t;
        Libro::disponible = true;
    }

    int getFechaEntrega() {
        return fechaEntrega;
    }

    void setFechaEntrega(int fechaEntrega) {
        Libro::fechaEntrega = fechaEntrega;
    }

    int getFechaDevolucion()  {
        return fechaDevolucion;
    }

    void setFechaDevolucion(int fechaDevolucion) {
        Libro::fechaDevolucion = fechaDevolucion;
    }

    bool isDisponible() {
        return disponible;
    }

    void setDisponible(bool disponible) {
        Libro::disponible = disponible;
    }
};
class Persona{
private:
    string nombre;
    int edad;
    string dni;
    Libro libro;
    vector<Libro> historial;
public:
    Persona(string n, int e, string dni){
        Persona::nombre = n;
        Persona::edad = e;
        Persona::dni = dni;
    }
    Libro getLibro(){
        return Persona::libro;
    }
    void setLibro(Libro l){
        Persona::libro=l;
    }

};

class Persona{
private:
    string nombre;
    int edad;
    string dni;
    Libro libro;
    vector<Libro> historial;
public:
    Persona(string n, int e, string dni){
        Persona::nombre = n;
        Persona::edad = e;
        Persona::dni = dni;
    }
    Libro getLibro(){
        return libro;
    }
    void setLibro(Libro libro) {
        Persona::libro = libro;
    }
};

class RegistroBiblio{
private:
    int puntero;
    Libro listaLibros[20];
    vector<Persona> registrados;
public:
    RegistroBiblio(){}

    void registrarLibro(Libro libro){
        listaLibros[puntero] = libro;
        puntero++;
    };
    void registrarPersona(Persona persona){
        registrados.push_back(persona);
    }
    void verLibros(){
        for (int i = 0; i < puntero; i++) {
            listaLibros[i].toString();
        }
    }
    bool buscarLibro(Libro l){
        for(int i = 0;i<20;i++){
            bool encontrado = false;
            int sumar = 0;
            if(listaLibros[sumar] == l){
                return true;
                sumar++;
            }
        }
    }
    void sacarLibro(Persona persona, Libro libro){

    }

};



#endif //GRUPO1_AC1_CLASES_H
