#pragma once
#include<string>


class CurlResult 
{
public:
	long response_code;
	std::string response_body;

	CurlResult(long response_code, std::string response_body) :
		response_code(response_code), response_body(response_body) {
	}
};

class CurlWrapper 
{
public:
	static CurlResult request(std::string uri);
	static size_t handle(char *data, size_t size, size_t nmemb, std::string *output);
};

