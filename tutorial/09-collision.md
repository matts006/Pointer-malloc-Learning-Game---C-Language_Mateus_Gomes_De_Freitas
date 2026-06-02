# 09 - Collision

# Trabalhando com Colisão em Raylib (C)

```c
#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Collision");

    Rectangle player = {100, 200, 100, 100};
    Rectangle enemy = {500, 200, 100, 100};

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) player.x += 5;
        if (IsKeyDown(KEY_LEFT)) player.x -= 5;

        bool collision = CheckCollisionRecs(player, enemy);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangleRec(player, BLUE);

        if (collision)
            DrawRectangleRec(enemy, RED);
        else
            DrawRectangleRec(enemy, GREEN);

        DrawText("Encoste no bloco", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```

---

# O que foi adicionado nesta etapa

Nesta etapa aprendemos:

- colisão
- hitbox
- Rectangle
- interação entre objetos
- detecção espacial
- lógica condicional

Agora o jogo consegue detectar contato entre elementos.

---

# Explicação linha por linha

# Importando a Raylib

```c
#include "raylib.h"
```

Importa:
- renderização
- input
- colisão
- estruturas gráficas

---

# Função principal

```c
int main()
```

Ponto inicial do programa.

---

# Criando janela

```c
InitWindow(800, 600, "Collision");
```

Cria:
- janela
- sistema gráfico
- contexto de renderização

---

# Estrutura Rectangle

```c
Rectangle player = {100, 200, 100, 100};
```

Criamos um objeto do tipo:

```c
Rectangle
```

---

# O que existe dentro de Rectangle

Internamente é parecido com:

```c
typedef struct Rectangle
{
    float x;
    float y;
    float width;
    float height;
} Rectangle;
```

Ou seja:
- posição X
- posição Y
- largura
- altura

Tudo armazenado em memória.

---

# Criando jogador

```c
Rectangle player = {100, 200, 100, 100};
```

Parâmetros:

| Valor | Significado |
|---|---|
| 100 | posição X |
| 200 | posição Y |
| 100 | largura |
| 100 | altura |

---

# Criando inimigo

```c
Rectangle enemy = {500, 200, 100, 100};
```

Cria:
- segundo objeto
- que servirá para colisão

---

# Loop principal

```c
while (!WindowShouldClose())
```

Executa continuamente:
- input
- lógica
- colisão
- renderização

---

# Movendo jogador

```c
if (IsKeyDown(KEY_RIGHT)) player.x += 5;
```

Aqui acontece algo MUITO importante:

```c
player.x
```

significa:

```text
acessar o campo x da struct player
```

---

# O que acontece internamente

Quando fazemos:

```c
player.x += 5;
```

o programa:
- acessa memória RAM
- altera valor armazenado
- atualiza posição do objeto

Isso já começa a preparar:
- ponteiros
- structs
- memória dinâmica

---

# Movimento para esquerda

```c
if (IsKeyDown(KEY_LEFT)) player.x -= 5;
```

Diminui posição horizontal.

---

# Detectando colisão

```c
bool collision = CheckCollisionRecs(player, enemy);
```

A Raylib verifica:

```text
“os dois retângulos estão se tocando?”
```

Se estiverem:
- retorna `true`

Senão:
- retorna `false`

---

# O que é bool

```c
bool
```

Representa:

| Valor | Significado |
|---|---|
| true | verdadeiro |
| false | falso |

---

# O que é hitbox

Hitbox é:

> uma área invisível usada para detectar colisão.

Muitos jogos usam:
- retângulos invisíveis
- círculos invisíveis
- polígonos

para detectar:
- dano
- contato
- tiros
- física

---

# Começando renderização

```c
BeginDrawing();
```

Inicia o frame atual.

---

# Limpando tela

```c
ClearBackground(RAYWHITE);
```

Apaga frame anterior.

---

# Desenhando jogador

```c
DrawRectangleRec(player, BLUE);
```

Desenha:
- Rectangle inteiro

usando:
- posição
- largura
- altura

da struct.

---

# O que significa Rec

```text
Rec = Rectangle
```

---

# Lógica condicional

```c
if (collision)
```

Significa:

```text
“se houver colisão”
```

---

# Mudando cor ao colidir

```c
DrawRectangleRec(enemy, RED);
```

Quando colide:
- inimigo fica vermelho

---

# Sem colisão

```c
DrawRectangleRec(enemy, GREEN);
```

Quando NÃO colide:
- inimigo fica verde

---

# O que é feedback visual

O jogador:
- vê mudança de cor
- entende interação
- percebe colisão

Isso é chamado:

```text
feedback visual
```

Muito importante em jogos.

---

# Desenhando texto

```c
DrawText("Encoste no bloco", 10, 10, 20, BLACK);
```

Mostra instruções na tela.

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
Move player
   ↓
CheckCollisionRecs()
   ↓
if(collision)
   ↓
Muda cor
   ↓
Renderiza frame
```

---

# O que acontece internamente

A cada frame:

1. jogador move
2. CPU compara retângulos
3. Raylib calcula interseção
4. GPU desenha resultado
5. monitor exibe atualização

Tudo isso ocorre:
- dezenas de vezes por segundo

---

# Como colisão funciona matematicamente

A Raylib compara:

```text
esquerda
direita
topo
base
```

dos retângulos.

Se as áreas se sobrepõem:
- há colisão

---

# Conceito novo aprendido

| Conceito | Explicação |
|---|---|
| Collision | detecção de contato |
| Hitbox | área invisível |
| Rectangle | estrutura geométrica |
| Bool | verdadeiro/falso |
| Struct | agrupamento de dados |

---

# Curiosidade MUITO importante

Quase todos os jogos usam:
- colisão simplificada
- hitbox invisível
- matemática espacial

Mesmo jogos AAA usam:
- caixas invisíveis
- volumes de colisão
- bounding boxes

---

# Resultado esperado

Você verá:

- jogador azul
- inimigo verde
- quando encostar:
  - inimigo fica vermelho

---

# Desafio

## Desafio 1

Permita:
- movimento vertical

---

## Desafio 2

Adicione:
- múltiplos inimigos

---

## Desafio 3

Mostre:

```text
COLIDIU!
```

na tela.

---

## Desafio 4

Faça:
- inimigo mover automaticamente

---

## Super Desafio

Crie:
- sistema de pontuação
- ao colidir:
  - ganha ponto

---

# Próximo passo

Na próxima etapa iremos aprender:

- tiros
- projéteis
- shooting system

usando:

```c
bool shooting;
```
