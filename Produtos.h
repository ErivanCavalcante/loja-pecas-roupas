#ifndef Produtos_H
#define Produtos_H

#include <vector>
#include <fstream>
#include "Lote.h"

using namespace std;

class Produtos
{
    public:

    Produtos();
    virtual ~Produtos();

    //Adiciona uma peça ao sistema
    bool adiciona( Lote *p  );

    //Remove uma peça do sistema
    bool remover( Lote *p );

    //Lista todas as pecas do sistema
    void listar_lotes();

    //Procura uma peça com o id dado
    Lote* procurar( unsigned int i );

    //Salvar no arquivo
    bool salvar();

    //Carrega do arquivo
    bool carregar();


    private:

    //Lista com todas as peças ativas
    vector < Lote* > listar_lote_var;

};

#endif // Produtos_H
