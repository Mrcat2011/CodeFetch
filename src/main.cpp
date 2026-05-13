#include "../include/CodeforcesFetcher.hpp"
#include <iostream>
#include <memory>
#include <string>

int main (int argc, char** argv) {
    if (argc < 3) {
        std::cout << "\nUsage: ./profile <site> <username>" << std::endl;
        std::cout << "Sites: codeforces\n" << std::endl; 
        return 1;
    }

    std::string site = argv[1];
    std::string handle = argv[2];

    std::unique_ptr<ProfileFetcher> fetcher;

    if (site == "codeforces" || site == "cf") {
        fetcher = std::make_unique<CodeforcesFetcher>();
    } else {
        std::cerr << "❌ Error: Site '" << site << "' is not supported." << std::endl;
        return 1;
    }

    fetcher->fetch(handle);

    return 0;
}