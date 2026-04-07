#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void swap(char *a, char *b);
void print_board(char board[25][25]);
void new_game(char board[25][25]);

typedef struct Link{
    int row1, col1;
    int row2, col2;
    char player;
} Link;

void print_links(Link links[], int count);
int eh_check_link_the_way_i_want_for_overlap_condition(int r1, int c1, int r2, int c2, Link l);
int overlap(int r1, int c1, int r2, int c2, Link links[], int count);
//int did_i_win(int arr[]);
void wanna_win(int r1, int c1, int r2, int c2, char player, int go_red_go[], int go_black_go[], int *next_cluster_id);
int yay_i_won(int clusters[]);

#endif