bishop_moves( int rank1,char file1,int rank2,char file2,char type)
{
int index1=(rank1-1)*8 + (file1-96) -1;
		int index2=(rank2-1)*8 + (file2-96) -1;
		u64 a=pieces[index1];
		u64 b=pieces[index2];
    
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
							    if(a|tboard!=0)
									 {
									  cout<<"Invalid move"<<endl;
								   	break;
								   }
							 	}
								else if(rank1>rank2)
								{
								 while(a!=b)
								 { 
								  a=a<<7;
							   	if(a|tboard!=0)
								   {
								    cout<<"Invalid move"<<endl;
								    break;
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
								   a=a   ;
									  if(a|tboard!=0)
										 {
										  cout<<"Invalid move"<<endl;
											break;
											}
									}
								}
								 else if(rank1<rank2)
									{
								  
								
								
             
    
