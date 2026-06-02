# 10 - Shooting

# Criando um Sistema de Tiros em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Shooting");

    int playerX = 100;

    int bulletX = playerX;
    int bulletY = 300;

    bool shooting = false;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) playerX += 5;
        if (IsKeyDown(KEY_LEFT)) playerX -= 5;

        if (IsKeyPressed(KEY_SPACE) && !shooting)
        {
            shooting = true;
            bulletX = playerX + 40;
            bulletY = 300;
        }

        if (shooting)
        {
            bulletY -= 10;

            if (bulletY < 0)
            {
                shooting = false;
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(playerX, 500, 100, 50, BLUE);

        if (shooting)
        {
            DrawRectangle(bulletX, bulletY, 10, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- sistema de tiros
- projéteis
- bool
- estados
- eventos
- spawning
- lógica temporal
- gameplay básico

Agora o jogo começa a parecer um jogo de verdade.

---

# Explicação linha por linha

# Importando a Raylib

```c
#include "raylib.h"
```

Importa:
- renderização
- teclado
- desenho
- sistema gráfico

---

# Função principal

```c
int main()
```

Ponto inicial do programa.

---

# Criando janela

```c
InitWindow(800, 600, "Shooting");
```

Cria:
- janela
- sistema gráfico
- contexto do jogo

---

# Variável do jogador

```c
int playerX = 100;
```

Guarda:
- posição horizontal do jogador

---

# Variáveis do projétil

```c
int bulletX = playerX;
int bulletY = 300;
```

Guardam:
- posição do tiro

---

# O que é projétil

Projétil significa:

```text
objeto disparado pelo jogador
```

Exemplos:
- bala
- laser
- flecha
- foguete

---

# Variável de estado

```c
bool shooting = false;
```

Isso é MUITO importante.

Representa:

| Valor | Significado |
|---|---|
| true | existe tiro ativo |
| false | não existe tiro |

---

# O que é estado

Estado significa:

```text
situação atual do jogo
```

Exemplos:
- player vivo
- inimigo morto
- tiro ativo
- game over

Jogos funcionam praticamente inteiros usando:
- estados
- lógica condicional

---

# Loop principal

```c
while (!WindowShouldClose())
```

Executa continuamente:
- input
- gameplay
- tiros
- renderização

---

# Movendo jogador

```c
if (IsKeyDown(KEY_RIGHT)) playerX += 5;
if (IsKeyDown(KEY_LEFT)) playerX -= 5;
```

Move:
- jogador azul

---

# Detectando tecla ESPAÇO

```c
if (IsKeyPressed(KEY_SPACE) && !shooting)
```

Verifica:

1. jogador apertou ESPAÇO
2. NÃO existe tiro ativo

---

# Diferença MUITO importante

## IsKeyDown()

```text
enquanto tecla estiver pressionada
```

---

## IsKeyPressed()

```text
somente no momento do clique
```

Isso evita:
- milhares de tiros instantâneos

---

# Operador &&

```c
&&
```

significa:

```text
E lógico
```

Então:

```c
IsKeyPressed(KEY_SPACE) && !shooting
```

significa:

```text
“espaço pressionado E não existe tiro”
```

---

# Criando o tiro

```c
shooting = true;
```

Ativa:
- estado do projétil

---

# Posicionando o tiro

```c
bulletX = playerX + 40;
```

Coloca o tiro:
- no centro aproximado do jogador

---

# Reiniciando altura do tiro

```c
bulletY = 300;
```

Define:
- posição inicial vertical

---

# Atualizando tiro

```c
if (shooting)
```

Significa:

```text
“se o tiro estiver ativo”
```

---

# Movimento do projétil

```c
bulletY -= 10;
```

Faz o tiro:
- subir na tela

Importante:

```text
Y negativo sobe
```

---

# Detectando saída da tela

```c
if (bulletY < 0)
```

Verifica:

```text
“o tiro saiu da parte superior?”
```

---

# Desativando projétil

```c
shooting = false;
```

Remove:
- tiro da tela

---

# Iniciando renderização

```c
BeginDrawing();
```

Começa frame atual.

---

# Limpando fundo

```c
ClearBackground(RAYWHITE);
```

Apaga frame anterior.

---

# Desenhando jogador

```c
DrawRectangle(playerX, 500, 100, 50, BLUE);
```

Desenha:
- nave azul

---

# Desenhando tiro

```c
DrawRectangle(bulletX, bulletY, 10, 20, RED);
```

Desenha:
- projétil vermelho

---

# Renderização condicional

```c
if (shooting)
```

O tiro só aparece:
- quando está ativo

---

# O que isso significa

O objeto:
- pode existir
- ou não existir

Isso é:
- base de gameplay
- base de entidades
- base de engines

---

# Finalizando renderização

```c
EndDrawing();
```

Entrega frame para GPU.

---

# Fechando janela

```c
CloseWindow();
```

Libera recursos corretamente.

---

# Fluxo visual do programa

```text
Teclado
   ↓
SPACE pressionado
   ↓
shooting = true
   ↓
projétil nasce
   ↓
bulletY sobe
   ↓
projétil sai da tela
   ↓
shooting = false
```

---

# O que acontece internamente

A cada frame:

1. CPU verifica teclado
2. atualiza posição
3. atualiza projétil
4. GPU desenha objetos
5. monitor mostra gameplay

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Projectile | projétil |
| Shooting | sistema de tiro |
| Bool | verdadeiro/falso |
| Estado | situação atual |
| Spawn | criação de objeto |

---

# Curiosidade MUITO importante

Quase todos os jogos usam:
- estados
- projéteis
- entidades temporárias
- lógica condicional

Mesmo engines AAA usam exatamente:
- spawning
- estados
- atualização frame a frame

---

# Resultado esperado

Você verá:

- jogador azul
- movimentação horizontal
- tiro vermelho
- tiro subindo na tela

---

# Desafio

## Desafio 1

Aumente velocidade do tiro:

```c
bulletY -= 20;
```

---

## Desafio 2

Permita:
- vários tiros simultâneos

---

## Desafio 3

Troque:
- cor do projétil

---

## Desafio 4

Adicione:
- som de tiro

---

## Super Desafio

Crie:
- sistema de cooldown
- limite de munição
- múltiplos tipos de tiro

---

# Curiosidade Avançada

Observe isso:

```c
bool shooting
```

é apenas:
- UM projétil

Jogos reais usam:
- arrays
- structs
- ponteiros
- memória dinâmica

para controlar:
- centenas
- milhares de tiros

Isso prepara o cérebro para:
- Entity Systems
- ECS
- malloc
- arrays dinâmicos

---

# Próximo passo

Na próxima etapa iremos aprender:

- inimigos
- IA simples
- movimento automático

usando:

```c
direction *= -1;
```
