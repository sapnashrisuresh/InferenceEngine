/*
 * trial.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: Sapna
 */
/*
 * main.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Sapna
 */
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <list>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string unified[100][100];
string lhs[100][100];
string rhs[100][100];
string lhs2[100][100];
string calculaterhs[100][100];
bool visited[10];
int p=0;
std::ofstream out("output.txt");

void breakparts_rhs(string rhscopy,int m)
{
	char c;
	int l=1;
	std::locale loc;
	string constant;
	string str=rhscopy;
	c=str[0];
	for (std::string::size_type i=0; i<str.length(); ++i)
	{
		int count=0;
	   //cout<<"here";
	   c=str[i];
	   if (std::islower(c,loc))  //c=std::tolower(c,loc);
	   {
		   if(str[i-1]=='(' and str[i]=='x')
		   {
			  // cout<<"variable1 is "<<str[i]<<"\n";
			   rhs[m][l]=str[i];
			   l++;
		   }
		   if(str[i-1]==',' and str[i]=='x')
		   {
	   		  // cout<<"variable2 is "<<str[i]<<"\n";
	   		   rhs[m][l]=str[i];
	   		   l++;
		   }
	   }
	   if (std::isupper(c,loc))  //c=std::tolower(c,loc);
	   {
		   //cout<<"here";
		   if(i==0)
		   {
			   for (std::string::size_type j=i; str[j]!='('; ++j)
			   {
				   count++;
			   }
			   constant = str.substr(i,count);
			   rhs[m][l]=constant;
			   l++;
			   // std::cout << "function here.."<<constant<<"\n";
		   }
		   else if(str[i-1]=='(')
		   {
			   for (std::string::size_type j=i; str[j]!=','; ++j)
			   {
				   if(str[j]==')')
					   break;
			   		count++;
			   }
			   constant = str.substr(i,count);
			   //std::cout << "constant1 here.."<<constant<<"\n";
			   rhs[m][l]=constant;
			   l++;
		   }
		   else if(str[i-1]==',')
		   {
			   for (std::string::size_type j=i; str[j]!=')'; ++j)
			   {
			   			   		count++;
			   }
			   constant = str.substr(i,count);
			   //std::cout << "constant2 here.."<<constant<<"\n";
			   rhs[m][l]=constant;
			   l++;
		   }
	   }
	}
}

void breakparts_lhs(string lhscopy,int y,int z)
{
	//p++;
	char c;
	std::locale loc;
	string constant;
	string str=lhscopy;
		//cout<<lhscopy<<"\n";
	c=str[0];
	int l=0;
	stringstream ss;
	string tostr;
	ss << y;
	tostr = ss.str();
	lhs2[p][l]=tostr;
	//cout<<lhs2[p][l]<<" ";
	l++;
	ss << z;
	tostr = ss.str();
	lhs2[p][l]=tostr;
	//cout<<lhs2[p][l]<<" ";
	l++;
	//cout<<"String is "<<str<<"\n";
	for (std::string::size_type i=0; i<str.length(); i++)
	{
		//cout<<"l value here "<<l<<"\n";
		int count=0;
		   //cout<<"here";
		c=str[i];
		if (std::islower(c,loc))  //c=std::tolower(c,loc);
		{
		   if(str[i-1]=='(' and str[i]=='x')
		   {
			  // cout<<"variable1 is "<<str[i]<<"\n";
			   lhs2[p][l]=str[i];
			   //cout<<lhs2[p][l]<<"\n";
			   l++;
		   }
		   if(str[i-1]==',' and str[i]=='x')
		   {
		   		  // cout<<"variable2 is "<<str[i]<<"\n";
	   		   lhs2[p][l]=str[i];
	   		  // cout<<lhs2[p][l]<<"\n";
	   		   l++;
		   }
		  }
		  if (std::isupper(c,loc))  //c=std::tolower(c,loc);
		  {
			   if(i==0)
			   {
				   count=0;
				   for (std::string::size_type j=i; str[j]!='('; ++j)
				   {
					   //cout<<str[j];
					   count++;
				   }
				   constant = str.substr(0,count);
				   // cout<<"const="<<count<<"\n";
				   lhs2[p][l]=constant;
				  // cout<<lhs2[p][l]<<"\n";
				   l++;
				   // std::cout << "function here.."<<constant<<"\n";
			    }
			   //cout<<"here";
			   else if(str[i-1]=='(')
			  {
				  count=0;
				   for (std::string::size_type j=i; str[j]!=','; ++j)
				   {
					   if(str[j]==')')
					  		break;
				   		count++;
				   }
				   constant = str.substr(i,count);
				   //std::cout << "constant1 here.."<<constant<<"\n";
				   lhs2[p][l]=constant;
				  // cout<<lhs2[p][l]<<"\n";
				   l++;
			   }

			   else if(str[i-1]==',')
			   {
				   count=0;
				   for (std::string::size_type j=i; str[j]!=')'; ++j)
				   {
					   count++;
				   }
				   constant = str.substr(i,count);
				   //std::cout << "constant2 here.."<<constant<<"\n";
				   lhs2[p][l]=constant;
				  // cout<<lhs2[p][l]<<"\n";
				   l++;
			   }
			   else
			   {
			   }
	   }
	}
	p++;
}

void breakparts_uni(string unicopy,int m)
{
	char c;
	int l=1;
	std::locale loc;
	string constant;
	string str=unicopy;
	c=str[0];
	for (std::string::size_type i=0; i<str.length(); ++i)
	{
		int count=0;
	   //cout<<"here";
	   c=str[i];
	   if (std::isupper(c,loc))  //c=std::tolower(c,loc);
	   {
		   //cout<<"here";
		   if(i==0)
		   {
			   for (std::string::size_type j=i; str[j]!='('; ++j)
			   {
				   count++;
			   }
			   constant = str.substr(i,count);
			   unified[m][l]=constant;
			   l++;
			   // std::cout << "function here.."<<constant<<"\n";
		   }
		   else if(str[i-1]=='(')
		   {
			   for (std::string::size_type j=i; str[j]!=','; ++j)
			   {
				   if(str[j]==')')
					   break;
				   count++;
			   }
			   constant = str.substr(i,count);
			   //std::cout << "constant1 here.."<<constant<<"\n";
			   unified[m][l]=constant;
			   l++;
		   }
		   else if(str[i-1]==',')
		   {
			   for (std::string::size_type j=i; str[j]!=')'; ++j)
			   {
			   			   		count++;
			   }
			   constant = str.substr(i,count);
			   unified[m][l]=constant;
			  // std::cout << "constant2 here.."<<unified[m][l]<<"\n";
			   l++;
		   }
		   else
		   {
		   }
	   }
	}
}

void break_input(string query1,string query[10])
{
	//string query[10];
	query[0]=query1;
	char c;
			int l=1;
			std::locale loc;
			string constant;
			c=query1[0];
			for (std::string::size_type i=0; i<query1.length(); i++)
			{
				int count=0;
			   //cout<<"here";
			   c=query1[i];
			   if (std::isupper(c,loc))  //c=std::tolower(c,loc);
			   {
				   //cout<<"here";
				   if(i==0)
				   {
					   for (std::string::size_type j=i; query1[j]!='('; ++j)
					   {
						   count++;
					   }
					   constant = query1.substr(i,count);
					   query[l]=constant;
					   l++;
					   //std::cout << "function here.."<<constant<<"\n";
				   }
				   else if(query1[i-1]=='(')
				   {
					   for (std::string::size_type j=i; query1[j]!=','; ++j)
					   {
						   if(query1[j]==')')
							   break;
						   count++;
					   }
					   constant = query1.substr(i,count);
					   //std::cout << "constant1 here.."<<constant<<"\n";
					   query[l]=constant;
					   l++;
				   }
				   else if(query1[i-1]==',')
				   {
					   for (std::string::size_type j=i; query1[j]!=')'; ++j)
					   {
					   			   		count++;
					   }
					   constant = query1.substr(i,count);
					   //std::cout << "constant2 here.."<<constant<<"\n";
					   query[l]=constant;
					   l++;
				   }
				   else
				   {
				   }
			   }
			}
			//cout<<"at break input : "<<query[0]<<"  "<<query[1]<<"  "<<query[2]<<"  "<<query[3]<<"\n";
			return;
}

int findx(string query)
{
	int position;
	std::size_t found = query.find("(x");
	if (found!=std::string::npos)
	 {
		position=0;
		return position;
	 }
	found = query.find("x)");
		if (found!=std::string::npos)
		 {
			position=1;
			return position;
		 }
	for(int i=0;i<10;i++)
	{
		if(rhs[i][2]=="x" and rhs[i][3].length()>0)
		{
			position=0;
			return position;
		}
		if(rhs[i][3]=="x")
		{
			position=1;
			return position;
		}
		if(lhs2[i][3]=="x" and lhs2[i][4].length()>0)
		{
			position=0;
			return position;
		}
		if(lhs2[i][4]=="x")
		{
			position=1;
			return position;
		}
	}
	return 0;
}
void dfs(string query[])
{
	string s;
	string x;
	string dupquery=query[0];
	bool valid;
	string output;
	vector<string> stack;
	vector<int>::iterator u;
	int position=findx(query[0]);
	//cout<<"position="<<position<<"\n";
	s=query[0];
	//cout<<"s="<<s<<"\n";
	break_input(s,query);
    if(query[3].length()>0)
    {
    	//cout<<query[1]<<" "<<query[2]<<" "<<query[3]<<"\n";
    	for(int j=0;j<10;j++)
    	{
    		if(query[1]==rhs[j][1] and (query[2]==rhs[j][2] or query[3]==rhs[j][3]))
    		{
    			//cout<<"here.\n";
    			//visited[j]=true;
    			std::size_t found = rhs[j][0].find("(x");
    			std::size_t found2 = rhs[j][0].find("x)");
    			if (position==0 and found==std::string::npos)
    			{
    			//cout<<"no x here \n";
    			valid=false;
    			if(query[2]==rhs[j][2] and query[3]==rhs[j][3])
    			{
    				valid=true;
    				stack.push_back(query[0]);
    				continue;
    			}
    			}
    			else if (position==1 and found2==std::string::npos)
    			{
    			//cout<<"no x here \n";
    			valid=false;
    			if(query[2]==rhs[j][2] and query[3]==rhs[j][3])
    			{
    				valid=true;
    				stack.push_back(query[0]);
    				continue;
    			}
    			}
    			else
    			{
    				//cout<<"hee";
    				stack.push_back(query[0]);
    				continue;
    			}
    		}

    	}
    }
    else
    {
    	for(int j=0;j<10;j++)
    	{
    		if(query[1]==rhs[j][1])
    		{
    			std::size_t found = rhs[j][0].find("(x");
    			if (found==std::string::npos)
    			{
    				//cout<<"no x here \n";
    				valid=false;
    				if(query[2]==rhs[j][2])
    				{
    					valid=true;
    					stack.push_back(query[0]);
    					continue;
    				}
    			}
    			else
    			{
    			//visited[j]=true;
    			stack.push_back(query[0]);
    			continue;
    			}
    		}
    	}
    }

    if(stack.empty())
    {
    	output="FALSE";
    	out<<"FALSE";
    	//cout<<output<<"\n";
    	return;
    }
	int first=1;
	//std::cout<<"length="<<stack.size()<<"\n";
	int duplicate=stack.size();
    //x=findingx(query);

	//cout<<"x="<<x<<"\n";
	//cout<<"dfs...\n";
	int m=0;
	bool totalval[10];
	bool finalval=true;
	bool finalval2=false;
	int rhsval=0;
	for(int i=0;i<duplicate;i++)
	{
		totalval[i]=true;
	}

	while(m<50)
	 {
		valid=false;
		 string query2[10];
	     s=stack.back();
	     //cout<<s<<"\n";
	     if(s==dupquery and first!=1)
	     {
	    	 if(rhsval<duplicate)
	    		 rhsval++;
	     }

	     break_input(s,query2);
	     int check=0;
		   for(int j=0;j<10;j++)
		   {
			   if((query2[3].length()<=0) and !stack.empty())
			   {
				   //x=unified[j][2];
				   if((query2[1]==unified[j][1] and unified[j][2]==x) || query2[0]==unified[j][0])
				   {check=1;
				   valid=true;
				   //x=unified[j][2];
				  // cout<<"1popping "<<query2[0]<<"\n";
				   stack.pop_back();
				   break;}
			   }
			   else if(query2[3].length()>0 and position==0 and query2[1]==unified[j][1] and query2[3]==unified[j][3] and first!=1 and !stack.empty())
			   {
				   check=1;
			    		 valid=true;
			    		 //x=unified[j][2];
			    		 stack.pop_back();
			    		//cout<<"2popping "<<query2[0]<<"\n";
			    		 break;
			   }
			   else if(query2[3].length()>0 and position==1 and query2[1]==unified[j][1] and query2[2]==unified[j][2] and first!=1 and !stack.empty())
			   {
				   check=1;
				   valid=true;
				   //x=unified[j][2];
				   stack.pop_back();
				   //cout<<"2popping "<<query2[0]<<"\n";
				   break;
			   }

			}

		  if(duplicate>1)
		  {
			  if(stack.empty() and first!=1)
			  {
				  //cout<<finalval2<<"\n";
				  for(int i=0;i<duplicate;i++)
				  {
					  finalval2=finalval2 or totalval[i];
				  }
				  if(finalval2==true)
				  {
					  output="TRUE";
					  out<<output;
					  //cout<<output<<"\n";
					  return;
				  }
				  if(finalval2==false)
				  {
					  output="FALSE";
					  out<<output;
					  //cout<<output<<"\n";
					  return;
				  }
			  }
		  }
		  else
		  {
			  if(finalval==true and stack.empty() and first!=1)
			 		 {
			 			 output="TRUE";
			 			 out<<output;
			 			 //cout<<output<<"\n";
			 			 return;
			 		 }
			  if(finalval==false and stack.empty() and first!=1)
			  			 		 {
			  			 			 output="FALSE";
			  			 			 out<<output;
			  			 			 //cout<<output<<"\n";
			  			 			 return;
			  			 		 }
		  }
	     m++;
	     first=0;
	     for(int j=0;j<10;j++)
	     {
	    	 if(check==0 and position==0 and query2[3].length()>0 and query2[1]==rhs[j][1] and query2[3]==rhs[j][3] and !stack.empty())
	    	 {
	    		 check=1;
	    		 valid=true;
	    		// if(rhs[j][2]!="x")
					  // x=rhs[j][2];
				   // cout<<"x here is "<<x<<"\n";
	    		//cout<<"3popping "<<query2[0]<<"\n";
	    		 stack.pop_back();
	    		 break;
			  }
			   else if(check==0 and query2[1]==rhs[j][1] and !stack.empty())
			   {
				   check=1;
				   valid=true;
			  				   //if(rhs[j][2]!="x")
			  					  // x=rhs[j][2];
			  				   // cout<<"x here is "<<x<<"\n";
				  // cout<<"4popping "<<query2[0]<<"\n";
				   stack.pop_back();
				   break;
			   }
			   else if(check==0 and position==1 and query2[3].length()>0 and query2[1]==rhs[j][1] and query2[2]==rhs[j][2] and !stack.empty())
	    	   {
				   check=1;
				   valid=true;
				   //if(rhs[j][2]!="x")
				   	   // x=rhs[j][2];
				   // cout<<"x here is "<<x<<"\n";
				   //cout<<"3popping "<<query2[0]<<"\n";
				   stack.pop_back();
				   break;
	    	   }
	    	  }

	     if(check==0 and !stack.empty())
	     {
	    	 valid=false;
	    	 finalval=finalval and valid;
	    	 totalval[rhsval]=totalval[rhsval] and valid;
	    	 stack.pop_back();
	    	// cout<<"5.popping"<<query2[0]<<"\n";
	     }


	     if(query2[3].length()>0)
	     {
	    	 int check=0;
	    	//cout<<"here this..\n";

	        for(int j=0;j<10;j++)
	        {
	            if(query2[1]==rhs[j][1] and (query2[2]==rhs[j][2] || query2[3]==rhs[j][3]) and visited[j]!=true)
	            {
	            	check=1;
	            	valid=true;
	            	visited[j]=true;
	            	//cout<<stack.back()<<"query="<<query2[1]<<" "<<" 2\n";
	            	//stack.pop_back();
	            	for(int i=0;i<10;i++)
	            	{
	            		stringstream ss;
	            		ss << j;
	            		string str = ss.str();
	            		if(lhs2[i][0]==str)
	            		{
	            			if(lhs2[i][4].length()>0)
	            			{
	            				for(int j=0;j<10;j++)
	            				{
	            					if(position==0 and lhs2[i][2]==rhs[j][1] and lhs2[i][4]==rhs[j][3])
	            					{
	            						x=rhs[j][2];
	            					}
	            					else if(position==0 and lhs2[i][2]==unified[j][1] and lhs2[i][4]==unified[j][3])
	            					{
	            						x=unified[j][2];
	            					}
	            					else if(position==1 and lhs2[i][2]==rhs[j][1] and lhs2[i][3]==rhs[j][2])
	            					{
	            						x=rhs[j][3];
	            					}
	            					else if(position==1 and lhs2[i][2]==unified[j][1] and lhs2[i][3]==unified[j][2])
	            					{
	            						x=unified[j][3];
	            					}
	            				}
	            			}
	            			else
	            			{
	            				for(int j=0;j<10;j++)
	            				{
	            					if(lhs2[i][2]==rhs[j][1])
	            					{
	            						x=rhs[j][2];
	            					}
	            					else if(lhs2[i][2]==unified[j][1])
	            					{
	            						x=unified[j][2];
	            					}
	            				}
	            			}
	            			if(x!="x")
	            				break;
	            		}
	            	}

	            	for(int i=0;i<10;i++)
	            	{
	            		stringstream ss;
	            		ss << j;
	            		string str = ss.str();
	            		if(lhs2[i][0]==str)
	            		{
	            			if(lhs2[i][4].length()>0 and position==0)
	            			{
	            				stack.push_back(lhs2[i][2]+"("+x+","+lhs2[i][4]+")");
	            				//cout<<"1pushing lhs.."<<lhs2[i][2]<<"\n";
	            				//break;
	            			}
	            			else if(lhs2[i][4].length()>0 and position==1)
	            			{
	            				stack.push_back(lhs2[i][2]+"("+lhs2[i][3]+","+x+")");
	            				//cout<<"1pushing lhs.."<<lhs2[i][2]<<"\n";
	            				//break;
	            			}
	            			else
	            			{
	            				stack.push_back(lhs2[i][2]+"("+x+")");
	            				//cout<<"2pushing lhs.."<<lhs2[i][2]<<"\n";
	            			}
	            		}
	            	}
	            }
	            if(check==1)
	            	break;
	        }

	        if(!valid)
	        {
	            	output="FALSE";

	        }
	    }
	 else
	 {
		 int check=0;
		//cout<<"exec this...\n";
		 for(int j=0;j<10;j++)
		 	        {
		 	            if(query2[1]==rhs[j][1] and visited[j]!=true)
		 	            {
		 	            	check=1;
		 	            	visited[j]=true;
		 	            	valid=true;
		 	            	//cout<<stack.back()<<" 4\n";
		 	            	//stack.pop_back();
		 	           	for(int i=0;i<10;i++)
		 	           	            	{
		 	           	            		stringstream ss;
		 	           	            		ss << j;
		 	           	            		string str = ss.str();
		 	           	            		if(lhs2[i][0]==str)
		 	           	            		{
		 	           	            			if(lhs2[i][4].length()>0)
		 	           	            			{
		 	           	            				for(int j=0;j<10;j++)
		 	           	            				{
		 	           	            					if(lhs2[i][2]==rhs[j][1] and lhs2[i][4]==rhs[j][3] and position==0)
		 	           	            					{
		 	           	            						x=rhs[j][2];
		 	           	            					}
		 	           	            					else if(lhs2[i][2]==unified[j][1] and lhs2[i][4]==unified[j][3] and position==0)
		 	           	            					{
		 	           	            						x=unified[j][2];
		 	           	            					}
		 	           	            					else if(lhs2[i][2]==rhs[j][1] and lhs2[i][3]==rhs[j][2] and position==1)
		 	           	            					{
		 	           	            						x=rhs[j][3];
		 	           	            					}
		 	           	            					else if(lhs2[i][2]==unified[j][1] and lhs2[i][3]==unified[j][2] and position==0)
		 	           	            					{
		 	           	            						x=unified[j][3];
		 	           	            					}
		 	           	            				}
		 	           	            			}
		 	           	            			else
		 	           	            			{
		 	           	            				for(int j=0;j<10;j++)
		 	           	            				{
		 	           	            					if(lhs2[i][2]==rhs[j][1])
		 	           	            					{
		 	           	            						x=rhs[j][2];
		 	           	            					}
		 	           	            					else if(lhs2[i][2]==unified[j][1])
		 	           	            					{
		 	           	            						x=unified[j][2];
		 	           	            					}
		 	           	            				}
		 	           	            			}
		 	           	            		if(x!="x")
		 	           	            			break;
		 	           	            		}
		 	           	            	}
		 	            	for(int i=0;i<10;i++)
		 	            	{
		 	            		stringstream ss;
		 	            		ss << j;
		 	            		string str = ss.str();
		 	            		if(lhs2[i][0]==str)
		 	            		{
		 	            			if(lhs2[i][4].length()>0 and position==0)
		 	            			{
		 	            				stack.push_back(lhs2[i][2]+"("+x+","+lhs2[i][4]+")");
		 	            				//cout<<"3pushing lhs.."<<lhs2[i][2]<<"\n";
		 	            				//break;
		 	            			}
		 	            			else if(lhs2[i][4].length()>0 and position==1)
		 	            			{
		 	            				stack.push_back(lhs2[i][2]+"("+lhs2[i][3]+","+x+")");
		 	            				//cout<<"3pushing lhs.."<<lhs2[i][2]<<"\n";
		 	            				//break;
		 	            			}
		 	            			else
		 	            			{
		 	            				stack.push_back(lhs2[i][2]+"("+x+")");
		 	            				//cout<<"4pushing lhs.."<<lhs2[i][2]<<"\n";
		 	            			}
		 	            		}
		 	            	}
		 	            }
		 	            if(check==1)
		 	            	break;
		 	        }
		 if(!valid)
		 {
			 output="FALSE";
		 }

		}
	 }
		// cout<<output<<"\n";
		 out<<output;
	 return;
}

void fol_bc(string query[],int n)
{
	for(int i=0;i<n;i++)
	{
		std::size_t found = unified[i][0].find(query[0]);
		if (found!=std::string::npos)
		{
			cout<<"True!";
			out<<"TRUE";
			return;
		}
	}
	dfs(query);
	return;
}

int main()
{
	string query1;
	string kbase[100];
	string query[10];
	int n;
	int j=0;
	int k=0;

	//cout<<"this will be awesome!\n\n";
	ifstream in;
	in.open("input.txt");
	in>>query1;
	in>>n;
	for(int i=0;i<n;i++)
		in>>kbase[i];

	string implication("=>");
	string an("&");
	int unlen=0;

	for(int i=0;i<n;i++)
	{
		std::size_t found = kbase[i].find(implication);
		if (found!=std::string::npos)
		{
			lhs[k][0] = kbase[i].substr(0,found);
			rhs[k][0] = kbase[i].substr(found+2);
			k++;
		}
		else
		{
			unlen++;
			unified[j][0]=kbase[i];
			j++;
		}
	}
	for(int k=0;k<n;k++)
	{
		std::size_t found = lhs[k][0].find(an);
		if (found!=std::string::npos)
		{
			lhs[k][1] = lhs[k][0].substr(0,found);
			lhs[k][2] = lhs[k][0].substr(found+1);
		}
		else
		{
			lhs[k][1] = lhs[k][0];
		}
	}
	for(int i=0;i<n;i++)
	{
		breakparts_rhs(rhs[i][0],i);
	}


	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			//cout<<lhs[i][j]<<"  ";
			string st=lhs[i][j];
			if(st.length()>0)
				breakparts_lhs(lhs[i][j],i,j);
		}
		//cout<<"\n";
	}

		for(int i=0;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				string x("x");
						std::size_t found = lhs[i][j].find(x);
								if (found==std::string::npos)
								{
									unified[unlen][0]=lhs[i][j];
									unlen++;
								}
			}
		}

	for(int i=0;i<n;i++)
		{
			breakparts_uni(unified[i][0],i);
		}
	for(int i=0;i<10;i++)
			{
				visited[i]=false;
			}

		break_input(query1,query);
		fol_bc(query,n);
	return 0;
}


