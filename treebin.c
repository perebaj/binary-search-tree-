#include <stdio.h>
// 1) Escreva uma função que calcule o número de nós de uma árvore binária.

typedef struct treebin
{
    int content;
    arvore *esq;
    arvore *dir;
} arvore;

int EDR(arvore *r)
{
    int number_Of_nodes = 0;
    if (r != NULL)
    {
        ERD(r->esq);
        number_Of_nodes++;
        ERD(r->dir);
    }
    return number_Of_nodes;
}

// 2) Escreva uma função que imprima, em ordem esquerda-raiz-direita, os conteudos das folhas de uma árvore binária

//Mesma coisa da de cima mas com printf na linha 17

// 3) Escreva uma função para calcular a altura de uma árvore binária

int altura(arvore *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int heightLeft = altura(root->esq);
        int heightRight = altura(root->dir);

        return (heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1;
    }
}
//3b Versão iterativa

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.

void erd_i (arvore r) {
   criapilha ();  // pilha de nós 
   empilha (r);
   while (true) {
      x = desempilha ();
      if (x != NULL) {
         empilha (x);
         empilha (x->esq);
      }
      else {
         if (pilhavazia ()) break;
         x = desempilha ();
         printf ("%d\n", x->conteudo);
         empilha (x->dir);
      }
   }
   liberapilha ();
}

/* 4) Considere uma árvore binária já construída, mas com os campos pai não
preenchidos. Escreva uma função que preencha corretamente todos os campos pai
desta árvore. */



/*
 5) Escreva uma função que verifica se uma dada árvore binária é de busca
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* Retorna verdadeiro se a árvore é de busca binária  */
int isBTS(arvore *root, int min, int max)
{
    if (root == NULL)
        return 1;

    /* 
    Retorna false o conteudo da raiz violar a definição de árvore de busca*/
    if (root->content < min || root->content > max)
        return 0;

    /* Senão da um check nas sub-árvores recursivamente tentando encontrar as restrições min ou max */
    return isBTS(root->esq, min, root->content - 1) && isBTS(root->dir, root->content + 1, max);  
}


int main()
{
    return 0;
}