

#include <stdio.h>

#define BIT_MAX 32

int solution(int N) {
    unsigned char i=0;
    unsigned char t_last_one_pos_p1=0;            ///< The 0 is invalid
    unsigned char t_cur_gap=0; 
    unsigned char t_last_max_gap=0; 
    // write your code in C99 (gcc 6.2.0)
    for(i=0; i<BIT_MAX; ++i)
    {
        //printf("Testing i=%d\n", i); 
        if( (N&(1<<i))==(1<<i) )
        {
            //printf("1 detected\n"); 
            if(t_last_one_pos_p1>0)
            {
                t_cur_gap=i-(t_last_one_pos_p1-1)-1; 
                //printf("t_cur_gap=%d\n",t_cur_gap); 
                if(t_cur_gap>t_last_max_gap) t_last_max_gap=t_cur_gap; 
            }
            t_last_one_pos_p1=i+1; 
        }
        else
        {
            //printf("No 1 detected\n"); 
        }
    }
    return t_last_max_gap; 
}

int main(void) {
	//printf("%d", (1<<4)); 
	int test=1041; 
	printf("Solution(%d)=%d\n", test, solution(test)); 
	// your code goes here
	return 0;
}


