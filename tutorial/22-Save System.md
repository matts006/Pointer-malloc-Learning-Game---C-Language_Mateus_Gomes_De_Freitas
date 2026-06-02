# 22 - Save System

# Criando Sistema de Save e Load em Raylib (C)

# Objetivo da Aula

Nesta aula iremos aprender a criar:

```text
sistema de save e load
```

Agora o jogo será capaz de:

- salvar progresso
- carregar dados
- salvar score
- salvar posição
- persistir informações
- continuar o jogo depois de fechar

Isso é a base de:

- saves de jogos
- checkpoints
- progresso do jogador
- arquivos de configuração
- persistência de dados

---

# O que iremos aprender

Nesta aula vamos estudar:

- arquivos em C
- fopen
- fprintf
- fscanf
- fclose
- salvar dados
- carregar dados
- persistência
- save game

---

# O que é persistência?

Persistência significa:

```text
guardar dados mesmo depois do programa fechar
```

Sem persistência:

```text
fechou jogo
↓
perde tudo
```

Com persistência:

```text
fecha jogo
↓
abre novamente
↓
dados continuam salvos
```

---

# Jogos que usam save

Praticamente TODOS:

| Jogo | Save |
|---|---|
| Minecraft | ✔ |
| Terraria | ✔ |
| Zelda | ✔ |
| Pokémon | ✔ |
| Stardew Valley | ✔ |

---

# Código Completo

```c
// =========================================
// IMPORTA RAYLIB
// =========================================

#include "raylib.h"

// Biblioteca de arquivos
#include <stdio.h>

// =========================================
// STRUCT SAVE DATA
// =========================================

typedef struct SaveData
{
    // Posição do jogador
    Vector2 jogador;

    // Score
    int score;

} SaveData;

// =========================================
// FUNÇÃO SAVE
// =========================================

void SalvarJogo(SaveData dados)
{
    // Abre arquivo para escrita
    FILE *arquivo =
        fopen("save.txt", "w");

    // Verifica erro
    if (arquivo != NULL)
    {
        // Salva posição X
        fprintf(
            arquivo,
            "%f\n",
            dados.jogador.x
        );

        // Salva posição Y
        fprintf(
            arquivo,
            "%f\n",
            dados.jogador.y
        );

        // Salva score
        fprintf(
            arquivo,
            "%d\n",
            dados.score
        );

        // Fecha arquivo
        fclose(arquivo);
    }
}

// =========================================
// FUNÇÃO LOAD
// =========================================

void CarregarJogo(SaveData *dados)
{
    // Abre arquivo para leitura
    FILE *arquivo =
        fopen("save.txt", "r");

    // Verifica se arquivo existe
    if (arquivo != NULL)
    {
        // Lê posição X
        fscanf(
            arquivo,
            "%f",
            &dados->jogador.x
        );

        // Lê posição Y
        fscanf(
            arquivo,
            "%f",
            &dados->jogador.y
        );

        // Lê score
        fscanf(
            arquivo,
            "%d",
            &dados->score
        );

        // Fecha arquivo
        fclose(arquivo);
    }
}

// =========================================
// MAIN
// =========================================

int main(void)
{
    // Cria janela
    InitWindow(1200, 700, "Save System");

    // Define FPS
    SetTargetFPS(60);

    // =========================================
    // DADOS DO JOGO
    // =========================================

    SaveData dados;

    // Valores iniciais
    dados.jogador = (Vector2){300, 300};

    dados.score = 0;

    // Velocidade
    float velocidade = 300;

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
        // SCORE
        // =========================================

        if (IsKeyPressed(KEY_P))
        {
            dados.score += 10;
        }

        // =========================================
        // SAVE
        // =========================================

        if (IsKeyPressed(KEY_S))
        {
            SalvarJogo(dados);
        }

        // =========================================
        // LOAD
        // =========================================

        if (IsKeyPressed(KEY_L))
        {
            CarregarJogo(&dados);
        }

        // =========================================
        // DRAW
        // =========================================

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // =========================================
        // JOGADOR
        // =========================================

        DrawRectangleV(
            dados.jogador,
            (Vector2){50, 50},
            BLUE
        );

        // =========================================
        // HUD
        // =========================================

        DrawRectangle(
            0,
            0,
            1200,
            140,
            Fade(LIGHTGRAY, 0.9f)
        );

        DrawText(
            "Save System em Raylib",
            20,
            20,
            30,
            DARKBLUE
        );

        DrawText(
            "Setas = mover",
            20,
            60,
            20,
            DARKGRAY
        );

        DrawText(
            "P = ganha score",
            20,
            90,
            20,
            DARKGRAY
        );

        DrawText(
            "S = salvar | L = carregar",
            220,
            90,
            20,
            MAROON
        );

        DrawText(
            TextFormat("Score: %d",
                       dados.score),
            520,
            90,
            20,
            BLACK
        );

        DrawText(
            TextFormat("Posicao: %.0f %.0f",
                       dados.jogador.x,
                       dados.jogador.y),
            720,
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
```

---

# Explicação COMPLETA da Arquitetura

# 1. O que é Save System?

Save System é:

```text
guardar informações do jogo em arquivos
```

Exemplos:
- score
- posição
- inventário
- fase atual
- progresso

---

# 2. Struct SaveData

```c
typedef struct SaveData
```

Criamos uma estrutura para agrupar:

- posição
- score

---

# Isso é MUITO importante

Em jogos reais:
- saves normalmente usam structs
- bancos de dados
- serialização

---

# Campos do save

| Campo | Função |
|---|---|
| jogador | posição |
| score | pontuação |

---

# 3. FILE

```c
FILE *arquivo;
```

Representa:

```text
um arquivo no sistema operacional
```

---

# 4. fopen()

```c
fopen("save.txt", "w");
```

Abre arquivo.

---

# Modos principais

| Modo | Função |
|---|---|
| "w" | escrever |
| "r" | ler |
| "a" | adicionar |

---

# "w"

```text
write
```

Cria arquivo novo ou sobrescreve.

---

# "r"

```text
read
```

Lê arquivo existente.

---

# 5. fprintf()

```c
fprintf()
```

Escreve dados no arquivo.

---

# Exemplo

```c
fprintf(arquivo, "%d", score);
```

Salva:
- número inteiro

---

# 6. Salvando posição

```c
fprintf(
    arquivo,
    "%f\n",
    dados.jogador.x
);
```

Salva:
- posição X

---

# O que significa %f

```text
float
```

---

# O que significa \n

```text
nova linha
```

---

# Resultado do save.txt

```text
300.000000
250.000000
50
```

---

# Isso representa

| Linha | Valor |
|---|---|
| 1 | posição X |
| 2 | posição Y |
| 3 | score |

---

# 7. fclose()

```c
fclose(arquivo);
```

Fecha arquivo corretamente.

---

# Isso é MUITO importante

Sem fclose:
- arquivo pode corromper
- save pode falhar

---

# 8. fscanf()

```c
fscanf()
```

Lê dados do arquivo.

---

# Exemplo

```c
fscanf(arquivo, "%d", &score);
```

Lê:
- inteiro

---

# 9. Ponteiros no Load

```c
SaveData *dados
```

Usamos ponteiro porque:
- queremos alterar struct original

---

# O que significa ->

```c
dados->score
```

É equivalente a:

```c
(*dados).score
```

---

# Isso acessa dados da struct

através do ponteiro.

---

# 10. Operador &

```c
&dados->score
```

Significa:

```text
endereço de memória
```

`fscanf()` precisa:
- endereço
- local onde irá escrever

---

# 11. Save

```c
SalvarJogo(dados);
```

Passa:
- cópia dos dados

---

# 12. Load

```c
CarregarJogo(&dados);
```

Passa:
- endereço da struct

---

# Isso permite

```text
modificar dados reais do jogo
```

---

# 13. Fluxo do save

```text
dados do jogo
↓
fprintf()
↓
arquivo save.txt
↓
dados persistem
```

---

# 14. Fluxo do load

```text
save.txt
↓
fscanf()
↓
dados carregados
↓
jogo continua
```

---

# 15. Persistência real

Agora:
- fechar jogo NÃO perde progresso

---

# Visualização mental

```text
JOGADOR
↓
SAVE
↓
ARQUIVO
↓
LOAD
↓
JOGO CONTINUA
```

---

# Conceitos profissionais aprendidos

| Conceito | Foi usado |
|---|---|
| Save System | ✔ |
| Arquivos | ✔ |
| fopen | ✔ |
| fprintf | ✔ |
| fscanf | ✔ |
| fclose | ✔ |
| Persistência | ✔ |
| Structs | ✔ |
| Ponteiros | ✔ |

---

# O que você aprende de verdade

# você entende:

```text
jogos salvam dados usando arquivos
```

E entende:
- persistência
- leitura de arquivos
- escrita
- ponteiros
- serialização simples

---

# Curiosidade MUITO importante

Jogos modernos usam:
- arquivos binários
- JSON
- XML
- bancos de dados
- cloud save

Mas o conceito base continua sendo:

```text
salvar e carregar dados
```

---

# Resultado esperado

Você verá:

✅ jogador andando  
✅ score aumentando  
✅ save funcionando  
✅ load funcionando  
✅ arquivo save.txt criado  
✅ progresso persistindo  

---

# Atividade da Aula

## Exercício 1

Adicione:
- vida

ao save.

---

## Exercício 2

Adicione:
- nome do jogador

---

## Exercício 3

Salve:
- fase atual

---

## Exercício 4

Crie:
- múltiplos saves

Exemplo:

```text
save1.txt
save2.txt
save3.txt
```

---

# Desafio Extra

Salve:
- inventário
- moedas
- posição de inimigos

---

# Super Desafio

Crie:
- menu de save/load
- autosave
- checkpoints
- sistema completo de persistência

---

# Próximo passo

Na próxima aula podemos evoluir para:

```text
23 - UI Buttons.md
```

onde iremos aprender:

- botões
- mouse
- interface clicável
- menus reais
- UI interativa
- interação gráfica
