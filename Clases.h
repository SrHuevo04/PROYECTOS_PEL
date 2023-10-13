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
    bool operator==(const Libro& l)const{
        return(autor == l.autor && titulo == l.titulo && numero == l.numero);
    }
    void toString(){
        cout<<"Autor: "<<Libro::autor<<
        "Titulo: "<<Libro::titulo<<
        "Fecha de entrega: "<<Libro::fechaEntrega<<
        "Fecha de devolucion: "<<Libro::fechaDevolucion<<
        "Numero: "<<Libro::numero<<endl;
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
    void sacarLibro(Persona persona, Libro l){
        for(int i = 0;i<20;i++){
            if(listaLibros[i] == l){
                listaLibros[i] = Libro();
                for(int j = i;j<puntero;j++){
                    listaLibros[j] = listaLibros[j+1];
                }
                puntero--;
            }
        }
    }

};



#endif //GRUPO1_AC1_CLASES_H
