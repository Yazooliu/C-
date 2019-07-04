#include <iostream>
#include <algorithm>
using namespace std;

// #1.选择排序:从小到大排序
void sortselection(int arr[],int n)
{
	int i= 0;
	for (i=0;i<n;i++)
	{
		int minIndex = 0;
		minIndex = i;
		for (int j= i+1;j<n;j++)  // 通过遍历 找到最小值对应的所用给minIndex 
		{
			if (arr[j]<arr[minIndex])
			   minIndex = j;
		}
		swap(arr[i],arr[minIndex]);  // 前面的值给最小值minIndex 交换
	}

	
}
// 求数组的长度
template <class T>
int length(T &arr)
{
	return sizeof(arr)/sizeof(arr[0]);
}

// 算法模板化
template <typename T>
void Sortselection(T arr[],int n)
{
	int i= 0;
	for (i=0;i<n;i++)
	{
		int minIndex = 0;
		minIndex = i;
		for (int j= i+1;j<n;j++)  // 通过遍历 找到最小值对应的所用给minIndex 
		{
			if (arr[j]<arr[minIndex])
			   minIndex = j;
		}
		swap(arr[i],arr[minIndex]);  // 前面的值给最小值minIndex 交换
	}

}

// #2插入排序
template<typename T>
void InsertSort(T arr[],int n)
{
	for (int i = 0;i<n;i++)
	{
		for(int j=i+1;j>0&&j<n;j--)  // 这里j不是i+1;因为j+1超过最大索引.
	   {

		   if (arr[j]<arr[j-1]){
			   swap(arr[j],arr[j-1]);
		   }
		   else
			   break;
	   }
	}
}
// #3插入排序改进版
template<typename T>
void InsertSortAdvance(T arr[],int n)
{
	
	for(int i =1;i<n; i++)
	{
		T eValue = arr[i];  // 先找到一个中间变量
		int j = 0;
		for(j = i; j>0; j--)
		{
			if (arr[j-1]>eValue)
			{
				arr[j] = arr[j-1];
			}
			else 
				break;
			
		}
		arr[j] = eValue;
	}

}

//#4 归并排序
//3.
template <typename T>
void __merge(T arr[],int l,int mid,int r)
{
    T *aux = new T[r-l+1];
    for(int i = l;i<=r;i++)
    {
        aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid + 1;
    for (int k = l;k<=r;k++)
    {
        if (i>mid)
        {
            arr[k] = aux[j-l];
            j ++;
        }
        else if (j>r)
        {
            arr[k] = aux[i-l];
            i++;
        }
        else if (aux[i-l]<aux[j-l])
        {
            arr[k] = aux[i-l];
            i++;
        }
        else
        {
            arr[k] = aux[j-l];
            j++;
        }
    }
	delete [] aux;
    
}

template <typename T>
void __mergeSort(T arr[],int l,int r)
{
    if(l>=r)
        return;
    int mid = (r +l)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    __merge(arr,l,mid,r);
}

template <typename T>
void mergeSort(T arr[],int n)
{
    __mergeSort(arr,0,n-1);
}
//#5 快速排序
template<typename T>
int _partition(T arr[],int l,int r )
{
	// 快速排序针对近乎有序的数组的排序会降低到o(n**2)的计算负责度
	//swap(arr[l],arr[rand()&(r-l+1)+l]);
	//索引-> [l,,,,,,j [p] j+1,,,,,,,,r]
	//值  -> [v,,,,,,,..........,,,]
	T v = arr[l];
	//arr[L+1,......j]<v, arr[j+1,.....i)>v  #这里i是要检查的索引,i取开区间
	int j = l;
	for(int i = j+1; i<=r;i++)
	{
		if (arr[i]<v)
		{
			
			swap(arr[i],arr[j+1]);
			j++;
			
		}
		/*else if (arr[i]>v)
		{
			i++；
		}*/ // else 逻辑重叠于for(;;i++)
			
	}
	// 遍历完成后,将l的值v 与 j 的位置交换，以把v 值放到中间适当的位置
	swap(arr[l],arr[j]);
	return j;
}
template<typename T>
void _quicksort(T arr[],int l,int r )
{
	if (l>=r)
		return;
	//先找到一个索引p,然后将前半部分和后半分分别使用快速排序
	int p = _partition(arr,l,r);
	_quicksort(arr,l,p-1);  // 前半部分,
	_quicksort(arr,p+1,r);  // 后半部分,
}
template<typename T>
void quicksort(T arr[],int n)
{
	_quicksort(arr,0,n-1);
}

//#6 两路快排序
template <typename T>
int quicksort2wayspartition(T arr[],int l,int r )
{
	//arr[l+1,i) <v; arr(j,...r]>v
	swap(arr[l],arr[rand()%(r-l+1) + l]);
	T v = arr[l];
	int i = l+1;
	int j = r;
	while(true){
	
		while(i>=l+1 && arr[i]<v)
			i++;
		while(j<=r && arr[j]>v)
			j--;
		if(i>j)
			break;

		swap(arr[i],arr[j]);
		i++;
		j--;
			
	}
	swap(arr[l],arr[j]);
	return j;
}
template <typename T>
void _quicksort2ways(T arr[],int l,int r )
{
	if (l>r)
		return;
	int p = quicksort2wayspartition(arr,l,r);
	_quicksort2ways(arr,l,p-1);
	_quicksort2ways(arr,p+1,r);
	
}
template <typename T>
void quicksort2ways(T arr[],int n)
{
	
	_quicksort2ways(arr,0,n-1);
}



//# 3路快速排序
template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

 
    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap( arr[l], arr[rand()%(r-l+1)+l ] );

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l+1;    // arr[lt+1...i) == v
    while( i < gt ){
        if( arr[i] < v ){
            swap( arr[i], arr[lt+1]);
            i ++;
            lt ++;
        }
        else if( arr[i] > v ){
            swap( arr[i], arr[gt-1]);
            gt --;
        }
        else{ // arr[i] == v
            i ++;
        }
    }

    swap( arr[l] , arr[lt] );

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n){

    __quickSort3Ways( arr, 0, n-1);
}

//
int main()
{
	int arr[] = {1,2,9,2,19,19,19,22,20,0,21,8,4,5};

	//sortselection(arr,length(arr));  // 选择排序
	//Sortselection(arr,length(arr));  // 选择排序 模板化
	//InsertSort(arr,length(arr)); // 插入排序
	//InsertSortAdvance(arr,length(arr));  //插入排序改进版
	//mergeSort(arr,length(arr)); // 归并排序
	//quicksort(arr,length(arr)); // 快速排序
    //quicksort2ways(arr,length(arr));// 2路快排
	//quickSort3Ways(arr,length(arr));// 3 路快排序
	for (int i =0;i<length(arr);i++)
	{
		cout<<arr[i]<<";";
		
	}
	cout<<endl;
	getchar();
	return 0;
}


