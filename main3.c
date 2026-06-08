#include "raylib.h"

// Define quantidade máxima de partículas
#define MAX_PARTICULAS 100

// =========================================
// ESTRUTURA PARTICULA
// =========================================


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
            particulas[i].velocidade.x = GetRandomValue(-50, 50) / 100.0f;

            // Define velocidade aleatória em Y
            particulas[i].velocidade.y = GetRandomValue(-50, 50) / 100.0f;

            // Define tamanho aleatório
            particulas[i].tamanho = GetRandomValue(3, 15);

            // Define tempo de vida
            particulas[i].tempoVida = 5.0f;

            // Define cor
            particulas[i].cor = WHITE;
        }
    }
}

// =========================================
// MAIN
// =========================================

int main(void)
{
 
    InitWindow(1000, 600, "Atividade 16");
    SetTargetFPS(60);

    // Cria vetor de partículas
    Particula particulas[MAX_PARTICULAS] = { 0 };

    // Posição inicial da explosão
    Vector2 origem = { 500, 300 };

    
    while (!WindowShouldClose())
    {
        // =========================================
        // UPDATE
        // =========================================

        // Captura delta time
        float delta = GetFrameTime();

        // Se apertar ESPAÇO, cria explosão
        //if (IsKeyPressed(KEY_SPACE))
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
                particulas[i].tamanho -= delta * 10;

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
        ClearBackground(BLACK);

        // Título
        DrawText(
            "Sistema de Particulas",
            20,
            20,
            30,
            SKYBLUE
        );

        // Instrução
        DrawText(
            "Mova o mouse e pressione ESPACO para criar explosao",
            20,
            60,
            20,
            WHITE
        );

        // Desenha origem
        DrawCircleV(
            origem,
            8,
            BLACK
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

    CloseWindow();

    return 0;
}