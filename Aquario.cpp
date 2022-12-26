#include "Aquario.h"
#include "Peixe.h"

int obtemRandomInt(int min, int max);


Aquario::Aquario(){}
Aquario::Aquario(const Aquario & obj){
    int contador = 0;
    cout << endl << "--- construtor por cópia Aquário---" << endl;

    auto it = obj.peixes.begin();
    while (it < obj.peixes.end()) {
        //(**it).imprime();
        //Livro * tmp = new Livro(**it);
        if(this->adicionaPeixe(new Peixe(**it)))
            contador++;
        ++it;
    }
    if(contador == obj.peixes.size())
        cout << endl << "Foram copiados todos os peixes para o novo aquário..." << peixes.size() <<  endl;
}
Aquario::~Aquario(){
    for (auto p : peixes)
        delete p;
    peixes.clear();
}
bool Aquario::adicionaPeixe(Peixe * peixe) {        // adiciona um novo peixe ao aquário
    cout << "Adiciona Peixe" << endl;
    if (peixe == nullptr)
        return false;

    Peixe * tmp = peixe;

    if (tmp->ligaAaquario(this) == false)
        return false;

    peixes.push_back(tmp);

    return true;
}
bool Aquario::peixeExiste(unsigned int numSerie) const{            // verifica se o peixe existe com base no número de série
    for(auto el: peixes){
        if(el->obtemNumeroSerie() == numSerie)
            return true;
        //el->imprime();
    }
    //cout << "Peixe exists?" << endl;
    return false;
}
void Aquario::alimentaPeixes(unsigned int dose) {    // alimentar os peixes todos - um a um
    cout << "Alimenta peixe" << endl;

    for(auto i = 0; i < peixes.size(); i++) {
        peixes[i]->come(dose);
    }

    /* // alternativa
   for(auto el: peixes)
       el->come(dose);
   */
}

void Aquario::limpaAquario(){
    auto it = peixes.begin();
    while(it < peixes.end()) {
        if ((*it)->isVivo()) {
            ++it;
        } else {
            delete (*it);
            it = peixes.erase(it);
        }
    }
}

Peixe *Aquario::removePeixe(unsigned int n) {
    auto it = peixes.begin();
    //while (it < peixes.end()) {
    while (it != peixes.end()) {
        if((*it)->obtemNumeroSerie() == n) {
            Peixe *out = *it;

            if ((*it)->desligaAquario(this) == false)
                return nullptr;

            peixes.erase(it);
            return out;
        }
        ++it;
    }
    return nullptr;
}

bool Aquario::removePeixeComido(unsigned int n) {
    cout << "Vou remover um peixe..." << endl;
    auto it = peixes.begin();
    //while (it < peixes.end()) {
    while (it != peixes.end()) {
        if((*it)->obtemNumeroSerie() == n) {
            //Peixe *out = *it;
            cout << "vou remover o peixe com NSerie: " << (*it)->obtemNumeroSerie()<< endl;
            if ((*it)->desligaAquario(this) == true) {
                peixes.erase(it);
                return true;
            }
        }
        ++it;
    }
    return false;
}
int Aquario::obtemID(unsigned int id){
    cout << "A Obter ID diferente de....: " << id << endl;
    int min = 1;
    int randomvalue = obtemRandomInt(min, peixes.size());

    if(peixes.size() == 0)  // usar o empty()
        return -1;
    else if(peixes[randomvalue-1]->obtemNumeroSerie() != id) {
        return peixes[randomvalue-1]->obtemNumeroSerie();
    }else{
        for (auto it: peixes){
            if( (*it).obtemNumeroSerie() != id)
                return (*it).obtemNumeroSerie();
        }
    }
    return -1;
}

Peixe *Aquario::obtemPeixe(unsigned int numSerie) const{
    auto it = peixes.begin();
    //while (it < peixes.end()) {
    while (it != peixes.end()) {
        if((*it)->obtemNumeroSerie() == numSerie) {
            Peixe *out = *it;
                return *it;
        }
        ++it;
    }
    return nullptr;
}

// eventualmente usada para o tubarão comer um peixe quando sabe qual a posição no vetor - pode não ser necessária
Peixe *Aquario::obtemPeixeComer(unsigned int pos) {
    // função que devolve o peixe para comer
    Peixe * tmp = peixes[pos];

    if(tmp != nullptr)
        return tmp;
    return nullptr;
}

int Aquario::peixeNoAquario() const{
    return peixes.size();
}

string Aquario::getAsString() const {
    ostringstream os;

    if (peixes.size() == 0)
        os << "---Aquário vazio---";
    else {
        os << "--- Peixes no aquário --- " << endl;
        for (auto *p: peixes)
            os << p->getAsString() << endl;
    }
    return  os.str();
}

/*
void Aquario::imprime(){
    cout << "Total de peixes: " << totalPeixes << endl;
    for(auto &el:peixes)
        el->imprime();
}*/

ostream &operator<<(ostream &os, const Aquario &p) {
    os << p.getAsString();
    return os;
}

Aquario &Aquario::operator=(const Aquario &obj){
    cout << "----- OPERATOR= ------ " << endl;
    if(this == &obj)
        return *this;

    if(obj.peixes.size() == 0)    // se a origem estiver vazia devolve a origem
        return *this;

    cout << "Total de Peixes no aquário: " << this->peixes.size() << endl;
    if( this->peixes.size() > 0 ) { // se não estiver vazio -- prepara o aquário para receber uma cópia dos peixes que se pretende copiar
        cout << "--- Entrei em modo destrói peixe --- operador= ---" << endl;
        this->peixes.clear();
    }

    auto it = obj.peixes.begin();
    while (it < obj.peixes.end()) {
        if(this->adicionaPeixe(new Peixe(**it))){}
        ++it;
    }

    return *this;
}

