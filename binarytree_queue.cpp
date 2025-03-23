#include <iostream>
using namespace std;
#include <queue>

class binarytree{
    private :
        struct node {
            char data;
            struct node * left,*right;
        };
    public:
        struct node * root;
        binarytree(){
            root=NULL;
        }
        void insert(char);
        void preorder(node * root);
        void inorder(node * root);
        void postorder(node * root);
        void search(node * root,char);
};

int main(){
    binarytree b1;
    char cha;
    int loop=0;
    while (loop==0){
        int ch;
        cout<<"\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter character:";
                cin>>cha;
               b1.insert(cha);
                break;
            case 2:
                cout<<"\nPreorder:";
                b1.preorder(b1.root);
                cout<<"\n";
                break;
            case 3:
                cout<<"\nInorder:";
                b1.inorder(b1.root);
                cout<<"\n";
                break;
            case 4:
                cout<<"\nPostorder:";
                b1.postorder(b1.root);
                cout<<"\n";
                break;
            case 5:
                cout<<"Enter the character to be searched:";
                cin>>cha;
                b1.search(b1.root,cha);
                break;
            case 6:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
                break;
        }
    }
}


void binarytree::insert(char cha){
    struct node * newnode=(struct node *) malloc(sizeof(struct node));
    newnode->data=cha;
    newnode->left=NULL;
    newnode->right=NULL;
    if (root==NULL){
        root=newnode;
        return;
    }

    queue <node*> q;
    q.push(root);
    while (!q.empty()){
        node * temp=q.front();
        q.pop();
        if (temp->left==NULL){
            temp->left=newnode;
            break;
        }
        else{
            q.push(temp->left);
        }
        if (temp->right==NULL){
            temp->right=newnode;
            break;
        }
        else{
            q.push(temp->right);
        }
    }

}


void binarytree::preorder(node* root){
    if (root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
    }
}


void binarytree::postorder(node * root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    else{
        return;
    }
}


void binarytree::inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    else{
        return;
    }
}

void binarytree::search(node * root,char cha){
    if (root!=NULL){
        if (root->data == cha){
            cout<<"\nElement Found\n";
            return;
        }
        search(root->left,cha);
        search(root->right,cha); 
    }
}
