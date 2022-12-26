#include <iostream>
#include <vector>
using namespace std;

#ifndef FT6_1_AQUARIO_H
#define FT6_1_AQUARIO_H

class Peixe;

class Aquario {
public:
    Aquario();
    Aquario(const Aquario & obj);
    ~Aquario();                                      // destrutor
    bool adicionaPeixe(Peixe * peixe);               // adiciona um novo peixe ao aquário
    bool peixeExiste(unsigned int numSerie) const;            // verifica se o peixe existe dado o número de série
    void alimentaPeixes(unsigned int dose);          // alimentar os peixes todos - um a um
    Peixe *removePeixe(unsigned int numSerie);       // remove um peixe dado o numSerie
    bool removePeixeComido(unsigned int numSerie);       // remove um peixe dado o numSerie
    Peixe *obtemPeixe(unsigned int numSerie) const;                 // obtém um ponteiro para um peixe que não pode ser alterado
    void limpaAquario();                             // limpa do aquário os peixes que entretanto morreram
    // void imprime();
    string getAsString() const;                      // obtém uma string com a informação (aquário/peixe)
    int peixeNoAquario() const;                      // função que permite saber o número total de peixes no aquário
    Peixe *obtemPeixeComer(unsigned int pos);        // função que devolve o peixe para comer
    int obtemID(unsigned int id);
    Aquario &operator=(const Aquario &);
private:
    vector<Peixe*> peixes;
};

ostream &operator<<(ostream &os, const Aquario &p);

#endif //FT6_1_AQUARIO_H
