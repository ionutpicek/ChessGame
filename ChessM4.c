#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// black = -
// white = unsigned
// rook = 5
// knight = 2
// bishop = 3
// queen = 9
// king = 10
// pawn = 1
// empty space = 0
#define X 0
#define Y 1
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int table[8][8] = {
        {-5, -2, -3, -9, -10, -3, -2, -5},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {5, 2, 3, 9, 10, 3, 2, 5}
    };

int chesstable()
{
    printf("      _________________________________________________________________\n      |       |       |       |       |       |       |       |       |");
    printf("\n  0");
    for(int i = 0; i < 8; i++){
         for(int j = 0; j < 8; j++)
            {
                printf("   | ");
                printf("%3d", table[i][j]);
            }
        printf("   |");
        printf("\n");
        printf("      |_______|_______|_______|_______|_______|_______|_______|_______|\n");
        if(i < 7)
            printf("      |       |       |       |       |       |       |       |       |");
        printf("\n");
        int d;
        d = i+1;
        if(d < 8)
            printf("  %d", d);
       }
        printf("   ");
       for(int i = 0; i < 8; i++){
        printf("       %d", i);
       }
        printf("\n");

}

/*int convert_leter_position(char OX)
{
    switch(OX){
        case 'A':{
            return 0;
        }
        case 'B':{
            return 1;
        }
        case 'C':{
            return 2;
        }
        case 'D':{
            return 3;
        }
        case 'E':{
            return 4;
        }
        case 'F':{
            return 5;
        }
        case 'G':{
            return 6;
        }
        case 'H':{
            return 7;
        }
    }
}

char convert_position_leter(int OY)
{
    switch(OY){
        case 0:{
            return 'A';
        }
        case 1:{
            return 'B';
        }
        case 2:{
            return 'C';
        }
        case 3:{
            return 'D';
        }
        case 4:{
            return 'E';
        }
        case 5:{
            return 'F';
        }
        case 6:{
            return 'G';
        }
        case 7:{
            return 'H';
        }
    }
}*/
int count_wpawn()
{
    int i;
    int j;
    int k = 0;
    for(i = 0; i<8; i++)
        for(j = 0; j<8; j++)
            if(table[i][j] == 1)
                k++;
    return k;
}
int count_bpawn()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == -1){
                k++;
            }
        }
    }
    return k;
}
int count_wknight()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == 2){
                k++;
            }
        }
    }
    return k;
}
int count_bknight()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == -2){
                k++;
            }
        }
    }
    return k;
}
int count_wbishop()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == 3){
                k++;
            }
        }
    }
    return k;
}
int count_bbishop()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == (-3)){
                k++;
            }
        }
    }
    return k;
}
int count_wrook()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == 5){
                k++;
            }
        }
    }
    return k;
}
int count_brook()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == (-5)){
                k++;
            }
        }
    }
    return k;
}
int count_wqueen()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == 9){
                k++;
            }
        }
    }
    return k;
}
int count_bqueen()
{
    int k = 0;
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(table[i][j] == (-9)){
                k++;
            }
        }
    }
    return k;
}
int double_wpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == 1){
                if(table[i-1][j] == 1 || table[i+1][j] == 1){
                    k=k+1;
                }
            }
        }
    }
    return k;
}
int double_bpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == -1){
                if(table[i-1][j] == -1 || table[i+1][j] == -1){
                    k=k+1;
                }
            }
        }
    }
    return k;
}
int isolated_wpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == 1){
                if(table[i][j-1] != 1)
                    if(table[i][j+1] != 1)
                        if(table[i+1][j] != 1)
                            if(table[i-1][j] != 1)
                                if(table[i+1][j+1] != 1)
                                    if(table[i-1][j-1] != 1)
                                        if(table[i-1][j+1] != 1)
                                            if(table[i+1][j-1] != 1)
                                                k++;
              }
            }
        }
    return k;
}
int isolated_bpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == -1){
                if(table[i][j-1] != -1)
                    if(table[i][j+1] != -1)
                        if(table[i+1][j] != -1)
                            if(table[i-1][j] != -1)
                                if(table[i+1][j+1] != -1)
                                    if(table[i-1][j-1] != -1)
                                        if(table[i-1][j+1] != -1)
                                            if(table[i+1][j-1] != -1)
                                                k++;
              }
            }
        }
    return k;
}
int blocked_wpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == 1)
                if(table[i-1][j] == -1)
                    k++;
        }
    }
    return k;
}
int blocked_bpawn()
{
    int k = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(table[i][j] == -1)
                if(table[i-1][j] == 1)
                    k++;
        }
    }
    return k;
}
int white_mobility()
{
    int p0[2];
    int p1[2];
    int b0[2];
    int b1[2];
    int q0[2];
    int q1[2];
    int k0[2];
    int k1[2];
    int r0[2];
    int r1[2];
    int king0[2];
    int king1[2];
    int i;
    int j;
    int contor = 0;
    int aux = 0;
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        p0[X] = x;
        p0[Y] = y;
    for(i=0; i<8; i++){                     //pawn moves
        for(j=0; j<8; j++){
            p1[X] = i;
            p1[Y] = j;

            if(table[p0[X]][p0[Y]] == 1){
                if((p0[Y] == p1[Y]) && ((p0[X] - 1) == p1[X])){     //verificare mutare normala
                    if(table[p1[X]][p1[Y]] == 0)
                        aux = 1;
                }
            if(p0[X] == 6){
            if((p0[Y] == p1[Y]) && ((p0[X] - 2) == p1[X])){     //verificare mutare normala
                if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        }
                if(table[p1[X]][p1[Y]] < 0)
                    if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] + 1) == p1[X])){     //verificare captura
                        if(table[p1[X]][p1[Y]] > 0)
                            aux = 1;
                }
            }
            if(aux == 1){
                contor++;
            }
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        r0[X] = x;
        r0[Y] = y;
    for(i=0; i<8; i++){                 //rook moves
        for(j=0; j<8; j++){
            r1[X] = i;
            r1[Y] = j;
            if(table[r0[X]][r0[Y]] == 5){
                if(r0[X] == r1[X]){
                    if(r0[Y]-r1[Y] < 0){
                        for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                            if(table[r0[X]][r0[Y]+i] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]][r0[Y]+i] < 0){
                                if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]][r0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[Y]-r1[Y] > 0){
                    for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                        if(table[r0[X]][r0[Y]-i] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]][r0[Y]-i] < 0){
                            if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]][r0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(r0[Y] == r1[Y]){
                    if(r0[X]-r1[X] < 0){
                        for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                            if(table[r0[X]+i][r0[Y]] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]+i][r0[Y]] < 0){
                                if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]+i][r0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[X]-r1[X] > 0){
                    for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                        if(table[r0[X]-i][r0[Y]] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]-i][r0[Y]] < 0){
                            if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]-i][r0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
        }
            if(aux == 1)
                contor++;
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        k0[X] = x;
        k0[Y] = y;
    for(i = 0; i<8; i++){               //knight moves
        for(j = 0; j<8; j++){
            k1[X] = i;
            k1[Y] = j;
            if (table[k0[X]][k0[Y]] == 2)  //white
            {
                if(((abs(k0[X]-k1[X]) == 1 && abs(k0[Y]-k1[Y]) == 2) || (abs(k0[X]-k1[X]) == 2 && abs(k0[Y]-k1[Y]) == 1)))//the position isn't occupied by another white piece
                    if(table[k1[X]][k1[Y]] <= 0){
                        contor++;
                    }
            }
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        b0[X] = x;
        b0[Y] = y;
    for(i = 0; i< 8; i++){                  //bishop moves
        for(j = 0; j<8; j++){
    b1[X] = i;
    b1[Y] = j;
    if(table[b0[X]][b0[Y]] == 3){
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] > 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] < 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    if(aux == 1)
        contor++;
    aux = 0;
        }
        }
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        king0[X] = x;
        king0[Y] = y;
    for(i = 0; i< 8; i++){                  //king moves
        for(j = 0; j<8; j++){
    king1[X] = i;
    king1[Y] = j;
    if(table[king0[X]][king0[Y]] == 10){
    if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] > 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] < 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if(aux == 1)
            contor++;
    aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        q0[X] = x;
        q0[Y] = y;
    for(i=0; i<8; i++){                 //queen moves
        for(j=0; j<8; j++){
            q1[X] = i;
            q1[Y] = j;
            if(table[q0[X]][q0[Y]] == 9){
                if(q0[X] == q1[X]){                         //mutare pe linie (rook)
                    if(q0[Y]-q1[Y] < 0){
                        for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                            if(table[q0[X]][q0[Y]+i] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]][q0[Y]+i] < 0){
                                if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]][q0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[Y]-q1[Y] > 0){
                    for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                        if(table[q0[X]][q0[Y]-i] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]][q0[Y]-i] < 0){
                            if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]][q0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(q0[Y] == q1[Y]){                                         //mutare pe coloana(rook)
                    if(q0[X]-q1[X] < 0){
                        for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                            if(table[q0[X]+i][q0[Y]] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]+i][q0[Y]] < 0){
                                if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]+i][q0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[X]-q1[X] > 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if(table[q0[X]-i][q0[Y]] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]-i][q0[Y]] < 0){
                            if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]-i][q0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y])){               //diagonala (bishop)
                if(table[q1[X]][q1[Y]] > 0)
                    aux = 0;
                if(table[q1[X]][q1[Y]] == 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                    }
                }
                if(table[q1[X]][q1[Y]] < 0){
                    if(abs(q0[X]-q1[X]) == 1){
                        aux = 1;
                    }
                    for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                    }
                }
            }
            }
            if(aux == 1)
                contor++;
            aux = 0;
        }
    }
    }
    }
    return contor;
}
int black_mobility()
{
    int p0[2];
    int p1[2];
    int b0[2];
    int b1[2];
    int q0[2];
    int q1[2];
    int k0[2];
    int k1[2];
    int r0[2];
    int r1[2];
    int king0[2];
    int king1[2];
    int i;
    int j;
    int contor = 0;
    int aux = 0;
    for(int x = 0; x<8; x++){           //pawn moves
    for(int y = 0; y<8; y++){
        p0[X] = x;
        p0[Y] = y;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            p1[X] = i;
            p1[Y] = j;
    if(table[p0[X]][p0[Y]] == -1){
            if((p0[Y] == p1[Y]) && ((p0[X] + 1) == p1[X])){     //verificare mutare normala
                if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
            }
            if(p0[X] == 1){
            if((p0[Y] == p1[Y]) && ((p0[X] + 2) == p1[X])){     //verificare mutare normala
            if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        }
            if(table[p1[X]][p1[Y]] > 0)
                if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] - 1) == p1[X])){     //verificare captura
                    if(table[p1[X]][p1[Y]] > 0)
                        aux = 1;
                }
        }
            if(aux == 1)
                contor++;
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){
    for(int y = 0; y<8; y++){
        k0[X] = x;
        k0[Y] = y;
    for(i=0; i<8; i++){                 //knight moves
        for(j=0; j<8; j++){
            k1[X] = i;
            k1[Y] = j;
            if(table[k0[X]][k0[Y]] == -2)           //black
            {
                if(((abs(k0[X]-k1[X]) == 1 && abs(k0[Y]-k1[Y]) == 2) || (abs(k0[X]-k1[X]) == 2 && abs(k0[Y]-k1[Y]) == 1)))   //the position isn't occupied by another black piece
                    if(table[k1[X]][k1[Y]] >= 0)
                {
                    contor++;
                }
            }
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){           //bishop moves
    for(int y = 0; y<8; y++){
        b0[X] = x;
        b0[Y] = y;
        if(table[b0[X]][b0[Y]] == -3){
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    b1[X] = i;
    b1[Y] = j;
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] < 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] > 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    if(aux == 1)
        contor++;
    aux = 0;
        }
        }
        }
    }
    }
    }
    for(int x = 0; x<8; x++){               // rook moves
    for(int y = 0; y<8; y++){
        r0[X] = x;
        r0[Y] = y;
        for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            r1[X] = i;
            r1[Y] = j;
            if(table[r0[X]][r0[Y]] == -5){
                if(r0[X] == r1[X]){
                    if(r0[Y]-r1[Y] < 0){
                        for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                            if(table[r0[X]][r0[Y]+i] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]][r0[Y]+i] > 0){
                                if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]][r0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[Y]-r1[Y] > 0){
                    for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                        if(table[r0[X]][r0[Y]-i] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]][r0[Y]-i] > 0){
                            if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]][r0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(r0[Y] == r1[Y]){
                    if(r0[X]-r1[X] < 0){
                        for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                            if(table[r0[X]+i][r0[Y]] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]+i][r0[Y]] > 0){
                                if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]+i][r0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[X]-r1[X] > 0){
                    for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                        if(table[r0[X]-i][r0[Y]] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]-i][r0[Y]] > 0){
                            if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]-i][r0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
        }
            if(aux == 1)
                contor++;
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){               //queen moves
    for(int y = 0; y<8; y++){
        q0[X] = x;
        q0[Y] = y;
        for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            q1[X] = i;
            q1[Y] = j;
            if(table[q0[X]][q0[Y]] == -9){
                if(q0[X] == q1[X]){                         //mutare pe linie (rook)
                    if(q0[Y]-q1[Y] < 0){
                        for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                            if(table[q0[X]][q0[Y]+i] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]][q0[Y]+i] > 0){
                                if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]][q0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[Y]-q1[Y] > 0){
                    for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                        if(table[q0[X]][q0[Y]-i] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]][q0[Y]-i] > 0){
                            if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]][q0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(q0[Y] == q1[Y]){                                         //mutare pe coloana(rook)
                    if(q0[X]-q1[X] < 0){
                        for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                            if(table[q0[X]+i][q0[Y]] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]+i][q0[Y]] > 0){
                                if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]+i][q0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[X]-q1[X] > 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if(table[q0[X]-i][q0[Y]] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]-i][q0[Y]] > 0){
                            if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]-i][q0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y])){               //diagonala (bishop)
                if(table[q1[X]][q1[Y]] < 0)
                    aux = 0;
                if(table[q1[X]][q1[Y]] == 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                    }
                }
                if(table[q1[X]][q1[Y]] > 0){
                    if(abs(q0[X]-q1[X]) == 1){
                        aux = 1;
                    }
                    for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                    }
                }
            }
            }
            if(aux == 1)
                contor++;
            aux = 0;
        }
    }
    }
    }
    for(int x = 0; x<8; x++){               //king moves
    for(int y = 0; y<8; y++){
        king0[X] = x;
        king0[Y] = y;
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    king1[X] = i;
    king1[Y] = j;
    if(table[king0[X]][king0[Y]] == -10){
    if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] < 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] > 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if(aux == 1)
            contor++;
    aux = 0;
        }
    }
    }
    }
    return contor;
}
int pvalid(int p0[2], int p1[2])
{
    int aux=0;
    if(table[p0[X]][p0[Y]] == 1){
        if((p0[Y] == p1[Y]) && ((p0[X] - 1) == p1[X])){     //verificare mutare normala
            if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        if(p0[X] == 6){
        if((p0[Y] == p1[Y]) && ((p0[X] - 2) == p1[X])){     //verificare mutare normala
            if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        }
        if(table[p1[X]][p1[Y]] < 0)
            if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] + 1) == p1[X])){     //verificare captura
                if(table[p1[X]][p1[Y]] > 0)
                    aux = 1;
                }
    }
    if(table[p0[X]][p0[Y]] == -1){
        if((p0[Y] == p1[Y]) && ((p0[X] + 1) == p1[X])){     //verificare mutare normala
            if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        if(p0[X] == 1){
        if((p0[Y] == p1[Y]) && ((p0[X] + 2) == p1[X])){     //verificare mutare normala
            if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
        }
        }
        if(table[p1[X]][p1[Y]] > 0)
            if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] - 1) == p1[X])){     //verificare captura
                if(table[p1[X]][p1[Y]] < 0)
                    aux = 1;
                }
    }
    return aux;
}
int rvalid(int r0[2], int r1[2])
{
    int aux;
    if(table[r0[X]][r0[Y]] == 5){
    if(r0[X] == r1[X]){
        if(r0[Y]-r1[Y] < 0){
            for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                if(table[r0[X]][r0[Y]+i] > 0){
                    aux = 0;
                    break;
                }
                if(table[r0[X]][r0[Y]+i] < 0){
                    if(i == abs(r0[Y]-r1[Y])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                }
                }
                if(table[r0[X]][r0[Y]+i] == 0){
                    aux = 1;
                }
            }
        }
    if(r0[Y]-r1[Y] > 0){
        for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
            if(table[r0[X]][r0[Y]-i] > 0){
                aux = 0;
                break;
            }
            if(table[r0[X]][r0[Y]-i] < 0){
                if(i == abs(r0[Y]-r1[Y])){
                        aux = 1;
                }
                    else{
                        aux = 0;
                        break;
                }
            }
            if(table[r0[X]][r0[Y]-i] == 0){
                aux = 1;
            }
        }
    }
    }
    if(r0[Y] == r1[Y]){
        if(r0[X]-r1[X] < 0){
            for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                if(table[r0[X]+i][r0[Y]] > 0){
                    aux = 0;
                    break;
                }
                if(table[r0[X]+i][r0[Y]] < 0){
                    if(i == abs(r0[X]-r1[X])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                if(table[r0[X]+i][r0[Y]] == 0){
                    aux = 1;
                }
            }
        }
    if(r0[X]-r1[X] > 0){
        for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
            if(table[r0[X]-i][r0[Y]] > 0){
                aux = 0;
                break;
            }
            if(table[r0[X]-i][r0[Y]] < 0){
                if(i == abs(r0[X]-r1[X])){
                        aux = 1;
                }
                    else{
                        aux = 0;
                        break;
                }
            }
            if(table[r0[X]-i][r0[Y]] == 0){
                aux = 1;
            }
        }
    }
    }
}
    if(table[r0[X]][r0[Y]] == -5){
        if(r0[X] == r1[X]){
            if(r0[Y]-r1[Y] < 0){
                for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                    if(table[r0[X]][r0[Y]+i] < 0){
                        aux = 0;
                        break;
                    }
                    if(table[r0[X]][r0[Y]+i] > 0){
                        if(i == abs(r0[Y]-r1[Y])){
                            aux = 1;
                        }
                        else{
                            aux = 0;
                            break;
                    }
                    }
                    if(table[r0[X]][r0[Y]+i] == 0){
                        aux = 1;
                    }
                }
            }
        if(r0[Y]-r1[Y] > 0){
            for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                if(table[r0[X]][r0[Y]-i] < 0){
                    aux = 0;
                    break;
                }
                if(table[r0[X]][r0[Y]-i] > 0){
                    if(i == abs(r0[Y]-r1[Y])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                if(table[r0[X]][r0[Y]-i] == 0){
                    aux = 1;
                }
            }
        }
        }
    if(r0[Y] == r1[Y]){
        if(r0[X]-r1[X] < 0){
            for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                if(table[r0[X]+i][r0[Y]] < 0){
                    aux = 0;
                    break;
                }
                if(table[r0[X]+i][r0[Y]] > 0){
                    if(i == abs(r0[X]-r1[X])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                    if(table[r0[X]+i][r0[Y]] == 0){
                        aux = 1;
                    }
            }
        }
        if(r0[X]-r1[X] > 0){
            for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                if(table[r0[X]-i][r0[Y]] < 0){
                    aux = 0;
                    break;
                }
                if(table[r0[X]-i][r0[Y]] > 0){
                    if(i == abs(r0[X]-r1[X])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                if(table[r0[X]-i][r0[Y]] == 0){
                    aux = 1;
                }
            }
        }
    }
    }
    return aux;
}
int bvalid(int b0[2], int b1[2])
{
    int aux;
    if(table[b0[X]][b0[Y]] == 3){
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] > 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] < 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    }
    }
        if(table[b0[X]][b0[Y]] == -3){
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] < 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] > 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    }
        }
    return aux;
}
int qvalid(int q0[2], int q1[2])
{
    int aux;
        if(table[q0[X]][q0[Y]] == 9){
                if(q0[X] == q1[X]){                         //mutare pe linie (rook)
                    if(q0[Y]-q1[Y] < 0){
                        for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                            if(table[q0[X]][q0[Y]+i] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]][q0[Y]+i] < 0){
                                if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]][q0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[Y]-q1[Y] > 0){
                    for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                        if(table[q0[X]][q0[Y]-i] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]][q0[Y]-i] < 0){
                            if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]][q0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(q0[Y] == q1[Y]){                                         //mutare pe coloana(rook)
                    if(q0[X]-q1[X] < 0){
                        for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                            if(table[q0[X]+i][q0[Y]] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]+i][q0[Y]] < 0){
                                if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]+i][q0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[X]-q1[X] > 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if(table[q0[X]-i][q0[Y]] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]-i][q0[Y]] < 0){
                            if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]-i][q0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y])){               //diagonala (bishop)
                if(table[q1[X]][q1[Y]] > 0)
                    aux = 0;
                if(table[q1[X]][q1[Y]] == 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                    }
                }
                if(table[q1[X]][q1[Y]] < 0){
                    if(abs(q0[X]-q1[X]) == 1){
                        aux = 1;
                    }
                    for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(table[q0[X]][q0[Y]] == -9){
        if(q0[X] == q1[X]){
            if(q0[Y]-q1[Y] < 0){
                for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                    if(table[q0[X]][q0[Y]+i] < 0){
                        aux = 0;
                        break;
                    }
                    if(table[q0[X]][q0[Y]+i] > 0){
                        if(i == abs(q0[Y]-q1[Y])){
                            aux = 1;
                        }
                        else{
                            aux = 0;
                            break;
                    }
                    }
                    if(table[q0[X]][q0[Y]+i] == 0){
                        aux = 1;
                    }
                }
            }
        if(q0[Y]-q1[Y] > 0){
            for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                if(table[q0[X]][q0[Y]-i] < 0){
                    aux = 0;
                    break;
                }
                if(table[q0[X]][q0[Y]-i] > 0){
                    if(i == abs(q0[Y]-q1[Y])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                if(table[q0[X]][q0[Y]-i] == 0){
                    aux = 1;
                }
            }
        }
        }
    if(q0[Y] == q1[Y]){
        if(q0[X]-q1[X] < 0){
            for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                if(table[q0[X]+i][q0[Y]] < 0){
                    aux = 0;
                    break;
                }
                if(table[q0[X]+i][q0[Y]] > 0){
                    if(i == abs(q0[X]-q1[X])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                    if(table[q0[X]+i][q0[Y]] == 0){
                        aux = 1;
                    }
            }
        }
        if(q0[X]-q1[X] > 0){
            for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                if(table[q0[X]-i][q0[Y]] < 0){
                    aux = 0;
                    break;
                }
                if(table[q0[X]-i][q0[Y]] > 0){
                    if(i == abs(q0[X]-q1[X])){
                        aux = 1;
                    }
                    else{
                        aux = 0;
                        break;
                    }
                }
                if(table[q0[X]-i][q0[Y]] == 0){
                    aux = 1;
                }
            }
        }
    }
    if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y]))
    {
        if(table[q1[X]][q1[Y]] < 0)
            aux = 0;
        if(table[q1[X]][q1[Y]] == 0){
            for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                    if(table[q0[X]+i][q0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                    if(table[q0[X]+i][q0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                    if(table[q0[X]-i][q0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                    if(table[q0[X]-i][q0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[q1[X]][q1[Y]] > 0){
            if(abs(q0[X]-q1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                    if(table[q0[X]+i][q0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                    if(table[q0[X]+i][q0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                    if(table[q0[X]-i][q0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                    if(table[q0[X]-i][q0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    }
    }
    return aux;
}

int knightvalid(int k0[2], int k1[2])
{
    int aux = 0;
    if(table[k0[X]][k0[Y]] == 2){
    if((abs(k0[X]-k1[X]) == 1) && (abs(k0[Y]-k1[Y]) == 2))
        aux = 1;
    if((abs(k0[X]-k1[X]) == 2) && (abs(k0[Y]-k1[Y]) == 1))
        aux = 1;
    if(table[k1[X]][k1[Y]] > 0)
        aux = 0;
    }
    if(table[k0[X]][k0[Y]] == -2){
    if((abs(k0[X]-k1[X]) == 1) && (abs(k0[Y]-k1[Y]) == 2))
        aux = 1;
    if((abs(k0[X]-k1[X]) == 2) && (abs(k0[Y]-k1[Y]) == 1))
        aux = 1;
    if(table[k1[X]][k1[Y]] < 0)
        aux = 0;
    }
    return aux;
}

int kvalid(int king0[2], int king1[2])
{
    int aux;
    if(table[king0[X]][king0[Y]] == 10){
     if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] > 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] < 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if(table[king0[X]][king0[Y]] == -10){
     if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] < 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] > 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    return aux;
}
int check_move(int piece, int p0[2], int p1[2])
{

    switch (piece){
        case 1:{
            return pvalid(p0, p1);
            break;
        }
        case -1:{
            return pvalid(p0, p1);
            break;
        }
        case 2: {
            return knightvalid(p0, p1);
            break;
        }
        case -2: {
            return knightvalid(p0, p1);
            break;
        }
        case 3: {
            return bvalid(p0, p1);
            break;
        }
        case -3: {
            return bvalid(p0, p1);
            break;
        }
        case 5: {
            return rvalid(p0, p1);
            break;
        }
        case -5: {
            return rvalid(p0, p1);
            break;
        }
        case 9: {
            return qvalid(p0, p1);
            break;
        }
        case -9: {
            return qvalid(p0, p1);
            break;
        }
        case 10: {
            return kvalid(p0, p1);
            break;
        }
        case -10: {
            return kvalid(p0, p1);
            break;
        }
    }
}
int wpallowed(int p0[2])
{
    int i;
    int j;
    int aux;
    int p1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            p1[X] = i;
            p1[Y] = j;

            if(table[p0[X]][p0[Y]] == 1){
                if((p0[Y] == p1[Y]) && ((p0[X] - 1) == p1[X])){     //verificare mutare normala
                    if(table[p1[X]][p1[Y]] == 0)
                        aux = 1;
                }
            if(p0[X] == 6){
                if((p0[Y] == p1[Y]) && ((p0[X] - 2) == p1[X])){     //verificare mutare normala
                    if(table[p1[X]][p1[Y]] == 0)
                        aux = 1;
        }
        }
                if(table[p1[X]][p1[Y]] < 0)
                    if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] + 1) == p1[X])){     //verificare captura
                        if(table[p1[X]][p1[Y]] > 0)
                            aux = 1;
                }
            }
            if(aux == 1){
                printf(" %d %d; ", i, j);
            }
            aux = 0;
        }
    }
}
int bpallowed(int p0[2])
{
    int i;
    int j;
    int aux = 0;
    int p1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            p1[X] = i;
            p1[Y] = j;
    if(table[p0[X]][p0[Y]] == -1){
            if((p0[Y] == p1[Y]) && ((p0[X] + 1) == p1[X])){     //verificare mutare normala
                if(table[p1[X]][p1[Y]] == 0)
                    aux = 1;
            }
            if(p0[X] == 6){
                if((p0[Y] == p1[Y]) && ((p0[X] + 2) == p1[X])){     //verificare mutare normala
                    if(table[p1[X]][p1[Y]] == 0)
                        aux = 1;
        }
        }
            if(table[p1[X]][p1[Y]] > 0)
                if((((p0[Y]+1) == p1[Y]) || (p0[Y]-1) == p1[Y]) &&  ((p0[X] - 1) == p1[X])){     //verificare captura
                    if(table[p1[X]][p1[Y]] > 0)
                        aux = 1;
                }
        }
            if(aux == 1)
                printf(" %d %d; ", i, j);
            aux = 0;
        }
    }
}
int wrallowed(int r0[2])
{
    int i;
    int j;
    int aux = 0;
    int r1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            r1[X] = i;
            r1[Y] = j;
            if(table[r0[X]][r0[Y]] == 5){
                if(r0[X] == r1[X]){
                    if(r0[Y]-r1[Y] < 0){
                        for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                            if(table[r0[X]][r0[Y]+i] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]][r0[Y]+i] < 0){
                                if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]][r0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[Y]-r1[Y] > 0){
                    for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                        if(table[r0[X]][r0[Y]-i] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]][r0[Y]-i] < 0){
                            if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]][r0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(r0[Y] == r1[Y]){
                    if(r0[X]-r1[X] < 0){
                        for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                            if(table[r0[X]+i][r0[Y]] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]+i][r0[Y]] < 0){
                                if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]+i][r0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[X]-r1[X] > 0){
                    for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                        if(table[r0[X]-i][r0[Y]] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]-i][r0[Y]] < 0){
                            if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]-i][r0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
        }
            if(aux == 1)
                printf(" %d %d; ", i, j);
            aux = 0;
        }
    }
}
int brallowed(int r0[2])
{
    int i;
    int j;
    int aux = 0;
    int r1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            r1[X] = i;
            r1[Y] = j;
            if(table[r0[X]][r0[Y]] == -5){
                if(r0[X] == r1[X]){
                    if(r0[Y]-r1[Y] < 0){
                        for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                            if(table[r0[X]][r0[Y]+i] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]][r0[Y]+i] > 0){
                                if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]][r0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[Y]-r1[Y] > 0){
                    for(int i = 1; i <= abs(r0[Y]-r1[Y]); i++){
                        if(table[r0[X]][r0[Y]-i] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]][r0[Y]-i] > 0){
                            if(i == abs(r0[Y]-r1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]][r0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(r0[Y] == r1[Y]){
                    if(r0[X]-r1[X] < 0){
                        for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                            if(table[r0[X]+i][r0[Y]] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[r0[X]+i][r0[Y]] > 0){
                                if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[r0[X]+i][r0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(r0[X]-r1[X] > 0){
                    for(int i = 1; i <= abs(r0[X]-r1[X]); i++){
                        if(table[r0[X]-i][r0[Y]] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[r0[X]-i][r0[Y]] > 0){
                            if(i == abs(r0[X]-r1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[r0[X]-i][r0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
        }
            if(aux == 1)
                printf(" %d %d; ", i, j);
            aux = 0;
        }
    }
}

int wknightallowed(int k0[2])
{
    int i;
    int j;
    int k1[2];
    int aux = 0;
    for(i = 0; i<8; i++){
        for(j = 0; j<8; j++){
            k1[X] = i;
            k1[Y] = j;
            if(table[k0[X]][k0[Y]] == 2)       //white
            {
                if(((abs(k0[X]-k1[X]) == 1 && abs(k0[Y]-k1[Y]) == 2) || (abs(k0[X]-k1[X]) == 2 && abs(k0[Y]-k1[Y]) == 1)))//the position isn't occupied by another white piece
                    if(table[k1[X]][k1[Y]] <= 0){
                        printf(" %d %d; ", i, j);
                    }
            }
            aux = 0;
        }
    }
}
int bknightallowed(int k0[2])
{
    int i;
    int j;
    int k1[2];
    int aux = 0;
    for(i = 0; i<8; i++){
        for(j = 0; j<8; j++){
            k1[X] = i;
            k1[Y] = j;
            if(table[k0[X]][k0[Y]] == -2)
            {
                if(((abs(k0[X]-k1[X]) == 1 && abs(k0[Y]-k1[Y]) == 2) || (abs(k0[X]-k1[X]) == 2 && abs(k0[Y]-k1[Y]) == 1)))//the position isn't occupied by another white piece
                    if(table[k1[X]][k1[Y]] >= 0){
                        printf(" %d %d; ", i, j);
                    }
            }
            aux = 0;
        }
    }
}
int wballowed(int b0[2])
{
    int i;
    int j;
    int b1[2];
    int aux = 0;
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    b1[X] = i;
    b1[Y] = j;
    if(table[b0[X]][b0[Y]] == 3){
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] > 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] < 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    if(aux == 1)
        printf(" %d %d; ", i, j);
    aux = 0;
        }
        }
        }
    }
}
int bballowed(int b0[2])
{
    int i;
    int j;
    int b1[2];
    int aux = 0;
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    b1[X] = i;
    b1[Y] = j;
    if(table[b0[X]][b0[Y]] == -3){
    if(abs(b0[X]-b1[X]) == abs(b0[Y]-b1[Y]))
    {
        if(table[b1[X]][b1[Y]] < 0)
            aux = 0;
        if(table[b1[X]][b1[Y]] == 0){
            for(int i = 1; i <= abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
        if(table[b1[X]][b1[Y]] > 0){
            if(abs(b0[X]-b1[X]) == 1){
                aux = 1;
            }
            for(int i = 1; i < abs(b0[X]-b1[X]); i++){
                if((b0[X] < b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]+i][b0[Y]+i] == 0)
                        aux = 1;
                    else{
                        aux = 0;
                        break;
                    }
                }
                if((b0[X] < b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]+i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] < b1[Y])){
                    if(table[b0[X]-i][b0[Y]+i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
                if((b0[X] > b1[X]) && (b0[Y] > b1[Y])){
                    if(table[b0[X]-i][b0[Y]-i] == 0)
                        aux = 1;
                        else{
                            aux = 0;
                            break;
                        }
                }
            }
        }
    if(aux == 1)
        printf(" %d %d; ", i, j);
    aux = 0;
        }
    }
        }
    }
}
int wkingallowed(int king0[2])
{
    int i;
    int j;
    int king1[2];
    int aux = 0;
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    king1[X] = i;
    king1[Y] = j;
    if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] > 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] < 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    if(aux == 1)
            printf(" %d %d; ", i, j);
    aux = 0;
        }
    }
}
int bkingallowed(int king0[2])
{
    int i;
    int j;
    int king1[2];
    int aux = 0;
    for(i = 0; i< 8; i++){
        for(j = 0; j<8; j++){
    king1[X] = i;
    king1[Y] = j;
    if( table[king1[X]][king1[Y]] == 0){
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    }
    if( table[king1[X]][king1[Y]] < 0)
        aux = 0;
    if( table[king1[X]][king1[Y]] > 0)
        if((abs(king0[X]-king1[X]) <= 1) && (abs(king0[Y]-king1[Y]) <= 1))
            aux = 1;
    if(aux == 1)
            printf(" %d %d; ", i, j);
    aux = 0;
        }
    }
}
int wqallowed(int q0[2])
{
    int i;
    int j;
    int aux = 0;
    int q1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            q1[X] = i;
            q1[Y] = j;
            if(table[q0[X]][q0[Y]] == 9){
                if(q0[X] == q1[X]){                         //mutare pe linie (rook)
                    if(q0[Y]-q1[Y] < 0){
                        for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                            if(table[q0[X]][q0[Y]+i] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]][q0[Y]+i] < 0){
                                if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]][q0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[Y]-q1[Y] > 0){
                    for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                        if(table[q0[X]][q0[Y]-i] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]][q0[Y]-i] < 0){
                            if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]][q0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(q0[Y] == q1[Y]){                                         //mutare pe coloana(rook)
                    if(q0[X]-q1[X] < 0){
                        for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                            if(table[q0[X]+i][q0[Y]] > 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]+i][q0[Y]] < 0){
                                if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]+i][q0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[X]-q1[X] > 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if(table[q0[X]-i][q0[Y]] > 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]-i][q0[Y]] < 0){
                            if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]-i][q0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y])){               //diagonala (bishop)
                if(table[q1[X]][q1[Y]] > 0)
                    aux = 0;
                if(table[q1[X]][q1[Y]] == 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                    }
                }
                if(table[q1[X]][q1[Y]] < 0){
                    if(abs(q0[X]-q1[X]) == 1){
                        aux = 1;
                    }
                    for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                    }
                }
            }
            }
            if(aux == 1)
                printf(" %d %d; ", i, j);
            aux = 0;
        }
    }
}
int bqallowed(int q0[2])
{
    int i;
    int j;
    int aux = 0;
    int q1[2];
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            q1[X] = i;
            q1[Y] = j;
            if(table[q0[X]][q0[Y]] == -9){
                if(q0[X] == q1[X]){                         //mutare pe linie (rook)
                    if(q0[Y]-q1[Y] < 0){
                        for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                            if(table[q0[X]][q0[Y]+i] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]][q0[Y]+i] > 0){
                                if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]][q0[Y]+i] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[Y]-q1[Y] > 0){
                    for(int i = 1; i <= abs(q0[Y]-q1[Y]); i++){
                        if(table[q0[X]][q0[Y]-i] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]][q0[Y]-i] > 0){
                            if(i == abs(q0[Y]-q1[Y])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]][q0[Y]-i] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(q0[Y] == q1[Y]){                                         //mutare pe coloana(rook)
                    if(q0[X]-q1[X] < 0){
                        for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                            if(table[q0[X]+i][q0[Y]] < 0){
                                aux = 0;
                                break;
                            }
                            if(table[q0[X]+i][q0[Y]] > 0){
                                if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                                }
                                else{
                                    aux = 0;
                                    break;
                            }
                            }
                            if(table[q0[X]+i][q0[Y]] == 0){
                                aux = 1;
                            }
                        }
                    }
                if(q0[X]-q1[X] > 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if(table[q0[X]-i][q0[Y]] < 0){
                            aux = 0;
                            break;
                        }
                        if(table[q0[X]-i][q0[Y]] > 0){
                            if(i == abs(q0[X]-q1[X])){
                                    aux = 1;
                            }
                                else{
                                    aux = 0;
                                    break;
                        }
                        }
                        if(table[q0[X]-i][q0[Y]] == 0){
                            aux = 1;
                        }
                    }
                }
            }
            if(abs(q0[X]-q1[X]) == abs(q0[Y]-q1[Y])){               //diagonala (bishop)
                if(table[q1[X]][q1[Y]] < 0)
                    aux = 0;
                if(table[q1[X]][q1[Y]] == 0){
                    for(int i = 1; i <= abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                    }
                }
                if(table[q1[X]][q1[Y]] > 0){
                    if(abs(q0[X]-q1[X]) == 1){
                        aux = 1;
                    }
                    for(int i = 1; i < abs(q0[X]-q1[X]); i++){
                        if((q0[X] < q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]+i][q0[Y]+i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                        if((q0[X] < q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]+i][q0[Y]-i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] < q1[Y])){
                            if(table[q0[X]-i][q0[Y]+i] == 0)
                                aux = 1;
                                else{
                                    aux = 0;
                                    break;
                                }
                        }
                        if((q0[X] > q1[X]) && (q0[Y] > q1[Y])){
                            if(table[q0[X]-i][q0[Y]-i] == 0)
                                aux = 1;
                            else{
                                aux = 0;
                                break;
                            }
                        }
                    }
                }
            }
            }
            if(aux == 1)
                printf(" %d %d; ", i, j);
            aux = 0;
        }
    }
}
int allowed_moves(int piece, int p0[2])
{
    printf("The available moves are: ");
    switch (piece) {
        case 1:
            wpallowed(p0);
            break;
        case -1:
            bpallowed(p0);
            break;
        case 2:
            wknightallowed(p0);
            break;
        case -2:
            bknightallowed(p0);
            break;
        case 3:
            wballowed(p0);
            break;
        case -3:
            bballowed(p0);
            break;
        case 5:
            wrallowed(p0);
            break;
        case -5:
            brallowed(p0);
            break;
        case 9:
            wqallowed(p0);
            break;
        case -9:
            bqallowed(p0);
            break;
        case 10:
            wkingallowed(p0);
            break;
        case -10:
            bkingallowed(p0);
            break;
    }
}
float move_value()
{
    int wQ = count_wqueen();
    int bQ = count_bqueen();
    int wKnight = count_wknight();
    int bKnight = count_bknight();
    int wB = count_wbishop();
    int bB = count_bbishop();
    int wR = count_wrook();
    int bR = count_brook();
    int wP = count_wpawn();
    int bP = count_bpawn();
    int wDP = double_wpawn();
    int bDP = double_bpawn();
    int wIP = isolated_wpawn();
    int bIP = isolated_bpawn();
    int wBP = blocked_wpawn();
    int bBP = blocked_bpawn();
    int wM = white_mobility();
    int bM = black_mobility();
    float value;
    value = 9*(wQ - bQ) + 5*(wR - bR) + 3*(wKnight - bKnight + wB - bB) + 1*(wP - bP) - 0.5*(wDP - bDP + wIP - bIP + wBP - bBP) + 0.1*(wM - bM);
    return value;
}
int computer_move()
{
    float value = 0;
    float best = 100;
    int p;
    int b;
    int b0[2];
    int b1[2];
    int v0[2];
    int v1[2];
    int aux;
    for(int m = 0; m<8; m++){
        for(int n = 0; n<8; n++){
            v0[X] = m;
            v0[Y] = n;
            if(table[m][n] < 0){
                p = table[m][n];
                for(int i = 0; i<8; i++){
                    for(int j = 0; j<8; j++){
                        v1[X]= i;
                        v1[Y] = j;
                        if(check_move(p, v0, v1) == 1){
                            aux = table[i][j];
                            table[m][n] = 0;
                            table[i][j] = p;
                            value = move_value();
                            table[m][n] = p;
                            table[i][j] = aux;
                            if(value < best){
                                best = value;
                                b0[X] = m;
                                b0[Y] = n;
                                b1[X] = i;
                                b1[Y] = j;
                                b = p;
                            }
                        }
                    }
                }
            }
        }
    }
    table[b0[X]][b0[Y]] = 0;
    table[b1[X]][b1[Y]] = b;
    return chesstable();
}
void check()
{

}
void checkmate()
{

}
void play_PvP()
{
    long m = 1;
    int p;
    int p0[2];
    int p1[2];
    chesstable();
    for(m = 1; m < 5000; m++){
    if(m % 2 == 1){
        printf("White's turn \n");
        printf("If you want to resign, press 0 \n");
        printf("If you want to continue, choose a piece to move: ");
        scanf("%d", &p);
        if(p == 0){
            printf("Black won!");
            break;
        }
        else{
            printf("Choose your piece position (ROW COLUMN): ");
            scanf("%d %d", &p0[X], &p0[Y]);
            printf("Choose where you want to move: ");
            scanf("%d %d", &p1[X], &p1[Y]);
            if(check_move(p, p0, p1) == 1){
                table[p0[X]][p0[Y]] = 0;
                table[p1[X]][p1[Y]] = p;
            }
            else{
                m--;
                printf("Not a valid move!\n");
        }
        }
        chesstable();
        }
    if(m % 2 == 0){
        printf("Black's turn \n");
        printf("If you want to resign, press 0 \n");
        printf("If you want to continue, choose a piece to move: ");
        scanf("%d", &p);
        if(p == 0){
            printf("White won!");
            break;
        }
        else{
            printf("Choose your piece position (ROW COLUMN): ");
            scanf("%d %d", &p0[X], &p0[Y]);
            printf("Choose where you want to move: ");
            scanf("%d %d", &p1[X], &p1[Y]);
            if(check_move(p, p0, p1) == 1){
                table[p0[X]][p0[Y]] = 0;
                table[p1[X]][p1[Y]] = p;
            }
            else{
                m--;
                printf("Not a valid move!\n");
        }
        }
        chesstable();
        }
    }
}
void play_PvC()
{
    long m = 1;
    int p;
    int p0[2];
    int p1[2];
    chesstable();
    for(m = 1; m < 5000; m++){
    if(m % 2 == 1){
        printf("White's turn \n");
        printf("If you want to resign, press 0 \n");
        printf("If you want to continue, choose a piese to move: ");
        scanf("%d", &p);
        if(p == 0){
            printf("Black won!");
            break;
        }
        else{
            printf("Choose your piece position: ");
            scanf("%d %d", &p0[X], &p0[Y]);
            printf("Choose where you want to move: ");
            scanf("%d %d", &p1[X], &p1[Y]);
            if(check_move(p, p0, p1) == 1){
                table[p0[X]][p0[Y]] = 0;
                table[p1[X]][p1[Y]] = p;
            }
            else{
                m--;
                printf("Not a valid move!");
            }
        chesstable();
    }
    }
    if(m % 2 == 0){
        computer_move();
    }
}
}
int main()
{
    int t;
    printf("Choose a game mode or exit\n");
    printf("Type 1 for PvP    Type 2 for PvC     Type something else if you want to exit\n");
    scanf("%d", &t);
    
    if(t == 1)
        play_PvP();
    else if(t == 2)
        play_PvC();
    return 0;
}