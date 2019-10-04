#include <iostream>
#include <cstdlib>
#include "Pecas.h"
#include "Produtos.h"

using namespace std;

int main( int argc, char **argv )
{
    //Cria o objeto que gerencia as peças
    Produtos *ag = new Produtos;

    //Pega o retorno do cin
    int ret;

    //Controla o loop do programa
    bool sair = false;

    while( !sair )
    {
        cout << "-------- Loja de Pecas --------" << endl;
        cout << "O que voce deseja fazer ?\n1 - Adicionar Lote\n2 - Adicionar Pecas\n3 - Remover Lote"<<
        "\n4 - Remover peca dentro do lote\n5 - Listar os lotes\n6 - Listar as pecas dentro do lote\n7 - Sair\n" << endl;

        //Pega a opção digitada
        cin >> ret;

        //Trata cada opção
        switch( ret )
        {

            case 1:     //Opção adicionar Lote
            {
                //Limpa a tela
                system ( "cls" );

                //Cria um objeto peca para receber as informaçoes
                Lote *pe = new Lote;

                //Pega as informações e coloca no objeto pe

                pe->pegaDadosLote();

                //Adiciona a peca na lista
                ag->adiciona( pe );
                break;
            }
            case 2:
            {
                cout << "Digite o lote em qual deseja adicionar:" << endl;
                //Lista todos os lotes do sistema
                ag->listar_lotes();

                //Pega a opcao digitada
                cin >> ret;
                //Pega o lote do sistema
                Lote *novo_lote = ag->procurar(ret);

                if( novo_lote == NULL )
                {
                    cout << "Nao ha valor. Retorne e digite um valor valido!" << endl;
                    break;
                }

                cout << "Digite o tipo de peca que voce deseja criar: " << endl;
                cout << "1) Metal \n2) Borracha" << endl;

                cin >> ret;

                if( ret == 1 )
                {
                    Metal *nome_metal = new Metal;

                    nome_metal->pega_dados();
                    novo_lote->adicionarPeca(nome_metal);
                }
                else if( ret == 2 )
                {
                    Borracha *nome_borracha = new Borracha;

                    nome_borracha->pega_dados();
                    novo_lote->adicionarPeca(nome_borracha);
                }
                else
                {
                    cout << "Opcao do tipo errada." << endl;
                    break;
                }

                //Salva o estado do sistema
                ag->salvar();
                break;
            }
            case 3:     //Opção para remover Lote
            {
                //Limpa a tela
                system ( "cls" );

                //Lista todas as peças no sistema
                ag->listar_lotes();

                cout << "Qual desses voce deseja remover ? "<< endl;

                cin >> ret;

                //Remove a peça do sistema e destroi
                ag->remover( ag->procurar( ret ) );

                ag->salvar();
                break;
            }
            case 4:     //Opção remover peças
            {
                //Limpa a tela
                system ( "cls" );

                cout << "Escolha o lote da peca que voce deseja apagar: "<<endl;

                //Lista todos os lotes
                ag->listar_lotes();

                cin >> ret;

                Lote *novo_lote = ag->procurar(ret);
                if( novo_lote == 0 )
                {
                    cout << "Opcao errada" << endl;
                    break;
                }

                cout << "Escolha qual peca que voce deseja apagar: "<< endl;

                novo_lote->listar_as_pecas();
                cin >> ret;

                //Procura a peca no sistema
                Pecas *apt_vetor = novo_lote->procurarPeca(ret);

                if( apt_vetor == NULL )
                {
                    cout << "Nao ha valor. Retorne e digite um valor valido!" << endl;
                    break;
                }

                novo_lote->removerPeca(apt_vetor);

                ag->salvar();
                break;
            }
            case 5:
                //Limpa a tela
                system ( "cls" );

                cout << "Lista dos lotes: "<<endl;

                ag->listar_lotes();
                break;

            case 6:
            {
                //Limpa a tela
                system ( "cls" );

                cout << "Escolha o lote da peca que voce deseja listar: " << endl;

                ag->listar_lotes();

                cin >> ret;
                Lote *novo_lote = ag->procurar(ret);

                if( novo_lote == 0 )
                {
                    cout << "Lote nao existe." << endl;
                    break;
                }

                cout << "Lista das Pecas: "<< endl;

                novo_lote->imprime_os_dados();

                break;
            }
            case 7:
                //Termina o loop e acaba o programa
                sair = true;
                break;
            default:    //Digitou o parametro errado
                cout << "Tente novamente!" << endl;
                break;
        }
    }

    delete ag;

    //Retorna sucesso
    return 0;
}
