#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Info
{
    char nome[100];
    int mat;
    int turma;
    float nota;
};

struct Node
{
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

struct Info criarInfo(char *nome, int mat, int turma, float nota);
struct Node *criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node *inserir(struct Node *raiz, struct Info info);

int main()
{
    struct Info info[10];
    info[0] = criarInfo("Kennedy", 4, 1, rand() % 10);
    info[1] = criarInfo("Mikael", 3, 1, rand() % 10);

    struct Node *raiz = 0;
    raiz = inserir(raiz, info[0]);
    raiz = inserir(raiz, info[1]);
}

struct Info criarInfo(char *nome, int mat, int turma, float nota)
{
    struct Info res;
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

struct Node *criarNode(struct Info info)
{
    struct Node *res = (struct Node *)malloc(sizeof(struct Node));
    res->info = info;
    res->dir = 0;
    res->esq = 0;
    return res;
}

int comparar(struct Info a, struct Info b)
{
    return strcmp(a.nome, b.nome);
}

struct Node *inserir(struct Node *raiz, struct Info info)
{
    if (raiz == 0)
    {
        return criarNode(info);
    }
    int x = comparar(raiz->info, info);
    if (x < 0)
    {
        raiz->dir = inserir(raiz->dir, info);
    }
    else if (x > 0)
    {
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz;
}