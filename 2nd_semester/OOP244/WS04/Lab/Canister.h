#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H

namespace sdds {
   class Canister {
      char* m_contentName;
      double m_diameter;
      double m_height;
      double m_contentVolume;
      bool m_usable;
      void setToDefault();
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
      void setName(const char* Cstr);
      ~Canister();
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter, const char* contentName = nullptr);
      void clear();
      double capacity()const;
      double volume()const;
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      std::ostream& display()const;
   };
}

#endif
