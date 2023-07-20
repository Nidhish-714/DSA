#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_safe(int *board, int row, int col)
{
    // Check if any queen exists in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)
        {
            return false;
        }
    }

    // Check diagonals
    for (int i = 0; i < row; i++)
    {
        int row_diff = row - i;
        int col_diff = abs(col - board[i]);
        if (row_diff == col_diff)
        {
            return false;
        }
    }

    // No conflicts found, so it's safe to place a queen here
    return true;
}

void print_board(int *board, int n)
{
    printf("\n  ");
    for (int i = 0; i < n; i++)
    {
        printf(" %2c ", 'A' + i);
    }
    printf("\n  ");
    for (int i = 0; i < n; i++)
    {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%2d|", i + 1);
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
            {
                printf(" \u265B ");
            }
            else if ((i + j) % 2 == 0)
            {
                printf(" \u25A1 ");
            }
            else
            {
                printf(" \u25A0 ");
            }
        }
        printf("|%d\n", i + 1);
    }
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("----");
    }
    printf("\n");
}

bool solve(int *board, int n, int row)
{
    // If we have placed queens on all rows, we have found a solution
    if (row == n)
    {
        return true;
    }

    bool found_solution = false;
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (is_safe(board, row, col))
        {
            // Place in column and move to the next row
            board[row] = col;
            print_board(board, n);

            // using recursion try to place queens in the remaining rows
            if (solve(board, n, row + 1))
            {
                found_solution = true;
                break;
            }

            // If we dont find a solution by placing the queen in this column,
            // backtrack by removing the queen from this column and trying the next column
            board[row] = -1;
            printf("Backtracking from row %d, column %d\n", row + 1, col + 1);
            printf("No safe spot found for queen %d in row %d at column %d\n", row + 1, row + 1, col + 1);
        }
    }

    // If we dont find a solution by placing queens in any of the columns of the current row,
    // backtrack to the previous row and try to place queens in a different column of that row
    if (!found_solution)
    {
        printf("No solution found for queen %d in row %d\n", row + 1, row + 1);
    }

    return found_solution;
}

int main()
{
    int n;
    printf("Enter the number of queens you want: ");
    scanf("%d", &n);

    int board[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = -1;
    }

    if (solve(board, n, 0))
    {
        printf("\033[1;33m\n");
        printf("Solution found:\n");
        printf("\033[0;37m\n");
        printf("\u263A");
        print_board(board, n);
    }
    else
    {
        printf("\033[1;31m\n");
        printf("no solution exists \n");
        printf("\033[1;37m\n");
        printf(" \u2639");
    }
    printf("\033[1;34m\n");                // Set the text to the color red
    printf("Hope you like our project\n"); // Display Hello in red
    printf("\033[1;31m\n");                // Set the text to the color red
    printf("S-7\n");

    return 0;
}