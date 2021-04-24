package Java.BankingApplication;

import java.util.Scanner;

public class BankingApplication {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("How many customers do you have?");
        int n = sc.nextInt();
        Customer[] customers = new Customer[n];
        System.out.println("Please provide the information for each customer:");
        for(int i=0; i<n; i++){
            System.out.println("Information of customer " + i + ": ");
            String customerName, customerId;
            System.out.println("Enter name: ");
            customerName = sc.next();
            System.out.println("Enter ID: ");
            customerId = sc.next();
            customers[i] = new Customer(customerName, customerId);
        }
        // for(int i=0; i<n; i++){
        //     customers[i].display();
        // }
        System.out.println("\n");
        System.out.println("Welcome to online banking system!");
        boolean second = false;
        do {
            for(int i=0; i<50; i++) System.out.println("\n");
            if (second){
                System.out.println("Your provided information does not match any account!");
                System.out.println("Please enter your information again!");
            }
            String customerName, customerId;
            System.out.println("Please enter your name: ");
            customerName = sc.next();
            System.out.println("Please enter your ID :");
            customerId = sc.next();
            boolean found = false;
            for(int i=0; i<n; i++){
                if (customers[i].getCustomerName().equals(customerName) && customers[i].getCustomerId().equals(customerId)){
                    found = true;
                    break;
                }
            }
            second = true;
            if (!found){
                continue;
            }
            System.out.println("We have found your account! Please wait!");
            if (found) break;
            
        } while (true);
    }
}
