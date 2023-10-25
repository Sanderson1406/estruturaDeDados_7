#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração de estruturas

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//func que insere um no na arvore

struct no *inserir(struct no *raiz, int numero) {
	//caso facil
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	}else {
		if ((rand() % 2) == 0) {
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else {
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	return raiz;
}

//navegacao em pre ordem 

void navegarPreOrdem(struct no *raiz){
	if(raiz != NULL) {
		printf("%d\t", raiz -> numero);
		navegarPreOrdem(raiz -> esquerda);
		navegarPreOrdem(raiz -> direita);
	}
}

void navegarEmOrdem(struct no *raiz){
	if(raiz != NULL) {
		navegarEmOrdem(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
	}
}

void navegarPosOrdem(struct no *raiz){
	if(raiz != NULL) {
		navegarPosOrdem(raiz -> esquerda);
		navegarPosOrdem(raiz -> direita);
		printf("%d\t", raiz -> numero);
	}
}

//funcao de execucao de programa

int main(){
	//declarar arvore
	struct no *raiz = NULL;
	//inicialização da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	//preenchimento da arvore
	int i = 0;
	for (i = 0; i < 10; i++) {
		raiz = inserir(raiz, i);
	}
	
	//navegacao pre ordem
	printf("\n-----PRE ORDEM-----\n");
	navegarPreOrdem(raiz);
	
	//navegacao em ordem
	printf("\n-----EM ORDEM-----\n");
	navegarEmOrdem(raiz);
	
	//navegacao pos ordem
	printf("\n-----POS ORDEM-----\n");
	navegarPosOrdem(raiz);
}
