#include<bits/stdc++.h>
#include<iostream>
#include"trie.h"
using namespace std;
int main()
{
    TrieNode *root= new TrieNode();
    while(1)
    {
    	int n;
    	
    	cout<<"1. Create Dictionary\n2. Insert Word\n3. Delete Word\n4. Search word\n5. Modify Word\n6. Count the Number of in the List\n7. Emptylist \n8. Exit"<<endl;
    	cin>>n;
    	if(n>=8)
    	{
    		cout<<"Thank you for using dictionay!!!\n";
    		break;
    	}
    	switch(n)
    	{
    	    case 1:
    	    {
    	    	cout<<"This Functionality is Currently Unavaliable\n";
    	    	break;
    	    }
            case 2: 
            {
                string str;
                cout<<"Enter Word to Insert:-";	
                cin>>str;
                root->Addword(str,root);
                break;
            }	  	
            case 3:
            {
                string str;
                cout<<"Enter Word to Delete:-";	
                cin>>str;
                root->DeleteWord(str,root);
                break;
            }	
            case 4:
            {
                string str;
                cout<<"Enter Word to Search:-";	
                cin>>str;
                root->search(str,root);
                break;
            }   
            case 5:
            {
                string str;
                cout<<"Enter Word to Modify:-";	
                cin>>str;
                root->ModifyWord(str,root);
                break;
            }
            case 6:
            {
                root->Count_No_Words(root);
                break;
            } 
            case 7:
            {
                cout<<"This Functionality is Crrently Unavaliable\n";
                    break;
            }
    	}  
    }
    
    //root->Addword("",root);
    return 0;
}
