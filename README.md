<h1 align="center">Guide Assembly x86 👽</h1>

<p align="center">
 <a href="#Introdução">Introdução</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
 <a href="#Porque Assembly">Porque Assembly</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#O que é assembly">O que é assembly</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#O que é assembler">O que é assembler</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Noção de arquitetura">Noção de arquitetura</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Endianness">Endianness</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Instruções">Instruções</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#Modo de processamento">Modo de processamento</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
    <a href="#Sintaxe">Sintaxe</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
    <a href="#Registradores gerais">Registradores gerais</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
    
</p>

<a id="Introdução"></a>

# Introdução 🥱

Esse e um guia para quem quer aprender Assembly x86 e x86-64.

<a id="Porque Assembly"></a>

#### Por que aprender Assembly ?

1. Engenharia Reversa (de software)
2. Exploração de binários
3. Otimização de código
4. Tarefas de "baixo nível"
5. C & Assembly

<a id="O que é assembly"></a>

# O que é Assembly ? 🧐

De forma resumida Assembly é uma notação em formato de texto das instruções do código de máquina de uma determinada arquitetura. A "arquitetura" ao qual me refiro aqui é a ISA (Instruction Set Architecture) onde ela cria um modelo abstrato de um computador e tem diversas instruções que são computadas pelo processador, essas instruções são o que é conhecido como código de máquina.
Falando de um ponto de vista humano, entender instruções em código de máquina é uma tarefa árdua. Por isso os manuais da ISA costumam simplificar o entendimento da instrução se referindo a ela com uma notação em texto, onde essa notação é conhecida como mnemônico e tem o fim de facilitar o entendimento e a memorização da instrução do processador.
E é justamente dessa notação em texto dos manuais que surgiu o que a gente conhece hoje como "linguagem Assembly". Onde na verdade não existe uma linguagem Assembly (ou ASM para abreviar) mas sim cada ISA tem uma linguagem ASM diferente.
Os programadores antigamente escreviam o código usando a notação em texto (Assembly) e depois, a partir dela, convertiam para código de máquina manualmente. Mas felizmente hoje em dia existem softwares que fazem essa conversão de maneira automática e eles são chamados de assemblers.

<a id="O que é assembler"></a>

# O que é Assembler ? 😄

O assembler é um compilador que converte código em Assembly para o código de máquina.

<a id="Noção de arquitetura"></a>

# Noção de arquitetura 🐵

Antes de ver a linguagem e importante que sabamos sobre a arquitetura do assembly. É claro que não dá para explicar todas as características da arquitetura x86 aqui, só para te dar uma noção o manual para desenvolvedores da Intel tem mais de 5 mil páginas. Mas por enquanto vamos ter apenas uma noção sobre a arquitetura x86 para entender melhor à respeito da mesma.

# O que é arquitetura x86 ? 🏴‍☠️

Essa arquitetura nasceu no 8086, que foi um microprocessador da Intel que fez grande sucesso.
Daí em diante a Intel lançou outros processadores baseados na arquitetura do 8086 ganhando nomes como: 80186, 80286, 80386 etc. Daí surgiu a nomenclatura 80x86 onde o x representaria um número qualquer, e depois a nomenclatura foi abreviada para apenas x86.
A arquitetura evoluiu com o tempo e foi ganhando adições de tecnologias, porém sempre mantendo compatibilidade com os processadores anteriores. O processador que você tem aí pode rodar código programado para o 8086 sem problema algum.
Mais para frente a AMD criou a arquitetura x86-64, que é um superconjunto da arquitetura x86 da Intel e adiciona o modo de 64 bit. Nos dias atuais a Intel e a AMD fazem um trabalho em conjunto para a evolução da arquitetura, por isso os processadores das duas fabricantes são compatíveis.
Ou seja, x86 é um nome genérico para se referir a uma família de arquiteturas de processadores. Por motivos de simplicidade eu vou me referir as arquiteturas apenas como x86, mas na prática estamos abordando três arquiteturas neste README.

<p align="center">
  <img src="./.github/arquitetura.jpeg">
</p>

<a id="Endianness"></a>

# Endianness 🤖

A arquitetura x86 é little-endian, o que significa que a ordem dos bytes de valores numéricos segue do menos significativo ao mais significativo. Por exemplo o seguinte valor numérico em hexadecimal 0x1a2b3c4d ficaria disposto na memória RAM na seguinte ordem:

```
  1 4d 3c 2b 1a
```

<a id="Instruções"></a>

# Instruções 🤖

A arquitetura x86 é uma arquitetura <a href="https://pt.wikipedia.org/wiki/CISC">CISC</a> que, resumindo, é uma arquitetura com um conjunto complexo de instruções. Falando de maneira leviana isso significa que há várias instruções e cada uma delas tem um nível de complexidade completamente variada. Boa parte das instruções são complexas na arquitetura x86. Uma instrução "complexa" é uma instrução que faz várias operações.
Cada instrução do código de máquina tem um tamanho que pode variar de 1 até 15 bytes. E cada instrução consome um número de ciclos diferente (devido a sua complexidade variada).

## Modulo

A arquitetura x86 segue o modelo da arquitetura de Von Neumann onde esse, mais uma vez resumindo, trabalha principalmente usando uma unidade central de processamento (CPU) e uma memória principal.

<p align="center">
  <img src="./.github/CPU.png">
</p>

<p>As instruções podem trabalhar manipulando/lendo dados em registradores que são pequenas áreas de memória internas à CPU. E também pode manipular dados na memória principal que no caso é a memória RAM. Bem como também usar o sistema de entrada e saída de dados, feito pelas portas físicas.
O registrador Program Counter no diagrama acima armazena o endereço da próxima instrução que será executada na memória principal. Na arquitetura x86 esse registrador é chamado de Instruction Pointer.</p>

## Portas físicas

Uma porta física é um barramento do processador usado para se comunicar com o restante do hardware. Por exemplo para poder usar a memória secundária, o HD, usamos uma porta física para enviar e receber dados do dispositivo. O gerenciamento desta comunicação é feito pelo chipset da placa-mãe.
Do ponto de vista do programador uma porta física é só um número especificado na instrução, muito parecido com uma porta lógica usada para comunicação em rede.

## FPU

Na época do 8086 a Intel também lançou o chamado 8087, que é um co-processador de ponto flutuante que trabalhava em conjunto com o 8086. Os processadores seguintes também ganharam co-processadores que receberam o nome genérico de x87. A partir do 80486 a FPU é interna a CPU e não mais um co-processador, porém por motivos históricos ainda chamamos a unidade de ponto flutuante da arquitetura x86 de x87.
FPU nada mais é que a unidade de processamento responsável por fazer cálculos de ponto flutuante, os famosos números float.

## Outras tecnologias

Quem dera um processador fosse tão simples assim, já mencionei que o manual da Intel tem mais de 5 mil páginas? Deixei de abordar muita coisa aqui mas que fique claro que os processadores da arquitetura x86 tem várias outras tecnologias, como o 3DNow! da AMD e o SSE da Intel.

<a id="Modo de processamento"></a>

# Modo de processamento 🤖

Como já explicado a arquitetura x86 foi uma evolução ao longo dos anos e sempre mantendo compatibilidade com os processadores anteriores. Mas código de 16, 32 e 64 bit são demasiadamente diferentes e boa parte das instruções não são equivalentes o que teoricamente faria com que, por exemplo, código de 32 bit fosse impossível de rodar em um processador x86-64. Mas é aí que entra os modos de processamento.
Um processador x86-64 consegue executar código de versões anteriores simplesmente trocando o modo de processamento. Cada modo faz com que o processador funcione de maneira um tanto quanto diferente, fazendo com que as instruções executadas também tenham resultados diferentes.
Ou seja, lá no 8086 seria como se só existisse o modo de 16 bit. Com a chegada dos processadores de 32 bit na verdade simplesmente foi adicionado um novo modo de processamento aos processadores que seria o modo de 32 bit. E o mesmo aconteceu com a chegada dos processadores x86-64 que basicamente adiciona um modo de processamento de 64 bit. É claro que além dos modos de processamento novos também surgem novas tecnologias e novas instruções, mas o modo de processamento anterior fica intacto e por isso se tem compatibilidade com os processadores anteriores.
Podemos dizer que existem três modos de processamento principais:

<p align="center">
  <img src="./.github/modoDePross.jpeg">
</p>

## Barramento interno

Os tais "bit" que são muito conhecidos mas pouco entendido, na verdade é simplesmente uma referência a largura do barramento interno do processador quando ele está em determinado modo de processamento. A largura do barramento interno do processador nada mais é que o tamanho padrão de dados que ele pode processar de uma única vez.
Imagine uma enorme via com 16 faixas e no final dela um pedágio, isso significa que 16 carros serão atendidos por vez no pedágio. Se é necessário atender 32 carros então será necessário duas vezes para atender todos os carros, já que apenas 16 podem ser atendidos de uma única vez. A largura de um barramento nada mais é que uma "via de bits", quanto mais largo mais informação pode ser enviada de uma única vez. O que teoricamente aumenta a eficiência.
No caso do barramento interno do processador seria a "via de bits" que o processador usa em todo o seu sistema interno, desconsiderando a comunicação com o hardware externo que é feita pelo barramento externo e não necessariamente tem o mesmo tamanho do barramento interno.

## Mais modos de processamento

Pelo que nós vimos acima então na verdade um "sistema operacional de 64 bit" nada mais é que um sistema operacional que executa em submodo de 64-bit. Ah, mas aí fica a pergunta:

    Se está rodando em 64 bit como é possivel execultar codigo de 32 bit ?

Isso é possível porque existem mais modos de processamento do que os que eu já mencionei. Reparou que eu disse "submodo" de 64-bit? É porque na verdade o 64-bit não é um modo principal mas sim um submodo. A hierarquia de modos de processamento de um processador Intel64 ficaria da seguinte forma:

  - Real mode (16 bit)
  - Protected mode (32 bit)
  - SMM (não vamos falar desse modo, mais ele existe)
  - IA-32e
    - 64-bit (64 bit)
    - Compatibility mode (32 bit)

O modo IA-32e é uma adição dos processadores x86-64. Repare que ele tem outro submodo chamado "compatibility mode", ou em português, "modo de compatibilidade".

    Não confundir com o modo de compatibilidade do Windows, ali é uma coisa diferente que leva o mesmo nome.

O modo de compatibilidade serve para obter compatibilidade com a arquitetura IA-32. Um sistema operacional pode setar para que código de apenas determinado segmento na memória rode nesse modo, permitindo assim que ele execute código de 32 e 64 bit paralelamente (supondo que o processador esteja em modo IA-32e). Por isso que seu Debian de 64 bit consegue rodar softwares de 32 bit, assim como o seu Windows 10 de 64 bit também consegue.

## Virtual-8086

Lembra que o antigo Windows XP de 32 bit era capaz de rodar programas de 16 bit do MS-DOS?
Isto era possível devido ao modo Virtual-8086 que, de maneira parecida com o compatibility mode, permite executar código de 16 bit enquanto o processador está em protected mode. Nos processadores atuais o Virtual-8086 não é um submodo de processamento do protected mode mas sim um atributo que pode ser setado
enquanto o processador está executando nesse modo.

<a id="Sintaxe"></a>

# Sintaxe 🤖

O Assembly da arquitetura x86 tem duas versões diferentes de sintaxe: A sintaxe Intel e a sintaxe AT&T.
A sintaxe Intel é a que iremos usar neste livro já que, ao meu ver, ela é mais intuitiva e legível. Também é a sintaxe que o nasm usa, já o GAS suporta as duas porém usando sintaxe AT&T por padrão. É importante saber ler código das duas sintaxes, mas por enquanto vamos aprender apenas a sintaxe do nasm.

## Case Insensitive

As instruções da linguagem Assembly, bem como também as instruções particulares do nasm, são case-insensitive. O que significa que não faz diferença se eu escrevo em caixa-alta, baixa ou mesclando os dois. Veja que cada linha abaixo o nasm irá compilar como a mesma instrução:

```assembly
  mov eax, 777
  Mov Eax, 777
  MOV EAX, 777
  mov EAX, 777
  MoV EaX, 777
```

## Comentários

No nasm se pode usar o ponto-vírgula `;` para comentários que única linha, equivalente ao `//` em C.
Comentários de múltiplas linhas podem ser feitos usando a diretiva pré-processada ``%comment`` para iniciar o comentário e ``%endcomment`` para finalizá-lo. Exemplo:

```assembly
; Um exemplo
mov eax, 777 ; Outro exemplo

%comment
  Mais
  um
  exemplo
%endcomment
```

## Números

Números literais podem ser escritos em base decimal, hexadecimal, octal e binário. Também é possível escrever constantes numéricas de ponto flutuante no nasm, conforme exemplos:

<p align="center">
  <img src="./.github/numeros.jpeg">
</p>

## Strings

Strings podem ser escritas no nasm de três formas diferentes:

<p align="center">
  <img src="./.github/string.jpeg">
</p>

Os dois primeiros são equivalentes e não tem nenhuma diferença para o nasm. O último aceita caracteres de escape no mesmo estilo da linguagem C.

## Formato das instruções

As instruções em Assembly seguem a premissa de especificar uma operação e seus operandos. Na arquitetura x86 uma instrução pode não ter operando algum e chegar até três operandos.

```asm
  operação operando1, operando2, operando3
```

Algumas instruções alteram o valor de um ou mais operandos, que pode ser um endereçamento na memória ou um registrador. Nas instruções que alteram o valor de apenas um operando ele sempre será o operando mais à esquerda. Um exemplo prático é a instrução mov:

```assembly
mov eax, 777
```

O mov especifica a operação enquanto o eax e o 777 são os operandos. Essa instrução altera o valor do operando destino eax para 777. Exemplo de pseudo-código:

```
  eax = 777;
```

ou em C

```C
int eax = 777;
```

    Da mesma forma que não é possível fazer 777 = eaxem linguagens de alto nível,
    também não dá para passar um valor numérico como operando destino para mov. Ou seja, isto está errado:
```
    mov 777, eax ; Erro
```

## Endereçamento

O endereçamento em Assembly x86 é basicamente um cálculo para acessar determinado valor na memória. O resultado deste cálculo é o endereço na memória que o processador irá acessar, seja para ler ou escrever dados no mesmo. Usá-se os colchetes ``[]`` para denotar um endereçamento. Ao usar colchetes como operando você está basicamente acessando um valor na memória. Por exemplo poderíamos alterar o valor no endereço 0x100 usando a instrução mov para o valor contido no registrador eax.

```asm
mov [0x100], eax
```
    Emdereçamentos se compara com ponteiros em C

    Você só pode usar um operando na memória por instrução. Então não é possível fazer algo como:
    mov [0x100], [0x200]


## Tamanho do operando

Quando um dos operandos é um endereçamento na memória você precisa especificar o seu tamanho.
Ao fazer isso você define o número de bytes que serão lidos ou escritos na memória. A maioria das instruções exigem que o operando destino tenha o mesmo tamanho do operando que irá definir o seu valor, salvo algumas exceções. No nasm existem palavra-chaves (keywords) que você pode posicionar logo antes do operando para determinar o seu tamanho.

<p align="center">
  <img src="./.github/keywords.jpeg">
</p>

Exemplo:

```asm
mov dword [0x100], 777
```
Se você usar um dos operandos como um registrador o nasm irá automaticamente assumir o tamanho do operando como o mesmo tamanho do registrador. Esse é o único caso onde você não é obrigado a especificar o tamanho porém em algumas instruções o nasm não consegue inferir o tamanho do operando.

## Pseudo-instruções

No nasm existem o que são chamadas de "pseudo-instruções", são instruções que não são de fato instruções da arquitetura x86 mas sim instruções que serão interpretadas pelo nasm. Elas são úteis para deixar o código em Assembly mais versátil mas deixando claro que elas não são instruções que serão executadas pelo processador. Exemplo básico é a pseudo-instrução db que serve para despejar bytes no correspondente local do arquivo binário de saída. Observe:

```asm
db 0x41, 0x42, 0x43, 0x44, "String", 0
```

Dá para especificar o byte como um número ou então uma sequência de bytes em formato de string. Essa pseudo-instrução não tem limite de valores separados por vírgula. Veja a saída do exemplo acima no hexdump, um visualizador hexadecimal:


<p align="center">
  <img src="./.github/hd.jpeg">
</p>

## Rótulos

Os rótulos, ou em inglês labels, são definições de símbolos usados para identificar determinados endereços da memória no código fonte em Assembly. Podem ser usados de maneira bastante parecida com os rótulos em C. O nome do rótulo serve para pegar o endereço da memória do byte seguinte a posição do rótulo, que pode ser uma instrução ou um byte qualquer produzido por uma pseudo-instrução.
Para escrever um rótulo basta digitar seu nome seguido de dois-pontos ``:``

    meu_rotulo: instrução/pseudo-instrução

Você pode inserir instruções/pseudo-instruções imediatamente após o rótulo ou então em qualquer linha seguinte, não faz diferença no resultado final. Também é possível adicionar um rótulo no final do arquivo, o fazendo apontar para o byte seguinte ao conteúdo do arquivo na memória.

Já vimos um exemplo prático de uso de rótulo na nossa PoC:

```asm
bits 64

global assembly
assembly:
  mov eax, 777
  ret
```

Repare o rótulo assembly na linha 4. Nesse caso o rótulo está sendo usado para denotar o símbolo que aponta para a primeira instrução da nossa função homônima.

## Rótulos locais

Um rótulo local, em inglês local label, é basicamente um rótulo que hierarquicamente está abaixo de outro rótulo. Para definir um rótulo local podemos simplesmente adicionar um ponto . como primeiro caractere do nosso rótulo. Veja o exemplo:

```asm
meu_rotulo:
  mov eax, 777
.subrotulo:
  mov ebx, 555
```

Dessa forma o nome completo de .subrotulo é na verdade meu_rotulo.subrotulo. As instruções que estejam hierarquicamente dentro do rótulo "pai" podem acessar o rótulo local usando de sua nomenclatura com . no início do nome ao invés de citar o nome completo. Como no exemplo:

```asm
meu_rotulo:
  jmp .subrotulo
  mov eax, 777

.subrotulo:
  ret
```

## Diretivas

Parecido com as pseudo-instruções, o nasm também oferece as chamadas diretivas. A diferença é que as pseudo-instruções apresentam uma saída em bytes exatamente onde elas são utilizadas, já as diretivas são como comandos para modificar o comportamento do assembler.
Por exemplo a diretiva ``bits`` que serve para especificar se as instruções seguintes são de 64, 32 ou 16 bits. Podemos observar o uso desta diretiva na nossa PoC. Por padrão o nasm monta as instruções como se fossem de 16 bits.


<a id="Registradores gerais"></a>

# Registradores gerais 🤖

Seguindo o modelo da arquitetura de Von Neumann, interno a CPU existem pequenos espaços de memória chamados de registers, ou em português, registradores.
Esses espaços de memória são pequenos, apenas o suficiente para armazenar um valor numérico de N bits de tamanho. Ler e escrever dados em um registrador é muito mais rápido do que a tarefa equivalente na memória principal. Do ponto de vista do programador é interessante usar registradores para manipular valores enquanto está trabalhando com eles, e depois armazená-lo de volta na memória se for o caso. Seguindo um fluxo como:

      Registradores = pequenos espaços de memória do CPU

      Registrador = Memória
      Operações com o valor no registrador
      Memória = Registrador

## Mapeamento dos registradores gerais

Afim de aumentar a versatilidade no uso de registradores, para poder manipular dados de tamanhos variados no mesmo espaço de memória do registrador, alguns registradores são subdivido em registradores menores. Isso seria o "mapeamento" dos registradores que faz com que vários registradores de tamanhos diferentes compartilhem o mesmo espaço. Se você entende como funciona uma union em C já deve ter entendido a lógica aqui.

Lá nos primórdios da arquitetura x86 os registradores tinham o tamanho de 16 bits (2 bytes). Os processadores IA-32 aumentaram o tamanho desses registradores para acompanhar a largura do barramento interno de 32 bits (4 bytes). A referência para o registrador completo ganhou um prefixo 'E' que seria a primeira letra de "Extended" (estendido). Processadores x86-64 aumentaram mais uma vez o tamanho desses registradores para 64 bits (8 bytes), dessa vez dando um prefixo 'R' que seria de "Re-extended" (re-estendido). Só que também trazendo alguns novos registradores gerais.

    AX = 16 bits (2 bytes)
    EAX = 32 bits (4 bytes) E = estendido
    RAX = 64 bits (8 bytes) R = re-estendido

## Registradores gerais (IA-16)

Os registradores de propósito geral (GPR na sigla em inglês) são registradores que são, como o nome sugere, de uso geral pelas instruções. Na arquitetura IA-16 nós temos os registradores de 16 bits que são mapeados em subdivisões como explicado acima.

Determinadas instruções da arquitetura usam alguns desses registradores para tarefas específicas mas eles não são limitados somente para esse uso. Você pode usá-los da maneira que quiser porém recomendo seguir o padrão para melhorar a legibilidade do código. O "apelido" na tabela abaixo é o nome dado aos registradores em inglês, serve para fins de memorização.

<p align="center">
  <img src="./.github/IA-16.jpeg">
</p>

Os registradores AX, BX, CX e DX são subdivididos em 2 registradores cada um. Um dos registradores é mapeado no seu byte mais significativo (Higher byte) e o outro no byte menos significativo (Lower byte).
Reparou que os registradores são uma de letra seguido do X? Para simplificar podemos dizer que os registradores são A, B, C e D e o sufixo X serve para mapear todo o registrador, enquanto o sufixo H mapeia o Higher byte e o sufixo L mapeia o Lower byte.

Ou seja se alteramos o valor de AL na verdade estamos alterando o byte menos significativo de AX. E se alteramos AH então é o byte mais significativo de AX. Como no exemplo abaixo:

```asm
mov ah, 0xaa
mov al, 0xbb
; Aqui o valor de AX é 0xaabb
```

Esse mesmo mapeamento ocorre também nos registradores BX, CX e DX. Como podemos ver na tabela abaixo:

<p align="center">
  <img src="./.github/tabela-ax.png">
</p>

    Obs: Do processador 80386 em diante, em real mode, é possível usar as versões estendidas dos registradores existentes em IA-32. Porém os registradores estendidos de x86-64 só podem ser acessados em submodo de 64-bit.

## Registradores gerais (IA-32)

Já vimos o registrador "EAX" sendo manipulado na nossa PoC. Como o prefixo 'E' indica ele é de 32 bits (4 bytes) de tamanho. Poderíamos simular esse registrador com uma union em C da seguinte forma:

    Para testar o exemplo você pode abrir a pasta src e procurar o nome do teste.

### Teste 1
```c
#include <stdio.h>
#include <stdint.h>

union reg
{
  uint32_t eax;
  uint16_t ax;

  struct
  {
    uint8_t al;
    uint8_t ah;
  };
};

int main(void)
{
  union reg x = {.eax = 0x11223344};

  printf("AH:  %02x\n"
         "AL:  %02x\n"
         "AX:  %04x\n"
         "EAX: %08x\n",
         x.ah,
         x.al,
         x.ax,
         x.eax);

  return 0;
}

```

O que deveria gerar a seguinte saída:

<p align="center">
  <img src="./.github/resultado-do-test-1.jpeg">
</p>

Podemos testar o mapeamento de EAX com nossa PoC:


### Teste 2
```asm
;Use o arquivo main.c a baixo

bits 64

global assembly
assembly:
  mov eax, 0x11223344
  mov ax,  0xaabb
  ret
```

```c
#include <stdio.h>

int assembly(void);

int main(void)
{
  printf("Resultado: %08x\n", assembly());
  return 0;
}
```

Na linha 8 alteramos o valor de EAX para ``0x11223344`` e logo em seguida, na linha 9, alteramos AX para ``0xaabb``. Isso deveria resultar em EAX = ``0x1122aabb``.


    Caso ainda não tenha reparado o retorno da nossa função assembly() é guardado no registrador EAX. Isso será explicado mais para frente nos tópicos sobre convenção de chamada.

## Registradores gerais (x86-64)

Os registradores de propósito geral em x86-64 são estendidos para 64 bits e ganham o prefixo 'R', ficando a lista: RAX, RBX, RCX, RDX, RSP, RBP, RSI, RDI

Todos os registradores gerais em IA-32 são mapeados nos 4 bytes menos significativos dos registradores re-estendidos seguindo o mesmo padrão de mapeamento anterior.

E há também um novo padrão de mapeamento do x86-64 com novos registradores gerais. Os novos nomes dos registradores são uma letra 'R' seguido de um número de 8 a 15.

O mapeamento dos novos registradores são um pouco diferentes. Podemos usar o sufixo 'B' para acessar o byte menos significativo, o sufixo 'W' para acessar a word (2 bytes) menos significativa e 'D' para acessar a doubleword (4 bytes) menos significativa. Usando R8 como exemplo podemos montar a tabela abaixo:

<p align="center">
  <img src="./.github/registradores-x86-64.jpeg">
</p>

Em x86-64 também é possível acessar o byte menos significativo dos registradores RSP, RBP, RSI e RDI. O que não é possível em IA-32 ou IA-16. Eles são mapeados em SPL, BPL, SIL e DIL.

## Escrita nos registradores gerais em x86-64

A escrita de dados nos 4 bytes menos significativos de um registrador em x86-64 funciona de maneira um pouco diferente do que nós estamos acostumados. Observe o exemplo:

```asm
mov rax, 0x11223344aabbccdd
mov eax, 0x1234
```

A instrução na linha 2 mudaria o valor de RAX para 0x0000000000001234. Isso acontece porque o valor é zero-extended, ou seja, ele é estendido de forma que os 4 bytes mais significativos de RAX são zerados.

O mesmo vale para todos os registradores gerais, incluindo os registradores R8..R15 caso você escreva algum valor em R8D..R15D.