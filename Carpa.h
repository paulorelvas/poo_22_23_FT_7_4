
#ifndef FT7_4_CARPA_H
#define FT7_4_CARPA_H

#include "Peixe.h"
/**
*Carpa: acrescente ao seu peso os gramas de comida que lhe é dada. Se o seu peso
exceder 50, divide-se em dois, ficando o original com 20 gramas, e passando a existir no
aquário um novo peixinho com as mesmas características (mesma cor etc. mas com um
número de série diferente). As carpas têm sempre o nome de espécie “carpa” e têm
inicialmente o peso 5
*/

class Carpa:public Peixe {
public:
    Carpa(string especie, string cor, int peso=5);
    Carpa(const Carpa &obj);

    ~Carpa() override;
    void come(unsigned int dose) override;
    string getAsString() const override;
    void imprime(ostream & saida) const override;
};

ostream &operator<<(ostream &, const Carpa &);


#endif //FT7_4_CARPA_H
