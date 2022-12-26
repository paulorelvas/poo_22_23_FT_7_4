
#include "Tubarao.h"

int obtemRandomInt(int min, int max);

Tubarao::Tubarao(string especie, string cor, int peso):
        Peixe(especie+"_Tubarao", cor, peso) {}

Tubarao::~Tubarao() {
    cout << "A destruir tubarão" << endl;
}

void Tubarao::come(unsigned int comida){         // função para alimentação do tubarão
    cout << "Tubarão vai comer...." << endl;
/**
 * Tubarão: ignora a comida que lhe é dada. Se tiver mais do que 20 gramas, diminui um
    grama de peso. Se tiver menos de 20 gramas procura um outro peixe qualquer e come-o,
    acrescentando ao seu peso o peso do peixe ingerido. Se não houver nenhum peixe para
    comer e já tiver menos de 20 gramas, diminui o seu peso em 2 gramas. Se tiver menos de
    5 gramas morre. Tem sempre o nome de espécie “Tubarão” e o peso inicial de 15.
 */

    if (peso > 20) {
        peso--;
    }else{
        // procura um peixe (pode ser com base no ID e come-o --- passa a pesar o peso)
        if(aquario->peixeNoAquario() > 1){ // existem peixes no aquario
            cout << "Peixes no aquario... " << aquario->peixeNoAquario() << endl;

            // o tubarão não se pode comer a si próprio---- restrição
            Peixe *tmp = aquario->obtemPeixe( aquario->obtemID(this->obtemNumeroSerie()) );
            cout << "NSERIE: " << (*tmp).obtemNumeroSerie() << endl;
            if(tmp != nullptr) {
                peso += tmp->obtemPeso();
                aquario->removePeixeComido((*tmp).obtemNumeroSerie());
            }
        }else if(peso < 5){
            aquario->adicionaPeixe(new Tubarao(especie+"_tubarão", cor));
            aquario->removePeixe(this->obtemNumeroSerie());
        }else{
            peso-=2;
        }
    }
}

string Tubarao::getAsString() const{             // obtem a informação do peixe (nome, cor, peso e número de série)
    ostringstream os;
    os << "---- Informação do Peixe -----" << endl;
    os << Peixe::getAsString();
    os << "---- Espécie::Tubarão -----" << endl;
    os << "---- :: -----" << endl;

    return os.str();
}

void Tubarao::imprime( ostream & os) const{
    Peixe::imprime(os);
    os << "---- Espécie::Tubarão -----" << endl;
}

ostream &operator<<(ostream &os, const Tubarao &p) {
    p.imprime(os);
    return os;
}

