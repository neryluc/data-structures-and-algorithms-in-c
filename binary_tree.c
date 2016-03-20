#include <stdio.h>
#include <stdlib.h>

struct No {
	struct No *dir;
	struct No *esq;
	int elem;
};

void inserir(struct No **raiz, int valor);
void imprimirEmOrdem(struct No *raiz);
struct No * find(struct No *raiz, int valor);

int main() {
	int operacao, valor;
	struct No *raiz = NULL;

	do {
		printf("---------- Operacoes --------------\n");
		printf("1 - Inserir na Arvore\n");
		printf("2 - Imprimir Arvore\n");
		printf("3 - Buscar valor\n");
		printf("0 - Sair\n");

		scanf_s("%d", &operacao);

		switch (operacao){
		case 1:
			printf("Digite um valor para inserir: ");
			scanf_s("%d", &valor);
			inserir(&raiz, valor);
			break;
		case 2:
			imprimirEmOrdem(raiz);
			break;
		case 3:
			printf("Digite um valor para pesquisar: ");
			scanf_s("%d", &valor);
			struct No *noEncontrado = find(raiz, valor);
			if (noEncontrado != NULL) {
				printf("\nEncontrado o seguinte No:");
				printf("\n>> Valor: %d", noEncontrado->elem);
				printf("\n>> Endereco SubArvore Esquerda: %d", noEncontrado->esq);
				if (noEncontrado->esq != NULL) {
					printf("\n>>>> Valor da SubArvore Esquerda: %d", noEncontrado->esq->elem);
				}
				printf("\n>> Endereco SubArvore Direita: %d", noEncontrado->dir);
				if (noEncontrado->dir != NULL) {
					printf("\n>>>> Valor da SubArvore Direita: %d", noEncontrado->dir->elem);
				}
			}
			else {
				printf("\nNao foi encontrado um no com esse valor!");
			}
			printf("\n");
			break;
		default:
			break;
		}
	} while (operacao != 0);

	system("pause");
	return 0;
}

void inserir(struct No **raiz, int valor) {
	if (*raiz == NULL) {
		*raiz = (struct No *) malloc(sizeof(struct No));
		(*raiz)->elem = valor;
		(*raiz)->dir = NULL;
		(*raiz)->esq = NULL;
	}
	else if (valor > (*raiz)->elem) {
		// inserir na direita
		inserir(&((*raiz)->dir), valor);
	}
	else if (valor < (*raiz)->elem) {
		// inserir na esquerda
		inserir(&((*raiz)->esq), valor);
	}
}

void imprimirEmOrdem(struct No *raiz) {
	if (raiz != NULL) {
		imprimirEmOrdem(raiz->esq);
		printf("%d \n", raiz->elem);
		imprimirEmOrdem(raiz->dir);
	}
}

struct No * find(struct No *raiz, int valor) {
	if (raiz != NULL) {
		if (valor == raiz->elem)
			return raiz;
		else if (valor > raiz->elem)
			return find(raiz->dir, valor);
		else if (valor < raiz->elem)
			return find(raiz->esq, valor);
	}
	else
		return NULL;
}