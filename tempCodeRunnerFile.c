int takeColumnInputFromUser () {
                int column;
                char newline;
                while (1) {
                    printf("Enter column number (1-3): ");

                    // attempt to read an integer
                    if (scanf("%d%c", &column, &newline) != 2 || newline != '\n') {
                        printf("Invalid input. Please enter a number\n");
                        // clear input buffer
                        while (getchar() != '\n'); 
                    } else {
                        // check if column is within the valid range
                        if (column >= 1 && column <= 3) {
                            break; // valid column number, exit the loop
                        } else {
                            printf("Enter valid column number (1-3)\n");
                        }
                    }
                }
                return column;
}