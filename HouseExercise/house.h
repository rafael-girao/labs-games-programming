#ifndef house_header
#define house_header

class House
{
public:
	House();
	House(int row, int collumn);
	void constructX();
	void constructHouse();
	int ** getHouse();
	int * getWidth();
	int * getHeight();
	void rotate90();
	void rotate180();
	void rotate45();

private:
	void initHouse(int row, int collumn);
	const int DefaultSize = 10;
	int ** mHouse;
	int * mpWidth = nullptr;
	int * mpHeight = nullptr;
	int mWidth = 0;
	int mHeight = 0;
	static const int HouseStWidth = 12;
	static const int HouseStHeight = 12;
	const int HouseWidth = HouseStWidth;
	const int HouseHeight = HouseStHeight;
	const int HardCodedHouse[HouseStHeight][HouseStWidth] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },	// row 1
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },	// row 2
		{ 0,0,0,1,0,0,0,0,0,0,0,0 },	// row 3
		{ 0,0,1,1,0,0,0,0,0,0,0,0 },	// row 4
		{ 0,0,1,1,0,1,1,0,0,0,0,0 },	// row 5
		{ 0,0,1,1,1,1,1,1,0,0,0,0 },	// row 6
		{ 0,0,1,1,1,1,1,1,1,0,0,0 },	// row 7
		{ 0,0,1,1,1,1,1,1,1,1,0,0 },	// row 8
		{ 0,1,1,1,0,0,1,1,1,1,1,0 },	// row 9
		{ 0,1,1,1,0,0,1,0,0,1,1,0 },	// row 10
		{ 0,1,1,1,0,0,1,0,0,1,1,0 },	// row 11
		{ 0,1,1,1,0,0,1,1,1,1,1,0 } 	// row 12
	};
};

#endif // !house_header