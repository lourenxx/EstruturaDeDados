#include <iostream>
using namespace std;

// Estrutura para representar um nó na fila
struct Node {
    int data;       // Dado armazenado no nó
    Node* next;     // Ponteiro para o próximo nó
};

// Classe para representar a fila
class Queue {
private:
    Node* head;    // Ponteiro para o primeiro nó da fila
    Node* tail;    // Ponteiro para o último nó da fila

public:
    // Construtor para inicializar a fila vazia
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    // Função para verificar se a fila está vazia
    bool isEmpty() {
        return (head == nullptr);
    }

    // Função para adicionar um elemento à fila
    void enqueue(int value) {
        // Cria um novo nó
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // Se a fila estiver vazia, o novo nó será o primeiro e o último nó
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            // Caso contrário, adiciona o novo nó ao final da fila
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Função para remover um elemento da fila
    int dequeue() {
        // Verifica se a fila está vazia
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Retorna -1 para indicar que a fila está vazia
        } else {
            // Armazena o valor do nó que será removido
            int value = head->data;
            // Move o ponteiro head para o próximo nó
            Node* temp = head;
            head = head->next;
            // Libera a memória do nó removido
            delete temp;
            cout << "Dequeued: " << value << endl;
            return value;
        }
    }

    // Função para exibir os elementos da fila
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    // Testando a fila
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue(); // Tentativa de remover de uma fila vazia

    return 0;
}