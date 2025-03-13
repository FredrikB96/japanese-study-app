#include "worditem.h"

WordItem::WordItem(int id, std::string Kanji,std::string kana,  std::string Translation, std::string Sentence, std::string SentanceTS)
{
    this->ID = id;
    this->Kanji = Kanji;
    this->Kana = kana;
    this->Translation = Translation;
    this->Sentence = Sentence;
    this->SentenceTS = SentanceTS;
}

int WordItem::getID()
{
    return this->ID;
}

std::string WordItem::getKanji()
{
    return this->Kanji;
}

std::string WordItem::getTranslation()
{
    return this->Translation;
}

std::string WordItem::getKana()
{
    return this->Kana;
}

std::string WordItem::getSentence()
{
    return this->Sentence;
}

std::string WordItem::getSentencets()
{
    return this->SentenceTS;
}

