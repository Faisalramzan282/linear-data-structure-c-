// #include <iostream>
// #include<unordered_map>
// #include<queue>
// using namespace std;
// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     int height;
//     Node(int value){
//     data = value;
//     }
// };
// class AVL{
//   public:
//    Node* root;
//    AVL(){
//     root = nullptr;
//    }
//    int calHeight(Node* current){
//      if(current->left && current->right){
//         if(current->left && current->right==NULL){
//             return current->left->height+1;
//         }
//         else{
//             return current->right->height+1;
//         }
//      }
//      else if(current->left && current->right == NULL){
//         return current->left->height+1;
//      }
//      else if(current->right  && current->left == NULL){
//         return current->right->height+1;
//      }
//      return 0; //means they have no child so return 0;
//    }
//    int balanceFactor(Node* current){
//      if(current->left && current->right){
//         return current->left->height-current->right->height;
//      }else if(current->left  && current->right==NULL){
//         return current->left->height;
//      }else if(current->right && current->left == NULL){
//        return -current->right->height;
//      }
//      return 0;//means the have not children
//    }
//    Node* llRotation(Node *current){
//      Node *parent;
//      Node * temParent;
//      parent = current;
//      temParent = parent->left;
//      parent->left = temParent->right;
//      temParent->right = parent;
//      return temParent;
//    } 
//    Node* rrRotation(Node *current){
//      Node* parent;
//      Node* temParent;
//      parent = current;
//      temParent = parent->right;
//      parent->right = temParent->left;
//      parent= temParent->left;
//      return temParent;
//    }
//    Node* rlRotation(Node* current){
//      Node* parent;
//      Node* temParent1;
//      Node* temParent2;
//      parent = current;
//      temParent1 = current->right;
//      parent->right = temParent2->left;
//      temParent1->left = temParent2->right;
//      temParent2->left = parent ;
//      temParent2->right = temParent1;
//      return temParent2;
//    }
//    Node* lrRotation(Node* current){
//     Node* parent ;
//     Node* temParent1;
//     Node* temParent2;
//     parent = current;
//     temParent1 = parent->left;
//     temParent2 = parent->left->right;
//     temParent1->right = temParent2->left;
//     parent->left = temParent2->right;
//     temParent2->left = temParent1;
//     temParent2->right = parent;
//     return temParent2;
//    }
//    Node* insert(Node* current, int value){
//     if(current==NULL){
//       Node* newNode = new Node(value);
//       newNode->left = newNode->right = NULL;
//       newNode->height =1;
//       return newNode;
//     }else{
//       if(value < current->data){
//         current->left = insert(current->left, value);
//       }
//       else{
//         current->right = insert(current->right , value);
//       }
//     }
//     current->height = calHeight(current);
//     if(balanceFactor(current)==2 && balanceFactor(current->left)==1){
//       current = llRotation(current);
//     }
//     else if(balanceFactor(current)==-2 && balanceFactor(current->left)==-1){
//       current = rrRotation(current);
//     }
//     else if(balanceFactor(current)==2 && balanceFactor(current->left)==-1){
//       current = lrRotation(current);
//     }
//     else if(balanceFactor(current)==-2 && balanceFactor(current->right)==1){
//      current = rlRotation(current);
//     }
//     return current;
//    }
//   void levelorder_newline(){
//         if (this->root == NULL){
//             cout<<"\n"<<"Empty tree"<<"\n";
//             return;            
//         }
//         levelorder_newline(root);
//     }
//     void levelorder_newline(Node *v){
//         queue <Node *> q; //for queue operations
//         Node *cur; 
//         q.push(v);
//         q.push(NULL);
//         while(!q.empty()){
//             cur = q.front();
//             q.pop();
//             if(cur == NULL && q.size()!=0){
//                 cout<<"\n";
//                 q.push(NULL);
//                 // continue;
//             }
//             if(cur!=NULL){
//                 cout<<" "<<cur->data;

//                 if (cur->left!=NULL){
//                 q.push(cur->left);
//                 }
//                 if (cur->right!=NULL){
//                     q.push(cur->right);
//                 }
//             }
//         }
//     }
// };
// int main(){
//   AVL obj;
//   int userInput, insertVal;
//   do{
//    std::cout<<"\n1-To see the level-Order"<<std::endl;
//    std::cout<<"2-To insert it "<<std::endl;
//    std::cout<<"0-For Exit"<<std::endl;
//    std::cout<<"\nEnter Choices\n"<<std::endl;
//    cin>>userInput;
//    switch (userInput)
//    {
//    case 1:
//     obj.levelorder_newline();
//     break;
//    case 2:
//     std::cout<<"Enter inserted value"<<std::endl;
//     std::cin>>insertVal;
//     obj.root = obj.insert(obj.root, insertVal);
//     break;
//    case 0:
//     break;
//   }
//   }while(userInput!=0);
//   return 0;
// }
//=====================================================
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct node {
    struct node *left;
    int data;
    int height;
    struct node *right;

};

class AVL
{
private:
    
public:
    struct node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(struct node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    struct node * llrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp; 
    }


    struct node * rrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp; 
    }


    struct node * rlrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        
        return tp2; 
    }

    struct node * lrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        
        return tp2; 
    }

    struct node* insert(struct node *r,int data){
        
        if(r==NULL){
            struct node *n;
            n = new struct node;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1; 
            return r;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;            
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline(struct node *v){
        queue <struct node *> q;
        struct node *cur;
        q.push(v);
        q.push(NULL);      

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
                cout<<"\n";
                
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" "<<cur->data;

                if (cur->left!=NULL){
                q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            
            
        }
    }
 
    struct node * deleteNode(struct node *p,int data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct node *t;
        struct node *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data > data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }                  
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

        
        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }

    ~AVL(){

    }
};


int main(){

    AVL b;
    int c,x;

    do{
        cout<<"\n1.Display levelorder on newline";
        cout<<"\n2.Insert";
        cout<<"\n3.Delete\n";
        cout<<"\n0.Exit\n";
        cout<<"\nChoice: ";

        cin>>c;

        switch (c)
        {
        case 1:
            b.levelorder_newline();
            // to print the tree in level order
            break;
                  
        case 2:
            cout<<"\nEnter no. ";
            cin>>x;
            b.root = b.insert(b.root,x);
            break;
        
        case 3:
            cout<<"\nWhat to delete? ";
            cin>>x;
            b.root = b.deleteNode(b.root,x);
            break;
            
        case 0:
            break;
        }

     } while(c!=0);
  
}