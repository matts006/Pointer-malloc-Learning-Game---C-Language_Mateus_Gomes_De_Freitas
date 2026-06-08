#include "raylib.h"

int main(void)
{
    InitWindow(1000, 600, "Sprite Sheet");

    SetTargetFPS(60);
    

    // =========================================
    // CARREGA TEXTURA
    // =========================================
  
    Texture2D sprite = LoadTexture("player.png");
   
    // =========================================
    // CONFIGURAÇÃO DOS FRAMES
    // =========================================

    // Quantidade de frames
    int frames = 8;

    // Frame atual
    int frameAtual = 0;

    // Largura de cada frame
    int larguraFrame =
        sprite.width / frames;

    // Altura do frame
    int alturaFrame =
        sprite.height;

    // Controle do tempo da animação
    float tempoAnimacao = 0;

    // Velocidade da animação
    float velocidadeAnimacao = 0.15f;
    
    // Verifica se há Movimento
    bool movendo = false;

    // =========================================
    // POSIÇÃO DO PERSONAGEM
    // =========================================

    Vector2 posicao = { 450, 250 };

    // =========================================
    // LOOP PRINCIPAL
    // =========================================

   while (!WindowShouldClose())
{
    // Delta time
    float delta = GetFrameTime();

    // Assume que não está movendo
    movendo = false;

    // Movimento do personagem
    if (IsKeyDown(KEY_RIGHT)) {
        posicao.x += 200 * delta;
        movendo = true;
    }

    if (IsKeyDown(KEY_LEFT)) {
        posicao.x -= 200 * delta;
        movendo = true;
    }

    if (IsKeyDown(KEY_UP)) {
        posicao.y -= 200 * delta;
        movendo = true;
    }

    if (IsKeyDown(KEY_DOWN)) {
        posicao.y += 200 * delta;
        movendo = true;
    }

    // Troca frame
    if (movendo)
    {
        tempoAnimacao += delta;

        if (tempoAnimacao >= velocidadeAnimacao)
        {
            frameAtual++;

            if (frameAtual >= frames)
            {
                frameAtual = 0;
            }

            tempoAnimacao = 0;
        }
    }

    // Quando parado frame = 0
    if (!movendo)
    {
        frameAtual = 0;
    }

    // =========================================
    // SOURCE RECTANGLE
    // =========================================

    Rectangle source = {
        frameAtual * larguraFrame,
        0,
        larguraFrame,
        alturaFrame
    };

        // =========================================
        // DESTINATION RECTANGLE
        // =========================================

        Rectangle dest = {

            // Posição X
            posicao.x,

            // Posição Y
            posicao.y,

            // Escala horizontal
            larguraFrame * 2,

            // Escala vertical
            alturaFrame * 2
        };

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Título
        DrawText(
            "Animacao com Sprite Sheet",
            20,
            20,
            30,
            DARKBLUE
        );

        // Instruções
        DrawText(
            "Use as setas para mover",
            20,
            60,
            20,
            DARKGRAY
        );

        // Desenha sprite animado
        DrawTexturePro(
            sprite,
            source,
            dest,
            (Vector2){0, 0},
            0,
            WHITE
        );

        // Informações
        DrawText(
            TextFormat("Frame Atual: %d",
                       frameAtual),
            20,
            100,
            20,
            BLACK
        );

        DrawText(
            "Sprite Sheet = varios frames em uma unica imagem",
            20,
            560,
            18,
            MAROON
        );

        EndDrawing();
    }


    UnloadTexture(sprite);

    CloseWindow();

    return 0;
}