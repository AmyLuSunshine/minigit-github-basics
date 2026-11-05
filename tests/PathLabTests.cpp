#include "PathLab.hpp"
#include <iostream>
#include <fstream>
#include <string>


bool check(bool condition, const char *message)
{
    if (!condition)
    {
        std::cerr << "FAILED: " << message << '\n';
        return false;
    }
    return true;
}

int main()
{
    // Baseline smoke check: the project and CTest wiring work before students
    // begin the path Issues. Add focused assertions with each Issue.
    std::filesystem::path sample = "course/repo";
    if (sample.filename() != "repo")
    {
        std::cerr << "path smoke check failed\n";
        return 1;
    }

    const std::filesystem::path root = "course/repo";
    // issue 1 test:
    if (!check(minigit::metadataDirectory(root) == root / ".minigit",
               "metadataDirectory should append .minigit to the root path"))
    {
        return 1;
    }

    // issue 2 test:
    // Normal root
    if (!check(minigit::getHead(root) == root / ".minigit" / "HEAD",
               "metadataDirectory should append HEAD to the root / '.minigit' path"))
    {
        // std::cout << "test case pass!";
        return 1;
    }
    // Nested root
    const std::filesystem::path nestedRoot = "course/repo/lab12";
    if (!check(minigit::getHead(nestedRoot) == nestedRoot / ".minigit" / "HEAD",
               "metadataDirectory should append HEAD to the root / '.minigit' path"))
    {
        // std::cout << "nest root test case pass!";
        return 1;
    }

        // issue 3 test:
        // Issue 3 test:
        const std::filesystem::path testFile =
        "build/issue3-test/nested/output.txt";

        if (!check(minigit::writeTextFile(testFile, "Hello MiniGit"),
           "writeTextFile should create parent directories and write text")) {
            return 1;
    }

            std::ifstream input(testFile);
            std::string contents;
            std::getline(input, contents);

        if (!check(contents == "Hello MiniGit",
           "writeTextFile should save the exact text")) {
            return 1;
    }

    std::filesystem::remove_all("build/issue3-test");


    std::cout << "PathLab smoke check passed\n";
    return 0;
}
