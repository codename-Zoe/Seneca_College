namespace sdds {
   class Stats {
       double* num = nullptr;
       double dummy = 0.0;
       char* m_filename = nullptr;
       unsigned columnWidth;
       unsigned noOfColumns;
       unsigned precision;
       unsigned countNum;
       void setFilename(const char* fname, bool isCopy = false);
       void setNoOfNum();
       void loadText();
       void saveAs(const char* fileName)const;
       void setEmpty();
   public:
       Stats(unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);
       Stats(const char* filename,
           unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);
       ~Stats();
       Stats(const Stats&);
       Stats& operator=(const Stats&);
       double& operator[](unsigned idx);
       double operator[](unsigned idx)const;
       operator bool()const;
       void sort(bool ascending);
       unsigned size()const;
       const char* name()const;
       unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
       std::ostream& view(std::ostream& ostr)const;
       std::istream& getFile(std::istream& istr);      
   };
   std::ostream& operator<<(std::ostream& ostr, const Stats& text);
   std::istream& operator>>(std::istream& istr, Stats& text);
}
