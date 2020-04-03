#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<bangtal.h>
#include<windows.h>
#include <stdbool.h>
#pragma comment(lib, "Bangtal.lib")

SceneID scene1, scene2;
ObjectID start, a, b, c, d, e, f, g, h, i, point, r,end;

int blankX = 738, blankY = 59, m;
int s[3][3];


    void endG () {
        if (s[0][0] == a && s[0][1] == b && s[0][2] == c && s[1][0] == d && s[1][1] == e && s[1][2] == f && s[2][0] == g && s[2][1] == h && s[2][2] == i) {
            showMessage("성공!");
            enterScene(scene1);
            showObject(start);
            showObject(end);
           
        }
    }



ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
    ObjectID object = createObject(name, image);
    locateObject(object, scene, x, y);
    if (shown) {
        showObject(object);
    }
    return object;
}


int T, t;

void random() {
    int r[3][3] = { {0,0,0},{0,0,0},{0,0,1} };
    s[0][0] = a, s[0][1] = b, s[0][2] = c;
    s[1][0] = d, s[1][1] = e, s[1][2] = f;
    s[2][0] = g, s[2][1] = h, s[2][2] = i;

    int blankX[3] = { 338,538,738 };
    int blankY[3] = { 459,259,59 };
    int i, j;

    int k = 0;
    ObjectID temp;
    srand(time(NULL));
    while (k < 50) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (r[i][j] == 1) {
                    T = i;
                    t = j;
                }
            }
        }
        switch (rand() % 4) {
        case 0: {//위쪽
            if (T == 0) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T - 1][t] = 1;
            hideObject(s[T - 1][t]);
            locateObject(s[T - 1][t], scene2, blankX[t], blankY[T]);
            showObject(s[T - 1][t]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t], blankY[T - 1]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T - 1][t];
            s[T - 1][t] = temp;
            k = k + 1;


            break;
        }
        case 1: {//아래쪽     
            if (T == 2) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T + 1][t] = 1;
            hideObject(s[T + 1][t]);
            locateObject(s[T + 1][t], scene2, blankX[t], blankY[T]);
            showObject(s[T + 1][t]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t], blankY[T + 1]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T + 1][t];
            s[T + 1][t] = temp;
            k = k + 1;

            break;
        }
        case 2: {//오른쪽
            if (t == 2) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T][t + 1] = 1;
            hideObject(s[T][t + 1]);
            locateObject(s[T][t + 1], scene2, blankX[t], blankY[T]);
            showObject(s[T][t + 1]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T][t + 1];
            s[T][t + 1] = temp;
            k = k + 1;

            break;
        }
        case 3: { //왼쪽
            if (t == 0) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T][t - 1] = 1;
            hideObject(s[T][t - 1]);
            locateObject(s[T][t - 1], scene2, blankX[t], blankY[T]);
            showObject(s[T][t - 1]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T][t - 1];
            s[T][t - 1] = temp;
            k = k + 1;

            break;

        }

        }
    }

    for (i = 0; i < 3; i++) {      
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }
}



void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == start) {
        hideObject(start);
        hideObject(end);
        enterScene(scene2);
        random();
        return;            
    }
    if (object == end) {
        endGame();
    }
    
    if (object == i)      
        return;

    int r[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
    r[T][t] = 1;
    int blankX[3] = { 338,538,738 };
    int blankY[3] = { 459,259,59 };
    int i, j;

    int k = 0;
    ObjectID temp;

    int right = 0, left = 0, up = 0, down = 0;      

    if (T != 0)     
        up = s[T - 1][t];

    if (T != 2)
        down = s[T + 1][t];

    if (t != 0)
        left = s[T][t - 1];

    if (t != 2)
        right = s[T][t + 1];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }

    if (object == right) {
        m = 0;
    }
    else if (object == left) {
        m = 1;
    }
    else if (object == up) {
        m = 2;
    }
    else if (object == down) {
        m = 3;
    }
    else {
        m = -1;               
    }

    switch (m) {
    case 0: {//오
      
        r[T][t] = 0;
        r[T][t + 1] = 1;
        hideObject(s[T][t + 1]);
        locateObject(s[T][t + 1], scene2, blankX[t], blankY[T]);
        showObject(s[T][t + 1]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T][t + 1];
        s[T][t + 1] = temp;

        k = k + 1;
        endG();
        break;
       
    }
    case 1: {//왼
        r[T][t] = 0;
        r[T][t - 1] = 1;
        hideObject(s[T][t - 1]);
        locateObject(s[T][t - 1], scene2, blankX[t], blankY[T]);
        showObject(s[T][t - 1]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T][t - 1];
        s[T][t - 1] = temp;
        k = k + 1;
        endG();
        break;
       
    }


    case 2: {//위
        r[T][t] = 0;
        r[T - 1][t] = 1;
        hideObject(s[T - 1][t]);
        locateObject(s[T - 1][t], scene2, blankX[t], blankY[T]);
        showObject(s[T - 1][t]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t], blankY[T - 1]);
        showObject(s[T][t]);
        temp = s[T][t];
        s[T][t] = s[T - 1][t];
        s[T - 1][t] = temp;
        k = k + 1;
        endG();
        break;
        
    }
    case 3: {//아래
        r[T][t] = 0;
        r[T + 1][t] = 1;
        hideObject(s[T + 1][t]);
        locateObject(s[T + 1][t], scene2, blankX[t], blankY[T]);
        showObject(s[T + 1][t]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t], blankY[T + 1]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T + 1][t];
        s[T + 1][t] = temp;
        k = k + 1;
        endG();
        break;
    }


    default:
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (r[i][j] == 1) {
                    T = i;
                    t = j;
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {         
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }
}


int main() {
    setMouseCallback(mouseCallback);

    scene1 = createScene("인어공주 퍼즐", "배경.jpg");
    scene2 = createScene("슬라이딩 퍼즐", "구멍.png");


    start = createObject("시작 버튼", "start.png", scene1, 450, 70, true);
    end = createObject("끝 버튼", "end.png", scene1, 690,70,true);
    a = createObject("1", "1.png", scene2, 338, 459, true);
    b = createObject("2", "2.png", scene2, 538, 459, true);
    c = createObject("3", "3.png", scene2, 738, 459, true);
    d = createObject("4", "4.png", scene2, 338, 259, true);
    e = createObject("5", "5.png", scene2, 538, 259, true);
    f = createObject("6", "6.png", scene2, 738, 259, true);
    g = createObject("7", "7.png", scene2, 338, 59, true);
    h = createObject("8", "8.png", scene2, 538, 59, true);
    i = createObject("9_", "9_.png", scene2, 738, 59, true);
    point = createObject("point", "point.png", scene1, 738, 459, false);
    scaleObject(point, 0.5f);

    startGame(scene1);

}