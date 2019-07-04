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
		int count = 1; // 相同元素的计数器
		int k = 0;     // 用来存放数据
		int len = nums.size();
		cout<<"len is " <<len;
		for(int i = 0; i<nums.size()-1; i++)
		{
			if (nums[i] == nums[i+1])
			{
				count ++;
			    /*if (count<2) // 有两个相同的情况
				{
					count = 2;
					nums[k] =nums[i];
					k++;
				}
				else // 多余两个相同的情况，不处理。因为在上面的count == 2的分支中已经处理
				{
					//i++; // 索引继续遍历
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

//80, 方法1, 在总的数据长度中，重复出现的次数超过2个，即>=3 的情况下,长度len--;最后返回len
class Solution {
public:
    int removeDuplicates(int arr[]) {
        
    }
};

// 80; 方法2 主动寻找 期望的数字 - 有效
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0 && nums.size() <= 2)
		   return nums.size();
	   // 找打期望的数字，寻找长度
	   int count = 0;
	   int pos   = 0;
	   for(int i = 1;i <nums.size(); i++) // 从索引为1开始;
	   {
		   if (nums[i] == nums[pos])
		   {
			   count++;
		       if (count <2) // 在重复出现的数字长度中，将首数字放入nums[pos], 
		       {
			      pos++; // pos 初始化为0
			      nums[pos] = nums[i];
		       }
		   }
		   else // nums[i] != nums[pos]
		   {
			   count = 0;
			   pos++;
			   nums[pos] = nums[i]; // // 在重复出现的数字长度中，将末尾数字放入nums[pos], 
		   }

	   }
      		   
      return 1 + pos; // 上面的循环少覆盖了第一个数。无路是相同的还是不同的.

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

// 75 三路快排的应用
class Solution75 {
public:
    void sortColors(vector<int>& nums) {
		//#1 方法1 先计算每个数出现的频次，然后再依次输出
		/*int arr[3] = {0};
		for (int i = 0;i<nums.size();i++)
		{
			assert(nums[i]>=0 && nums[i]<=2);
			arr[nums[i]] ++;        // 记录了0,1,2出现的次数,arr[0]表示0出现的次数,arr[1]表示1 出现的次数;arr[2]表示2出现的次数
		}
		int index = 0;
		for(int i = 0;i<arr[0];i++) // 输出全0
			nums[index++] = 0;
		for(int i = 0;i<arr[1];i++) // 输出全1
			nums[index++] = 1;
		for(int i = 0;i<arr[2];i++) // 输出全2
			nums[index++] = 2;*/
	
       //#2 方法2 使用三路快排的方法排序
		// [0....zero]  全零的区间
		// [zero+1,,,two) 全1的区间
		// [two,,,,,n] 全2的区间
		    int zero = -1;
		    int two  = nums.size();
			for(int i = 0;i<two;)
			{
				if(nums[i] == 1)
					i++;
				else if (nums[i] == 0)
				{
					assert(nums[i] == 0);
					swap(nums[++zero],nums[i++]);  // 将nums[i]与zero+1 交换,换回的是确定的1,因此i++指向一下个元素
				}
				else // if nums[i] == 2 
					swap(nums[i],nums[--two]);     // 将nums[i]与two-1号元素交换，由于交换来的two-1号元素不确定是什么， 所以i索引不必+1,而 只需继续从i开启
			}
    }
};

// #167 
class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    //#1.双层遍历,直至找到两个数之和为target 
	 
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
		

    //#2.有序的数组,利用二分法查找



    //#3. 对撞指针
    /*int left = 0;
	int right  = numbers.size()-1;
	// 异常判断.
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

	// 80 的数组计算方法;
	/*int pos  = 0;
	int count = 0;  // 计算
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
	int numbers[] = {2,3,4};  // 升序排序
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
