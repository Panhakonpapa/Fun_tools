#include <stdio.h> 
#include <error.h>
int main(int argc, char* argv[]) {
	char* filePath = argv[1];
	if (filePath == NULL) {
		perror("Argv[1] given (exit -1)\n"); 
		return -1; 
	}	
	long file_size; 
	FILE* Open; 
	Open = fopen(filePath, "r"); 
	if (Open == NULL) {
		perror("Error while doing Operation\n"); 
		return -1; 
	}
	fseek(Open, 0, SEEK_END); 
	file_size = ftell(Open);			
	fseek(Open, 0, SEEK_END);

	if (remove(filePath) == 0) {		
		printf("File %s had been deleted: %ld bytes\n", filePath, file_size);	
	}
	fclose(Open); 	
	return 0; 
}
