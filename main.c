#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int main()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;

    /** VARIAVEIS UTILIZADAS COMO CONTADOR PARA IMPRIMIR AS MATRIZES **/
    int i, j;

    /** VARIAVEIS UTILIZADAS COMO LOCALIZADOR DAS MATRIZES PARA MOVIMENTOS **/
    int L, C;

    /** VARIAVEIS PARA FINALIZAR OS WHILES **/
    int map1, map2, faq, credits, menu2;

    /** VARIAVEIS UTILIZADAS PARA SABER SE OS MAPAS FORAM COMPLETADOS **/
    int v1, v2;

    /** VARIAVEL UTILIZADA COMO CONTADOR DE MOVIMENTOS **/
    int contador;

    /** VARIAVEL UTILIZADA PARA CAPTURAR AS TECLAS APERTADAS **/
    char tecla;

    /** VARIAVEL UTILIZADA PARA IMPRIMIR AS POSICOES FINAIS DAS MATRIZES DOS MAPAS **/
    char matrizmap_final = (char) 176;

///====================================MATRIZ MENU PRINCIPAL====================================MATRIZ MENU PRINCIPAL====================================MATRIZ MENU PRINCIPAL===================================
    char menumatriz[14][22] =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ', 'P', 'L', 'A', 'Y', ' ', ' ', ' ', '>', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'F', 'A', 'Q', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', 'R', 'E', 'D', 'I', 'T', 'S', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', 'X', 'I', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
///====================================MATRIZ MENU PRINCIPAL====================================MATRIZ MENU PRINCIPAL====================================MATRIZ MENU PRINCIPAL===================================

///======================================MATRIZ MENU NIVEIS=======================================MATRIZ MENU NIVEIS=======================================MATRIZ MENU NIVEIS====================================
    char menumatriz_nivel[14][21] =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', 'A', 'P', 'S', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '<', ' ', ' ', ' ', 'M', 'A', 'P', '-', ' ', '1', ' ', ' ', ' ', '>',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', 'A', 'P', '-', ' ', '2', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', 'E', 'N', 'U', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
///======================================MATRIZ MENU NIVEIS=======================================MATRIZ MENU NIVEIS=======================================MATRIZ MENU NIVEIS====================================

/**========================================MATRIZ MAPA 1============================================MATRIZ MAPA 1============================================MATRIZ MAPA 1======================================= **/
    char matrizmap1[9][16]  =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '#', ' ', '*', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '#', '*', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '#', ' ', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '?', ' ', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' '
    };

/**-----------------------------------MATRIZ MAPA 1 RESTART-------------------------------------MATRIZ MAPA 1 RESTART-----------------------------------MATRIZ MAPA 1 RESTART------------------------------------ **/
    char matrizmap1_restart [9][16] =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '#', ' ', '*', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '#', '*', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '#', ' ', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '?', ' ', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' '
    };
/**-----------------------------------MATRIZ MAPA 1 RESTART-------------------------------------MATRIZ MAPA 1 RESTART-----------------------------------MATRIZ MAPA 1 RESTART------------------------------------ **/

/**========================================MATRIZ MAPA 1============================================MATRIZ MAPA 1============================================MATRIZ MAPA 1======================================= **/


/**========================================MATRIZ MAPA 2============================================MATRIZ MAPA 2============================================MATRIZ MAPA 2======================================= **/
    char matrizmap2[12][18] =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '#', ' ', ' ', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '#', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '#', '?', '*', ' ', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', '#', '#', '#', '*', ' ', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' '
    };

/**-----------------------------------MATRIZ MAPA 2 RESTART-------------------------------------MATRIZ MAPA 2 RESTART-----------------------------------MATRIZ MAPA 2 RESTART------------------------------------ **/
    char matrizmap2_restart [12][18] =
    {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', '*', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '#', ' ', ' ', '*', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '#', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '#', '?', '*', ' ', ' ', ' ', ' ', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', '#', '#', '#', '*', ' ', '*', '*',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' '
    };
/**-----------------------------------MATRIZ MAPA 2 RESTART-------------------------------------MATRIZ MAPA 2 RESTART-----------------------------------MATRIZ MAPA 2 RESTART------------------------------------ **/

/**========================================MATRIZ MAPA 2============================================MATRIZ MAPA 2============================================MATRIZ MAPA 2======================================= **/




    while (1)
    {
        SetConsoleTextAttribute(out, DEFAULT_PALETTE);
        system("CLS");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (i = 0; i < 14; i++)
        {
            for (j = 0; j < 22; j++)
            {
                /** IMPRIMENDO MENU **/
                printf("%c", menumatriz[i][j]);
            }
            printf("\n");
        }

        /** CAPTURANDO TECLA **/
        tecla = getch();

///====================================IF MENU PRINCIPAL_MENU NIVEIS====================================IF MENU PRINCIPAL_MENU NIVEIS====================================IF MENU PRINCIPAL_MENU NIVEIS====================================

        if (tecla == '\r' && menumatriz [2][7] == '<')
        {
            tecla = 'x';
            menu2 = 1;
            while (menu2 > 0)
            {
/**-----------------------------IMPRIME O MENU NIVEIS----------------------------------------------------------IMPRIME O MENU NIVEIS----------------------------------------------------------IMPRIME O MENU NIVEIS **/
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                system("CLS");
                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                for (i = 0; i < 14; i++)
                {
                    for (j = 0; j < 21; j++)
                    {
                        /** CASO O PRIMEIRO MAPA FOR COMPLETADO, O FOR IMPRIME EM VERDE O PRIMEIRO MAPA **/
                        if (v1 == 1 && v2 != 1)
                        {
                            /** LOCALIZACAO NA MATRIZ MENU NIVEIS A POSICAO DAS LETRAS DO "MAP - 1"**/
                            if (i == 5 && j == 11 || i == 5 && j == 12 || i == 5 && j == 13 || i == 5 && j == 14 || i == 5 && j == 16)
                            {
                                SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                printf("%c", menumatriz_nivel[i][j]);
                            }

                            /** IMPRIME O RESTANTE DA MATRIZ DO MENU NIVEIS NA COLORACAO PADRAO **/
                            else
                            {
                                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                                printf("%c", menumatriz_nivel[i][j]);
                            }
                        }
                        /** CASO O SEGUNDO MAPA FOR COMPLETADO, O FOR IMPRIME EM VERDE O SEGUNDO MAPA **/
                        else if (v2 == 1 && v1 != 1)
                        {
                            /** LOCALIZACAO NA MATRIZ MENU NIVEIS A POSICAO DAS LETRAS DO "MAP - 2"**/
                            if (i == 8 && j == 11 || i == 8 && j == 12 || i == 8 && j == 13 || i == 8 && j == 14 || i == 8 && j == 16)
                            {
                                SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                printf("%c", menumatriz_nivel[i][j]);
                            }

                            /** IMPRIME O RESTANTE DA MATRIZ DO MENU NIVEIS NA COLORACAO PADRAO **/
                            else
                            {
                                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                                printf("%c", menumatriz_nivel[i][j]);
                            }
                        }

                        /** CASO OS DOIS MAPAS FORAM COMPLETADOS, O FOR IMPRIME EM VERDE OS DOIS MAPAS **/
                        else if (v1 == 1 && v2 == 1)
                        {
                            /** LOCALIZACAO NA MATRIZ MENU NIVEIS A POSICAO DAS LETRAS DO "MAP - 1"**/
                            if (i == 5 && j == 11 || i == 5 && j == 12 || i == 5 && j == 13 || i == 5 && j == 14 || i == 5 && j == 16)
                            {
                                SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                printf("%c", menumatriz_nivel[i][j]);
                            }
                            /** LOCALIZACAO NA MATRIZ MENU NIVEIS A POSICAO DAS LETRAS DO "MAP - 2"**/
                            else if (i == 8 && j == 11 || i == 8 && j == 12 || i == 8 && j == 13 || i == 8 && j == 14 || i == 8 && j == 16)
                            {
                                SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                printf("%c", menumatriz_nivel[i][j]);
                            }
                            /** IMPRIME O RESTANTE DA MATRIZ DO MENU NIVEIS NA COLORACAO PADRAO **/
                            else
                            {
                                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                                printf("%c", menumatriz_nivel[i][j]);
                            }
                        }
                        /** IMPRIME A MATRIZ DO MENU NIVEIS NA COLORACAO PADRAO **/
                        else
                        {
                            printf("%c", menumatriz_nivel[i][j]);
                        }
                    }
                    printf("\n");
                }
/**-----------------------------IMPRIME O MENU NIVEIS----------------------------------------------------------IMPRIME O MENU NIVEIS----------------------------------------------------------IMPRIME O MENU NIVEIS **/

                tecla = getch();

/**-----------------------------------MAPA 1-----------------------------------MAPA 1-----------------------------------MAPA 1-----------------------------------MAPA 1----------------------------------- **/
                if (tecla == '\r' && menumatriz_nivel [5][7] == '<')
                {
                    SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                    system("CLS");
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    /** RESETA AS CONFIGURACOES DO MAPA 1**/
                    map1 = 1;
                    contador = 0;
                    v1 = 0;
                    for (i = 0; i < 9; i++)
                    {
                        for (j = 0; j < 16; j++)
                        {
                            matrizmap1 [i][j] = matrizmap1_restart [i][j];
                        }
                    }
                    /** RESETA AS CONFIGURACOES DO MAPA 1**/
                    while (map1 > 0)
                    {
/**-----------------------------IMPRIME O MAPA 1----------------------------------------------------------IMPRIME O MAPA 1----------------------------------------------------------IMPRIME O MAPA 1 **/
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                        for (i = 0; i < 9; i++)
                        {
                            for (j = 0; j < 16; j++)
                            {
                                /** IMPRIME AS PAREDES **/
                                if ( matrizmap1[i][j] == '*')
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),227);
                                    printf("%c",  (char) 176);
                                }

                                /** IMPRIME AS CAIXAS **/
                                else if( matrizmap1[i][j] == '#')
                                {
                                    /** CASO A CAIXA ESTIVER NA POSICAO FINAL, ELA E IMPRESSA EM ROXO **/
                                    if (i == 7 && j == 11 || i == 7 && j == 12 || i == 7 && j == 13)
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_BLUE);
                                        printf("%c", (char) 178);
                                    }

                                    else
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_RED);
                                        printf("%c", (char) 178);
                                    }
                                }

                                /** IMPRIME O PERSONAGEM **/
                                else if( matrizmap1[i][j] == '?')
                                {
                                    SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                    printf("%c", (char) 178);
                                    L = i;
                                    C = j;
                                }

                                /** IMPRIME AS POSICOES FINAIS **/
                                else if (i == 7 && j == 11 || i == 7 && j == 12 || i == 7 && j == 13)
                                {
                                    if (matrizmap1 [i][j] == ' ')
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
                                        printf("%c", matrizmap_final);
                                    }
                                }

                                /** IMPRIME O RESTANTE DO MAPA 1 **/
                                else
                                {
                                    SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                                    printf("%c", matrizmap1[i][j]);
                                }

                            }
                            printf("\n");
                        }
/**-----------------------------IMPRIME O MAPA 1----------------------------------------------------------IMPRIME O MAPA 1----------------------------------------------------------IMPRIME O MAPA 1 **/

                        /** IMPRIME O CONTADOR DE MOVIMENTOS **/
                        printf("      MOVIMENTOS: %d", contador);

                        /** IMPRIME VITORIA E FINALIZA O MAPA 1 **/
                        if (matrizmap1 [7][11] == '#' && matrizmap1 [7][12] == '#' && matrizmap1 [7][13] == '#')
                        {
                            printf("\n\n        VITORIA!!!\n\nPRESSIONE UMA TECLA PARA RETORNAR AO MENU");
                            v1 = 1;
                            map1 = 0;
                        }

/**----------------------------SWITCH MAPA 1-------------------------------------------------------------SWITCH MAPA 1-------------------------------------------------------------SWITCH MAPA 1 **/
                        tecla = getch();
                        switch (tecla)
                        {


                        case 'w':
                            if (matrizmap1[L][C] == '?' && matrizmap1[L - 1][C] == ' ' )
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L - 1][C] = '?';
                                contador = contador + 1;

                            }
                            else if (matrizmap1[L][C] == '?' &&  matrizmap1[L - 1][C] == '#' && matrizmap1[L - 2][C] == ' ')
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L - 1][C] = '?';
                                matrizmap1[L - 2][C] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 's':
                            if (matrizmap1[L][C] == '?' && matrizmap1[L + 1][C] == ' ' )
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L + 1][C] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap1[L][C] == '?' &&  matrizmap1[L + 1][C] == '#' && matrizmap1[L + 2][C] == ' ')
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L + 1][C] = '?';
                                matrizmap1[L +  2][C] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'a':
                            if (matrizmap1[L][C] == '?' && matrizmap1[L][C - 1] == ' ' )
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L][C - 1] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap1[L][C] == '?' &&  matrizmap1[L][C - 1] == '#' && matrizmap1[L][C - 2] == ' ')
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L][C - 1] = '?';
                                matrizmap1[L][C - 2] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'd':
                            if (matrizmap1[L][C] == '?' && matrizmap1[L][C + 1] == ' ' )
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L][C + 1] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap1[L][C] == '?' &&  matrizmap1[L][C + 1] == '#' && matrizmap1[L][C + 2] == ' ')
                            {
                                matrizmap1[L][C] = ' ';
                                matrizmap1[L][C + 1] = '?';
                                matrizmap1[L][C + 2] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'r':
                            for (i = 0; i < 9; i++)
                            {
                                for (j = 0; j < 16; j++)
                                {
                                    matrizmap1 [i][j] = matrizmap1_restart [i][j];
                                }
                            }
                            contador = 0;
                            v1 = 0;
                            system("CLS");
                            break;


                        case (char) 27:
                            map1 = 0;
                            break;
                        }
/**----------------------------SWITCH MAPA 1-------------------------------------------------------------SWITCH MAPA 1-------------------------------------------------------------SWITCH MAPA 1 **/

                    }
                }
/**-----------------------------------MAPA 1-----------------------------------MAPA 1-----------------------------------MAPA 1-----------------------------------MAPA 1----------------------------------- **/



/**-----------------------------------MAPA 2-----------------------------------MAPA 2-----------------------------------MAPA 2-----------------------------------MAPA 2----------------------------------- **/
                else if (tecla == '\r' && menumatriz_nivel [8][7] == '<')
                {
                    SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                    system("CLS");
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    /** RESETA AS CONFIGURACOES DO MAPA 1**/
                    map2 = 1;
                    contador = 0;
                    v2 = 0;
                    for (i = 0; i < 12; i++)
                    {
                        for (j = 0; j < 18; j++)
                        {
                            matrizmap2 [i][j] = matrizmap2_restart [i][j];
                        }
                    }
                    /** RESETA AS CONFIGURACOES DO MAPA 1**/

                    while (map2 > 0)
                    {
/**-----------------------------IMPRIME O MAPA 2----------------------------------------------------------IMPRIME O MAPA 2----------------------------------------------------------IMPRIME O MAPA 2 **/
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                        for (i = 0; i < 12; i++)
                        {
                            for (j = 0; j < 18; j++)
                            {
                                /** IMPRIME AS PAREDES **/
                                if ( matrizmap2[i][j] == '*')
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),227);
                                    printf("%c",  (char) 176);
                                }

                                /** IMPRIME AS CAIXAS **/
                                else if( matrizmap2[i][j] == '#')
                                {
                                    /** CASO A CAIXA ESTIVER NA POSICAO FINAL, ELA E IMPRESSA EM ROXO **/
                                    if (i == 8 && j == 9 || i == 8 && j == 10 || i == 7 && j == 10 || i == 5 && j == 14 || i == 4 && j == 14 || i == 4 && j == 15)
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_RED | FOREGROUND_BLUE);
                                        printf("%c", (char) 178);
                                    }

                                    else
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_RED);
                                        printf("%c", (char) 178);
                                    }
                                }

                                /** IMPRIME O PERSONAGEM **/
                                else if( matrizmap2[i][j] == '?')
                                {
                                    SetConsoleTextAttribute(out, FOREGROUND_GREEN);
                                    printf("%c", (char) 178);
                                    L = i;
                                    C = j;
                                }

                                /** IMPRIME AS POSICOES FINAIS **/
                                else if (i == 8 && j == 9 || i == 8 && j == 10 || i == 7 && j == 10 || i == 5 && j == 14 || i == 4 && j == 14 || i == 4 && j == 15)
                                {
                                    if (matrizmap2 [i][j] == ' ')
                                    {
                                        SetConsoleTextAttribute(out, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
                                        printf("%c", matrizmap_final);
                                    }
                                }

                                /** IMPRIME O RESTANTE DO MAPA 2 **/
                                else
                                {
                                    SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                                    printf("%c", matrizmap2[i][j]);
                                }
                            }
                            printf("\n");
                        }
/**-----------------------------IMPRIME O MAPA 2----------------------------------------------------------IMPRIME O MAPA 2----------------------------------------------------------IMPRIME O MAPA 2 **/

                        /** IMPRIME O CONTADOR DE MOVIMENTOS **/
                        printf("      MOVIMENTOS: %d", contador);

                        /** IMPRIME VITORIA E FINALIZA O MAPA 2 **/
                        if (matrizmap2 [8][9] == '#' && matrizmap2 [8][10] == '#' && matrizmap2 [7][10] == '#' && matrizmap2 [5][14] == '#' && matrizmap2 [4][14] == '#' && matrizmap2 [4][15] == '#')
                        {
                            printf("\n\n        VITORIA!!!\n\nPRESSIONE UMA TECLA PARA RETORNAR AO MENU");
                            v2 = 1;
                            map2 = 0;
                        }

/**----------------------------SWITCH MAPA 2-------------------------------------------------------------SWITCH MAPA 2-------------------------------------------------------------SWITCH MAPA 2 **/
                        tecla = getch();
                        switch (tecla)
                        {


                        case 'w':
                            if (matrizmap2[L][C] == '?' && matrizmap2[L - 1][C] == ' ' )
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L - 1][C] = '?';
                                contador = contador + 1;

                            }
                            else if (matrizmap2[L][C] == '?' &&  matrizmap2[L - 1][C] == '#' && matrizmap2[L - 2][C] == ' ')
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L - 1][C] = '?';
                                matrizmap2[L - 2][C] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 's':
                            if (matrizmap2[L][C] == '?' && matrizmap2[L + 1][C] == ' ' )
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L + 1][C] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap2[L][C] == '?' &&  matrizmap2[L + 1][C] == '#' && matrizmap2[L + 2][C] == ' ')
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L + 1][C] = '?';
                                matrizmap2[L +  2][C] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'a':
                            if (matrizmap2[L][C] == '?' && matrizmap2[L][C - 1] == ' ' )
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L][C - 1] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap2[L][C] == '?' &&  matrizmap2[L][C - 1] == '#' && matrizmap2[L][C - 2] == ' ')
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L][C - 1] = '?';
                                matrizmap2[L][C - 2] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'd':
                            if (matrizmap2[L][C] == '?' && matrizmap2[L][C + 1] == ' ' )
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L][C + 1] = '?';
                                contador = contador + 1;
                            }
                            else if (matrizmap2[L][C] == '?' &&  matrizmap2[L][C + 1] == '#' && matrizmap2[L][C + 2] == ' ')
                            {
                                matrizmap2[L][C] = ' ';
                                matrizmap2[L][C + 1] = '?';
                                matrizmap2[L][C + 2] = '#';
                                contador = contador + 1;
                            }
                            break;


                        case 'r':
                            for (i = 0; i < 12; i++)
                            {
                                for (j = 0; j < 18; j++)
                                {
                                    matrizmap2 [i][j] = matrizmap2_restart [i][j];
                                }
                            }
                            contador = 0;
                            v2 = 0;
                            system("CLS");
                            break;


                        case (char) 27:
                            map2 = 0;
                            break;
                        }
/**----------------------------SWITCH MAPA 2-------------------------------------------------------------SWITCH MAPA 2-------------------------------------------------------------SWITCH MAPA 2 **/

                    }
                }
/**-----------------------------------MAPA 2-----------------------------------MAPA 2-----------------------------------MAPA 2-----------------------------------MAPA 2----------------------------------- **/




/**-----------------------------------RETORNAR PARA O MENU PRINCIPAL-----------------------------------------------------------RETORNAR PARA O MENU PRINCIPAL---------------------------------------------- **/
                else if (tecla == '\r' && menumatriz_nivel [11][7] == '<')
                {
                    menu2 = 0;
                }
/**-----------------------------------RETORNAR PARA O MENU PRINCIPAL-----------------------------------------------------------RETORNAR PARA O MENU PRINCIPAL---------------------------------------------- **/

/**-----------------------------------------SWITCH MENU NIVEIS-----------------------------------------------------------------------SWITCH MENU NIVEIS---------------------------------------------------- **/
                switch (tecla)
                {
                case 'w':
                    if (tecla == 'w' && menumatriz_nivel [5][7] == '<')
                    {
                        menumatriz_nivel [5][7] = ' ';
                        menumatriz_nivel [5][20] = ' ';
                        menumatriz_nivel [11][7] = '<';
                        menumatriz_nivel [11][18] = '>';
                    }
                    else if (tecla == 'w' && menumatriz_nivel [8][7] == '<')
                    {
                        menumatriz_nivel [8][7] = ' ';
                        menumatriz_nivel [8][20] = ' ';
                        menumatriz_nivel [5][7] = '<';
                        menumatriz_nivel [5][20] = '>';
                    }
                    else if (tecla == 'w' && menumatriz_nivel [11][7] == '<')
                    {
                        menumatriz_nivel [11][7] = ' ';
                        menumatriz_nivel [11][18] = ' ';
                        menumatriz_nivel [8][7] = '<';
                        menumatriz_nivel [8][20] = '>';
                    }

                    break;


                case 's':
                    if (tecla == 's' && menumatriz_nivel [5][7] == '<')
                    {
                        menumatriz_nivel [5][7] = ' ';
                        menumatriz_nivel [5][20] = ' ';
                        menumatriz_nivel [8][7] = '<';
                        menumatriz_nivel [8][20] = '>';
                    }
                    else if (tecla == 's' && menumatriz_nivel [8][7] == '<')
                    {
                        menumatriz_nivel [8][7] = ' ';
                        menumatriz_nivel [8][20] = ' ';
                        menumatriz_nivel [11][7] = '<';
                        menumatriz_nivel [11][18] = '>';
                    }
                    else if (tecla == 's' && menumatriz_nivel [11][7] == '<')
                    {
                        menumatriz_nivel [11][7] = ' ';
                        menumatriz_nivel [11][18] = ' ';
                        menumatriz_nivel [5][7] = '<';
                        menumatriz_nivel [5][20] = '>';
                    }

                    break;

                case (char) 27:
                    menu2 = 0;
                    break;

                }
            }
        }
/**-----------------------------------------SWITCH MENU NIVEIS-----------------------------------------------------------------------SWITCH MENU NIVEIS---------------------------------------------------- **/

///====================================IF MENU PRINCIPAL_MENU NIVEIS====================================IF MENU PRINCIPAL_MENU NIVEIS====================================IF MENU PRINCIPAL_MENU NIVEIS====================================

/**===============================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ================================================= **/
        else if (tecla == '\r' && menumatriz[5][7] == '<')
        {
            faq =1;
            while ( faq > 0)
            {
                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                system("CLS");
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                printf(" Sokoban com 2 mapas: (Boxxle 2: 1) e (Grigr 2002: 1) \n Objetivo do jogo e empurrar as caixas ate a area de blocos roxos \n\n CONTROLES:  \n W para cima \n S para baixo \n A para esquerda \n D para direita \n R para resetar \n ESC voltar ao menu \n ENTER selecionar as opcoes do menu ");
                tecla = getch();
                switch (tecla)
                {
                case (char) 27:
                    faq = 0;
                }
            }
        }
/**===============================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ=================================================IF MENU PRINCIPAL FAQ================================================= **/



/**===============================IF MENU PRINCIPAL CREDITOS============================================IF MENU PRINCIPAL CREDITOS================================================================== **/
        else if (tecla == '\r' && menumatriz[8][7] == '<')
        {
            credits = 1 ;
            while ( credits > 0)
            {
                SetConsoleTextAttribute(out, DEFAULT_PALETTE);
                system("CLS");
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                printf(" Jogo produzido por:\n Gustavo Constantini\n Marco Corazza\n Matheus Souza\n\n UNIVALI - ITAJAI");
                tecla = getch();
                switch (tecla)
                {
                case (char) 27:
                    credits = 0;
                }
            }
        }
/**===============================IF MENU PRINCIPAL CREDITOS============================================IF MENU PRINCIPAL CREDITOS================================================================== **/



/**===============================IF MENU PRINCIPAL EXIT=========================================================IF MENU PRINCIPAL EXIT============================================================= **/
        else if (tecla == '\r' && menumatriz[11][7] == '<')
        {
            SetConsoleTextAttribute(out, DEFAULT_PALETTE);
            system("CLS");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            printf("Saindo...");
            return 0;
        }
/**===============================IF MENU PRINCIPAL EXIT=========================================================IF MENU PRINCIPAL EXIT============================================================= **/


///==================================================SWITCH MENU PRINCIPAL==================================================SWITCH MENU PRINCIPAL===========================================================
        switch (tecla)
        {


        case 'w': /* CIMA */
            if (tecla == 'w' &&  menumatriz[2][7] == '<')
            {
                menumatriz[2][7] = ' ';
                menumatriz[2][18] = ' ';
                menumatriz[11][7] = '<';
                menumatriz[11][18] = '>';
            }
            else if (tecla == 'w' &&  menumatriz[11][7] == '<')
            {
                menumatriz[11][7] = ' ';
                menumatriz[11][18] = ' ';
                menumatriz[8][7] = '<';
                menumatriz[8][21] = '>';
            }
            else if (tecla == 'w' &&  menumatriz[8][7] == '<')
            {
                menumatriz[8][7] = ' ';
                menumatriz[8][21] = ' ';
                menumatriz[5][7] = '<';
                menumatriz[5][17] = '>';
            }
            else if (tecla == 'w' &&  menumatriz[5][7] == '<')
            {
                menumatriz[5][7] = ' ';
                menumatriz[5][17] = ' ';
                menumatriz[2][7] = '<';
                menumatriz[2][18] = '>';
            }


        case 's': /* baixo */
            if (tecla == 's' &&  menumatriz[2][7] == '<')
            {
                menumatriz[2][7] = ' ';
                menumatriz[2][18] = ' ';
                menumatriz[5][7] = '<';
                menumatriz[5][17] = '>';
            }
            else if (tecla == 's' && menumatriz[5][7] == '<')
            {
                menumatriz[5][7] = ' ';
                menumatriz[5][17] = ' ';
                menumatriz[8][7] = '<';
                menumatriz[8][21] = '>';
            }
            else if (tecla == 's' && menumatriz[8][7] == '<')
            {
                menumatriz[8][7] = ' ';
                menumatriz[8][21] = ' ';
                menumatriz[11][7] = '<';
                menumatriz[11][18] = '>';
            }
            else if (tecla == 's' && menumatriz[11][7] == '<')
            {
                menumatriz[11][7] = ' ';
                menumatriz[11][18] = ' ';
                menumatriz[2][7] = '<';
                menumatriz[2][18] = '>';
            }

        }
///==================================================SWITCH MENU PRINCIPAL==================================================SWITCH MENU PRINCIPAL===========================================================

    }
}
