#include <stdio.h> 

int main(int argc, char* argv[]) {
	char* filePath = argv[1];
	long file_size; 
	FILE* Open; 
	Open = fopen(filePath, "r"); 
	if (Open == NULL) {
		printf("Error while doing Operation\n"); 
		return -1; 
	}
	fseek(Open, 0, SEEK_END); 
	file_size = ftell(Open);

	if (remove(filePath) == 0) {		
		printf("File %s had been deleted: %ld bytes\n", filePath, file_size);	
	}
	return 0; 
}
