#include <stdio.h>
#include <string.h>

void read_file(char *filename, int limit, char *data)
{
	FILE *FilePointer;
	FilePointer = fopen(filename, "r");
	if (FilePointer == NULL)
	{
		printf("Error opening file\n");
		return;
	}
	// fputs(data, FilePointer);
	fread(data, sizeof(char), limit, FilePointer);
	fclose(FilePointer);
}

void write_file(char *filename, char *data)
{
	FILE *FilePointer;
	FilePointer = fopen(filename, "w");
	if (FilePointer == NULL)
	{
		printf("Error opening file\n");
		return;
	}
	// fputs(data, FilePointer);
	fwrite(data, sizeof(char), strlen(data), FilePointer);
	fclose(FilePointer);
}

void append_file(char *filename, char *data)
{
	FILE *FilePointer;
	FilePointer = fopen(filename, "a");
	if (FilePointer == NULL)
	{
		printf("Error opening file\n");
		return;
	}
	fputs(data, FilePointer);
	fclose(FilePointer);
}

int main()
{
	write_file("file.txt", "Hello World\nBye World\n");
	append_file("file.txt", "Hello Again\n");

	int limit = 1000;
	char data[limit];
	read_file("file.txt", limit, data);
	printf("%s", data);
}