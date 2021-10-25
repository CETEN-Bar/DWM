#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  system("xhost local:$USER");

  setreuid(geteuid(), geteuid());

  char *args[] = {"/usr/bin/firefox", "--kiosk",         "rickroll.valekoz.fr",
                  "--display",        getenv("DISPLAY"), NULL};
  execve(args[0], args, NULL);
}