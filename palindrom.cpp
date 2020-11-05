#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    bool flag = false;
    string s;
    cin >> s;
    stack<char> S;
    int len = s.length();
    for(int i = 0; i < len; i++)
        S.push(s[i]);
    
    for(int i = 0; i < len; i++)
    {
        if(S.top() == s[i])
            flag = true;
        else
        {
            flag = false;
            break;
        }
        S.pop();
    }
    if(flag)
        cout << "DA" << endl;
    else
        cout << "NE" << endl;
            
    
    return EXIT_SUCCESS;
}