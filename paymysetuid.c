#include <bits/types.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void help() {
  puts("******************************");
  puts("* PAYMYBAR WRAPPER WITH SUID *");
  puts("******************************");
  puts("");
  puts("");
  puts("$ paymysetuid");
  puts("    - Launch paymybar");
  puts("");
  puts("$ paymysetuid --restart / -r");
  puts("    - Restart paymybar");
  puts("");
  puts("$ paymysetuid --stop / -s");
  puts("    - Stop paymybar");
  puts("");
  puts("$ paymysetuid --help / -s");
  puts("    - Print this menu");
}

int main(int argc, char **argv, char **env) {

  __pid_t pid;

  if (argc == 1) {
    system("xhost local:$USER & picom & dunst &");

    setreuid(geteuid(), geteuid());

    chdir("/home/orderclient/orderClient");

    char *args[] = {"/home/orderclient/orderClient/launch_local.sh",
                    "/home/orderclient/orderClient/pmb_ghetto_custom.jar",
                    NULL};

    if ((pid = fork()) == 0)
      execve(args[0], args, env);
    else {
      int fd = open("/tmp/paymytmp", O_WRONLY | O_CREAT | O_TRUNC, 0640);
      write(fd, &pid, sizeof(pid));
      close(fd);
    }
  } else if (argc == 2) {

    /* * * * * * * * HELP * * * * * * * */
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      help();
    } else

        /* * * * * * * * STOP * * * * * * * */
        if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--stop") == 0) {
      setreuid(geteuid(), geteuid());
      int fd = open("/tmp/paymytmp", O_RDONLY);
      if (fd == -1) {
        fprintf(stderr, "[\033[41mERROR\033[0m]\t\tImpossible de lire "
                        "`/tmp/paymytmp` ...\n");
        fprintf(stderr, "[\033[31mWARNING\033[0m]\tAssurez vous que paymybar "
                        "est bien lancé\n");
        exit(-1);
      }
      read(fd, &pid, sizeof(pid));
      kill(pid, SIGKILL);
      system("killall java");

    } else

        /* * * * * * * * RESTART * * * * * * * */
        if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--restart") == 0) {
      setreuid(geteuid(), geteuid());
      system("killall java");
    } else {
      help();
      exit(-1);
    }
  } else {
    exit(-1);
  }
}