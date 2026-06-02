#include "raylib.h"
#include <stdio.h>

//Definir estados dentro de typedef enum GameState
typedef enum GameState
{
    Menu,
    Jogar,
    Configuracoes,
    GAME_OVER
} GameState;

int main(void)
{
    InitWindow(800, 450, "Meu menu");
    
    int fps = 60;

    SetTargetFPS(fps);

    GameState estadoAtual = Menu;

    Vector2 jogador = { 400, 225 };

    float velocidade = 4.0f;
    

    while (!WindowShouldClose())
    {
        

        if (estadoAtual == Menu)
        {
            if (IsKeyPressed(KEY_J))
            {
                estadoAtual = Jogar;
            }

            if (IsKeyPressed(KEY_C))
            {
                estadoAtual = Configuracoes;
            }

            if (IsKeyPressed(KEY_ESCAPE))
            {
                break;
            }
        }
        
        else if (estadoAtual == Configuracoes)
        {char textoFPS[50];
        sprintf(textoFPS, "FPS: %d", fps);

        DrawText("CONFIGURACOES", 300, 80, 32, DARKBLUE);

        DrawText(textoFPS, 280, 160, 24, WHITE);
        DrawText("<- e -> para alterar", 250, 200, 20, GRAY);

    if (IsKeyPressed(KEY_RIGHT))
    {
        fps += 30;
        SetTargetFPS(fps);
    }

    if (IsKeyPressed(KEY_LEFT))
    {
        if (fps > 30)
        {
            fps -= 30;
            SetTargetFPS(fps);
        }
    }    

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        estadoAtual = Menu;
    }
}
        else if (estadoAtual == Jogar)
        {
            if (IsKeyDown(KEY_RIGHT)) jogador.x += velocidade;
            if (IsKeyDown(KEY_LEFT))  jogador.x -= velocidade;
            if (IsKeyDown(KEY_UP))    jogador.y -= velocidade;
            if (IsKeyDown(KEY_DOWN))  jogador.y += velocidade;

            if (IsKeyPressed(KEY_G))
            {
                estadoAtual = GAME_OVER;
            }
        }
        else if (estadoAtual == GAME_OVER)
        {
            if (IsKeyPressed(KEY_R))
            {
                jogador = (Vector2){ 400, 225 };
                estadoAtual = Jogar;
            }

            if (IsKeyPressed(KEY_M))
            {
                jogador = (Vector2){ 400, 225 };
                estadoAtual = Menu;
            }
        }

        // DRAW
       

        BeginDrawing();

        ClearBackground(BLACK);

        if (estadoAtual == Menu)
        {
            DrawText("MEU JOGO EM RAYLIB", 230, 90, 32, DARKBLUE);
            DrawText("Pressione J para jogar", 280, 170, 22, SKYBLUE);
            DrawText("Pressione C para configurações", 240, 210, 22, WHITE);
            DrawText("Pressione ESC para sair", 270, 250, 22, MAROON);
        }
        else if (estadoAtual == Configuracoes)
        {
            DrawText("Use as setas para mudar o fps", 180, 260, 22, SKYBLUE);
            DrawText("Pressione BACKSPACE para voltar.", 180, 300, 22, WHITE);
        }
        else if (estadoAtual == Jogar)
        {
            DrawText("JOGO RODANDO", 20, 20, 24, DARKBLUE);
            DrawText("Use as setas para mover", 20, 55, 18, DARKGRAY);
            DrawText("Pressione G para Game Over", 20, 80, 18, MAROON);

            DrawRectangleV(jogador, (Vector2){ 40, 40 }, BLUE);
        }
        else if (estadoAtual == GAME_OVER)
        {
            DrawText("GAME OVER", 270, 120, 48, RED);
            DrawText("Pressione R para reiniciar", 260, 220, 22, BLACK);
            DrawText("Pressione M para voltar ao menu", 235, 260, 22, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}