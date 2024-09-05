# Tabela de Dispersão(HASH)

são estruturas de dados que utilizam uma função de dispersão (função hash) para mapear chaves a posições em uma tabela. O principal objetivo das tabelas hash é permitir o acesso rápido aos dados, com complexidade ideal de busca, inserção e remoção em 
𝑂(1).


## Conseitos Fundamentais

**1. Função HASH:**

- A função hash é responsável por converter uma chave em um índice da tabela hash. A eficiência da tabela depende de uma boa função hash que distribua as chaves de maneira uniforme.


Exemplo de função hash:

ℎ(𝑘)=𝑘 mod 𝑚, onde 𝑚 é o tamanho da tabela e mod é a operação modulo(resto da divisão).

**2. Colisões:**
 - Colisão ocorre quando duas chaves diferentes são mapeadas para o mesmo índice. Por exemplo, se ℎ(5)=1 e ℎ(9)=1, ambos ocupam o índice 1, resultando em uma colisão.

- No "mundo ideal", uma função hash perfeita não teria colisões, mas no "mundo real", colisões são inevitáveis.

## Métodos de Tratamento de Colisões

Existem vários métodos para resolver colisões em uma tabela hash:

**1.Endereçamento Aberto:**

O conceito de endereçamento aberto é encontrar um novo local na tabela para uma chave quando ocorre uma colisão.

**Sondagem Linear:**

- Procura sequencialmente pelo próximo espaço livre na tabela.

- Fórmula: 𝑝𝑥=(ℎ(𝑘)+𝑖)mod 𝑚, onde 𝑖 é o número de tentativas.

Problema: pode causar "agrupamento primário", onde muitos elementos se aglomeram em um local, diminuindo a eficiência.

**2.Encadeamento (Hashing por Encadeamento):**

- Utiliza listas encadeadas para armazenar todas as chaves que mapeiam para o mesmo índice.

- Encadeamento Separado: Cada índice na tabela contém uma lista de todas as chaves que mapeiam para aquele índice.

- Encadeamento Coalescido: Divide a tabela em duas partes: uma para armazenar as chaves primárias e outra para os elementos colididos.

## Tipos de Funções Hash

**1.Método da Divisão:**

Utiliza o operador módulo para determinar o índice.

Fórmula: ℎ(𝑘)=𝑘 mod 𝑚.
Escolha de 𝑚: M * numDeChaves(primo mais proximo).

Idealmente um número primo para distribuir uniformemente as chaves e evitar padrões.

**2.Método da Dobra:**

#### Como Funciona o Método da Dobra

A ideia principal do método da dobra é quebrar a chave original em várias partes menores de tamanho fixo. Em seguida, essas partes são somadas (ou combinadas de outra forma) para formar um único valor, que será usado para calcular o índice na tabela hash.

O nome "dobra" vem do fato de que podemos "dobrar" ou rearranjar as partes da chave antes de somá-las, para garantir uma melhor dispersão.

Exemplo Básico do Método da Dobra

Considere uma chave de 8 dígitos, como 12345678, e queremos aplicar o método da dobra para gerar um índice.

Dividir a chave em partes menores:

Suponha que decidimos dividir a chave em partes de 4 dígitos.

- Temos: 1234 e 5678.

- Somar as partes:

 - 1234+5678=6912

Aplicar o módulo para gerar o índice:

Se a tabela hash tiver tamanho 𝑚 = 100, usamos o módulo ℎ(𝑘) = 6912 mod 100=12.

Neste exemplo, o índice gerado para a chave 12345678 na tabela seria 12.

**3.Método da Multiplicação**

Multiplica a chave por uma constante 𝐴 e extrai uma parte específica do resultado.

Fórmula: ℎ(𝑘)=⌊𝑚×(𝑘𝐴 mod 1)⌋,onde 𝐴 é uma constante fracionária próxima de 1/𝜙(onde 𝜙 é a proporção áurea).


## Exemplo Prático

Suponha uma tabela hash com tamanho 𝑚=10 e chaves a serem inseridas: 12, 44, 13, 23.

Usando a função hash ℎ(𝑘)=𝑘 mod 10: 
- ℎ(12)=12 mod 10=2(índice 2)
- ℎ(44)=44 mod 10=4(índice 4)
- ℎ(13)=13 mod 10=3 (índice 3)
- ℎ(23)=23 mod 10=3 (colisão com chave 13)

Tratando a colisão com sondagem linear:

Chave 23 colide com 13 no índice 3.

Usando sondagem linear, o próximo índice verificado é 4, mas já está ocupado pela chave 44.

O próximo índice livre é 5. Portanto, a chave 23 é armazenada no índice 5.