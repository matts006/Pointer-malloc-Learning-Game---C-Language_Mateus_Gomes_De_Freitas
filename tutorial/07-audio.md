# 07 - Audio

# Trabalhando com Áudio em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Audio");

    InitAudioDevice();

    Sound sound = LoadSound("tiro.wav");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(sound);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Pressione ESPACO para tocar som", 120, 250, 20, BLACK);

        EndDrawing();
    }

    UnloadSound(sound);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- áudio
- efeitos sonoros
- teclado
- eventos
- interação do jogador

Agora o jogo começa realmente a ficar vivo.

---

# Explicação linha por linha

## Inicializando áudio

```c
InitAudioDevice();
```

Liga o sistema de áudio.

Sem isso:
- nenhum som funciona

---

# Carregando som

```c
Sound sound = LoadSound("tiro.wav");
```

Carrega o arquivo:

```text
tiro.wav
```

para memória.

---

# O que é WAV

WAV é um formato de áudio.

Muito usado em:
- jogos
- efeitos sonoros
- engines

---

# Detectando teclado

```c
IsKeyPressed(KEY_SPACE)
```

Verifica:

> “a tecla espaço foi pressionada?”

---

# Tocando som

```c
PlaySound(sound);
```

Executa o efeito sonoro.

---

# O que acontece internamente

A Raylib:

1. lê arquivo WAV
2. carrega áudio na memória
3. envia para sistema de som
4. placa de áudio reproduz

---

# Desenhando texto

```c
DrawText(...)
```

Mostra instruções para jogador.

---

# Liberando som

```c
UnloadSound(sound);
```

Libera memória usada pelo áudio.

---

# Fechando sistema de áudio

```c
CloseAudioDevice();
```

Encerra corretamente o sistema de som.

---

# Resultado esperado

Você verá:
- texto na tela

Ao apertar:
- ESPAÇO

o som será reproduzido.

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Sound | efeito sonoro |
| WAV | formato de áudio |
| Evento | ação disparada |
| Input | entrada do jogador |
| Áudio digital | reprodução sonora |

---

# Curiosidade

Jogos modernos usam:
- mixagem em tempo real
- áudio espacial
- reverberação
- múltiplos canais
- compressão de áudio

---

# Desafio

## Desafio 1

Troque:

```text
tiro.wav
```

por outro som.

---

## Desafio 2

Toque som usando:
- ENTER
- ESC
- tecla A

---

## Desafio 3

Adicione música:

```c
Music music = LoadMusicStream(...);
```

---

## Desafio 4

Toque sons diferentes para teclas diferentes.

---

# Próximo passo

Agora você já possui:
- janela
- renderização
- movimento
- FPS
- delta time
- texturas
- áudio

Você já consegue criar:
- mini games
- shooters
- jogos arcade
- plataformas simples
