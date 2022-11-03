#include <stdio.h>
#include <stdlib.h>

// Estrutura dos Nós da arvore
typedef struct tree {
  int data;
  struct tree *left;
  struct tree *right;
  struct tree *root;
} binTree;

// Inicia a arvore
void startTree(binTree *T) {
  T = NULL;
  printf("Arvore inicializada.\n\n");
}

// Verifica se a lista esta vazia
// int isEmptyTree(binTree *T) {
//   if (T == NULL) {
//     printf("A arvore esta vazia.");
//     return 0;
//   } else {
//     printf("Ha elementos na arvore.");
//     return 0;
//   }
// }

// Cria/Insere (n)a arvore
void insertTree(binTree *T, int value) {
  if (T->root == NULL) {
    // Aloca memoria para o novo Nó
    T = (binTree *)malloc(sizeof(value));
    // Define o dado a ser inserido no Nó
    T->data = value;
    // Inicializa os filhos
    T->left = NULL;
    T->right = NULL;
    T->root = T;

  } else {
    if (T != NULL) {
      // Verifica se o valor inserido é menor que a raiz e o proximo, e inserir
      // a esquerda
      if (value < T->root->data) {
        T = (binTree *)malloc(sizeof(value));
        T->data = value;
        // Inicializa os filhos
        T->left = NULL;
        T->right = NULL;
        T->left = T;

      } else {
        T = (binTree *)malloc(sizeof(value));
        // Do contrario, se o valor inserido for maior que a raiz e o proximo,
        // inserir a direita
        T->data = value;
        // Inicializa os filhos
        T->left = NULL;
        T->right = NULL;
        T->right = T;
      }
    }
  }
}

// Faz a leitura dos elementos a esquerda da arvore
binTree *left(binTree *node) {
  binTree *aux = node;
  if (aux->left != NULL)
    aux = aux->left;
  else
    return NULL;
  return aux;
}

// Faz a leitura dos elementos a direita da arvore
binTree *right(binTree *node) {
  binTree *aux = node;
  if (aux->right != NULL)
    aux = aux->right;
  else
    return NULL;
  return aux;
}

// Faz a leitura da raiz da arvore
// binTree *mainroot(binTree *node) {
//   binTree *aux = node;
//   if (aux->root != NULL)
//     aux = aux->root;
//   else
//     return NULL;
//   return aux;
// }

// Faz a leitura dos elementos da arvore
// binTree *branches(binTree *node) {
//   binTree *aux = node;

//   if (aux == aux->root->left) {
//     if (aux->root->right != NULL) {
//       aux = aux->root->right;
//       return aux;
//     } else {
//       return NULL;
//     }
//   }

//   if (aux == aux->root->right) {
//     if (aux->root->left != NULL) {
//       aux = aux->root->left;
//       return aux;
//     } else {
//       return NULL;
//     }
//   }
// }

// Leitua em-ordem da arvore
int inOrder(binTree *T) {
  if (T->root == NULL)
    return 1;

  inOrder(T->left);
  printf("%d\n", T->data);
  inOrder(T->right);

  return 0;
}

// Pesquisa na arvore
int searchInTree(binTree *T, int value) {
  if (T->data == value)
    return 1;
  else {
    if (value > T->data)
      T = right(T);
    else
      T = left(T);

    if (T == NULL)
      return 0;
    searchInTree(T, value);
  }

  return value;
}

int main() {
  int value, opt;
  binTree *T;

  binTree tree;
  tree.root = NULL;

  do {
    printf("\n\tArvore Binaria de Pesquisa\n\n");
    printf("1. Criar uma árvore vazia\n");
    printf("2. Lista o conteúdo da árvore (in-ordem)\n");
    printf("3. Buscar um elemento na árvore\n");
    printf("4. Inserir novo elemento na árvore\n");
    printf("5. Sair\n\n");

    printf("Opt.: ");
    scanf("%d", &opt);
    system("cls || clear");

    switch (opt) {
    case 1:
      startTree(T);
      break;

    case 2:
      inOrder(T);
      break;

    case 3:
      printf("Insira o valor inteiro a ser pesquisado: ");
      scanf("%d", &value);
      searchInTree(T, value);
      break;

    case 4:
      printf("Insira o valor inteiro a ser inserido: ");
      scanf("%d", &value);
      insertTree(T, value);
      break;
    case 5:
      printf("Encerrando a arvore...\n\n");
      return 0;
      break;
    default:
      printf("Digite uma opcao valida\n");
    }
  } while (opt);

  // insertLeft(T, value);
  // insertRight(T, value);
  // left(node);
  // right(node);
  // mainroot(node);
  // branches(node);

  return 0;
}