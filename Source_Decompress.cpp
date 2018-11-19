#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"

using namespace std;


int main() 
{
	vector <int> vecNum;
	string text = "";
	string num = "";
	ifstream reader;
	ofstream writer;
	reader.open("compout.txt");
	writer.open("decompout.txt");
	while(getline(reader,text))// taking all int strings in a vector.
	{
		istringstream iss(text);
		while(iss >> num)
		{
			vecNum.push_back(stoi(num)); // 
		}
	}
	if(vecNum.size()==0)
	{
		writer.close();
		reader.close();
		return 0;
	}
	int size = 256;
	btree<int,string> BT;
	writer << char(vecNum[0]);
	int current = 0;
	int prev = 0 ;
	string currentS="";
	string prevS(1,char(vecNum[0]));
	string add="";
	for(int i = 0; i < vecNum.size()-1;i++)
	{

		prev=vecNum[i];
		current = vecNum[i+1];
		if(vecNum[i+1]<256)// x is just char;0
		{

			writer << char(current);
			currentS="";
			currentS.push_back(char(current));
			add=prevS+currentS;
			BT.insert(size,add);
			size++;
			prevS=currentS;
		}
		else if(!(BT.search(current))) // x not in dictionary
		{

			add = prevS+prevS.at(0);
			currentS=add;
			writer << add;
			BT.insert(current,add);
			size++;
			prevS=currentS;
		}
		else  // x is dictionary
		{

			currentS=BT.keyVal(current);
			add=prevS+currentS.at(0);
			BT.insert(size,add);
			size++;
			writer << BT.keyVal(current);
			prevS=currentS;
		}
	}
	if(vecNum.size()==1)
	{
		cout << prevS;
	}



	writer.close();
	reader.close();
	return 0;
}