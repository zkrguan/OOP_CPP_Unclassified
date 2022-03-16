#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
namespace sdds {
	class container{
		char m_content[50]{};
		int m_capacity{};
		int m_contentVolume{};
	public:
		container(const char*srcContent, int srcCapacity);
		container(const char*srcContent, int srcCapacity, int srcContentVolume);
		~container();
	protected:
		container& setEmpty() ;
		int capacity() const;
		int volume() const;
	public:
		int operator += (int srcVolume);
		int operator -=(int dstVolume);
		operator bool()const;
		// Temp spot for the container methods// 
		void clear(const int capacity, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator << (std::ostream& ostr, const container& ctnerToPrint);
	std::istream& operator >> (std::istream& istr, container& ctnerToSet);
}
#endif // !SDDS_CONTAINER_H