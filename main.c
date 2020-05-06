/*
 * @author Artur Rosa
 * 2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sudoku.h"
#include "utils.h"

int main(int argc, const char *argv[]) {
  fprintf(stdout, "SUDOKU GENERATOR\n");

  sudoku_game *sudoku;
  char input[20];
  int level, gameCreated = 0, ok;

  while (1) {
    printf("Available commands: (g) generate, (q) quit.\n");
    scanf("%s", input);
    if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
      if (gameCreated) free(sudoku);
      printf("\nBye!\n");
      return 0;
    }
    if (strcmp(input, "g") == 0 || strcmp(input, "generate") == 0) {
      printf("\nChoose difficulty (0-20): ");
      ok = fscanf(stdin, "%d", &level);
      if (ok == 0 || level < 0 || level > 20) {
        printf("No such level\n\n");
      } else {
        if (gameCreated) free(sudoku);
        sudoku = createSolvedGame();
        resetSafeRandomCells(sudoku, 30 + level);
        printBoard(sudoku);
        printf("Done!\n\n");
        gameCreated = 1;
      }
    } else {
      fprintf(stdout, "No such command.\n\n");
    }
  }
}
