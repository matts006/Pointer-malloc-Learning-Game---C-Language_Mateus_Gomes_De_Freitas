#include "raylib.h"

int main(void)
{
    InitWindow(1000, 600, "Atividade 15");
    SetTargetFPS(60);
    Vector2 jogador = { 480, 300 };
    float velocidade = 4.0f;
    
    //===============
    // Interface
    //================
    
    // Pontuação
    int score = 0;

    // Vida atual
    int vida = 100;

    // Munição
    int municao = 100;

    // Tempo de jogo para contar os pontos
    float tempoPontos = 0;
    
    //Tempo de jogo no HUD
    float tempoTotal = 0;


    while (!WindowShouldClose())
    {

        // Transforma fps em segundos
        tempoTotal += GetFrameTime();
        tempoPontos += GetFrameTime();
        
    //////////////////////
    //MOVIMENTO JOGADOR
    //////////////////////
    
    
        // Movimento direita
        if (IsKeyDown(KEY_RIGHT))
            jogador.x += velocidade;


        // Movimento esquerda
        if (IsKeyDown(KEY_LEFT))
            jogador.x -= velocidade;


        // Movimento cima
        if (IsKeyDown(KEY_UP))
            jogador.y -= velocidade;


        // Movimento baixo
        if (IsKeyDown(KEY_DOWN))
            jogador.y += velocidade;
            

        // Ganhar pontos conforme tempo avança
        if (tempoPontos >= 10.0f)
        {
            score += 10;
            tempoPontos = 0.0f;
        }

        // Simula tomar dano
        if (IsKeyPressed(KEY_H))
        {
            vida -= 10;

            if (vida < 0)
                vida = 0;
        }


        // Simula gastar munição
        if (IsKeyPressed(KEY_SPACE) && municao > 0)
        {
            municao--;
        }
        
        
        // PLANO DE FUNDO
   

        BeginDrawing();
        ClearBackground(BLACK);
        

        //=====================
        // MUNDO DO JOGO
        //======================

        // Desenha jogador
        DrawRectangleV(
            jogador,
            (Vector2){40, 40},
            WHITE
        );

        // =========================================
        // HUD
        // =========================================

        // Fundo da HUD
        DrawRectangle(
            0,
            0,
            1000,
            115,
            SKYBLUE
        );

        // Linha separadora
        DrawRectangle(
            0,
            115,
            1000,
            5,
            WHITE
        );

        // Título
        DrawText(
            "HUD",
            20,
            15,
            28,
            WHITE
        );

        // Score
        DrawText(
            TextFormat("Score: %d", score),
            20,
            65,
            20,
            WHITE
        );

        // Vida
        DrawText(
            TextFormat("Vida: %d", vida),
            220,
            65,
            20,
            WHITE
        );

        // =========================================
        // BARRA DE VIDA
        // =========================================

        // Fundo vermelho da barra
        DrawRectangle(
            220,
            40,
            200,
            20,
            RED
        );

        // Vida verde
        DrawRectangle(
            220,
            40,
            vida * 2,
            20,
            GREEN
        );

        // Borda da barra
        DrawRectangleLines(
            220,
            40,
            200,
            20,
            WHITE
        );

        // Munição
        DrawText(
            TextFormat("Municao: %d", municao),
            470,
            65,
            20,
            WHITE
        );
 
        // =========================================
        // BARRA MUNICAO
        // =========================================

        // Fundo cinza da barra
        DrawRectangle(
            450,
            40,
            200,
            20,
            DARKGRAY
        );

        // Munição dourada
        DrawRectangle(
            450,
            40,
            municao * 2,
            20,
            GOLD
        );

        // Borda da barra
        DrawRectangleLines(
            450,
            40,
            200,
            20,
            WHITE
        );
        
        
        // Tempo
        DrawText(
            TextFormat("Tempo: %.1f", tempoTotal),
            700,
            65,
            20,
            WHITE
        );

        // Texto explicativo
        DrawText(
            "Pontos a cada 10s | H = Dano | ESPACO = Gasta Municao",
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