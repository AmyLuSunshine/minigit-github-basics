#include "PathLab.hpp"
#include <fstream>
#include <iterator>

namespace minigit {
    std::filesystem::path metadataDirectory(const std::filesystem::path& root) {
        return root / ".minigit";
    }

    std::filesystem::path getHead(const std::filesystem::path& root) {
        return metadataDirectory(root) / "HEAD";
    }

    bool readTextFile(const std::filesystem::path& path, std::string& text) {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) {
            return false;
        }

        std::string contents((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());
        if (file.bad()) {
            return false;
        }

        text = contents;
        return true;
    }
}