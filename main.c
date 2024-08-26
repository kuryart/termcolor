// This file is used for test purposes only
#include "termcolor.h"

int main() {
  char name[6] = "world";
  printf_color(RED, DEFAULT, NONE, "Hello, %s!\n", name);
  printf_color(WHITE, CYAN, BOLD, "Hello, %s!\n", name);
  printf_color(RED, CYAN, BOLD, "Hello, %s!\n", name);
  printf_color(YELLOW, DEFAULT, NONE, "Hello, %s!\n", name);

  fprintf_color(stdout, GREEN, DEFAULT, UNDERLINE, "Hello, %s!\n", name);
  fprintf_color(stderr, YELLOW, BLUE, BOLD, "Hello, %s!\n", name);
  fprintf_color(stderr, YELLOW, BLUE, NONE, "Hello, %s!\n", name);

  char buffer[256];
  sprintf_color(buffer, YELLOW, DEFAULT, NONE, "Formatted text: %s", name);
  printf("%s\n", buffer);

  char small_buffer[20];
  snprintf_color(small_buffer, sizeof(small_buffer), MAGENTA, DEFAULT, NONE,
                 "Short: %s", name);
  printf("%s\n", small_buffer);

  perror_color(RED, DEFAULT, NONE, "An error occurred");

  return 0;
}
