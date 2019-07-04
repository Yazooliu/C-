#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution349 {
public:
	// ʱ�临�Ӷ�O(n)
	// �ؼ����Ӷ�o(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
   
		// (nlogn���ȱ�������� n*log 
		set<int> copyset(nums1.begin(),nums1.end());
	//for(int i = 0;i<nums1.size();i++)
		//copyset.insert(nums1[i]);
	

	//(nlogn ;�ȱ������ٱȽϲ���n*lognʱ�临�Ӷ�
	set<int>myset;
	for(int i = 0;i<nums2.size();i++)
		if(copyset.find(nums2[i]) != copyset.end() )
		{
			myset.insert(nums2[i]);
		}
	
	// ����0(n) 
	/*vector<int>returnvector;
	for(set<int>::iterator iter = myset.begin(); iter != myset.end();iter++)
	{
		returnvector.push_back(*iter);
	}*/
		return vector<int>(myset.begin(),myset.end());


    }
};

class Solution350 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // �󽻼�������Ҫȡ���ظ���,����map�ļ�ֵ����
    map<int,int> record;
	// ͳ��Ƶ��
	for(int i= 0;i<nums1.size();i++)
		record[nums1[i]] ++;

	vector<int> result;
	for(int i= 0;i<nums2.size();i++){
		if( record[nums2[i]]>0   ) // nums����nums1����nums2��
		{
			result.push_back(nums2[i]);
			record[nums2[i]]--;   // record�е�Ƶ�μ���1.
		}   
	    }
	return result;
    }
};

class Solution1002 {
public:
    vector<string> commonChars(vector<string>& A) {
	map<int,int> record;
	for(vector<string>::iterator it = A.begin(); it != A.end(); it++)
	{
		
	}
		
        
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
	// ���ù�ϣ�� unorder_map/unorderd_set ����ʹ�ý���ʱ�临�Ӷ�
     unordered_map<int,int> record;
	 for(int i = 0; i<nums.size();i++)
	 {
		 int cm = target - nums[i];
		 if(record.find(cm) != record.end())
		 {
			 int res[] = {i, record[cm]};
			 return vector<int>(res,res+2);
		 }

		 record[nums[i]] = i; // ֵ��key, ������value 
	 }
    throw invalid_argument("the input has no solutions");
    }
};

class Solution447 {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
    // O(n) ����ļ��㸴�Ӷ�
    
    int res = 0;
    for(int i = 0;i<points.size();i++){
        unordered_map<int,int> record; // key��ž��룬value�������������ĵ��м���
        for(int j = 0;j<points.size();j++)
            if(i=!j)
                record[distance(points[i],points[j])] ++; 
        
        
        for(unordered_map<int,int>::iterator iter = record.begin();iter!=record.end();iter++)
            res+= (iter->second)*(iter->second-1); // iter->second>=2
        
    }
    return res;
    }
    
private:
    int distance(const pair<int, int>& points1,const pair<int, int>& points2)
    {
        return (points1.first -  points2.first)*(points1.first -  points2.first) + 
            (points1.second -  points2.second)* (points1.second -  points2.second);
    }
};

// ��������+ ����
class Solution219 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	// ʱ�临�Ӷ�ΪO(n),))(k) �ռ临�Ӷ�
    // ��ѡ������[l,..i...j,....l+k]��������ҵ�iandj ʹnums[i] == nums[j] �򷵻�True;
	// ���û���ҵ�������nums[l+k+1] �ǲ���������[l+1,,,,.....k+l] �����ڡ����û���������Ҷ˼�1 �ϲ���nums[l+k+1] �������[l+1,,;......l+k+1]
	unordered_set<int> record;
	for(int  i= 0;i<nums.size();i++)
	{
		if(record.find(nums[i]) != record.end())
		{
			return true;
		}
		record.insert(nums[i]);
		
		//ȷ��record �еĳ��Ȳ�����K
		if(record.size() == k+1)
			record.erase(nums[i-k]);
	}
	return false;
	}
};

class Solution220 {
public:
	// ʱ�临�Ӷ�nlogn
    // �ռ临�� O(k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // find index: i and j to make sure thet abs(nums[i] - nums[j]) <= t and j-i<= k
	if(t<0)
		return false;
	set<long long> record;
	for(int i = 0;i<nums.size();i++)
	{
		if(  record.lower_bound((long long)nums[i]-(long long)t) != record.end() && 
			*record.lower_bound((long long)nums[i] - (long long)t)<= (long long)nums[i] + (long long)t )
			return true;
			
		record.insert(nums[i]);
		if(record.size() == 1+k)
			record.erase(nums[i-k]);
	}

	return false;
    }
};

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int,int> record;
	for(int i =0;i<nums.size();i++)
		record[nums[i]]++;
	
	vector<vector<int>> result;
	if(record[0]>=3) //0 ���ֵ�Ƶ��>=3
	{
		vector<int>vec(3,0);
		result.push_back(vec);
	}
	 
	//��nums��ȡ���ظ���Ԫ��
	sort(nums.begin(),nums.end());
	vector<int>::iterator iter = unique(nums.begin(),nums.end()); // ���ظ����ֵ�Ԫ�����ں���
	nums.erase(iter,nums.end()); // ȥ��ĩβ�ظ���Ԫ��
	
	//����
	for(int i= 0;i<nums.size();i++){
		for(int j =i+1;j<nums.size();j++){
			if(nums[i]*2 + nums[j] == 0 && record[nums[i]]>=2) // record[nums[i]]>=2 �������record[nums[j]]>=2 ��Ϊ�˱������ֳ���Ƶ��Ϊ1������ظ����ֵ������record[nums[i]]>=2 ��˵��ȷʵ�ǳ���Ƶ�δ�Լ��2������£��Ż������ͬ��Ԫ����solution�С�
			{
				int res[3] = {nums[i],nums[i],nums[j]};
				vector<int> vec1(res,res+3);
				result.push_back(vec1);
			}
			
			if(nums[i] + 2*nums[j] == 0 && record[nums[j]] >=2)
			{
				int res[3] = {nums[i],nums[j],nums[j]};
				vector<int> vec2(res,res+3);
				result.push_back(vec2);
			}
			
			int c = 0-nums[i]-nums[j];
			if(record[c]!=0 && c>nums[j])
			{
			    int res[3] = {nums[i],nums[j],c};
				vector<int> vec3(res,res+3);
				result.push_back(vec3);	
			}
	

		}
	}
	return result;
    }
};

class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
	if(nums.empty() || nums.back() < 0 || nums.front() > 0){
		//vector<int> vec(0,0);
		//res.push_back(vec);
		res.clear();
	}
	sort(nums.begin(),nums.end());
	for(int i =0;i<nums.size();i++)
	{
		if(nums[i]>0) break;
		// nums[i] �����ظ��ɼ������d
		if(i>0 && nums[i] == nums[i-1]) continue;
		int target  = 0 - nums[i];
		int left  = i+1;
		int right = nums.size()-1;
		while(left<right){
			if(nums[left] + nums[right] == target)
			{
				int  target[3] = {nums[i],nums[left],nums[right]};
				vector<int> vec(target,target+3);
				res.push_back(vec);
				// �ڱ����Ĺ���������left and left+1��Ԫ���ظ�����
				// �ڱ����Ĺ���������right and right+1��Ԫ���ظ�����
				while(left<right&&nums[left] == nums[left+1]) left++;
				while(left<right&&nums[right] == nums[right-1]) right--;
				left++;
				right--;
			}
			else if (nums[left] + nums[right] < target)
			{
				left++;
			}
			else // (nums[left] + nums[right] > target)
			{
				right--;
			}
		
		} // while end 
		
	} // for end 
		return res;
    }
};

class Solutionboke {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0){
		vector<int> vec(0,0);
		res.push_back(vec);
		}
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    int  target[] = {nums[k],nums[i],nums[j]};
				    vector<int> vec(target,target+3);
				    res.push_back(vec);
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
		if(nums.size()<4) 
		{
			res.clear();
			return res;
		}
		// ����
		sort(nums.begin(),nums.end());
		for(int i = 0;i<nums.size()-3;i++)
		{
			if(i>0 && nums[i-1] == nums[i]) continue;  // �����ظ��ɼ�������
			for(int j= i+1; j<nums.size()-2;j++)
			{
				if(j>i+1 && nums[j] == nums[j-1]) continue; // �����ظ��ɼ�������
				int left  = j+1;
				int right = nums.size() -1;
			    
				while(left<right)
				{
					int sum   = nums[i] + nums[j] + nums[left] + nums[right];
					if(sum == target)
				    {
					   int vec[] = {nums[i],nums[j],nums[left],nums[right] };
					   vector<int> rev(vec,vec+sizeof(vec)/sizeof(vec[0]));
					   res.push_back(rev);

					   while(left<right && nums[left] == nums[left+1]) left++;
					   while(left<right && nums[right] == nums[right-1]) right--;

				       left++;
					   right--;
					
				    }
					else if (sum<target)
					{
						left++;
					}
					else //  (sum>target)
					{
						right--;
					}
				}

			} // for j end
				
		} // for i end 

		return res;
    }
};


void main()
{
    
	int nums[] = {1, 0, -1, 0, -2, 2};
	vector<int>vec(nums,nums + sizeof(nums)/sizeof(nums[0]));
	int target = 0;
	vector<vector<int>> result = Solution18().fourSum(vec,target);
	
	for(int i =0;i<result.size();i++)
		for(int j = 0;j<result[i].size();j++)
			cout<<result[i][j]<<" ";

	getchar();
	cout<<endl;

}