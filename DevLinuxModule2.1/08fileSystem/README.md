
# File System Metadata Checker

## Description
This module provides a command-line tool to check and display **metadata** of files and directories on Linux systems. The program uses the `lstat()` system call to access inode information and display detailed file information.

## Main Features
**Display file types**: Regular File, Directory, Symbolic Link
**File size**: Display exact byte count
**Modification time**: Human-readable format (YYYY-MM-DD HH:MM:SS)
**Read file content**: Preview content with 1024 bytes limit
**Handle special characters**: Tab, newline, non-printable characters
**Line numbering**: Number lines for easy tracking

## Usage

### Syntax
```bash
./filestat <file_path>

## Output Format

```bash
==========================================
       FILE METADATA INFORMATION
==========================================
File Path: main.c
File Type: Regular File
Size: 3842 bytes
Last Modified: 2025-09-01 14:30:15
==========================================

==========================================
           FILE CONTENT
==========================================
Full file content (3842 bytes):
------------------------------------------
  1: #include <stdio.h>
  2: #include <stdlib.h>
  3: #include <sys/types.h>
  4: #include <sys/stat.h>
  5: ...
------------------------------------------
Total lines displayed: 132
==========================================
```

## File Structure
```
08fileSystem/
├── main.c          # Main program
├── README.md       # Documentation
```


## Build Instructions
1. Open terminal in `08fileSystem` folder
2. Build project:
  ```
  make all
  ```
3. Clean build files:
  ```
  make clean
  ```

### 2. Run Program
```bash
# Check current file
./filestat main.c

# Check directory
./filestat ../

# Check other file
./filestat /etc/hosts
```

### 3. Debug (Optional)
```bash
gcc -g -Wall -o filestat main.c
gdb ./filestat
```

## Technical Details

### System Calls Used
- **`lstat()`**: Get metadata from inode
- **`fopen()`/`fgetc()`**: Read file content
- **`localtime()`/`strftime()`**: Format time

### File Type Handling
| Macro | File Type | Description |
|-------|-----------|-------------|
| `S_ISREG()` | Regular File | Normal file containing data |
| `S_ISDIR()` | Directory | Directory folder |
| `S_ISLNK()` | Symbolic Link | Symbolic link |

### Display Limits
- **File content**: Maximum 1024 bytes
- **Printable characters**: ASCII 32-126
- **Special characters**: Tab → 4 spaces, Other → "."

## Common Errors

### 1. Permission Denied
```bash
Error: Cannot access file: Permission denied
```
**Solution**: Use `sudo` or change file permissions

### 2. File Not Found
```bash
Error: Cannot access file: No such file or directory
```
**Solution**: Check file path

### 3. Cannot Open File
```bash
Error: Cannot open file for reading: Permission denied
```
**Solution**: File metadata readable but content is not accessible

