             #include <stdio.h>

int main() {
    int bookID, dueDate, returnDate, daysOverdue;
    int fineRate, fineAmount;

    // Input book ID, due date, and return date
    printf("Enter Book ID: ");
    scanf("%d", &bookID);
    
    printf("Enter Due Date (as an integer, ): ");
    scanf("%d", &dueDate);
    
    printf("Enter Return Date (as an integer, ): ");
    scanf("%d", &returnDate);

    // Calculate days overdue
    daysOverdue = returnDate - dueDate;

    // Determine fine rate based on days overdue
    if (daysOverdue <= 7) {
        fineRate = 20;
    } else if (daysOverdue >= 8 && daysOverdue <= 14) {
        fineRate = 50;
    } else {
        fineRate = 100;
    }

    // Calculate total fine amount
    fineAmount = fineRate * daysOverdue;

    // Display the required information
    printf("Book ID: %d\n", bookID);
    printf("Due Date: %d\n", dueDate);
    printf("Return Date: %d\n", returnDate);
    printf("Days Overdue: %d\n", daysOverdue);
    printf("Fine Rate: Ksh %d per day\n", fineRate);
    printf("Fine Amount: Ksh %d\n", fineAmount);

    return 0;
}