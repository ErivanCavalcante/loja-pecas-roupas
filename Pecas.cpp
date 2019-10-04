#include "Pecas.h"

Pecas::Pecas()
{
    diametro  = 0 ;
    nome      = "zero";
    tipo      = -1;
}

Pecas::~Pecas()
{
}

string Pecas::pegaNome()
{
    return nome;
}

 void Pecas::pega_dados()
 {
     cout << "Digite o nome do produto: " << endl;
     cin >> nome;
     cout << "Digite o diametro do produto: " << endl;
     cin >> diametro;
}


void Pecas::imprime_dados()
{
    cout << "Nome: " << nome << endl;
    cout << "Diametro: " << diametro << endl;
}

void Pecas::salvar(ofstream &file)
{
    //Primeira coisa a ser salva eh o tipo
    file << tipo << endl;

    file << nome << endl;
    file << diametro << endl;

}

void Pecas::carregar(ifstream &file)
{
    file >> nome;
    file >> diametro;
}
