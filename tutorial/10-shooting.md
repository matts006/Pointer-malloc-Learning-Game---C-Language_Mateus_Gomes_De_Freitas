# 10 - Shooting

# Sistema de Tiros em Raylib (C)

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

Aprendemos:
- projéteis
- tiros
- lógica de shooting
- estados booleanos

---

# O que é bool

```c
bool shooting
```

Representa:
- verdadeiro
- falso

---

# Sistema de tiro

Quando:
```c
SPACE
```

é pressionado:
- tiro nasce
- sobe na tela

---

# Resultado esperado

Você verá:
- jogador azul
- tiros vermelhos

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Projectile | projétil |
| Shooting | sistema de tiro |
| Bool | verdadeiro/falso |
| Estado | situação atual |

---

# Desafio

## Desafio 1

Aumente velocidade do tiro.

## Desafio 2

Permita vários tiros.

## Desafio 3

Adicione som.

---

# Próximo passo

Na próxima etapa iremos aprender:
- inimigos
- IA simples
- movimentação automática
