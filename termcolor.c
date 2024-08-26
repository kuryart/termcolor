#include "termcolor.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void apply_styles(Color textColor, Color bgColor, Style style,
                         char *buffer) {
  const char *color_codes[] = {
      "",         // Default
      "\033[31m", // Red
      "\033[32m", // Green
      "\033[33m", // Yellow
      "\033[34m", // Blue
      "\033[35m", // Magenta
      "\033[36m", // Cyan
      "\033[37m", // White
  };

  const char *background_codes[] = {
      "",         // Default
      "\033[41m", // Red
      "\033[42m", // Green
      "\033[43m", // Yellow
      "\033[44m", // Blue
      "\033[45m", // Magenta
      "\033[46m", // Cyan
      "\033[47m"  // White
  };

  buffer[0] = '\0';
  strcat(buffer, color_codes[textColor]);
  strcat(buffer, background_codes[bgColor]);

  if (style & BOLD)
    strcat(buffer, "\033[1m");
  if (style & UNDERLINE)
    strcat(buffer, "\033[4m");
  if (style & BLINK)
    strcat(buffer, "\033[5m");
  if (style & REVERSE)
    strcat(buffer, "\033[7m");
}

void printf_color(Color textColor, Color bgColor, Style style,
                  const char *format, ...) {
  char style_buffer[256];
  apply_styles(textColor, bgColor, style, style_buffer);
  va_list args;
  va_start(args, format);
  printf("%s", style_buffer);
  vprintf(format, args);
  va_end(args);
  printf("\033[0m");
}

void fprintf_color(FILE *stream, Color textColor, Color bgColor, Style style,
                   const char *format, ...) {
  char style_buffer[256];
  apply_styles(textColor, bgColor, style, style_buffer);
  va_list args;
  va_start(args, format);
  fprintf(stream, "%s", style_buffer);
  vfprintf(stream, format, args);
  va_end(args);
  fprintf(stream, "\033[0m");
}

void sprintf_color(char *buffer, Color textColor, Color bgColor, Style style,
                   const char *format, ...) {
  char style_buffer[256];
  char format_buffer[1024];
  apply_styles(textColor, bgColor, style, style_buffer);
  va_list args;
  va_start(args, format);
  vsprintf(format_buffer, format, args);
  va_end(args);
  sprintf(buffer, "%s%s\033[0m", style_buffer, format_buffer);
}

void snprintf_color(char *buffer, size_t size, Color textColor, Color bgColor,
                    Style style, const char *format, ...) {
  char style_buffer[256];
  char format_buffer[1024];
  apply_styles(textColor, bgColor, style, style_buffer);
  va_list args;
  va_start(args, format);
  vsnprintf(format_buffer, sizeof(format_buffer), format, args);
  va_end(args);
  snprintf(buffer, size, "%s%s\033[0m", style_buffer, format_buffer);
}

void perror_color(Color textColor, Color bgColor, Style style,
                  const char *message) {
  char style_buffer[256];
  apply_styles(textColor, bgColor, style, style_buffer);
  fprintf(stderr, "%s", style_buffer);
  perror(message);
  fprintf(stderr, "\033[0m");
}
