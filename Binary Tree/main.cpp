#include <iostream>
#include <queue>

using namespace std;
template <class type >
class BSTFCI{
    struct node{
        type value ;
        node *right ;
        node *left ;
        node * parent ;
    };
    public:
    node *root = NULL ;


        void insert(type x ){
            if(root == NULL){
                root = new node ;
                root->value = x;
                root->left = NULL ;
                root->right = NULL ;
            }else{
                node *current = new node ;
                node *newnode = new node ;
                current = root ;
                while(true){
                    if(x > current->value){
                        if(current->right == NULL){
                            newnode->value = x ;
                            newnode->left = NULL ;
                            newnode->right = NULL ;
                            current->right = newnode ;
                            return ;
                        }
                        current = current->right ;
                    }
                    if(x < current->value){
                        if(current->left == NULL){
                            newnode->value = x ;
                            newnode->left = NULL ;
                            newnode->right = NULL ;
                            current->left = newnode ;
                            return;
                        }
                        current = current->left;
                    }
                    if(x == current->value){            // repetition case
                        cout << " You tried to enter an exciting element (" << x << ")  !!" << endl;
                        return ;

                    }
                }
            }
        }
        node *begin(){
            return root ;
        }
        void preOrder( node* newroot){
            if(newroot != NULL){
                cout << newroot->value << " " ;
                preOrder(newroot->left);
                preOrder(newroot->right);
            }
        }
        void postOrder( node* newroot){
            if(newroot != NULL){
                postOrder(newroot->left);
                postOrder(newroot->right);
                cout << newroot->value << " " ;
            }
        }
        void inOrder( node* newroot){
            if(newroot != NULL){
                inOrder(newroot->left);
                cout << newroot->value << " " ;
                inOrder(newroot->right);
            }
        }
        void levelOrder(node* newroot){
            queue<node*> myqueue ;
            myqueue.push(newroot);
            while(myqueue.size() != 0){
                cout << myqueue.front()->value << " " ;
                if(myqueue.front()->left != NULL)
                    myqueue.push(myqueue.front()->left);
                if(myqueue.front()->right != NULL)
                    myqueue.push(myqueue.front()->right);
                myqueue.pop();
            }
        }

    void left_rotate(node * rotated){
        if(rotated == root){
            root = rotated->right  ;
        }
        node * rotatedR = rotated->right ;
        rotated->right = rotatedR->left;
        rotatedR->parent = rotated->parent;
        rotatedR->left = rotated;
        rotated->parent = rotatedR;

    }
    void right_rotate(node * rotated){
        if(rotated == root){
            root = rotated->left ;
        }
        node * rotatedL = rotated->left ;
        rotated->left = rotatedL->right ;
        rotatedL->parent = rotated ->parent ;
        rotatedL->right = rotated ;
        rotated->parent = rotatedL ;
    }

};

int main()
{
    BSTFCI<int> tree ;
    tree.insert(15);
    tree.insert(17);
    tree.insert(5);
    tree.insert(4);
    tree.insert(12);
    tree.insert(16);
    tree.insert(21);

    tree.preOrder(tree.begin());
    cout << endl;
    tree.postOrder(tree.begin());
    cout << endl;
    tree.inOrder(tree.begin());
    cout << endl;
    tree.levelOrder(tree.begin());
    tree.right_rotate(tree.begin());
    cout << endl;
    tree.levelOrder(tree.begin());

    return 0;
}
