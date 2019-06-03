// WebCrawler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include<thread>
#include <vector>
#include<cmath>
#include<algorithm>
#include<chrono>
#include<regex>
#include "CurlWrapper.h"
using namespace std;

class Encrypt
{
	int m_count;
	bool m_increment;
public:
	Encrypt(bool increment, int count) : m_increment(increment), m_count(count)
	{
	}
	void operator()(string& input)
	{
		for_each(input.begin(), input.end(), [&, this](char& c) {
			if (m_increment)
				c += m_count;
			else
				c -= m_count;
		});
	}
};



void createMessage(string data, Encrypt encrypt)
{
	encrypt(data);
	cout << data << endl;
}

int MOD = (int)pow(10, 7) + 9;
void computeProduct(int start, int end, vector<int>& productVector, vector<vector<int>> matrix)
{
	for (int i = start; i < end; i++)
	{
		int product = 1;
		for (int j = 0; j < matrix[i].size(); j++)
		{
			product = (product % MOD) * (matrix[i][j] % MOD ) % MOD;
		}
		productVector[i] = product;
	}
}

void crawl_url(std::string uri) {
	CurlResult result = CurlWrapper::request(uri);

	std::cout << result.response_body << std::endl;
}
void checkRegexSupport() {
	try {
		std::regex_match("123", std::regex("^(0|[1-9][0-9]*)$"));
	}
	catch (std::regex_error& e) {
		std::cout << "This project requires regex support." << std::endl
			<< "GCC users need version 4.9.0 or later." << std::endl
			<< "CLang users need 3.3 or later." << std::endl;
		exit(1);
	}
}
int main()
{	
	string url = "www.google.com";
	crawl_url(url);
	
}



/*int n = 2000;
string data = "hello world!";
vector<vector<int>> matrix(n, vector<int>(n, 0));
unsigned int count = 1;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		matrix[i][j] = count % MOD;
		count++;
	}
}
auto start = chrono::system_clock::now();
vector<int> productVector(n, 0);
vector<int> productVectorCopy(n, 0);
thread th1(computeProduct, 0, n / 2, ref(productVector), matrix);
thread th2(computeProduct, n / 2 + 1, n, ref(productVector), matrix);

th1.join();
th2.join();
auto end = chrono::system_clock::now();
int sum = 0;
for_each(productVectorCopy.begin(), productVectorCopy.end(), [&](int item) {
	sum += item;
});
std::chrono::duration<double> elapsed_seconds = end - start;
cout << "Elapsed Time:" << elapsed_seconds.count() << endl;
cout << "Sum:" << sum << endl;
return 0; */

