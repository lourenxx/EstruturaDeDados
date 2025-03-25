#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <thread>
#include <cmath>

using namespace std;

// Função para o Exercício 1: Quick Sort com Escolha Inteligente de Pivô
int particionar(vector<int>& arr, int low, int high) {
    int meio = low + (high - low) / 2;
    int pivot = arr[meio];
    swap(arr[meio], arr[high]);  // Mover o pivô para o final
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortEscolhaInteligente(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);
        quickSortEscolhaInteligente(arr, low, pi - 1);
        quickSortEscolhaInteligente(arr, pi + 1, high);
    }
}

// Função para o Exercício 2: Quick Sort com Mediana de Três
int particionarMediana(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int pivot = (a < b ? (b < c ? b : (a < c ? c : a)) : (b < c ? c : (a < c ? a : b)));
    if (pivot == a) swap(arr[low], arr[low]);
    else if (pivot == b) swap(arr[mid], arr[high]);
    else swap(arr[high], arr[high]);

    return particionar(arr, low, high);
}

void quickSortMediana(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = particionarMediana(arr, low, high);
        quickSortMediana(arr, low, pi - 1);
        quickSortMediana(arr, pi + 1, high);
    }
}

// Função para o Exercício 3: Merge Sort (memória auxiliar mínima)
void merge(vector<int>& arr, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(high - low + 1);

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Função para o Exercício 4: Heap Sort (estrutura dinâmica)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Função para o Exercício 5: Busca binária em lista rotacionada
int buscaBinariaRotacionada(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) return mid;
    
    if (arr[low] <= arr[mid]) {
        if (arr[low] <= target && target < arr[mid]) return buscaBinariaRotacionada(arr, low, mid - 1, target);
        return buscaBinariaRotacionada(arr, mid + 1, high, target);
    } else {
        if (arr[mid] < target && target <= arr[high]) return buscaBinariaRotacionada(arr, mid + 1, high, target);
        return buscaBinariaRotacionada(arr, low, mid - 1, target);
    }
}

// Função para o Exercício 6: Quick Sort com Insertion Sort para sublistas pequenas
void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSortHibrido(vector<int>& arr, int low, int high) {
    if (low < high) {
        if (high - low < 10) {
            insertionSort(arr, low, high);
        } else {
            int pi = particionar(arr, low, high);
            quickSortHibrido(arr, low, pi - 1);
            quickSortHibrido(arr, pi + 1, high);
        }
    }
}

// Função para o Exercício 7: Counting Sort para números negativos e positivos
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    vector<int> count(maxVal - minVal + 1, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

// Função para o Exercício 8: Radix Sort para strings
void countingSortStrings(vector<string>& arr, int exp) {
    vector<string> output(arr.size());
    vector<int> count(256, 0);

    for (int i = 0; i < arr.size(); i++) {
        int idx = exp < arr[i].size() ? arr[i][arr[i].size() - exp - 1] : 0;
        count[idx]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        int idx = exp < arr[i].size() ? arr[i][arr[i].size() - exp - 1] : 0;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    arr = output;
}

void radixSortStrings(vector<string>& arr) {
    int maxLength = 0;
    for (auto& str : arr) {
        maxLength = max(maxLength, (int)str.size());
    }

    for (int exp = 0; exp < maxLength; exp++) {
        countingSortStrings(arr, exp);
    }
}

// Função para o Exercício 9: Bucket Sort utilizando listas encadeadas
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int bucketCount = (maxVal - minVal) / n + 1;
    vector<queue<int>> buckets(bucketCount);

    for (int i = 0; i < n; i++) {
        int idx = (arr[i] - minVal) / n;
        buckets[idx].push(arr[i]);
    }

    int idx = 0;
    for (auto& bucket : buckets) {
        while (!bucket.empty()) {
            arr[idx++] = bucket.front();
            bucket.pop();
        }
    }
}

// Função para o Exercício 10: Busca sequencial para todas as ocorrências
vector<int> buscaSequencialTodos(vector<int>& arr, int target) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) indices.push_back(i);
    }
    return indices;
}

// Função para o Exercício 11: Busca binária para primeira e última ocorrência
pair<int, int> buscaBinariaDuplicatas(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int first = -1, last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    low = 0;
    high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return make_pair(first, last);
}

// Função para o Exercício 12: Ordenar uma lista de structs (exemplo: Pessoa)
struct Pessoa {
    string nome;
    int idade;
};

bool comparaPessoa(const Pessoa& p1, const Pessoa& p2) {
    if (p1.idade == p2.idade) {
        return p1.nome < p2.nome;
    }
    return p1.idade < p2.idade;
}

void ordenarPessoas(vector<Pessoa>& pessoas) {
    sort(pessoas.begin(), pessoas.end(), comparaPessoa);
}

//DESAFIO


int main() {
    // Exercício 1: Quick Sort com escolha inteligente de pivô
    vector<int> arr1 = {10, 80, 30, 90, 40, 50, 70};
    quickSortEscolhaInteligente(arr1, 0, arr1.size() - 1);
    for (int n : arr1) cout << n << " ";
    cout << endl;

    // Exercício 2: Quick Sort com mediana de três
    vector<int> arr2 = {10, 80, 30, 90, 40, 50, 70};
    quickSortMediana(arr2, 0, arr2.size() - 1);
    for (int n : arr2) cout << n << " ";
    cout << endl;

    // Exercício 3: Merge Sort com memória auxiliar mínima
    vector<int> arr3 = {10, 80, 30, 90, 40, 50, 70};
    mergeSort(arr3, 0, arr3.size() - 1);
    for (int n : arr3) cout << n << " ";
    cout << endl;

    // Exercício 4: Heap Sort com estrutura dinâmica
    vector<int> arr4 = {10, 80, 30, 90, 40, 50, 70};
    heapSort(arr4);
    for (int n : arr4) cout << n << " ";
    cout << endl;

    // Exercício 5: Busca binária em lista rotacionada
    vector<int> arr5 = {5, 6, 7, 1, 2, 3, 4};
    int target = 3;
    cout << "Elemento encontrado no indice: " << buscaBinariaRotacionada(arr5, 0, arr5.size() - 1, target) << endl;

    // Exercício 6: Quick Sort com Insertion Sort para sublistas pequenas
    vector<int> arr6 = {10, 80, 30, 90, 40, 50, 70};
    quickSortHibrido(arr6, 0, arr6.size() - 1);
    for (int n : arr6) cout << n << " ";
    cout << endl;

    // Exercício 7: Counting Sort para números negativos e positivos
    vector<int> arr7 = {10, -2, 3, 9, -6, 7};
    countingSort(arr7);
    for (int n : arr7) cout << n << " ";
    cout << endl;

    // Exercício 8: Radix Sort para strings
    vector<string> arr8 = {"banana", "apple", "kiwi", "grape"};
    radixSortStrings(arr8);
    for (const string& str : arr8) cout << str << " ";
    cout << endl;

    // Exercício 9: Bucket Sort utilizando listas encadeadas
    vector<int> arr9 = {10, 80, 30, 90, 40, 50, 70};
    bucketSort(arr9);
    for (int n : arr9) cout << n << " ";
    cout << endl;

    // Exercício 10: Busca sequencial para todas as ocorrências
    vector<int> arr10 = {1, 2, 3, 3, 4, 3, 5};
    vector<int> indices = buscaSequencialTodos(arr10, 3);
    for (int idx : indices) cout << idx << " ";
    cout << endl;

    // Exercício 11: Busca binária para primeira e última ocorrência
    vector<int> arr11 = {1, 2, 3, 3, 3, 4, 5};
    auto result = buscaBinariaDuplicatas(arr11, 3);
    cout << "Primeira ocorrencia: " << result.first << ", Ultima ocorrencia: " << result.second << endl;

    // Exercício 12: Ordenar uma lista de structs
    vector<Pessoa> pessoas = {{"Joao", 30}, {"Maria", 25}, {"Ana", 30}};
    ordenarPessoas(pessoas);
    for (const auto& pessoa : pessoas) {
        cout << pessoa.nome << " " << pessoa.idade << endl;
    }

    //DESAFIO 


    return 0;
}