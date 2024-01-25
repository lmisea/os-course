/* This program is for simulating a really simple calculator.
It supports addition, subtraction, multiplication, and division.
Author: Luis Isea (19-10175) */

#include <stdio.h>  // printf, fflush, scanf, getchar
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

/* The ask_for_number function is used to ask the user for a number
It takes one argument:
- num_name: the name of the number (first or second)*/
int ask_for_number(char *num_name) {
  int num;
  printf("Enter the %s number: ", num_name);
  fflush(stdout);
  scanf("%d", &num);
  return num;
}

/* The perform_operation function is used to perform the operation on the two
numbers
It takes three arguments:
- first_number: the first number
- second_number: the second number
- operation: the operation to perform */
int perform_operation(int first_number, int second_number, char operation) {
  switch (operation) {
  case '+':
    // Make the addition
    return first_number + second_number;
    break;

  case '-':
    // Make the subtraction
    return first_number - second_number;
    break;

  case '*':
    // Make the multiplication
    return first_number * second_number;
    break;

  case '/':
    // Make the division
    if (second_number != 0) {
      return first_number / second_number;
    } else {
      printf("Error: Division by zero is not allowed.\n");
      exit(EXIT_FAILURE);
    }
    break;

  default:
    printf("I didn't understand that :(\n");
    exit(EXIT_FAILURE);
    break;
  }
}

/* The print_result function outputs the result of the operation in a nice
format.
It takes four arguments:
- first_number: the first number
- operation: the operation that was performed
- second_number: the second number
- result: the result of the operation */
void print_result(int first_number, char operation, int second_number,
                  int result) {
  // Seven digits is the maximum number of digits accepted by the calculator
  printf("%8d\n%c%7d\n--------\n%8d\n", first_number, operation, second_number,
         result);
}

int main() {
  int first_number, second_number, result;
  char operation;

  // Ask the user for the first number
  first_number = ask_for_number("first");
  // Ask the user for the second number
  second_number = ask_for_number("second");

  // Ask the user for the operation
  printf("Enter the operation: (+, -, *, /): ");
  fflush(stdout);
  getchar(); // This is here to consume the newline character
  operation = getchar();

  // Then perform the operation
  result = perform_operation(first_number, second_number, operation);
  // And print the result
  print_result(first_number, operation, second_number, result);

  return EXIT_SUCCESS;
}
