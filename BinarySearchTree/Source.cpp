#include <iostream>


template <typename Key, typename Value>
class BinaryTreeSearch{

private:
	struct Node {
	Key key;
	Value value;
	Node* left;
	Node* right
	
	};
	Node *root;
	int count;

	Node(Key key,Value value)
	{
		this->value = value;
		this->key = key;
		this->left = this->right = NULL;
	}

public:
	BinaryTreeSearch()
	{
		count = 0;
		root  = NULL;
	}
	
	~BinaryTreeSearch()
	{
		//TODO....
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

	// Insert Items in binary serach tree 
	// ���ز����½ڵ�������µĶ������ĸ��ڵ�
	void insertnode(Key key,Value value)
	{
		root = insertnode(root,key,value);
	}


	//�������в���ĳһ��key,������True ����False 
	bool contain(Key key)
	{
		return contain(root,key);
	}
	
	// �������ң��ҵ��󷵻ظýڵ��ֵ
	Value* search(Key key)
	{
		return search(root,key);
	}

	// ǰ�����;
	void preorder()
	{
		return preorder(root);
	}
	// �������
	void inerorder()
	{
		return inerorder(root);
	}
	// �������
	void afterorder()
	{
		return afterorder(root);
	}

	// Ѱ����Сֵ,����key
	Key minimum()
	{
		assert(count!=0);
		Node* node = minimum(root); // ���ﷵ�ص���һ����С��ֵ��Ӧ�Ľڵ�node
		return node->key;
	}
	
	//�ҵ����ֵ, ����key
	Key maxmum()
	{
		assert(count !=0)
	    Node* node = maxmum(root);
	    return node->key;
	}

	// ɾ������Сֵ�����ֵ��������ɾ����ĸ��ڵ�node 
	void  removemax()
	{
		if (root)
			root = removemax(root);
		
	}
	// ɾ����Сֵ
	void removemin()
	{
		if (root)
			root = removemin(root);
	}

	// ɾ��һ����ֵ
	void removeItem(Key key)
	{
		if(root)
			root = removeItem(root,key)
			
	}
private:
	Node* insertnode(Node* node,Key key,Value value) // ���ز����½ڵ�������µĶ������ĸ��ڵ�
	{
		if (node == NULL) // �ݹ鵽�׵�����
		{
			count ++;
			return new Node(key,value);	
		}
		
		if (key == node->key)    // ����Ľڵ��ֵkey ǡ�õ���
			node->value = value; // �������ֵ��ֵ���ӵ�value 
		if (key <node->key)
			node->left =  insertnode(node->left,key,value);
		else // (key> node->key)
			node->right = insertnode(node->right,key,value);
		
		return mode;
	}


	//�Ƿ����һ��key,����True or False 
	bool contain(Node* node, Key key)
	{
		if (node == NULL)
			return false;
		
		if (key == node->key)
			return true;
		else if (key< node->key) // ��������...
		{
			return contain(node->left,key);
		}
		else 
		{
			return contain(node->right,key);
		}
	}


	// �����ڵ㣬����ֵvalue 
	Value* search(Node* node,Key key)
	{
		if(node ==NULL)
			return NULL;
		
		if (node->key == key)
			return &(node->value);
		else if (key <node->key)
			return search(node->left,key,value);
		else// key >node->key 
			return = search(node->right,key,value);
		
	}

	// ǰ�����
	void preorder(Node* node)
	{
		if (node == NULL)
			return;
		
		cout<<node->key<<endl;
		preorder(node->left);
		preorder(node->right);
	}

	// �������
	void inerorder(Node* node)
	{
		if (node != NULL)
		{
			inerorder(node->left);
			cout<< node->key; // ���������ӡ
			inerorder(node->right);
		}
	}

	// �������
	void afterorder(Node* node)
	{
		if (node != NULL)
		{
			afterorder(node->left);
			afterorder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	// ���պ�������ķ�����һ���������������delete node �������
	void destory(Node* node){
	if (node != NULL)
	{
		destory(node->left);
		destory(node->right);
		count--;
		delete node;
	}
	}

	// �������
	void levelOrder()
	{
	     queue<Node*> q; 
		 q.push(root); // һ��ʼ����root ���

		 
		 while(!q.empty()) // ֻҪ������Ԫ�أ������ִ��
		 {
			 Node* node = q.front(); // ����һ���ڵ㣬����������ǰ���ֵ������ڵ�
			 q.pop(); // ������ڵ���ӣ���ͬʱcheck �ýڵ����ڵ���ҽڵ��Ƿ�Ϊ��
			 
			 if(node->left)
				 q.push(node->key); // ��ڵ㲻Ϊ��,��ֱ�����
			 if(node->right)
				 q.push(node->key);

		 }


	}

	// �ҵ���Сֵ��Ӧ�Ľڵ�
	Node* node minimum(Node* node)
	{
		if (node->left == NULL)
			return node;
		else // node->left != NULL
			return minimum(node->left);
	}

	// �ҵ����ֵ��Ӧ�Ľڵ�
	Node* node maxmum(Node* node)
	{
		if (node->right == NULL)
			return node;
		// node->right != NULL
		return maxmum(node->right);
	}

	// ɾ�����key ������ɾ����ĸ��ڵ�
	Node* removemax(Node* node)
	{
	   // ���ж��ұߵĽڵ�
	    if(node->right == NULL) // ����ұߵĽڵ�Ϊ��,��ýڵ�Ϊ���ֵ
		{
			if (node->left !=NULL) //ɾ���ýڵ��,���������ǲ���Ϊ�գ��������ӽڵ�������ڵĽڵ�;�������Ϊ�գ�Ҳû��ϵ����Ϊ���صĽڵ㻹�ǿ�
			{
				Node* newnode  = node->left;
				count--;
				delete node;
				return newnode;
			}
		}

		//  �����Ϊ�� ,���������ҽڵ�
		node->right = removemax(node->right);
		return node;
	}
		
	// ɾ����Сֵd
	Node* removemin(Node* node)
	{
		if (node->left == NULL)
		{
			//if(node->right != NULL)
				Node* newnode = node->right;
			    delete node;
				count--;
				return newnode;
		}
		node->left = removemin(node->left);
		return node;
	}


	// ɾ����ֵΪkey �Ĳ�����ɾ���������ĸ��ڵ�
	Node* removeItem(Node* node,Key key)
	{
		if(node == NULL)
			return NULL;
		
		
		if(key< node->key) // Ѱ��key: ����������KeyС�ڵ�ǰ��key�����������node����Ѱ��key������ɾ��key��Ľڵ㸳ֵ����ǰnode ������
		{
			node->left = removeItem(node->left,key);  
			return node;
		}
		else if (key> node->key)
		{
			node->right = removeItem(node->right);
			return node;
		}
		else 
		{
			
		if(node->left == NULL)
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
		else // ɾ��һ������������������������
		{
			Node* scussor =new Node(maxmum(node->right)); // ���������Ľڵ���µ�scussor
			count++;

			scussor->right =  removemin(node->right,key,value);
			scussor->left  = node->left;
			delete node;
			count--;
		    return scussor;
		}
		}



	}
};