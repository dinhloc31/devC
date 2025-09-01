#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char* path = argv[1];
    struct stat st;

    if (lstat(path, &st) != 0) 
    {
        perror("lstat");
        return 1;
    }

    char* type;
    if (S_ISREG(st.st_mode)) type = "Regular File";
    else if (S_ISDIR(st.st_mode)) type = "Directory";
    else type = "Other";

    char timebuf[64];
    struct tm* tm_info = localtime(&st.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("File Path: %s\n", path);
    printf("File Type: %s\n", type);
    printf("Size: %lld bytes\n", (long long)st.st_size);
    printf("Last Modified: %s\n", timebuf);

    return 0;
}