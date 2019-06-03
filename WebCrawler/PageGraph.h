#pragma once
#include<string>
#include<vector>
using namespace std;

class PageGraph
{
public:
	vector<string> m_urls;
	vector<PageGraph*> m_neighbors;
};