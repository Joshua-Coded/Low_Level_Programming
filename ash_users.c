/*
* Author: Joshua Alana
* Date Created: 19TH September 2024
* Purpose: Compute the dimensional weight of a box from input provided by the user
*/

#include <stdio.h>
int main()
{
int height, length, width, volume, weight;
printf("Enter height of box: ");
scanf("%d", &height);
printf("Enter Length of box: ");
scanf("%d", &length);
printf("Enter width of box: ");
scanf("%d", &width);

volume = height * length * width;
weight = (volume + 165) / 166;

printf("Volume (cubic inches): %d\n", volume);
printf("Dimensional weight (pounds): %d\n", weight);
return 0;


}
