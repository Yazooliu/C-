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
	// 返回插入新节点后整个新的二叉树的根节点
	void insertnode(Key key,Value value)
	{
		root = insertnode(root,key,value);
	}


	//二叉树中查找某一个key,并返回True 或者False 
	bool contain(Key key)
	{
		return contain(root,key);
	}
	
	// 搜索查找，找到后返回该节点的值
	Value* search(Key key)
	{
		return search(root,key);
	}

	// 前序遍历;
	void preorder()
	{
		return preorder(root);
	}
	// 中序遍历
	void inerorder()
	{
		return inerorder(root);
	}
	// 后序遍历
	void afterorder()
	{
		return afterorder(root);
	}

	// 寻找最小值,返回key
	Key minimum()
	{
		assert(count!=0);
		Node* node = minimum(root); // 这里返回的是一个最小键值对应的节点node
		return node->key;
	}
	
	//找到最大值, 返回key
	Key maxmum()
	{
		assert(count !=0)
	    Node* node = maxmum(root);
	    return node->key;
	}

	// 删除掉最小值，最大值，并返回删除后的根节点node 
	void  removemax()
	{
		if (root)
			root = removemax(root);
		
	}
	// 删除最小值
	void removemin()
	{
		if (root)
			root = removemin(root);
	}

	// 删除一个键值
	void removeItem(Key key)
	{
		if(root)
			root = removeItem(root,key)
			
	}
private:
	Node* insertnode(Node* node,Key key,Value value) // 返回插入新节点后整个新的二叉树的根节点
	{
		if (node == NULL) // 递归到底的做法
		{
			count ++;
			return new Node(key,value);	
		}
		
		if (key == node->key)    // 插入的节点键值key 恰好等于
			node->value = value; // 将插入的值赋值给加点value 
		if (key <node->key)
			node->left =  insertnode(node->left,key,value);
		else // (key> node->key)
			node->right = insertnode(node->right,key,value);
		
		return mode;
	}


	//是否包含一个key,返回True or False 
	bool contain(Node* node, Key key)
	{
		if (node == NULL)
			return false;
		
		if (key == node->key)
			return true;
		else if (key< node->key) // 左子树中...
		{
			return contain(node->left,key);
		}
		else 
		{
			return contain(node->right,key);
		}
	}


	// 搜索节点，返回值value 
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

	// 前序遍历
	void preorder(Node* node)
	{
		if (node == NULL)
			return;
		
		cout<<node->key<<endl;
		preorder(node->left);
		preorder(node->right);
	}

	// 中序遍历
	void inerorder(Node* node)
	{
		if (node != NULL)
		{
			inerorder(node->left);
			cout<< node->key; // 中序遍历打印
			inerorder(node->right);
		}
	}

	// 后序遍历
	void afterorder(Node* node)
	{
		if (node != NULL)
		{
			afterorder(node->left);
			afterorder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	// 按照后序遍历的方法做一个析构方法，最后delete node 放在最后
	void destory(Node* node){
	if (node != NULL)
	{
		destory(node->left);
		destory(node->right);
		count--;
		delete node;
	}
	}

	// 层序遍历
	void levelOrder()
	{
	     queue<Node*> q; 
		 q.push(root); // 一开始先让root 入队

		 
		 while(!q.empty()) // 只要队中有元素，则继续执行
		 {
			 Node* node = q.front(); // 声明一个节点，并将队列最前面的值给这个节点
			 q.pop(); // 将这个节点出队，并同时check 该节点的左节点和右节点是否为空
			 
			 if(node->left)
				 q.push(node->key); // 左节点不为空,则直接入队
			 if(node->right)
				 q.push(node->key);

		 }


	}

	// 找到最小值对应的节点
	Node* node minimum(Node* node)
	{
		if (node->left == NULL)
			return node;
		else // node->left != NULL
			return minimum(node->left);
	}

	// 找到最大值对应的节点
	Node* node maxmum(Node* node)
	{
		if (node->right == NULL)
			return node;
		// node->right != NULL
		return maxmum(node->right);
	}

	// 删除最大key 并返回删除后的根节点
	Node* removemax(Node* node)
	{
	   // 先判断右边的节点
	    if(node->right == NULL) // 如果右边的节点为空,则该节点为最大值
		{
			if (node->left !=NULL) //删除该节点后,看看左孩子是不是为空，并有左孩子节点代替现在的节点;如果左孩子为空，也没关系，因为返回的节点还是空
			{
				Node* newnode  = node->left;
				count--;
				delete node;
				return newnode;
			}
		}

		//  如果不为空 ,继续返回右节点
		node->right = removemax(node->right);
		return node;
	}
		
	// 删除最小值d
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


	// 删除键值为key 的并返回删除二叉树的根节点
	Node* removeItem(Node* node,Key key)
	{
		if(node == NULL)
			return NULL;
		
		
		if(key< node->key) // 寻找key: 如果在输入的Key小于当前的key，则继续沿着node左孩子寻找key，并把删除key后的节点赋值给当前node 的左孩子
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
		else // 删除一个既有右子树，又有左子树
		{
			Node* scussor =new Node(maxmum(node->right)); // 将右子树的节点给新的scussor
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