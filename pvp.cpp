#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long u64;
class cboard
{
  private :
  u64 WKnights;
  u64 WPawns ;
  u64 WRooks ;
  u64 WBishops;
  u64 WKing;
  u64 WQueen;
  u64 BKnights;
  u64 BPawns ;
  u64 BRooks ;
  u64 BBishops;
  u64 BKing;
  u64 BQueen;
  u64 wboard;
  u64 bboard;
  u64 tboard;
  u64 pieces[64];
  public :
  	cboard()
  	{            
  	
  	//NOTE: We could also create different values for every piece to make it simple while printing the board
  		WKnights  =4755801206503243776;//0100001000000000000000000000000000000000000000000000000000000000
                WPawns    =71776119061217280;  //0000000011111111000000000000000000000000000000000000000000000000
  		WRooks    =9295429630892703744;//1000000100000000000000000000000000000000000000000000000000000000
  		WBishops  =2594073385365405696;//0010010000000000000000000000000000000000000000000000000000000000
  		WKing     =576460752303423488; //0000100000000000000000000000000000000000000000000000000000000000
  		WQueen    =1152921504606846976;//0001000000000000000000000000000000000000000000000000000000000000
  		BKnights  =66;                 //0000000000000000000000000000000000000000000000000000000001000010
  		BPawns    =65280;              //0000000000000000000000000000000000000000000000001111111100000000
  		BRooks    =129;                //0000000000000000000000000000000000000000000000000000000010000001
  		BBishops  =36;                 //0000000000000000000000000000000000000000000000000000000000100100
  		BKing     =8;                  //0000000000000000000000000000000000000000000000000000000000001000
  		BQueen    =16;                 //0000000000000000000000000000000000000000000000000000000000010000
		int i ;
		u64 x;
		for(i=0;i<64;i++)
		{	
	        x=pow(2,i);
		pieces[63-i]=  x;  // Each index has a bitboard for piece (ie) a1 ,b1 , c1 and so on 
	        }
	}	
	 total_board()
	{
		
		wboard=WKnights|WPawns|WRooks|WBishops|WKing|WQueen;
		bboard=BKnights|BPawns|BRooks|BBishops|BKing|BQueen;
		tboard=wboard|bboard;
	}
	
	 pawn_moves(int rank1,char file1,int rank2,char file2,char type)
	{
	   //Number of shifting positions will vary with the pawn taken 
                int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
		 if(type=='w' || type=='W')
		 {	if((rank1==2 && rank2 >4 || rank2-rank1 > 1 )&& ((file1-file2!=0)&&oropshift|bboard==0))
			{ 	
			   cout<<"Invalid move"<<endl;
		   	   return 0;
			}
		       else
		       {
	           		WPawns= WPawns^oroperand;
		   		WPawns= WPawns|oropshift;
				 if(oropshift&bboard==1)       //If a black piece is removed this block removes that piece from the bitboard
				 {
		          		BPawns=BPawns^oropshift;
				 	
			 	}
			       total_board();
		 	}
		 }
		 else if(type=='b' || type=='B')
		 { 
			 if((rank1=7 && rank2<5 || rank1-rank2 >1 ) && ((file1-file2!=0)&&oropshift|wboard==0))
		   		{	 cout<<"Invalid move"<<endl;
	                		  return 0;
		   		}
		     	else 
		 		{
	        	   		BPawns=BPawns^oroperand;
	        	   		BPawns=BPawns|oropshift;
	      	   			if(oropshift&wboard==1)            // Similar block for removing white piece
			 		{
		          		WPawns=WPawns^oropshift;
				 	
			 		}
				total_board();
		               }
	       	}
		 else
		 { cout<<"Invalid type "<<endl;
		   return 1;
		 }
		
	} 
       
    knight_moves(int rank1,char file1,int rank2,char file2,char type)
    {
	        int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 oroperand=pieces[index1];
		u64 oropshift=pieces[index2];
	switch(type)
	{
		case 'w' :
		case 'W' :  	if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||wboard|oropshift==0)
	           		cout<<"Invalid move"<<endl;
	         	 	else 
	         	 	 {
	           			WKnights=WKnights^oroperand;
	           			WKnights=WKnights|oropshift;
	           			if(oropshift&bboard==1)
					{
	           			BKnights=BKnights^oropshift;
	           			
					}
					total_board();
			  	 }
		      		 break;
	      case 'b' :
	      case 'B' :	        if((abs(rank1-rank2)!=1 && abs(file1-file2)!=2 ) || (abs(rank1-rank2)!=2 && abs(file1-file2)!=1) ||bboard|oropshift==0)
	           	        cout<<"Invalid move"<<endl;
	         	        else 
	          	         {
	           			BKnights=BKnights^oroperand;
	           			BKnights=BKnights|oropshift;
	           			if(oropshift&wboard==1)
					{	
					WPawns=WPawns^oropshift;
	           			
					}
					total_board();
		       		 }
		     		 break;
	    default : cout<<"Invalid Type "<<endl;
		      cout<<"Try again "<<endl;
	}
}  
 bishop_moves( int rank1,char file1,int rank2,char file2,char type)
{
int index1=(rank1-1)*8 + (file1-96) -1;
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];
u64 c=a;
    
    switch(type)
    {
    case 'w':
    case 'W':  
		   if(file1<file2)
		     {
			if(rank1<rank2)
			  {
			    while(a!=b)
			     {
			      a=a>>9;
		              if(a&tboard!=0)
				 {
			           cout<<"Invalid move"<<endl;
			     	   break;
			         }
			     }
			    if(a==b)
			     {
				WBishops=WBishops^c;
				WBishops=WBishops|a;
				    if(a&bboard==a)
				    {
					    remove(a,1);
				    }
			        total_board();
			     }
			  }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
					{
						WBishops=WBishops^c;
						WBishops=WBishops|a;
						if(a&bboard==1)
						{
							remove(a,1);
						}
					}
			           }
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
			{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
					if(a==b)
					{
				}
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
				 }
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
		    else
		    {
			    cout<<"Invalid move"<<endl;
		    }
                break;
		 
	    case 'b' :
	    case 'B' :
		        if(file1<file2)
		     {
			if(rank1<rank2)
			  {
			    while(a!=b)
			     {
			      a=a>>9;
		              if(a&tboard!=0)
				 {
			           cout<<"Invalid move"<<endl;
			     	   break;
			         }
			     }
			    if(a==b)
			     {
				BBishops=BBishops^c;
				BBishops=BBishops|a;
				    if(a&wboard==a)
				    {
					    remove(a,0);
				    }
			        total_board();
			     }
			  }
				else if(rank1>rank2)
				  {
				     while(a!=b)
					 { 
					  a=a<<7;
					  if(a&tboard!=0)
					    {
						 cout<<"Invalid move"<<endl;
						 break;
					    }
					 }
					if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard==1)
						{
							remove(a,0);
						}
				  }
				}
				else
				{
				cout<<"Invalid move"<<endl;
				}
			  }
	      		else if(file1>file2)
			{
				if(rank1>rank2)
				{
				 while(a!=b)
				 {
				   a=a>>7  ;
				  if(a&tboard!=0)
				   {
				    cout<<"Invalid move"<<endl;
				    break;
			       	   }
				 }
					if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard==1)
						{
							remove(a,0);
						}
					}
				}
				 else if(rank1<rank2)
 		        	 {
	          		   while(a!=b)
				   {
					   a=a<<9  ;
					   if(a&tboard!=0)
					   {
					     cout<<"Invalid move"<<endl;
				             break;
					   }
				   }
					 if(a==b)
					{
						BBishops=BBishops^c;
						BBishops=BBishops|a;
						if(a&wboard==1)
						{
							remove(a,0);
						}
				  	}
				 }
				else 
			   	{
		          	 cout<<"Invalid move"<<endl;
				}
			}
		   
                                break;
				default: cout<<"Invalid color"<<endl;
			}       
    }
	
	rook_moves(int rank1,char file1,int rank2,char file2,char type)
{
 int index1=(rank1-1)*8 + (file1-96) -1;//ascii of a is 97
int index2=(rank2-1)*8 + (file2-96) -1;
u64 a=pieces[index1];
u64 b=pieces[index2];
int test;
//u64 a;
u64 c=a; 
	switch(type)
	{
		case 'w':
		case 'W':


//Piece Illegal Move
if(file2!=file1) && (rank1!=rank2)
{
cout<<"Invalid Move"<<endl;
test=1; 
}
			
		
			
if(test==0)
{
	if (file1==file2)
	{
		if(rank2>rank1)
		while(a!=b)
		{
			a=a>>8;
			 if(a&tboard==0)
			{
			cout<<"Invalid move"<<endl;
			break;
			}
	else {
		c=a>>8*(rank2-rank1);
		WRooks=WRooks|c;
		remove2(WRooks,a);  //Basically removing elements of a from the bitboard		
	}


			
		}
	else if(rank2<rank1)
	while(a!=b)
	{
	a=a<<8;
 	if(a&tboard==0)
	{
	cout<<"Invalid move"<<endl;
	break;
	}

else {
		c=c<<8*abs((rank2-rank1));
		WRooks=WRooks|c;
		remove2(WRooks,a);
	
}
		
	}

	
	}
		}
	}
}


if(rank1==rank2)
{
if(file1>file2) 
{
a=a<<(file1-file2); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
}
	else	{
		c=c<<abs((file1-file2));
		WRooks=WRooks|c;
		remove2(WRooks,a);	
	}
	
	
}
else if(file2>file1)
 {
a=a>>(file2-file1); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
} 
	else	{
		c=c>>abs((file1-file2));
		WRooks=WRooks|c;
		remove2(WRooks,a);
	}
	
	
}
}


		case 'B': 
		case 'b':
			
//Piece Illegal Move
if(file2!=file1) && (rank1!=rank2)
{
cout<<"Invalid Move"<<endl;
test=1; 
}
			
		
			
if(test==0)
{
	if (file1==file2)
	{
		if(rank2>rank1)
		while(a!=b)
		{
			a=a>>8;
			 if(a&tboard==0)
			{
			cout<<"Invalid move"<<endl;
			break;
			}
	else {
		c=a>>8*abs((rank2-rank1));
		BRooks=BRooks|c;
		remove2(BRooks,a);  //Basically removing elements of a from the bitboard		
	}


			
		}
	else if(rank2<rank1)
	while(a!=b)
	{
	a=a<<8;
 	if(a&tboard==0)
	{
	cout<<"Invalid move"<<endl;
	break;
	}

else {
		c=c<<8*abs((rank2-rank1));
		BRooks=BRooks|c;
		remove2(BRooks,a);
	
}
		
	}

	
	}
		}
	}
}


if(rank1==rank2)
{
if(file1>file2) 
{
a=a<<(file1-file2); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
}
	else	{
		c=c<<abs((file1-file2));
		BRooks=BRooks|c;
		remove2(BRooks,a);	
	}
	
	
}
else if(file2>file1)
 {
a=a>>(file2-file1); 
if(a&tboard==0)
{
cout<<"Invalid move"<<endl;
break;
} 
	else	{
		c=c>>abs((file1-file2));
		BRooks=BRooks|c;
		remove2(BRooks,a);
	}
	
	
}
}









}

};
int main()
{

return 0;

}
