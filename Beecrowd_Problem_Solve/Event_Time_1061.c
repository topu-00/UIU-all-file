//Presentation Error(45%);
#include <stdio.h>
int main()
{
    int Dia_in;
    int Dia_out;
    int hour_in, minit_in, second_in;
    int hour_out, minit_out, second_out;
    printf("Dia ");
    scanf("%d", &Dia_in);
    scanf("%d %d %d", &hour_in, &minit_in, &second_in);
    printf("Dia ");
    scanf("%d", &Dia_out);
    scanf("%d %d %d", &hour_out, &minit_out, &second_out);
    int total_in_time = (Dia_in * 86400) + (hour_in * 3600) + (minit_in * 60) + second_in;
    int total_out_time = (Dia_out * 86400) + (hour_out * 3600) + (minit_out * 60) + second_out;
    int total_stay_time = total_out_time - total_in_time;

    printf("%d dia(s)\n",total_stay_time/86400);
    total_stay_time=total_stay_time%86400;

    printf("%d hora(s)\n",total_stay_time/3600);
    total_stay_time=total_stay_time%3600;

    printf("%d minuto(s)\n",total_stay_time/60);
    total_stay_time=total_stay_time%60;

    printf("%d segundo(s)\n",total_stay_time);
    return 0;
}