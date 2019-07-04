#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <cassert>
template <typename Key,typename Value>
class BST
{
private:
	struct Node{
		Key key;
		Value value;
		Node *left; // �����ʾ�ṹ��ָ��,�����������ʽṹ���Ա����
		Node *right;

		Node (Key key,Value value)  // ͬ���ṹ�幹�캯��,������ʼ��
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		Node(*node)  // ����һ���ڵ�
		{
			this->key = key;
			this->value = value;
			this->left  = left;
			this->right = right;
		}
	};
	Node *root;  // ���ڵ���
	int count;   // �ڵ���Ŀ

public:
	BST(){
		root = NULL;
		count = 0;
	}

	~BST()
	{

		//TODO: ~BST();
		destory(root);
	}
	
	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}
	// ����һ���ڵ�(key,value)
	void insert(Key key,Value value)
	{
		root = insert(root,key,value); // ��������ĺ���,���صĽڵ�ĸ�
	}

	// �ж�һ�������ǲ��Ǻ���һ��key,����True False 
	bool contain(Key key)
	{
		return contain(root,key);
	}

    // ���Ҷ��������ǲ��Ǻ���ĳһ��key,���ﷵ��һ��ָ��
	Value *search(Key key)
	{
		return search(root,key);
	}

    // ---------------------
	// �������е� ����
	// ---------------------
	// ǰ�����
	void proOrder()
	{
		return proOrder(root);
	}

	// �������
	void InOrder()
	{
		return InOrder(root);
	}

	// �������
	void outOrder()
	{
		return outOrder(root);
	}

	//-------------
	//  ������� -- ���ǰ���ÿ���㼶�ı���
	// ============
	void levelOrder()
	{
		queue<Node*> q;��// ���� ������Node*ָ��
		q.push(root);   // �����ڵ����
	    
		while(!q.empty())  
		{
			Node *node = q.front();  // �������еĵ�һ��Ԫ�ظ�node 
			q.pop();                  // ���Ľڵ��׳�
			cout<<node->key<<endl;    // ��ӡ���ýڵ��key
			if (node->left) // �� �ڵ��׳���ͬʱ,��֤��ߵĽڵ��ǲ�����Ч����Ч����ߵĽڵ������
				q.push(node->left);
			if (node->right)  // �� �ڵ��׳���ͬʱ,��֤�ұߵĽڵ��ǲ�����Ч����Ч���ұߵĽڵ������
				q.push(node->right);

		}
	}

	// Ѱ���ڶ�������Ѱ����С���ֵ
	Key minimum()
	{
		assert(count !=0)
		Node* mininode = minimum(root); // ����һ���ڵ�
		return mininode->key;
	}

	// Ѱ�Ҷ����������ֵ
	Key maxmum()
	{
		assert(count !=0);
		Node *maxnode = maxmum(root);
		return maxnode;
	}


	// ɾ�����ֵ����ɾ����Сֵ�ڵ�
	void removemin() // ɾ����Сֵ
	{
		if (root)
		{
		   root = removemin(root);
		}
		
	}

	// ɾ�����ֵ�ڵ�
	void removemax()
	{
		if (root)
		{
			root = removemax(root);
		}
	}


	// remove ��һ����ֵΪkey �Ľڵ�
	Node* removenode(Key key)
	{
		root = removenode(root,key)
	}

private:
	// ����node Ϊ���Ķ����������в���ڵ�(key value)ֵ�����ҷ��ز����½ڵ�Ԫ�غ���µĶ������ĸ�root�ڵ�
	// 
	Node *insert(Node *node,Key key,Value value)
	{
		if (node == NULL) // �������ĸ��ڵ�node Ϊ�գ�������newһ���ڵ�Node(key,value)
		{
			count++;
			return new Node(key,value);
		}

		if (key == node->key)    // ������������Ѿ��в���Ľڵ㣬��ֱ�ӽ��µ�ֵ��ֵ�����еĽڵ�
			node->value = value;
		else if (key< node->key) // ��������ֵ�����еĽڵ�С������������
			node->left = insert(node->left, key,value);
		else // key> node->key
			node->right = insert(node->right,key,value);
		
		return node; // �����µĽڵ�
		
	}

	// ��node Ϊ���ڵ�Ķ������в����Ƿ���ĳһ��key
	bool contain (Node *node ,Key key)
	{
		if (node == NULL) // �ݹ鵽�׵����
			return false;
		
		if (node->key == key)
			return true; 
		else if (key < node->key)
			return contain(node->left,key);
		else // key > node->key
			return contain(node->right,key);
	}

	// ��node Ϊ���ڵ�Ķ������в���key����Ӧ��value,���ص���ֵ
	Value *search(Node*node,Key key) //
	{

		if (node == NULL)
			return NULL;
		if (node->key == key)
			return &(node->value)  // ���ص�ַ
		else if (node->key<key)
		    return search(node->right,key);
		else // node->key >key 
			return search(node->left,key);
		
	}

	// ��nodeΪ�ڵ�Ķ���������ǰ�����,�ݹ��㷨
	void proOrder(Node *node)
	{
		if (node != NULL)
		{
		   cout<<node->key<<endl;
		   proOrder(node->left);
		   proOrder(node->right);
		}

	}

	// ����node Ϊ�ڵ�Ķ������Ͻ�����������,�ݹ��㷨
	void InOrder(Node *node)
	{
		if (node != NULL)
		{
			InOrder(node->left);
			cout<<node->key;
			InOrder(node->right);
		}
	}

	// ����node Ϊ�ڵ�Ķ������Ͻ��к�������,�ݹ��㷨
	void outOrder(Node *node)
	{
		if (node !=NULL)
		{
			outOrder(node->left);
			outOrder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	// ���ձ����ķ���destory �����нڵ���Ϊ�������
	void destory(Node *node)
	{
		if (node !=NULL)
		{
			destory(node->left);
			destory(node->right);
			count --;
			delete node;
		}
	}

	//Ѱ����Сֵ�Ľڵ�
	Node* minimum(Node* node) // ������ߵ���������Сֵ,ֱ���ڵ�Ϊ�գ���ýڵ�Ϊ��Сֵ�ڵ�
	{
		if (node->left == NULL)
			return node;
			
        return minimum(node->left);
	}
	
	// Ѱ�����ֵ�Ľڵ�
	Node* maxmum(Node* node)
		{
			if (node->right == NULL)
				return node;

			// node->rigth !=NULL
			return maxmum(node->right);
	}

	// ɾ����Сֵ
	// ɾ����nodeΪ���ڵ�Ķ���������Сֵ,������ɾ�����µĸ��ڵ�
	Node* removemin(Node*node)
	{
		if (node->left == NULL) // ����Ϊ�գ���ǰ�ڵ������Сֵ
		{
			// ���ұߵĽڵ���浱ǰ�ڵ㣬��Ϊ�µĽڵ�
	        Node* newnode = node->right; // 
		    delete node;
		    coun --;
		    return newnode;
		}

		// �����ߵĽڵ㲻Ϊ��,������ݹ�ֱ���ҵ���ڵ�Ϊ�յ�Ϊ���ֵ
		node->left  = removemin(node->left);
		return node;
	}

	// ɾ�����ֵ
	Node* removemax(Node *node)
	{
		if (node->right == NULL)
		{
            Node* newnode =  node->left;
		    delete node;
			count --;
		    return newnode;
		}
	    
		node->right = removemax(node->right);
		return node;		
	}


	// ����node Ϊ���Ķ�����remove��Ϊkey�Ľڵ�
	Node* removenode(Node* node,Key key)
	{
		if (node  == NULL)
			return NULL;
		if (key <node->key)
			node->left = removenode(node->left,key);
		    return node;
		else if (key>node->key)
		{
			node->right = removenode(node->right,key);
			return node 
		}
		else // key == node->key
		{
			if (node->left == NULL) // �����߽ڵ�Ϊ�գ����������Ľڵ����ȥ
			{
				Node* newnode = node->right;
				count--;
				delete node;
			    
				return newnode;
				
			}
			else if (node->right == NULL)
			{
				Node* newnode = node->left;
				count--;
				delete node;
				return newnode;
			}
			else // node->left != NULL && node->rigth !=NULL
			{
				/// ��node ����������Сֵ�Żظ�һ���µĽڵ�successor 
				Node* successor  = new Node(minimum(node->right)); 
				count ++;
				
				successor->right = removemin(node->right);  // ������������Сֵȥ������ȥ����Сֵ��ĸ��ڵ㷵��
				successor->left  = node->left;
				delete node;
				count--;
				return successor;
			}
			
			// ����Ĳ���ʱȡ����������Сֵ���滻Ҫɾ���Ľڵ㡣����������ȡ�����������ֵ���滻Ҫɾ���Ľڵ�
			/*Node* pucco = new Node(maxmum(node->left));
			count++;
			
			pucco->left = removemax(node->left);
			pucco->right = node->right;
			delete node;
			count--;
			return pucco;*/
			   

		}
			
	}

};

int main()
{
	return 0;
}