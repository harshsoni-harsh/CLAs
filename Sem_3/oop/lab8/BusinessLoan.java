package lab8;
public class BusinessLoan extends Loan {
    BusinessLoan(float prime_interest_rate, int loan_num, String customer_last, int amoun, int ter) {
        super(loan_num, customer_last, amoun, ter);
        interest_rate = 1 + prime_interest_rate;
    }
}