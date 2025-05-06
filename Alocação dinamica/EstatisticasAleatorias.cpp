#include <iostream>
#include <cstdlib>  
#include <ctime>   
#include <climits>  
#include <cfloat> 

using namespace std;

int main() {
    double* ptr = nullptr; 
    int numValues = 0;     
    char choice;
    
    srand(static_cast<unsigned int>(time(0)));
    
    do {
        cout << "\nMenu de Controle:\n";
        cout << "1. Gerar valores randômicos\n";
        cout << "2. Exibir estatísticas\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                cout << "Quantos valores deseja gerar? ";
                cin >> numValues;

                if (ptr != nullptr) {
                    free(ptr);
                }

                ptr = (double*)calloc(numValues, sizeof(double));

                if (ptr == nullptr) {
                    cout << "Erro ao alocar memória!" << endl;
                    return 1;
                }

                for (int i = 0; i < numValues; i++) {
                    ptr[i] = (rand() % 10000) / 100.0;
                }

                cout << "Valores gerados com sucesso!" << endl;
                break;
            }

            case '2': {
                if (ptr == nullptr) {
                    cout << "Nenhum valor gerado. Gere valores primeiro!" << endl;
                    break;
                }

                double sum = 0, maxVal = DBL_MIN, minVal = DBL_MAX;

                for (int i = 0; i < numValues; i++) {
                    sum += ptr[i];
                    if (ptr[i] > maxVal) {
                        maxVal = ptr[i];
                    }
                    if (ptr[i] < minVal) {
                        minVal = ptr[i];
                    }
                }

                double average = sum / numValues;

                cout << "\nEstatísticas dos valores gerados:\n";
                cout << "Média: " << average << endl;
                cout << "Somatório: " << sum << endl;
                cout << "Maior valor: " << maxVal << endl;
                cout << "Menor valor: " << minVal << endl;

                break;
            }

            case '3':
                if (ptr != nullptr) {
                    free(ptr);
                }
                cout << "Saindo do programa...\n";
                break;

            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (choice != '3');
    
    return 0;
}
