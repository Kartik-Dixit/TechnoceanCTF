#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 72
#define FLAGSIZE 64

int main(int argc, char **argv)
{
    volatile int modified;
    char buffer[BUFSIZE];
    char *variable;

    variable = getenv("TECHNOCEAN");

    if (variable == NULL)
    {
        errx(1, "You missed something! Please read the code \n");
    }

    modified = 0;

    strcpy(buffer, variable);

    if (modified == 0x61626364)
    {
        char buf[FLAGSIZE];
        FILE *f = fopen("flag.txt", "r");
        if (f == NULL)
        {
            printf("%s %s", "Please create 'flag.txt' in this directory with your",
                   "own debugging flag.\n");
            exit(0);
        }

        fgets(buf, FLAGSIZE, f);
        printf(buf);
    }
    else
    {
        printf("Try again, you got 0x%08x\n", modified);
    }
}
