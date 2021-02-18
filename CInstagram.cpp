#include "CInstagram.h"
#include <string>

int CInstagram::m_nPosTotal = 0;
int CInstagram::m_nNegTotal = 0;

CInstagram::CInstagram()
{
	m_strId = "Default";
	m_strHashtag = "Default";
	m_nPositive = 0;
	m_nNegative = 0;
	m_nPosTotal = 0;
	m_nNegTotal = 0;

}


CInstagram::~CInstagram()
{
}

CInstagram::CInstagram(string strId, string strHashtag, int nPositive, int nNegative)
{
	m_strId = strId;
	m_strHashtag = strHashtag;
	m_nPositive = nPositive;
	m_nNegative = nNegative;
	m_nPosTotal += nPositive;
	m_nNegTotal += nNegative;
}


string CInstagram::getStrId()
{
	return m_strId;
}
string CInstagram::getStrHashtag()
{
	return m_strHashtag;
}
int CInstagram::getnPositive()
{
	return m_nPositive;
}
int CInstagram::getnNegative()
{
	return m_nNegative;
}
int CInstagram::getnPosTotal()
{
	return m_nPosTotal;
}
int CInstagram::getnNegTotal()
{
	return m_nNegTotal;
}
void CInstagram::setStrId(string strId)
{
	m_strId = strId;
}
void CInstagram::setStrHashtag(string strHashtag)
{
	m_strHashtag = strHashtag;

}
void CInstagram::setnPositive(int nPositive)
{
	m_nPositive = nPositive;

}
void CInstagram::setnNegative(int nNegative)
{
	m_nNegative = nNegative;

}

void CInstagram::setnPosTotal(int nPosTotal)
{
	m_nPosTotal = nPosTotal;
}
void CInstagram::setnNegTotal(int nNegTotal)
{
	m_nNegTotal = nNegTotal;
}

