#pragma once
#include<string>
#include<vector>

class PageGraph;

class Crawler
{
public:
	enum LEVEL
	{
		LEVEL_1,
		LEVEL_2,
		ALL
	};

	Crawler(LEVEL level = LEVEL::LEVEL_1, bool outside = false);
	void spawnThreads(std::vector<std::string> urls);


private:
	LEVEL m_level;
	bool m_outside;
	PageGraph* root;
};
