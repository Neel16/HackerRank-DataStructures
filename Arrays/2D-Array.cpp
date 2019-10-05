#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

vector<int> sumvector;
for(int row =0; row <=3 ; row++)
{
    for(int col = 0; col <=3 ; col++)
    {
        int sum = 0;

        sum += arr[row][col];
        sum += arr[row][col+1];
        sum += arr[row][col+2];
        sum += arr[row+1][col+1];
        sum += arr[row+2][col];
        sum += arr[row+2][col+1];
        sum += arr[row+2][col+2];
        
        sumvector.push_back(sum);
    }
}

return *max_element(sumvector.begin(), sumvector.end());

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
