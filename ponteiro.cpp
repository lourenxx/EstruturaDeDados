#include <iostream>

int main() {
int numero = 42;

// Declarando um ponteiro e atribuindo o endereço de 'numero'
int* ponteiro = &numero; // ponteiro é um ponteiro para int

std::cout << "Valor de numero: " << numero << std::endl;
std::cout << "Endereco de numero: " << &numero << std::endl;

// Desreferenciando o ponteiro
std::cout << "Valor do ponteiro: " << *ponteiro << std::endl;
std::cout << "Endereco do ponteiro: " << ponteiro << std::endl;

// Modificando o valor através do ponteiro
*ponteiro = 99; // ponteiro aponta para o endereço de 'numero', então *ponteiro modifica 'numero'
std::cout << "Novo valor de numero: " << numero << std::endl;

return 0;
}