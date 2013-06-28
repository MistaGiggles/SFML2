#pragma once
class Cell
{
private:
	Cell *TL, *TR, *BL, *BR;
	bool hasSplit;

public:
	Cell(void);
	~Cell(void);

	void Split(void);
};

class QuadTree
{
public:
	QuadTree(void);
	~QuadTree(void);
};

