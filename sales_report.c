#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float *summary(float f[]);
float *moving_avg(float f[]);
int *sort(float f[]);
void swap(float *x, float *y);

int main(){

    FILE *fptr;
    char file_name[14] = "sales_data";
    char month[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float monthly_sales[12]; 
    fptr = fopen(file_name, "r");
    if(fptr == NULL){
        printf("failed to open file\n");
        return 1;
    }
    for(int i = 0; i < 12; i++){
        fscanf(fptr, "%f", &monthly_sales[i]);
    }
    printf("Monthly sales report for 2022:\n");
    printf("%-12s", "Month");
    printf("%s","Sales\n");
    for(int i = 0; i < 12; i++){
        printf("%-12s%-12.02f\n", month[i], monthly_sales[i]);
    }

    float *sum;
    sum = summary(monthly_sales);
    printf("Sales summary\n");
    printf("%-15s%s%-10.02f%s%s%s\n", "Minimum sales:", "$", sum[0], "(", month[(int)sum[1]], ")");
    printf("%-15s%s%-10.02f%s%s%s\n", "Maximum sales:", "$", sum[2], "(", month[(int)sum[3]], ")");
    printf("%-15s%s%-10.02f\n", "Average sales:", "$", sum[4]);

    sum = moving_avg(monthly_sales);
    printf("Six-Month Moving Average Report:\n");
    for(int i = 0; i < 7; i++){
        printf("%-10s%-2s%-10s%s%-12.02f\n", month[i], "-", month[i+5], "$", sum[i]);
    }

    int *month_ptr;
    month_ptr = sort(monthly_sales);
    printf("Sales Report (Highest to Lowest):\n");
    printf("%-12s", "Month");
    printf("%s","Sales\n");
    for(int i = 0; i < 12; i++){
        printf("%-12s%-12.02f\n", month[month_ptr[i]], monthly_sales[i]);
    }

    return 0;
}

float *summary(float f[]){
    float min = f[0];
    float max = f[0];
    float avg = f[0];
    int month[2] = {0,0};
    for(int i = 1; i < 12; i++){
        if(min > f[i]){
            min = f[i];
            month[0] = i;
        }
        if(max < f[i]){
            max = f[i];
            month[1] = i;
        }
        avg = avg + f[i];
    }
    avg = avg/12.0;
    static float arr[5];
    arr[0] = min;
    arr[1] = month[0];
    arr[2] = max;
    arr[3] = month[1];
    arr[4] = avg;
    return arr;
}

float *moving_avg(float f[]){
    static float ma[7];
    for(int i = 0; i < 7; i++){
        for(int j = i; j < i+6; j++){
            ma[i] += f[j];
        }
        ma[i] = ma[i]/6;
    }
    return ma;
}

int *sort(float f[]){
    int idx = 0;
    static int m[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for(int i = 0; i < 11; i++){
        idx = i;
        for(int j = i+1; j < 12; j++){
            if(f[j] > f[idx]){
                idx = j;
            }
        }
        if(idx != i){
            swap(&f[idx], &f[i]);
            int temp = m[idx];
            m[idx] = i;
            m[i] = temp;
        }
    }
    return m;
}

void swap(float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}