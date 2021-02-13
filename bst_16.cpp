void find_node(Node* root,int &nodes)
{
    if(root==NULL)
    {
        return;
    }
    find_node(root->left,nodes);
    nodes++;
    find_node(root->right,nodes);
}

int find_o(Node *root,int &cnt, int k) 
{
    if(root==NULL)
    {
        return -1;
    }
    int ans=find_o(root->left,cnt,k);
    if(ans!=-1)
    {
        return ans;
    }
    cnt++;
    if(cnt==k)
    {
        return root->data;
    }
    return find_o(root->right,cnt,k);
}



float findMedian(struct Node *root)
{
      int nodes=0;
      find_node(root,nodes);
      if(nodes%2!=0)
      {
          int cnt=0;
          return find_o(root,cnt,nodes/2+1);
      }
      else
      {
          int cnt1=0;
          int cnt2=0;
          int a=find_o(root,cnt1,nodes/2+1);
          int b=find_o(root,cnt2,nodes/2);
          return (a+b)/2.0;
      }
}

