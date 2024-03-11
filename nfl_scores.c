#include <stdio.h>

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
            for(int fg = 2; fg <= score; fg++){
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
        int transfer_count[score+1][5];
        for(int i = 2; i < score+1; i++){
            if((total_count[i][0] == total_count[i-1][0]) && (total_count[i][1] == total_count[i-1][1]) && (total_count[i][2] == total_count[i-1][2]) && (total_count[i][3] == total_count[i-1][3]) && (total_count[i][4] == total_count[i-1][4])){
                //skip doubles
            }
            else{
                for(int j = 0; j < 5; j++){
                    transfer_count[i][j] = total_count[i][j];
                }
                printf("%d TD+2pt, %d TD+1pt, %d TD, %d FG, %d safetys\n", transfer_count[i][4], transfer_count[i][3], transfer_count[i][2], transfer_count[i][1], transfer_count[i][0]);
            } 
            //ran out of time here but to continue
            //currently the program only shows the max values of each type
            //so next i would program functions to splits the max values of each
            //pseudo code:
            //if FG >= 3 then take 2 FG and make it 3 safetys
            //if TD >= 2 then take 1 TD and make it 2 FGs then repeat above
            //if TD+1pt >= 2 then take 1 TD+1pt and make it 1 FG and 2 safetys then repeat above
            //if TD+2pt >= 2 then take 1 TD+2pt and make it 1 TD and 1 safety then repeat above
        }
    }
    while(score > 1);
    return 0;
}
