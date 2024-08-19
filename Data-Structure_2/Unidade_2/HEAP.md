# HEAP

Uma Heap é uma estrutura de dados baseada em arvore binaria que obedece a uma propriedade especifica, conhecida como propriedade do heap. Existem dois tipos de heaps: Heap Maxima e Heap Minima.


## Heap Minima

Definição:


A heap minima exige que, para qualquer nó N, o valor de N seja menor ou igual ao valor de seus filhos.


Em outras palavras, o menor valor da arvore esta sempre na raiz(o topo da arvore), e cada subarvore tambem é uma heap minima.


## Heap Maxima

Definição:


A heap Maxima exige que, para qualquer nó N, o valor de N seja maior ou igual ao valor de seus filhos. Isso significa que o maior valor da arvore esta na raiz, e cada subarvore tambem é uma heap maxima.


# Conceito Binário de Comparação em Heaps

Estrutura Binária:

Heap é uma árvore binária completa. Isso significa que é uma estrutura onde cada nó tem no máximo dois filhos, e a árvore é preenchida da esquerda para a direita em cada nível antes de passar para o próximo.

Na representação de heap como um vetor, cada nó tem uma posição que está diretamente relacionada à posição de seus filhos e seu pai:

* O pai de um nó na posição 
𝑖 está na posição 
⌊
𝑖
/
2
⌋
⌊i/2⌋.

* O filho esquerdo de um nó na posição 
𝑖 está na posição 
2
𝑖.

* O filho direito de um nó na posição 
𝑖
está na posição 
2𝑖+1.

# Mudança de Prioridade

Para mudar a prioridade de um elemento em uma heap, você deve seguir algumas etapas que dependem de como a prioridade é alterada. Existem dois cenários principais: aumento de prioridade e diminuição de prioridade. Vamos considerar uma heap do tipo max-heap para a explicação, mas os passos são análogos para uma min-heap, com as direções de movimento (subir ou descer) sendo opostas.


## Aumento da Prioridade

Quando a prioridade de um nó é aumentada (o valor do nó é incrementado em um max-heap):

Passo 1: Aumente o valor da chave do nó.


Passo 2: Verifique se o nó ainda obedece à propriedade do heap. Se o novo valor da chave for maior que o valor da chave do seu pai, troque o nó com seu pai.


Passo 3: Continue trocando o nó com seu pai até que a propriedade do heap seja restaurada (ou seja, o nó esteja na posição correta onde é menor ou igual ao seu pai e maior ou igual a seus filhos).


## Diminuição de Prioridade


Quando a prioridade de um nó é diminuída (o valor do nó é decrementado em um max-heap):

Passo 1: Diminua o valor da chave do nó.


Passo 2: Verifique se o nó ainda obedece à propriedade do heap. Se o novo valor da chave for menor que o valor das chaves dos seus filhos, troque o nó com o maior dos seus filhos.


Passo 3: Continue trocando o nó com o maior de seus filhos até que a propriedade do heap seja restaurada (ou seja, o nó esteja na posição correta onde é maior ou igual aos seus filhos e menor ou igual ao seu pai).


## Exemplo Prático:
Suponha que você tenha uma max-heap com os elementos [95, 60, 78, 39, 28, 66, 70, 33] e deseja aumentar a prioridade do elemento 66 para 98.

Passo 1: Aumente 66 para 98.
Passo 2: Agora compare 98 com seu pai (78). Como 98 é maior, troque-os.
Passo 3: Agora 98 está na posição onde estava 78, e 78 desceu. Compare 98 com o novo pai, 95. Como 98 é maior que 95, troque-os.
Resultado: 98 agora é a raiz da heap, e a estrutura ainda obedece à propriedade de max-heap.
Se fosse necessário diminuir a prioridade de 95 para 37, o processo seria análogo, mas trocando o nó 95 para baixo na árvore até que a propriedade do heap seja restabelecida.

Alterar a prioridade de um nó em uma heap é uma operação que pode ser feita em tempo 
𝑂(log 𝑛), onde 𝑛 é o número de elementos na heap, pois a altura máxima da árvore é 
log 𝑛.

