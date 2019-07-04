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
	int count; // Ԫ�ظ���
	int capacity;
	Item* data;
	void shiftup(int k )
	{
		while (data[k] > data[k/2] && k>1) // �����׽ڵ�ıȽ�
		{
			swap(data[k],data[k/2]);
			k = k/2;   // ������ ����k ��Ϊԭ����1/2
		}
	}
	void ShiftDown(int k)
	{
		while(2*k<count)
		{
	       Item j = 2*k;
		   if (data[j+1]>data[j]&& j+1<count)  // j+1<count��ʾ  �����ұߵķ�֧���Һ��Ӵ�������
			   j ++; //  �ұߵķ�֧����
		   
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
			ShiftDown(i); // һ��shiftdown�Ժ�,��data ��ԭ��arr ����Ԫ�ص��������ϳɶѵ�����
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
	

	// �����еĶ��в����µ�Ԫ��
    void InsertItem(Item item)
	{
		assert(count + 1 <= capacity);
		data[count+1] = item;  // ���Ǵ�����1 ��ʼ������
		count++;
		shiftup(count);
	}

	//shiftdown -��ȡ�����ڵ㲢����������ֵ�ŵ����ڵ���
	Item ExtractMax()
	{
		assert(count>0);
		/*�ҵ����ڵ㷵�أ��������������ֵ���������ڵ㣬�ѵ���������1*/
		Item ret  = data[1];
		swap(data[1],data[count]);
		count --;
		ShiftDown(1);
		return  ret;
	}
	
	// Get MaxItem in �Ѷ�
	Item getMax()
	{
		assert(count>0);
		return data[1];
			
	}
		
	
};
// ������
//���öѵ����Կ���ʵ������   - �����Ǵ����ѻ����ǳ�ȡ�ѵ�ʱ�临�Ӷ�Ϊo(nlogn)
template<typename T>
void HeapSort(T arr[],int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);  // ��������ɶ�
	for (int i=0;i<n;i++)
		maxheap.InsertItem(arr[i]);

	for(int i = n-1;i>=0;i--)  // ͨ��ÿ���ҵ����ֵ��������С����� arr[];
		arr[i] = maxheap.ExtractMax();

}

//  ͨ��heapify �������ѵ�ʱ�临�Ӷ�Ϊo(n)
template<typename T> // �������MaxHeap(Item arr[],int n) ����
void HeapSort2(T arr[],int n)
{
	// ͨ��heapify ����������
	MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
	for(int i = n-1;i>=0;i--)
		arr[i] = maxheap.ExtractMax();

}



// ԭ�ض�����
template<typename T>
void __shifdown(T arr,int n,int k)
{
	while(2*k+1<n)  // ����ѵĸ������Ǵ�0 ��ʼ��ģ�������ߵ�������2k+1,�ұߵ���2k+2
	{
		int j = 2*k +1;
	    if (arr[j+1]>arr[j] && j+1<n)
			j++;

		if (arr[k]>=arr[j]) break; // index k ������Ҫshifdown ��Ŀ��index
		swap(arr[k],arr[j]);
		j = k;
	}
}

template<typename T> 
void HeapSort2(T arr[],int n)
{
	// Heapify ->�ӵ�һ����Ҷ�ӽڵ��������ʼ
	for (int i = (n-1)/2; i>=0;i--)  // (n-1)/2 ���һ����Ҷ�ӽڵ�
		__shifdown(arr,n,i);
	
	for(int i = n-1;i>0;i--) 
		swap(arr[0],arr[i]);  // �������ѣ��Ƚ���һ��Ҳ���Ǹ��ڵ��ֵ�ŵ���󣬳������һ����֮������е㣬�Ͳ����������ˣ����ڶ�ʣ���Ԫ�صĵ�һ��Ԫ��ʹ��shifdown���������ѣ�Ȼ���ٰ����ɺ�����һ��
	// ����һ������;����ѭ���¾Ϳ��Դ�С�����������
	    __shifdown(arr,i,0); //  
}

int main()
{
	MaxHeap<int> maxheap =MaxHeap<int>(100);  // ��100 ����
	cout<<maxheap.size()<<endl;
	
	int n =200;
	// �����в���һ��Ԫ��
	for (int i = 0;i<n;i++)
		maxheap.InsertItem(rand()%200);
	
	int *arr = new int[n];
	for (int i = 0;i<n;i++)
	{
		arr[i] = maxheap.ExtractMax();  // ȡ�����ֵ Ȼ���մӴ�С����
		cout<< arr[i]<<endl;
	}



	getchar();
	return 0;
}