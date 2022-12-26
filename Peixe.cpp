#include "Peixe.h"
#include "Aquario.h"

int Peixe::nSerie = 1000;
double obtemRandom(double min, double max);

Peixe::Peixe(string especie, string cor, int peso):especie(especie), cor(cor), peso(peso), numeroSerie(nSerie++){ // construtor do peixe (especie e cor) o peso é sempre 10 no início - depois varia consoante a comida/alimentação
    cout << "Construtor Peixe" << endl;
}
Peixe::Peixe(const Peixe &peixe){      // construtor por cópia
    cout << "Construtor por cópia de Peixe" << endl;

    numeroSerie = nSerie++;
    cor = peixe.cor;
    especie = peixe.especie;
    peso = peixe.peso;
    indigestao = peixe.indigestao;
    numVidas = peixe.numVidas;

}
Peixe::~Peixe(){                        // destrutor
    cout << "Destrutor de peixe" << endl;
}
int Peixe::obtemNumeroSerie() const{           // obtem o número de série de um dado peixe
    return this->numeroSerie;
};

string Peixe::getAsString() const{             // obtem a informação do peixe (nome, cor, peso e número de série)
    ostringstream os;
    os << "---- Informação do Peixe -----" << endl;
    os << "Número de série: " << numeroSerie << endl;
    os << "Espécie: " << especie << endl;
    os << "Cor: " << cor << endl;
    os << "Peso: " << peso << endl;
    os << "---- :: -----" << endl;

    return os.str();
}

void Peixe::come(unsigned int comida){         // função para alimentação do peixe
    double max = 0.5; double min = 0.1;
    double randomvalue = obtemRandom(min, max); // obtem valor aleatório entre 0.0 e 0.5 para gerir vida do peixe
    //Em 50% dos casos o peixe emagrece 50%, não come nada nas 4 vezes seguintes em
    //que o aquário distribuir alimentos e morre na vez seguinte
    if (indigestao) {
        if (numVidas > 0)
            --numVidas;
        return;
    }
    peso += comida;
    if (peso > 50) {
        if (randomvalue < 0.5) {
            // Peixe *peixinho = new Peixe(especie, cor);
            // aquario->adicionaPeixe(peixinho);
            aquario->adicionaPeixe(new Peixe(especie, cor));
            peso = 40;
        }
        else{
            indigestao = true;
            peso /= 2;
        }
    }
};

bool Peixe::isVivo() const{                     // função que permite aumentar ou reduzir a vida do peixe ou gerar um novo
    return (numVidas > 0);
}

bool Peixe::ligaAaquario(Aquario *a){                  // função que permite ligar o aquário e juntar peixes
    if (aquario != nullptr || a == nullptr)            // caso o aquario seja != nullptr ou a = nullptr - sai
        return false;

    aquario = a;
    cout << "----------------- :: liguei o aquario :: ---------------------" << endl;
    return true;
}

bool Peixe::desligaAquario(Aquario *a){                // função que permite desligar um aquário - deixa de ter peixes
    if (aquario != a)
        return false;

    aquario = nullptr;
    return true;
}

bool Peixe::alteraPeso(int g) {                              // função que controla o peso do peixe
    if (g < 0)
        return false;
    peso = g;
    return true;
}

int Peixe::obtemPeso() const {
    return peso;
}

void Peixe::imprime( ostream & os) const{
    os << "---- Informação do Peixe -----" << endl;
    os << "Número de série: " << numeroSerie << endl;
    os << "Espécie: " << especie << endl;
    os << "Cor: " << cor << endl;
    os << "Peso: " << peso << endl;
}
ostream &operator<<(ostream &os, const Peixe &p) {
    //os << p.getAsString();
    p.imprime(os);
    return os;
}