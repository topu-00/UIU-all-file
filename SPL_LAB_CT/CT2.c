// WAP that will read time and speed and calculate the distance[Calculate distance in a function].
#include <stdio.h>
#include <limits.h>
float(findDistance(float speed, float timee))
{
  return speed * timee;
}

int main()
{
  float speed[5];
  float time[5];
  for (int i = 0; i < 5; i++)
  {
    printf("Enter Speed: ");
    scanf("%f", &speed[i]);
    printf("Enter time: ");
    scanf("%f", &time[i]);
  }
  float mini = (float)INT_MAX;
  for (int i = 0; i < 5; i++)
  {
    printf("Distance %d %.2f:\n", i + 1, findDistance(speed[i], time[i]));
    if (mini > findDistance(speed[i], time[i]))
    {
      mini = findDistance(speed[i], time[i]);
    }
  }
  printf("Minimum Distance: %.2f", mini);
  return 0;
}
