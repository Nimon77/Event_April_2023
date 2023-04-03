#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s <cards>", argv[0]);
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < strlen(argv[1]); i++){
        if (argv[1][i] == 'A'){
            if (sum + 11 > 21){
                sum += 1;
            } else {
                sum += 11;
            }
        } else if (argv[1][i] == 'T' || argv[1][i] == 'J' || argv[1][i] == 'D' || argv[1][i] == 'K'){
            sum += 10;
        } else {
            sum += argv[1][i] - '0';
        }
    }
    if (sum == 21)
        printf("Blackjack!\n");
    else
        printf("%d\n", sum);
}