/**
* Author: joshua Alana
* Date: 1st/10/2024
**/

#include <stdio.h>
 
int main(){
	
	//define array for province, districts, and weather data

	char *provinces[] = {"Kigali", "North", "East"};
	char *districts[3][3] = {
	{"Kicukiro", "Gasabo", "Nyarugenge"}, // Districts in Kigali
        {"Rulindo", "Gicumbi", "Musanze"},    // Districts in North
        {"Kayonza", "Rwamagana", "Nyagatare"}
	};

	// weather data
	int temperature[3][3] = {{23, 23, 22}, {20, 19, 18}, {25, 24, 23}};
   	int humidity[3][3] = {{53, 56, 50}, {49, 52, 47}, {57, 55, 54}};
   	int wind_speed[3][3] = {{3, 6, 4}, {3, 5, 2}, {4, 3, 3}};
    	float rainfall[3][3] = {{0, 0, 0.2}, {1, 0.8, 0}, {0.5, 0.3, 0}};

	//display the weather data
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%s, %s, Temp: %d, Humid: %d, Wind: %d, Rain: %.1f\n", 
       provinces[i], districts[i][j], temperature[i][j], 
       humidity[i][j], wind_speed[i][j], rainfall[i][j]);

}
}
return 0;

}
