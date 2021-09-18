#include <stdio.h>
char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkwin();
void board();
int main()
{
    printf("\e[1;1H\e[2J");
    printf("\n\n\tTic Tac Toe - choi la thanh Shark Toe!!\n\n");

    int player = 1, i, choice;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Trong trường hợp này, toi khang dinh toi khong lien quan \n den ban thu %d nen ban di nuoc di nay di: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            printf("Nuoc di hay day, nhung sai roi. Di lai di my fence :)");
            player--;
            getchar();
        }
        i = checkwin();
        player++;
    } while (i == -1);
    board();
    if (i == 1)
        printf("\a'Ban tang chua ngan ai bao gio'\n- nguoi thu %d said.", --player);
    else
        printf("\aSuc 2 thanh bang nhau, ban tang khong dam xet xu ah.");
    getchar();
    return 0;
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void board()
{
    printf("\n\n\n");
    printf("Nguoi choi 1 [X]  -  Nguoi choi 2 [O]\n\n\n");
    printf("___________________\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
    printf("|_____|_____|_____|\n\n\n");
}