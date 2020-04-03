#include<bangtal.h>
#pragma comment(lib, "Bangtal.lib");

SceneID scene1;
ObjectID problem;

ObjectID left[7];
ObjectID right[7];

int leftX[7] = { 546, 77, 361, 379, 39, 570, 298 };
int rightX[7] = { 1164, 695, 979, 997, 657, 1188, 916 };
int Y[7] = { 542, 499, 430, 106, 203, 369, 65 };
int radius[7] = { 54, 17, 16, 27, 36, 35, 13 };

bool checked[7];

bool checkIn(int x, int y, int cx, int cy, int r) {
	return(x > cx - r && x< cx + r && y>cy - r && y < cy + r);

}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == problem) {

		bool wrong = true;

		for (int i = 0; i < 7; i++) {
			if ((checked[i] == false) && (checkIn(x, y, leftX[i], Y[i], radius[i]) || checkIn(x, y, rightX[i], Y[i], radius[i]))) {
				showObject(left[i]);
				showObject(right[i]);
				checked[i] = true;
				wrong = false;
			}
		}
		if (wrong) {
			endGame();
		}
		else {
			bool completed = true;
			for (int i = 0; i < 7; i++) {
				if (checked[i] == false) {
					completed = false;
				}
			}
			if (completed) {
				endGame();
			}
		}
	}
}

int main() {

	setMouseCallback(mouseCallback);

	scene1 = createScene("틀린그림찾기", "problem.png");

	problem = createObject("problem", "problem.png");
	locateObject(problem, scene1, 0, 0);
	showObject(problem);

	for (int i = 0; i < 7; i++) {
		left[i] = createObject("체크마크", "check.png");
		locateObject(left[i], scene1, leftX[i] - 25, Y[i] - 25);

		right[i] = createObject("체크마크", "check.png");
		locateObject(right[i], scene1, rightX[i] - 25, Y[i] - 25);

	}

	showMessage("좌우에 틀린 곳을 찾아보세요.");

	startGame(scene1);
}