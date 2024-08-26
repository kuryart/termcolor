#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#include <stdarg.h>
#include <stdio.h>

typedef enum {
  DEFAULT = 0,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
} Color;

typedef enum {
  NONE = 0,
  BOLD = 1 << 0,
  UNDERLINE = 1 << 1,
  BLINK = 1 << 2,
  REVERSE = 1 << 3,
} Style;

void printf_color(Color textColor, Color bgColor, Style style,
                  const char *format, ...);
void fprintf_color(FILE *stream, Color textColor, Color bgColor, Style style,
                   const char *format, ...);
void sprintf_color(char *buffer, Color textColor, Color bgColor, Style style,
                   const char *format, ...);
void snprintf_color(char *buffer, size_t size, Color textColor, Color bgColor,
                    Style style, const char *format, ...);
void perror_color(Color textColor, Color bgColor, Style style,
                  const char *message);

#endif
