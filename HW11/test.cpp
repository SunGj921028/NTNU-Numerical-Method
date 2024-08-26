#include<iostream>
#include<vector>

using namespace std;

int main(){
    // 3 x 2
    vector<vector<double> > A = {
        {1, 2, 3}, 
        {4, 5, 5}, 
        {7, 8, 8}, 
        {11, 10, 15}, 
    };

    // for(int i = 0; i < A.size(); i++) {
    //     for(int j = 0; j < A[i].size(); j++) {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << A.size() << endl;
    cout << A[0].size() << endl;
    // cout << A.front() << endl;
    cout << A.front().size() << endl;
    // cout << A.back() << endl;
    cout << A.back().size() << endl;
    return 0;
}