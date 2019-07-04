#include <iostream>
#include <algorithm>
using namespace std;

// #1.ѡ������:��С��������
void sortselection(int arr[],int n)
{
	int i= 0;
	for (i=0;i<n;i++)
	{
		int minIndex = 0;
		minIndex = i;
		for (int j= i+1;j<n;j++)  // ͨ������ �ҵ���Сֵ��Ӧ�����ø�minIndex 
		{
			if (arr[j]<arr[minIndex])
			   minIndex = j;
		}
		swap(arr[i],arr[minIndex]);  // ǰ���ֵ����СֵminIndex ����
	}

	
}
// ������ĳ���
template <class T>
int length(T &arr)
{
	return sizeof(arr)/sizeof(arr[0]);
}

// �㷨ģ�廯
template <typename T>
void Sortselection(T arr[],int n)
{
	int i= 0;
	for (i=0;i<n;i++)
	{
		int minIndex = 0;
		minIndex = i;
		for (int j= i+1;j<n;j++)  // ͨ������ �ҵ���Сֵ��Ӧ�����ø�minIndex 
		{
			if (arr[j]<arr[minIndex])
			   minIndex = j;
		}
		swap(arr[i],arr[minIndex]);  // ǰ���ֵ����СֵminIndex ����
	}

}

// #2��������
template<typename T>
void InsertSort(T arr[],int n)
{
	for (int i = 0;i<n;i++)
	{
		for(int j=i+1;j>0&&j<n;j--)  // ����j����i+1;��Ϊj+1�����������.
	   {

		   if (arr[j]<arr[j-1]){
			   swap(arr[j],arr[j-1]);
		   }
		   else
			   break;
	   }
	}
}
// #3��������Ľ���
template<typename T>
void InsertSortAdvance(T arr[],int n)
{
	
	for(int i =1;i<n; i++)
	{
		T eValue = arr[i];  // ���ҵ�һ���м����
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

//#4 �鲢����
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
//#5 ��������
template<typename T>
int _partition(T arr[],int l,int r )
{
	// ����������Խ�����������������ή�͵�o(n**2)�ļ��㸺���
	//swap(arr[l],arr[rand()&(r-l+1)+l]);
	//����-> [l,,,,,,j [p] j+1,,,,,,,,r]
	//ֵ  -> [v,,,,,,,..........,,,]
	T v = arr[l];
	//arr[L+1,......j]<v, arr[j+1,.....i)>v  #����i��Ҫ��������,iȡ������
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
			i++��
		}*/ // else �߼��ص���for(;;i++)
			
	}
	// ������ɺ�,��l��ֵv �� j ��λ�ý������԰�v ֵ�ŵ��м��ʵ���λ��
	swap(arr[l],arr[j]);
	return j;
}
template<typename T>
void _quicksort(T arr[],int l,int r )
{
	if (l>=r)
		return;
	//���ҵ�һ������p,Ȼ��ǰ�벿�ֺͺ��ֱַ�ʹ�ÿ�������
	int p = _partition(arr,l,r);
	_quicksort(arr,l,p-1);  // ǰ�벿��,
	_quicksort(arr,p+1,r);  // ��벿��,
}
template<typename T>
void quicksort(T arr[],int n)
{
	_quicksort(arr,0,n-1);
}

//#6 ��·������
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



//# 3·��������
template <typename T>
void __quickSort3Ways(T arr[], int l, int r){

 
    // �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
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

	//sortselection(arr,length(arr));  // ѡ������
	//Sortselection(arr,length(arr));  // ѡ������ ģ�廯
	//InsertSort(arr,length(arr)); // ��������
	//InsertSortAdvance(arr,length(arr));  //��������Ľ���
	//mergeSort(arr,length(arr)); // �鲢����
	//quicksort(arr,length(arr)); // ��������
    //quicksort2ways(arr,length(arr));// 2·����
	//quickSort3Ways(arr,length(arr));// 3 ·������
	for (int i =0;i<length(arr);i++)
	{
		cout<<arr[i]<<";";
		
	}
	cout<<endl;
	getchar();
	return 0;
}


