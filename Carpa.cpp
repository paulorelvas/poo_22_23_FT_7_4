
#include "Carpa.h"

Carpa::Carpa(string especie, string cor, int peso):
        Peixe(especie+"_Carpa", cor, peso) {}

Carpa::~Carpa() {
    cout << "A destruir carpa\n";
};

void Carpa::come(unsigned int comida){         // função para alimentação do peixe
    /**
    *Carpa: acrescente ao seu peso os gramas de comida que lhe é dada. Se o seu peso
    exceder 50, divide-se em dois, ficando o original com 20 gramas, e passando a existir no
    aquário um novo peixinho com as mesmas características (mesma cor etc. mas com um
    número de série diferente). As carpas têm sempre o nome de espécie “carpa” e têm
    inicialmente o peso 5
    */

    peso += comida;
    if (peso > 50) {
        aquario->adicionaPeixe(new Carpa("Carpa", cor));
        peso = 20;
    }
};

string Carpa::getAsString() const{             // obtem a informação do peixe (nome, cor, peso e número de série)
    ostringstream os;
    os << "---- Informação do Peixe -----" << endl;
    os << Peixe::getAsString();
    os << "---- Espécie::Carpa -----" << endl;
    os << "---- :: -----" << endl;

    return os.str();
}

void Carpa::imprime( ostream & os) const{
    Peixe::imprime(os);
    os << "---- Espécie::Carpa -----" << endl;
}

ostream &operator<<(ostream &os, const Carpa &p) {
    p.imprime(os);
    return os;
}
