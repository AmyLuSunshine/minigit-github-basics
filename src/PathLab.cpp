#include "PathLab.hpp"
#include <filesystem>
#include <iostream>
#include <string>


namespace minigit {
    // Implement the focused behavior described by the active Issue.
    std::filesystem::path metadataDirectory(const std::filesystem::path& root) {
        return root / ".minigit";
    }

    std::filesystem::path getHead(const std::filesystem::path& root) {
        return metadataDirectory(root) / "HEAD";
    }

    bool createparentdirectories(const std::filesystem::path &path) {
        std::filesystem::path parent = path.parent_path();
        // create missing parent directories when needed
        if (!parent.empty() && !std::filesystem::exists(parent)) {
            std::cout << "Creating missing parent directories for: " << parent << std::endl;

            return std::filesystem::create_directories(parent);
        }
        return true;
    }
    bool writeTextFile(const std::filesystem::path& path, const std::string& text) {
    if (!createparentdirectories(path)) {
        return false;
    }

    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    file <<text;
    return file.good();
}
}   // namespace minigit
