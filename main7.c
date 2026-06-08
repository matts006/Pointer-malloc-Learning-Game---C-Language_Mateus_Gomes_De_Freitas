#include "raylib.h"

int main(void)
{
    // Cria janela
    InitWindow(1200, 700, "Physics em Raylib");

    SetTargetFPS(60);

    // =========================================
    // JOGADOR
    // =========================================

    // Posição do jogador
    Vector2 jogador = { 550, 300 };

    // Velocidade vertical
    float velocidadeY = 0;

    // Velocidade horizontal
    float velocidadeX = 300;

    // Gravidade
    float gravidade = 300;

    // Força do pulo
    float forcaPulo = -400;

    // Verifica se está no chão
    bool noChao = false;

    // =========================================
    // Criando colisão CHÃO
    // =========================================

    Rectangle chao = {
        0,
        600,
        1200,
        100
    };

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
        // MOVIMENTO HORIZONTAL
        // =========================================

        // Direita
        if (IsKeyDown(KEY_RIGHT))
        {
            jogador.x += velocidadeX * delta;
        }

        // Esquerda
        if (IsKeyDown(KEY_LEFT))
        {
            jogador.x -= velocidadeX * delta;
        }

        // =========================================
        // PULO
        // =========================================

        // Só pula se estiver no chão
        if (IsKeyPressed(KEY_SPACE) && noChao)
        {
            // Aplica força para cima
            velocidadeY = forcaPulo;

            // Sai do chão
            noChao = false;
        }

        // =========================================
        // GRAVIDADE
        // =========================================

        // Gravidade aumenta velocidade vertical
        velocidadeY += gravidade * delta;

        // Movimento vertical
        jogador.y += velocidadeY * delta;

        // =========================================
        // HITBOX DO JOGADOR
        // =========================================

        Rectangle jogadorRect = {
            jogador.x,
            jogador.y,
            50,
            50
        };

        // =========================================
        // COLISÃO COM CHÃO
        // =========================================

        if (CheckCollisionRecs(jogadorRect, chao))
        {
            // Encosta jogador no chão
            jogador.y = chao.y - 50;

            // Para velocidade vertical
            velocidadeY = 0;

            // Marca que está no chão
            noChao = true;
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        // Fundo
        ClearBackground(BLACK);

        // =========================================
        // CHÃO
        // =========================================

        DrawRectangleRec(
            chao,
            GRAY
        );

        // =========================================
        // JOGADOR
        // =========================================

        DrawRectangleV(
            jogador,
            (Vector2){50, 50},
            WHITE
        );

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(
            0,
            0,
            1200,
            120,
            Fade(WHITE, 0.9f)
        );

        DrawText(
            "Physics em Raylib",
            20,
            20,
            30,
            SKYBLUE
        );

        DrawText(
            "Setas = mover | ESPACO = pular",
            20,
            60,
            20,
            SKYBLUE
        );

        DrawText(
            TextFormat("Velocidade Y: %.2f",
                       velocidadeY),
            20,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("Posicao Y: %.2f",
                       jogador.y),
            320,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("No Chao: %s",
                       noChao ? "SIM" : "NAO"),
            620,
            90,
            20,
            BLACK
        );

        DrawText(
            "Fisica gravidade da Lua",
            820,
            90,
            20,
            BLACK
        );

        EndDrawing();
    }

    // Fecha janela
    CloseWindow();

    return 0;
}