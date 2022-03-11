#include "catttcattt.h"

cat::cat()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

size_t cat::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string cat::downloaddcattpicss(int count)
{
    // create directory.
    std::filesystem::create_directory("WDEFWGTBRHYTEGEFWQDWEFWTRH5YJTGFDXW.");

    // urls.
    std::string url = baseurl + "img";

    // get all links.
    std::string content;
    std::vector<std::string> urls;

    for (int result = 0; result < count; result++)
    {
        {
            curl = curl_easy_init();
            if (curl)
            {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
                curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

                // callback
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);

                // send
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }
            curl_global_cleanup();


            try
            {
                auto json = json::parse(content);
                std::string resultt = json["url"].get<std::string>();
                urls.emplace_back(resultt);
                content.clear();

                std::cout << "\ncatt pic " << resultt << " setted ready\n";
               
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            }
            catch (json::parse_error& ex)
            {
                std::cerr << "\nparse error at byte " << ex.byte << ":(\n";
            }
        }

    }

    // download picture.
    for (auto& s : urls)
    {
        {
            if (download(s))
            {
                std::cout << "\ndownloaded " << s << "\n";
            }
            else
            {
                std::cout << "\nFAILEDD :(( " << s << "\n";
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }


    std::string resultt = "\n downloaded " + count + std::string(" cattpicss\n");
    return resultt;
}

bool cat::download(std::string link)
{
    std::string s = "WDEFWGTBRHYTEGEFWQDWEFWTRH5YJTGFDXW\\" + random_string(4) + ".jpg";
    FILE* file = fopen(s.c_str(), "wb");
    if (!file)
    {
        std::cout << "failed\n";
        return false;
    }
    

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());   
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);     
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    else
    {
        return false;
    }

    curl_global_cleanup();
    fclose(file);

    return true;
}

std::string cat::Get8Ball()
{
	std::string url = baseurl + "8ball";
	std::string content;
 
    {
        curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

            // callback
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);

            // send
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
	}

    auto json = json::parse(content);
   
	std::string result;
    result = json["response"].get<std::string>();
	return result;
}


std::string cat::WhattDoooCattboyySayyNoww()
{
    std::string url = baseurl + "catboy";
    std::string content;

    {
        curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_0);
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

            // callback
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);

            // send
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }

    auto json = json::parse(content);

    std::string result;
    result = json["response"].get<std::string>();
    return result;
}

std::string cat::random_string(std::size_t length)
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    static std::default_random_engine rng(std::time(nullptr));
    static std::uniform_int_distribution<std::size_t> distribution(0, alphabet.size() - 1);

    std::string str;
    while (str.size() < length) str += alphabet[distribution(rng)];
    return str;
}