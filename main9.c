#include "raylib.h"
#include <stdio.h>

// =========================================
// SLOTS DE SAVE
// =========================================
#define SAVE_SLOT_1 "save1.txt"
#define SAVE_SLOT_2 "save2.txt"
#define SAVE_SLOT_3 "save3.txt"

// =========================================
// STRUCT SAVE DATA
// =========================================
typedef struct SaveData
{
    Vector2 jogador;

    int score;
    int vida;
    int fase;

    char nome[32];

} SaveData;

// =========================================
// SALVAR
// =========================================
void SalvarJogo(SaveData dados, const char* slot)
{
    FILE *arquivo = fopen(slot, "w");

    if (arquivo != NULL)
    {
        fprintf(arquivo, "%f\n", dados.jogador.x);
        fprintf(arquivo, "%f\n", dados.jogador.y);

        fprintf(arquivo, "%d\n", dados.score);
        fprintf(arquivo, "%d\n", dados.vida);
        fprintf(arquivo, "%d\n", dados.fase);

        fprintf(arquivo, "%s\n", dados.nome);

        fclose(arquivo);
    }
}

// =========================================
// CARREGAR
// =========================================
void CarregarJogo(SaveData *dados, const char* slot)
{
    FILE *arquivo = fopen(slot, "r");

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%f", &dados->jogador.x);
        fscanf(arquivo, "%f", &dados->jogador.y);

        fscanf(arquivo, "%d", &dados->score);
        fscanf(arquivo, "%d", &dados->vida);
        fscanf(arquivo, "%d", &dados->fase);

        fscanf(arquivo, " %31[^\n]", dados->nome);

        fclose(arquivo);
    }
}

// =========================================
// MAIN
// =========================================
int main(void)
{
    InitWindow(1200, 700, "Atividade 22");
    SetTargetFPS(60);

    // =========================================
    // DADOS DO JOGO
    // =========================================
    SaveData dados;

    dados.jogador = (Vector2){300, 300};
    dados.score = 0;
    dados.vida = 100;
    dados.fase = 1;

    snprintf(dados.nome, 32, "Player");

    float velocidade = 300;

    // =========================================
    // LOOP
    // =========================================
    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        // =========================================
        // MOVIMENTO
        // =========================================
        if (IsKeyDown(KEY_RIGHT))
            dados.jogador.x += velocidade * delta;

        if (IsKeyDown(KEY_LEFT))
            dados.jogador.x -= velocidade * delta;

        if (IsKeyDown(KEY_UP))
            dados.jogador.y -= velocidade * delta;

        if (IsKeyDown(KEY_DOWN))
            dados.jogador.y += velocidade * delta;

        // =========================================
        // SCORE TESTE
        // =========================================
        if (IsKeyPressed(KEY_P))
        {
            dados.score += 10;
        }

        // =========================================
        // VIDA TESTE
        // =========================================
        if (IsKeyPressed(KEY_H))
        {
            dados.vida -= 10;
        }

        // =========================================
        // FASE TESTE
        // =========================================
        if (IsKeyPressed(KEY_F))
        {
            dados.fase += 1;
        }

        // =========================================
        // SALVAR (1,2,3)
        // =========================================
        if (IsKeyPressed(KEY_ONE))
            SalvarJogo(dados, SAVE_SLOT_1);

        if (IsKeyPressed(KEY_TWO))
            SalvarJogo(dados, SAVE_SLOT_2);

        if (IsKeyPressed(KEY_THREE))
            SalvarJogo(dados, SAVE_SLOT_3);

        // =========================================
        // CARREGAR (F1,F2,F3)
        // =========================================
        if (IsKeyPressed(KEY_F1))
            CarregarJogo(&dados, SAVE_SLOT_1);

        if (IsKeyPressed(KEY_F2))
            CarregarJogo(&dados, SAVE_SLOT_2);

        if (IsKeyPressed(KEY_F3))
            CarregarJogo(&dados, SAVE_SLOT_3);

        // =========================================
        // DRAW
        // =========================================
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleV(
            dados.jogador,
            (Vector2){50, 50},
            BLUE
        );

        // =========================================
        // HUD
        // =========================================
        DrawRectangle(0, 0, 1200, 150, Fade(LIGHTGRAY, 0.9f));

        DrawText("SAVE SYSTEM COMPLETO", 20, 20, 30, DARKBLUE);

        DrawText("Setas = mover | P = score | H = vida | F = fase", 20, 60, 20, DARKGRAY);

        DrawText("1/2/3 = salvar | F1/F2/F3 = carregar", 20, 90, 20, MAROON);

        DrawText(TextFormat("Score: %d", dados.score), 20, 120, 20, BLACK);

        DrawText(TextFormat("Vida: %d", dados.vida), 150, 120, 20, RED);

        DrawText(TextFormat("Fase: %d", dados.fase), 260, 120, 20, DARKBLUE);

        DrawText(TextFormat("Nome: %s", dados.nome), 360, 120, 20, BLACK);

        DrawText(TextFormat("Pos: %.0f %.0f", dados.jogador.x, dados.jogador.y),
                 520, 120, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}