#include "../include/CodeforcesFetcher.hpp"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json= nlohmann::json;

size_t CodeforcesFetcher::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size*nmemb;
}

void CodeforcesFetcher::fetch(const std::string& handle) {
    CURL* curl = curl_easy_init();

    if (!curl) return;

    std::string readBuffer;
    std::string url = "https://codeforces.com/api/user.info?handles=" + handle;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    if (curl_easy_perform(curl) == CURLE_OK) {
        try {
            auto data = json::parse(readBuffer);

            if (data["status"] == "OK") {
            auto u = data["result"][0];
            

            std::string rank = u.value("rank", "unranked");
            int rating = u.value("rating", 0);
            int maxRating = u.value("maxRating", 0);
            std::string firstName = u.value("firstName", "");
            std::string lastName = u.value("lastName", "");
            std::string country = u.value("country", "Unknown");
            int contribution = u.value("contribution", 0);

            std::string RENDER_COLOR = "\033[0;37m"; 
        
            if (rating >= 2400) {
                RENDER_COLOR = "\033[1;31m"; 
            } else if (rating >= 2100) {
                RENDER_COLOR = "\033[1;33m"; 
            } else if (rating >= 1900) {
                RENDER_COLOR = "\033[1;35m"; 
            } else if (rating >= 1600) {
                RENDER_COLOR = "\033[1;34m"; 
            } else if (rating >= 1400) {
                RENDER_COLOR = "\033[1;36m";
            } else if (rating >= 1200) {
                RENDER_COLOR = "\033[1;32m";
            } else if (rating > 0) {
                RENDER_COLOR = "\033[1;30m"; 
            }
            
            std::string RESET = "\033[0m";
            std::string BOLD = "\033[1m";

            std::cout << "\n " << RENDER_COLOR << "┌──────────────────────────────────────────────────────────┐" << RESET << std::endl;
            
            std::cout << "  " << RENDER_COLOR << "👤 " << BOLD << rank << " " << handle << RESET << std::endl;
            std::cout << " " << RENDER_COLOR << "├──────────────────────────────────────────────────────────┤" << RESET << std::endl;

            std::cout << "  " << BOLD << "📇 Full name:    " << RESET << firstName << " " << lastName << std::endl;
            std::cout << "  " << BOLD << "🚩 From:         " << RESET << "\033[32m" << country << RESET << std::endl;
            std::cout << "  " << BOLD << "📈 Rating:       " << RESET << RENDER_COLOR << rating << RESET << " (max. " << maxRating << ", " << rank << ")" << std::endl;
            
            std::string contribColor = (contribution >= 0) ? "\033[32m+" : "\033[31m";
            std::cout << "  " << BOLD << "🌟 Contribution: " << RESET << contribColor << contribution << RESET << std::endl;

            std::cout << " " << RENDER_COLOR << "└──────────────────────────────────────────────────────────┘" << RESET << "\n" << std::endl;
        }   else {
                std::cerr << "Handle didn'n find" << std::endl;
            }
        } catch (...) {
            std::cerr << "ERROR" << std::endl;
        }
    }

    curl_easy_cleanup(curl);
    
}