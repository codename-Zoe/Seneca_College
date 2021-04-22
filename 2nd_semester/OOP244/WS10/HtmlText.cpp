#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HtmlText.h"

using namespace std;
namespace sdds
{
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
        if (title != nullptr) {
            m_title = nullptr;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        else {
            m_title = nullptr;
        }
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    HtmlText::HtmlText(const HtmlText& html) : Text(html){
        if (html.m_title != nullptr) {
            m_title = nullptr;
            m_title = new char[strlen(html.m_title) + 1];
            strcpy(m_title, html.m_title);
        }
    }

    HtmlText& HtmlText::operator=(const HtmlText& html) {
        if (this != &html) {
            if (html.m_title != nullptr) {
                if (m_title != nullptr) {
                    delete[] m_title;
                    m_title = nullptr;
                }
                m_title = new char[strlen(html.m_title) + 1];
                strcpy(m_title, html.m_title);
                Text::operator=(html);
            }
        }
        return *this;
    }

    void HtmlText::write(std::ostream& os) const {
        int i = 0;
        bool multiSpace = false;
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        while(Text::operator[](i) != '\0') {
            char ch = Text::operator[](i);
            if (ch == ' ') {
                if (multiSpace == true) {
                    os << "&nbsp;";
                }
                else {
                    multiSpace = true;
                    os << " ";
                }
            }
            else if (ch == '<') {
                os << "&lt;";
                multiSpace = false;
            }
            else if (ch == '>') {
                os << "&gt;";
                multiSpace = false;
            }
            else if (ch == '\n') {
                os << "<br />\n";
                multiSpace = false;
            }
            else {
                multiSpace = false;
                os << ch;
            }
            i++;
        }
        os << "</body>\n</html>";
    }
}