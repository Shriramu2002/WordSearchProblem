#include<bits/stdc++.h>
using namespace std;
int nooflink=0;
struct node{
    int data;
    char ch;
    struct node *left;
    struct node *right;
     struct node *up;
     struct node *down;
     struct node *upleft;
     struct node *upright;
     struct node *downleft;
     struct node *downright;
};
struct node* insert(string str,node *head)
{
    
     int n=0,i=0;
    while(str[i]!='\0')
    {
       n++;

       i++;
    }
    for(int i=0;i<n;i++)
    {
       node *ne=new node;
       ne->ch=str[i];
       ne->left=NULL;
        ne->right=NULL;
         ne->up=NULL;
          ne->down=NULL;
           ne->upright=NULL;
            ne->upleft=NULL;
             ne->downleft=NULL;
              ne->downright=NULL;
              if(head==NULL)
              head=ne;
              else 
              {
                  node *t=head;
                  while(t->right!=NULL)
                  {
                      t=t->right;
                  }
                  t->right=ne;
              }
              
        
    }
    return head;
}
struct node *linking(node *r1,node *r2)
{
  
    node *e=r1;
  for(int i=0;i<nooflink-1;i++)
  {
      r1=r1->down;
}
  
    while(r1!=NULL)
    {
        r1->down=r2;
        r2->up=r1;
        // node *p= r1->right;
    r1->right->left=r1;
         r1->downleft=r2->left;
         if(r2->left!=NULL)
         r2->left->upright=r1;
         
        if(r1->right!=NULL)
        {
        r1->upright=r1->right->up;
        if(r1->right->up!=NULL)
        r1->right->up->downleft = r1;
        
              
           }
        if(r2->right!=NULL){
         r1->downright=r2->right;
        r2->right->upleft=r1;
        }
       // if(r1->left!=NULL)
        // {

         //    r1->upleft=r1->left->up;
       //  }
        
        r1=r1->right;
        r2=r2->right;
    }

return e;
}
int main()
{
    node *root=NULL;
    node *root1=insert("abc",root);
   
    node *root2=insert("def",root);
    node *root3=insert("xyz",root);
   
    node *root4=linking(root1,root2);
   nooflink+=2;
   node *root5=linking(root4,root3);
    while(root5->down!=NULL)
    {
     //cout<<root5->ch;
      root5=root5->down;
    }
    while(root5!=NULL)
    {
     cout<<root5->ch;
      root5=root5->upright;
    }   
    //cout<<root5->ch;
    //root5=root5->down;
    //while(root5->left!=NULL)
    //{
//cout<<root5->ch;
//root5=root5->left;
   // }
   
    
}