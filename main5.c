#include "raylib.h"

int main(void)
{

    InitWindow(1200, 700, "Camera2D");
    SetTargetFPS(60);

    // =========================================
    // JOGADOR
    // =========================================

    // Posição do jogador no mundo
    Vector2 jogador = { 500, 500 };

    // Velocidade
    float velocidade = 300;

    // =========================================
    // CAMERA
    // =========================================

    Camera2D camera = { 0 };

    // Centro da câmera na tela
    camera.offset = (Vector2){ 600, 350 };

    // Alvo da câmera
    camera.target = jogador;

    // Rotação da câmera
    camera.rotation = 0.0f;

    // Zoom
    camera.zoom = 10.0f;
    
    // =========================
    // Colisao Com Quadrado Verde Afeta Rotação
    // ==========================
    
    //Criando Colisão Quadrado verde
    Rectangle areaVerde = { 1000, 300, 200, 200 };
    
    
    
    // =========================================
    // LOOP PRINCIPAL
    // =========================================

    while (!WindowShouldClose())
    {
        // =========================================
        // UPDATE
        // =========================================

        // Delta time
        float delta = GetFrameTime();

        // Movimento direita
        if (IsKeyDown(KEY_RIGHT))
            jogador.x += velocidade * delta;

        // Movimento esquerda
        if (IsKeyDown(KEY_LEFT))
            jogador.x -= velocidade * delta;

        // Movimento cima
        if (IsKeyDown(KEY_UP))
            jogador.y -= velocidade * delta;

        // Movimento baixo
        if (IsKeyDown(KEY_DOWN))
            jogador.y += velocidade * delta;
        
        // Criando Colisao Jogador
        Rectangle jogadorRect = {
        jogador.x,
        jogador.y,
        50,
        50
        };
        
        //Aumentando rotação ao colidir com quadrado verde
         if (CheckCollisionRecs(jogadorRect, areaVerde))
         {
         camera.rotation += 100 * delta;
         }
    
        // Atualiza alvo da câmera
        camera.target = jogador;

        // Zoom com mouse wheel
        camera.zoom += GetMouseWheelMove() * 0.1f;

        // Limites do zoom
        if (camera.zoom < 0.2f)
            camera.zoom = 0.2f;

        if (camera.zoom > 3.0f)
            camera.zoom = 3.0f;

        // Rotação com teclas
        if (IsKeyDown(KEY_Q))
            camera.rotation -= 100 * delta;

        if (IsKeyDown(KEY_E))
            camera.rotation += 100 * delta;

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        // Fundo
        ClearBackground(RAYWHITE);

        // =========================================
        // MODO CAMERA 2D
        // =========================================

        BeginMode2D(camera);

        // =========================================
        // MUNDO
        // =========================================

        // Grid do mundo
        for (int x = -5000; x < 5000; x += 100)
        {
            DrawLine(x, -5000, x, 5000, LIGHTGRAY);
        }

        for (int y = -5000; y < 5000; y += 100)
        {
            DrawLine(-5000, y, 5000, y, LIGHTGRAY);
        }

        // Centro do mundo
        DrawCircle(0, 0, 20, RED);

        // Jogador
        DrawRectangleV(
            jogador,
            (Vector2){50, 50},
            BLUE
        );

        // Objetos do mundo
        DrawRectangle(1000, 300, 200, 200, GREEN);
        DrawRectangle(-800, -400, 300, 150, ORANGE);
        DrawCircle(-1200, 700, 100, PURPLE);

        // Finaliza modo câmera
        EndMode2D();

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(0, 0, 1200, 120, Fade(LIGHTGRAY, 0.8f));

        DrawText(
            "Camera2D em Raylib",
            20,
            20,
            30,
            DARKBLUE
        );

        DrawText(
            "Setas = mover | Mouse Wheel = zoom | Q/E = rotacao | Encoste no quadrado verde para afetar a rotação",
            20,
            60,
            20,
            DARKGRAY
        );

        DrawText(
            TextFormat("Posicao: %.0f %.0f",
                       jogador.x,
                       jogador.y),
            20,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("Zoom: %.2f",
                       camera.zoom),
            350,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("Rotacao: %.1f",
                       camera.rotation),
            520,
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