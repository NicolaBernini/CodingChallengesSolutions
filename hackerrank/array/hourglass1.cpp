// Solution to 
// https://www.hackerrank.com/challenges/2d-array

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


long int do_wire_hg_compute(const int* in_wire_arr, const int in_wire_id)
{
    int t_wire_row = (in_wire_id/4)+1; 
    int t_wire_col = (in_wire_id%4)+1; 
    //printf("Checking HG at %d %d\n", t_wire_row, t_wire_col); 
    //printf("Elem %d\n", in_wire_arr[(t_wire_row-1)*6+(t_wire_col-1)]); 
    //return 0; 
    return (in_wire_arr[(t_wire_row-1)*6+(t_wire_col-1)]+
           in_wire_arr[(t_wire_row-1)*6+(t_wire_col)]+
           in_wire_arr[(t_wire_row-1)*6+(t_wire_col+1)]+
           in_wire_arr[(t_wire_row)*6+(t_wire_col)]+
           in_wire_arr[(t_wire_row+1)*6+(t_wire_col-1)]+
           in_wire_arr[(t_wire_row+1)*6+(t_wire_col)]+
           in_wire_arr[(t_wire_row+1)*6+(t_wire_col+1)]); 
}

int main(){
    long int t_stg_max; 
    long int t_stg_temp=0; 
    // Loading 
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    t_stg_max=do_wire_hg_compute(arr, 0); 
    for(int t_wire_i=1; t_wire_i<16; t_wire_i++) 
    {
        t_stg_temp=do_wire_hg_compute(arr, t_wire_i); 
        if(t_stg_temp>t_stg_max) t_stg_max=t_stg_temp; 
    }
    printf("%d\n", t_stg_max); 
    return 0;
}


