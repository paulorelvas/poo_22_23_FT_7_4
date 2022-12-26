#ifndef FT7_4_TUBARAO_H
#define FT7_4_TUBARAO_H
#include "Peixe.h"

class Tubarao:public Peixe {
public:
    Tubarao(string especie, string cor, int peso=3);  // deve ter 15 quando é criado --- o valor 5 força o teste na comida
    Tubarao(const Tubarao & obj);
    ~Tubarao() override;

    void come(unsigned int q) override;
    string getAsString() const override;
    void imprime(ostream & saida) const override;

};
ostream &operator<<(ostream &, const Tubarao &);

#endif //FT7_4_TUBARAO_H
