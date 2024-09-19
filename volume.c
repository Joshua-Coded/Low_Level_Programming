/*
* Author: Joshua Alana
* Date: 19th Sep 2024
* Purpose: Compute the dimensional weight og a 12'' etc
*/

#include <stdio.h>
int main(){
int height, lenght, width, volume, weight;
height = 8;
lenght = 12;
width = 10;
volume = height * lenght * width;
weight = (volume + 165) / 166;

printf("Dimentions: %d*%d*%d\n", lenght, width, height);
printf("Volume (cubic inches): %d\n", volume);
printf("Dimensional weight (pounds): %d\n", weight);
return 0;
}
