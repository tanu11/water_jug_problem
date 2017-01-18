#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef unsigned long long ullint;

/*inline void Scan_f(int a)
   {
  char c = 0;
  while(c<33)
  //c = fgetc_unlocked(stdin);
  c = getc(stdin);
 a  = 0;
 while(c>33)
 {
 a = a*10 + c - '0';
 //c = fgetc_unlocked(stdin);
 c = getc(stdin);
 }*/
 struct Pair
 {
 	int x;
 	int y;
 };
int main()
{
  int cap1,cap2,l;
 cout<<"Enter the capacities of 2 jug :";
 cin>>cap1;
 cin>>cap2;
  cout<<"Enter the quantity you want to make :";
 cin>>l;
 
  Pair a;
  bool flag=false;
  a.x=0;a.y=0;
  queue< Pair > q;
  q.push(a);
   map< pair<int,int>,bool > visited;
   map<pair<int,int>,pair<int,int> > parent;
  
  while(q.empty()!=true)
  {  
    
    a=q.front();
    q.pop();
    
    if(a.x==l||a.y==l)
   { flag=true;
     break;
   }
    
      Pair b;
	
	  if(a.x<cap1)
        {   
        b.x=cap1;
        b.y=a.y;
          if(!visited[make_pair(b.x,b.y)])
          { q.push(b);  
          
		    parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
		      //cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
		  
		        }	
		        
		        
		}
		
		if(a.y<cap2)
		{ 
		 b.x=a.x;
        b.y=cap2;
            if(!visited[make_pair(b.x,b.y)])
           {q.push(b); parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
		   
//		       cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
		   }
			
		}
		if(a.x>0)
		{
			b.x=0;
			b.y=a.y;
		  if(!visited[make_pair(b.x,b.y)])
           {q.push(b); parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
//		      cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
		   }
			
		}
			if(a.y>0)
		{
			b.x=a.x;
			b.y=0;
		  if(!visited[make_pair(b.x,b.y)])
            {q.push(b); parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
			     // cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
			}
			
		}
		
		if(a.y>0 &&a.x<cap1)
		{   
		int x=min(a.x+a.y,cap1);
		    int y=max(0,a.y+a.x-cap1);
		    b.x=x;
		    b.y=y;
			
	  if(!visited[make_pair(b.x,b.y)])
             {q.push(b); parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
			      //cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
			 }
		}
			if(a.x>0&&a.y<cap2)
		{   
		int y=min(a.x+a.y,cap2);
		    int x=max(0,a.y+a.x-cap2);
		b.x=x;
		    b.y=y;
		    
		  if(!visited[make_pair(b.x,b.y)])
            {q.push(b); parent[make_pair(b.x,b.y)]=make_pair(a.x,a.y);
			
			    //  cout<<b.x<<b.y<<"("<<a.x<<a.y<<" )"<<"-> ";
			}
		}
		
		
    
   visited[make_pair(a.x,a.y)]=true;
    
	}
	
	if(flag==true)
	cout<<"The required quantity can be made \n";
	else
	cout<<"we are sorry, this quantity cannot be made using the given jugs\n";
	stack<Pair> st;
  	
  	while(parent[make_pair(a.x,a.y)]!=make_pair(0,0) && flag)
  	{  
  	  st.push(a);
  	  Pair temp;
  	  temp.x=parent[make_pair(a.x,a.y)].first;
  	  temp.y=parent[make_pair(a.x,a.y)].second;
  		a=temp;
  	
  		
  		
	  }
	  st.push(a);
	  st.push({0,0});
	  int i=0;
	  while(!st.empty() && flag)
	  { a=st.top();
	   st.pop();
	   cout<<i<<". ( "<<a.x<<" "<<a.y<<" )";
	   ;
	   cout<<"\n";i++;
	  }
   if(flag)
   cout<<"Total steps required ="<<i;
  	
  
    





return 0;}

