#include "raylib.h"

// =========================================
// CONSTANTES
// =========================================

// Quantidade de colunas
#define MAP_WIDTH 20

// Quantidade de linhas
#define MAP_HEIGHT 12

// Tamanho de cada tile
#define TILE_SIZE 64

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Cria janela
    InitWindow(
        MAP_WIDTH * TILE_SIZE,
        MAP_HEIGHT * TILE_SIZE,
        "Atividade 19"
    );

    SetTargetFPS(60);

    // =========================================
    // MAPA
    // =========================================

    // Matriz do mapa
    int mapa[MAP_HEIGHT][MAP_WIDTH] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
        {1,0,2,2,0,0,0,3,3,0,0,4,0,0,0,0,0,0,0,1},
        {1,0,4,0,2,0,0,3,3,0,0,0,0,0,0,0,0,4,0,1},
        {1,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,3,3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,3,3,0,0,2,2,2,0,0,0,0,4,0,0,0,0,1},
        {1,0,0,3,3,3,0,0,0,2,2,0,0,0,0,0,0,0,0,1},
        {1,0,4,0,0,0,0,0,4,0,2,0,0,0,0,0,0,0,4,1},
        {1,0,0,0,0,0,3,3,0,0,2,2,0,4,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,3,3,0,0,2,2,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    // =========================================
    // JOGADOR
    // =========================================

    Vector2 jogador = { 100, 100 };

    float velocidade = 250;

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // UPDATE
        // =========================================

        float delta = GetFrameTime();

        // Guarda posição antiga
        Vector2 antigaPosicao = jogador;

        // Movimento
        if (IsKeyDown(KEY_RIGHT))
            jogador.x += velocidade * delta;

        if (IsKeyDown(KEY_LEFT))
            jogador.x -= velocidade * delta;

        if (IsKeyDown(KEY_UP))
            jogador.y -= velocidade * delta;

        if (IsKeyDown(KEY_DOWN))
            jogador.y += velocidade * delta;

        // =========================================
        // COLISÃO COM TILES
        // =========================================

        // Descobre coluna do jogador
        int coluna =
            jogador.x / TILE_SIZE;

        // Descobre linha do jogador
        int linha =
            jogador.y / TILE_SIZE;

        // Verifica limites
        if (linha >= 0 &&
            linha < MAP_HEIGHT &&
            coluna >= 0 &&
            coluna < MAP_WIDTH)
        {
            // Tile sólido
            if (mapa[linha][coluna] == 1)
            {
                // Volta posição antiga
                jogador = antigaPosicao;
            }
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(BLACK);

        // =========================================
        // DESENHA MAPA
        // =========================================

        for (int linha = 0;
             linha < MAP_HEIGHT;
             linha++)
        {
            for (int coluna = 0;
                 coluna < MAP_WIDTH;
                 coluna++)
            {
                // Posição do tile
                int x = coluna * TILE_SIZE;
                int y = linha * TILE_SIZE;

                // Tipo do tile
                int tile = mapa[linha][coluna];

                // =========================================
                // TILE PAREDE
                // =========================================

                if (tile == 1)
                {
                    DrawRectangle(
                        x,
                        y,
                        TILE_SIZE,
                        TILE_SIZE,
                        WHITE
                    );
                }

                // =========================================
                // TILE TERRA
                // =========================================

                else if (tile == 2)
                {
                    DrawRectangle(
                        x,
                        y,
                        TILE_SIZE,
                        TILE_SIZE,
                        MAROON
                    );
                }

                // =========================================
                // TILE ÁGUA
                // =========================================

                else if (tile == 3)
                {
                    DrawRectangle(
                        x,
                        y,
                        TILE_SIZE,
                        TILE_SIZE,
                        SKYBLUE
                    );
                }
                
                // =========================================
                // TILE PEDRA
                // =========================================

                else if (tile == 4)
                {
                    DrawRectangle(
                        x,
                        y,
                        TILE_SIZE,
                        TILE_SIZE,
                        GRAY
                    );
                }

                // =========================================
                // TILE VAZIO
                // =========================================

                else
                {
                    DrawRectangleLines(
                        x,
                        y,
                        TILE_SIZE,
                        TILE_SIZE,
                        BLACK
                    );
                }
            }
        }

        // =========================================
        // DESENHA JOGADOR
        // =========================================

        DrawRectangleV(
            jogador,
            (Vector2){40, 40},
            WHITE
        );

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(
            0,
            0,
            1280,
            90,
            Fade(LIGHTGRAY, 0.9f)
        );

        DrawText(
            "Tilemap em Raylib",
            20,
            20,
            30,
            BLUE
        );

        DrawText(
            "Setas = mover jogador",
            20,
            55,
            20,
            WHITE
        );

        DrawText(
            "Tilemaps = mapas feitos com blocos",
            700,
            55,
            20,
            WHITE
        );

        EndDrawing();
    }

    // Fecha janela
    CloseWindow();

    return 0;
}