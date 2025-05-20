#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define TAM_NOME 100


typedef struct pessoa {
    char nome[TAM_NOME];
    float salario;
    struct pessoa *ant;
} pessoa;

pessoa *topo = NULL;

// Empilhar pessoa
void push(const char* nome, float salario) {
    pessoa *nova = (pessoa *) malloc(sizeof(pessoa));
    if (nova == NULL) {
        cout << "Erro ao alocar memória.\n";
        return;
    }

    strncpy(nova->nome, nome, TAM_NOME);
    nova->nome[TAM_NOME - 1] = '\0';
    nova->salario = salario;
    nova->ant = topo;
    topo = nova;

    cout << "Pessoa empilhada com sucesso!\n";
}

// Desempilhar pessoa
void pop() {
    if (topo == NULL) {
        cout << "A pilha está vazia.\n";
        return;
    }

    pessoa *temp = topo;
    topo = temp->ant;

    cout << "Removido: " << temp->nome << " | R$ " << temp->salario << endl;

    free(temp);
}

// Exibir pilha
void exibir() {
    if (topo == NULL) {
        cout << "A pilha está vazia.\n";
        return;
    }

    pessoa *temp = topo;
    cout << "\n--- PILHA DE PESSOAS ---\n";
    while (temp != NULL) {
        cout << "Nome: " << temp->nome << " | Salário: R$ " << temp->salario << endl;
        temp = temp->ant;
    }
}

// Destruir pilha
void destruir() {
    pessoa *temp;
    while (topo != NULL) {
        temp = topo;
        topo = temp->ant;
        free(temp);
    }
    cout << "Pilha destruída com sucesso!\n";
}

int main() {
    int opcao;
    char nome[TAM_NOME];
    float salario;

    do {
        cout << "\n===== MENU PILHA DE PESSOAS =====\n";
        cout << "1 - Empilhar pessoa\n";
        cout << "2 - Desempilhar\n";
        cout << "3 - Exibir pilha\n";
        cout << "4 - Destruir pilha\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1:
                cout << "Digite o nome: ";
                cin.getline(nome, TAM_NOME);
                cout << "Digite o salário: R$ ";
                cin >> salario;
                cin.ignore();
                push(nome, salario);
                break;

            case 2:
                pop();
                break;

            case 3:
                exibir();
                break;

            case 4:
                destruir();
                break;

            case 0:
                destruir();
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opção inválida!\n";
        }

        cout << "Pressione ENTER para continuar...";
        cin.get();

    } while(opcao != 0);

    return 0;
}
