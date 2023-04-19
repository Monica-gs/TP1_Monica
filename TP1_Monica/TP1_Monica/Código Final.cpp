#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

void BubbleSortMelhorado(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC); 
void ShellSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC);
void SelectionSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC);
void InsertSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC);
void QuickSort(vector<int> &vetor, int inicio, int fim, long long int &numT, long long int &numC);
void MergeSort(vector<int> &vetor, int inicio, int fim, long long int &numT, long long int &numC); 
void ImprimiVetor(vector<int> vetor, int tamanho);

void BubbleSortMelhoradoDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC);
void ShellSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC);
void SelectionSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC);
void InsertSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC);
void QuickSortDicionario(vector<string> &vetor, int inicio, int fim, long long int &numT, long long int &numC);
void MergeSortDicionario(vector<string> &vetor, int inicio, int fim, long long int &numT, long long int &numC); 
void ImprimiVetorDicionario(vector<string> vetor, int tamanho);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);\
    ifstream arqEntrada; 
    ofstream arqSaida; 
    char proximo[1000];
    vector<int> vetor;
    int* arr = vetor.data();
    int tamanho, metodo, inst;
    long long int numT, numC;
    clock_t t;
    string EntradaArq;
    string SaidaArq;
    string NomeMetodo;

    bool verifica = false;
    vector<string> instancias;
    string elemento; 

    setlocale(LC_ALL, "Portuguese_Brasil");
    menuInst:
    cout << "          Escolha uma Instância?                 " << endl;
    cout << "_________________________________________________" << endl;
    cout << "|                                               |" << endl;
    cout << "|                  Menu                         |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "|  1 - Lista Aleatoria de 1k                    |" << endl;
    cout << "|  2 - Lista Aleatoria de 10k                   |" << endl;
    cout << "|  3 - Lista Aleatoria de 100k                  |" << endl;
    cout << "|  4 - ListaInversamenteOrdenada de 1k          |" << endl;
    cout << "|  5 - ListaInversamenteOrdenada de 10k         |" << endl;
    cout << "|  6 - ListaInversamenteOrdenada de 100k        |" << endl;
    cout << "|  7 - Lista Quase Ordenada de 1k               |" << endl;
    cout << "|  8 - Lista Quase Ordenada de 10k              |" << endl;
    cout << "|  9 - Lista Quase Ordenada de 100k             |" << endl;
    cout << "|  10 - Lista Ordenada de 1k                    |" << endl;
    cout << "|  11 - Lista Ordenada de 10k                   |" << endl;
    cout << "|  12 - Lista Ordenada de 100k                  |" << endl;
    cout << "|  13 - Lista Aleatoria de 1M                   |" << endl;
    cout << "|  14 - Lista Quase Ordenada de 1M              |" << endl;
    cout << "|  15 - Lista Inversamente Ordenada de 1M       |" << endl;
    cout << "|  16 - Lista Ordenada de 1M                    |" << endl;
    cout << "|  17 - Dicionario Aleatorio-29855              |" << endl;
    cout << "|  18 - Dicionario Ordenado-29855               |" << endl;
    cout << "|  19 - Dicionario Inversamente Ordenadoo-29855 |" << endl;
    cout << "|  20 - Dicionario Aleatorio-261791             |" << endl;
    cout << "|  21 - Dicionario Ordenado-261791              |" << endl;
    cout << "|  22 - Dicionario Inversamente Ordenadoo-261791|" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite o número correspondete a instância?" << endl;
    cin >> inst;
    switch (inst) {
    case 1:
        EntradaArq = "../ListaAleatoria-1000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 2:
        EntradaArq = "../ListaAleatoria-10000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 3:
        EntradaArq = "../ListaAleatoria-100000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 4:
        EntradaArq = "../ListaInversamenteOrdenada-1000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 5:
        EntradaArq = "../ListaInversamenteOrdenada-10000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 6:
        EntradaArq = "../ListaInversamenteOrdenada-100000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 7:
        EntradaArq = "../ListaQuaseOrdenada-1000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 8:
        EntradaArq = "../ListaQuaseOrdenada-10000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 9:
        EntradaArq = "../ListaQuaseOrdenada-100000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 10:
        EntradaArq = "../ListaOrdenada-1000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 11:
        EntradaArq = "../ListaOrdenada-10000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 12:
        EntradaArq = "../ListaOrdenada-100000.txt";
        SaidaArq =  "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 13: 
        EntradaArq = "../ListaAleatoria-1000000.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 14: 
        EntradaArq = "../ListaQuaseOrdenada-1000000.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 15:
        EntradaArq = "../ListaInversamenteOrdenada-1000000.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 16:
        EntradaArq = "../ListaOrdenada-1000000.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        goto menu;
    case 17:
        EntradaArq = "../DicionarioAleatorio-29855.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;
    case 18:
        EntradaArq = "../DicionarioOrdenado-29855.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;
    case 19:
        EntradaArq = "../DicionarioInversamenteOrdenadoo-29855.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;
    case 20:
        EntradaArq = "../DicionarioAleatorio-261791.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;
    case 21:
        EntradaArq = "../DicionarioOrdenado-261791.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;
    case 22:
        EntradaArq = "../DicionarioInversamenteOrdenadoo-261791.txt";
        SaidaArq = "Saida_" + EntradaArq;
        arqSaida.open(SaidaArq);
        verifica = true;
        goto menu;

    default :
    system("cls");
    goto menuInst;
    } 
    menu:
    vetor.clear();
    tamanho = 0;
    metodo = 0;
    numC = 0;
    numT = 0;

    if (verifica) {
      arqEntrada.open(EntradaArq);
      if (!arqEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
      }  
      while (arqEntrada >> elemento ) {
        instancias.push_back(elemento);
      } arqEntrada.close();
    } 
    
    else {
            arqEntrada.open(EntradaArq);
    if (arqEntrada.fail()) {
        cout << "Falha ao abrir o arquivo." << endl;
        exit(1);
    }
    do {
        arqEntrada.getline(proximo, 10000);
        tamanho = atoi(proximo);
        vetor.push_back(tamanho);
    } while (!arqEntrada.eof());
    arqEntrada.close();
    
    }

    cout << "     Escolha uma metodo de Ordenação?                " << endl;
    cout << "_____________________________________________________" << endl;
    cout << "|                                                   |" << endl;
    cout << "|                  Menu                             |" << endl;
    cout << "|___________________________________________________|" << endl;
    cout << "|  1 - Metodo Bubble Sort Melhorado                 |" << endl;
    cout << "|  2 - Metodo Shell Sort                            |" << endl;
    cout << "|  3 - Metodo Selection Sort                        |" << endl;
    cout << "|  4 - Metodo Insertion Sort                        |" << endl;
    cout << "|  5 - Metodo Quick Sort                            |" << endl;
    cout << "|  6 - Metodo Marge Sort                            |" << endl;
    cout << "|  7 - Metodo Bubble Sort Melhorado Para Dicionário |" << endl;
    cout << "|  8 - Metodo Shell Sort Para Dicionário            |" << endl;
    cout << "|  9 - Metodo Selection Sort Para Dicionário        |" << endl;
    cout << "|  10 - Metodo Insertion Sort Para Dicionário       |" << endl;
    cout << "|  11 - Metodo Quick Sort Para Dicionário           |" << endl;
    cout << "|  12 - Metodo Marge Sort Para Dicionário           |" << endl;
    cout << "|  13 - Trocar Instância                            |" << endl;
    cout << "|  14 - Para finalizar o programa                   |" << endl;
    cout << "|___________________________________________________|" << endl;
    cin >> metodo;
    switch (metodo) {
    case 1:
        NomeMetodo = "Buble Sort Melhorado";
        t = clock();
        BubbleSortMelhorado(vetor, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 2:
        NomeMetodo = "Shell Sort";
        t = clock();
        ShellSort(vetor, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 3:
        NomeMetodo = "Selection Sort";
        t = clock();
        SelectionSort(vetor, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 4:
        NomeMetodo = "Insert Sort";
        t = clock();
        InsertSort(vetor, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 5:
        NomeMetodo = "Quick Sort";
        t = clock();
        QuickSort(vetor, 0, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 6:
        NomeMetodo = "Merge Sort";
        t = clock();
        MergeSort(vetor, 0, vetor.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetor(vetor, vetor.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 7:
        NomeMetodo = "Bubble Sort";
        t = clock();
        BubbleSortMelhoradoDicionario(instancias, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 8: 
        NomeMetodo = "Shell Sort";
        t = clock();
        ShellSortDicionario(instancias, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 9: 
        NomeMetodo = "Selection Sort";
        t = clock();
        SelectionSortDicionario(instancias, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " <<NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 10:
        NomeMetodo = "Insertion Sort";
        t = clock();
        InsertSortDicionario(instancias, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 11:
        NomeMetodo = "Quick Sort";
        t = clock();
        QuickSortDicionario(instancias, 0, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 12:  
        NomeMetodo = "Merge Sort";
        t = clock();
        MergeSortDicionario(instancias, 0, instancias.size(), numT, numC);
        t = clock() - t;
        cout << "Ordenado pelo metodo " << NomeMetodo << ":" << endl;
        ImprimiVetorDicionario(instancias, instancias.size());
        arqSaida << NomeMetodo << " Número de Trocas: " << numT << " Número de Comparações: " << numC << " Tempo de Execução: " << t << endl;
        goto menu;
    case 13:
        arqSaida.close();
        goto menuInst;
        break;
    case 14:
        break;
    default :
        system("cls");
        goto menu;
    } 
    system("cls");
    return 0;
}
void BubbleSortMelhorado(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC){
    int aux, troca;
    for (int i = 0; i < tamanho - 1; i++){
      troca = 0;
        for (int j = 1; j < tamanho - i; j++){
            if (vetor[j] < vetor[j - 1]){
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
                troca = 1;
                numT++;
                numC++;
            }else{
                numC++;
            }
        }
        if (troca == 0){
            break;
        }
    }
}
void ShellSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC){
    int i, j, value;
    int h = 1;
    while (h < tamanho){
        numC++;
        h = 3 * h + 1;
    }
    while (h > 0){
        numC++;
        for (i = h; i < tamanho; i++){
            value = vetor[i];
            j = i;
            while (j > h - 1 && value <= vetor[j - h]){
                numC++;
                vetor[j] = vetor[j - h];
                numT++;
                j = j - h;
            }
            numC++;
            if (j != i){
                numT++;
                vetor[j] = value;
            }
        }
        h = h / 3;
    }
}
void SelectionSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC){
    int i, j, menor, aux;
    for (i = 0; i < tamanho - 1; i++){
        menor = i;
        for (j = i + 1; j < tamanho; j++){
            if (vetor[j] < vetor[menor]){
                menor = j;
                numC++;
                numT++;
            }else{
                numC++;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}
void InsertSort(vector<int> &vetor, int tamanho, long long int &numT, long long int &numC){
    int i = 0, j = 1, aux = 0;
    while (j < tamanho){
        numC++;
        aux = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] > aux)){
            numC++;
            numT++;
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = aux;
        numT++;
        j = j + 1;
    }
}
void QuickSort(vector<int> &vetor, int inicio, int fim, long long int &numT, long long int &numC){
    int tmp, i = inicio, j = fim;
    int pivor = vetor[(inicio + fim)/2];
    while (i <= j){ 
        numC++; 
        while (vetor[i] < pivor){ 
            i++; 
        }
        while (vetor[j] > pivor){
            j--; 
        }
        if(i <= j){
            tmp = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = tmp; 
            i++;
            j--;
        }
	}
        numC++; 
        if (inicio < j){   
            QuickSort(vetor, inicio, j, numT, numC);
        }
        if (i < fim){ 
            QuickSort(vetor, i, fim, numT, numC);
        }
}
void MergeSort(vector<int> &vetor, int inicio, int fim, long long int &numT, long long int &numC){
    int *Auxvetor = new int [fim - inicio + 1];
    int meio;
    numC++;
    if (inicio < fim){
        meio = (inicio + fim) / 2;
        MergeSort(vetor, inicio, meio, numT, numC);
        MergeSort(vetor, meio + 1, fim, numT, numC);
        int i=0, x = inicio, y = meio+1;
        while (x <= meio && y <= fim) {
            numC++;
            if (vetor[x] < vetor[y]) {
                Auxvetor[i] = vetor[x];
                x++;
            } else {
                Auxvetor[i] = vetor[y];
                y++;
            }
            i++;
        }
        while (x <= meio) {
            Auxvetor[i] = vetor[x];
            i++;
            x++;
        }
        while (y <= fim) {
            Auxvetor[i] = vetor[y];
            i++;
            y++;
        }
        for (i = inicio; i <= fim; i++){
            vetor[i] = Auxvetor[i - inicio];
            numT++;
        }
        free(Auxvetor);
    }
}

void BubbleSortMelhoradoDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC){
bool swapped;
    
    for (int i = 0; i < tamanho - 1; i++) {
        swapped = false;
        for (int j = 0; j < tamanho - i - 1; j++) {
            numC++;
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
                swapped = true;
                numC++;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void ShellSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC){
int i, j;
string value;
    int h = 1;
    while (h < tamanho){
        numC++;
        h = 3 * h + 1;
    }
    while (h > 0){
        numC++;
        for (i = h; i < tamanho; i++){
            value = vetor[i];
            j = i;
            while (j > h - 1 && value <= vetor[j - h]){
                numC++;
                vetor[j] = vetor[j - h];
                numT++;
                j = j - h;
            }
            numC++;
            if (j != i){
                numT++;
                vetor[j] = value;
            }
        }
        h = h / 3;
    }
}

void SelectionSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC){
for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            numC++;
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(vetor[i], vetor[minIndex]);
            numT++; 
        }
    }
}

void InsertSortDicionario(vector<string> &vetor, int tamanho, long long int &numT, long long int &numC){

for (int i = 1; i < tamanho; i++) {
        string key = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            numC++;
            vetor[j + 1] = vetor[j];
            j--;
            numT++;
        }
        vetor[j + 1] = key;
        numT++;
    }
}

void QuickSortDicionario(vector<string> &vetor, int inicio, int fim, long long int &numT, long long int &numC){

    int i = inicio, j = fim;

    string tmp;
    string pivor = vetor[(inicio + fim)/2];
    while (i <= j){ 
        numC++; 
        while (vetor[i] < pivor){ 
            i++; 
        }
        while (vetor[j] > pivor){
            j--; 
        }
        if(i <= j){
            tmp = vetor[i]; 
            vetor[i] = vetor[j]; 
            vetor[j] = tmp; 
            i++;
            j--;
        }
	}
        numC++; 
        if (inicio < j){   
            QuickSortDicionario(vetor, inicio, j, numT, numC);
        }
        if (i < fim){ 
            QuickSortDicionario(vetor, i, fim, numT, numC);
        }
}

void MergeSortDicionario(vector<string> &vetor, int inicio, int fim, long long int &numT, long long int &numC){
string *Auxvetor = new string [fim - inicio + 1];
int meio;
    numC++;
    if (inicio < fim){
        meio = (inicio + fim) / 2;
        MergeSortDicionario(vetor, inicio, meio, numT, numC);
        MergeSortDicionario(vetor, meio + 1, fim, numT, numC);
        int i=0, x = inicio, y = meio+1;
        while (x <= meio && y <= fim) {
            numC++;
            if (vetor[x] < vetor[y]) {
                Auxvetor[i] = vetor[x];
                x++;
            } else {
                Auxvetor[i] = vetor[y];
                y++;
            }
            i++;
        }
        while (x <= meio) {
            Auxvetor[i] = vetor[x];
            i++;
            x++;
        }
        while (y <= fim) {
            Auxvetor[i] = vetor[y];
            i++;
            y++;
        }
        for (i = inicio; i <= fim; i++){
            vetor[i] = Auxvetor[i - inicio];
            numT++;
        }
        free(Auxvetor);
    }
}

void ImprimiVetor(vector<int> vetor, int tamanho){
  for (int i = 0; i < tamanho; i++){
    cout << vetor[i] << " " ;
  }
  cout << endl;
}

void ImprimiVetorDicionario(vector<string> vetor, int tamanho){
  for (int i = 0; i < tamanho; i++){
    cout << vetor[i] << " " ;
  }
  cout << endl;
}