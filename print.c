#include <stdio.h> 
	
int main(int argc, char* argv[]) {
	FILE* fileOpen;
	char* filePath = argv[1];
	char ch; 		
	long file_size; 
	//*- FileOpen with givin filePath //
	fileOpen = fopen(filePath, "r"); 
	if (fileOpen == NULL) { 
		printf("Error\n");
		return -1; 
	}
	//* - Read the content of the files //
	while ((ch = fgetc(fileOpen)) != EOF) {
		printf("%c", ch); 
	}
	//* - Find the file size //	
	fseek(fileOpen, 0, SEEK_END); 
	file_size = ftell(fileOpen);		
	//* - Get the fileSize  // 	
	printf("\n"); 	
	printf("file size: %ldbytes\n", file_size); 
	return 0; 
}
