#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int input[1000];
    int output;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>input[i];
    }
    sort(input,input+n);
    //nÎªÅ¼Êý
    if(n%2==0)
    {
        int i=n/2-1;
        int j=n/2;
        output=-1;
        if(input[i]==input[j])
        {
            output=input[i];
            --i;
            ++j;
        }
        while(i>=0&&j<n&&output!=-1)
        {
            if(input[i]==input[j] && input[i]==output)
            {
                --i;
                ++j;
            }
            else if(input[i]==input[j] && input[i]!=output)
            {
                break;
            }
            else if(input[i]!=input[j] && (input[i]!=output) && input[j]!=output)
                break;
            else
                output=-1;
        }
        cout<<output<<endl;
    }
    else
    {
        int i=(n-1)/2;
        int j=i;
        output=input[i];
        --i;
        ++j;
        while(i>=0&&j<n)
        {
            if(input[i]==input[j] && input[i]==output)
            {
                --i;
                ++j;
            }
            else if(input[i]==input[j] && input[i]!=output)
            {
                break;
            }
            else if(input[i]!=input[j] && (input[i]!=output) && input[j]!=output)
                break;
            else
                output=-1;
        }
        cout<<output<<endl;
    }
    return 0;
}
