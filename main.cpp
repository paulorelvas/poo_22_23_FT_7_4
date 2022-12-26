#include <iostream>
#include <random>

#include "Aquario.h"
#include "Peixe.h"
#include "Carpa.h"
#include "Tubarao.h"

using namespace std;

double obtemRandom(double min, double max){
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int obtemRandomInt(int min, int max){
    int range = (max - min);
    int div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {

    cout << "---- Ficha 7.4 -----" << endl;
    Aquario *aq1 = new Aquario();
    Peixe *px1 = new Peixe {"peixe Verde", "laranja"};
    Peixe *px2 = new Carpa {"peixe branco", "verde"};
    Peixe *px3 = new Tubarao{"peixe azul", "azul"};
    Peixe *px4 = new Peixe{"peixe dourado", "prata"};

    cout << "-----BEGIN:: cout << peixe1 << peixe2 <<..." << endl;
    cout << *px1 << *px3 << *px2;
    cout << "-----END:: cout << peixe1 << peixe2 <<..." << endl;

    aq1->adicionaPeixe(px1);
    aq1->adicionaPeixe(px2);
    aq1->adicionaPeixe(px3);
    // cout << px3->obtemNumeroSerie() << endl;

    cout << "---- *aq1 -----" << endl;
    cout << *aq1 << endl;

    Peixe *px_temp = new Peixe(*px3);
    cout << "---- *aq1::*px_temp(*px3)::construtor por cópia -----" << endl;
    cout << *aq1 << endl;

    aq1->alimentaPeixes(1);
    cout << *aq1 << endl;


    int id = aq1->obtemID(1002);
    cout << id << endl;

    delete aq1;
    delete px1;
    delete px2;
    delete px3;
    delete px4;

    return 0;

}
