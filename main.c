#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
    
    printf("-------------TWIXT----------------\n");
    char board[25][25];
    new_game(board);
    /*printf("For new game type: 'new'\n");
    char k[50];
    scanf("%49s",k);
    char board[25][25];
    if(strcmp(k,"new")==0){
        
    }
    else{
        printf("Incorrect command.\n");
        //break;
    }*/

    Link links[1000];
    int link_count = 0;

    int go_red_go[24] = {0};
    int go_black_go[24] = {0};
    int next_cluster_id = 1;

    int game=1;
    char current_player = 'R';
    char next_player = 'B';

    printf("Red starts.\n");

    while(game==1){

        print_links(links, link_count);

        int row;
        int column;
        printf("\nPlayer %c's Turn\n", current_player);
        printf("Enter the row number and column number in range 1 to 24 or enter '0 0' to start new game or exit.\n");
        //scanf("%d %d", &row, &column);

        int result = scanf("%d %d", &row, &column);

        if (result != 2) {
            printf("Invalid input! Please enter integers only.\n");
            scanf("%*s"); 
        }

        if(row==0 && column==0){
            char str[10];
            printf("Enter:\n");
            printf("new: to start new game\n");
            printf("exit: to exit game\n");

            scanf("%9s", str);
            if(strcmp(str,"new")==0){
                printf("--------------------New Game-----------------------\n");
                new_game(board);
                link_count = 0;
                for(int k=0; k<24; k++){
                    go_red_go[k]=0;
                    go_black_go[k]=0;
                }
                next_cluster_id = 1;
                current_player = 'R'; 
                next_player = 'B';
            }
            else if(strcmp(str, "exit")==0){
                game=0;
            }
            else{
                break;
            }
        }

        else if(row>24||column>24){
            printf("Invalid input!\n");
        }

        else if(board[row][column]=='*'){
            
            if(current_player=='R'&& column==1||current_player=='R'&& column==24){
                printf("Not a valid input as it crosses the border of Black.\n");
                //swap('R', 'B');
            }
            else if(current_player=='B'&& row==1||current_player=='B'&& row==24){
                printf("Not a valid input as it crosses the border of Red.\n");
                //swap('R', 'B');
            }
            else{
                board[row][column] = current_player;

                int dr[] = {-2, -2, -1, -1,  1, 1,  2, 2};
                int dc[] = {-1,  1, -2,  2, -2, 2, -1, 1};

                for(int i=0; i<8; i++){
                    int r2 = row + dr[i];
                    int c2 = column + dc[i];

                    if(r2 >= 1 && r2 <= 24 && c2 >= 1 && c2 <= 24){
                        if(board[r2][c2] == current_player){
                            if(overlap(row, column, r2, c2, links, link_count) == 1){
                                printf("Cannot link to (%d,%d) because it overlaps another link!\n", r2, c2);
                            }
                            
                            else{links[link_count].row1 = row;
                                links[link_count].col1 = column;
                                links[link_count].row2 = r2;
                                links[link_count].col2 = c2;
                                links[link_count].player = current_player;
                                
                                link_count++;
                                printf("Link created between (%d,%d) and (%d,%d)!\n", row, column, r2, c2);

                                wanna_win(row, column, r2, c2, current_player, go_red_go, go_black_go, &next_cluster_id);
                            }
                        }
                    }
                }
                
                swap(&current_player, &next_player);
                print_board(board);

                /*if (did_i_win(red_rows) == 1){
                    printf("\n*** RED WINS! ***\n");
                    game = 0;
                }
                else if (did_i_win(black_cols) == 1){
                    printf("\n*** BLACK WINS! ***\n");
                    game = 0;
                }*/
               if (yay_i_won(go_red_go) == 1) {
                    printf("---------------------RED WINS!-------------------------\n");
                    game = 0;
                }
                else if (yay_i_won(go_black_go) == 1) {
                    printf("--------------------BLACK WINS!-------------------------\n");
                    game = 0;
                }
            }
            
        }
        else{
            printf("Place taken!\n");
        }
    }
    return 0;
}