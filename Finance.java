import java.util.Scanner;

public class Finance{
    
    public static double futureInvestmentValue(double investmentAmount, double annualInterestRate, int years){
        //using the formula provided
        double futureValue=investmentAmount*Math.pow(1+annualInterestRate, years);
        return futureValue;
    }
    public static void printTable(double investmentAmount, double annualInterestRate){
        double futureValue=investmentAmount;
        System.out.println("Years       Future Value");
        //multiplying investamount by (1+annualinterestrate) at every step
        for(int i=1;i<=30;i++){
            futureValue*=(1+annualInterestRate);
            System.out.println(i+"    "+futureValue);
        }
    }
    public static void main(String[] args) {
        //taking input parameters
        System.out.print("The amount Invested: ");
        Scanner sc=new Scanner(System.in);
        double amount=sc.nextDouble();
        System.out.print("Annual Interest Rate: ");
        double rate=sc.nextDouble();
        sc.close();
        int years=5;
        //print table for 1-30 years
        printTable(amount, rate);
        //calling futureinvestment value function at 5 years
        double futureValue=futureInvestmentValue(amount, rate, years);
        System.out.println("Amount after "+years+" years: "+futureValue);

    }
}