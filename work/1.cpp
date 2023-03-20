#include<bits/stdc++.h>
#define wc 1e-6
#define inf 0x3f3f3f3f.0
typedef long long ll;
using namespace std;
stack<int>nub;
stack<char>ch;
string s;
int ys()
{
    int a=nub.top();
    nub.pop();
    int b=nub.top();
    nub.pop();
    if(ch.top()=='+')
        return a+b;
    if(ch.top()=='-')
        return b-a;
    if(ch.top()=='*')
        return a*b;
    if(ch.top()=='/')
        return b/a;
}
int main()
{
    ios::sync_with_stdio(false);
    printf("请输入算术表达式：");
    cin>>s;
    int i=0;
    while(i<s.size()&&s[i]!='=')
    {
        if(isdigit(s[i]))//检查参数是否为数字
        {
            int ls=0;
            while(i<s.size()&&isdigit(s[i]))
            {
                ls=10*ls+(s[i]-'0');
                i++;
            }
            nub.push(ls);
        }
        else if(s[i]=='(')//遇到左括号，字符入栈
            ch.push(s[i++]);
        else if(s[i]=='+'||s[i]=='-')//处理加法和减法
        {
            if(ch.empty()||ch.top()=='(')
                ch.push(s[i++]);
            else
            {
                int ls=ys();//数字进行加减运算
                nub.push(ls);//将获得的新数字入栈
                ch.pop();//加减运算符出栈
                ch.push(s[i++]);
            }
        }
        else if(s[i]=='*'||s[i]=='/')
        {
            if(ch.empty()||ch.top()=='('||ch.top()=='+'||ch.top()=='-')//处理乘法和除法
                ch.push(s[i++]);
            else
            {
                int ls=ys();//运算如上述
                nub.push(ls);
                ch.pop();
                ch.push(s[i++]);
            }
        }
        else if(s[i]==')')//遇到右括号
        {
            while(ch.top()!='(')//出栈左括号之前的运算符
            {
                int ls=ys();//运算
                nub.push(ls);//新数字入栈
                ch.pop();
            }
            ch.pop();//将右括号出栈
            i++;
        }
    }
    while(ch.size()>1)//栈中还有剩余的运算符，留一个下面运算输出结果
    {
        int ls=ys();
        nub.push(ls);
        ch.pop();
    }
    cout<<"结果为："<<ys()<<endl;
    system("pause");
    return 0;
}