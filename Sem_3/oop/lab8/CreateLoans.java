package lab8;

import java.util.Scanner;

public class CreateLoans {
    public static void main(String[] args) {
        PersonalLoan[] arr1 = new PersonalLoan[100];
        BusinessLoan[] arr2 = new BusinessLoan[100];
        float prime_interest_rate;
        String customer_last;
        int amount, term;
        double final_amount;
        PersonalLoan a1;
        BusinessLoan a2;


        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the current prime interest rate: ");
        prime_interest_rate = scan.nextFloat();
        int repeat = 1;
        int index1 = 0;
        int index2 = 0;
        int is_businness;
        while(repeat == 1) {
            System.out.print("Enter your last name: ");
            customer_last = scan.next();
            System.out.print("Enter the loan amount: ");
            amount = scan.nextInt();
            System.out.print("Enter the term in years: ");
            term = scan.nextInt();
            System.out.print("If you are a business type 1, else type 2: ");
            is_businness = scan.nextInt();
            if(is_businness == 1) {
                arr2[index2] = new BusinessLoan(prime_interest_rate, index2, customer_last, amount, term);
                if(arr2[index2].is_valid) {
                    index2++;
                }
                else {
                    System.out.println("We do not allow loan amounts over 1,00,000 rupees");
                }
            }
            else {
                arr1[index1] = new PersonalLoan(prime_interest_rate, index1, customer_last, amount, term);
                if(arr1[index1].is_valid) {
                    index1++;
                }
                else {
                    System.out.println("We do not allow loan amounts over 1,00,000 rupees");
                }
            }
            System.out.println("If you want to feed more loans, then press 1, else any other number.");
            repeat = scan.nextInt();
        }
        scan.close();
        if(index2 != 0) {
            System.out.println();
            System.out.println("****Business Loans****");
            for (int i=0; i<index2; i++) {
                System.out.println();
                System.out.println("--------------------");
                System.out.println("Loan number: "+arr2[i].loan_number);
                System.out.println("Customer Last name: "+arr2[i].customer_last_name);
                System.out.println("Amount of loan: "+arr2[i].amount);
                System.out.println("Interest rate: "+arr2[i].interest_rate);
                System.out.println("Term: "+arr2[i].term);
                final_amount = arr2[i].amount*(1+arr2[i].interest_rate/100.0);
                System.out.println("Total amount owed at the due date: "+final_amount);
                System.out.println("--------------------");
            }
        }
        if(index1 != 0) {
            System.out.println();
            System.out.println("****Personal Loans****");
            for (int i=0; i<index1; i++) {
                System.out.println();
                System.out.println("--------------------");
                System.out.println("Loan number: "+arr1[i].loan_number);
                System.out.println("Customer Last name: "+arr1[i].customer_last_name);
                System.out.println("Amount of loan: "+arr1[i].amount);
                System.out.println("Interest rate: "+arr1[i].interest_rate);
                System.out.println("Term: "+arr1[i].term);
                final_amount = arr1[i].amount*(1+arr1[i].interest_rate/100.0);
                System.out.println("Total amount owed at the due date: "+final_amount);
                System.out.println("--------------------");
            }
        }
    }
}
