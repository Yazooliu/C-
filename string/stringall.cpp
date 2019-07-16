#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
vector<string> split(const string &str, const string &pattern)
{
    vector<string> res;
    if(str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

class Solution{
public:
	vector<string> Split(string input,vector<string>ListofToken,vector<string> &res){
		string tmpstr;
	
		
		// if input or ListofToken is empty //
		if(input.size() == 0)
			return res;
	    if(ListofToken.size()== 0){
			tmpstr = input.substr(0,input.size());
			res.push_back(tmpstr);
		}

		// if input and ListofToken are not empty //
		set<char> records;
		for(int i = 0;i<ListofToken.size();i++)
			for(int j=0;j<ListofToken[i].size();j++)
				records.insert(ListofToken[i][j]);
			
		//
		int rawinputsize = input.size();
		for(int i = 0;i<input.size();i++)
			if(records.find(input[i])!= records.end()) // in input, can find char in ListofToken
			{
				tmpstr = input.substr(0,i);
				res.push_back(tmpstr);
				input = input.substr(i+1,rawinputsize-i-1);
				//i = 0;
			}
			
				
	}
};


void main()
{
  string inputs = "abc,def.ghi";
  size_t pos1st = inputs.find("ef");
  string c[]=  {"ef","c"};
  
  vector<string>ListofToken;
  ListofToken.push_back(c[0]);
  ListofToken.push_back(c[1]);
  vector<string> res;
  Solution().Split(inputs,ListofToken,res);
  
  getchar();
}