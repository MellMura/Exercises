#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "");
	short red = 0, green = 0, blue = 0;
	short red2 = 0, green2 = 0, blue2 = 0;
	
	bool isValid = false;
	
	printf("\e[37;1mWelcome to complementary color finder!\033[0m");
	
	while(!isValid) {
		printf("\n\n\033[0mInput your color RGB values:");
		printf("\n\033[31mR: ");
		scanf("%hu", &red);
		printf("\033[32mG: ");
		scanf("%hu", &green);
		printf("\033[34mB: ");
		scanf("%hu", &blue);
		
		if (red >= 0 && red <=255 && green >= 0 && green <= 255 && blue >=0 && blue <= 255) {
			isValid = true;
			break;
		}
		else {
			printf("\n\033[0mError! All rgb values must be somewhere between 0 and 255.");
			continue;
		}
	}
	
	//printf("\n\033[0mYour color is: ");
	//printf("\033[38;2;%d;%d;%dm█\033[0m\n", red, green, blue);
	
	red2 = 255 - red;
	green2 = 255 - green;
	blue2 = 255 - blue;
	
	printf("\n\033[0mYour complementary color is: ");
	//printf("\033[38;2;%d;%d;%dm█\033[0m\n", red2, green2, blue2);
	printf("\n\033[31mR: %hu", red2);
	printf("\n\033[32mG: %hu", green2);
	printf("\n\033[34mB: %hu", blue2);
	
	//printf("\n\n\033[0mThe color visualization may be incorrect due to the terminal limitations.");
	
	return 0;
}