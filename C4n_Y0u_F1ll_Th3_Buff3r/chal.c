#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 32
#define FLAGSIZE 64

void win()
{
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("%s %s", "Please create 'flag.txt' in this directory with your",
                    "own debugging flag.\n");
    exit(0);
  }

  fgets(buf,FLAGSIZE,f);
  printf(buf);
}

int main(int argc, char **argv)
{
  volatile int (*fp)();
  char buf[64];

  fp = 0;

  gets(buf);

  if(fp) {
      win();
  }
}
