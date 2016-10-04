#include "house.h"

/// <summary>
/// Default constructor:
///  will initialize our 2D house array of size of 10 x 10
///  and fill it with 0's.
/// </summary>
House::House()
{
	initHouse(DefaultSize, DefaultSize);
}

/// <summary>
/// Sets the current limits and initializes the 2D array to 0.
/// </summary>
/// <param name = "lRow"> integer that decides the Height of the array </param>
/// <param name = "lCollumn"> integer that decides the Width of the array </param>
House::House(int lRow, int lCollumn)
{
	initHouse(lRow, lCollumn);
}

/// <summary>
/// Assigns our 2D house array with the content of 0 or 1
///  will assign in a way to contain a X shape of 1's
/// </summary>
void House::constructX()
{
	const int WidthOfX = 10;
	const int HeightOfX = 10;

	initHouse(HeightOfX, WidthOfX);

	int i = *(mpHeight) - 1;
	short unsigned int halfHeight = *(mpHeight) / 2;
	short unsigned int halfWidth = *(mpWidth) / 2;
	for (int row = 0; row < *(mpHeight); row++, i--)
	{
		for (int col = 0; col < *(mpWidth); col++)
		{
			if (col == row)
			{
				mHouse[row][col] = 1;
			}
			else if ( col == (halfHeight) && row <= (halfWidth) )
			{
				mHouse[row][col] = 1;
			}
			else if (col == i)
			{
				mHouse[row][col] = 1;
			}
			else
			{
				mHouse[row][col] = 0;
			}
		}
	}
}

/// <summary>
/// Will construct a hard coded house of size 7x9
/// </summary>
void House::constructHouse()
{
	initHouse(HouseHeight, HouseWidth);

	// Brackets used to avoid any precedence errors example: *(mpHeight)++

	for (int r = 0; r < *(mpHeight); r++)
	{
		for (int c = 0; c < *(mpWidth); c++)
		{
			mHouse[r][c] = HardCodedHouse[r][c];
		}
	}
}

/// <summary>
/// Will get the 2D house array
/// </summary>
/// <returns> a dynamic 2D house array of integers </returns>
int** House::getHouse()
{
	return mHouse;
}

/// <summary>
/// Will provide you with the width of the current
///  instance of the array 
/// </summary>
/// <returns> returns a pointer to the width (integer) </returns>
int* House::getWidth()
{
	return mpWidth;
}

/// <summary>
/// Will provide you with the height of the current
///  instance of the array 
/// </summary>
/// <returns> returns a pointer to the height (integer) </returns>
int* House::getHeight()
{
	return mpHeight;
}

/// <summary>
/// Will initialize the house with a new set of row and collumns,
///  this is made private so that only constructors and methods have access to this method.
/// </summary>
/// <param name = "row"> Defines the Height of the dynamic 2d array </param>
/// <param name = "collumn"> Defines the Width of the dynamic 2d array </param>
void House::initHouse(int row, int collumn)
{
	mpHeight = &mHeight;
	mpWidth = &mWidth;

	*mpHeight = row;
	*mpWidth = collumn;

	mHouse = new int*[*(mpHeight)];

	for (int r = 0; r < *(mpHeight); r++)
	{
		mHouse[r] = new int[*(mpWidth)];
		for (int c = 0; c < *(mpWidth); c++)
		{
			mHouse[r][c] = 0;
		}
	}
}

/// <summary>
/// Rotates the house 90 degrees clockwise
/// </summary>
void House::rotate90()
{
	int ** houseCopy = new int*[*(mpHeight)];

	for (int r = 0; r < *(mpHeight); r++)
	{
		houseCopy[r] = new int[*(mpWidth)];

		for (int c = 0; c < *(mpWidth); c++)
		{
			houseCopy[r][c] = mHouse[r][c];
		}
	}

	// There is where we actually do the rotation

	for (int r = 0, difC = 0; r < *(mpHeight); r++, difC++)
	{
		for (int c = 0, difR = *(mpHeight)-1; c < *(mpWidth); c++, difR--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}
}

/// <summary>
/// Rotates the House by 180 degrees clockwise
/// </summary>
void House::rotate180()
{
	int ** houseCopy = new int*[*(mpHeight)];

	for (int r = 0; r < *(mpHeight); r++)
	{
		houseCopy[r] = new int[*(mpWidth)];

		for (int c = 0; c < *(mpWidth); c++)
		{
			houseCopy[r][c] = mHouse[r][c];
		}
	}

	// There is where we actually do the rotation

	for (int r = 0, difR = *(mpHeight)-1; r < *(mpHeight); r++, difR--)
	{
		for (int c = 0, difC = *(mpWidth)-1; c < *(mpWidth); c++, difC--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}
}

/// <summary>
/// Rotates the house by 45 degrees clockwise
/// </summary>
void House::rotate45()
{
	// create a copy of the current array
	int ** houseCopy = new int*[*(mpHeight)];

	for (int r = 0; r < *(mpHeight); r++)
	{
		houseCopy[r] = new int[*(mpWidth)];

		for (int c = 0; c < *(mpWidth); c++)
		{
			houseCopy[r][c] = mHouse[r][c];
		}
	}

	// There is where we actually do the rotation

	int halfWidth = *(mpWidth) / 2;
	int halfHeight = *(mpHeight) / 2;
	const int RightMost = *(mpWidth)-1;
	const int BottomMost = *(mpHeight)-1;

	int diagR;
	int diagC;
	int r;
	int c;
	int difR;
	int difC;

	// Top-Left diagonal
	for (diagR = 0, diagC = 0; diagR <= halfHeight, diagC <= halfWidth; diagR++, diagC++)
	{
		r = diagR; difR = diagR;
		for ( c = halfWidth, difC = diagC; c < *(mpWidth), difC <= halfWidth; c++, difC++)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
		difC = diagC; c = diagC; r = diagR;
		for (difR = halfHeight; difR >= 0, c <= halfWidth; difR--, c++)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}

	// Top-Right diagonal
	for (diagR = 0, diagC = RightMost; diagR <= halfHeight, diagC > halfWidth; diagR++, diagC--)
	{
		c = diagC; difC = diagC;
		for (r = halfHeight, difR = diagR; r < *(mpHeight), difR < halfHeight; r++, difR++)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
		difR = diagR; r = diagR; difC = diagC;
		for (difC = halfWidth; difC > *(mpWidth), r < halfHeight; difC++, r++)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}

	// Bottom-Right diagonal
	for (diagR = BottomMost, diagC = RightMost; diagR > halfHeight, diagC > halfWidth; diagR--, diagC--)
	{
		r = diagR; difR = diagR;
		for (c = halfWidth, difC = diagC; c > 0, difC >= halfWidth; c--, difC--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
		difC = diagC; c = diagC; r = diagR;
		for (difR = halfHeight; difR <= BottomMost, c >= halfWidth; difR++, c--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}

	// Bottom-Left diagonal
	for (diagR = BottomMost, diagC = 0; diagR > halfHeight, diagC <= halfWidth; diagR--, diagC++)
	{
		c = diagC; difC = diagC;
		for (r = halfHeight, difR = diagR; r > 0, difR > halfHeight; r--, difR--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
		difR = diagR; r = diagR; difC = diagC;
		for (difC = halfWidth; difC > 0, r > halfHeight; difC--, r--)
		{
			mHouse[r][c] = houseCopy[difR][difC];
		}
	}
}