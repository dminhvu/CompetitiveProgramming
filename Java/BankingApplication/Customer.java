package Java.BankingApplication;

public class Customer{
    private int customerBalance, lastTransaction;
    private String customerName, customerId;
    public Customer(String customerName, String customerId){
        this.customerName = customerName;
        this.customerId = customerId;
        this.customerBalance = 0;
        this.lastTransaction = 0;
    }
    public void deposit(int amount){
        if (amount>0){
            customerBalance += amount;
        }
    }
    public String getCustomerName(){
        return customerName;
    }
    public String getCustomerId(){
        return customerId;
    }
    public void display(){
        System.out.println("Name: " + customerName);
        System.out.println("ID: " + customerId);
    }
}