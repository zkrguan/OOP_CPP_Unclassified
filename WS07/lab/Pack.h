#ifndef SSDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
namespace sdds {
   class pack : public container {
      int m_unitSize{};
      int m_packSize{};
      int m_numOfUnits{};
   public:
      // should use fardad's way showed during week 8's vid//
      pack(int size, int unitSize=330, int numOfUnits=0);
      pack& operator += (int addUnits);
      pack& operator -= (int deductUnits);
      int unit()const;
      int numOfUnits() const;
      int size() const;
      // not shadows the base class//
      pack& clear(int packSize, int unitSize, char* description);
      // shadows the print of the base class//
      pack& print(std::ostream& ostr);
      pack& read(std::istream& istr);
   };
   std::ostream& operator << (std::ostream ostr, const pack& packToPrint);
   std::istream& operator >> (std::istream istr, pack& packToSet);
}
#endif // !SSDS_PACK_H
