// 0: Success
// 1: Operation not permitted
// 2: No such file or directory
// 3: No such process
// 4: Interrupted system call
// 5: Input/output error
// 6: No such device or address
// 7: Argument list too long
// 8: Exec format error
// 9: Bad file descriptor
// 10: No child processes
// 11: Resource temporarily unavailable
// 12: Cannot allocate memory
// 13: Permission denied

// Binary files have no EOF. They are arrays of structs.
// They are not human readable. They are written to disk, while arrays are in memory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int limit = 133;
	for(int i = 0; i < limit; i++)
	{
		printf("%d: %s\n", i, strerror(i));
	}
	
}