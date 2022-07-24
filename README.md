<h1 align="center">Guide Assembly x86 👽</h1>

<p align="center">
 <a href="#Introdução">Introdução</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
 <a href="#Porque Assembly">Porque Assembly</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#O que é assembly">O que é assembly</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#O que é assembler">O que é assembler</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Noção de arquitetura">Noção de arquitetura</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Endianness">Endianness</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Instruções">Instruções</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
</p>

<a id="Introdução"></a>

## Introdução 🥱

Esse e um guia para quem quer aprender Assembly x86 e x86-64.

<a id="Porque Assembly"></a>

#### Por que aprender Assembly ?

1. Engenharia Reversa (de software)
2. Exploração de binários
3. Otimização de código
4. Tarefas de "baixo nível"
5. C & Assembly

<a id="O que é assembly"></a>

## O que é Assembly ? 🧐

De forma resumida Assembly é uma notação em formato de texto das instruções do código de máquina de uma determinada arquitetura. A "arquitetura" ao qual me refiro aqui é a ISA (Instruction Set Architecture) onde ela cria um modelo abstrato de um computador e tem diversas instruções que são computadas pelo processador, essas instruções são o que é conhecido como código de máquina.
Falando de um ponto de vista humano, entender instruções em código de máquina é uma tarefa árdua. Por isso os manuais da ISA costumam simplificar o entendimento da instrução se referindo a ela com uma notação em texto, onde essa notação é conhecida como mnemônico e tem o fim de facilitar o entendimento e a memorização da instrução do processador.
E é justamente dessa notação em texto dos manuais que surgiu o que a gente conhece hoje como "linguagem Assembly". Onde na verdade não existe uma linguagem Assembly (ou ASM para abreviar) mas sim cada ISA tem uma linguagem ASM diferente.
Os programadores antigamente escreviam o código usando a notação em texto (Assembly) e depois, a partir dela, convertiam para código de máquina manualmente. Mas felizmente hoje em dia existem softwares que fazem essa conversão de maneira automática e eles são chamados de assemblers.

<a id="O que é assembler"></a>

## O que é Assembler ? 😄

O assembler é um compilador que converte código em Assembly para o código de máquina.

<a id="Noção de arquitetura"></a>

## Noção de arquitetura 🐵

Antes de ver a linguagem e importante que sabamos sobre a arquitetura do assembly. É claro que não dá para explicar todas as características da arquitetura x86 aqui, só para te dar uma noção o manual para desenvolvedores da Intel tem mais de 5 mil páginas. Mas por enquanto vamos ter apenas uma noção sobre a arquitetura x86 para entender melhor à respeito da mesma.

## O que é arquitetura x86 ? 🏴‍☠️

Essa arquitetura nasceu no 8086, que foi um microprocessador da Intel que fez grande sucesso.
Daí em diante a Intel lançou outros processadores baseados na arquitetura do 8086 ganhando nomes como: 80186, 80286, 80386 etc. Daí surgiu a nomenclatura 80x86 onde o x representaria um número qualquer, e depois a nomenclatura foi abreviada para apenas x86.
A arquitetura evoluiu com o tempo e foi ganhando adições de tecnologias, porém sempre mantendo compatibilidade com os processadores anteriores. O processador que você tem aí pode rodar código programado para o 8086 sem problema algum.
Mais para frente a AMD criou a arquitetura x86-64, que é um superconjunto da arquitetura x86 da Intel e adiciona o modo de 64 bit. Nos dias atuais a Intel e a AMD fazem um trabalho em conjunto para a evolução da arquitetura, por isso os processadores das duas fabricantes são compatíveis.
Ou seja, x86 é um nome genérico para se referir a uma família de arquiteturas de processadores. Por motivos de simplicidade eu vou me referir as arquiteturas apenas como x86, mas na prática estamos abordando três arquiteturas neste README.

<p align="center">
  <img src="./.github/arquitetura.jpeg">
</p>

<a id="Endianness"></a>

## Endianness 🤖

A arquitetura x86 é little-endian, o que significa que a ordem dos bytes de valores numéricos segue do menos significativo ao mais significativo. Por exemplo o seguinte valor numérico em hexadecimal 0x1a2b3c4d ficaria disposto na memória RAM na seguinte ordem:

```
  1 4d 3c 2b 1a
```

<a id="Instruções"></a>

## Instruções 🤖

A arquitetura x86 é uma arquitetura <a href="https://pt.wikipedia.org/wiki/CISC">CISC</a> que, resumindo, é uma arquitetura com um conjunto complexo de instruções. Falando de maneira leviana isso significa que há várias instruções e cada uma delas tem um nível de complexidade completamente variada. Boa parte das instruções são complexas na arquitetura x86. Uma instrução "complexa" é uma instrução que faz várias operações.
Cada instrução do código de máquina tem um tamanho que pode variar de 1 até 15 bytes. E cada instrução consome um número de ciclos diferente (devido a sua complexidade variada).

## Modulo

A arquitetura x86 segue o modelo da arquitetura de Von Neumann onde esse, mais uma vez resumindo, trabalha principalmente usando uma unidade central de processamento (CPU) e uma memória principal.

<p align="center">
  <img src="./.github/CPU.png">
</p>

<p>As instruções podem trabalhar manipulando/lendo dados em registradores que são pequenas áreas de memória internas à CPU. E também pode manipular dados na memória principal que no caso é a memória RAM. Bem como também usar o sistema de entrada e saída de dados, feito pelas portas físicas.
O registrador Program Counter no diagrama acima armazena o endereço da próxima instrução que será executada na memória principal. Na arquitetura x86 esse registrador é chamado de Instruction Pointer.</p>
