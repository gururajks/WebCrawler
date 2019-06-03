#pragma once

#include<string>
#include<iostream>
#include<regex>
#include<vector>
using namespace std;

class HTMLParser
{
public:
	string getPage(string body);
	void modifyURL(string url, bool removeOnline = true);
	vector<string> getHTMLLinks(string body);
	void cleanUpHref(string& url);
};