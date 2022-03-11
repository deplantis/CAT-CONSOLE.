#pragma once
#include <string>
#include <windows.h>
#include <filesystem>

#include <iostream>

#include <chrono>
#include <thread>
#include <random>

#define CURL_STATICLIB
#include <curl/curl.h>

#include <nlohmann/json.hpp>
using nlohmann::json;

#pragma warning(disable : 4996)

class cat
{
public:
	cat();
	std::string downloaddcattpicss(int count);
	std::string Get8Ball();
	std::string WhattDoooCattboyySayyNoww();
private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
	std::string random_string(std::size_t length);
	bool download(std::string link);
	std::string baseurl = "https://api.catboys.com/";

	// curl.
	CURL *curl;
	CURLcode res;
};