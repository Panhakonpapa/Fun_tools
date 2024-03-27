#include <stdio.h> 
//* file open with const path   // 	
//* get seek the file 		// 
//* Find the file size in btyes // 
//* Output it into a console    // 
int main(int argc, char* argv[]) {
	FILE* fileOpen;
        const char* filePath = argv[1]; 
	long file_sizes;	
	fileOpen = fopen(filePath, "r");
	fseek(fileOpen, 0, SEEK_END); 
	file_sizes = ftell(fileOpen);
	printf("sizes: %ld bytes\n", file_sizes); 
	return 0; 
} 
