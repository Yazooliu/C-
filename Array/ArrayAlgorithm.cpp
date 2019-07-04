// ArrayAlgorithm.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

// 二分查找法
template <typename T>
int binaryserach (T arr[],int n,T target) // 在长度为n的 T arr[]上通过二分法查找target 
{
	   // [l......r] 的数据区间上
       int l = 0; // 初始化
	   int r = n; //[l,,,r)hi


	   
	   while (l<r) // l==r 以后区间有数,边界数目
	   {
		   int mid = (r-l)/2 + l;
		   if(arr[mid] == target)
	        {
		       return mid;
	        }
		   else if (target < arr[mid]) // 左边区域 [l,....mid) 这里区域不包括mid 
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
//# 方法1
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
		
//#2.方法2
		/*int k = 0; // [0,,,,,k)存放非零元素
		for(int i = 0;i< nums.size(); i++)
		{
			if(nums[i]) // 利用索引k存放非零元素在原来的nums中
			{
			  nums[k] = nums[i];
			  k++;
			}
		}
		// 剩余位置全部补上0
		for (int i = k; i<nums.size(); i++ )
		{
		    nums[i] = 0;	
		}*/
		

//#3方法三
		// 利用k 索引记录非领元素的，
		
		/*int k = 0;
		for (int i = 0;i<nums.size(); i++)
		{
			if (nums[i]) // 如果nums[i]非零则交换
			{
				swap(nums[i],nums[k]);
				k++; // 指向下一个非零索引
			}
			
		}*/


    }// end of moveZeroes

// 27 
	int removeElement(vector<int>& nums, int val) {

		//#1.直接遍历找到后erase 
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
		
	// #2。
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

	// 方法1
    // # 26在有序的数字数组中，去掉重复的数字的后返回数字数组的长度
		/*int removeDuplicates(vector<int>& nums) {
		    int k = 0;
			if (nums.size()== 0)
				return k;
		   //数组非空的情况
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
	//方法2;
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
			if (nums[i] != nums[i+2]) // 非三个数字连续的情况
			{
                 // 1.连续三个数都彼此不相同的情况
				if (nums[i+1] != nums[i] && nums[i+1] != nums[i+2])
				{
					nums[k] = nums[i];
					nums[k+1] = nums[i+1];
					nums[k+2] = nums[i+2];
					k = k+3;
				}
				else
					//2 前两个一样或者后两个一样的情况
				{
					nums[k] = nums[i];
					nums[k+1] = nums[i+2];
					k = k+2;
				}
				
			}
			else // 相同数字到达三个及三个以上的情况 nums[i] == nums[i+2], i<nums.size()-2
			{
				// 赋值及计算仅仅执行一次
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
		int count = 1; // 相同元素的计数器
		int k = 0;     // 用来存放数据
		int len = nums.size();

		for(int i = 0; i<nums.size()-1; i++)
		{
			if (nums[i] == nums[i+1])
			{
				count ++;
			    if (count== 2) // 有两个相同的情况
				{
					count = 2;
					nums[k] =nums[i];
					k++;
				}
				else // 多余两个相同的情况，不处理。因为在上面的count == 2的分支中已经处理
				{
					//i++; // 索引继续遍历
					len--;
				}
			}
			else // if nums[i] != nums[i+1] --- 有长段相同元素的时候，随着索引i 的增加,只会去长段的首末数字填充到nums[k]
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
