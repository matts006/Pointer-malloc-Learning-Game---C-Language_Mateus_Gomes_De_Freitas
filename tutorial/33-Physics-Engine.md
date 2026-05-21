# 33 - Physics Engine

# Criando uma Physics Engine em Raylib (C)

# Objetivo da Aula

Nesta aula iremos aprender a criar:

```text
uma mini physics engine
```

Agora o projeto começará a possuir:

- gravidade
- forças
- velocidade
- aceleração
- impulso
- colisão física
- rigid bodies
- movimento realista

Isso é a base de:
- engines modernas
- física de jogos
- plataformas
- simuladores
- motores físicos

---

# O que iremos aprender

Nesta aula vamos estudar:

- física em jogos
- gravidade
- vetores
- velocidade
- aceleração
- forças
- rigid body
- impulso
- colisão física

---

# O que é Physics Engine?

Physics Engine é:

```text
sistema que simula física
```

---

# O mais importante

A física dos jogos é:

```text
matemática aplicada em tempo real
```

---

# O que uma physics engine faz?

Ela controla:

- gravidade
- colisão
- velocidade
- forças
- atrito
- impulso
- movimento realista

---

# Jogos usam física o tempo todo

| Jogo | Física |
|---|---|
| Angry Birds | ✔ |
| GTA V | ✔ |
| Minecraft | ✔ |
| Terraria | ✔ |
| Half-Life | ✔ |

---

# Motores físicos famosos

| Engine | Física |
|---|---|
| Box2D | 2D |
| Bullet | 3D |
| PhysX | NVIDIA |
| Havok | AAA |
| Chipmunk | 2D |

---

# Estrutura Física Básica

```text
FORÇA
↓
ACELERAÇÃO
↓
VELOCIDADE
↓
POSIÇÃO
```

---

# Código Completo

```c
// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"

// =========================================
// IMPORTA MATH
// =========================================

#include <math.h>

// =========================================
// RIGID BODY
// =========================================

typedef struct RigidBody
{
    // =====================================
    // POSIÇÃO
    // =====================================

    Vector2 position;

    // =====================================
    // VELOCIDADE
    // =====================================

    Vector2 velocity;

    // =====================================
    // ACELERAÇÃO
    // =====================================

    Vector2 acceleration;

    // =====================================
    // MASSA
    // =====================================

    float mass;

    // =====================================
    // TAMANHO
    // =====================================

    float size;

    // =====================================
    // CHÃO
    // =====================================

    bool grounded;

} RigidBody;

// =========================================
// APLICA FORÇA
// =========================================

void ApplyForce(
    RigidBody *body,
    Vector2 force)
{
    // =====================================
    // F = m * a
    // =====================================

    body->acceleration.x +=
        force.x / body->mass;

    body->acceleration.y +=
        force.y / body->mass;
}

// =========================================
// UPDATE PHYSICS
// =========================================

void UpdatePhysics(
    RigidBody *body,
    float delta)
{
    // =====================================
    // VELOCIDADE
    // =====================================

    body->velocity.x +=
        body->acceleration.x *
        delta;

    body->velocity.y +=
        body->acceleration.y *
        delta;

    // =====================================
    // POSIÇÃO
    // =====================================

    body->position.x +=
        body->velocity.x *
        delta;

    body->position.y +=
        body->velocity.y *
        delta;

    // =====================================
    // RESET ACCELERATION
    // =====================================

    body->acceleration =
        (Vector2){0, 0};

    // =====================================
    // COLISÃO CHÃO
    // =====================================

    float groundY = 620;

    if (body->position.y + body->size >
        groundY)
    {
        body->position.y =
            groundY - body->size;

        body->velocity.y = 0;

        body->grounded = true;
    }
    else
    {
        body->grounded = false;
    }
}

// =========================================
// MAIN
// =========================================

int main(void)
{
    // =========================================
    // CRIA JANELA
    // =========================================

    InitWindow(
        1280,
        720,
        "Physics Engine"
    );

    // FPS
    SetTargetFPS(60);

    // =========================================
    // PLAYER BODY
    // =========================================

    RigidBody player;

    player.position =
        (Vector2){300, 200};

    player.velocity =
        (Vector2){0, 0};

    player.acceleration =
        (Vector2){0, 0};

    player.mass = 1.0f;

    player.size = 50;

    player.grounded = false;

    // =========================================
    // GRAVIDADE
    // =========================================

    Vector2 gravity =
        {0, 980};

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // DELTA TIME
        // =========================================

        float delta =
            GetFrameTime();

        // =========================================
        // APLICA GRAVIDADE
        // =========================================

        ApplyForce(
            &player,
            gravity
        );

        // =========================================
        // MOVIMENTO HORIZONTAL
        // =========================================

        if (IsKeyDown(KEY_RIGHT))
        {
            ApplyForce(
                &player,
                (Vector2){600, 0}
            );
        }

        if (IsKeyDown(KEY_LEFT))
        {
            ApplyForce(
                &player,
                (Vector2){-600, 0}
            );
        }

        // =========================================
        // PULO
        // =========================================

        if (IsKeyPressed(KEY_SPACE) &&
            player.grounded)
        {
            player.velocity.y =
                -500;
        }

        // =========================================
        // ATRITO
        // =========================================

        player.velocity.x *= 0.90f;

        // =========================================
        // UPDATE PHYSICS
        // =========================================

        UpdatePhysics(
            &player,
            delta
        );

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // =========================================
        // CHÃO
        // =========================================

        DrawRectangle(
            0,
            620,
            1280,
            100,
            DARKGREEN
        );

        // =========================================
        // PLAYER
        // =========================================

        DrawRectangleV(
            player.position,
            (Vector2)
            {
                player.size,
                player.size
            },
            BLUE
        );

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(
            0,
            0,
            1280,
            160,
            Fade(BLACK, 0.5f)
        );

        DrawText(
            "Physics Engine",
            20,
            20,
            40,
            WHITE
        );

        DrawText(
            "Setas = mover",
            20,
            70,
            20,
            WHITE
        );

        DrawText(
            "ESPACO = pular",
            20,
            100,
            20,
            WHITE
        );

        DrawText(
            TextFormat(
                "Velocidade X: %.2f",
                player.velocity.x
            ),
            400,
            70,
            20,
            YELLOW
        );

        DrawText(
            TextFormat(
                "Velocidade Y: %.2f",
                player.velocity.y
            ),
            400,
            100,
            20,
            YELLOW
        );

        DrawText(
            TextFormat(
                "Grounded: %s",
                player.grounded ?
                "TRUE" :
                "FALSE"
            ),
            800,
            100,
            20,
            SKYBLUE
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

# 1. O que é física em jogos?

Física em jogos é:

```text
simulação matemática de movimento
```

---

# Isso inclui

- gravidade
- colisão
- velocidade
- forças
- impulso

---

# 2. RigidBody

```c
typedef struct RigidBody
```

Representa:
- corpo físico

---

# Um rigid body possui

| Campo | Função |
|---|---|
| position | posição |
| velocity | velocidade |
| acceleration | aceleração |
| mass | massa |
| grounded | está no chão |

---

# 3. Velocity

```c
velocity
```

Representa:

```text
velocidade do objeto
```

---

# Fórmula da velocidade

:contentReference[oaicite:0]{index=0}

---

# 4. Acceleration

```c
acceleration
```

Representa:

```text
mudança de velocidade
```

---

# Fórmula da aceleração

:contentReference[oaicite:1]{index=1}

---

# 5. ApplyForce()

```c
ApplyForce()
```

Aplica:
- força física

---

# Lei de Newton

A função usa:

:contentReference[oaicite:2]{index=2}

---

# Reorganizando fórmula

:contentReference[oaicite:3]{index=3}

---

# Isso significa

Mais força:
- mais aceleração

Mais massa:
- menos aceleração

---

# 6. Gravidade

```c
Vector2 gravity = {0, 980};
```

Representa:
- aceleração gravitacional

---

# O eixo Y cresce para baixo

Por isso:
- gravidade é positiva

---

# 7. Delta Time

```c
GetFrameTime()
```

Retorna:
- tempo entre frames

---

# Isso é MUITO importante

Sem delta:
- física dependeria do FPS

---

# 8. Atualização da velocidade

```c
velocity += acceleration * delta
```

---

# Fórmula real

:contentReference[oaicite:4]{index=4}

---

# 9. Atualização da posição

```c
position += velocity * delta
```

---

# Fórmula usada

:contentReference[oaicite:5]{index=5}

---

# Isso cria movimento físico

---

# 10. Reset acceleration

```c
acceleration = {0,0}
```

Muito importante.

---

# Por quê?

Forças precisam ser:
- reaplicadas continuamente

---

# Isso imita física real

---

# 11. Ground Collision

```c
if (position.y + size > groundY)
```

Detecta:
- colisão com chão

---

# Então:

- corrige posição
- zera velocidade
- ativa grounded

---

# 12. Grounded

```c
grounded = true
```

Indica:
- objeto está no chão

---

# Isso permite

- pulo
- atrito
- física correta

---

# 13. Jump

```c
velocity.y = -500;
```

Aplica:
- impulso instantâneo

---

# Isso é impulso físico

---

# Fórmula do impulso

:contentReference[oaicite:6]{index=6}

---

# 14. Atrito

```c
velocity.x *= 0.90f;
```

Reduz:
- velocidade horizontal

---

# Isso simula resistência

---

# 15. Physics Loop

Fluxo da física:

```text
FORÇAS
↓
ACELERAÇÃO
↓
VELOCIDADE
↓
POSIÇÃO
↓
COLISÃO
```

---

# Visualização mental

```text
GRAVIDADE
↓
BODY CAI
↓
COLIDE CHÃO
↓
VELOCIDADE ZERA
```

---

# 16. Física moderna

Motores físicos modernos possuem:
- rigid bodies
- constraints
- joints
- friction
- restitution
- CCD

---

# 17. Continuous Collision Detection

Jogos modernos usam:

```text
CCD
```

para evitar:
- atravessar paredes

---

# 18. Física em engines reais

| Engine | Física |
|---|---|
| Unity | PhysX |
| Unreal | Chaos |
| Godot | Godot Physics |
| Source | Havok |

---

# 19. Matemática da física

Grande parte da física em jogos usa:
- álgebra vetorial
- cálculo
- trigonometria
- integração numérica

---

# 20. Euler Integration

Nosso sistema usa:

```text
Euler Integration
```

---

# Fórmula

:contentReference[oaicite:7]{index=7}

---

# Isso é a forma mais simples de integração física

---

# Conceitos profissionais aprendidos

| Conceito | Foi usado |
|---|---|
| Physics Engine | ✔ |
| RigidBody | ✔ |
| Gravidade | ✔ |
| Forças | ✔ |
| Velocidade | ✔ |
| Aceleração | ✔ |
| Impulso | ✔ |
| Colisão Física | ✔ |

---

# O que você aprende de verdade

# você entende:

```text
física de jogos é matemática executada em tempo real
```

E entende:
- forças
- gravidade
- rigid bodies
- impulso
- colisão física
- física moderna de engines

---

# Curiosidade MUITO importante

Mesmo engines AAA ainda usam:
- integração numérica
- rigid bodies
- vetores
- forças

Porque:
- física real é extremamente cara computacionalmente

---

# Resultado esperado

Você verá:

✅ gravidade funcionando  
✅ pulo funcionando  
✅ colisão física  
✅ rigid body  
✅ física baseada em forças  
✅ movimento realista  

---

# Atividade da Aula

## Exercício 1

Adicione:
- múltiplas plataformas

---

## Exercício 2

Adicione:
- caixas físicas

---

## Exercício 3

Adicione:
- colisão entre objetos

---

## Exercício 4

Adicione:
- elasticidade

---

# Desafio Extra

Crie:
- rope physics

---

# Super Desafio

Transforme isso em:
- mini Box2D
- ragdoll physics
- verlet integration
- soft bodies
- fluid simulation
- physics engine completa

---

# Próximo passo

Na próxima aula podemos evoluir para:

```text
34 - 3D Programming.md
```

onde iremos aprender:

- gráficos 3D
- câmera 3D
- meshes
- iluminação 3D
- mundo tridimensional
- fundamentos de engines 3D
