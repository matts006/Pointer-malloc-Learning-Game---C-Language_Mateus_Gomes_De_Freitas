# 06 - Delta Time

# Movimento Profissional com Delta Time em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Delta Time");

    SetTargetFPS(60);

    float x = 0;
    float velocidade = 300;

    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        x += velocidade * delta;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle((int)x, 250, 100, 100, BLUE);

        DrawFPS(700, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- delta time
- tempo real
- movimento independente de FPS
- física básica
- velocidade profissional

Agora o jogo funciona corretamente em qualquer computador.

---

# Explicação linha por linha

## Definir FPS

```c
SetTargetFPS(60);
```

Tenta manter:
- 60 frames por segundo

---

# Variáveis de movimento

```c
float x = 0;
float velocidade = 300;
```

## x

Guarda posição horizontal.

## velocidade

Representa:

```text
300 pixels por segundo
```

---

# Por que usar float

```c
float
```

permite:
- números quebrados
- maior precisão
- movimento suave

---

# Capturando Delta Time

```c
float delta = GetFrameTime();
```

Retorna:
- tempo entre um frame e outro

Exemplo:

```text
0.016
```

aproximadamente:
- 16 milissegundos

---

# Movimento profissional

```c
x += velocidade * delta;
```

Agora o movimento depende:
- do tempo real
- e não do FPS

---

# Problema antigo

Antes fazíamos:

```c
x += 2;
```

Problema:
- PCs rápidos → jogo rápido
- PCs lentos → jogo lento

---

# Solução correta

Agora usamos:

```c
velocidade * delta
```

Isso gera:

```text
movimento consistente
```

em qualquer computador.

---

# O que acontece internamente

A Raylib:

1. mede tempo do frame
2. calcula delta
3. atualiza posição
4. sincroniza movimento

---

# DrawRectangle

```c
DrawRectangle((int)x, 250, 100, 100, BLUE);
```

Convertemos:

```c
(int)x
```

porque:
- DrawRectangle usa inteiros

---

# Mostrar FPS

```c
DrawFPS(700, 10);
```

Mostra FPS atual na tela.

---

# Resultado esperado

Você verá:
- quadrado azul
- movimento suave
- FPS estável

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Delta Time | tempo entre frames |
| Float | número decimal |
| Movimento temporal | baseado em segundos |
| FPS independente | velocidade consistente |

---

# Curiosidade

Engines profissionais como:
- Unity
- Unreal
- Godot

também usam delta time.

---

# Desafio

## Desafio 1

Teste:

```c
SetTargetFPS(30);
```

Veja:
- movimento continua correto

---

## Desafio 2

Aumente velocidade:

```c
float velocidade = 600;
```

---

## Desafio 3

Crie dois objetos:
- velocidades diferentes
- cores diferentes

---

## Desafio 4

Faça o quadrado voltar ao início da tela.

---

# Próximo passo

Na próxima etapa iremos aprender:
- áudio
- música
- efeitos sonoros

usando:

```c
PlaySound();
```
