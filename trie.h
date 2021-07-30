#ifndef TRIE_H
#define TRIE_H
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class TrieNode{
    TrieNode* charecter[26];
    map<string,vector<string> >mp;
    int count;
    public:
        TrieNode();
        void Addword(string,TrieNode*);
        void search(string,TrieNode*);
        void DeleteWord(string,TrieNode*);
        void ModifyWord(string,TrieNode*);
        void Count_No_Words(TrieNode*);
         
        // ~TrieNode();
};


TrieNode::TrieNode()
{	
	for(int i=0;i<26;i++)
	    charecter[i]=NULL;
		count=0;
}


void TrieNode::Addword(string word,TrieNode *root)
{
    if(word=="")
    {
    	cout<<"Opps Word is Empty!!!\n";
		return ;
	}
    TrieNode *tmp=root;
    if(root==NULL)
    {
        cout<<"List is empty\n";
        root= new TrieNode();
        tmp=root;     
    }
    for(int i=0;i<word.size();i++)
    {
        int k=word[i]-97;
        if(tmp->charecter[k]==NULL)
        {
            TrieNode *tmp1=new TrieNode();
            tmp->charecter[k]=tmp1;
            //tmp=tmp1;
            //cout<<"new one\n";
        }
        tmp->count++;
        tmp=tmp->charecter[k];

    }
    map<string,vector<string> >mp1;
    cout<<"Enter Details for -> "<<word<<endl;
    cout<<"Enter Definition:- ";
    while(1)
    {
        string str;
        cin>>str;
        if(str==".")
            break;
        mp1["Definition"].push_back(str);
    }
    cout<<"Enter Origin:- ";
    while(1)
    {
        string str;
        cin>>str;
        if(str==".")
            break;
        mp1["Origin"].push_back(str);
    }
    cout<<"Enter Synonym:- ";
    while(1)
    {
        string str;
        cin>>str;
        if(str==".")
            break;
        mp1["Synonym"].push_back(str);
    }
    cout<<"Enter Antonym:- ";
    while(1)
    {
        string str;
        cin>>str;
        if(str==".")
            break;
        mp1["Antonym"].push_back(str);
    }
    cout<<"Word Added Successfully\n";
    cout<<endl;
    tmp->mp=mp1;
}



void TrieNode::search(string word,TrieNode *root)
{
	if(root==NULL)
	{
	     cout<<"List is Empty\n";
	     cout<<endl;
	     return;
	}
	TrieNode* tmp=root; 
	for(int i=0;i<word.size();i++)
    {
    	int k=word[i]-97;
    	if(tmp->charecter[k]==NULL)
    	{
            cout<<"Word is Not Present in the Dictionary\n";
            cout<<endl;
            return;
        }
        tmp=tmp->charecter[k];
    }
    map<string,vector<string> >mp1 = tmp->mp;
    vector<string>v;
    cout<<"Details for ->"<<word<<endl;
    v = mp1["Definition"];
    cout<<"Definition:- ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }        
    cout<<"\n";
    v = mp1["Origin"];
    cout<<"Origin:- ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    v = mp1["Synonym"];
    cout<<"Synonym:- ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<"\n";
    v = mp1["Antonym"];
    cout<<"Antonym:- ";
        for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }   
    cout<<"\n";
    cout<<endl;
}

void TrieNode::DeleteWord(string word,TrieNode *root)
{
	if(root==NULL)
	{
	     cout<<"List is Empty\n";
	     return;
	}
	TrieNode* tmp=root;
	TrieNode* prev=NULL;
	for(int i=0;i<word.size();i++)
        {
        	int k=word[i]-97;
        	if(tmp->charecter[k]==NULL)
        	{
        		cout<<"Word is Not Present in the Dictionary\n";
        		return;
        	}
        	tmp=tmp->charecter[k];
        }
        tmp=root;
        int flg=0;
        for(int i=0;i<word.size();i++)
        {
        	int k=word[i]-97;
        	prev=tmp;
             	tmp=tmp->charecter[k];
             	if(tmp->count==1)
             	{
             		prev->charecter[k]=NULL;
             		while(tmp!=NULL)
             		{
             			i++;
             			k=word[i]-97;
             			prev=tmp;
             			tmp=tmp->charecter[k];
             			delete prev;
             			flg=1;
             		}
             	     
             	}
             	else
             	tmp->count--;
             	if(flg==1)
             	break;
        }
        root->count--;
        cout<<"Word Deleted Successfully!!!\n";
        cout<<endl;
}

void TrieNode::ModifyWord(string word,TrieNode *root)
{
    	if(root==NULL)
	{
	     cout<<"List is Empty\n";
	     return;
	}
	TrieNode* tmp=root;
	TrieNode* prev=NULL;
	for(int i=0;i<word.size();i++)
        {
        	int k=word[i]-97;
        	if(tmp->charecter[k]==NULL)
        	{
        		cout<<"Word is Not Present in the Dictionary\n";
        		return;
        	}
        	tmp=tmp->charecter[k];
        }
        map<string,vector<string> >mp1;
        cout<<"Enter New Details for -> "<<word;
        cout<<"Enter Definition:- ";
        while(1)
        {
            string str;
            cin>>str;
            if(str==".")
                break;
            mp1["Definition"].push_back(str);
        }
        cout<<"Enter Origin:- ";
        while(1)
        {
            string str;
            cin>>str;
            if(str==".")
                break;
            mp1["Origin"].push_back(str);
        }
        cout<<"Enter Synonym:- ";
        while(1)
        {
            string str;
            cin>>str;
            if(str==".")
                break;
            mp1["Synonym"].push_back(str);
        }
        cout<<"Enter Antonym:- ";
        while(1)
        {
            string str;
            cin>>str;
            if(str==".")
                break;
            mp1["Antonym"].push_back(str);
        }
        cout<<"Word Modified Successfully\n";
        cout<<"\n";
        tmp->mp=mp1;
}

void TrieNode::Count_No_Words(TrieNode *root)
{
	if(root==NULL)
		return;
	int cnt=root->count;
	cout<<"Number of Words in Dictionary:- "<<cnt<<endl;
}

#endif
