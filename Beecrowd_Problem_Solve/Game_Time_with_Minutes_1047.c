#include <stdio.h>
#include <limits.h>
int main()
{
    int s_hr;
    int s_min;
    int e_hr;
    int e_min;
    scanf("%d%d%d%d", &s_hr, &s_min, &e_hr, &e_min);
    int max_hr = (e_hr * 60) + e_min;
    int mini_hr = (s_hr * 60) + s_min;
    int C_game_time = max_hr - mini_hr;
    if (C_game_time <= 0)
    {
        C_game_time += 24 * 60;
    }
    int game_time_hr = C_game_time / 60;
    int game_time_min = C_game_time % 60;
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", game_time_hr, game_time_min);
    return 0;
}