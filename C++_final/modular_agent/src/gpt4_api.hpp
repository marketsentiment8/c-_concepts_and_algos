#ifndef GPT4_API_HPP
#define GPT4_API_HPP

#include <string>
#include <vector>
#include <tuple>

namespace GPT4_API {
    std::tuple<std::string, std::string, std::vector<std::string>> generate_modified_code();
}

#endif // GPT4_API_HPP
