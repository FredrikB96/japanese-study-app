#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include "util.h"

using namespace std;
namespace fs = std::filesystem;

class FileManager{

public:
static std::string Initialize()
{
    return GetModules();
}

static bool SaveFile(std::string filename,  std::string *msg)
{
    return 0;
}

static std::vector<Word> LoadFile(std::string filepath,char delimiter)
{

    auto iFile = std::unique_ptr<std::ifstream, void(*)(std::ifstream*)>(
        new std::ifstream(filepath),
        [](std::ifstream* f) {
            if (f->is_open()) f->close();
            delete f;
        }
        );

    // Reset the stream position
    iFile->clear();  // Clear EOF flag
    iFile->seekg(0, std::ios::beg);

    std::vector<Word> words;
    try {
        std::string input_Data;
        while (std::getline(*iFile, input_Data)) {
            std::istringstream iss(input_Data);
            std::string field;
            Word word;

            std::getline(iss, word.word, '\t');  // Field 1: Word
            std::getline(iss, word.reading, '\t');  // Field 2: Reading
            std::getline(iss, word.meaning, '\t');  // Field 3: Meaning
            std::string temp;
            std::getline(iss, temp, '\t');  // Field 4: Word Group
            word.word_group = decideWordGroup(temp);
            std::getline(iss, word.sentence, '\t');  // Field 5: Sentence
            std::getline(iss, word.sentence_translation, '\t');  // Field 6: Sentence Translation

            words.push_back(word);
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "General error: " << e.what() << '\n';
    }
    catch (...) {
        std::cerr << "Unknown critical error occurred!" << '\n';
    }
    return words;
}



private:
static std::string GetModules()
{
    std::string Modules = "";
    std::string path = "C:/Users/blomg/Documents/QT/Testing_Projects/Japanese_Study/Modules";
    for (const auto & entry : fs::directory_iterator(path))
    {
        Modules.append(std::string(entry.path().generic_string()+"\n").replace(0,entry.path().generic_string().find_last_of("/")+1,""));
    }

    return Modules;
}

static int decideWordGroup(std::string word) {
    int group = 0;

    if (word.find("Noun ") != std::string::npos) {
        group |= (1 << NOUN);  // Add Noun flag
    }
    if (word.find("Adverb") != std::string::npos) {
        group |= (1 << ADVERB);
    }
    if (word.find("Ichidan verb") != std::string::npos) {
        group |= (1 << I_VERB);
    }
    if (word.find("Godan verb") != std::string::npos) {
        group |= (1 << G_VERB);
    }
    if (word.find("NA-adjective") != std::string::npos) {
        group |= (1 << NA_ADJ);
    }
    if (word.find("I-adjective") != std::string::npos) {
        group |= (1 << I_ADJ);
    }

    return group;  // Multiple flags can now coexist
}
};
