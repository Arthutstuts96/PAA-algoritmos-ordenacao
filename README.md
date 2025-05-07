# Trabalho de Projeto e Análise de Algoritmos

###### Este repositório diz respeito aos códigos a serem desenvolvidos para o trabalho da disciplina de projeto e análise de algoritmos sobre algoritmos de ordenação, de modo a verificar a eficácia de diferentes algoritmos em âmbito teórico e prático

#### Linguagem utilizada:

<p>Escolhi utilizar a linguagem C, pois, além de ser bastante veloz em execução, possui o baixo nível necessário para abstrair os conceitos estudados na disciplina</p>

#### Editor de código utilizado:

<p>VSCode, pela familiarização de uso e ferramentas e extensões poderosas</p>

### Como utilizar:

- Ao compilar e executar o arquivo de output, o terminal abrirá uma interface interativa na qual é possível escolher qual das entradas deseja-se usar (1k, 10k, 50k e 100k), além da função a ser executada em tal entrada (Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort e Heap Sort)
<img src="/imagens/terminal.png" alt="Imagem da interface no terminal da aplicação" />
- Após escolhidos, o algoritmo marca o tempo atual e chama a função para ordenar a lista. Depois de executada, é marcado o tempo novamente e calcula-se a diferença, assim tendo o tempo de execução do algoritmo
- Por fim, o loop reinicia, assim permitindo testar várias funções diferentes com uma execução

#### Detalhes:

- Os tempos de execução foram marcados com o tipo <code>clock_t</code>, da biblioteca <code>time_h</code>, e o valor foi armazenado em um tipo double de 15 casas de precisão
- As funções estão separadas em um arquivo <code>funcoes.c</code> para fins de organização