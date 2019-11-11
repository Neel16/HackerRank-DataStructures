#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeftBy1(vector<int> a){. //didnt end up using this because time complexity became o(n^2)
    int temp= a.front();

    vector<int> b;
    vector<int>::iterator it;

    for(it = a.begin() ; it != a.end() ; it++)
    {
        b.push_back(*(it+1));
    }
    b.back()=temp;
    
    return b;

}
vector<int> rotLeft(vector<int> a, int d) {

        vector<int> b;
        queue<int> q;
        vector<int>::iterator it;
        for(it=a.begin(); it!=a.end(); it++) //fill a queue with vector elements
        {
            q.push(*it);
        }

        for(int i =0 ;i<d ;i++) //rotate the queue d times (Pop front and push front in back)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            // int temp= a.front();

            // vector<int>::iterator it;

            //  for(it = a.begin() ; it != a.end() ; it++) // This fails large test cases
            // {                                            //since time complexity 
            //       *it = *(it+1);                         //became o(n^2)
            // }   
            // a.back()=temp;
            
        }
        while(!q.empty()) //create a new vector to push q elements
        {
            b.push_back(q.front());
            q.pop();
        }
        return b;


        //betterway, O(1)

        reverse(a.begin(), a.begin()+d);
        reverse(a.begin()+d, a.end());
        reverse(a.begin(), a.end());

}

void rotateRight(vector<int> a, int k)
{
	k %= a.size();
	reverse(a.begin(), a.end());
	reverse(a.begin(), a.begin()+k);
	reverse(a.begin()+k, a.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
