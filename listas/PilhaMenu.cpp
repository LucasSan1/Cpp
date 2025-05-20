#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct nopilha pilha;

struct nopilha {
    int valor;
    pilha *ant;
};

pilha *topo = NULL;

// Insere elementos na pilha
void push(int valor) {
    pilha *newpilha = (pilha *) malloc(sizeof(pilha));
    if (newpilha == NULL) {
        cout << "Erro: falha na alocação de memória.\n";
        return;
    }
    newpilha->valor = valor;
    newpilha->ant = topo;
    topo = newpilha;
}

// Remove elementos da pilha
void pop() {
    if (topo == NULL) {
        cout << "A pilha já está vazia.\n";
        return;
    }
    pilha *temp = topo;
    topo = temp->ant;
    free(temp);
    cout << "Elemento removido do topo da pilha.\n";
}

// Exibe os elementos da pilha
void exibirpilha() {
    if (topo == NULL) {
        cout << "A pilha está vazia.\n";
        return;
    }

    pilha *temp = topo;
    cout << "Elementos da pilha:\n";
    while (temp != NULL) {
        cout << temp->valor << endl;
        temp = temp->ant;
    }
}

// Exclui a pilha inteira
void destrutor() {
    pilha *temp;
    while (topo != NULL) {
        temp = topo;
        topo = temp->ant;
        free(temp);
    }
    cout << "A pilha foi destruída!\n";
}

int main() {
    int opcao, valor;

    do {
        cout << "\n===== MENU PILHA (LIFO) =====\n";
        cout << "1 - Inserir (push)\n";
        cout << "2 - Remover (pop)\n";
        cout << "3 - Exibir pilha\n";
        cout << "4 - Destruir pilha\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                exibirpilha();
                break;
            case 4:
                destrutor();
                break;
            case 0:
                destrutor();
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }

        cout << "Pressione ENTER para continuar...";
        cin.ignore();
        cin.get();

    } while(opcao != 0);

    return 0;
}
