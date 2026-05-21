# 24 - Scene Manager

# Criando Scene Manager em Raylib (C)

# Objetivo da Aula

Nesta aula iremos aprender a criar:

```text
gerenciamento de cenas
```

Agora o jogo poderá possuir:

- menu principal
- gameplay
- pause
- game over
- vitória
- troca de telas
- estados do jogo

Isso é a base da arquitetura de praticamente qualquer jogo profissional.

---

# O que iremos aprender

Nesta aula vamos estudar:

- game states
- scene manager
- enum
- troca de telas
- fluxo do jogo
- menu → gameplay
- pause
- game over
- arquitetura de jogos

---

# O que é uma cena?

Uma cena é:

```text
uma tela do jogo
```

Exemplos:

| Cena | Função |
|---|---|
| MENU | tela inicial |
| GAMEPLAY | jogo acontecendo |
| PAUSE | jogo pausado |
| GAME OVER | derrota |
| WIN | vitória |

---

# O que é Scene Manager?

Scene Manager é:

```text
sistema que controla qual tela está ativa
```

---

# Jogos usam isso o tempo todo

| Jogo | Scene Manager |
|---|---|
| Mario | ✔ |
| GTA | ✔ |
| Terraria | ✔ |
| Hollow Knight | ✔ |
| Minecraft | ✔ |

---

# Código Completo

```c
// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"

// =========================================
// GAME STATES
// =========================================

typedef enum GameScene
{
    MENU,
    GAMEPLAY,
    PAUSE,
    GAMEOVER

} GameScene;

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Cria janela
    InitWindow(1200, 700, "Scene Manager");

    // FPS
    SetTargetFPS(60);

    // =========================================
    // CENA ATUAL
    // =========================================

    GameScene cenaAtual = MENU;

    // =========================================
    // JOGADOR
    // =========================================

    Vector2 jogador = { 300, 300 };

    float velocidade = 300;

    int score = 0;

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // DELTA TIME
        // =========================================

        float delta = GetFrameTime();

        // =========================================
        // MENU
        // =========================================

        if (cenaAtual == MENU)
        {
            // ENTER inicia jogo
            if (IsKeyPressed(KEY_ENTER))
            {
                cenaAtual = GAMEPLAY;
            }
        }

        // =========================================
        // GAMEPLAY
        // =========================================

        else if (cenaAtual == GAMEPLAY)
        {
            // Movimento
            if (IsKeyDown(KEY_RIGHT))
                jogador.x += velocidade * delta;

            if (IsKeyDown(KEY_LEFT))
                jogador.x -= velocidade * delta;

            if (IsKeyDown(KEY_UP))
                jogador.y -= velocidade * delta;

            if (IsKeyDown(KEY_DOWN))
                jogador.y += velocidade * delta;

            // Score
            if (IsKeyPressed(KEY_P))
            {
                score += 10;
            }

            // Pause
            if (IsKeyPressed(KEY_ESCAPE))
            {
                cenaAtual = PAUSE;
            }

            // Game over
            if (score >= 100)
            {
                cenaAtual = GAMEOVER;
            }
        }

        // =========================================
        // PAUSE
        // =========================================

        else if (cenaAtual == PAUSE)
        {
            // Volta jogo
            if (IsKeyPressed(KEY_ENTER))
            {
                cenaAtual = GAMEPLAY;
            }

            // Volta menu
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                cenaAtual = MENU;
            }
        }

        // =========================================
        // GAME OVER
        // =========================================

        else if (cenaAtual == GAMEOVER)
        {
            // Reinicia jogo
            if (IsKeyPressed(KEY_R))
            {
                // Reinicia variáveis
                score = 0;

                jogador = (Vector2){300, 300};

                // Volta gameplay
                cenaAtual = GAMEPLAY;
            }
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // =========================================
        // MENU
        // =========================================

        if (cenaAtual == MENU)
        {
            DrawText(
                "MENU PRINCIPAL",
                340,
                180,
                60,
                DARKBLUE
            );

            DrawText(
                "ENTER = iniciar jogo",
                380,
                320,
                30,
                DARKGRAY
            );

            DrawText(
                "Scene Manager controla telas do jogo",
                260,
                500,
                25,
                MAROON
            );
        }

        // =========================================
        // GAMEPLAY
        // =========================================

        else if (cenaAtual == GAMEPLAY)
        {
            // Mundo
            DrawRectangle(
                0,
                620,
                1200,
                80,
                DARKGREEN
            );

            // Jogador
            DrawRectangleV(
                jogador,
                (Vector2){50, 50},
                BLUE
            );

            // HUD
            DrawRectangle(
                0,
                0,
                1200,
                120,
                Fade(LIGHTGRAY, 0.9f)
            );

            DrawText(
                "GAMEPLAY",
                20,
                20,
                40,
                DARKBLUE
            );

            DrawText(
                "Setas = mover",
                20,
                70,
                20,
                DARKGRAY
            );

            DrawText(
                "P = ganha score",
                220,
                70,
                20,
                DARKGRAY
            );

            DrawText(
                "ESC = pause",
                420,
                70,
                20,
                DARKGRAY
            );

            DrawText(
                TextFormat("Score: %d", score),
                720,
                70,
                25,
                MAROON
            );
        }

        // =========================================
        // PAUSE
        // =========================================

        else if (cenaAtual == PAUSE)
        {
            DrawText(
                "PAUSE",
                450,
                180,
                70,
                ORANGE
            );

            DrawText(
                "ENTER = voltar",
                390,
                320,
                30,
                DARKGRAY
            );

            DrawText(
                "BACKSPACE = menu",
                350,
                380,
                30,
                DARKGRAY
            );
        }

        // =========================================
        // GAME OVER
        // =========================================

        else if (cenaAtual == GAMEOVER)
        {
            DrawText(
                "GAME OVER",
                320,
                180,
                70,
                RED
            );

            DrawText(
                "Voce atingiu 100 pontos!",
                320,
                300,
                35,
                DARKGRAY
            );

            DrawText(
                "R = reiniciar jogo",
                380,
                420,
                30,
                MAROON
            );
        }

        // =========================================
        // DEBUG INFO
        // =========================================

        DrawText(
            TextFormat(
                "Cena Atual: %d",
                cenaAtual
            ),
            20,
            660,
            20,
            BLACK
        );

        EndDrawing();
    }

    // Fecha janela
    CloseWindow();

    return 0;
}
```

---

# Explicação COMPLETA da Arquitetura

# 1. O que é Scene Manager?

Scene Manager controla:

```text
qual tela do jogo está ativa
```

---

# Exemplo

```text
MENU
↓
GAMEPLAY
↓
PAUSE
↓
GAME OVER
```

---

# 2. Enum GameScene

```c
typedef enum GameScene
```

Criamos:

```text
tipos de cena
```

---

# Cenas disponíveis

| Cena | Função |
|---|---|
| MENU | tela inicial |
| GAMEPLAY | jogo principal |
| PAUSE | pausa |
| GAMEOVER | derrota/fim |

---

# 3. Cena Atual

```c
GameScene cenaAtual = MENU;
```

Guarda:

```text
qual tela está ativa
```

---

# Isso é MUITO importante

Todo o jogo depende dessa variável.

---

# 4. Máquina de estados

O Scene Manager funciona como:

```text
máquina de estados
```

---

# Exemplo visual

```text
MENU
  ↓
GAMEPLAY
  ↓
PAUSE
  ↓
GAMEPLAY
  ↓
GAME OVER
```

---

# 5. Controle de fluxo

```c
if (cenaAtual == MENU)
```

Executa:
- apenas lógica do menu

---

# Isso separa o jogo

Cada cena:
- possui regras próprias
- input próprio
- renderização própria

---

# 6. Cena MENU

```c
if (IsKeyPressed(KEY_ENTER))
{
    cenaAtual = GAMEPLAY;
}
```

Quando ENTER:
- troca cena

---

# Isso é transição de tela

```text
MENU → GAMEPLAY
```

---

# 7. Cena GAMEPLAY

Aqui:
- jogo realmente acontece

---

# Movimento

```c
jogador.x += velocidade * delta;
```

---

# Score

```c
score += 10;
```

---

# Pause

```c
cenaAtual = PAUSE;
```

---

# Game Over

```c
if (score >= 100)
```

Troca para:
- GAMEOVER

---

# 8. Cena PAUSE

Pause:
- congela gameplay
- muda apenas interface

---

# ENTER

```c
cenaAtual = GAMEPLAY;
```

Volta jogo.

---

# BACKSPACE

```c
cenaAtual = MENU;
```

Volta menu principal.

---

# 9. Cena GAME OVER

```c
if (IsKeyPressed(KEY_R))
```

Reinicia:
- score
- posição
- gameplay

---

# Isso é reset de estado

Muito comum em jogos.

---

# 10. Draw separado por cenas

Cada cena possui:

```text
renderização própria
```

---

# Exemplo

MENU:
- desenha menu

GAMEPLAY:
- desenha mundo

PAUSE:
- desenha pausa

---

# Isso deixa arquitetura limpa

Sem isso:
- código vira bagunça gigante

---

# 11. Máquina de estados visual

```text
[MENU]
   ↓ ENTER

[GAMEPLAY]
   ↓ ESC

[PAUSE]
   ↓ ENTER

[GAMEPLAY]
   ↓ SCORE >= 100

[GAME OVER]
   ↓ R

[GAMEPLAY]
```

---

# 12. Fluxo completo

```text
input
↓
troca estado
↓
executa lógica da cena
↓
desenha cena atual
```

---

# 13. Scene Manager profissional

Engines reais possuem:
- scene manager
- game states
- state machines

---

# Inclusive

| Engine | Scene System |
|---|---|
| Unity | Scenes |
| Unreal | Levels |
| Godot | Nodes/Scenes |
| Raylib | manual |

---

# Conceitos profissionais aprendidos

| Conceito | Foi usado |
|---|---|
| Scene Manager | ✔ |
| Game States | ✔ |
| Enum | ✔ |
| Máquina de Estado | ✔ |
| Menu | ✔ |
| Pause | ✔ |
| Gameplay | ✔ |
| Game Over | ✔ |

---

# O que você aprende de verdade

# você entende:

```text
jogos profissionais são organizados em estados
```

E entende:
- como menus funcionam
- como trocar telas
- como pausar jogos
- como organizar arquitetura de gameplay

---

# Curiosidade MUITO importante

Mesmo jogos gigantes usam:
- state machines
- scene managers
- game states

Inclusive:
- GTA
- Mario
- Zelda
- Terraria
- Hollow Knight

---

# Resultado esperado

Você verá:

✅ menu principal  
✅ gameplay  
✅ pause  
✅ game over  
✅ troca de cenas  
✅ arquitetura organizada  
✅ fluxo profissional  

---

# Atividade da Aula

## Exercício 1

Adicione:
- cena de vitória

---

## Exercício 2

Adicione:
- fade entre cenas

---

## Exercício 3

Crie:
- loading screen

---

## Exercício 4

Adicione:
- menu settings

---

# Desafio Extra

Crie:
- menu completo com botões

---

# Super Desafio

Crie:
- sistema completo de telas
- inventário
- loja
- mapa
- multiplayer lobby
- arquitetura profissional

---

# Próximo passo

Na próxima aula podemos evoluir para:

```text
25 - Game Architecture.md
```

onde iremos aprender:

- organização de projeto
- separação em arquivos
- modules
- engine architecture
- game loop profissional
- estrutura de jogos reais
