#pragma once
#include <iostream>
#include <string>
using namespace std;

class CInstagram
{
public:
	CInstagram();
	CInstagram(string strId, string strHashtag, int nPositive, int nNegative);
	~CInstagram();
	string getStrId();
	string getStrHashtag();
	int getnPositive();
	int getnNegative();
	int getnPosTotal();
	int getnNegTotal();

	void setStrId(string strId);
	void setStrHashtag(string strHashtag);
	void setnPositive(int nPositive);
	void setnNegative(int nNegative);
	void setnPosTotal(int nPosTotal);
	void setnNegTotal(int nNegTotal);

	friend ostream& operator <<(ostream& outputStream, const CInstagram& CObj);

private:
	string m_strId;
	string m_strHashtag;
	int m_nPositive;
	int m_nNegative;

	static int m_nPosTotal;
	static int m_nNegTotal;

};

