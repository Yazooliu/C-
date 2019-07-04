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
		Node *left; // 这里表示结构体指针,可以用来访问结构体成员变量
		Node *right;

		Node (Key key,Value value)  // 同名结构体构造函数,变量初始化
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

		Node(*node)  // 备份一个节点
		{
			this->key = key;
			this->value = value;
			this->left  = left;
			this->right = right;
		}
	};
	Node *root;  // 根节点数
	int count;   // 节点数目

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
	// 插入一个节点(key,value)
	void insert(Key key,Value value)
	{
		root = insert(root,key,value); // 调用下面的函数,返回的节点的根
	}

	// 判断一个函数是不是含有一个key,返回True False 
	bool contain(Key key)
	{
		return contain(root,key);
	}

    // 查找二叉树中是不是含有某一个key,这里返回一个指针
	Value *search(Key key)
	{
		return search(root,key);
	}

    // ---------------------
	// 二叉树中的 遍历
	// ---------------------
	// 前序遍历
	void proOrder()
	{
		return proOrder(root);
	}

	// 中序遍历
	void InOrder()
	{
		return InOrder(root);
	}

	// 后序遍历
	void outOrder()
	{
		return outOrder(root);
	}

	//-------------
	//  层序遍历 -- 就是按照每个层级的遍历
	// ============
	void levelOrder()
	{
		queue<Node*> q;　// 队列 里面存的Node*指针
		q.push(root);   // 将根节点进队
	    
		while(!q.empty())  
		{
			Node *node = q.front();  // 将队列中的第一个元素给node 
			q.pop();                  // 将改节点抛出
			cout<<node->key<<endl;    // 打印出该节点的key
			if (node->left) // 将 节点抛出的同时,验证左边的节点是不是有效，有效则将左边的节点进队列
				q.push(node->left);
			if (node->right)  // 将 节点抛出的同时,验证右边的节点是不是有效，有效则将右边的节点进队列
				q.push(node->right);

		}
	}

	// 寻找在二叉树中寻找最小最大值
	Key minimum()
	{
		assert(count !=0)
		Node* mininode = minimum(root); // 返回一个节点
		return mininode->key;
	}

	// 寻找二叉树中最大值
	Key maxmum()
	{
		assert(count !=0);
		Node *maxnode = maxmum(root);
		return maxnode;
	}


	// 删除最大值节与删除最小值节点
	void removemin() // 删除最小值
	{
		if (root)
		{
		   root = removemin(root);
		}
		
	}

	// 删除最大值节点
	void removemax()
	{
		if (root)
		{
			root = removemax(root);
		}
	}


	// remove 掉一个键值为key 的节点
	Node* removenode(Key key)
	{
		root = removenode(root,key)
	}

private:
	// 在以node 为根的二叉搜索树中插入节点(key value)值，并且返回插入新节点元素后的新的二叉树的根root节点
	// 
	Node *insert(Node *node,Key key,Value value)
	{
		if (node == NULL) // 如果插入的根节点node 为空，则重新new一个节点Node(key,value)
		{
			count++;
			return new Node(key,value);
		}

		if (key == node->key)    // 如果现有树中已经有插入的节点，则直接将新的值赋值给现有的节点
			node->value = value;
		else if (key< node->key) // 如果插入的值比现有的节点小，则插入在左边
			node->left = insert(node->left, key,value);
		else // key> node->key
			node->right = insert(node->right,key,value);
		
		return node; // 返回新的节点
		
	}

	// 在node 为根节点的二叉树中查找是否含有某一个key
	bool contain (Node *node ,Key key)
	{
		if (node == NULL) // 递归到底的情况
			return false;
		
		if (node->key == key)
			return true; 
		else if (key < node->key)
			return contain(node->left,key);
		else // key > node->key
			return contain(node->right,key);
	}

	// 在node 为根节点的二叉树中查找key所对应的value,返回的是值
	Value *search(Node*node,Key key) //
	{

		if (node == NULL)
			return NULL;
		if (node->key == key)
			return &(node->value)  // 返回地址
		else if (node->key<key)
		    return search(node->right,key);
		else // node->key >key 
			return search(node->left,key);
		
	}

	// 以node为节点的二叉树进行前序遍历,递归算法
	void proOrder(Node *node)
	{
		if (node != NULL)
		{
		   cout<<node->key<<endl;
		   proOrder(node->left);
		   proOrder(node->right);
		}

	}

	// 在以node 为节点的二叉树上进行中序排序,递归算法
	void InOrder(Node *node)
	{
		if (node != NULL)
		{
			InOrder(node->left);
			cout<<node->key;
			InOrder(node->right);
		}
	}

	// 在以node 为节点的二叉树上进行后续排序,递归算法
	void outOrder(Node *node)
	{
		if (node !=NULL)
		{
			outOrder(node->left);
			outOrder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	// 按照遍历的方法destory 掉所有节点作为完成析构
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

	//寻找最小值的节点
	Node* minimum(Node* node) // 沿着左边的树查找最小值,直到节点为空，这该节点为最小值节点
	{
		if (node->left == NULL)
			return node;
			
        return minimum(node->left);
	}
	
	// 寻找最大值的节点
	Node* maxmum(Node* node)
		{
			if (node->right == NULL)
				return node;

			// node->rigth !=NULL
			return maxmum(node->right);
	}

	// 删除最小值
	// 删除以node为根节点的二叉树的最小值,并返回删除后新的根节点
	Node* removemin(Node*node)
	{
		if (node->left == NULL) // 左孩子为空，则当前节点就是最小值
		{
			// 将右边的节点代替当前节点，作为新的节点
	        Node* newnode = node->right; // 
		    delete node;
		    coun --;
		    return newnode;
		}

		// 如果左边的节点不为空,则继续递归直到找到左节点为空的为最大值
		node->left  = removemin(node->left);
		return node;
	}

	// 删除最大值
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


	// 在以node 为根的二叉树remove键为key的节点
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
			if (node->left == NULL) // 如果左边节点为空，则将右子树的节点接上去
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
				/// 将node 右子树的最小值放回给一个新的节点successor 
				Node* successor  = new Node(minimum(node->right)); 
				count ++;
				
				successor->right = removemin(node->right);  // 将右子树的最小值去掉并把去掉最小值后的根节点返回
				successor->left  = node->left;
				delete node;
				count--;
				return successor;
			}
			
			// 上面的操作时取右子树的最小值来替换要删除的节点。下面做饭是取左子树的最大值来替换要删除的节点
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