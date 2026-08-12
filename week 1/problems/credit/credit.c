#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void){
    int sum = 0, count = 0, tmp = 0;
    long int card_number = get_long("Number: ");
    long int backup = card_number;

    while (card_number > 0) {
        if(count%2==0){sum = sum + card_number % 10;}
        else{
            if(card_number % 10 < 5){sum = sum + 2 * (card_number % 10);}
            else{
                tmp = 2 * (card_number % 10);
                sum = sum + (tmp % 10);
                tmp /= 10;
                sum = sum + (tmp % 10);
            }
        }
        card_number /= 10;
        count++;
    }
    if(sum % 10 != 0 || count < 12 || count > 16){
        printf("INVALID\n");
    }else{
        int first, second;
        for(int i = 0; i < count-2; i++){
            backup /= 10;
        }

        first = backup/10;

        if(first == 4 && (count == 16 || count == 13)){
            printf("VISA\n");
        }else if((backup == 34 || backup == 37) && count == 15){
            printf("AMEX\n");
        }else if((backup == 51 || backup == 52 || backup == 53 || backup == 54 || backup == 55) && count == 16){
            printf("MASTERCARD\n");
        }else{
            printf("INVALID\n");
        }
    }
}
