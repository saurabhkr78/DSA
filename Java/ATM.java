import java.util.Scanner;

public class ATM {

    private int balance = 100000;
    private Scanner sc;

    public static void main(String[] args) {
        // Create an instance of the ATMExample class
        ATM atm = new ATM();

        // Initialize the scanner object
        atm.sc = new Scanner(System.in);

        // Start the ATM program
        atm.start();
    }

    private void start() {
        // Display the main menu
        System.out.println("Welcome TO CU Bank");
        System.out.println("Choose 1 for Withdraw");
        System.out.println("Choose 2 for Deposit");
        System.out.println("Choose 3 for Check Balance");
        System.out.println("Choose 4 for EXIT");
        System.out.print("Please Select an Option:\n");

        // Get the user's choice
        int choice = sc.nextInt();

        // Switch on the user's choice
        switch(choice) {
            case 1:
                // Withdraw money
                withdrawMoney();
                break;
            case 2:
                // Deposit money
                depositMoney();
                break;
            case 3:
                // Check balance
                checkBalance();
                break;
            case 4:
                // Exit the ATM program
                System.exit(0);
                break;
            default:
                // Invalid choice
                System.out.println("Invalid choice. Please try again.");
        }

        // Start the ATM program again
        start();
    }

    private void withdrawMoney() {
        // Get the amount to withdraw
        System.out.print("Enter amount to be withdrawn:");
        int amount = sc.nextInt();

        // Check if the balance is sufficient
        if(amount <= balance) {
            // Withdraw the money
            balance -= amount;
            System.out.println("Please collect your money");
        } else {
            // Insufficient balance
            System.out.println("Insufficient Balance");
        }
    }

    private void depositMoney() {
        // Get the amount to deposit
        System.out.print("Enter amount to be deposited:");
        int amount = sc.nextInt();

        // Deposit the money
        balance += amount;
        System.out.println("Your Money has been successfully deposited");

    }

    private void checkBalance() {
        // Display the balance
        System.out.println("Balance : " + balance);
    }
}
