#include <iostream>
using namespace std;

/*
 * Árvore AVL - O que é?
 * 
 * AVL é um tipo de árvore binária de busca (BST) auto-balanceada, onde o nome "AVL" 
 * vem das iniciais de seus inventores: Adelson-Velsky e Landis (1962).
 * 
 * Características principais:
 * 1. Para qualquer nó da árvore, a diferença de altura entre suas subárvores 
 *    esquerda e direita (fator de balanceamento) deve ser -1, 0 ou 1
 * 2. Quando essa diferença se torna maior que 1 ou menor que -1, a árvore 
 *    realiza rotações para se rebalancear
 * 3. Garante que operações como inserção, remoção e busca sejam realizadas 
 *    em tempo O(log n)
 * 
 * Guia de Rotações AVL:
 * 
 * 1. Rotação Simples à Direita (LL - Left-Left)
 *    Quando: FB > 1 e o novo nó foi inserido na subárvore esquerda do filho esquerdo
 *    Efeito: Rotaciona a árvore uma vez para a direita
 * 
 * 2. Rotação Simples à Esquerda (RR - Right-Right)
 *    Quando: FB < -1 e o novo nó foi inserido na subárvore direita do filho direito
 *    Efeito: Rotaciona a árvore uma vez para a esquerda
 * 
 * 3. Rotação Dupla Esquerda-Direita (LR - Left-Right)
 *    Quando: FB > 1 e o novo nó foi inserido na subárvore direita do filho esquerdo
 *    Efeito: Primeiro rotaciona o filho esquerdo para a esquerda, depois rotaciona a raiz para a direita
 * 
 * 4. Rotação Dupla Direita-Esquerda (RL - Right-Left)
 *    Quando: FB < -1 e o novo nó foi inserido na subárvore esquerda do filho direito
 *    Efeito: Primeiro rotaciona o filho direito para a direita, depois rotaciona a raiz para a esquerda
 * 
 * Onde FB = Fator de Balanceamento (altura_esquerda - altura_direita)
 */


 
// 1. Estrutura do nó AVL
// Cada nó contém uma chave, ponteiros para filhos esquerdo/direito e a altura do nó
struct Node {
    int key;        // Valor armazenado no nó
    Node* left;     // Ponteiro para o filho esquerdo
    Node* right;    // Ponteiro para o filho direito
    int height;     // Altura do nó na árvore
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {} 
};

// 2. Função para obter a altura de um nó
// Se o nó for nulo, retorna 0; caso contrário, retorna a altura armazenada
int height(Node* n) {
    return n ? n->height : 0; 
}

// 3. Função para calcular o fator de balanceamento
// Fator de balanceamento = altura da subárvore esquerda - altura da subárvore direita
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0; 
    
}

// 4. Rotação à direita
// Corrige desbalanceamento do tipo Esquerda-Esquerda
Node* rotateRight(Node* y) {
    Node* x = y->left;      // x será a nova raiz da subárvore
    Node* T2 = x->right;    // T2 será filho esquerdo de y após rotação

    // Realiza rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas dos nós afetados
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Retorna nova raiz da subárvore
    return x;
}

// 4. Rotação à esquerda
// Corrige desbalanceamento do tipo Direita-Direita
Node* rotateLeft(Node* x) {
    Node* y = x->right;     // y será a nova raiz da subárvore
    Node* T2 = y->left;     // T2 será filho direito de x após rotação

    // Realiza rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas dos nós afetados
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retorna nova raiz da subárvore
    return y;
}

// 5. Função de inserção
// Insere um novo nó na árvore AVL e garante o balanceamento
Node* insert(Node* node, int key) {
    // Inserção normal de BST (árvore binária de busca)
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Duplicados não são permitidos em AVL
        return node;

    // Atualiza altura do nó atual
    node->height = 1 + max(height(node->left), height(node->right));

    // Calcula o fator de balanceamento para verificar se ficou desbalanceado
    int balance = getBalance(node);

    // 4 casos de desbalanceamento:

    // Caso 1: Esquerda-Esquerda
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Caso 2: Direita-Direita
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Caso 3: Esquerda-Direita
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);   // Rotação dupla: esquerda depois direita
        return rotateRight(node);
    }

    // Caso 4: Direita-Esquerda
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right); // Rotação dupla: direita depois esquerda
        return rotateLeft(node);
    }

    // Retorna o ponteiro do nó (sem alterações se não precisou rotacionar)
    return node;
}

// 6. Percurso em ordem (in-order)
// Imprime os valores da árvore em ordem crescente
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);           // Visita subárvore esquerda
        cout << root->key << " ";      // Imprime valor do nó atual
        inOrder(root->right);          // Visita subárvore direita
    }
}

// Exemplo de uso
int main() {
    Node* root = nullptr;
    int valores[] = {10, 20, 30, 40, 50, 25}; // Valores a serem inseridos na árvore
    for (int v : valores)
        root = insert(root, v);               // Insere cada valor na AVL

    cout << "Percurso em ordem da AVL: ";
    inOrder(root);                            // Imprime os valores em ordem
    cout << endl;
    return 0;
}