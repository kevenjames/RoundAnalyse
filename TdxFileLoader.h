#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class TdxFileLoader
{
public:
	TdxFileLoader(void);
	TdxFileLoader(string strPathName);
	~TdxFileLoader(void);

private:
	string m_strFilePathName;

};

