#include<iostream>
using namespace std;
struct tree{
    char a;
    tree *lchild;
    tree *rchild;
};
int i=0;
void preorder(tree *p,string a,string b,int x,int y)
{
    if(i<b.length())
    {
        p->a=a[i];
        p->lchild=new tree;
        p->rchild=new tree;
        int u=i;
        if(b.find(a[i])-1!=x)
        {
            preorder(p->lchild,a,b,x,b.find(a[i++]));
        }    
        else
        {
        p->lchild=NULL;
        }
        
        if(b.find(a[u])+1!=y)
        {
                i++;
            preorder(p->rchild,a,b,b.find(a[u]),y);        
        }
        else
        {
        p->rchild=NULL;
        }
    }    
}
void postorder(tree *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);                
        postorder(p->rchild);    
        cout<<p->a;
    }                    
}
int main()
{
    string a,b,c;
    cin>>a>>b;
    tree *p=new tree;
    p->lchild=NULL;
    p->rchild=NULL;
    int y=b.length(),x=-1;
    preorder(p,a,b,x,y);
    postorder(p);
    return 0;
}

