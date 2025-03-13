#pragma once
#include <string>
#define UTIL_HEADER


struct Word {
    std::string word;
    std::string reading;
    std::string meaning;
    int word_group;
    std::string sentence;
    std::string sentence_translation;
};

enum WordGroup {
    NOUN = 0,   // 00001
    ADVERB = 1,   // 00010
    I_VERB = 2,   // 00100
    G_VERB = 3,   // 01000
    NA_ADJ = 4,   // 00010
    I_ADJ = 5    // 100000
};

