# 16 - Partículas

# Criando Sistema de Partículas em Raylib (C)

# Objetivo da Aula

Nesta aula iremos aprender a criar um:

```text
sistema de partículas
```

Partículas são pequenos elementos visuais usados para criar efeitos como:

- explosões
- fumaça
- poeira
- fogo
- faíscas
- magia
- estrelas
- impacto de tiro
- coleta de itens

Em jogos, partículas são usadas para dar:

- feedback visual
- sensação de impacto
- movimento
- vida ao cenário
- polimento visual

---

# O que iremos aprender

Nesta aula vamos criar:

- struct de partícula
- várias partículas na tela
- posição
- velocidade
- tempo de vida
- ativação e desativação
- explosão simples
- efeito ao pressionar uma tecla
- renderização de partículas

---

# O que são partículas?

Uma partícula é um pequeno objeto visual.

Normalmente ela possui:

| Propriedade | Função |
|---|---|
| posição | onde a partícula está |
| velocidade | para onde ela se move |
| tamanho | tamanho visual |
| tempo de vida | quanto tempo ela dura |
| ativa | se ela aparece ou não |
| cor | aparência visual |

---

# Exemplo simples

Imagine uma explosão:

```text
        *
    *       *
  *    X      *
    *       *
        *
```

O `X` é o ponto da explosão.

Os `*` são partículas indo para várias direções.

---

# Código Completo

```c
// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"

// =========================================
// CONSTANTES
// =========================================

// Define quantidade máxima de partículas
#define MAX_PARTICULAS 100

// =========================================
// STRUCT PARTICULA
// =========================================

// Cria a estrutura da partícula
typedef struct Particula
{
    // Posição da partícula
    Vector2 posicao;

    // Velocidade da partícula
    Vector2 velocidade;

    // Tamanho da partícula
    float tamanho;

    // Tempo de vida da partícula
    float tempoVida;

    // Indica se a partícula está ativa
    bool ativa;

    // Cor da partícula
    Color cor;

} Particula;

// =========================================
// FUNÇÃO PARA CRIAR EXPLOSÃO
// =========================================

void CriarExplosao(Particula particulas[], Vector2 origem)
{
    // Percorre todas as partículas disponíveis
    for (int i = 0; i < MAX_PARTICULAS; i++)
    {
        // Ativa somente partículas livres
        if (!particulas[i].ativa)
        {
            // Ativa a partícula
            particulas[i].ativa = true;

            // Define origem da partícula
            particulas[i].posicao = origem;

            // Define velocidade aleatória em X
            particulas[i].velocidade.x = GetRandomValue(-200, 200) / 100.0f;

            // Define velocidade aleatória em Y
            particulas[i].velocidade.y = GetRandomValue(-200, 200) / 100.0f;

            // Define tamanho aleatório
            particulas[i].tamanho = GetRandomValue(3, 8);

            // Define tempo de vida
            particulas[i].tempoVida = 1.0f;

            // Define cor
            particulas[i].cor = ORANGE;
        }
    }
}

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Cria janela
    InitWindow(1000, 600, "Particulas em Raylib");

    // Define FPS
    SetTargetFPS(60);

    // Cria vetor de partículas
    Particula particulas[MAX_PARTICULAS] = { 0 };

    // Posição inicial da explosão
    Vector2 origem = { 500, 300 };

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // UPDATE
        // =========================================

        // Captura delta time
        float delta = GetFrameTime();

        // Se apertar ESPAÇO, cria explosão
        if (IsKeyPressed(KEY_SPACE))
        {
            CriarExplosao(particulas, origem);
        }

        // Move origem com o mouse
        origem = GetMousePosition();

        // Atualiza partículas
        for (int i = 0; i < MAX_PARTICULAS; i++)
        {
            // Só atualiza partículas ativas
            if (particulas[i].ativa)
            {
                // Move partícula no eixo X
                particulas[i].posicao.x += particulas[i].velocidade.x * 100 * delta;

                // Move partícula no eixo Y
                particulas[i].posicao.y += particulas[i].velocidade.y * 100 * delta;

                // Reduz tempo de vida
                particulas[i].tempoVida -= delta;

                // Reduz tamanho aos poucos
                particulas[i].tamanho -= delta * 3;

                // Se acabou o tempo de vida
                if (particulas[i].tempoVida <= 0 || particulas[i].tamanho <= 0)
                {
                    // Desativa partícula
                    particulas[i].ativa = false;
                }
            }
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        // Fundo
        ClearBackground(RAYWHITE);

        // Título
        DrawText(
            "Sistema de Particulas",
            20,
            20,
            30,
            DARKBLUE
        );

        // Instrução
        DrawText(
            "Mova o mouse e pressione ESPACO para criar explosao",
            20,
            60,
            20,
            DARKGRAY
        );

        // Desenha origem
        DrawCircleV(
            origem,
            8,
            RED
        );

        // Desenha partículas
        for (int i = 0; i < MAX_PARTICULAS; i++)
        {
            // Só desenha partículas ativas
            if (particulas[i].ativa)
            {
                DrawCircleV(
                    particulas[i].posicao,
                    particulas[i].tamanho,
                    particulas[i].cor
                );
            }
        }

        // Texto inferior
        DrawText(
            "Particulas = posicao + velocidade + tempo de vida",
            20,
            560,
            18,
            MAROON
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

# 1. O que é um sistema de partículas?

Um sistema de partículas é um conjunto de pequenos objetos visuais que aparecem, se movem e desaparecem.

Em vez de desenhar uma explosão como uma única imagem, podemos criar várias pequenas partículas.

Cada partícula tem vida própria:

```text
nasce
↓
se move
↓
perde força
↓
desaparece
```

---

# 2. Por que usar partículas?

Partículas dão sensação de:

- impacto
- explosão
- energia
- magia
- movimento
- feedback visual

Sem partículas, o jogo pode parecer “seco”.

Com partículas, o jogador sente melhor as ações.

---

# 3. Constante MAX_PARTICULAS

```c
#define MAX_PARTICULAS 100
```

Essa linha define:

```text
quantidade máxima de partículas
```

Neste exemplo, podemos ter até:

```text
100 partículas
```

na tela.

---

# Por que usar constante?

Porque facilita alteração.

Se quiser mais partículas:

```c
#define MAX_PARTICULAS 300
```

Mas cuidado:

```text
mais partículas = mais processamento
```

---

# 4. Struct Particula

```c
typedef struct Particula
```

Criamos um tipo personalizado chamado:

```text
Particula
```

---

# Campos da Particula

```c
Vector2 posicao;
Vector2 velocidade;
float tamanho;
float tempoVida;
bool ativa;
Color cor;
```

---

# O que cada campo faz

| Campo | Função |
|---|---|
| posicao | onde a partícula está |
| velocidade | para onde ela anda |
| tamanho | tamanho do círculo |
| tempoVida | quanto tempo ela existe |
| ativa | se está aparecendo |
| cor | cor visual |

---

# 5. Por que usar Vector2?

```c
Vector2
```

é uma struct da Raylib com:

```c
float x;
float y;
```

Usamos `Vector2` para representar:

- posição
- direção
- velocidade

---

# 6. Vetor de partículas

```c
Particula particulas[MAX_PARTICULAS] = { 0 };
```

Criamos um array com várias partículas.

O `{ 0 }` inicializa tudo com zero.

Isso ajuda porque:

- `ativa` começa como falso
- posição começa zerada
- tamanho começa zerado

---

# 7. Função CriarExplosao

```c
void CriarExplosao(Particula particulas[], Vector2 origem)
```

Essa função cria partículas no ponto da explosão.

Ela recebe:

| Parâmetro | Função |
|---|---|
| particulas[] | array de partículas |
| origem | posição da explosão |

---

# 8. Por que função separada?

Porque melhora organização.

Em vez de colocar tudo dentro do `main`, criamos uma função específica.

Isso facilita:

- leitura
- manutenção
- reutilização
- evolução do jogo

---

# 9. Ativando partículas

```c
if (!particulas[i].ativa)
```

Essa condição procura partículas livres.

Ou seja:

```text
partículas que não estão sendo usadas
```

---

# O que significa !

```c
!
```

significa:

```text
NÃO
```

Então:

```c
!particulas[i].ativa
```

significa:

```text
se a partícula NÃO está ativa
```

---

# 10. Posição inicial da partícula

```c
particulas[i].posicao = origem;
```

Toda partícula começa no ponto da explosão.

---

# 11. Velocidade aleatória

```c
particulas[i].velocidade.x = GetRandomValue(-200, 200) / 100.0f;
particulas[i].velocidade.y = GetRandomValue(-200, 200) / 100.0f;
```

Cada partícula recebe uma velocidade diferente.

Isso faz com que elas se espalhem para várias direções.

---

# Por que dividir por 100.0f?

Para transformar valores grandes em valores menores.

Exemplo:

```text
200 / 100.0 = 2.0
```

Assim a velocidade fica em uma faixa controlada:

```text
-2.0 até 2.0
```

---

# 12. Tamanho aleatório

```c
particulas[i].tamanho = GetRandomValue(3, 8);
```

Cada partícula nasce com tamanho diferente.

Isso deixa o efeito mais natural.

---

# 13. Tempo de vida

```c
particulas[i].tempoVida = 1.0f;
```

Cada partícula viverá aproximadamente:

```text
1 segundo
```

---

# 14. Cor da partícula

```c
particulas[i].cor = ORANGE;
```

Neste exemplo, usamos:

```text
laranja
```

porque combina com explosão.

---

# 15. Capturando delta time

```c
float delta = GetFrameTime();
```

O delta time permite que o movimento das partículas seja baseado no tempo.

Isso deixa o efeito mais consistente em diferentes computadores.

---

# 16. Criando explosão com ESPAÇO

```c
if (IsKeyPressed(KEY_SPACE))
{
    CriarExplosao(particulas, origem);
}
```

Quando o jogador aperta espaço:

```text
nasce uma explosão
```

---

# 17. Usando mouse como origem

```c
origem = GetMousePosition();
```

A explosão aparece onde o mouse estiver.

Isso torna a aula mais interativa.

---

# 18. Atualizando partículas

```c
for (int i = 0; i < MAX_PARTICULAS; i++)
```

Percorremos todas as partículas.

---

# 19. Atualizar apenas partículas ativas

```c
if (particulas[i].ativa)
```

Só mexemos nas partículas que existem visualmente.

---

# 20. Movimento da partícula

```c
particulas[i].posicao.x += particulas[i].velocidade.x * 100 * delta;
particulas[i].posicao.y += particulas[i].velocidade.y * 100 * delta;
```

A posição muda com base em:

```text
velocidade × tempo
```

Esse é o mesmo princípio usado em movimento profissional.

---

# 21. Reduzindo tempo de vida

```c
particulas[i].tempoVida -= delta;
```

A cada frame, a partícula perde tempo de vida.

Quando chega a zero:

```text
a partícula desaparece
```

---

# 22. Reduzindo tamanho

```c
particulas[i].tamanho -= delta * 3;
```

A partícula vai diminuindo com o tempo.

Isso cria sensação de:

- dissipação
- desaparecimento
- explosão se apagando

---

# 23. Desativando partículas

```c
if (particulas[i].tempoVida <= 0 || particulas[i].tamanho <= 0)
{
    particulas[i].ativa = false;
}
```

Se o tempo acabou ou o tamanho ficou zero:

```text
a partícula deixa de existir visualmente
```

---

# O que significa ||

```c
||
```

significa:

```text
OU
```

Então:

```c
tempoVida <= 0 || tamanho <= 0
```

quer dizer:

```text
se o tempo acabou OU o tamanho acabou
```

---

# 24. Renderizando partículas

```c
DrawCircleV(
    particulas[i].posicao,
    particulas[i].tamanho,
    particulas[i].cor
);
```

Cada partícula é desenhada como um círculo.

---

# 25. Fluxo completo

```text
ESPAÇO pressionado
   ↓
CriarExplosao()
   ↓
ativa partículas
   ↓
define posição
   ↓
define velocidade aleatória
   ↓
partículas se movem
   ↓
tempo de vida diminui
   ↓
partículas desaparecem
```

---

# Visualização mental

```text
Nascimento
   ↓
Movimento
   ↓
Diminuição
   ↓
Desaparecimento
```

---

# Conceitos profissionais aprendidos

| Conceito | Foi usado |
|---|---|
| Partículas | ✔ |
| Struct | ✔ |
| Array | ✔ |
| Vector2 | ✔ |
| Random | ✔ |
| Delta Time | ✔ |
| Tempo de Vida | ✔ |
| Ativação/Desativação | ✔ |
| Efeito Visual | ✔ |
| Feedback Visual | ✔ |

---

# O que voce aprende de verdade
voce entende que efeitos visuais são construídos com:

```text
muitos objetos pequenos
```

E que cada objeto possui:

```text
estado próprio
```

Ou seja:

```text
partículas são entidades temporárias
```

---

# Curiosidade MUITO importante

Sistemas de partículas são usados em praticamente todos os jogos.

Exemplos:

- tiro batendo na parede
- sangue estilizado
- poeira ao correr
- fumaça de explosão
- magia
- fogo
- chuva
- neve
- brilho de moeda

---

# Resultado esperado

Você verá:

✅ ponto vermelho seguindo o mouse  
✅ explosões ao apertar ESPAÇO  
✅ partículas laranjas se espalhando  
✅ partículas diminuindo  
✅ partículas desaparecendo  

---

# Atividade da Aula

## Exercício 1

Mude a cor das partículas:

```c
particulas[i].cor = RED;
```

---

## Exercício 2

Aumente o número de partículas:

```c
#define MAX_PARTICULAS 300
```

---

## Exercício 3

Faça partículas menores:

```c
particulas[i].tamanho = GetRandomValue(1, 4);
```

---

## Exercício 4

Faça a explosão durar mais:

```c
particulas[i].tempoVida = 2.0f;
```

---

# Desafio Extra

Crie partículas com cores aleatórias.

Dica:

```c
particulas[i].cor = (Color)
{
    GetRandomValue(100, 255),
    GetRandomValue(50, 150),
    0,
    255
};
```

---

# Super Desafio

Crie diferentes tipos de efeitos:

| Efeito | Ideia |
|---|---|
| Explosão | partículas laranjas |
| Fumaça | partículas cinzas |
| Magia | partículas roxas |
| Gelo | partículas azuis |
| Moeda | partículas amarelas |

---

# Próximo passo

Na próxima aula podemos evoluir para:

```text
17 - Animação com Sprite Sheet
```

onde iremos aprender:

- sprite sheets
- frames de animação
- troca de quadros
- animação de personagem
- animação de inimigos
