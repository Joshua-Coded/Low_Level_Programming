/*
* Author: Joshua Alana
* dATE CREATED: 19TH SEPTEMBER 2024
* purpose: users enter value in fahrenheit and convert it to celsius
*/

#include <stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

int main()
{
float fahrenheit, celsius;

printf("Enter Fahrenheit temperature: ");
scanf("%f", &fahrenheit);

celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
printf("Celsius equivalent: %.1f\n", celsius);
return 0;
}
