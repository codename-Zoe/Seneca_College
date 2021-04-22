#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "TextFile.h"
using namespace std;
namespace sdds
{
    Line::Line() {
        m_value = nullptr;
    }

    Line::~Line() {
        delete[] m_value;
    }

    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (isCopy) {
            char chr[] = "C_";
            delete[] m_filename;
            m_filename = new char[strlen(fname) + strlen(chr) + 1];
            strcpy(m_filename, chr);
            strcat(m_filename, fname);
        }
        else {
            delete[] m_filename;
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        int count = 0;
        ifstream  file(m_filename);
        while(file){
            if (file.get() == '\n') {
               count++;
            }
        }
        m_noOfLines = count;
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        else {
            m_noOfLines += 1;
        }
    }

    void TextFile::loadText() {
        int i = 0;
        string line;
        if (m_filename != nullptr) {
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];
            ifstream file(m_filename);
            if (file.is_open()) {
                while (getline(file, line)) {
                    m_textLines[i] = line.c_str();
                    i++;
                }
                m_noOfLines = i;
            }
        }
    }

    void TextFile::saveAs(const char* fileName)const {
        ofstream file(fileName);
        if(file.is_open()){
            for (unsigned i = 0; i < m_noOfLines; i++) {
                file << m_textLines[i] << endl;
            }
        }
    }

    TextFile::TextFile(unsigned pageSize) {
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize){
        m_pageSize = pageSize;
        setEmpty();
        ifstream file(filename);
        if (file) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& text) {
        m_pageSize = text.m_pageSize;
        setEmpty();
        if (text) {
            setFilename(text.m_filename, true);
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& text) {
        if (this != &text) {
            delete[] m_textLines;
            m_textLines = nullptr;
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        delete[] m_filename;
    }

    unsigned TextFile::lines()const {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr)const {
        unsigned count = 0;
        char input = 'x';
        if (*this) {
            ostr << m_filename << endl;
            ostr.fill('=');
            ostr.width(strlen(m_filename));
            ostr << "=" << endl;
            for (unsigned i = 0; i < m_noOfLines; i++) {
                ostr << m_textLines[i] << endl;
                count++;
                if(count == m_pageSize){
                    ostr << "Hit ENTER to continue...";
                    while (getchar() != '\n');
                    if (input != '\n') {
                        input = getchar();
                    }
                    count = 0;
                }
            }            
        }
        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string temp;
        istr >> temp;
        setFilename(temp.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned index)const {
        const char* txt = NULL;
        if (*this) {
            if(index > m_noOfLines -1) {
                index -= m_noOfLines;
            }
            txt = m_textLines[index];
        }
        return txt;
    }

    TextFile::operator bool()const {
        if (m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0 && m_pageSize != 0) {
            return true;
        }
        else {
            return false;
        }
    }

    const char* TextFile::name()const {
        return m_filename;
    }

    ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }

    istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }

}