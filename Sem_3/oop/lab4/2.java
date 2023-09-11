import java.util.*;
class game
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String[] vocabs = new String[5];
        String[] meaning = new String[5];
        vocabs[0] = "Ab_initio";
        vocabs[1] = "Ad_hoc";
        vocabs[2] = "Alma_mater";
        vocabs[3] = "Apropos";
        vocabs[4] = "Alibi";
        meaning[0] = "From_the_beginning";
        meaning[1] = "Extempore";
        meaning[2] = "school";
        meaning[3] = "reference_to";
        meaning[4] = "false_excuse";

        int[] discarded = new int[5];
        Arrays.fill(discarded, -1);
        int top = 0;
        int correct = 0;
        String input;
        while(correct < 5)
        {
            if(top == 5)
            {
                top = 0;
            }
            int resume=1;
            for (int i=0; i<5; i++)
            {
                if(discarded[i]==top)
                {
                    resume=0;
                    break;
                }
            }
            if(resume==1)
            {

                System.out.print("\nEnter word the foreign word for "+meaning[top]+": ");
                input = scan.next();
                if(vocabs[top].compareTo(input) == 0)
                {
                    System.out.println("You got this right!");
                    discarded[correct++] = top;
                }
                else
                {
                    System.out.println("Wrong!");
                }
            }
            top++;
        }
        System.out.println("You answered all answers correctly.");
        scan.close();
    }
}