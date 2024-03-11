#include <stdio.h>

int safetys(int score);
int field_goals(int score);
int tds(int score);
int td_plus_xp(int score);
int td_plus_twop(int score);

int main(){
    int score;
    do{
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        int total_count[score+1][5];
        int score_tracker[score+1];
        for(int i = 0; i < score+1; i++){
            score_tracker[i] = score;
            for(int j = 0; j < 5; j++){
                total_count[i][j] = 0;
            }
        }
        total_count[0][0] = 1;
        total_count[0][1] = 1;
        total_count[0][2] = 1;
        total_count[0][3] = 1;
        total_count[0][4] = 1;
        for(int safety = 2; safety <= score; safety++){
            while(score_tracker[safety] >= 2 && score_tracker[safety] != 3){
                total_count[safety][0]++;
                score_tracker[safety]-=2;
            }
            for(int fg = 3; fg <= score; fg++){
                while(score_tracker[fg] >= 3 && score_tracker[fg] != 4){
                    total_count[fg][1]++;
                    score_tracker[fg]-=3;
                }
                for(int td = 6; td <= score; td++){
                    while(score_tracker[td] >= 6 && score_tracker[td] != 7){
                        total_count[td][2]++;
                        score_tracker[td]-=6;
                    }
                    for(int td_xp = 7; td_xp <= score; td_xp++){
                        while(score_tracker[td_xp] >= 7 && score_tracker[td_xp] != 8){
                            total_count[td_xp][3]++;
                            score_tracker[td_xp]-=7;
                        }
                        for(int td_twop = 8; td_twop <= score; td_twop++){
                            while(score_tracker[td_twop] >= 8 && score_tracker[td_twop] != 9){
                                total_count[td_twop][4]++;
                                score_tracker[td_twop]-=8;
                            }
                        }
                    }
                }
            }
        }
        for(int i = 2; i < score+1; i++){
            if((total_count[i][0] == total_count[i-1][0]) && (total_count[i][1] == total_count[i-1][1]) && (total_count[i][2] == total_count[i-1][2]) && (total_count[i][3] == total_count[i-1][3]) && (total_count[i][4] == total_count[i-1][4])){
                 //skip double
            }
            else printf("%d TD+2pt, %d TD+1pt, %d TD, %d FG, %d safetys\n", total_count[i][4], total_count[i][3], total_count[i][2], total_count[i][1], total_count[i][0]);
        }
    }
    while(score > 1);
    return 0;
}

int safetys(int score){
    int safety_count = 0;
    for(int i = 0; i < score-3; i+=2){
        safety_count++;
    }
    return safety_count;
}

int field_goals(int score){
    int fg_count = 0;
    for(int i = 0; i < score-4; i+=3){
        fg_count++;
    }
    return fg_count;
}

int tds(int score){
    int td_count = 0;
    for(int i = 0; i < score-7; i+=6){
        td_count++;
    }
    return td_count;
}

int td_plus_xp(int score){
    int xp_count = 0;
    for(int i = 0; i < score-8; i+=7){
        xp_count++;
    }
    return xp_count;
}

int td_plus_twop(int score){
    int twop_count = 0;
    for(int i = 0; i < score-9; i+=8){
        twop_count++;
    }
    return twop_count;
}