#include <linux/input.h>
#include <linux/input-event-codes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "keynames.h"

int main(int argc, char **argv)
{

  const char * binds_cmd[600] = {NULL};
  //int binds_type[600] = {0};

  int fd;
  if(argc < 2) {
    fprintf(stderr, "usage: %s /dev/input/event0 --rel ENTER command\non key release 'command release KEY_ENTER' will be executed", argv[0]);
    return 1;
  }
  fd = open(argv[1], O_RDONLY);

  if(fd < 0)
  {
    fprintf(stderr, "cant open %s!!\n", argv[1]);
    return 2;
  }

  for(int i = 2; i < argc; i++)
  {
    if(!strcmp(argv[i], "--rel"))
    {
      if(!strcmp(argv[i+1], "all"))
      {
        for(int key = 0; key < 600; key++) {
          binds_cmd[key] = argv[i+2];
        }
        i += 2;
        continue;
      }
      int key = getkey(argv[i+1]);
      if(key < 0 || key >= 600)
      {
        fprintf(stderr, "invalid key %s!!\n", argv[i+1]);
        return 3;
      }
      binds_cmd[key] = argv[i+2];
      fprintf(stderr, "registered %d -> %s\n", key,  binds_cmd[key]);
      i += 2;
      continue;
    }
  }

  struct input_event ev;

  while (1)
  {
    int cnt = read(fd, &ev, sizeof(struct input_event));
    if(cnt == -1)
    {
      perror(argv[1]);
      return 1;
    }
    if(cnt < sizeof(struct input_event))
      continue;
    if(ev.type == EV_KEY)
    {
      //printf("key %i state %i\n", ev.code, ev.value);
      if(ev.value == 0) // release
      {
        if(ev.code >= 0 && ev.code < 600 && binds_cmd[ev.code])
        {
          if(strcmp(binds_cmd[ev.code], "print") == 0)
          {
            puts(keynames[ev.code]);
            fflush(stdout);
          }
          else
          {
            if(fork() == 0)
            {
              const char * const args[] = {binds_cmd[ev.code], "release", keynames[ev.code], NULL};
              return execv(args[0], args);
            }
          }
        }
      }
    }
  }
}
