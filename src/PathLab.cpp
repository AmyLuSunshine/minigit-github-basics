#include "PathLab.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>
#include <fstream>

namespace minigit {
    // Implement the focused behavior described by the active Issue.
    std::filesystem::path metadataDirectory(const std::filesystem::path& root) {
        return root / ".minigit";
    }

    std::filesystem::path getHead(const std::filesystem::path& root) {
        return metadataDirectory(root) / "HEAD";
    }

    
bool createparentdirectories(const std::filesystem::path& path) {
    std::filesystem::path parent = path.parent_path();

    if (parent.empty()) {
        return true;
    }

    std::error_code error;
    std::filesystem::create_directories(parent, error);

    if (error) {
        std::cerr << "Failed to create directories: "
                  << error.message() << '\n';
        return false;
    }

    return std::filesystem::is_directory(parent, error) && !error;
}

    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    file <<text;
    return file.good();
}
}   // namespace minigit
