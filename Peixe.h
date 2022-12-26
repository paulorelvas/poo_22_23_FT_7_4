#include<iostream>
#include<sstream>

using namespace std;

#ifndef FT6_1_PEIXE_H
#define FT6_1_PEIXE_H

#include "Aquario.h"

class Peixe{
public:
    Peixe(string especie, string cor, int peso=10); // construtor do peixe (especie e cor) o peso é sempre 10 no início - depois varia consoante a comida/alimentação
    Peixe(const Peixe &peixe);                      // construtor por cópia
    virtual ~Peixe();                               // destrutor

    int obtemNumeroSerie() const;                   // obtem o número de série de um dado peixe
    int obtemPeso() const;                          // função que devolve o peso do peixinho
    bool isVivo() const;                            // função que recalcula o ciclo/estado de vida do peixe
    bool ligaAaquario(Aquario *a);                  // função que permite ligar o aquário e juntar peixes
    bool desligaAquario(Aquario *a);                // função que permite desligar um aquário - deixa de ter peixes

    virtual void come(unsigned int comida);         // função para alimentação do peixe
    virtual string getAsString() const;             // obtem a informação do peixe (nome, cor, peso e número de série)
    virtual void imprime(ostream & saida) const;    // imprime info do peixe - igual ao getAsstring - usado para testes - não é necessário - apagar

protected:
    bool alteraPeso(int g);                         // função que controla o peso do peixe
    string especie;                                 // espécie do peixe
    string cor{"cinzento"};                      // cor do peixe - por omissão é cinzento
    int peso;                                       // peso do peixe
    Aquario * aquario = nullptr;                    // variável que permite associar peixes ao aquário

private:
    unsigned int numVidas = 4;                      // tempo de vida do peixe até morrer (alimentação)
    bool indigestao = false;                        // variáveil usada para controlar o estado do peixe ao ser alimentado - vive - morre
    int numeroSerie;                                // número de série do peixe - inicia em 1000
    static int nSerie;                              // contador de peixes - usado em conjugação com o número de série do peixe
};
ostream &operator<<(ostream &, const Peixe &);
#endif //FT6_1_PEIXE_H
