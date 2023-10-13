#include <iostream>
#include "Clases.h"
using namespace std;
int main() {
    RegistroBiblio rg = RegistroBiblio();
    Persona Paco = Persona("Paco", 48,"5688896T");
    Persona Ramon = Persona("Ramon",22,"6789876L");
    Persona Loli = Persona("Loli", 56, "439287LM");
    Libro romantico = Libro("Las locuras de Juan","Alberto Aparicio",78965);
    Libro aventura = Libro("El viaje de Pedro", "Pedro Jimenez", 54176);
    Libro terror = Libro("Pesadilla en mi casa", "Maria Suarez", 65539);

    rg.verLibros();
    rg.sacarLibro(Paco,aventura);
    rg.sacarLibro(Ramon,romantico);
    rg.sacarLibro(Loli,terror);
    rg.hasLibro(Paco);
    rg.hasLibro(Ramon);
    rg.hasLibro(Loli);
    rg.devolverLibro(Paco,aventura);
    rg.devolverLibro(Ramon,romantico);
    rg.devolverLibro(Loli, terror);
    rg.verHistorial(Paco);
    rg.verHistorial(Ramon);
    rg.verHistorial(Loli);
    return 0;
}
