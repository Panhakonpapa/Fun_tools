#include <stdio.h> 
#include <pwd.h> 
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h> 
const char* get_Operating_sys() {
	#ifdef _WIN32
		char* os_name = "WindowOS"; 
	#elif __linux__ 
		char* os_name = "Linux_x86"; 
	#elif __unix__ 
		char* os_name = "UNIX"; 
	#elif BSD
		char* os_name = "BSE UNIX"; 
	#endif 	
	return os_name; 
}
const char* get_Shell() {	
   	const char* shell = getenv("SHELL");
	return shell; 
}
const char* username() {	
   struct passwd *pw = getpwuid(getuid());
   const char* username = pw->pw_name; 
   return username; 
}
unsigned long meminfo() {	
   char cpBuffer[256];
   unsigned long total_memery = 0; 
   FILE* FileOpen; 
   FileOpen = fopen("/proc/meminfo", "r"); 
   if (FileOpen == NULL) {
	perror("Error\n"); 
	return -1; 
   }
   while (fgets(cpBuffer, 256, FileOpen) != NULL) {

	if (strstr(cpBuffer, "MemTotal:") != NULL) {
		sscanf(cpBuffer, "MemTotal: %lu kB", &total_memery);
		break; 	
	}
   }   
   fclose(FileOpen);
   return total_memery; 
}
const char* getPackege() {				
   FILE* FileOpen; 	
   char buffer[5]; 
   char* results = (char *)malloc(5);  
   FileOpen = popen("pacman -Q | wc -l", "r");
   if (FileOpen == NULL) {
	perror("Error\n"); 
   }
   fgets(buffer, 5, FileOpen); 		
   pclose(FileOpen);
   strcpy(results, buffer);
   return results; 
}
const char* uptime() {
   FILE* FileOpen; 	
   char bufferUptime[50];
   FileOpen = popen("uptime", "r"); 
   if (FileOpen == NULL) {
	perror("Error\n"); 
   }
   fgets(bufferUptime, 50, FileOpen); 		
   pclose(FileOpen);
   char* results = (char*)malloc(50); 
   strcpy(results, bufferUptime);
   return results;
}

int main() {
    printf("                          .,,uod8B8bou,,.\t\t\t        Operating System:  %s\n", get_Operating_sys());
    printf("                ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.\t\t\tShell:             %s\n", get_Shell());
    printf("           ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||\t\t\tUser Pofile:       %s\n", username());
    printf("           !...:!TVBBBRPFT||||||||||!!^^lll   ||||\t\t\tMemory:            %lu\n", meminfo() / 1000);
    printf("           !.......:!?|||||!!^^'              ||||\t\t\tPackages:          %s\n", getPackege());
    printf("           !.........||||                     ||||\t\t\tUptime:           %s\n", uptime());
    printf("           !.........||||  ##                 ||||\t\t\tFamily:	           UNIX 1960\n");
    printf("           !.........||||  :)                 ||||\t\t\tCPU:		   Intel\n");
    printf("           !.........||||                     ||||\t\t\tGPU:		   Intel\n");
    printf("           !.........||||                     ||||\n");
    printf("           !.........||||                     ||||\n");
    printf("           `.........||||                    ,||||\n");
    printf("            .;.......||||               _.-!!|||||\n");
    printf("     .,uodWBBBBb.....||||       _.-!!|||||||||!:\"'\n");
    printf("  !YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....\n");
    printf("  !..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.\n");
    printf("  !....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.\n");
    printf("  !......YBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"\"`;::       `.\n");
    printf("  !........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.\n");
    printf("  `..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.\n");
    printf("    `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'\n");
    printf("      `......::::::::::::::::;iof688888888888888888888b.\n");
    printf("        `....:::;iof688888888888888888888888888888888b.\n");
    printf("          `..::!8888888888888888888888888888888899fT!\n");
    printf("            `' !!988888888888888888888888899fT|!^\"'\n");
    printf("                `!!8888888888888888899fT|!^\"'\n");
    printf("                  `!988888888899fT|!^\"'\n");
    printf("                    `!9899fT|!^\"'\n");
    printf("                      `!^\"'\n\n");

}
