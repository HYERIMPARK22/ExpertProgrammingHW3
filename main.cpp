#include "CInstagram.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void ReadInsta(const string strFilename, CInstagram &CObj);


int main()
{
	CInstagram Insta1;
	string strEvaldata1;
	strEvaldata1 = "my-instagram-1.txt";
	ReadInsta(strEvaldata1, Insta1);
	cout << Insta1;

	CInstagram Insta2, Insta3;
	vector<CInstagram> pInstagramObj;
	string strEvaldata2, strEvaldata3;
	strEvaldata2 = "my-instagram-2.txt";
	strEvaldata3 = "my-instagram-3.txt";

	pInstagramObj.push_back(Insta1);
	ReadInsta(strEvaldata2, Insta2);
	pInstagramObj.push_back(Insta2);

	ReadInsta(strEvaldata3, Insta3);
	pInstagramObj.push_back(Insta3);
	
	cout << Insta2;
	cout << Insta3;


}

void ReadInsta(const string strFilename, CInstagram &CObj)
{
	ifstream myReadFile;
	string strId, strHashtag, strComment, strReply, strEnter;
	const int num = 10;
	string positiveWords[num] = { "����","�η�","�ְ�","�ٻ�","���","��õ","������","��û","����","����" };
	string negativeWords[num] = {"����","¥","���","��ģ��","����","����","����","���Ʊ�","����","�״�"};

	char hashFlag;
	int nPositive, nNegative;
	int nPosTotal, nNegTotal;
	myReadFile.open(strFilename);
	myReadFile >> strId;
	CObj.setStrId(strId);

	do
	{
		myReadFile >> hashFlag;
	} while (hashFlag != '#');
	myReadFile >> strHashtag;
	CObj.setStrHashtag(strHashtag);
	//cout << strHashtag << endl;
	getline(myReadFile, strComment);
	//cout << strComment << endl;

	while (myReadFile.peek() != EOF)
	{
		getline(myReadFile, strEnter);
		getline(myReadFile, strReply);
		//cout << strReply << endl;
		for (int i = 0; i < num; i++)
		{
			if (strReply.find(positiveWords[i]) != string::npos)
			{
				nPositive = CObj.getnPositive();
				CObj.setnPositive(++nPositive);
				nPosTotal = CObj.getnPosTotal();
				CObj.setnPosTotal(++nPosTotal);
			}
			if (strReply.find(negativeWords[i]) != string::npos)
			{
				nNegative = CObj.getnNegative();
				CObj.setnNegative(++nNegative);
				nNegTotal = CObj.getnNegTotal();
				CObj.setnNegTotal(++nNegTotal);
			}
		}
	}
	//cout << "< " << strFilename << " >" << endl;
	//cout << CObj;

	myReadFile.close();
}

ostream& operator <<(ostream& outputStream, const CInstagram& CObj)
{
	cout << "-----------------------------------------------------" << endl;
	cout << "ID : " << CObj.m_strId << endl;
	cout << "ù��° Hashtag : " << CObj.m_strHashtag << endl;
	cout << "�������� �ܾ� : " << CObj.m_nPositive << "��" << endl;
	cout << "�������� �ܾ� : " << CObj.m_nNegative << "��" << endl;
	cout << "* �������� �ܾ� �� " << CObj.m_nPosTotal << "��" << endl;
	cout << "* �������� �ܾ� �� " << CObj.m_nNegTotal << "��" << endl;
	cout << "-----------------------------------------------------" << endl << endl;
	return outputStream;
}
