#include "Borracha.h"

Borracha::Borracha() : Pecas()
{
    maleabilidade = 0;
    cor           = "";
    tipo          = TIPO_BORRACHA;
}

Borracha::~Borracha()
{
    //dtor
}

float Borracha::pega_maleabilidade()
{
    return maleabilidade;
}

string Borracha::pega_cor()
{
    return cor;
}

void Borracha::pega_dados()
{

    Pecas::pega_dados(); // CHAMA A FUNÇÃO O PAI

    cout << "Digite o quanto a borracha eh maleavel \n";
    cin >> maleabilidade;
    cout << "Digite a cor da sua borracha \n";
    cin >> cor;
}

void Borracha::imprime_dados()
{
    Pecas::imprime_dados();

    cout << "Maleabilidade da borracha: " << maleabilidade << endl;
    cout << "Cor da borracha: " << cor << endl;

}
void Borracha::salvar(ofstream &file)
{
    Pecas::salvar(file);

    file << maleabilidade << endl;
    file << cor << endl;
}
void Borracha::carregar(ifstream &file)
{
    Pecas::carregar(file);

    file >> maleabilidade;
    file >> cor;
}
