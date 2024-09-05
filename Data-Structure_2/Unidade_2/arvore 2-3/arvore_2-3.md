# Árvore 2-3

Uma árvore 2-3 é uma árvore de busca balanceada em que cada nó pode ter 2 ou 3 filhos. Todas as folhas estão no mesmo nível, o que significa que a árvore é balanceada.

Estrutura de um Nó na Árvore 2-3
Cada nó em uma árvore 2-3 pode ser de dois tipos:

Nó 2 (contém uma chave):

Tem dois filhos (esquerdo e direito). Exemplo:

```
[10]
/  \
```
Nó 3 (contém duas chaves):

Tem três filhos (esquerdo, central e direito). Exemplo:
```
[10 | 20]
/   |   \
```

## Características

As árvores 2-3 possuem uma organização semelhante a uma árvore binária de busca, com algumas regras adicionais:

* Os filhos à esquerda de uma chave são menores que a chave.

* Os filhos à direita de uma chave são maiores que a chave.

* Se um nó tem duas chaves, os filhos entre essas chaves têm valores intermediários entre as duas chaves.


## Implementação de um Nó 2-3
Em C, um nó de uma árvore 2-3 pode ser representado como:


```
typedef struct No23 {
    int chave_esq;
    int chave_dir;
    int num_chaves;  // Indica quantas chaves o nó possui (1 ou 2)
    struct No23 *esq;
    struct No23 *dir;
    struct No23 *central;
} no23;
```
### Exemplo de Inserção

Considere a árvore a seguir e a inserção da chave **K**:
````
        M
       / \
    E|J   R
   / | \  / \
 A|C H L P S|X
````
A árvore está organizada da seguinte forma:

A raiz é o nó **M**.

M tem dois filhos: **E | J** e **R**.

**E | J** é um nó 3 (contém duas chaves: E e J) e tem três filhos: **A | C**, **H**, e **L**.

R é um nó 2 (contém uma chave: R) e tem dois filhos: **P** e **S | X**.

Passo 1: Localização

* Primeiro, localizamos onde a chave **K** deve ser inserida.
**K** é maior que **E** e menor que **J**, então deve ser inserido na subárvore central que está entre **E** e **J** (no filho H de E | J).

Passo 2: Inserção no Nó Simples

* O nó **H** atualmente é um nó simples (um nó 2), o que significa que ele pode acomodar uma nova chave sem precisar de divisão.

Portanto, **K** é inserido diretamente no nó **H**.

Árvore Após a Inserção:

O nó **H** agora se torna um nó 3, contendo as chaves **H | K**.

* A estrutura da árvore não requer mais alterações, pois não há necessidade de rebalanceamento ou divisão dos nós.

A árvore 2-3 atualizada fica assim:
````
         M
       /   \
    E|J     R
   / |  \  / \
 A|C H|K L P S|X
````

Neste caso, a inserção foi simples porque o nó **H** tinha espaço disponível para a nova chave **K**. Não foi necessário dividir o nó ou propagar mudanças para a raiz.

## Remoção de Elemento

Vamos remover a chave **J**

Passo 1: Localizar o Nó para Remoção

* Localização: **J** está no nó **E|J** na subárvore esquerda de **M**.

Passo 2: Remover a Chave de um Nó Interno

* Quando removemos uma chave de um nó interno (como **J** no nó **E|J**), precisamos substituí-la pelo sucessor in-order (o menor valor na subárvore direita de **J**).
O sucessor in-order de **J** é o menor valor na subárvore direita de **J**, que é **L** (a menor chave na subárvore que começa no nó **L**).

#### Passo 3: Substituição e Ajuste

Substituir **J** por **L**:

* Removemos **J** do nó **E|J** e o substituímos pela chave **L**.

Remover **L** da subárvore correspondente:

* Como **L** é um nó folha, sua remoção é direta e não requer nenhum rebalanceamento adicional.

Árvore após substituir **J** por **L** e remover **L**:
```
         M
      /     \
   E | L     R
  /  |      /  \
A|C H|K    P   S|X
```

#### Passo 4: Rebalanceamento (se necessário)

A remoção de **J** e a substituição por **L** não causam desbalanceamento adicional:

* O nó **E|L** continua sendo um nó 2-3 válido.

* Todas as folhas ainda estão no mesmo nível.

* Não há necessidade de fusões ou redistribuições adicionais.

Após a remoção de J e sua substituição por L, a árvore permanece balanceada e mantém suas propriedades de árvore 2-3. O processo de remoção envolveu substituir J pelo sucessor in-order L e remover L de sua posição original. A árvore final está balanceada corretamente sem a necessidade de rebalanceamento adicional.