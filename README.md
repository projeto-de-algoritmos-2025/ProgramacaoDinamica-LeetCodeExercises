# Trabalho: Soluções de Programação Dinâmica (LeetCode)

**Disciplina**: Projeto de Algoritmos (FGA0124) 

**Professor**: Maurício Serrano

## 📖 Sobre o Projeto

Este repositório contém as soluções desenvolvidas para o módulo de **Programação Dinâmica** da disciplina de Projeto de Algoritmos. O objetivo principal foi aplicar e demonstrar o conhecimento teórico adquirido em aula através da resolução de desafios práticos de nível Difícil (Hard) da plataforma LeetCode.

O foco deste trabalho é a identificação de subproblemas, a utilização de *memoization* ou tabelas (*bottom-up*) e a otimização de complexidade para problemas que envolvem decisões sequenciais e estruturas complexas.

## 👥 Equipe

| Matrícula  | Aluno                               |
| :--------- | :---------------------------------- |
| 231028989  | Joao Pedro Ferreira Moraes          |



## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++

## 🚀 Desafios Resolvidos

Abaixo estão detalhados os problemas abordados, com uma breve explicação da estratégia utilizada e o comprovante de submissão.

---
### 1. [10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/description/)
![](assets/10.png)

#### **Estratégia: Programação Dinâmica (Bottom-Up)** Este é um problema clássico de correspondência de padrões que exige o tratamento de caracteres curinga (`.`) e quantificadores (`*`).

- Utilizamos uma matriz de DP `dp[i][j]`, onde a célula representa se os primeiros `i` caracteres da string `s` correspondem aos primeiros `j` caracteres do padrão `p`.
- **Casos Base:** Tratamos strings vazias e padrões que podem corresponder a vazio (como `a*b*`).
- **Transições:**
    - Se o caractere atual do padrão for uma letra ou `.`, verificamos a diagonal anterior (`dp[i-1][j-1]`).
    - Se o caractere for `*`, temos uma bifurcação lógica (a essência da DP aqui):
        1.  **Zero ocorrências:** Ignoramos o caractere anterior e o `*` (olhamos para `dp[i][j-2]`).
        2.  **Uma ou mais ocorrências:** Se o caractere anterior bater com a string, consumimos um caractere de `s` e mantemos o estado no `*` (olhamos para `dp[i-1][j]`).

**Submissão:**
[Submissão LeetCode 10](https://leetcode.com/problems/regular-expression-matching/submissions/1844585251)

![](assets/10Sub.png)

---

### 2. [140. Word Break II](https://leetcode.com/problems/word-break-ii/description/)
![](assets/140.png)

#### **Estratégia: DP Top-Down (DFS com Memoization)** Diferente da versão I deste problema (que pede apenas verdadeiro/falso), aqui precisamos listar todas as sentenças possíveis. Uma abordagem puramente iterativa (tabela) seria custosa em memória.

- Utilizamos **DFS (Backtracking)** combinado com **Memoization** (`unordered_map<int, vector<string>>`).
- A função recursiva recebe um índice inicial. Para cada chamada, iteramos sobre possíveis finais de palavras. Se a substring `s[inicio...fim]` existe no dicionário, fazemos a chamada recursiva para o restante da string.
- O retorno da recursão é combinado com a palavra atual para formar as frases.
- O mapa de memoization armazena as listas de frases já calculadas para determinado índice, evitando reprocessamento exponencial de sufixos idênticos.

**Submissão:**
[Submissão LeetCode 140](https://leetcode.com/problems/word-break-ii/submissions/1844587145)

![](assets/140Sub.png)

---

### 3. [85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/description/)
![](assets/85.png)

#### **Estratégia: Programação Dinâmica com Histograma (Limites Left/Right)** Resolver este problema testando todas as submatrizes seria inviável. A estratégia utilizada reduz o problema 2D para uma série de problemas 1D.

- Tratamos cada linha da matriz como a base de um histograma acumulativo. Se encontramos um `1`, incrementamos a altura; se `0`, a altura reseta.
- Para calcular a área máxima em cada linha de forma eficiente ($O(N)$ por linha), mantivemos três vetores de estado DP:
    1.  `height[j]`: Altura acumulada de 1s na coluna `j`.
    2.  `left[j]`: O índice mais à esquerda que a barra atual consegue se estender (limite esquerdo).
    3.  `right[j]`: O índice mais à direita que a barra atual consegue se estender (limite direito).
- A área máxima para cada célula é calculada como `(right[j] - left[j]) * height[j]`. Essa abordagem evita o uso explícito de pilhas e mantém a complexidade total em $O(N \cdot M)$.

**Submissão:**
[Submissão LeetCode 85](https://leetcode.com/problems/maximal-rectangle/submissions/1844588422)

![](assets/85Sub.png)

---

## 🎬 Vídeo de Apresentação

A explicação detalhada do raciocínio por trás de cada solução pode ser encontrada nos vídeos abaixo:

[10. Regular Expression Matching](LINK_AQUI)

[140. Word Break II](LINK_AQUI)

[85. Maximal Rectangle](LINK_AQUI)