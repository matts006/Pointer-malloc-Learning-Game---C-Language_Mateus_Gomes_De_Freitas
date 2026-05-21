# 11 - Enemies

# Criando Inimigos em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Enemies");

    int enemyX = 700;
    int direction = -1;

    while (!WindowShouldClose())
    {
        enemyX += direction * 5;

        if (enemyX <= 0 || enemyX >= 700)
        {
            direction *= -1;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(enemyX, 200, 100, 100, RED);

        DrawText("Enemy AI", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Aprendemos:
- inimigos
- IA básica
- movimentação automática
- direção

---

# Movimento automático

```c
enemyX += direction * 5;
```

Move inimigo sozinho.

---

# Troca de direção

```c
direction *= -1;
```

Inverte:
- esquerda
- direita

---

# Resultado esperado

Você verá:
- inimigo vermelho
- andando sozinho

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| AI | inteligência artificial |
| Direction | direção |
| Movimento automático | sem input |

---

# Desafio

## Desafio 1

Crie vários inimigos.

## Desafio 2

Velocidades diferentes.

## Desafio 3

Inimigos verticais.

---

# Próximo passo

Na próxima etapa iremos aprender:
- ponteiros
- malloc
- memória dinâmica
