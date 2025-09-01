#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


void readFile(const char* path, long long file_size, int is_regular);

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        printf("Example: %s /etc/passwd\n", argv[0]);
        return 1;
    }

    const char* path = argv[1];
    struct stat st;

    if (lstat(path, &st) != 0) 
    {
        perror("Error: Cannot access file");
        return 1;
    }

    char* type;
    if (S_ISREG(st.st_mode)) {
        type = "Regular File";
    } else if (S_ISDIR(st.st_mode)) {
        type = "Directory";
    } else if (S_ISLNK(st.st_mode)) {
        type = "Symbolic Link";
    } else {
        type = "Other";
    }

    char timebuf[64];
    struct tm* tm_info = localtime(&st.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("==========================================\n");
    printf("       FILE METADATA INFORMATION\n");
    printf("==========================================\n");
    printf("File Path: %s\n", path);
    printf("File Type: %s\n", type);
    printf("Size: %lld bytes\n", (long long)st.st_size);
    printf("Last Modified: %s\n", timebuf);
    printf("==========================================\n");

    readFile(path, st.st_size, S_ISREG(st.st_mode));

    return 0;
}

void readFile(const char* path, long long fileSize, int isRegular) 
{
    printf("\n==========================================\n");
    printf("           FILE CONTENT\n");
    printf("==========================================\n");
    
    if (!isRegular) 
    {
        printf("Cannot display content: Not a regular file\n");
        printf("==========================================\n");
        return;
    }
    
    if (fileSize == 0) 
    {
        printf("File is empty (0 bytes)\n");
        printf("==========================================\n");
        return;
    }
    
    if (fileSize > 1024) 
    {
        printf("File is large (%lld bytes). Showing first 1024 bytes:\n", fileSize);
        printf("------------------------------------------\n");
    } else {
        printf("Full file content (%lld bytes):\n", fileSize);
        printf("------------------------------------------\n");
    }
    
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Error: Cannot open file for reading");
        printf("==========================================\n");
        return;
    }

    int character;
    int bytesRead = 0;
    int lineNumber = 1;

    printf("%3d: ", lineNumber);

    while ((character = fgetc(file)) != EOF && bytesRead < 1024) 
    {
        if (character == '\n') 
        {
            printf("\n");
            lineNumber++;
            if (bytesRead + 1 < 1024 && !feof(file)) // set default 1kb limit, we need to check feof to avoid printing extra line number at end of file
            {
                printf("%3d: ", lineNumber);
            }
        } 
        else if (character >= 32 && character <= 126) //Character can print, from 32 to 126
        {
            printf("%c", character);
        } 
        else if (character == '\t') 
        {
            printf("    "); 
        } 
        else 
        {
            printf(".");
        }
        bytesRead++;
    }

    if (character != '\n' && bytesRead > 0) {
        printf("\n");
    }

    if (fileSize > 1024) {
        printf("... (%lld more bytes remaining)\n", fileSize - 1024);
    }
    
    printf("------------------------------------------\n");
    printf("Total lines displayed: %d\n", lineNumber);
    printf("==========================================\n");
    
    fclose(file);
}