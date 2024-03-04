#include <iostream>
using namespace std;

class Solution{
  public:
    void swapElements(int arr[], int n){
        
        for(int i = 0,j = i+2;j<n;i++,j++){
            arr[i]=arr[i]^arr[j];
            arr[j]=arr[i]^arr[j];
            arr[i]=arr[i]^arr[j];
        }
    }
};

int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution obj;
	    obj.swapElements(arr, n);
	    
	    for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}