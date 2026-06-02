# 05 - Textures

# Trabalhando com Texturas em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Textures");

    Texture2D sprite = LoadTexture("player.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, 300, 200, WHITE);

        EndDrawing();
    }

    UnloadTexture(sprite);

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- texturas
- sprites
- imagens
- GPU
- VRAM
- carregamento de arquivos

Agora começamos a usar imagens reais dentro do jogo.

---

# Explicação linha por linha

## Criando a janela

```c
InitWindow(800, 600, "Textures");
```

Cria a janela principal do jogo.

---

# Carregando uma textura

```c
Texture2D sprite = LoadTexture("player.png");
```

Carrega a imagem:

```text
player.png
```

para memória da GPU.

---

# O que é Texture2D

```c
Texture2D
```

É um tipo da Raylib usado para representar imagens carregadas na memória gráfica.

---

# O que é uma textura

Uma textura é:

> uma imagem usada pela GPU para desenhar gráficos.

Exemplos:
- personagens
- inimigos
- cenários
- itens
- efeitos

---

# O que acontece internamente

Quando usamos:

```c
LoadTexture()
```

a Raylib:

1. lê o arquivo PNG
2. decodifica a imagem
3. cria uma textura na GPU
4. envia os pixels para VRAM

---

# O que é VRAM

VRAM significa:

```text
Video RAM
```

É a memória da placa de vídeo.

Ela armazena:
- texturas
- shaders
- buffers
- frames

---

# Loop principal

```c
while (!WindowShouldClose())
```

Executa continuamente:
- lógica
- renderização
- desenho da tela

---

# Iniciar renderização

```c
BeginDrawing();
```

Começa o frame atual.

---

# Limpar fundo

```c
ClearBackground(RAYWHITE);
```

Apaga o frame anterior.

---

# Desenhando a textura

```c
DrawTexture(sprite, 300, 200, WHITE);
```

Parâmetros:

| Valor | Significado |
|---|---|
| sprite | textura carregada |
| 300 | posição X |
| 200 | posição Y |
| WHITE | cor multiplicadora |

---

# Por que usar WHITE

```c
WHITE
```

significa:

> “não alterar as cores originais”.

---

# Finalizar renderização

```c
EndDrawing();
```

Entrega o frame para GPU mostrar na tela.

---

# Liberando textura

```c
UnloadTexture(sprite);
```

Libera a memória usada pela textura.

Muito importante.

Sem isso:
- vazamento de VRAM
- aumento de consumo
- travamentos

---

# Fechar janela

```c
CloseWindow();
```

Encerra corretamente.

---

# Fluxo visual do programa

```text
LoadTexture()

↓ LOOP

BeginDrawing()
    ↓
ClearBackground()
    ↓
DrawTexture()
    ↓
EndDrawing()

↓
UnloadTexture()
```

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Textura | imagem usada pela GPU |
| Sprite | imagem de personagem/objeto |
| VRAM | memória gráfica |
| LoadTexture | carregar imagem |
| DrawTexture | desenhar imagem |

---

# Resultado esperado

Você verá:

- uma imagem carregada
- desenhada no centro da tela

---

# Curiosidade

Praticamente todos os jogos 2D usam:
- sprites
- atlas de textura
- renderização por GPU

---

# Desafio

## Desafio 1

Troque:

```text
player.png
```

por outra imagem.

---

## Desafio 2

Desenhe duas imagens.

---

## Desafio 3

Mude a posição da textura.

---

## Desafio 4

Teste imagens maiores e menores.

---

# Próximo passo

Na próxima etapa iremos aprender:

- delta time
- tempo real
- movimento profissional

usando:

```c
GetFrameTime();
```
