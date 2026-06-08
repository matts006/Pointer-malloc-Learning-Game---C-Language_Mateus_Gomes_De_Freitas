// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"
#include <math.h>
#include "raymath.h"

// =========================================
// ESTADOS DO INIMIGO
// =========================================

typedef enum EnemyState
{
    PARADO,
    PATRULHANDO,
    PERSEGUINDO
} EnemyState;

// =========================================
// STRUCT DO INIMIGO
// =========================================

typedef struct Enemy
{
    // Posição
    Vector2 posicao;

    // Velocidade
    float velocidade;

    // Direção
    int direcao;

    // Estado atual
    EnemyState estado;

} Enemy;

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Cria janela
    InitWindow(1200, 700, "Atividade 21");

    // Define FPS
    SetTargetFPS(60);

    // =========================================
    // JOGADOR
    // =========================================

    Vector2 jogador = { 300, 300 };

    float velocidadeJogador = 300;

    // =========================================
    // INIMIGO
    // =========================================

    Enemy inimigo;

    inimigo.posicao = (Vector2){ 700, 300 };

    inimigo.velocidade = 150;

    inimigo.direcao = 1;

    inimigo.estado = PATRULHANDO;
    
    //Definir Estado GameOver
    bool gameOver = false;

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // DELTA TIME
        // =========================================

        float delta = GetFrameTime();

        // =========================================
        // MOVIMENTO DO JOGADOR
        // =========================================

        if (IsKeyDown(KEY_RIGHT))
            jogador.x += velocidadeJogador * delta;

        if (IsKeyDown(KEY_LEFT))
            jogador.x -= velocidadeJogador * delta;

        if (IsKeyDown(KEY_UP))
            jogador.y -= velocidadeJogador * delta;

        if (IsKeyDown(KEY_DOWN))
            jogador.y += velocidadeJogador * delta;

        // =========================================
        // DISTÂNCIA ENTRE JOGADOR E INIMIGO
        // =========================================

        float distancia =
            Vector2Distance(
                jogador,
                inimigo.posicao
            );

        // =========================================
        // TROCA DE ESTADO
        // =========================================

        // Se jogador estiver perto
        if (distancia < 200)
        {
            inimigo.estado = PERSEGUINDO;
        }
        else
        {
            inimigo.estado = PATRULHANDO;
        }

        // =========================================
        // IA - PATRULHA
        // =========================================

        if (inimigo.estado == PATRULHANDO)
        {
            // Movimento horizontal
            inimigo.posicao.x +=
                inimigo.velocidade *
                inimigo.direcao *
                delta;

            // Limites da patrulha
            if (inimigo.posicao.x > 900)
            {
                inimigo.direcao = -1;
            }

            if (inimigo.posicao.x < 600)
            {
                inimigo.direcao = 1;
            }
        }
        
        // ========================
        // COLISOES PLAYER E INIMIGO
        // =========================
       
       Rectangle recJogador = { jogador.x, jogador.y, 50, 50 };
       Rectangle recInimigo = { inimigo.posicao.x, inimigo.posicao.y, 50, 50 };

       //Checando Colisoes
       if (CheckCollisionRecs(recJogador, recInimigo))
       {
       gameOver = true;
       }
        
        
        // =========================================
        // IA - PERSEGUIÇÃO
        // =========================================
        
        if (inimigo.estado == PERSEGUINDO)
        {
            // Vetor direção
            Vector2 direcao =
                Vector2Subtract(
                    jogador,
                    inimigo.posicao
                );

            // Normaliza vetor
            direcao =
                Vector2Normalize(direcao);

            // Move inimigo
            inimigo.posicao.x +=
                direcao.x *
                inimigo.velocidade *
                1.5f *
                delta;

            inimigo.posicao.y +=
                direcao.y *
                inimigo.velocidade *
                1.5f *
                delta;
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(BLACK);

        
        // =========================================
        // JOGADOR
        // =========================================

        DrawRectangleV(
            jogador,
            (Vector2){50, 50},
            WHITE
        );

        // =========================================
        // INIMIGO
        // =========================================

        Color corInimigo;

        // Cor muda conforme estado
        if (inimigo.estado == PATRULHANDO)
        {
            corInimigo = SKYBLUE;
        }
        else
        {
            corInimigo = RED;
        }

        DrawRectangleV(
            inimigo.posicao,
            (Vector2){50, 50},
            corInimigo
        );

        // =========================================
        // LINHA DE VISÃO
        // =========================================

        if (inimigo.estado == PERSEGUINDO)
        {
            DrawLineV(
                jogador,
                inimigo.posicao,
                BLUE
            );
        }

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(
            0,
            0,
            1200,
            120,
            Fade(LIGHTGRAY, 0.9f)
        );

        DrawText(
            "Enemy AI em Raylib",
            20,
            20,
            30,
            DARKBLUE
        );

        DrawText(
            "Setas = mover jogador",
            20,
            60,
            20,
            DARKGRAY
        );

        DrawText(
            TextFormat("Distancia: %.2f",
                       distancia),
            20,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("Estado: %s",
                inimigo.estado == PATRULHANDO
                ? "PATRULHANDO"
                : "PERSEGUINDO"),
            320,
            90,
            20,
            BLACK
        );

        DrawText(
            "Laranja = patrulha | Vermelho = perseguicao",
            650,
            90,
            20,
            MAROON
        );
        
        if (gameOver)
        {
        DrawRectangle(0, 0, 1200, 700, Fade(BLACK, 0.6f));

        DrawText(
          "VOCE MORREU",
          400,
          300,
          60,
         RED
        );

    
    }

        EndDrawing();
    }

    // Fecha janela
    CloseWindow();

    return 0;
}