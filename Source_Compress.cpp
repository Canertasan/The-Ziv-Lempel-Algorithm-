/*
The Ziv-Lempel Algorithm(compressor and uncompressor)
Ziv-Lempel is an example of an adaptive data compression algorithm.
This string is composed of the characters 'a' and 'b' for this code.
example: aaabbbbbbaabaaba
Initially 'a' is assigned the code 0 and 'b' the code l. 
Each dictionary entry has two fields: key and code.
Code 0 1 2 3 4 5 6 7
Key  a b ............

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinaryTree.h"

using namespace std;


int main() 
{
	string temp = "";
	string entered = "";
	ifstream reader;
	ofstream writer;
	writer.open("compout.txt");
	reader.open("compin.txt");
	while(getline(reader,temp)) // this gets all inputs.
	{
		entered += temp;
	}
	btree<string> dictionary;
	//
	int i=0;//starting point on substr
	int j=2;// j is the move index
	int size = 256;
	while(i < entered.length())
	{
		if(entered.length()==1 || entered.length()==0)
		{
			writer << entered;
			break;
		}
		else
		{
			while(entered.length() >= (i+j))
			{
				if(dictionary.search(entered.substr(i,j)) == nullptr)
				{
					dictionary.insert(entered.substr(i,j),size);
					size++;
					j--;
					if(entered.substr(i,j).length()==1)
					{
						writer << int(unsigned char(entered.at(i))) << " " ;
						i+=j;
					}
					else
					{
						writer << dictionary.keyVal(entered.substr(i,j)) << " ";
						i+=j;
					}
					break;
				}
				j++;
			}
			if(entered.length() < (i+j))
			{
				if(dictionary.search(entered.substr(i,entered.length()-i)) == nullptr)
				{
					dictionary.insert(entered.substr(i,entered.length()-i),size);
					size++;
					if(entered.substr(i,entered.length()-i).length()==1)
					{
						writer << int(unsigned char(entered.at(i))) << " " ;
						i+=j;
						break;
					}
				}
				else
				{
					writer << dictionary.keyVal(entered.substr(i,entered.length()-i)) << " ";
					i+=j;
					break;
				}
			}

			j=2;
		}

	}

	writer.close();
	reader.close();
	return 0;
}
