// Source.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

class Solution80New {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0<=nums.size()<=2)
			return nums.size();
		int count = 1; // ��ͬԪ�صļ�����
		int k = 0;     // �����������
		int len = nums.size();
		cout<<"len is " <<len;
		for(int i = 0; i<nums.size()-1; i++)
		{
			if (nums[i] == nums[i+1])
			{
				count ++;
			    /*if (count<2) // ��������ͬ�����
				{
					count = 2;
					nums[k] =nums[i];
					k++;
				}
				else // ����������ͬ���������������Ϊ�������count == 2�ķ�֧���Ѿ�����
				{
					//i++; // ������������
					len--;
				}*/
				if (count >=3)
				{
					len --;
				}
				else 
				{
					
				}
			}
			else // if nums[i] != nums[i+1] --- �г�����ͬԪ�ص�ʱ����������i ������,ֻ��ȥ���ε���ĩ������䵽nums[k]
			{
				count = 1;
				nums[k] = nums[i];
				k++;
			}
		}
		return len;

    }
};

template <typename T>
int length(T& arr)
{
  return sizeof(arr)/sizeof(arr[0]);	
}
template<typename T>
int removeDuplicates1(T nums[]) 
{
        if(nums.length == 0) return 0;
        if(nums.length <= 2) return nums.length;
        int len = nums.length;
        for(int i = 1,j=1,count = 1;j<nums.length;j++)
		{
            if(nums[j] == nums[j-1]) 
			{
                count++;
                if(count >= 3){                 //left pointer stay the same when count >=3
                    len--;
                }else{
                    nums[i] = nums[j];
                    i++; 
                }
            }
            else
			{
                count = 1;
                nums[i] = nums[j];
                i++;
            }
        }
      
   return len;
}

//80, ����1, ���ܵ����ݳ����У��ظ����ֵĴ�������2������>=3 �������,����len--;��󷵻�len
class Solution {
public:
    int removeDuplicates(int arr[]) {
        
    }
};

// 80; ����2 ����Ѱ�� ���������� - ��Ч
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0 && nums.size() <= 2)
		   return nums.size();
	   // �Ҵ����������֣�Ѱ�ҳ���
	   int count = 0;
	   int pos   = 0;
	   for(int i = 1;i <nums.size(); i++) // ������Ϊ1��ʼ;
	   {
		   if (nums[i] == nums[pos])
		   {
			   count++;
		       if (count <2) // ���ظ����ֵ����ֳ����У��������ַ���nums[pos], 
		       {
			      pos++; // pos ��ʼ��Ϊ0
			      nums[pos] = nums[i];
		       }
		   }
		   else // nums[i] != nums[pos]
		   {
			   count = 0;
			   pos++;
			   nums[pos] = nums[i]; // // ���ظ����ֵ����ֳ����У���ĩβ���ַ���nums[pos], 
		   }

	   }
      		   
      return 1 + pos; // �����ѭ���ٸ����˵�һ��������·����ͬ�Ļ��ǲ�ͬ��.

}
};

//80 
class solutios{
public:
	int removeDuplicates2(vector<int>& nums)
	{
		int i = 0;
		for(int n:nums)
			if(i<2||n>nums[i-2])
				nums[i++] = n;
		return i;
	}

};

// 75 ��·���ŵ�Ӧ��
class Solution75 {
public:
    void sortColors(vector<int>& nums) {
		//#1 ����1 �ȼ���ÿ�������ֵ�Ƶ�Σ�Ȼ�����������
		/*int arr[3] = {0};
		for (int i = 0;i<nums.size();i++)
		{
			assert(nums[i]>=0 && nums[i]<=2);
			arr[nums[i]] ++;        // ��¼��0,1,2���ֵĴ���,arr[0]��ʾ0���ֵĴ���,arr[1]��ʾ1 ���ֵĴ���;arr[2]��ʾ2���ֵĴ���
		}
		int index = 0;
		for(int i = 0;i<arr[0];i++) // ���ȫ0
			nums[index++] = 0;
		for(int i = 0;i<arr[1];i++) // ���ȫ1
			nums[index++] = 1;
		for(int i = 0;i<arr[2];i++) // ���ȫ2
			nums[index++] = 2;*/
	
       //#2 ����2 ʹ����·���ŵķ�������
		// [0....zero]  ȫ�������
		// [zero+1,,,two) ȫ1������
		// [two,,,,,n] ȫ2������
		    int zero = -1;
		    int two  = nums.size();
			for(int i = 0;i<two;)
			{
				if(nums[i] == 1)
					i++;
				else if (nums[i] == 0)
				{
					assert(nums[i] == 0);
					swap(nums[++zero],nums[i++]);  // ��nums[i]��zero+1 ����,���ص���ȷ����1,���i++ָ��һ�¸�Ԫ��
				}
				else // if nums[i] == 2 
					swap(nums[i],nums[--two]);     // ��nums[i]��two-1��Ԫ�ؽ��������ڽ�������two-1��Ԫ�ز�ȷ����ʲô�� ����i��������+1,�� ֻ�������i����
			}
    }
};

// #167 
class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    //#1.˫�����,ֱ���ҵ�������֮��Ϊtarget 
	 
	for(int i = 0;i<numbers.size()-1;i++)
	{
		for (int j = numbers.size()-1;j<=i;j--)
		{
			if(numbers[i] + numbers[j] == target){
			    int arr[] = {i+1,j+1};
				return vector<int>(arr,arr + sizeof(arr)/sizeof(int));

			}
			else
			{
				i++;
				j--;
			}
			
			
		}
	}
		

    //#2.���������,���ö��ַ�����



    //#3. ��ײָ��
    /*int left = 0;
	int right  = numbers.size()-1;
	// �쳣�ж�.
	vector<int> vec;
    if(numbers.size()<2)
		return vector<int>(0,0);

	while(left<right)
	{
		if(numbers[left] + numbers[right] == target)
		{
			int arr[] = {1+ left,1+right};
			return vector<int>(arr, arr + sizeof(arr)/sizeof(int));
		}
		else if (numbers[left] + numbers[right] < target) // 
			left++;
		else
			right--;
	}*/

    }
};


int main()
{
	int arr[] = {0,0,1,1,1,1,2,2,2,2,2,2,2,0,0,0,1,1,1};
	vector<int> vec(arr,arr + sizeof(arr)/sizeof(int));
	
	/*int k = Solution2().removeDuplicates(vec);
	for (int i =0; i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	cout<<" k = "<< k <<endl;
	cout<<"nums.size()"<<vec.size()<<endl;*/

	// 80 ��������㷽��;
	/*int pos  = 0;
	int count = 0;  // ����
	int len   = length(arr);
	int k1     = 0;
	for(int i = 1;i<len;i++)
		{
			if (arr[i] == arr[i-1])
			{
				count ++;
				if(count >1)
				{	
					len--;
				}	
				else
				{
					i++;
				}
			}
			else 
			{
				count = 0;
				i++;
			}
			
		}
	cout<<"------------"<<endl;	
	cout<<endl;
	cout<<"Len is "<<len;*/

	/*
	int lens = solutios().removeDuplicates2(vec);
	cout<<"lens is "<< lens <<endl;*/

	/*Solution75().sortColors(vec);
	for(int i = 0; i< vec.size();i++)
		cout<<vec[i] << " ";*/
	int numbers[] = {2,3,4};  // ��������
	int  target = 6;
	vector<int> testvec(numbers,numbers + sizeof(numbers)/sizeof(numbers[0]) );
	vector<int> IndexVector(Solution167().twoSum(testvec,target));
	for(int i = 0;i<testvec.size();i++)
		cout<<testvec[i]<< " ";
	cout<<endl;

	
	for(int ii =0;ii<3;ii++)
		for(int jj = 2; jj<=ii;jj--)
		{
			if(numbers[ii] + numbers[jj] == target)
			{
				cout<<" i+1= "<<ii+1;
				cout<<" j+1= "<<jj+1;
				break;
			}
			else
			{
				ii++;
				jj--;
			}
		}

		cout<<".....................";
	getchar();
	return -1;
}
