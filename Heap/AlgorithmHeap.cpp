#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap
{
private:
	int count; // 元素个数
	int capacity;
	Item* data;
	void shiftup(int k )
	{
		while (data[k] > data[k/2] && k>1) // 跟父亲节点的比较
		{
			swap(data[k],data[k/2]);
			k = k/2;   // 交换后 索引k 变为原来的1/2
		}
	}
	void ShiftDown(int k)
	{
		while(2*k<count)
		{
	       Item j = 2*k;
		   if (data[j+1]>data[j]&& j+1<count)  // j+1<count表示  存在右边的分支，右孩子大于左孩子
			   j ++; //  右边的分支索引
		   
		   if (data[k] > data[j]) break;
		   swap(data[k],data[j]);
		   k = j;
		}
	}
public:
	MaxHeap(int capacity)
	{
		data = new Item[capacity +1];
		count = 0;
		this->capacity = capacity;
	}

	MaxHeap(Item arr[],int n)
	{
		data = new Item[n+1];
		capacity = n;
		for (int i = 0;i<n;i++)
			data[i+1] = arr[i];
		count = n;
		
		for (int i = count/2;i>=1;i--) 
			ShiftDown(i); // 一旦shiftdown以后,将data 中原来arr 数据元素的样子整合成堆的样子
	}

	~MaxHeap()
	{
		delete [] data;
	}

	int size(){
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}
	

	// 在先有的堆中插入新的元素
    void InsertItem(Item item)
	{
		assert(count + 1 <= capacity);
		data[count+1] = item;  // 堆是从索引1 开始计数的
		count++;
		shiftup(count);
	}

	//shiftdown -提取出根节点并把最后的索引值放到根节点上
	Item ExtractMax()
	{
		assert(count>0);
		/*找到根节点返回，并将最后索引的值交换给根节点，堆的总数减少1*/
		Item ret  = data[1];
		swap(data[1],data[count]);
		count --;
		ShiftDown(1);
		return  ret;
	}
	
	// Get MaxItem in 堆顶
	Item getMax()
	{
		assert(count>0);
		return data[1];
			
	}
		
	
};
// 堆排序
//利用堆的特性可以实现排序   - 无论是创建堆或者是抽取堆的时间复杂度为o(nlogn)
template<typename T>
void HeapSort(T arr[],int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);  // 插入后生成堆
	for (int i=0;i<n;i++)
		maxheap.InsertItem(arr[i]);

	for(int i = n-1;i>=0;i--)  // 通过每次找到最大值，生成由小到大的 arr[];
		arr[i] = maxheap.ExtractMax();

}

//  通过heapify 来创建堆的时间复杂度为o(n)
template<typename T> // 这里调用MaxHeap(Item arr[],int n) 过程
void HeapSort2(T arr[],int n)
{
	// 通过heapify 来创建最大堆
	MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
	for(int i = n-1;i>=0;i--)
		arr[i] = maxheap.ExtractMax();

}



// 原地堆排序
template<typename T>
void __shifdown(T arr,int n,int k)
{
	while(2*k+1<n)  // 这里堆的根索引是从0 开始算的，所以左边的索引是2k+1,右边的是2k+2
	{
		int j = 2*k +1;
	    if (arr[j+1]>arr[j] && j+1<n)
			j++;

		if (arr[k]>=arr[j]) break; // index k 是我们要shifdown 的目标index
		swap(arr[k],arr[j]);
		j = k;
	}
}

template<typename T> 
void HeapSort2(T arr[],int n)
{
	// Heapify ->从第一个非叶子节点的索引开始
	for (int i = (n-1)/2; i>=0;i--)  // (n-1)/2 最后一个非叶子节点
		__shifdown(arr,n,i);
	
	for(int i = n-1;i>0;i--) 
		swap(arr[0],arr[i]);  // 对于最大堆，先将第一个也就是根节点的值放到最后，除了最后一个点之外的所有点，就不再是最大堆了；现在对剩余的元素的第一个元素使用shifdown再生成最大堆；然后再把生成后的最后一个
	// 跟第一个交换;依次循环下就可以从小到大排序完成
	    __shifdown(arr,i,0); //  
}

int main()
{
	MaxHeap<int> maxheap =MaxHeap<int>(100);  // 将100 传入
	cout<<maxheap.size()<<endl;
	
	int n =200;
	// 往堆中插入一个元素
	for (int i = 0;i<n;i++)
		maxheap.InsertItem(rand()%200);
	
	int *arr = new int[n];
	for (int i = 0;i<n;i++)
	{
		arr[i] = maxheap.ExtractMax();  // 取出最大值 然后按照从大到小排序
		cout<< arr[i]<<endl;
	}



	getchar();
	return 0;
}