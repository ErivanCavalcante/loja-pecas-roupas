#ifndef METAL_H
#define METAL_H

#include "Pecas.h"

class Metal: public Pecas
{

    public:
        Metal();
        virtual ~Metal();

        void pega_dados();
        void imprime_dados();

        void salvar(ofstream &file);
        void carregar(ifstream &file);

    private:
        float condutibilidade;
        float brilho;
};

#endif // METAL_H
