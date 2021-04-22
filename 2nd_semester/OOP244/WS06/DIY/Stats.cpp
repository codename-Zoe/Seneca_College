#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Stats.h"

using namespace std;
namespace sdds
{    
    void Stats::setFilename(const char* fname, bool isCopy) {
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

    void Stats::setNoOfNum() {
        int count = 0;
        char chr;
        ifstream  file(m_filename);
        if(file.is_open()){
            while (!file.eof()) {
                chr = file.get();
                if (chr == ',') {
                    count++;
                }
            }
            countNum = count;
            if (countNum == 0) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                countNum += 1;
            }
        }
    }

    void Stats::loadText() {
        string line;
        int i = 0;
        if (m_filename != nullptr) {
            if (countNum > 0) {
                delete[] num;
                num = new double[countNum];
                ifstream file(m_filename);
                if (file.is_open()) {
                    while (getline(file, line, ',')) {
                        num[i] = stod(line);
                        i++;
                    }
                }
                countNum = i;
            }
        }
    }

    void Stats::saveAs(const char* fileName)const {
        ofstream file(fileName);
        if (file.is_open()) {
            for (unsigned i = 0; i < size(); i++) {
                if (i == size() - 1) {
                    file << num[i];
                }
                else {
                    file << num[i] << ",";
                } 
            }
        }
    }

    Stats::Stats(const Stats& stats) {
        columnWidth = stats.columnWidth;
        noOfColumns = stats.noOfColumns;
        precision = stats.precision;
        setEmpty();
        if (stats) {
            setFilename(stats.name(), true);
            stats.saveAs(m_filename);
            setNoOfNum();
            loadText();
        }
    }

    Stats& Stats::operator=(const Stats& stats) {
        if (this != &stats) {
            if (stats && *this) {
                columnWidth = stats.columnWidth;
                noOfColumns = stats.noOfColumns;
                precision = stats.precision;
                stats.saveAs(m_filename);
                setNoOfNum();
                loadText();
            }
        }
        return *this;
    }

    void Stats::setEmpty() {
        delete[] num;
        num = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        countNum = 0;
    }

    Stats::Stats(unsigned width, unsigned numColumn, unsigned pre) {
        columnWidth = width;
        noOfColumns = numColumn;
        precision = pre;
        setEmpty();
    }

    Stats::Stats(const char* fname, unsigned width, unsigned numColumn, unsigned pre) {
        columnWidth = width;
        noOfColumns = numColumn;
        precision = pre;
        setEmpty();
        ifstream file(fname);
        if (fname != nullptr) {
            setFilename(fname);
            setNoOfNum();
            loadText();
        }
    }

    Stats::~Stats() {
        delete[] num;
        delete[] m_filename;
    }

    double& Stats::operator[](unsigned idx) {
        if (*this) {
            if (idx > countNum - 1) {
                idx -= (countNum);
            }
            return num[idx]; 
        }
        else {
            return dummy;
        }
    }

    double Stats::operator[](unsigned idx)const {
        double value;
        if (*this) {
            if (idx > countNum - 1) {
                idx -= countNum;
            }
            value = num[idx];
        }
        else {
            value = 0.0;
        }
        return value;
    }

    Stats::operator bool()const {
        if (num != nullptr && m_filename != nullptr && countNum != 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void Stats::sort(bool ascending) {
        double temp;
        if (*this) {
            if (ascending) {
                for (unsigned i = countNum - 1; i > 0; i--) {
                    for (unsigned j = 0; j < i; j++) {
                        if (num[j] > num[j + 1]) {
                            temp = num[j + 1];
                            num[j + 1] = num[j];
                            num[j] = temp;
                        }
                    }
                }
            }
            else {
                for (unsigned i = countNum - 1; i > 0; i--) {
                    for (unsigned j = 0; j < i; j++) {
                        if (num[j] < num[j + 1]) {
                            temp = num[j];
                            num[j] = num[j + 1];
                            num[j + 1] = temp;
                        }
                    }
                }
            }
        }
    }

    unsigned Stats::size()const {
        return countNum;
    }

    const char* Stats::name()const {
        return m_filename;
    }

    unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
        unsigned count = 0;
        int occur = 0;
        if (*this) {
            ostr << endl;
            for (unsigned i = 0; i < countNum; i++) {
                if (num[i] >= min && num[i] <= max) {
                    ostr.width(columnWidth);
                    ostr.setf(ios::fixed);
                    ostr.precision(precision);
                    ostr << num[i];
                    count++;
                    occur++;
                    if (count == noOfColumns) {
                        ostr << endl;
                        count = 0;
                    }
                }
            }
            ostr << endl;
            ostr << "Total of " << occur << " numbers are between " << min << " and " << max << endl;
        }
        return occur;
    }

    std::ostream& Stats::view(std::ostream& ostr)const {
        unsigned count = 0;
        int total = 0;
        if (*this) {
            ostr << m_filename << endl;
            ostr.fill('=');
            ostr.width(strlen(m_filename));
            ostr << "=" << endl << endl;
            for (unsigned i = 0; i < countNum; i++) {
                ostr.fill(' ');
                ostr.width(columnWidth);
                ostr.setf(ios::fixed);
                ostr.precision(precision);
                ostr << num[i];
                count++;
                total++;
                if (count == noOfColumns) {
                    ostr << endl;
                    count = 0;
                }
                else if (i == countNum -1){
                    ostr << endl;
                }
            }
            ostr << "Total of " << total << " listed!" << endl;
        }
        return ostr;
    }

    std::istream& Stats::getFile(std::istream& istr) {
        string file;
        istr >> file;
        setFilename(file.c_str());
        setNoOfNum();
        loadText();
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Stats& stats) {
        return stats.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, Stats& stats) {
        return stats.getFile(istr);
    }

}

