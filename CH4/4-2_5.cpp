// 생각해보기 문제
#include <iostream>
#include "math.h"

class Point {
    public:
    int x, y;
    Point (int pos_x, int pos_y) {
        x = pos_x;
        y = pos_y;
    }
};

class Geometry {
    private:
    Point* point_array[100]; // 점 100개를 보관하는 배열
    int num_points;
    
    public:
    Geometry() {
        num_points = 0;
    }

    void AddPoint(const Point &point) {
        point_array[num_points++] = new Point(point.x, point.y);
    }

    void PrintDistance(); // 모든 점을 이은 선의 거리를 출력
    void PrintNumMeets(); // 모든 점을 이은 선의 교점의 수를 출력
};

void Geometry::PrintDistance () {
    float dis = 0.0f;
    for (int i = 0; i < num_points - 1; i++) {
        for (int j = i + 1; j < num_points; j++) {
            dis += sqrt(pow((*point_array[i]).x - (*point_array[j]).x, 2) + pow((*point_array[i]).y - (*point_array[j]).y, 2));
        }
    }
    std::cout << ("%.2f\n", dis) << std::endl;
}

void Geometry::PrintNumMeets () {
    int num_meets = 0;
    for (int i = 0; i < num_points - 3; i++) {
        for (int j = i + 1; j < num_points - 2; j++) {
            for (int k = j + 1; k < num_points - 1; k++) {
                for (int l = k + 1; l < num_points; l++) {
// 포기... 나중에 수정해서 올리겠습니다.
                }
            }
        }
    }
    std::cout << ("%d\n", num_meets) << std::endl;
}