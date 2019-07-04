// ArrayAlgorithm.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

// ���ֲ��ҷ�
template <typename T>
int binaryserach (T arr[],int n,T target) // �ڳ���Ϊn�� T arr[]��ͨ�����ַ�����target 
{
	   // [l......r] ������������
       int l = 0; // ��ʼ��
	   int r = n; //[l,,,r)hi


	   
	   while (l<r) // l==r �Ժ���������,�߽���Ŀ
	   {
		   int mid = (r-l)/2 + l;
		   if(arr[mid] == target)
	        {
		       return mid;
	        }
		   else if (target < arr[mid]) // ������� [l,....mid) �������򲻰���mid 
			   r = mid;
		   else 
			   l = mid +1; // [mid+1 ,,,r)
	   }
	 return -1;
}

// # 283.MOve Zersos 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//# ����1
		/*vector<int> NoneZerosnums;
		for(int i =0; i< nums.size();i++)
		{ 
			if (nums[i]!=0)
			{
				NoneZerosnums.push_back(nums[i]);
			}
			
		}
		for (int i = 0;i<NoneZerosnums.size();i++  )
			nums[i] = NoneZerosnums[i];
		for (int i =NoneZerosnums.size(); i<nums.size();i++ )
			nums[i] = 0;*/
		
//#2.����2
		/*int k = 0; // [0,,,,,k)��ŷ���Ԫ��
		for(int i = 0;i< nums.size(); i++)
		{
			if(nums[i]) // ��������k��ŷ���Ԫ����ԭ����nums��
			{
			  nums[k] = nums[i];
			  k++;
			}
		}
		// ʣ��λ��ȫ������0
		for (int i = k; i<nums.size(); i++ )
		{
		    nums[i] = 0;	
		}*/
		

//#3������
		// ����k ������¼����Ԫ�صģ�
		
		/*int k = 0;
		for (int i = 0;i<nums.size(); i++)
		{
			if (nums[i]) // ���nums[i]�����򽻻�
			{
				swap(nums[i],nums[k]);
				k++; // ָ����һ����������
			}
			
		}*/


    }// end of moveZeroes

// 27 
	int removeElement(vector<int>& nums, int val) {

		//#1.ֱ�ӱ����ҵ���erase 
	    /*vector<int>::iterator it;
		for(it = nums.begin();it !=nums.end();)
			if (*it == val)
			{
				it = nums.erase(it);
			}
			else
				it++;
		for(int i = 0;i<nums.size();i++)
			cout<< nums[i] << " ";
	cout<<endl;
	return nums.size();*/
		
	// #2��
		int k = 1;// 
		for(int i = 0;i<nums.size();i++)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[k];
				k++;
			}
			
		}
	}
};

class Solution26 {
public:

	// ����1
    // # 26����������������У�ȥ���ظ������ֵĺ󷵻���������ĳ���
		/*int removeDuplicates(vector<int>& nums) {
		    int k = 0;
			if (nums.size()== 0)
				return k;
		   //����ǿյ����
			for (int i = 0;i <nums.size()-1;i++)
			{
				if (nums[i]!=nums[i+1])
				{
					nums[k]=nums[i];
					k++;
				}	      
			}
				
			nums[k] = nums[nums.size()-1];
			k++;
        return k;
    }*/
	//����2;
	int removeDuplicates(vector<int>& nums) {

	}
};
		
class Solution80 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()== 0)
			return 0;
		int k = 0;
		for(int i = 0;i<nums.size()-2;i++)
		{
			// 1.
			if (nums[i] != nums[i+2]) // �������������������
			{
                 // 1.�������������˴˲���ͬ�����
				if (nums[i+1] != nums[i] && nums[i+1] != nums[i+2])
				{
					nums[k] = nums[i];
					nums[k+1] = nums[i+1];
					nums[k+2] = nums[i+2];
					k = k+3;
				}
				else
					//2 ǰ����һ�����ߺ�����һ�������
				{
					nums[k] = nums[i];
					nums[k+1] = nums[i+2];
					k = k+2;
				}
				
			}
			else // ��ͬ���ֵ����������������ϵ���� nums[i] == nums[i+2], i<nums.size()-2
			{
				// ��ֵ���������ִ��һ��
				if(nums[i] != nums[i+3])
				{
					nums[k] = nums[i]; 
					k++;
				}
			}
			
		}// for end 
		nums[k]=nums[nums.size()-2];
		nums[k+1]=nums[nums.size()-1];
		k = k+2;
		return k;
    }
};

class Solution80New {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0<=nums.size()<=2)
			return nums.size();
		int count = 1; // ��ͬԪ�صļ�����
		int k = 0;     // �����������
		int len = nums.size();

		for(int i = 0; i<nums.size()-1; i++)
		{
			if (nums[i] == nums[i+1])
			{
				count ++;
			    if (count== 2) // ��������ͬ�����
				{
					count = 2;
					nums[k] =nums[i];
					k++;
				}
				else // ����������ͬ���������������Ϊ�������count == 2�ķ�֧���Ѿ�����
				{
					//i++; // ������������
					len--;
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

//This is 
//int main()
//{
	/*int arr[] = {0,1,0,3,12};
	vector<int> vec(arr,arr + sizeof(arr)/sizeof(int));
	Solution().moveZeroes(vec);
	for (int i =0; i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;*/



//#27 
	/*int arr[] = {0,3,2,2,3,6,1,22,3};
	vector<int> vec(arr,arr+ sizeof(arr)/sizeof(int));
	int sum =Solution().removeElement(vec,3);
	cout<<"sum is "<< sum;*/



//#26
	/*int arr[] = {0,0,1,1,1,1,2,2,3,3,3,4,4,4,4,5,5,8};
	vector<int> vec(arr,arr + sizeof(arr)/sizeof(int));
	//int k = Solution26().removeDuplicates(vec);
	int k = Solution80New().removeDuplicates(vec);
	for (int i =0; i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	cout<<" k = "<< k;

	getchar();

	return -1;
}*/
