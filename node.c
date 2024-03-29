#include <stdio.h> 
#include <error.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char* argv[]) {
	char* filewrite = argv[1]; 
	char* writeTo = argv[2];
	if (filewrite == NULL && writeTo == NULL) {
		perror("Error(exit -1)\n"); 
		return -1; 
	}
	FILE* OpenFile;
	OpenFile = fopen(writeTo, "a"); 
	for (int i = 0; filewrite[i] != '\0'; i++) {
		if (isspace(filewrite[i])) {
			fprintf(OpenFile, "[SPACE]"); 		
		}
		else {
			fprintf(OpenFile, "%c", filewrite[i]); 
		}
	}	
	if (fseek(OpenFile, 0, SEEK_END) == -1) {	
		perror("Error(exit -1)\n");
		return -1;
	}
	long file_size; 
	file_size = ftell(OpenFile); 
	printf("Written to a files sucessful %ld bytes\n", file_size); 
	fclose(OpenFile); 
	return -1; 
}
