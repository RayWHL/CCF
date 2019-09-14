#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int m,n;
map<string, string> name;
vector<string> input;

void deal()
{
    for(int i=0;i<m;++i)
    {
        int pos=0;
        while((pos=input[i].find("{{ ",pos))!=string::npos)
        {
            pos=pos+3;
            string na;
            int pos1;
            if((pos1=input[i].find(" ",pos))!=string::npos)
            {
                if(pos1+2<input[i].size() && input[i].substr(pos1,3)==" }}")
                {
                    na=input[i].substr(pos, pos1-pos);
                    string get=name[na];
                    if(get.size()!=0)
                    {
                        input[i].replace(pos-3,pos1-pos+6,get.substr(1,get.size()-2));
                        pos=pos-3+get.size()-2;
                    }
                    else
                    {
                        input[i].replace(pos-3,pos1-pos+6,"");
                        pos=pos-3;
                    }

                }

            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin>>m>>n;
    char c;
    cin.get(c);
    string temp,temp2;
    for(int i=0;i<m;++i)
    {
        getline(cin,temp);
        input.push_back(temp);
    }
    for(int i=0;i<n;++i)
    {
        cin>>temp;
        cin.get(c);
        getline(cin,temp2);
        name[temp]=temp2;
    }

    deal();

    for(int i=0;i<m;++i)
        cout<<input[i]<<endl;

    return 0;
}
