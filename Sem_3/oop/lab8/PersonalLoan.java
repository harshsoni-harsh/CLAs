package lab8;
public class PersonalLoan extends Loan {
    PersonalLoan(float prime_interest_rate, int loan_num, String customer_last, int amoun, int ter) {
        super(loan_num, customer_last, amoun, ter);
        interest_rate = 2 + prime_interest_rate;
    }
}