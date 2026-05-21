# 08 - Input

# Trabalhando com Input de Teclado em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Keyboard Input");

    int x = 350;
    int y = 250;
    int velocidade = 5;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) x += velocidade;
        if (IsKeyDown(KEY_LEFT)) x -= velocidade;
        if (IsKeyDown(KEY_UP)) y -= velocidade;
        if (IsKeyDown(KEY_DOWN)) y += velocidade;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(x, y, 100, 100, BLUE);

        DrawText("Use as setas do teclado", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- teclado
- input
- interação
- controle do jogador
- movimentação manual

Agora o jogador controla o objeto.

---

# O que é input

Input significa:

> entrada de dados do jogador.

Exemplos:
- teclado
- mouse
- joystick
- touchscreen

---

# Detectando teclas

```c
IsKeyDown(KEY_RIGHT)
```

Verifica:
- se a tecla está pressionada.

---

# Movimento

```c
x += velocidade;
```

Move o quadrado para direita.

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Input | entrada do jogador |
| KEY_RIGHT | seta direita |
| KEY_LEFT | seta esquerda |
| Controle | movimentação manual |

---

# Resultado esperado

Você verá:
- quadrado azul
- movimentação pelas setas

---

# Desafio

## Desafio 1

Mude velocidade.

## Desafio 2

Troque cor.

## Desafio 3

Adicione limite de tela.

---

# Próximo passo

Na próxima etapa iremos aprender:
- colisão
- hitbox
- detecção entre objetos
