#ifndef BORRACHA_H
#define BORRACHA_H
#include "Pecas.h"
#include <string>

using namespace std;

class Borracha : public Pecas
{

    public:
        Borracha();
        virtual ~Borracha();

        float pega_maleabilidade();
        string pega_cor();

        void pega_dados();
        void imprime_dados();
        void salvar(ofstream &file);
        void carregar(ifstream &file);

    private:
        float maleabilidade;
        string cor;
};

#endif // BORRACHA_H
