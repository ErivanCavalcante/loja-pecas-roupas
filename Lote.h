#ifndef LOTE_H
#define LOTE_H

#include <iostream>
#include <vector>
#include <string>
#include "Variaveis.h"
#include "Borracha.h"
#include "Metal.h"

using namespace std;

class Lote
{
    public:
    Lote();
    virtual ~Lote();

    string pegaTempo();
    uInt pegaSerie();
    uInt pegaQtdPecas();

    void setaTempo( string t );
    void setaSerie( uInt i );
    //void setaQtdPPecas( uInt q );

    bool adicionarPeca( Pecas *p );
    bool removerPeca( Pecas *p );
    Pecas* procurarPeca( uInt i );

    void pegaDadosLote();
    void imprime_os_dados();
    void listar_as_pecas();

    void salvar(ofstream &file);
    void carregar(ifstream &file);


    string tempo;
    uInt serie;

    protected:

    //Lista de pecas desse lote
    vector< Pecas* > lista_pecas;
};

#endif // LOTE_H
