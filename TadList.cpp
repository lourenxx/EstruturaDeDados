#include <iostream>
#include <vector>

int main() {
// Criando um vetor de inteiros
std::vector<int> numeros;
// Adicionando elementos ao vetor
numeros.push_back(10);
 numeros.push_back(20);
 numeros.push_back(30);
 numeros.push_back(40);

 // Acessando e imprimindo elementos do vetor
 std::cout << "Elementos do vetor: ";
 for (int i = 0; i < numeros.size(); ++i) {
 std::cout << numeros[i] << " ";
 }
 std::cout << std::endl;

 // Modificando um elemento do vetor
 numeros[1] = 25;

 // Removendo o último elemento do vetor
 numeros.pop_back();

 // Imprimindo novamente os elementos do vetor
 std::cout << "Novos elementos do vetor: ";
 for (int num : numeros) {
 std::cout << num << " ";
 }
 std::cout << std::endl;

 return 0;
}