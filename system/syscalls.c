#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

extern char _end;
static char *heap_end;

int _close(int file) { return -1; }
int _fstat(int file, struct stat *st) { st->st_mode = S_IFCHR; return 0; }
int _isatty(int file) { return 1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _read(int file, char *ptr, int len) { return 0; }

int _getpid(void) {
    return 1;
}

int _kill(int pid, int sig) {
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

int _write(int file, char *ptr, int len)
{
    // Por ahora: descartar salida
    return len;
}

void _exit(int status)
{
    while (1);
}

void* _sbrk(int nbytes)
{
    if (!heap_end)
        heap_end = &_end;

    char *prev = heap_end;
    heap_end += nbytes;
    return prev;
}
