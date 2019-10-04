#include "Produtos.h"
#include <iostream>

using namespace std;

Produtos::Produtos()
{                   //Construtor de Produtos
    if ( carregar() == false )
    {
        cout << "Erro: nada foi encontrado ao carregar o arquivo" << endl;
        return ;
    }
}

Produtos::~Produtos()
{                  //Destrutor de Produtos

    if ( listar_lote_var.size() == 0 )
    {
        return ;
    }

    for( unsigned int i = 0 ; i < listar_lote_var.size() ; ++i )
    {
        delete listar_lote_var[i];
    }

    listar_lote_var.clear();
}

bool Produtos::adiciona(Lote* p)
{      //Adiciona uma peça

     if( p == 0 )
     {
        return false;
     }

     listar_lote_var.push_back(p);

     if ( salvar() == false )
     {
        cout << "Erro: não podemos salvar o seu arquivo" << endl;
        return false ;
     }

     return true;
}

bool Produtos::remover(Lote* p)
{       //Remover as peças
    if( p == 0 )
    {
        return false;
    }

    for( unsigned int i = 0 ; i < listar_lote_var.size() ; ++i )
    {
        if ( p == listar_lote_var[i] )
        {
            delete listar_lote_var[i];
            listar_lote_var.erase(listar_lote_var.begin()+i);
            return true;
        }
    }

    return false;
}

Lote* Produtos::procurar( unsigned int i )
{       //Para procurar as peças

    if ( i > listar_lote_var.size() )
    {
        cout<< "Esta errado!\n"<< endl;
        return 0;
    }

    return listar_lote_var[i];

}

void Produtos::listar_lotes()
{          //Para listar peças

    for( unsigned int i = 0 ; i < listar_lote_var.size() ; ++i )
    {
        cout << i << ") " << " " << listar_lote_var[i]->pegaSerie() << " " << listar_lote_var[i]->pegaTempo() << endl;
    }
}

bool Produtos::salvar()
{                //Salvar arquivo
    ofstream file( "Lojas_Pecas.cper" );

    if( file.is_open( ) )
    {
        file << listar_lote_var.size() << endl;     //Ele vai pegar o valor do tamanho da lista e salvar no arquivo

        for( Lote* p : listar_lote_var )
        {
            p->salvar(file);
        }
    }
    else
        return false;

    file.close();

    return true;
}

bool Produtos::carregar()
{              //Carregar arquivo
    ifstream file( "Lojas_Pecas.cper" );                      //Criamos uma variavel para acessar o arquivo

    if( file.is_open( ) )
    {
        int lol = 0;                      //Carregar o contador (mostra quantas peças existem na lista)
        file >> lol;

        for( int i = 0 ; i < lol ; ++i )
        {
            Lote *p = new Lote();      //Criando um novo objeto da classe Peças

            p->carregar(file);

            listar_lote_var.push_back( p );
        }
    }
    else
        return false;

    file.close();

    return true;                     //Fechar o programa
}

