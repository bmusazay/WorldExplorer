class Mouse {

public:
	Mouse();
	void mouseMotion(int x, int y);

private:
	int x;
	int y;
	int difX;
	int difY;
	bool lmb;
	bool rmb;
};