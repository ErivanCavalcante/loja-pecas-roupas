#ifndef Pecas_H
#define Pecas_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum{

    TIPO_BORRACHA=0,
    TIPO_METAL=1

};

class Pecas
{

    public:
    Pecas();
    virtual ~Pecas();

    string pegaNome();

    virtual void pega_dados();
    virtual void imprime_dados();
    virtual void salvar(ofstream &file);
    virtual void carregar(ifstream &file);

    protected:
    //Variaveis de uma peça
    float diametro;
    string nome;
    int tipo;
 };

#endif // Pecas_H
