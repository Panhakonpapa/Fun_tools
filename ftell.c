#include <stdio.h>
#include <error.h> 
int main(int argc, char* argv[]) {
	FILE* fileOpen;
        const char* filePath = argv[1]; 
	if (filePath == NULL) {
		perror("Error Open file (exit -1)\n");	
		return -1; 	
	}	
	long file_sizes;	
	fileOpen = fopen(filePath, "r");
	if (fileOpen == NULL) {	
		perror("Error Opening file (exit -1)"); 
		return -1;  
	}	
	if (fseek(fileOpen, 0, SEEK_END) == -1) {		
		perror("Error seeking file (exit -1)\n");	
		return -1; 	
	} 	
	file_sizes = ftell(fileOpen);
	printf("sizes: %ld bytes\n", file_sizes); 
	fclose(fileOpen); 	
	return 0; 
} 
