# Árvore AVL

Árvores AVL são introduzidas como uma solução para manter a altura da árvore balanceada, garantindo que as operações de busca, inserção e exclusão permaneçam eficientes. O termo balanceado pode ser entendido como sinônimo de equilibrado

O objetivo é manter as subárvores esquerda e direita com a menor diferença possivel. A menor diferença possivel é 1.

## Fator de Balanceamento

Todo nó da árvore agora possui um conceito chamado de fator de balanceamento(fb).
O FB é calculado por meio da subtração entre a altura da subarvore esquerda e direita. 

FB = altEsq - altDir

o FB é o que vai dizer se é necessario ou não balancear a arvore.

Os valores possíveis para FB são -1, 0 ou +1. Se o FB estiver fora desse intervalo, a árvore requer balanceamento.

Neste caso fazemos rotações para a esquerda ou direita a fim de rebalancear a arvore.

## Tipos de Rotações:

### Rotação à Esquerda

 Quando usar:

A rotação simples à esquerda é usada quando um nó é inserido na subárvore direita de outro nó, e isso causa um desbalanceamento com fator de balanceamento de -2 no nó pai.
Passos para realizar a rotação:

Identifique o nó desbalanceado (A).
Eleve o filho direito (B) de A.
Faça o nó A se tornar o filho esquerdo de B.
Se B tiver uma subárvore esquerda (BL), ela se torna a subárvore direita de A.
```
Antes:
    A
     \
      B
       \
        C

Depois da Rotação RR:
    B
   / \
  A   C
```

### Rotação à Direita

Quando usar:

A rotação simples à direita é utilizada quando um nó é inserido na subárvore esquerda, causando um desbalanceamento com fator de balanceamento de +2 no nó pai.
Passos para realizar a rotação:

Identifique o nó desbalanceado (A).
Eleve o filho esquerdo (B) de A.
Faça o nó A se tornar o filho direito de B.
Se B tiver uma subárvore direita (BR), ela se torna a subárvore esquerda de A.
```
Antes:
      A
     /
    B
   /
  C
Depois da Rotação LL:
    B
   / \
  C   A
```

### Rotação Esquerda Direita

Quando usar:

A rotação dupla à direita é usada quando um nó é inserido na subárvore direita do filho esquerdo, causando um desbalanceamento com fator de balanceamento de +2 no nó pai, mas a subárvore direita do filho esquerdo é mais alta.
Passos para realizar a rotação:

Identifique o nó desbalanceado (A).
Realize uma rotação à esquerda (RR) no filho esquerdo (B).
Realize uma rotação à direita (LL) no nó A.

```
Antes:
    A
   /
  B
   \
    C

Depois da Rotação LR:
    C
   / \
  B   A
```

### Rotação Direita Esquerda

Quando usar:

A rotação dupla à esquerda é utilizada quando um nó é inserido na subárvore esquerda do filho direito, causando um desbalanceamento com fator de balanceamento de -2 no nó pai, mas a subárvore esquerda do filho direito é mais alta.
Passos para realizar a rotação:

Identifique o nó desbalanceado (A).
Realize uma rotação simples à direita (LL) no filho direito (B).
Realize uma rotação simples à esquerda (RR) no nó A.

```
Antes:
  A
   \
    B
   /
  C

Depois da Rotação RL:
    C
   / \
  A   B

```