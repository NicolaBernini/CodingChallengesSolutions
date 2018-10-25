// Challenge at 
// https://www.hackerrank.com/challenges/deque-stl/problem

#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    if (n==0) return; 
	//Write your code here.
    deque<int> temp; 
    bool is_set=false; 
    int t_max; 
    
    // NOTE: Main O(N) loop necessary to see all the items 
    for(int i=0; i<n; ++i)
    {
        temp.push_front(arr[i]);
        if(temp.size()>k) 
        {
            //NOTE: If the removed element is t_max, invalidate the tracked max so to recompute it 
            if(temp.back()==t_max) is_set=false; 
            temp.pop_back();             
        }

        if(temp.size()==k) 
        {
            if(!is_set) 
            {
                //NOTE: No valid max tracked, recompute it 
                t_max = *max_element(temp.begin(), temp.end()); 
                is_set = true; 
            }
            else 
            {
                //NOTE: Valid max tracked, do not spend O(N) time to recompute but just O(1) to compare 
                if(arr[i] > t_max) t_max = arr[i]; 
            }
            
            cout << t_max << " "; 
        }
    }
    cout << endl; 
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}


