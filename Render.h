#pragma once

class Render {
public:
	void updateStep(int n);
	void updatePush(int n);
	void updateLevel(int n);
private:
	int nStep;
	int nPush;
	int nLevel;
};