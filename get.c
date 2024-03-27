#include <stdio.h> 

int main(int argc, char* argv[]) {
	char chArg = argv[1][0];
	char ch; 
	const char* filePath = argv[2];
	FILE* fileOpen; 
	fileOpen = fopen(filePath, "r"); 
	while ((ch = fgetc(fileOpen)) != EOF) {
		if (ch == chArg) {
			printf("ଘ(੭ˊᵕˋ)੭* ੈ✩‧˚ Found Character: %c\n", chArg);
		}	
	}
	
	return 0; 
}
