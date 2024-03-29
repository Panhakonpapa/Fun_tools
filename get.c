#include <stdio.h> 
#include <error.h>
#include <unistd.h>
void man_pages() {	
	printf("Error: Useage get <char> <filename>\n");
	printf("Example: get c file.txt\n"); 
}
int main(int argc, char* argv[]) {
	char chArg = argv[1][0];	
	const char* filePath = argv[2];
	if (chArg == -1 && filePath == NULL) {
		man_pages();
		perror("Error argv [1][0], argv [2] (exit -1)\n"); 
		return -1; 	
	}	
	
	char ch; 
	FILE* fileOpen; 
	fileOpen = fopen(filePath, "r"); 
	if (fileOpen == NULL) {
		perror("Error while open file (exit code -1)\n"); 
		return -1; 	
	}
	
	while ((ch = fgetc(fileOpen)) != EOF) {
		if (ch == chArg) {
			printf("ଘ(੭ˊᵕˋ)੭* ੈ✩‧˚ Found Character: %c\n", chArg);
		}	
	}
	fclose(fileOpen); 	
	return 0; 
}
