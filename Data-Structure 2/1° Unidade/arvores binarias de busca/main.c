#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Estudante {
    char nome[100];
    int matricula;
    char turma[10];
    float nota;
} Estudante;

typedef struct Node {
    Estudante estudante;
    struct Node *left;
    struct Node *right;
} Node;

Node* criarNo(Estudante estudante) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->estudante = estudante;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

Node* inserir(Node* root, Estudante estudante) {
    if (root == NULL) {
        return criarNo(estudante);
    }

    if (strcmp(estudante.nome, root->estudante.nome) < 0) {
        root->left = inserir(root->left, estudante);
    } else if (strcmp(estudante.nome, root->estudante.nome) > 0) {
        root->right = inserir(root->right, estudante);
    } else {
        if (estudante.matricula < root->estudante.matricula) {
            root->left = inserir(root->left, estudante);
        } else if (estudante.matricula > root->estudante.matricula) {
            root->right = inserir(root->right, estudante);
        } else {
            if (strcmp(estudante.turma, root->estudante.turma) < 0) {
                root->left = inserir(root->left, estudante);
            } else {
                root->right = inserir(root->right, estudante);
            }
        }
    }

    return root;
}

void preOrdem(Node* root) {
    if (root != NULL) {
        printf("%s ", root->estudante.nome);
        preOrdem(root->left);
        preOrdem(root->right);
    }
}

void inOrdem(Node* root) {
    if (root != NULL) {
        inOrdem(root->left);
        printf("%s ", root->estudante.nome);
        inOrdem(root->right);
    }
}

void posOrdem(Node* root) {
    if (root != NULL) {
        posOrdem(root->left);
        posOrdem(root->right);
        printf("%s ", root->estudante.nome);
    }
}

int profundidade(Node* root, char* nome, int depth) {
    if (root == NULL) {
        return -1;
    }

    if (strcmp(nome, root->estudante.nome) == 0) {
        return depth;
    } else if (strcmp(nome, root->estudante.nome) < 0) {
        return profundidade(root->left, nome, depth + 1);
    } else {
        return profundidade(root->right, nome, depth + 1);
    }
}

Node* encontrarNo(Node* root, char* nome) {
    if (root == NULL || strcmp(root->estudante.nome, nome) == 0) {
        return root;
    }

    if (strcmp(nome, root->estudante.nome) < 0) {
        return encontrarNo(root->left, nome);
    } else {
        return encontrarNo(root->right, nome);
    }
}

Node* encontrarPai(Node* root, char* nome, Node* parent) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(root->estudante.nome, nome) == 0) {
        return parent;
    } else if (strcmp(nome, root->estudante.nome) < 0) {
        return encontrarPai(root->left, nome, root);
    } else {
        return encontrarPai(root->right, nome, root);
    }
}

void inicializarEstudantes(Estudante estudantes[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        estudantes[i].nota = (float)rand() / RAND_MAX * 10;
    }
}

int main() {
    Estudante estudantes[] = {
        {"ALEX BRUNO DUARTE", 1, "01"},
        {"AMANDA DE QUEIROZ SANTIAGO", 2, "01"},
        {"ANAILTON ARTUR FERNANDES", 3, "01"},
        {"ANTHONY MATHEUS NASCIMENTO FREITAS", 4, "01"},
        {"DIEGO NASCIMENTO DE OLIVEIRA", 5, "01"},
        {"FABRICIO ANDREY LEANDRO DAMIAO", 6, "01"},
        {"FERNANDO UMBILINO ALVES", 7, "01"},
        {"FRANCISCO RYAM FEITOSA DINIZ", 8, "01"},
        {"GUILHERME DE FRANCA VASCONCELOS", 9, "01"},
        {"HARLEY LUCAS DE SOUZA BATISTA", 10, "01"},
        {"JOSE FERREIRA SOUSA NETO", 11, "01"},
        {"JOSE VERISSIMO DE OLIVEIRA QUEIROZ", 12, "01"},
        {"LUIS IZAÍAS VALENTIM DE AQUINO", 13, "01"},
        {"MEL CAMILY MONTENEGRO CARDOSO", 14, "01"},
        {"PABLO GERALDO LINHARES DO NASCIMENTO LEITE", 15, "01"},
        {"STHEFFANY DA CÂMARA GUILHERMINO", 16, "01"},
        {"THALLYS ARAUJO DE MORAIS", 17, "01"},
        {"TÚLIO GOMES DE ARAÚJO FEITOSA", 18, "01"},
        {"VICENTE BENTO DA SILVA NETO", 19, "01"},
        {"ANTONIO ERICK DA SILVEIRA FARIAS OLIVEIRA", 1, "02"},
        {"ANTONIO NOGUEIRA DA SILVA NETO", 2, "02"},
        {"DANIEL NERES VIEIRA", 3, "02"},
        {"EDUARDO PEREIRA ABRANTES", 4, "02"},
        {"EVERSON ALISSON QUEIROZ SILVA", 5, "02"},
        {"GUSTAVO KESLEY DE FONTES NUNES", 6, "02"},
        {"JEAN RICHARDSON GONCALVES MARCOS", 7, "02"},
        {"JOAO GUSTAVO SOUZA LIMA", 8, "02"},
        {"JOSE MATHEUS GOMES SILVA", 9, "02"},
        {"LEANDRO CARLOS MARTINS DE CARVALHO", 10, "02"},
        {"NATTAN FERREIRA LOPES", 11, "02"},
        {"PEDRO LUCAS DE SOUSA FERREIRA", 12, "02"},
        {"RUBENS ALEXANDRE DE SOUSA FERREIRA", 13, "02"},
        {"SAMUEL DE ALMEIDA SATURNO", 14, "02"},
        {"WESLLEY EMANOEL SILVA SOARES", 15, "02"},
        {"ALLAN GABRIEL SILVA DE FREITAS", 1, "03"},
        {"ALLYSON DA SILVA FELIX", 2, "03"},
        {"ANA BEATRIZ ALMEIDA DA SILVA", 3, "03"},
        {"ANTONIO JOAQUIM DE LIRA NETO", 4, "03"},
        {"ANTONIO VINICIUS OLIVEIRA LIMA", 5, "03"},
        {"ARTUR CARVALHO GAMA", 6, "03"},
        {"CARLOS HENRIQUE DUARTE ABRANTES", 7, "03"},
        {"DINARTE RODRIGUES DE OLIVEIRA FILHO", 8, "03"},
        {"ERIK THADEU SALES PRAXEDES", 9, "03"},
        {"EVELYN CRISTINA DE OLIVEIRA GOMES", 10, "03"},
        {"FABIO QUEIROZ VIEIRA", 11, "03"},
        {"FRANCIER EDUARDO DA SILVA LUZ", 12, "03"},
        {"FRANCISCO ADRIAN VINICIUS CHAVES SAMPAIO", 13, "03"},
        {"FRANCISCO LAILSON DE ALMEIDA", 14, "03"},
        {"GUSTAVO RODRIGUES DOS REIS", 15, "03"},
        {"HILLARY DINIZ SALDANHA", 16, "03"},
        {"JOSE KAYQUE LIMA LOPES", 17, "03"},
        {"JUANNY THAYSSA GUEDES DE FREITAS", 18, "03"},
        {"KAUE VALENTIM DE CARVALHO", 19, "03"},
        {"LEONARDO AUGUSTO SILVA DE SOUSA", 20, "03"},
        {"LETICIA MARIA GONCALVES DE MORAIS", 21, "03"},
        {"LETICIA VIEIRA GONCALVES", 22, "03"},
        {"LEVITICO RIMON PEREZ ANDRADE ALVES", 23, "03"},
        {"LUIZ EDUARDO DE ALMEIDA RODRIGUES", 24, "03"},
        {"MARCELO AUGUSTO DA SILVA FERNANDES", 25, "03"},
        {"MARCELO HENRIQUE MESSIAS CAVALCANTE", 26, "03"},
        {"MARIA CLARA SARAIVA LEAL", 27, "03"},
        {"MARIA EDUARDA DA SILVA SOUZA", 28, "03"},
        {"MARIA EDUARDA RODRIGUES BEZERRA", 29, "03"},
        {"MARIA ISABELLY LIMA DE SOUSA", 30, "03"},
        {"PEDRO HENRIQUE ANDRADE DA CONCEICAO", 31, "03"},
        {"SAMUEL IAGO DE FARIAS CABRAL", 32, "03"},
        {"SHAMYRA DE FATIMA SARAIVA CARVALHO", 33, "03"},
        {"THYAGO FABRICIO MELO COSTA", 34, "03"},
        {"TOBIAS FERNANDES FIGUEIREDO", 35, "03"}
    };

    int tamanho = sizeof(estudantes) / sizeof(estudantes[0]);
    inicializarEstudantes(estudantes, tamanho);

    Node* root = NULL;
    for (int i = 0; i < tamanho; i++) {
        root = inserir(root, estudantes[i]);
    }

    printf("Listagem Pre-Ordem: ");
    preOrdem(root);
    printf("\n");

    printf("Listagem In-Ordem: ");
    inOrdem(root);
    printf("\n");

    printf("Listagem Pos-Ordem: ");
    posOrdem(root);
    printf("\n");

    char nome[] = "JOAO GUSTAVO SOUZA LIMA";
    int profundidadeGustavo = profundidade(root, nome, 0);
    printf("Profundidade do no '%s': %d\n", nome, profundidadeGustavo);

    Node* noGustavo = encontrarNo(root, nome);
    Node* paiGustavo = encontrarPai(root, nome, NULL);

    if (paiGustavo != NULL) {
        printf("Pai de '%s': %s\n", nome, paiGustavo->estudante.nome);
    } else {
        printf("Pai de '%s': Nenhum\n", nome);
    }

    if (noGustavo != NULL) {
        if (noGustavo->left != NULL) {
            printf("Filho a esquerda de '%s': %s\n", nome, noGustavo->left->estudante.nome);
        } else {
            printf("Filho a esquerda de '%s': Nenhum\n", nome);
        }

        if (noGustavo->right != NULL) {
            printf("Filho a direita de '%s': %s\n", nome, noGustavo->right->estudante.nome);
        } else {
            printf("Filho a direita de '%s': Nenhum\n", nome);
        }
    }

    return 0;
}