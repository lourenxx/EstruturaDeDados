#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low - 1; // = -1 para que ele compare todo numero do array

    for(int j = low; j < high; j++){ 
        if(arr[j] < pivot){ // aqui está comparando o valor contido no indice do array com o valor do pivot 
            i++; // CASO SEJA MENOR DO QUE O PIVOT, o indice i será somado +1 e irá ganhará esse indice para ser ordenado na frente do pivot
            swap(arr[i], arr[j]); //a função swap faz a troca de posição com o array da posicção j com o array da posição i
        }
    }
    swap(arr[i+1], arr[high]); //rearranja o PIVOT na posição correta. i+1 significa que ele irá ficar na posição após o elemento i que foi trocado agora {1, 5...}
    return i  + 1;

}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Particiona o array

        quickSort(arr, low, pi - 1); // Ordena a parte esquerda
        quickSort(arr, pi + 1, high); // Ordena a parte direita
    }
}

int buscaBinaria(int arr[], int low, int high, int target){
    while (low <= high)
    {
        int mid = low + (high - low)/2; // formula que calcula o meio do array

        if (arr[mid] == target) // traduzindo: o valor calculado é EXATAMENTE o buscado
        {
            return target;
        }

        else if (arr[mid] > target) // traduzindo: valor encontrado no calculo MAIOR do que o numero buscado, ou seja, o valor buscado está para à ESQUERDA.
        {
            high = mid - 1;
        }

        else if (arr[mid] < target) // traduzindo: valor encontrado no calculo MENOR do que o numero buscado, ou seja, o valor buscado está para à DIREITA.
        {
            low = mid + 1;
        }
        
    }

    return - 1;
    
}

void printArray(int arr[], int size) { //função somente para printar o array na tela
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int arr[100] = {
        582, 219, 876, 143, 665, 311, 498, 927, 753, 182, 
        23, 411, 945, 759, 362, 587, 204, 635, 728, 384, 
        992, 147, 814, 592, 375, 223, 569, 176, 304, 831, 
        902, 115, 748, 256, 932, 105, 645, 389, 734, 281, 
        501, 759, 629, 318, 853, 468, 190, 755, 233, 667, 
        742, 358, 612, 288, 998, 401, 947, 735, 546, 219, 
        301, 820, 392, 127, 502, 666, 150, 713, 645, 927, 
        851, 243, 473, 810, 985, 264, 547, 192, 316, 205, 
        629, 444, 737, 812, 502, 641, 281, 490, 736, 159, 
        582, 611, 711, 378, 924, 864, 302, 299, 725, 472
    };
     // Array inicial
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    cout << "Array antes da ordenacao: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Chama Quick Sort


    cout << "\n ";

    cout << "Array apos a ordenacao: ";
    printArray(arr, n);

    cout << "\n ";

    int target;
    cout << "Digite um numero para buscar: ";
    cin >> target;

    // 🔹 Chamamos a busca binária
    int resultado = buscaBinaria(arr, 0, n - 1, target);

    if (resultado != -1)
        cout << "Numero encontrado na posicao: " << resultado << endl;
    else
        cout << "Numero nao encontrado no array." << endl;
                                                                                                         
    return 0;
}

