#include <iostream>
#include <map>
#include <conio.h>

using namespace std;

void main()
{
	char ch;
	map<char,int> Asciitable;
	int i;
	for(i=0;i<26;i++)
	{
		Asciitable.insert(pair<char,int>('A'+i,(int)('A'+i)));

	}
	for(i=0;i<26;i++)
	{
		Asciitable.insert(pair<char,int>('a'+i,(int)('a'+i)));
	}
	cout<<"\n Enter a character for which the ASCII value has to be fetched :";
	cin>>ch;
	map<char,int>::iterator iter;
	iter=Asciitable.find(ch);
	if(iter==Asciitable.end())
		cout<<"\n Character not found!";
	else
		cout<<"\n The ASCII value for character "<<ch<<" is "<<iter->second;
	getch();
}
