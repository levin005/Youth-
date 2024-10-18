#include <stdio.h>
#include <string.h>

// Function prototypes
void inputCustomerDetails(char customer_id[], char customer_name[], int *units_consumed);
float calculateChargePerUnit(int units_consumed);
float calculateTotalBill(int units_consumed, float charge_per_unit);
float applySurchargeAndMinimumBill(float total_bill, float *surcharge);
void displayBillSummary(char customer_id[], char customer_name[], int units_consumed, float charge_per_unit, float total_bill, float surcharge);

int main() {
    // Declare variables
    char customer_id[20];
    char customer_name[50];
    int units_consumed;
    float charge_per_unit, total_bill, surcharge = 0;

    // Input customer details
    inputCustomerDetails(customer_id, customer_name, &units_consumed);

    // Calculate charge per unit
    charge_per_unit = calculateChargePerUnit(units_consumed);

    // Calculate total bill
    total_bill = calculateTotalBill(units_consumed, charge_per_unit);

    // Apply surcharge and minimum bill
    total_bill = applySurchargeAndMinimumBill(total_bill, &surcharge);

    // Display the bill summary
    displayBillSummary(customer_id, customer_name, units_consumed, charge_per_unit, total_bill, surcharge);

    return 0;
}

// Function to input customer details
void inputCustomerDetails(char customer_id[], char customer_name[], int *units_consumed) {
    printf("Enter Customer ID: ");
    scanf("%s", customer_id);
    printf("Enter Customer Name: ");
    scanf("%s", customer_name);
    printf("Enter Units Consumed: ");
    scanf("%d", units_consumed);
}

// Function to calculate charge per unit
float calculateChargePerUnit(int units_consumed) {
    if (units_consumed <= 199) {
        return 1.20;
    } else if (units_consumed >= 200 && units_consumed < 400) {
        return 1.50;
    } else if (units_consumed >= 400 && units_consumed < 600) {
        return 1.80;
    } else {
        return 2.00;
    }
}

// Function to calculate the total bill
float calculateTotalBill(int units_consumed, float charge_per_unit) {
    return units_consumed * charge_per_unit;
}

// Function to apply a 15% surcharge if the bill exceeds 400 Ksh and ensure minimum bill of 100 Ksh
float applySurchargeAndMinimumBill(float total_bill, float *surcharge) {
    *surcharge = 0;  // Initialize surcharge
    
    if (total_bill > 400) {
        *surcharge = total_bill * 0.15;  // Calculate 15% surcharge
        total_bill += *surcharge;        // Add surcharge to total bill
    }

    // Ensure minimum bill is Ksh. 100
    if (total_bill < 100) {
        total_bill = 100;
    }

    return total_bill;
}

// Function to display the bill summary
void displayBillSummary(char customer_id[], char customer_name[], int units_consumed, float charge_per_unit, float total_bill, float surcharge) {
    printf("\nElectricity Bill Summary:\n");
    printf("Customer ID       : %s\n", customer_id);
    printf("Customer Name     : %s\n", customer_name);
    printf("Units Consumed    : %d\n", units_consumed);
    printf("Charge per Unit   : %.2f Ksh\n", charge_per_unit);
    if (surcharge > 0) {
        printf("Surcharge Applied : %.2f Ksh\n", surcharge);
    }
    printf("Total Amount to Pay: %.2f Ksh\n", total_bill);
}