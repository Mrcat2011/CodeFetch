#ifndef CODEFORCES_FETCHER_HPP
#define CODEFORCES_FETCHER_HPP

#include "ProfileFetcher.hpp"

class CodeforcesFetcher : public ProfileFetcher {
    public:
        void fetch(const std::string& handle) override;
    private:
        static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp); 
};


#endif //!CODEFORCES_FETCHER_HPP