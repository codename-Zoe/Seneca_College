#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

using namespace std;
namespace sdds 
{
   class Text {
      char* m_filename = nullptr;
      char* m_content = nullptr;
      int getFileLength()const;
   protected:
      const char& operator[](int index) const;
   public:
      Text(const char* filename = nullptr);
      ~Text();
      Text(const Text&);
      Text& operator=(const Text&);
      void read();
      virtual void write(std::ostream&) const;
   };
   ostream& operator<<(ostream&, const Text&);
}
#endif

