# 12 - Pointers and Memory

# Ponteiros e Memória Dinâmica em Raylib (C)

```c
#include "raylib.h"
#include <stdlib.h>

typedef struct Enemy
{
    int x;
    int y;
} Enemy;

int main()
{
    InitWindow(800, 600, "Pointers and Memory");

    int quantidade = 5;

    Enemy *enemies = malloc(sizeof(Enemy) * quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        enemies[i].x = 100 * i + 50;
        enemies[i].y = 200;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < quantidade; i++)
        {
            DrawRectangle(enemies[i].x,
                          enemies[i].y,
                          50,
                          50,
                          RED);
        }

        DrawText("Dynamic Memory Example", 10, 10, 20, BLACK);

        EndDrawing();
    }

    free(enemies);

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- ponteiros
- memória dinâmica
- heap
- malloc
- free
- structs
- arrays dinâmicos
- gerenciamento de memória

Agora entramos em conceitos MUITO importantes da Ciência da Computação.

---

# Explicação linha por linha

# Importando Raylib

```c
#include "raylib.h"
```

Importa:
- renderização
- gráficos
- sistema de janela

---

# Importando stdlib

```c
#include <stdlib.h>
```

Importa funções da biblioteca padrão do C.

Aqui usamos:

- malloc()
- free()

---

# O que é stdlib

```text
Standard Library
```

Possui:
- memória dinâmica
- conversão
- números aleatórios
- controle de processos

---

# Criando uma struct

```c
typedef struct Enemy
{
    int x;
    int y;
} Enemy;
```

Criamos um novo tipo chamado:

```c
Enemy
```

---

# O que é struct

Struct significa:

```text
estrutura de dados
```

Ela agrupa:
- múltiplas variáveis
- dentro de um único objeto

---

# O que existe dentro de Enemy

Cada inimigo possui:

| Campo | Significado |
|---|---|
| x | posição horizontal |
| y | posição vertical |

---

# O que o compilador faz

Internamente fica parecido com:

```text
Enemy
├── x
└── y
```

Tudo organizado na memória RAM.

---

# Função principal

```c
int main()
```

Ponto inicial do programa.

---

# Criando janela

```c
InitWindow(800, 600, "Pointers and Memory");
```

Cria:
- janela gráfica
- sistema de renderização

---

# Quantidade de inimigos

```c
int quantidade = 5;
```

Define:

```text
quantos inimigos existirão
```

---

# Introdução aos ponteiros

```c
Enemy *enemies
```

Aqui começa a parte MUITO importante.

---

# O que significa *

```c
*
```

significa:

```text
PONTEIRO
```

---

# O que é ponteiro

Um ponteiro:
- guarda endereço de memória

Ou seja:

```c
Enemy *enemies
```

significa:

```text
“enemies aponta para um local da memória”
```

---

# O que é memória RAM

RAM é:
- memória temporária do computador

Tudo do jogo fica lá:
- variáveis
- posições
- sprites
- áudio
- structs

---

# Alocando memória dinâmica

```c
Enemy *enemies = malloc(sizeof(Enemy) * quantidade);
```

Aqui acontece algo MUITO importante.

---

# O que é malloc

```c
malloc()
```

significa:

```text
memory allocation
```

ou:

```text
alocação de memória
```

---

# O que malloc faz

O sistema operacional:

1. reserva memória na RAM
2. retorna endereço dessa memória
3. ponteiro guarda esse endereço

---

# O que é heap

A memória usada pelo malloc fica na:

```text
HEAP
```

Heap é:
- área de memória dinâmica

Usada quando:
- tamanho muda
- quantidade varia
- objetos nascem/desaparecem

---

# O que sizeof faz

```c
sizeof(Enemy)
```

retorna:

```text
quantos bytes um Enemy ocupa
```

---

# Multiplicando pela quantidade

```c
sizeof(Enemy) * quantidade
```

Significa:

```text
“reserve espaço para vários inimigos”
```

---

# O que acontece internamente

Imagine:

```text
Enemy ocupa 8 bytes
```

Então:

```text
8 * 5 = 40 bytes
```

malloc reservará:
- 40 bytes na heap

---

# Acessando memória dinâmica

```c
enemies[i]
```

Acessa:
- cada posição do array dinâmico

---

# O que é i

```c
i
```

é o índice do vetor.

---

# Loop de inicialização

```c
for (int i = 0; i < quantidade; i++)
```

Repete:
- para todos os inimigos

---

# Definindo posição X

```c
enemies[i].x = 100 * i + 50;
```

Cada inimigo:
- nasce em posição diferente

---

# O que significa enemies[i].x

Isso significa:

```text
acessar o campo x do inimigo i
```

---

# O que acontece internamente

O compilador faz algo parecido com:

```c
(*(enemies + i)).x
```

Isso já envolve:
- ponteiros
- aritmética de memória

---

# Definindo posição Y

```c
enemies[i].y = 200;
```

Todos começam:
- na mesma altura

---

# Loop principal

```c
while (!WindowShouldClose())
```

Executa continuamente:
- renderização
- atualização
- gameplay

---

# Começando renderização

```c
BeginDrawing();
```

Inicia frame atual.

---

# Limpando tela

```c
ClearBackground(RAYWHITE);
```

Apaga frame anterior.

---

# Loop de renderização

```c
for (int i = 0; i < quantidade; i++)
```

Desenha:
- todos os inimigos

---

# Desenhando inimigos

```c
DrawRectangle(enemies[i].x,
              enemies[i].y,
              50,
              50,
              RED);
```

Desenha:
- vários inimigos vermelhos

---

# O mais importante desta aula

Observe isso:

```c
enemies[i]
```

Agora:
- NÃO temos apenas um inimigo

Temos:

```text
um sistema dinâmico de entidades
```

---

# Desenhando texto

```c
DrawText("Dynamic Memory Example", 10, 10, 20, BLACK);
```

Mostra:
- informação na tela

---

# Finalizando renderização

```c
EndDrawing();
```

Entrega frame para GPU.

---

# Liberando memória

```c
free(enemies);
```

MUUUITO importante.

---

# O que free faz

```c
free()
```

devolve memória para sistema operacional.

---

# Sem free acontece:

- memory leak
- vazamento de RAM
- consumo crescente
- travamentos

---

# Fechando janela

```c
CloseWindow();
```

Libera sistema gráfico corretamente.

---

# Fluxo visual do programa

```text
malloc()
   ↓
Reserva memória na heap
   ↓
Ponteiro recebe endereço
   ↓
Loop cria inimigos
   ↓
Renderização desenha inimigos
   ↓
free()
   ↓
Memória liberada
```

---

# O que acontece internamente

O sistema operacional:

1. reserva RAM
2. entrega endereço
3. CPU acessa memória
4. GPU desenha entidades
5. free devolve memória

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Pointer | endereço de memória |
| Heap | memória dinâmica |
| malloc | alocação dinâmica |
| free | liberar memória |
| Struct | agrupamento de dados |
| Array Dinâmico | vetor criado em tempo real |

---

# Curiosidade MUITO importante

Quase TODAS as engines modernas usam:

- ponteiros
- heap
- memória dinâmica
- arrays de entidades

Inclusive:
- Unity
- Unreal
- Godot
- engines AAA

---

# calloc()

Existe também:

```c
calloc()
```

Diferença:

| Função | Comportamento |
|---|---|
| malloc | memória “suja” |
| calloc | memória zerada |

---

# realloc()

Também existe:

```c
realloc()
```

Usado para:
- aumentar arrays
- criar wave systems
- crescer entidades dinamicamente

---

# Resultado esperado

Você verá:

- vários inimigos vermelhos
- criados dinamicamente
- usando memória heap

---

# Desafio

## Desafio 1

Aumente:

```c
int quantidade = 20;
```

---

## Desafio 2

Movimente os inimigos.

---

## Desafio 3

Use:
- cores diferentes

---

## Desafio 4

Teste:

```c
calloc()
```

---

## Super Desafio

Use:

```c
realloc()
```

para:
- aumentar inimigos durante o jogo

---

# Curiosidade Avançada

Observe isso:

```c
Enemy *enemies
```

é praticamente o começo de:

- ECS
- Entity Systems
- Game Engines
- Data-Oriented Design

Ou seja:

```text
você já está entrando em arquitetura real de engines
```

---

# Próximo passo

Agora você já possui:

- renderização
- input
- colisão
- shooting
- inimigos
- structs
- ponteiros
- heap
- memória dinâmica

Você já consegue construir:

- mini shooters
- arcade games
- sistemas ECS básicos
- mini engines 2D
- jogos completos em C
