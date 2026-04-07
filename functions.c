#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void new_game(char board[25][25]){
    
    for(int i=0;i<25;i++){
        if(i==0){
            for(int j=0;j<25;j++){
                if(j==0){
                    printf(" X ");
                }
                else if(j==1||j==23){
                    printf("%2d|",j);
                }
                else{
                    printf("%2d ",j);
                }
                
            }
        }
        else if(i==1){
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d__",i);
                }

                else{
                    if(j==1){
                        board[i][j]=' ';
                        printf("%c|_",board[i][j]);
                    }
                    else if(j==23){
                        board[i][j]='*';
                        printf("%c|_",board[i][j]);
                    }
                    else if(j==24){
                        board[i][j]=' ';
                        printf("%c__",board[i][j]);
                    }
                    else{
                        board[i][j]='*';
                        printf("%c__",board[i][j]);
                    }
                    
                }
                
            }
        }
        else if(i==23){
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d__",i);
                }

                else{
                    if(j==1){
                        board[i][j]='*';
                        printf("%c|_",board[i][j]);
                    }
                    else if(j==23){
                        board[i][j]='*';
                        printf("%c|_",board[i][j]);
                    }
                    else{
                        board[i][j]='*';
                        printf("%c__",board[i][j]);
                    }
                    
                }
                
            }
        }
        else if(i==24){
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d  ",i);
                }
                else{
                    if(j==1){
                        board[i][j]=' ';
                        printf("%c| ",board[i][j]);
                    }
                    else if(j==23){
                    
                        board[i][j]='*';
                        printf("%c| ",board[i][j]);
                        
                    }
                    else if(j==24){
                        board[i][j]=' ';
                        printf("%c  ",board[i][j]);
                    }
                    else{
                        board[i][j]='*';
                        printf("%c  ",board[i][j]);
                    }
                    
                }
                
            }
        }
        else{
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d  ",i);
                }
                else{
                    if(j==1||j==23){
                    
                        board[i][j]='*';
                        printf("%c| ",board[i][j]);
                        
                    }
                    else{
                        board[i][j]='*';
                        printf("%c  ",board[i][j]);
                    }
                    
                }
                
            }
        }
        
        printf("\n");
    }
}

void print_board(char board[25][25]){
    for(int i=0;i<25;i++){
        if(i==0){
            for(int j=0;j<25;j++){
                if(j==1||j==23){
                    printf("%2d|",j);
                }
                else{
                    printf("%2d ",j);
                }
            
            }
        }
        else if(i==1||i==23){
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d__",i);
                }
                else{
                    if(j==1||j==23){
                        printf("%c|_", board[i][j]);
                    }
                    else{
                        printf("%c__", board[i][j]);
                    }
                    
                }
                    
            } 
        }    
        else{
            for(int j=0;j<25;j++){
                if(j==0){
                    printf("%2d  ",i);
                }
                else{
                    if(j==1||j==23){
                        printf("%c| ", board[i][j]);
                    }
                    else{
                        printf("%c  ", board[i][j]);
                    }
                    
                }
                    
            }            
        }
        printf("\n");
        
    }
    
}

void swap(char *a, char *b){
    char temp;
    temp=*a;
    *a = *b;
    *b = temp;
}

void print_links(Link links[], int count){
    printf("\n--- ACTIVE LINKS ---\n");
    if(count == 0) {
        printf("None\n");
    }
    for(int i=0; i<count; i++){
        printf("%c Link: (%d,%d) <--> (%d,%d)\n", links[i].player, links[i].row1, links[i].col1, links[i].row2, links[i].col2);
    }
    printf("--------------------\n");
}

/*int overlap(int r1, int c1, int r2, int c2, Link links[], int count){
    int new_r_sum = r1 + r2;
    int new_c_sum = c1 + c2;

    for(int i=0; i<count; i++){

        int old_r_sum = links[i].row1 + links[i].row2;
        int old_c_sum = links[i].col1 + links[i].col2;

        if(new_r_sum == old_r_sum && new_c_sum == old_c_sum){
            return 1;
        }
    }
    return 0;
}*/

int eh_check_link_the_way_i_want_for_overlap_condition(int r1, int c1, int r2, int c2, Link l){
    if (l.row1 == r1 && l.col1 == c1 && l.row2 == r2 && l.col2 == c2) return 1;
    if (l.row1 == r2 && l.col1 == c2 && l.row2 == r1 && l.col2 == c1) return 1;
    return 0;
}

int overlap(int r1, int c1, int r2, int c2, Link links[], int count){
    
    if (r1 > r2) {
        int t;
        t=r1;
        r1=r2;
        r2=t;
        t=c1;
        c1=c2;
        c2=t;
    }

    int dr = r2 - r1;
    int dc = c2 - c1;

    for(int i=0; i<count; i++){
        
        //(r,c) -> (r+2, c+1)
        if (dr == 2 && dc == 1){
            //midpoint thingy (r, c+1) -> (r+2, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1+1, r2, c1, links[i])) return 1;
            
            //upper thingy (r-1, c+1) -> (r+1, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1-1, c1+1, r1+1, c1, links[i])) return 1;

            //lower thingy (r+1, c+1) -> (r+3, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1+1, c1+1, r1+3, c1, links[i])) return 1;
        }

        // (r,c) -> (r+2, c-1)
        else if (dr == 2 && dc == -1){
            // middle thingy (r, c-1) -> (r+2, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1-1, r2, c1, links[i])) return 1;

            // upper thingy (r-1, c-1) -> (r+1, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1-1, c1-1, r1+1, c1, links[i])) return 1;

            // lower thingy (r+1, c-1) -> (r+3, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1+1, c1-1, r1+3, c1, links[i])) return 1;
        }

        //(r,c) -> (r+1, c+2)
        else if (dr == 1 && dc == 2){
            // middle (r, c+2) -> (r+1, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1+2, r2, c1, links[i])) return 1;

            // left (r+1, c-1) -> (r, c+1)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r2, c1-1, r1, c1+1, links[i])) return 1;

            // right (r, c+3) -> (r+1, c+1)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1+3, r2, c1+1, links[i])) return 1;
        }

        //(r,c) -> (r+1, c-2)
        else if (dr == 1 && dc == -2){
            // middle (r, c-2) -> (r+1, c)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1-2, r2, c1, links[i])) return 1;

            // right (r+1, c+1) -> (r, c-1)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r2, c1+1, r1, c1-1, links[i])) return 1;

            // left (r, c-3) -> (r+1, c-1)
            if (eh_check_link_the_way_i_want_for_overlap_condition(r1, c1-3, r2, c1-1, links[i])) return 1;
        }
    }
    return 0;
}

/*int did_i_win(int arr[]){
    int sum = 0;

    for(int i=0; i<24; i++){
        sum += arr[i];
    }

    if(sum == 24) return 1;
    return 0;
}*/

void link_join_or_not(int i1, int i2, int tracker[], int *next_id){
    if (i1 < 0 || i1 > 23 || i2 < 0 || i2 > 23) return;

    int id1 = tracker[i1];
    int id2 = tracker[i2];

    // Both empty the create new cluster
    if (id1 == 0 && id2 == 0){
        int new_id = *next_id;
        (*next_id)++;
        tracker[i1] = new_id;
        tracker[i2] = new_id;
        if (i1 - i2 == 2 || i2 - i1 == 2) tracker[(i1+i2)/2] = new_id;
    }
    // If 1 exists and next doesnt then merge it with 1st
    else if (id1 != 0 && id2 == 0){
        tracker[i2] = id1;
        if (i1 - i2 == 2 || i2 - i1 == 2) tracker[(i1+i2)/2] = id1;
    }
    else if (id1 == 0 && id2 != 0){
        tracker[i1] = id2;
        if (i1 - i2 == 2 || i2 - i1 == 2) tracker[(i1+i2)/2] = id2;
    }
    // Both diff then merge them
    else if (id1 != id2){
        int old_id = id2;
        int now_id = id1;
        
        for (int i = 0; i < 24; i++){
            if (tracker[i] == old_id){
                tracker[i] = now_id;
            }
        }
        if (i1 - i2 == 2 || i2 - i1 == 2) tracker[(i1+i2)/2] = now_id;
    }
    
    else{
        if (i1 - i2 == 2 || i2 - i1 == 2) tracker[(i1+i2)/2] = id1;
    }
}

void wanna_win(int r1, int c1, int r2, int c2, char player, int go_red_go[], int go_black_go[], int *next_cluster_id){
    
    if (player == 'R'){
        link_join_or_not(r1-1, r2-1, go_red_go, next_cluster_id);
    } 
    else{
        link_join_or_not(c1-1, c2-1, go_black_go, next_cluster_id);
    }
}

int yay_i_won(int clusters[]){
    if (clusters[0] != 0 && clusters[0] == clusters[23]){
        return 1;
    }
    return 0;
}