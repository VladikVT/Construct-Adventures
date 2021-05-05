#ifndef CONADVLIB_H
#define CONADVLIB_H

#define CurPosSave cout << "\033[s";
#define CurPosLoad cout << "\033[l";
#define CurGoToXY(x, y) printf("\033[%d; %dH", x, y);
#define CurHide cout << "\033[?25l";
#define CurShow cout << "\033[?25h";

#endif // CONADVLIB_H
