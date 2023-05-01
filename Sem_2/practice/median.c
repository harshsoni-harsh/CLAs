#include <stdio.h>
#include <stdbool.h>
#include <time.h>

char * longestPalindrome(char * s){
    int len;
    for (len=0; s[len]!='\0'; len++);
    if(len%2==0)
    {
        char s1[2*len+1];
        int calc=2*len+1;
        for (int i=0; i<calc; i++)
        {
            if(i%2==0)
            {
                s1[i]='|';
            }
            else
            {
                s1[i]=s[len--];
            }
        }
        int prev=0;
        int next=0;
        int start_index=0;
        int end_index=0;
        int final=0;
        for (int i=1; i<calc; i++)
        {
            while(prev!=-1)
            {
                if(next!=calc && s1[prev]==s1[next])
                {
                    if((next-prev)>final)
                    {
                        final=next-prev;
                        start_index=prev;
                        end_index=next;
                    }
                    if(prev>0)
                        prev--;
                    else
                        break;
                    if(next!=calc)
                        next++;
                    else
                        break;
                }
                else break;
            }
            prev=i-1;
            next=i+1;
        }
        char out[final];
        int index=0;
        for (int i=0; i<final; i++)
        {
            if(s1[start_index+i]!='|')
            out[index++]=s1[start_index+i];
        }
        for (int i=0; i<final; i++)
        {
            s[i]=out[i];
        }
        s[final]=0;
        return s;
    }
    else
    {
        int prev=0;
        int next=0;
        int start_index=0;
        int end_index=0;
        int final=0;
        for (int i=1; i<len; i++)
        {
            while(prev!=-1)
            {
                if(next!=len && s[prev]==s[next])
                {
                    if((next-prev)>final)
                    {
                        final=next-prev;
                        start_index=prev;
                        end_index=next;
                    }
                    if(prev>0)
                        prev--;
                    else
                        break;
                    if(next!=len)
                        next++;
                    else
                        break;
                }
                else break;
            }
            prev=i-1;
            next=i+1;
        }
        if(s[start_index]!=s[end_index])
        {
            if(start_index!=0 && s[start_index-1]==s[end_index])
            {
                start_index--;
            }
            else if(start_index!=0 && s[start_index+1]==s[end_index])
            {
                start_index++;
            }
            else if(end_index!=len-1 && s[end_index+1]==s[start_index])
            {
                end_index++;
            }
        }
        int index=0;
        for (int i=0; i<final; i++)
        {
            s[index++]=s[start_index+i];
        }
        if(s[0]!=s[index])
        s[++index]=0;
        return s;
    }
}

void main()
{
    clock_t start_time, end_time;
    double runtime;
    start_time=clock();
    char st[]="cbb";
    //char st[]="wwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd";
    longestPalindrome(st);
    end_time=clock();
    runtime = ((double)(end_time-start_time))/CLOCKS_PER_SEC;
    printf("%s  :: %lf\n", st, runtime);

}