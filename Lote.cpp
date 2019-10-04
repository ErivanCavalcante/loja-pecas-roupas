#include "Lote.h"

Lote::Lote()
{
    tempo     = "";
    serie     = 0;
}

Lote::~Lote()
{
    if( lista_pecas.empty() )
        return;

    for( Pecas *p : lista_pecas )
    {
        delete p;
        p = 0;
    }

    lista_pecas.clear();
}

string Lote::pegaTempo()
{
    return tempo;
}

uInt Lote::pegaSerie()
{
    return serie;
}

uInt Lote::pegaQtdPecas()
{
    return lista_pecas.size();
}

void Lote::setaTempo( string t )
{
    tempo = t;
}

void Lote::setaSerie( uInt i )
{
    serie = i;
}

void Lote::pegaDadosLote()
{
    cout << "Digite a data de entrada do lote" << endl;
    cin >> tempo;

    cout << "Digite o numero de serie do lote" << endl;
    cin >> serie;
}

bool Lote::adicionarPeca(Pecas* p)
{
    //Testa se o ponteiro eh valido
    if( p == 0 )
        return false;


    lista_pecas.push_back( p );


    return true;
}

bool Lote::removerPeca(Pecas* p)
{
    //Testa se o ponteiro eh valido
    if( p == 0 )
        return false;

    for( uInt i = 0 ; i < lista_pecas.size() ; ++i )
    {
        if ( p == lista_pecas[i] )
        {
            delete lista_pecas[ i ];
            lista_pecas.erase( lista_pecas.begin() + i );
            return true;
        }
    }

    return false;

}

Pecas* Lote::procurarPeca( uInt i )
{        //Procura uma peça

    if ( i > lista_pecas.size() )
    {          //Se o parametro de entrada for maior que a lista, adeus.
        cout << "Esta errado!\n" << endl;
        return 0;
    }

    return lista_pecas[i];                   // Se não, irá retornar a posição da lista
}

void Lote::imprime_os_dados()
{
    cout << "Serie : " << serie << endl;
    cout << "Tempo : " << tempo << endl;

    cout << endl;

    for( Pecas *p : lista_pecas )
    {
        p->imprime_dados();
        cout << "-------------------------------" << endl;
    }
}

void Lote::listar_as_pecas()
{
    cout << endl;

    for( unsigned int i = 0; i < lista_pecas.size(); ++i )
    {
        cout << i << ") " << lista_pecas[i]->pegaNome() << endl;
    }

}
void Lote::salvar(ofstream &file)
{
    file << tempo << endl;
    file << serie << endl;

    file << lista_pecas.size() << endl;

    for( Pecas *p : lista_pecas )
    {
        p->salvar(file);
    }

}
void Lote::carregar(ifstream &file)
{
    int tamanho_lotes = 0, tipo;

    file >> tempo;
    file >> serie;

    file >> tamanho_lotes;

    for( int i = 0; i < tamanho_lotes; ++i )
    {
        file >> tipo;

        if ( tipo == TIPO_BORRACHA )
        {
            Borracha *var_pega_dados = new Borracha;

            var_pega_dados->carregar(file);
            adicionarPeca(var_pega_dados);
        }
        else
        {
            Metal *var_pega_dados = new Metal;

            var_pega_dados->carregar(file);
            adicionarPeca(var_pega_dados);
        }
    }
}
