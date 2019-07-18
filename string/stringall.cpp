#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

vector<string> split(string str, vector<string> ListOfToken)
{
    vector<string> res;
    // if input or ListofToken is empty //
	if(str.size() == 0)
		return res;
	if(ListOfToken.size()== 0){
		str = str.substr(0,str.size());
		res.push_back(str);
	}
    // set ch as set as no depuliacted fromListOfToken//
	set<char> ch;
	for(int i=0;i<ListOfToken.size();i++)
		for(int j=0;j<ListOfToken[i].size();j++)
			ch.insert(ListOfToken[i][j]);
	
    for(set<char>::iterator iter = ch.begin();iter!=ch.end();iter++){
		size_t pos = str.find(*iter);
		//ch.erase(iter);
		if(pos!= str.npos){
			string curstring = str.substr(0,pos); // pos = length 
			res.push_back(curstring);
			str = str.substr(pos+1,str.size());
		}
	}
	res.push_back(str);
    return res;
}

void main()
{
  string inputs = "abc,def.ghi";
  vector<string> strs;
  strs.push_back("ef");
  strs.push_back("v");
  vector<string> res = split(inputs,strs);
  
  for(int i = 0;i<res.size();i++)
	    cout<<res[i]<<" ";
  
  getchar();
}

def CheckHave(inputs,listoftoken):
    '''
    inputs:      inputs string 
    listoftoken: list of token 
    puprose    : This functon is used to check if inputs-string have any char in listoftoken; 
                 if have reture True; if don't have return False
    '''
    Haveornot = False
    for i in range(len(inputs)):
        for j in range(len(listoftoken)):
            if listoftoken[j] == inputs[i]:
                Haveornot = True
     
    return Haveornot
