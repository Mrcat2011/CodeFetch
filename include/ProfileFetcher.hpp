#ifndef PROFILE_FECTHER_HPP
#define PROFILE_FECTHER_HPP

#include <string>

class ProfileFetcher {
    public:
        virtual ~ProfileFetcher() = default;
        virtual void fetch(const std::string& handle) = 0;
};

#endif //!PROFILE_FECTHER_HPP