package lab8;
class MyException extends Exception {}

public abstract class Loan implements LoanConstants {
    int loan_number;
    String customer_last_name;
    int amount;
    int term;
    float interest_rate;
    boolean is_valid = true;
    Loan(int loan_num, String customer_last, int amoun, int ter) {
        if(amoun > LoanConstants.max_amount) {
            System.out.println("Loan amount can't exceed 1,00,000");
            is_valid = false;
        }
        loan_number = loan_num;
        customer_last_name = customer_last;
        amount = amoun;
        if(ter != short_term && ter != medium_term && ter != long_term) {
            term = short_term;
            System.out.println("Sorry! We don't provide term of "+ter+" years.");
            System.out.println("Selecting short-term of 1 year");
        }
        else {
            term = ter;
        }
    }
    public String toString() {
        String out = "";
        out += "Loan number: "+loan_number+ "\n";
        out += "Customer Last Name: "+customer_last_name+ "\n";
        out += "Amount: "+amount+ "\n";
        out += "Term: "+term+ "\n";
        out += "Interest Rate: "+interest_rate+ "\n";
        return out;
    }
}