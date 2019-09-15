#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node
{
    int rank;
    string label;
    string name;
};

int n,m;
vector<string> input;
vector<node> get_input;
vector<int> out;

//大小写
void deal1()
{
    for(int i=0;i<n;++i)
    {
        unsigned int pos;
        if((pos=input[i].find("..",0))!=string::npos)
        {
            unsigned int pos2=pos+2;
            while(input[i][pos2]=='.')
                ++pos2;
            //pos2指向.后一个字符
            for(;pos2<input[i].size();++pos2)
            {
                if(input[i][pos2]==' ') break;
                if(input[i][pos2]>='A' &&input[i][pos2]<='Z')
                    input[i][pos2]=input[i][pos2]-'A'+'a';
            }
        }

    }
}

void deal2()
{
    for(int i=0;i<n;++i)
    {
        int pos=0;
        for(;input[i][pos]=='.';++pos);
        node temp;
        temp.rank=pos/2;
        unsigned int pos2=0;
        if((pos2=input[i].find(" ",pos))!=string::npos)
        {
            temp.label=input[i].substr(pos,pos2-pos);
            temp.name=input[i].substr(pos2+1,input[i].size()-pos2-1);
        }
        else
        {
            temp.label=input[i].substr(pos,input[i].size()-pos);
            temp.name="";
        }
        get_input.push_back(temp);
    }
}

void deal4(string s)
{
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]-'A'+'a';
    }
}

void deal3(string s)
{
    //单个
    if(s.find(" ",0)==string::npos)
    {
        //名称
        if(s[0]=='#')
        {
            int sum=0;
            out.clear();
            for(int i=0;i<n;++i)
            {
                if(get_input[i].name==s)
                {
                    ++sum;
                    out.push_back(i+1);
                }
            }
            if(sum!=0) cout<<sum<<" ";
            else cout<<sum<<endl;
            for(int i=0;i<sum-1;++i)
                cout<<out[i]<<" ";
            if(sum!=0) cout<<out[sum-1]<<endl;
        }
        else    //标签
        {
            int sum=0;
            out.clear();
            //处理大小写
            deal4(s);
            for(int i=0;i<n;++i)
            {
                if(get_input[i].label==s)
                {
                    ++sum;
                    out.push_back(i+1);
                }
            }
            if(sum!=0) cout<<sum<<" ";
            else cout<<sum<<endl;
            for(int i=0;i<sum-1;++i)
                cout<<out[i]<<" ";
            if(sum!=0) cout<<out[sum-1]<<endl;
        }
    }
    //嵌套
    else
    {
        vector<string> middle;
        int pos=0;
        int pos1=0;
        while((pos1=s.find(" ",pos))!=string::npos)
        {
            middle.push_back(s.substr(pos,pos1-pos));
            pos=pos1+1;
        }
        middle.push_back(s.substr(pos,s.size()-pos));

        int j=0;
        int i;
        int pri_rank=-1;
        out.clear();
        int sum=0;
        //while(true)
        {
            for(i=0;i<(int)middle.size()-1;++i)
            {
                if(j==(int)get_input.size())
                {
                    break;
                }
                for(;j<(int)get_input.size();++j)
                {
                    if(get_input[j].label==middle[i] && get_input[j].rank>pri_rank)
                    {
                        pri_rank=get_input[j].rank;
                        ++j;
                        break;
                    }
                }
            }
            //全部匹配
            if(i==(int)middle.size()-1)
            {

                for(;j<get_input.size();++j)
                {
                    if((get_input[j].name==middle[i] || get_input[j].label==middle[i]) && get_input[j].rank>pri_rank)
                    {
                        out.push_back(j+1);
                        //++j;
                        //break;
                    }
                }
                sum=out.size();
                if(sum!=0) cout<<sum<<" ";
            else cout<<sum<<endl;
            for(int i=0;i<sum-1;++i)
                cout<<out[i]<<" ";
            if(sum!=0) cout<<out[sum-1]<<endl;

            }
            else
            {
                cout<<0<<endl;
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    string temp;
    char c;
    cin.get(c);
    for(int i=0;i<n;++i)
    {
        getline(cin,temp);
        input.push_back(temp);
    }
    deal1();
    deal2();
    for(int i=0;i<m;++i)
    {
        getline(cin,temp);
        deal3(temp);
    }
    return 0;
}
