#include "Metal.h"

Metal::Metal() : Pecas()
{
    //ctor
    brilho          = 0;
    condutibilidade = 0;
    tipo            = TIPO_METAL;
}

Metal::~Metal()
{
    //dtor
}

void Metal::pega_dados(){

    Pecas::pega_dados(); // CHAMA A FUNÇÃO O PAI

    cout << "Digite a condutibilidade do produto: \n";
    cin >> condutibilidade;
    cout << "Digite o brilho do produto: \n";
    cin >> brilho;
}

void Metal::imprime_dados(){

    Pecas::imprime_dados();

    cout << "A condutibilidade do produto: " << condutibilidade << endl;
    cout << "O brilho do produto: " << brilho << endl;
}

void Metal::salvar(ofstream &file)
{
    Pecas::salvar(file);

    file << condutibilidade << endl;
    file << brilho << endl;
}
void Metal::carregar(ifstream &file)
{
    Pecas::carregar(file);

    file >> condutibilidade;
    file >> brilho;
}
