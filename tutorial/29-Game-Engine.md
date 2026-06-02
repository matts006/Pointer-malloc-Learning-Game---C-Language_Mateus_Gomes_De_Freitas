# 29 - Game Engine

# Criando uma Mini Game Engine em C com Raylib

# Objetivo da Aula

Nesta aula iremos aprender a criar:

```text
uma mini game engine
```

Agora o projeto deixará de ser apenas:

```text
um jogo
```

e começará a se tornar:

```text
uma engine reutilizável
```

Vamos construir:

- engine loop
- renderer
- systems
- scene manager
- input manager
- asset manager
- arquitetura de engine
- núcleo reutilizável

Isso é a base de:
- engines reais
- frameworks
- engines 2D
- engines AAA

---

# O que iremos aprender

Nesta aula vamos estudar:

- engine architecture
- game loop profissional
- renderer
- systems
- modules
- scene graph
- managers
- arquitetura de engines
- organização profissional

---

# O que é uma Game Engine?

Uma engine é:

```text
o núcleo tecnológico do jogo
```

---

# O jogo usa a engine

```text
JOGO
↓
usa
↓
ENGINE
```

---

# O que a engine faz?

A engine normalmente controla:

| Sistema | Responsabilidade |
|---|---|
| renderer | renderização |
| input | teclado/mouse |
| audio | sons |
| physics | física |
| scenes | telas |
| assets | recursos |
| networking | multiplayer |

---

# Jogos famosos usam engines

| Jogo | Engine |
|---|---|
| Fortnite | Unreal |
| Terraria | Própria |
| Hollow Knight | Unity |
| Doom | id Tech |
| Minecraft | Java Engine |

---

# Estrutura Profissional

```text
mini_engine/
│
├── assets/
│
├── src/
│   ├── main.c
│   │
│   ├── engine/
│   │   ├── engine.c
│   │   ├── engine.h
│   │   ├── renderer.c
│   │   ├── renderer.h
│   │   ├── input.c
│   │   ├── input.h
│   │   ├── scene_manager.c
│   │   ├── scene_manager.h
│   │   ├── asset_manager.c
│   │   └── asset_manager.h
│   │
│   ├── game/
│   │   ├── player.c
│   │   ├── player.h
│   │   ├── enemy.c
│   │   └── enemy.h
│
└── README.md
```

---

# Arquitetura Geral

```text
GAME
↓
ENGINE API
↓
SYSTEMS
↓
RAYLIB
↓
OPENGL
↓
GPU
```

---

# Código Completo

# engine.h

```c
#ifndef ENGINE_H
#define ENGINE_H

// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"

// =========================================
// ENGINE FUNCTIONS
// =========================================

void EngineInit();

void EngineUpdate();

void EngineDraw();

void EngineClose();

#endif
```

---

# engine.c

```c
// =========================================
// IMPORTA ENGINE
// =========================================

#include "engine.h"

// =========================================
// IMPORTA SYSTEMS
// =========================================

#include "renderer.h"

#include "input.h"

#include "scene_manager.h"

#include "asset_manager.h"

// =========================================
// ENGINE INIT
// =========================================

void EngineInit()
{
    // Cria janela
    InitWindow(
        1280,
        720,
        "Mini Game Engine"
    );

    // FPS
    SetTargetFPS(60);

    // Inicializa systems
    RendererInit();

    InputInit();

    SceneManagerInit();

    AssetManagerInit();
}

// =========================================
// ENGINE UPDATE
// =========================================

void EngineUpdate()
{
    // Atualiza systems
    InputUpdate();

    SceneManagerUpdate();

    AssetManagerUpdate();
}

// =========================================
// ENGINE DRAW
// =========================================

void EngineDraw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    RendererDraw();

    EndDrawing();
}

// =========================================
// ENGINE CLOSE
// =========================================

void EngineClose()
{
    AssetManagerClose();

    CloseWindow();
}
```

---

# renderer.h

```c
#ifndef RENDERER_H
#define RENDERER_H

void RendererInit();

void RendererDraw();

#endif
```

---

# renderer.c

```c
#include "raylib.h"

#include "renderer.h"

// =========================================
// RENDERER INIT
// =========================================

void RendererInit()
{

}

// =========================================
// RENDERER DRAW
// =========================================

void RendererDraw()
{
    // =========================================
    // GRID DEBUG
    // =========================================

    for (int x = 0; x < 1280; x += 64)
    {
        DrawLine(
            x,
            0,
            x,
            720,
            LIGHTGRAY
        );
    }

    for (int y = 0; y < 720; y += 64)
    {
        DrawLine(
            0,
            y,
            1280,
            y,
            LIGHTGRAY
        );
    }

    // =========================================
    // TEXTO ENGINE
    // =========================================

    DrawText(
        "Mini Game Engine",
        20,
        20,
        40,
        DARKBLUE
    );

    DrawText(
        "Renderer System",
        20,
        80,
        20,
        MAROON
    );
}
```

---

# input.h

```c
#ifndef INPUT_H
#define INPUT_H

void InputInit();

void InputUpdate();

#endif
```

---

# input.c

```c
#include "raylib.h"

#include "input.h"

// =========================================
// INPUT INIT
// =========================================

void InputInit()
{

}

// =========================================
// INPUT UPDATE
// =========================================

void InputUpdate()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        TraceLog(
            LOG_INFO,
            "ESPACO PRESSIONADO"
        );
    }
}
```

---

# scene_manager.h

```c
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

void SceneManagerInit();

void SceneManagerUpdate();

#endif
```

---

# scene_manager.c

```c
#include "raylib.h"

#include "scene_manager.h"

// =========================================
// SCENES
// =========================================

typedef enum Scene
{
    MENU,
    GAMEPLAY

} Scene;

// =========================================
// CURRENT SCENE
// =========================================

static Scene currentScene;

// =========================================
// INIT
// =========================================

void SceneManagerInit()
{
    currentScene = MENU;
}

// =========================================
// UPDATE
// =========================================

void SceneManagerUpdate()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentScene = GAMEPLAY;
    }

    if (currentScene == MENU)
    {
        DrawText(
            "MENU",
            500,
            300,
            60,
            BLUE
        );
    }

    if (currentScene == GAMEPLAY)
    {
        DrawText(
            "GAMEPLAY",
            420,
            300,
            60,
            RED
        );
    }
}
```

---

# asset_manager.h

```c
#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

void AssetManagerInit();

void AssetManagerUpdate();

void AssetManagerClose();

#endif
```

---

# asset_manager.c

```c
#include "raylib.h"

#include "asset_manager.h"

// =========================================
// INIT
// =========================================

void AssetManagerInit()
{
    InitAudioDevice();
}

// =========================================
// UPDATE
// =========================================

void AssetManagerUpdate()
{

}

// =========================================
// CLOSE
// =========================================

void AssetManagerClose()
{
    CloseAudioDevice();
}
```

---

# main.c

```c
// =========================================
// IMPORTA ENGINE
// =========================================

#include "engine.h"

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Inicializa engine
    EngineInit();

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // Atualiza engine
        EngineUpdate();

        // Desenha engine
        EngineDraw();
    }

    // Fecha engine
    EngineClose();

    return 0;
}
```

---

# Explicação COMPLETA da Arquitetura

# 1. O que é uma engine?

Uma engine é:

```text
um conjunto de sistemas reutilizáveis
```

---

# O jogo usa a engine

```text
JOGO
↓
usa APIs da engine
```

---

# 2. EngineInit()

```c
EngineInit();
```

Inicializa:
- janela
- renderer
- input
- scenes
- assets

---

# Isso é bootstrap

A engine:
- prepara tudo

---

# 3. EngineUpdate()

```c
EngineUpdate();
```

Atualiza:
- systems

---

# Aqui acontece:

- input
- física
- IA
- networking

---

# 4. EngineDraw()

```c
EngineDraw();
```

Responsável por:
- renderização

---

# Fluxo profissional

```text
Update
↓
Render
```

---

# Isso separa lógica e desenho

Muito importante.

---

# 5. Renderer System

```c
RendererDraw();
```

Centraliza:
- renderização da engine

---

# Em engines reais

Renderer controla:
- OpenGL
- DirectX
- Vulkan
- shaders
- pipelines

---

# 6. Input System

```c
InputUpdate();
```

Centraliza:
- teclado
- mouse
- gamepad

---

# Isso evita

```text
input espalhado pelo projeto
```

---

# 7. Scene Manager

```c
SceneManagerUpdate();
```

Controla:
- telas
- estados
- fluxo do jogo

---

# 8. Asset Manager

```c
AssetManagerInit();
```

Controla:
- texturas
- sons
- músicas

---

# 9. Encapsulamento

Cada módulo:
- possui responsabilidade única

---

# Isso é MUITO importante

Sem isso:
- engine vira caos

---

# 10. Game Loop profissional

```c
while (!WindowShouldClose())
```

Agora:
- apenas coordena systems

---

# Isso é arquitetura moderna

---

# 11. Fluxo completo da engine

```text
MAIN
↓
ENGINE
│
├── INPUT
├── RENDERER
├── SCENES
├── AUDIO
└── ASSETS
```

---

# 12. Render Pipeline

Quando você faz:

```c
DrawText()
```

Internamente:

```text
CPU
↓
Raylib
↓
OpenGL
↓
GPU
↓
VRAM
↓
MONITOR
```

---

# 13. Engine modular

Agora:
- systems são independentes

---

# Isso permite

```text
escalar projeto
```

---

# 14. Engines reais

Grandes engines possuem:
- centenas de módulos

---

# Exemplos

| Sistema | Existe |
|---|---|
| Physics | ✔ |
| Animation | ✔ |
| AI | ✔ |
| Audio | ✔ |
| ECS | ✔ |
| Networking | ✔ |

---

# 15. Mini Engine

O que você criou aqui já é:

```text
uma mini game engine
```

Mesmo simples.

---

# Visualização mental

```text
ENGINE
│
├── Renderer
├── Input
├── Audio
├── Assets
├── Physics
├── ECS
└── Networking
```

---

# Conceitos profissionais aprendidos

| Conceito | Foi usado |
|---|---|
| Engine Architecture | ✔ |
| Renderer | ✔ |
| Input System | ✔ |
| Scene Manager | ✔ |
| Asset Manager | ✔ |
| Modularização | ✔ |
| Game Loop | ✔ |
| Encapsulamento | ✔ |

---

# O que você aprende de verdade

# você entende:

```text
uma engine é um conjunto de sistemas organizados
```

E entende:
- arquitetura de engines
- modularização
- systems
- render pipeline
- organização profissional
- estrutura usada em engines reais

---

# Curiosidade MUITO importante

Engines gigantes como:
- Unreal
- Unity
- Godot
- Frostbite

seguem exatamente esse conceito:

```text
systems independentes
↓
coordenados por uma engine central
```

---

# Resultado esperado

Você verá:

✅ mini engine funcionando  
✅ renderer system  
✅ input system  
✅ scene manager  
✅ asset manager  
✅ arquitetura modular  
✅ engine profissional básica  

---

# Atividade da Aula

## Exercício 1

Adicione:
- Physics System

---

## Exercício 2

Adicione:
- ECS System

---

## Exercício 3

Adicione:
- Networking System

---

## Exercício 4

Crie:
- Debug Console

---

# Desafio Extra

Crie:
- plugin system

---

# Super Desafio

Transforme isso em:
- engine 2D completa
- editor visual
- ECS engine
- scripting system
- Vulkan renderer
- engine profissional

---

# Próximo passo

Na próxima aula podemos evoluir para:

```text
30 - Shader Programming.md
```

onde iremos aprender:

- shaders
- GPU programming
- fragment shader
- vertex shader
- efeitos gráficos
- renderização moderna
