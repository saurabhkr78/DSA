

import java.util.Scanner;
class InsufficientBalanceException extends Exception
 {

    public InsufficientBalanceException(String message)
     {
        super(message);
    }
}







class Bank
{
    private int balance;
      
    public Bank(int initialBalance) 
    {
        balance = initialBalance;
    }




    public void withdraw(int amount) throws InsufficientBalanceException
     {
        if (amount <= 0) throw new IllegalArgumentException("Invalid withdrawal amount");

        if (amount > balance) throw new InsufficientBalanceException("Insufficient balance to withdraw $" + amount);

        balance =balance-amount;
        System.out.println(+ amount +"Withdrawn" + " successfully");
    }



    public int getBalance() {
        return balance;
    }
}




public class BankingApplication
 {
    public static void main(String[] args)
     {
        Bank account = new Bank(1000);

        try
         {
            System.out.println("Enter The Amount to be Withdrawn:");
            Scanner sc=new Scanner(System.in);
            int x=sc.nextInt();
            account.withdraw(x);
            System.out.println("Balance after first withdrawal=" + account.getBalance());

            account.withdraw(800);
            System.out.println("Balance after second withdrawal=" + account.getBalance());
        }
         catch (InsufficientBalanceException | IllegalArgumentException e) 
         {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
